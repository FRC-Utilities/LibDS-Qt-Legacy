/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#ifndef _LIB_DS_SOCKETS_H
#define _LIB_DS_SOCKETS_H

#include <Core/ConfigurableSocket.h>

class Sockets : public QObject
{
    Q_OBJECT

public:
    Sockets();
    ~Sockets();

    int socketCount() const;
    int fmsInputPort() const;
    int fmsOutputPort() const;
    int radioInputPort() const;
    int robotInputPort() const;
    int radioOutputPort() const;
    int robotOutputPort() const;

    QString radioIp() const;
    QString robotIp() const;
    QStringList robotIpList() const;

    DS_Common::SocketType fmsSocketType() const;
    DS_Common::SocketType radioSocketType() const;
    DS_Common::SocketType robotSocketType() const;

public slots:
    void sendToFMS (const QByteArray& data);
    void sendToRobot (const QByteArray& data);
    void sendToRadio (const QByteArray& data);

    void setRadioIp (const QString& ip);
    void setRobotIp (const QString& ip);
    void setRobotIpList (const QStringList& list);

    void setSocketCount (const int& count);

    void setFMSInputPort (const int& port);
    void setFMSOutputPort (const int& port);
    void setRadioInputPort (const int& port);
    void setRobotInputPort (const int& port);
    void setRadioOutputPort (const int& port);
    void setRobotOutputPort (const int& port);

    void setFMSSocketType (const DS_Common::SocketType& type);
    void setRadioSocketType (const DS_Common::SocketType& type);
    void setRobotSocketType (const DS_Common::SocketType& type);

signals:
    void fmsPacketReceived (QByteArray data);
    void radioPacketReceived (QByteArray data);
    void robotPacketReceived (QByteArray data);

private slots:
    void readFMSData();
    void readRadioData();
    void readRobotData();
    void refreshRobotIPs();
    void clearSocketLists();
    void generateSocketPairs();
    void generateLocalNetworkAddresses();

private:
    QString m_robotIp;
    QString m_radioIp;
    QStringList m_robotIpList;

    ConfigurableSocket* m_robotSender;
    ConfigurableSocket* m_fmsSender;
    ConfigurableSocket* m_fmsReceiver;
    ConfigurableSocket* m_radioSender;
    ConfigurableSocket* m_radioReceiver;

    QList<ConfigurableSocket*> m_robotSenderList;
    QList<ConfigurableSocket*> m_robotInputSockets;

    int m_fmsInput;
    int m_fmsOutput;
    int m_radioInput;
    int m_robotInput;
    int m_radioOutput;
    int m_robotOutput;

    int m_socketCount;
    int m_iterator;

    DS_Common::SocketType m_fmsSocketType;
    DS_Common::SocketType m_radioSocketType;
    DS_Common::SocketType m_robotSocketType;
};

#endif
