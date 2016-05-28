/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#ifndef _LIB_DS_PRIVATE_CONFIG_H
#define _LIB_DS_PRIVATE_CONFIG_H

#include <Core/DS_Base.h>

/**
 * This class updates the variables of the \c DriverStation class without
 * exposing potentionally dangerous/private functions to the client.
 *
 * This class is meant to be used only by protocols, we could define these
 * functions directly with each protocol, but this could increase memory usage
 * and - if not managed correctly - cause a lot of issues with the event system
 * of Qt.
 */
class DS_Config : public DS_Base
{
    Q_OBJECT

public:
    static DS_Config* getInstance();

    bool isEnabled() const
    {
        return enableStatus() == DS_Common::kRobotEnabled;
    }

    bool isConnectedToRadio() const
    {
        return radioCommStatus() == DS_Common::kCommsWorking;
    }

    bool isConnectedToRobot() const
    {
        return robotCommStatus() == DS_Common::kCommsWorking;
    }

    bool isFMSAttached() const
    {
        return fmsCommStatus() == DS_Common::kCommsWorking;
    }

    bool isEmergencyStopped() const
    {
        return operationStatus() == DS_Common::kEmergencyStop;
    }

    bool isRobotCodeRunning() const
    {
        return robotCodeStatus() == DS_Common::kCodeRunning;
    }

    int team() const;
    float voltage() const;
    Alliance alliance() const;
    Position position() const;
    QString libVersion() const;
    QString pcmVersion() const;
    QString pdpVersion() const;
    ControlMode controlMode() const;
    CommStatus fmsCommStatus() const;
    EnableStatus enableStatus() const;
    CommStatus radioCommStatus() const;
    CommStatus robotCommStatus() const;
    CodeStatus robotCodeStatus() const;
    VoltageStatus voltageStatus() const;
    OperationStatus operationStatus() const;

public slots:
    void updateTeam (const int& team);
    void updateCpuUsage (const int& usage);
    void updateVoltage (const float& voltage);
    void updateEnable (const EnableStatus& statusChanged);
    void updateAlliance (const Alliance& alliance);
    void updatePosition (const Position& position);
    void updateLibVersion (const QString& version);
    void updatePcmVersion (const QString& version);
    void updatePdpVersion (const QString& version);
    void updateControlMode (const ControlMode& mode);
    void updateFMSCommStatus (const CommStatus& statusChanged);
    void updateRadioCommStatus (const CommStatus& statusChanged);
    void updateRobotCommStatus (const CommStatus& statusChanged);
    void updateRobotCodeStatus (const CodeStatus& statusChanged);
    void updateVoltageStatus (const VoltageStatus& statusChanged);
    void updateRamUsage (const int& usage, const int& total);
    void updateDiskUsage (const int& usage, const int& total);
    void updateOperationStatus (const OperationStatus& statusChanged);

    void setEmergencyStop (const bool& estop)
    {
        DS_Common::OperationStatus status = DS_Common::kNormal;
        if (estop) status = DS_Common::kEmergencyStop;

        updateOperationStatus (status);
    }

    void setEnabled (const bool& enabled)
    {
        DS_Common::EnableStatus status = DS_Common::kRobotDisabled;
        if (enabled) status = DS_Common::kRobotEnabled;

        updateEnable (status);
    }

    void setRobotCode (const bool& code)
    {
        DS_Common::CodeStatus status = DS_Common::kCodeFailing;
        if (code) status = DS_Common::kCodeRunning;

        updateRobotCodeStatus (status);
    }

    void setBrownout (const bool& brownout)
    {
        DS_Common::VoltageStatus status = DS_Common::kVoltageNormal;
        if (brownout) status = DS_Common::kVoltageBrownout;

        updateVoltageStatus (status);
    }

protected:
    DS_Config();

private:
    int m_team;
    float m_voltage;
    Alliance m_alliance;
    Position m_position;
    QString m_libVersion;
    QString m_pcmVersion;
    QString m_pdpVersion;
    CodeStatus m_codeStatus;
    ControlMode m_controlMode;
    CommStatus m_fmsCommStatus;
    EnableStatus m_enableStatus;
    CommStatus m_radioCommStatus;
    CommStatus m_robotCommStatus;
    VoltageStatus m_voltageStatus;
    OperationStatus m_operationStatus;
};

#endif
