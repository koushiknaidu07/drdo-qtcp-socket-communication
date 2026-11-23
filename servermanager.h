
#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>

class ServerManager : public QObject
{
    Q_OBJECT

public:
    explicit ServerManager(QObject* parent = nullptr);

    ushort toggleServer(QHostAddress serverAddress, ushort port);

signals:
    void newClientConnected(QTcpSocket* client);
    void clientDisconnected(QTcpSocket* client);

private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();

private:
    QTcpServer* _server;
    QList<QTcpSocket*> _clients;
};

#endif // SERVERMANAGER_H
