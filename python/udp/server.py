#!/bin/python3

import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_socket.bind(("127.0.0.1", 8000))

while True:
    response, client = server_socket.recvfrom(1024)
    print(f"[client]: {response.decode()}")

    try:
        msg = input('>>> ')
    except Exception:
        break

    server_socket.sendto(bytes(msg, 'UTF-8'), client)


