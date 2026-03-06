#!/bin/python3

import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind(("127.0.0.1", 8000))

server_socket.listen(10)

client, _ = server_socket.accept()

while True:
    response = client.recv(1024)
    print(f"[client]: {response.decode()}")

    try:
        msg = input('>>> ')
    except Exception:
        break

    client.send(bytes(msg, 'UTF-8'))


