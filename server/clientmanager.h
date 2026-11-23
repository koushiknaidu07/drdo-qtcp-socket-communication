
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
    explicit ClientManager(QTcpSocket* client,
                           QObject* parent = nullptr);

    void connectToServer();
    void sendMessage(QString message);
    void sendIsTyping();
    void sendName(QString name);
    void sendStatus(MessageProtocol::Status status);
    void sendRequestUpload(QString filename);
    void sendAcceptUpload();
    void sendRejectUpload();

    QString username() const;

signals:
    void connected();
    void disconnected();
    void messageReceived(QString message);
    void nameChanged(QString name);
    void statusChanged(MessageProtocol::Status status);
    void otherSideisTyping();
    void fileRequestReceived(QString username,
                             QString filename,
                             qint64 filesize);
    void fileRejected();
    void fileSaved(QString path);

private slots:
    void readyRead();

private:
    void uploadFile();
    void saveFile();

    QTcpSocket* _client;
    QHostAddress _ip;
    ushort _port = 0;

    MessageProtocol _protocol;
    QString _temp_filename;
};

#endif // CLIENTMANAGER_H
