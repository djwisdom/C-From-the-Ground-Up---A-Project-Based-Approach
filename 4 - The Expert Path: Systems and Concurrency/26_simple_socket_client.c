/**
 * @file 26_simple_socket_client.c
 * @author dunamismax (enhanced by Gemini)
 * @date 2025-06-10
 *
 * @brief An expert-level project: A simple TCP client.
 *
 * ---
 *
 * This program is the other half of our networking pair. A "client" is an
 * application that initiates a connection to a server.
 *
 * Core Concepts:
 * 1.  **Socket:** Just like the server, the client needs a socket endpoint.
 * 2.  **Server Address:** The client must know the server's IP address and port to
 *     connect to it. Here, we use "127.0.0.1", which is a special "localhost"
 *     address that always points to your own machine.
 * 3.  **Connect:** `connect()` is the key client-side function. It attempts to
 *     establish a TCP connection to the server at the specified address and port.
 * 4.  **Send/Receive:** Once connected, the client can use `send()` to send data
 *     and `recv()` (or `read()`) to receive data, just like the server.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1. Make sure the server is already compiled and running in another terminal.
 *
 * 2. Compile the client code:
 *    - On Linux/macOS: `gcc -Wall -Wextra -std=c11 -o client 26_simple_socket_client.c`
 *    - On Windows: `gcc -Wall -Wextra -std=c11 -o client.exe 26_simple_socket_client.c -lws2_32`
 *
 * 3. Run the client executable:
 *    `./client` or `client.exe`
 *
 * 4. The client will connect to the server. You can now type messages in the client's
 *    terminal, press Enter, and see them appear on the server's terminal.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Platform-specific headers for networking
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

#define SERVER_IP "127.0.0.1" // Localhost IP address
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
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        fprintf(stderr, "WSAStartup failed.\n");
        return 1;
    }
#endif

    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};

    // 1. Create the client's socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        handle_error("socket creation failed");
    }

    // 2. Prepare the server's address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert the IP address string into the correct network format
    // and store it in the address structure.
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0)
    {
        handle_error("invalid address or address not supported");
    }

    // 3. Connect to the server
    // This call attempts to establish a connection with the server.
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        handle_error("connection failed");
    }

    printf("Connected to the server. Type 'exit' to quit.\n");

    // --- Communication Loop ---
    while (1)
    {
        printf("Enter message: ");
        // Read a line of text from the user
        fgets(buffer, BUFFER_SIZE, stdin);

        // Check if the user wants to exit
        if (strncmp(buffer, "exit", 4) == 0)
        {
            printf("Disconnecting from server...\n");
            break;
        }

        // Send the message to the server
        if (send(client_socket, buffer, strlen(buffer), 0) < 0)
        {
            handle_error("send failed");
        }

        // Clear buffer and wait for a response from the server
        memset(buffer, 0, BUFFER_SIZE);
        if (read(client_socket, buffer, BUFFER_SIZE) < 0)
        {
            handle_error("read failed");
        }
        printf("Server response: %s\n", buffer);
    }

    // --- Cleanup ---
#ifdef _WIN32
    closesocket(client_socket);
    WSACleanup();
#else
    close(client_socket);
#endif

    return 0;
}