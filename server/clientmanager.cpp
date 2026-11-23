
#include "clientmanager.h"

#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>

ClientManager::ClientManager(QTcpSocket* client, QObject* parent)
    : QObject{parent}, _client(client)
{
    connect(_client, &QTcpSocket::connected,
            this, &ClientManager::connected);

    connect(_client, &QTcpSocket::disconnected,
            this, &ClientManager::disconnected);

    connect(_client, &QTcpSocket::readyRead,
            this, &ClientManager::readyRead);
}

void ClientManager::uploadFile()
{
    _client->write(_protocol.setUploadMessage(_temp_filename));
}

void ClientManager::saveFile()
{
    QString directory =
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    QDir dir(directory);

    QString username = this->username();
    QString userDirectory = dir.filePath(username);

    QDir().mkpath(userDirectory);

    QString filename =
        QString("%1_%2")
        .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"))
        .arg(QFileInfo(_temp_filename).fileName());

    QString path = QDir(userDirectory).filePath(filename);

    QFile file(path);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(_protocol.filedata());
        file.close();

        emit fileSaved(path);
    }
}

void ClientManager::connectToServer()
{
    _client->connectToHost(_ip, _port);
}

void ClientManager::sendMessage(const QString& message)
{
    _client->write(_protocol.textMessage(message));
}

void ClientManager::sendIsTyping()
{
    _client->write(_protocol.isTypingMessage());
}

void ClientManager::sendName(const QString& name)
{
    _client->write(_protocol.setNameMessage(name));
}

void ClientManager::sendStatus(MessageProtocol::Status status)
{
    _client->write(_protocol.setStatusMessage(status));
}

QString ClientManager::username() const
{
    QString name = _protocol.username();

    if (name.isEmpty())
    {
        return QString("Client_%1").arg(
            _client->property("id").toInt());
    }

    return name;
}

void ClientManager::sendRequestUpload(const QString& filename)
{
    _temp_filename = filename;
    _client->write(_protocol.setRequestUploadMessage(filename));
}

void ClientManager::sendAcceptUpload()
{
    _client->write(_protocol.setAcceptUploadMessage());
}

void ClientManager::sendRejectUpload()
{
    _client->write(_protocol.setRejectUploadMessage());
}

void ClientManager::readyRead()
{
    auto data = _client->readAll();

    if (!_protocol.parseData(data))
        return;

    switch (_protocol.type())
    {
    case MessageProtocol::Text:
        emit messageReceived(_protocol.message());
        break;

    case MessageProtocol::SetName:
        emit nameChanged(_protocol.username());
        break;

    case MessageProtocol::SetStatus:
        emit statusChanged(_protocol.status());
        break;

    case MessageProtocol::IsTyping:
        emit isTyping();
        break;

    case MessageProtocol::RequestUpload:
        _temp_filename = _protocol.filename();
        emit fileUploadRequested(_protocol.username(),
                                 _temp_filename);
        break;

    case MessageProtocol::AcceptUpload:
        uploadFile();
        break;

    case MessageProtocol::RejectUpload:
        emit fileUploadRejected();
        break;

    case MessageProtocol::Upload:
        saveFile();
        break;
    }
}
