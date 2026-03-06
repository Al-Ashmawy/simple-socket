#!/bin/python3

import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect(('127.0.0.1', 8000))

while True:
    try:
        msg = input('>>> ')
    except Exception:
        break

    client_socket.send(bytes(msg, 'UTF-8'))
    response = client_socket.recv(1024)
    print(f"[server]: {response.decode()}")


client_socket.close()
