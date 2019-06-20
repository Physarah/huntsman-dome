#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
// #include <string.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <time.h>
#include <stdint.h>


#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "licensedinterfaces/sberrorx.h"
#include "licensedinterfaces/serxinterface.h"
#include "licensedinterfaces/loggerinterface.h"

#include <grpcpp/grpcpp.h>

#include "hx2dome.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hx2dome::ReturnCode;
using hx2dome::AzEl;
using hx2dome::IsComplete;
using hx2dome::BasicString;
using hx2dome::HX2Dome;
using std::shared_ptr;
using std::unique_ptr;

enum HuntsmanDomeErrors {HD_OK=0, NOT_CONNECTED, HD_CANT_CONNECT, HD_BAD_CMD_RESPONSE, COMMAND_FAILED, INVALID_COMMAND};

class HuntsmanDome
{
public:
  HuntsmanDome();
  ~HuntsmanDome();

  int Connect();
  void Disconnect(void);
  bool IsConnected(void) { return m_bIsConnected; }

  // SerXInterface is a standard way for serial devices and X2 drivers to communicate
  // We are using gRPC instead
  void    SetSerxPointer(SerXInterface *p) { m_pSerx = p; }
  void    setLogger(LoggerInterface *pLogger) { m_pLogger = pLogger; };


  int GetAzEl ();
  int GotoAzEl (double dAz, double dEl);
  int Abort ();
  // int Open ();
  // int Close ();
  int Park ();
  int Unpark ();
  int FindHome ();
  int GotoComplete ();
  // int OpenComplete ();
  // int CloseComplete ();
  int ParkComplete ();
  int UnparkComplete ();
  int FindHomeComplete ();
  int Sync ();
  // Hardware Info Interface
  int deviceInfoNameShort ();
  int deviceInfoNameLong ();
  int deviceInfoDetailedDescription ();
  int deviceInfoFirmwareVersion ();
  int deviceInfoModel ();

protected:



  // I dont know if these will be usefull later - fergus
  SerXInterface*                m_pSerx;
  shared_ptr<Channel>           m_pGRPCchannel;
  unique_ptr<HX2Dome::Stub>     m_pGRPCstub;
  LoggerInterface*              m_pLogger;
  bool                          m_bDebugLog;

  bool                          m_bIsConnected;
  bool                          m_bHomed;
  bool                          m_bParked;
  bool                          m_bCalibrating;

  double                        m_dHomeAz;
  double                        m_dParkAz;
  double                        m_dCurrentAzPosition;
  double                        m_dCurrentElPosition;
  double                        m_dGotoAz;
  double                        m_dGotoEl;
  int                           m_nTargetAdc;

};
