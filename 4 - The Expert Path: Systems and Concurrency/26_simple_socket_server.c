/**
 * @file 26_simple_socket_server.c
 * @author dunamismax (enhanced by Gemini)
 * @date 2025-06-10
 *
 * @brief An expert-level project: A simple TCP server.
 *
 * ---
 *
 * Welcome to Network Programming!
 *
 * This program creates a "server," which is an application that listens for incoming
 * network connections. It uses a protocol called TCP (Transmission Control Protocol),
 * which guarantees that data arrives in order and without errors.
 *
 * Core Concepts:
 * 1.  **Socket:** A "socket" is an endpoint for network communication. Think of it as a
 *     doorway in your program for sending and receiving data. We create one using `socket()`.
 * 2.  **Address & Port:** Just like a house has a street address and an apartment number, a
 *     network service has an IP address and a Port number. We will run our server on
 *     port 8080.
 * 3.  **Bind:** `bind()` associates our socket with a specific IP address and port on the
 *     local machine. It's like claiming a specific P.O. Box for your program.
 * 4.  **Listen:** `listen()` puts the socket in a passive "listening mode," ready to
 *     accept connections from clients.
 * 5.  **Accept:** `accept()` is a blocking call. The program will wait here until a client
 *     tries to connect. When one does, `accept()` creates a *new* socket just for
 *     communicating with that specific client.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1. Compile the code. Note the special `-l` flag for linking a library.
 *    - On Linux/macOS: `gcc -Wall -Wextra -std=c11 -o server 26_simple_socket_server.c`
 *    - On Windows: `gcc -Wall -Wextra -std=c11 -o server.exe 26_simple_socket_server.c -lws2_32`
 *      (You need `-lws2_32` to link the Windows Sockets library.)
 *
 * 2. Run the server executable first:
 *    `./server` or `server.exe`
 *
 * 3. The server will print "Server listening on port 8080..." and wait.
 *    Now, you must compile and run the client program in a *separate terminal window*.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Platform-specific headers for networking
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib") // Link with the Winsock library on Windows
#else
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_error(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main(void)
{
#ifdef _WIN32
    // On Windows, we must initialize the Winsock library
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        fprintf(stderr, "WSAStartup failed.\n");
        return 1;
    }
#endif

    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    int addr_len = sizeof(client_addr);

    // 1. Create the socket
    // AF_INET: Address Family for IPv4
    // SOCK_STREAM: Type for TCP (reliable, connection-oriented)
    // 0: Protocol value for IP
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        handle_error("socket failed");
    }

    // 2. Prepare the server address structure
    server_addr.sin_family = AF_INET;
    // INADDR_ANY means we will accept connections on any of the machine's available network interfaces.
    server_addr.sin_addr.s_addr = INADDR_ANY;
    // htons() converts the port number from "host byte order" to "network byte order".
    // This ensures systems with different internal byte representations can communicate.
    server_addr.sin_port = htons(PORT);

    // 3. Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        handle_error("bind failed");
    }

    // 4. Listen for incoming connections
    // The '3' is the "backlog" size - the maximum number of pending connections queued up.
    if (listen(server_fd, 3) < 0)
    {
        handle_error("listen failed");
    }

    printf("Server listening on port %d...\n", PORT);

    // 5. Accept an incoming connection
    // The program will block here, waiting for a client to connect.
    // When a connection is made, it returns a new file descriptor for that specific client.
    if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0)
    {
        handle_error("accept failed");
    }

    printf("Connection accepted from a client.\n");

    // --- Communication Loop ---
    while (1)
    {
        // Clear the buffer before reading new data
        memset(buffer, 0, BUFFER_SIZE);

        // Read data from the client
        // `read()` or `recv()` is a blocking call; it waits until data is sent.
        int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            printf("Client disconnected or error occurred.\n");
            break; // Exit loop if client disconnects or an error happens
        }

        printf("Client says: %s", buffer);

        // Send a response back to the client
        const char *response = "Message received.\n";
        send(client_socket, response, strlen(response), 0);
    }

    // --- Cleanup ---
#ifdef _WIN32
    closesocket(client_socket);
    closesocket(server_fd);
    WSACleanup();
#else
    close(client_socket);
    close(server_fd);
#endif

    return 0;
}