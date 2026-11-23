# Seamless TCP Communication with QTcpSocket in Qt Software

A C++ and Qt-based client-server communication application developed during my internship at the Defence Research and Development Laboratory (DRDL), DRDO, Hyderabad.

## Project Overview

This project focuses on developing a TCP-based client-server communication application using Qt software. It demonstrates communication between multiple clients and a server over a local network using TCP/IP and Qt's QTcpSocket and QTcpServer classes.

The application provides a graphical interface for exchanging text messages, managing client connections, displaying user status and handling file transfer requests.

## Features

- TCP-based client-server communication over a local network.
- Text message exchange between connected clients.
- Client username management.
- User status management (Available, Busy and Away).
- Typing status indication.
- File transfer request and acceptance/rejection workflow.
- Graphical user interface developed using Qt Widgets.
- Server-side client connection management.

## Technology Stack

| Component | Technology |
|---|---|
| Programming Language | C++ |
| Framework | Qt |
| GUI | Qt Widgets |
| Networking | Qt Network |
| Socket Communication | QTcpSocket, QTcpServer |
| Communication Protocol | TCP/IP |
| Build System | CMake |
| Development Environment | Qt Creator |

## Project Architecture

The application follows a client-server architecture.

- **Client:** Connects to the server, sends and receives messages, manages user information and handles file transfer operations.
- **Server:** Listens for incoming connections, manages connected clients and coordinates communication.
- **Message Protocol:** Handles message types and data exchanged between clients and the server.

## Repository Structure

```text
drdo-qtcp-socket-communication/
│
├── client/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   ├── clientmanager.cpp
│   ├── clientmanager.h
│   ├── MessageProtocol.cpp
│   └── messageprotocol.h
│
├── server/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   ├── clientmanager.cpp
│   ├── clientmanager.h
│   ├── clientchatwidget.cpp
│   ├── clientchatwidget.h
│   ├── servermanager.cpp
│   ├── servermanager.h
│   ├── messageprotocol.cpp
│   └── messageprotocol.h
│
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Learning Outcomes

Through this internship project, I gained exposure to:

- C++ application development.
- Qt framework and GUI development.
- TCP/IP networking fundamentals.
- Client-server communication architecture.
- Socket programming using QTcpSocket.
- Message handling and file transfer workflows.
- Organizing modular C++ applications.

## Project Status

- Source code organized into separate client and server modules.
- CMake build configuration added.
- Compilation and runtime testing are pending.
- Further verification and refinement of the reconstructed source code are required.

## Internship Details

**Organization:** Defence Research and Development Laboratory (DRDL), DRDO, Hyderabad

**Internship Period:** 01 May 2024 – 28 June 2024

**Project:** Seamless TCP Communication with QTcpSocket in Qt Software

---

*Developed as part of my internship experience at DRDL, DRDO.*
