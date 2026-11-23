
#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>

#include "messageprotocol.h"

class ClientManager : public QObject
{
    Q_OBJECT

public:
    explicit ClientManager(QObject *parent = nullptr);

    ClientManager(QHostAddress ip, ushort port,
                  QObject *parent = nullptr);

    QHostAddress ip() const;
    void setIp(const QHostAddress &newIp);

    ushort port() const;
    void setPort(ushort newPort);

    void connectToServer();
    void disconnectFromServer();
    bool isConnected();

    void sendMessage(QString message);
    void sendIsTyping();
    void sendName(QString name);
    void sendStatus(MessageProtocol::Status status);

    void sendRequestUpload(QString filename);
    void sendAcceptUpload();
    void sendRejectUpload();

    void uploadFile();

signals:
    void connected();
    void disconnected();

    void messageReceived(QString message);
    void nameChanged(QString username);
    void statusChanged(MessageProtocol::Status status);

    void otherSideisTyping();

    void fileRequestReceived(QString username,
                             QString filename,
                             qint64 filesize);

    void fileRejected();

private slots:
    void readyRead();

private:
    QTcpSocket *_client = nullptr;

    QHostAddress _ip;
    ushort _port = 0;

    MessageProtocol _protocol;

    QString _temp_filename;
};

#endif // CLIENTMANAGER_H
