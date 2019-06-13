#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
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

#ifdef BAZEL_BUILD
#include "/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/x2dome.grpc.pb.h"
#else
#include "x2dome.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using x2dome::ReturnCode;
using x2dome::AzEl;
using x2dome::IsComplete;
using x2dome::BasicString;
using x2dome::X2Dome;

// HuntsmanDome hdome(grpc::CreateChannel(
//     "localhost:50051", grpc::InsecureChannelCredentials()));

class HuntsmanDome
{
public:
  HuntsmanDome(std::shared_ptr<Channel> channel)
      : stub_(X2Dome::NewStub(channel)) {}
  ~HuntsmanDome();

  int Connect();
  void Disconnect(void);
  bool IsConnected(void) { return m_bIsConnected; }

  void    SetSerxPointer(SerXInterface *p) { m_pSerx = p; }
  void    setLogger(LoggerInterface *pLogger) { m_pLogger = pLogger; };


  int GetAzEl ();
  int GotoAzEl ();
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
  SerXInterface*  m_pSerx;
  LoggerInterface*    m_pLogger;
  bool            m_bDebugLog;

  bool            m_bIsConnected;
  bool            m_bHomed;
  bool            m_bParked;
  bool            m_bCalibrating;

  double          m_dHomeAz;
  double          m_dParkAz;
  double          m_dCurrentAzPosition;
  double          m_dCurrentElPosition;
  double          m_dGotoAz;
  double          m_dGotoEl;
  int             m_nTargetAdc;

};
