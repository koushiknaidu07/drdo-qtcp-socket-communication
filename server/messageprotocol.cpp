
#include "messageprotocol.h"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>

MessageProtocol::MessageProtocol()
{
    _type = Text;
    _status = Available;
}

QByteArray MessageProtocol::textMessage(QString message)
{
    return convertData(Text, message);
}

QByteArray MessageProtocol::isTypingMessage()
{
    return convertData(IsTyping, "");
}

QByteArray MessageProtocol::setNameMessage(QString name)
{
    return convertData(SetName, name);
}

QByteArray MessageProtocol::setStatusMessage(Status status)
{
    QByteArray data;

    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_6_0);

    stream << SetStatus << status;

    return data;
}

QByteArray MessageProtocol::setRequestUploadMessage(QString filename)
{
    QByteArray data;

    QFileInfo info(filename);

    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_6_0);

    stream << RequestUpload
           << info.fileName()
           << info.size();

    return data;
}

QByteArray MessageProtocol::setAcceptUploadMessage()
{
    return convertData(AcceptUpload, "");
}

QByteArray MessageProtocol::setRejectUploadMessage()
{
    return convertData(RejectUpload, "");
}

QByteArray MessageProtocol::setUploadMessage(QString filename)
{
    QByteArray data;

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly))
        return data;

    QFileInfo info(filename);

    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_6_0);

    stream << Upload
           << info.fileName()
           << info.size()
           << file.readAll();

    file.close();

    return data;
}

void MessageProtocol::parseData(QByteArray data)
{
    QDataStream stream(data);
    stream.setVersion(QDataStream::Qt_6_0);

    stream >> _type;

    switch (_type)
    {
    case Text:
        stream >> _message;
        break;

    case SetName:
        stream >> _username;
        break;

    case SetStatus:
        stream >> _status;
        break;

    case RequestUpload:
        stream >> _filename >> _filesize;
        break;

    case Upload:
        stream >> _filename >> _filesize >> _filedata;
        break;

    default:
        break;
    }
}

QString MessageProtocol::message() const
{
    return _message;
}

QString MessageProtocol::username() const
{
    return _username;
}

QString MessageProtocol::filename() const
{
    return _filename;
}

qint64 MessageProtocol::filesize() const
{
    return _filesize;
}

QByteArray MessageProtocol::filedata() const
{
    return _filedata;
}

MessageProtocol::Status MessageProtocol::status() const
{
    return _status;
}

MessageProtocol::MessageType MessageProtocol::type() const
{
    return _type;
}

QByteArray MessageProtocol::convertData(
    MessageType type,
    QString data)
{
    QByteArray byteArray;

    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_6_0);

    stream << type << data;

    return byteArray;
}
