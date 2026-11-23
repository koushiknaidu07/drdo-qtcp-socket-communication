
#ifndef MESSAGEPROTOCOL_H
#define MESSAGEPROTOCOL_H

#include <QString>
#include <QByteArray>
#include <QtGlobal>

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
        Online,
        Offline,
        Away
    };

    MessageProtocol();

    static QByteArray textMessage(QString message);
    static QByteArray isTypingMessage();
    static QByteArray setNameMessage(QString name);
    static QByteArray setStatusMessage(Status status);

    static QByteArray setRequestUploadMessage(QString filename);
    static QByteArray setAcceptUploadMessage();
    static QByteArray setRejectUploadMessage();
    static QByteArray setUploadMessage(QString filename);

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
