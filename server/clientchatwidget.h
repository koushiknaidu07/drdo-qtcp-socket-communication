
#ifndef CLIENTCHATWIDGET_H
#define CLIENTCHATWIDGET_H

#include <QWidget>
#include <QTcpSocket>

#include "clientmanager.h"
#include "messageprotocol.h"

namespace Ui {
class ClientChatWidget;
}

class ClientChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChatWidget(
        QTcpSocket* client,
        QWidget* parent = nullptr
    );

    ~ClientChatWidget();

signals:
    void disconnected();
    void clientNameChanged(QString name);
    void clientStatusChanged(MessageProtocol::Status status);
    void clientIsTyping(QString name);

private slots:
    void on_btn_send_clicked();

    void clientDisconnected();
    void messageReceived(QString message);
    void nameChanged(QString name);

    void statusChanged(MessageProtocol::Status status);
    void onTyping();

    void handleFileRequest(
        QString username,
        QString filename,
        qint64 filesize
    );

    void onFileSaved(QString path);

private:
    Ui::ClientChatWidget *ui;
    ClientManager *_client;
};

#endif // CLIENTCHATWIDGET_H
