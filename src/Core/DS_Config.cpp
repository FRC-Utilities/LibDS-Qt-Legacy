/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#include "DS_Config.h"
#include "DriverStation.h"

/**
 * Initializes all the internal values
 */
DS_Config::DS_Config()
{
    m_team = 0;
    m_voltage = 0;
    m_libVersion = "";
    m_pcmVersion = "";
    m_pdpVersion = "";
    m_alliance = kRedAlliance;
    m_position = kPosition1;
    m_codeStatus = kCodeFailing;
    m_operationStatus = kNormal;
    m_fmsCommStatus = kCommsFailing;
    m_enableStatus = kRobotDisabled;
    m_voltageStatus = kVoltageNormal;
    m_radioCommStatus = kCommsFailing;
    m_robotCommStatus = kCommsFailing;
    m_controlMode = kControlTeleoperated;
}

/**
 * Returns a pointer to the only instance of this class.
 * This class must use a single instance because both the \c DriverStation class
 * and the derived protocols use this class to store and change the internal
 * variables of the library.
 */
DS_Config* DS_Config::getInstance()
{
    static DS_Config instance;
    return &instance;
}

/**
 * Returns the current team number.
 */
int DS_Config::team() const
{
    return m_team;
}

float DS_Config::voltage() const
{
    return m_voltage;
}

DS_Common::Alliance DS_Config::alliance() const
{
    return m_alliance;
}

DS_Common::Position DS_Config::position() const
{
    return m_position;
}

QString DS_Config::libVersion() const
{
    return m_libVersion;
}

QString DS_Config::pcmVersion() const
{
    return m_pcmVersion;
}

QString DS_Config::pdpVersion() const
{
    return m_pdpVersion;
}

DS_Common::ControlMode DS_Config::controlMode() const
{
    return m_controlMode;
}

DS_Common::CommStatus DS_Config::fmsCommStatus() const
{
    return m_fmsCommStatus;
}

DS_Common::EnableStatus DS_Config::enableStatus() const
{
    return m_enableStatus;
}

DS_Common::CommStatus DS_Config::radioCommStatus() const
{
    return m_radioCommStatus;
}

DS_Common::CommStatus DS_Config::robotCommStatus() const
{
    return m_robotCommStatus;
}

DS_Common::CodeStatus DS_Config::robotCodeStatus() const
{
    return m_codeStatus;
}

DS_Common::VoltageStatus DS_Config::voltageStatus() const
{
    return m_voltageStatus;
}

DS_Common::OperationStatus DS_Config::operationStatus() const
{
    return m_operationStatus;
}

void DS_Config::updateTeam (const int& team)
{
    if (m_team != team) {
        m_team = team;
        emit teamChanged (m_team);
    }
}

void DS_Config::updateCpuUsage (const int& usage)
{
    emit cpuUsageChanged (usage);
}

void DS_Config::updateVoltage (const float& voltage)
{
    if (m_voltage != voltage) {
        m_voltage = voltage;
        emit voltageChanged (m_voltage);
    }
}

void DS_Config::updateEnable (const EnableStatus& status)
{
    if (m_enableStatus != status) {
        m_enableStatus = status;
        emit enabledChanged (m_enableStatus);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}

void DS_Config::updateAlliance (const Alliance& alliance)
{
    if (m_alliance != alliance) {
        m_alliance = alliance;
        emit allianceChanged (m_alliance);
    }
}

void DS_Config::updatePosition (const Position& position)
{
    if (m_position != position) {
        m_position = position;
        emit positionChanged (m_position);
    }
}

void DS_Config::updateLibVersion (const QString& version)
{
    if (m_libVersion != version) {
        m_libVersion = version;
        emit libVersionChanged (m_libVersion);
    }
}

void DS_Config::updatePcmVersion (const QString& version)
{
    if (m_pcmVersion != version) {
        m_pcmVersion = version;
        emit pcmVersionChanged (m_pcmVersion);
    }
}

void DS_Config::updatePdpVersion (const QString& version)
{
    if (m_pdpVersion != version) {
        m_pdpVersion = version;
        emit pdpVersionChanged (m_pdpVersion);
    }
}

void DS_Config::updateRobotCodeStatus (const CodeStatus& status)
{
    if (m_codeStatus != status) {
        m_codeStatus = status;
        emit codeStatusChanged (status);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}

void DS_Config::updateControlMode (const ControlMode& mode)
{
    if (m_controlMode != mode) {
        m_controlMode = mode;
        emit controlModeChanged (m_controlMode);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}

void DS_Config::updateFMSCommStatus (const CommStatus& status)
{
    if (m_fmsCommStatus != status) {
        m_fmsCommStatus = status;
        emit fmsCommStatusChanged (m_fmsCommStatus);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}

void DS_Config::updateRadioCommStatus (const CommStatus& status)
{
    if (m_radioCommStatus != status) {
        m_radioCommStatus = status;
        emit radioCommStatusChanged (m_radioCommStatus);
    }
}

void DS_Config::updateRobotCommStatus (const CommStatus& status)
{
    if (m_robotCommStatus != status) {
        m_robotCommStatus = status;
        emit robotCommStatusChanged (m_robotCommStatus);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}

void DS_Config::updateVoltageStatus (const VoltageStatus& status)
{
    if (m_voltageStatus != status) {
        m_voltageStatus = status;
        emit voltageStatusChanged (m_voltageStatus);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}

void DS_Config::updateRamUsage (const int& usage, const int& total)
{
    emit ramUsageChanged (usage, total);
}

void DS_Config::updateDiskUsage (const int& usage, const int& total)
{
    emit diskUsageChanged (usage, total);
}

void DS_Config::updateOperationStatus (const OperationStatus& status)
{
    if (m_operationStatus != status) {
        m_operationStatus = status;
        emit operationStatusChanged (m_operationStatus);
        emit statusChanged (DriverStation::getInstance()->generalStatus());
    }
}