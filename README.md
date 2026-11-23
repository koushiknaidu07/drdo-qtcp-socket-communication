# Seamless TCP Communication with QTcpSocket in Qt

A C++ and Qt-based client-server application developed during my internship at **Defence Research and Development Laboratory (DRDL), DRDO**.

## Project Overview

This project demonstrates TCP/IP socket programming using Qt's `QTcpSocket` and related networking classes. It provides graphical client and server applications for communication over a local network.

## Key Features

- TCP client-server connection
- Real-time text message exchange
- Multiple client connections to a server
- File upload requests with accept/reject functionality
- Client status updates (Available, Away and Busy)
- Typing indicators
- Connection and disconnection notifications
- Graphical user interface using Qt Widgets

## Technologies Used

- **Programming Language:** C++
- **Framework:** Qt
- **IDE:** Qt Creator
- **Networking:** TCP/IP
- **Qt Classes:** QTcpSocket, QTcpServer, QDataStream, QFile, QFileDialog

## Architecture

The application follows a client-server architecture:

1. The server listens for incoming TCP connections.
2. Clients connect using the server IP address and port.
3. Clients send messages and file-upload requests.
4. The server handles client communication and file reception.
5. The GUI displays connection status and communication activity.

## Project Structure

The intended source organization includes:

- Client application
- Server application
- Client manager
- Message protocol
- Client chat widget
- Main window and UI resources

The complete buildable source structure is still being assembled from the internship report.

## Learning Outcomes

- Practical understanding of TCP/IP communication
- C++ socket programming using Qt
- Client-server application development
- Signal-slot communication in Qt
- File handling and data transmission
- Debugging network communication

## Internship Details

- **Organization:** DRDL, DRDO
- **Project:** Seamless TCP Communication with QTcpSocket in Qt Software
- **Duration:** May 2024 – June 2024
- **Domain:** Software Development and Network Programming

## Author

**Koushik Gurram**

[LinkedIn](https://in.linkedin.com/in/koushikgurram) | [GitHub](https://github.com/koushiknaidu07)

---

*This repository documents the internship project. Source files will be added and organized as the implementation is reconstructed and verified.*
