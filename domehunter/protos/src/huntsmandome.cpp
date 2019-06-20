#include "huntsmandome.h"

HuntsmanDome::HuntsmanDome()
{
  // set some sane values
  m_bDebugLog = true;

  m_pSerx = NULL;

  shared_ptr<Channel> m_pGRPCchannel;
  std::unique_ptr<HX2Dome::Stub> m_pGRPCstub;
  m_bIsConnected = false;

  m_dHomeAz = 0;
  m_dParkAz = 0;

  m_dCurrentAzPosition = 0.0;
  // m_dCurrentElPosition = 0.0;

  m_bCalibrating = false;

  m_bParked = true;   // assume we were parked.
  m_bHomed = false;

}


HuntsmanDome::~HuntsmanDome()
{}

// Dome Communication


int HuntsmanDome::Connect()
{
  //int nErr;
  //int nState;

  if(m_pGRPCstub!=NULL)
    // see licensedinterfaces/sberrorx.h
    // if we have already connected dont connect again?
    return INVALID_COMMAND;

  // shared_ptr<Channel> pGRPCchannel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
  // std::unique_ptr<HX2Dome::Stub> pGRPCstub(HX2Dome::NewStub(pGRPCchannel));
  //
  // shared_ptr<Channel> *m_pGRPCchannel;
  // std::unique_ptr<HX2Dome::Stub> *m_pGRPCstub;
  //
  // m_pGRPCchannel = &pGRPCchannel;
  // m_pGRPCstub = &pGRPCstub;

  auto m_pGRPCchannel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
  auto m_pGRPCstub = HX2Dome::NewStub(m_pGRPCchannel);

  // Stupid way to check if the grpc connection is working
  // going to send an AzEl request through to python grpc server and have it bounce somthing back
  int rc(1);
  double az(10);
  double el(20);
  AzEl request;
  request.set_return_code( rc );
  request.set_az( az );
  request.set_el( el );
  // Container for the data we expect from the server.
  ReturnCode reply;
  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  ClientContext context;

  // The actual RPC.
  Status status = m_pGRPCstub->dapiGotoAzEl(&context, request, &reply);

  if(status.ok()) {
    m_bIsConnected = true;
    return HD_OK;
  }
  else {
    m_bIsConnected = false;
    return ERR_COMMNOLINK;
  }


}

void HuntsmanDome::Disconnect()
{
  m_bIsConnected = false;
}

// Dome API call

int HuntsmanDome::GetAzEl()
{
  return HD_OK;
}

int HuntsmanDome::GotoAzEl(double dAz, double dEl)
{
  int rc = 0;

  if(!m_bIsConnected) {
    return NOT_CONNECTED;
  }

  AzEl request;
  request.set_return_code( rc );
  request.set_az( dAz );
  request.set_el( dEl );
  // Container for the data we expect from the server.
  ReturnCode reply;
  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  ClientContext context;

  // The actual RPC.
  Status status = m_pGRPCstub->dapiGotoAzEl(&context, request, &reply);

  if(status.ok()) {
    return reply.return_code();
  }
  else {
    return ERR_CMDFAILED;
  }
}

int HuntsmanDome::Abort()
{
  return HD_OK;
}

int HuntsmanDome::Park()
{
  return HD_OK;
}

int HuntsmanDome::Unpark()
{
  return HD_OK;
}

int HuntsmanDome::FindHome()
{
  return HD_OK;
}

int HuntsmanDome::Sync()
{
  return HD_OK;
}

// command complete functions

int HuntsmanDome::GotoComplete()
{
  return HD_OK;
}

int HuntsmanDome::ParkComplete()
{
  return HD_OK;
}

int HuntsmanDome::UnparkComplete()
{
  return HD_OK;
}

int HuntsmanDome::FindHomeComplete()
{
  return HD_OK;
}

// dome controller informations

int HuntsmanDome::deviceInfoNameShort()
{
  return HD_OK;
}

int HuntsmanDome::deviceInfoNameLong()
{
  return HD_OK;
}

int HuntsmanDome::deviceInfoDetailedDescription()
{
  return HD_OK;
}

int HuntsmanDome::deviceInfoFirmwareVersion()
{
  return HD_OK;
}

int HuntsmanDome::deviceInfoModel()
{
  return HD_OK;
}
