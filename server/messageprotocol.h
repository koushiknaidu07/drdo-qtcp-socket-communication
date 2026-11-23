
#ifndef MESSAGEPROTOCOL_H
#define MESSAGEPROTOCOL_H

#include <QByteArray>
#include <QString>
#include <QDataStream>

class MessageProtocol
{
public:
    enum MessageType
    {
        Text,
        IsTyping,
        SetName,
        SetStatus,
        RequestUpload,
        AcceptUpload,
        RejectUpload,
        Upload
    };

    enum Status
    {
        Available,
        Busy,
        Away
    };

    MessageProtocol();

    QByteArray textMessage(QString message);
    QByteArray isTypingMessage();
    QByteArray setNameMessage(QString name);
    QByteArray setStatusMessage(Status status);

    QByteArray setRequestUploadMessage(QString filename);
    QByteArray setAcceptUploadMessage();
    QByteArray setRejectUploadMessage();
    QByteArray setUploadMessage(QString filename);

    void parseData(QByteArray data);

    QString message() const;
    QString username() const;
    QString filename() const;
    qint64 filesize() const;
    QByteArray filedata() const;
    Status status() const;
    MessageType type() const;

private:
    QByteArray convertData(MessageType type, QString data);

    MessageType _type;
    Status _status;

    QString _message;
    QString _username;
    QString _filename;

    qint64 _filesize = 0;
    QByteArray _filedata;
};

#endif // MESSAGEPROTOCOL_H
