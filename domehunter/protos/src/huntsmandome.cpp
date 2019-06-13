#include "huntsmandome.h"

HuntsmanDome::HuntsmanDome()
{
  // set some sane values
  m_bDebugLog = true;

  m_pSerx = NULL;
  m_bIsConnected = false;

  m_dHomeAz = 0;
  m_dParkAz = 0;

  m_dCurrentAzPosition = 0.0;
  m_dCurrentElPosition = 0.0;

  m_bCalibrating = false;

  m_bParked = true;   // assume we were parked.
  m_bHomed = false;

}


HuntsmanDome::~HuntsmanDome()
{}

#pragma mark - Dome Communication

int HuntsmanDome::Connect()
{
  m_bIsConnected = True;
}

void HuntsmanDome::Disconnect()
{
  m_bIsConnected = False;
}

#pragma mark - Dome API call

int HuntsmanDome::GetAzEl();
{}

int HuntsmanDome::GotoAzEl()
{}

int HuntsmanDome::Abort()
{}

int HuntsmanDome::Park()
{}

int HuntsmanDome::Unpark()
{}

int HuntsmanDome::FindHome()
{}

int HuntsmanDome::GetAzEl()
{}

int HuntsmanDome::Sync()
{}

#pragma mark - command complete functions

int HuntsmanDome::GotoComplete()
{}

int HuntsmanDome::ParkComplete()
{}

int HuntsmanDome::UnparkComplete()
{}

int HuntsmanDome::FindHomeComplete()
{}

#pragma mark - dome controller informations

int HuntsmanDome::deviceInfoNameShort()
{}

int HuntsmanDome::deviceInfoNameLong()
{}

int HuntsmanDome::deviceInfoDetailedDescription()
{}

int HuntsmanDome::deviceInfoFirmwareVersion()
{}

int HuntsmanDome::deviceInfoModel()
{}
