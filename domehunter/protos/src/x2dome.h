#include <stdio.h>
#include <string.h>

#include "licensedinterfaces/sberrorx.h"
#include "licensedinterfaces/basicstringinterface.h"
#include "licensedinterfaces/serxinterface.h"
#include "licensedinterfaces/basiciniutilinterface.h"
#include "licensedinterfaces/theskyxfacadefordriversinterface.h"
#include "licensedinterfaces/sleeperinterface.h"
#include "licensedinterfaces/loggerinterface.h"
#include "licensedinterfaces/basiciniutilinterface.h"
#include "licensedinterfaces/mutexinterface.h"
#include "licensedinterfaces/tickcountinterface.h"
#include "licensedinterfaces/domedriverinterface.h"

#include <iostream>
#include <memory>
//#include <string>

// #include <grpcpp/grpcpp.h>
// #include "hx2dome.grpc.pb.h"
#include "huntsmandome.h"

// using grpc::Channel;
// using grpc::ClientContext;
// using grpc::Status;
// using hx2dome::ReturnCode;
// using hx2dome::AzEl;
// using hx2dome::IsComplete;
// using hx2dome::BasicString;
// using hx2dome::HX2Dome;

//

class X2Dome: DomeDriverInterface
{
public:

	/*!Standard X2 constructor*/
	X2Dome(	const char* pszSelectionString,
					const int& nISIndex,
					SerXInterface*						pSerX,
					TheSkyXFacadeForDriversInterface* pTheSkyXForMounts,
					SleeperInterface*				pSleeper,
					BasicIniUtilInterface*			pIniUtil,
					LoggerInterface*					pLogger,
					MutexInterface*					pIOMutex,
					TickCountInterface*				pTickCount);
	virtual ~X2Dome();

	/*!\name DriverRootInterface Implementation
	See DriverRootInterface.*/
	//@{
	virtual DeviceType							deviceType(void)							  {return DriverRootInterface::DT_DOME;}
	virtual int									queryAbstraction(const char* pszName, void** ppVal);
	//@}

	/*!\name LinkInterface Implementation
	See LinkInterface.*/
	//@{
	virtual int									establishLink(void)						;
	virtual int									terminateLink(void)						;
	virtual bool								isLinked(void) const					;
	//@}

	/*!\name HardwareInfoInterface Implementation
	See HardwareInfoInterface.*/
	//@{
	virtual void deviceInfoNameShort(BasicStringInterface& str) const					;
	virtual void deviceInfoNameLong(BasicStringInterface& str) const					;
	virtual void deviceInfoDetailedDescription(BasicStringInterface& str) const		;
	virtual void deviceInfoFirmwareVersion(BasicStringInterface& str)					;
	virtual void deviceInfoModel(BasicStringInterface& str)							;
	//@}

	/*!\name DriverInfoInterface Implementation
	See DriverInfoInterface.*/
	//@{
	virtual void								driverInfoDetailedInfo(BasicStringInterface& str) const	;
	virtual double								driverInfoVersion(void) const								;
	//@}

	//DomeDriverInterface
	virtual int dapiGetAzEl(double* pdAz, double* pdEl);
	virtual int dapiGotoAzEl(double dAz, double dEl);
	virtual int dapiAbort(void);
	virtual int dapiOpen(void);
	virtual int dapiClose(void);
	virtual int dapiPark(void);
	virtual int dapiUnpark(void);
	virtual int dapiFindHome(void);
	virtual int dapiIsGotoComplete(bool* pbComplete);
	virtual int dapiIsOpenComplete(bool* pbComplete);
	virtual int	dapiIsCloseComplete(bool* pbComplete);
	virtual int dapiIsParkComplete(bool* pbComplete);
	virtual int dapiIsUnparkComplete(bool* pbComplete);
	virtual int dapiIsFindHomeComplete(bool* pbComplete);
	virtual int dapiSync(double dAz, double dEl);


private:

	SerXInterface 									*	GetSerX() {return m_pSerX; }
	TheSkyXFacadeForDriversInterface				*	GetTheSkyXFacadeForDrivers() {return m_pTheSkyXForMounts;}
	SleeperInterface								*	GetSleeper() {return m_pSleeper; }
	BasicIniUtilInterface							*	GetSimpleIniUtil() {return m_pIniUtil; }
	LoggerInterface									*	GetLogger() {return m_pLogger; }
	MutexInterface									*	GetMutex()  {return m_pIOMutex;}
	TickCountInterface								*	GetTickCountInterface() {return m_pTickCount;}

	SerXInterface									*	m_pSerX;
	TheSkyXFacadeForDriversInterface				*	m_pTheSkyXForMounts;
	SleeperInterface								*	m_pSleeper;
	BasicIniUtilInterface							*	m_pIniUtil;
	LoggerInterface									*	m_pLogger;
	MutexInterface									*	m_pIOMutex;
	TickCountInterface								*	m_pTickCount;

	int m_nPrivateISIndex;

	int m_bLinked;

	HuntsmanDome m_HuntsmanDome;


};
