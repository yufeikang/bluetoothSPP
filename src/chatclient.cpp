#include "chatclient.h"

#include <qbluetoothsocket.h>

ChatClient::ChatClient(QObject *parent)
:   QObject(parent), socket(0)
{
}

ChatClient::~ChatClient()
{
    stopClient();
}

void ChatClient::startClient(const QBluetoothServiceInfo &remoteService)
{
    if (socket)
        return;

    // Connect to service
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    qDebug() << "Create socket";
    socket->connectToService(remoteService);
    qDebug() << "ConnectToService done";

    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
}

void ChatClient::stopClient()
{
    delete socket;
    socket = 0;
}

void ChatClient::readSocket()
{
    if (!socket)
        return;
    QByteArray data = socket->readAll();
    emit messageReceived(socket->peerName(),data);
}

void ChatClient::sendMessage(const QByteArray &message)
{
    socket->write(message);
}

void ChatClient::connected()
{
    emit connected(socket->peerName());
}
