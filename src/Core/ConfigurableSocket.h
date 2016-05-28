/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#ifndef _LIB_DS_CONFIGURABLE_SOCKET_H
#define _LIB_DS_CONFIGURABLE_SOCKET_H

#include <QTcpSocket>
#include <QUdpSocket>
#include <Core/DS_Common.h>

class ConfigurableSocket
{
public:
    explicit ConfigurableSocket (const DS_Common::SocketType& type);

    QAbstractSocket* socket() const;
    DS_Common::SocketType socketType() const;

    qint64 writeDatagram (const QByteArray& data, const QString& ip, quint16 port);
    qint64 writeDatagram (const QByteArray& data, const QHostAddress& ip,
                          quint16 port);

    void bind (const QString& ip, quint16 port, QAbstractSocket::BindMode mode);
    void bind (const QHostAddress& ip, quint16 port,
               QAbstractSocket::BindMode mode);
    void connectToHost (const QString& host, quint16 port,
                        QIODevice::OpenMode mode);
    void connectToHost (const QHostAddress& host, quint16 port,
                        QIODevice::OpenMode mode);

private:
    QUdpSocket m_udpSocket;
    QTcpSocket m_tcpSocket;
    QAbstractSocket* m_socket;
    DS_Common::SocketType m_socketType;
};

#endif

