
#include "servermanager.h"

ServerManager::ServerManager(QObject* parent)
    : QObject{parent}
{
    _server = new QTcpServer(this);

    connect(
        _server,
        &QTcpServer::newConnection,
        this,
        &ServerManager::newClientConnectionReceived
    );
}

void ServerManager::newClientConnectionReceived()
{
    // Get the next pending client connection
    auto client = _server->nextPendingConnection();

    if (!client)
        return;

    // Assign a unique ID to the client
    auto id = _clients.size();
    client->setProperty("id", id);

    // Add the client to the list
    _clients << client;

    connect(
        client,
        &QTcpSocket::disconnected,
        this,
        &ServerManager::onClientDisconnected
    );

    emit newClientConnected(client);
}

void ServerManager::onClientDisconnected()
{
    auto client = qobject_cast<QTcpSocket*>(sender());

    if (!client)
        return;

    // Remove the disconnected client
    _clients.removeOne(client);

    emit clientDisconnected(client);
}

ushort ServerManager::toggleServer(
    QHostAddress serverAddress,
    ushort port)
{
    if (_server->isListening())
    {
        _server->close();
        return 0;
    }
    else
    {
        if (_server->listen(serverAddress, port))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
