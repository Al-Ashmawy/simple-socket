#!/bin/python3

import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    try:
        msg = input('>>> ')
    except Exception:
        break

    client_socket.sendto(bytes(msg, 'UTF-8'), ('127.0.0.1', 8000))
    response, _ = client_socket.recvfrom(1024)
    print(f"[server]: {response.decode()}")


client_socket.close()
