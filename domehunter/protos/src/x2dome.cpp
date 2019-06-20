#include "x2dome.h"

X2Dome::X2Dome(const char* pszSelection,
							 const int& nISIndex,
							 			 SerXInterface*						pSerX,
										 TheSkyXFacadeForDriversInterface*	pTheSkyXForMounts,
										 SleeperInterface*					pSleeper,
										 BasicIniUtilInterface*			pIniUtil,
										 LoggerInterface*					pLogger,
										 MutexInterface*						pIOMutex,
										 TickCountInterface*					pTickCount)
{
	m_nPrivateISIndex				= nISIndex;
	m_pSerX							    = pSerX;
	m_pTheSkyXForMounts			= pTheSkyXForMounts;
	m_pSleeper						  = pSleeper;
	m_pIniUtil						  = pIniUtil;
	m_pLogger						    = pLogger;
	m_pIOMutex						  = pIOMutex;
	m_pTickCount					  = pTickCount;

	m_bLinked = false;
	// m_HuntsmanDome.something(something);
}


X2Dome::~X2Dome()
{
	if (m_pSerX)
		delete m_pSerX;
	if (m_pTheSkyXForMounts)
		delete m_pTheSkyXForMounts;
	if (m_pSleeper)
		delete m_pSleeper;
	if (m_pIniUtil)
		delete m_pIniUtil;
	if (m_pLogger)
		delete m_pLogger;
	if (m_pIOMutex)
		delete m_pIOMutex;
	if (m_pTickCount)
		delete m_pTickCount;

}


int X2Dome::establishLink(void)
{
	// if (GetLogger())
	// 	GetLogger()->out("X2Dome::establishLink");
	int nErr;
	nErr = m_HuntsmanDome.Connect();
	if(nErr)
		m_bLinked = false;
	else
		m_bLinked = true;
	return SB_OK;
}
int X2Dome::terminateLink(void)
{
	if (GetLogger())
		GetLogger()->out("X2Dome::terminateLink");

	m_bLinked = false;
	return SB_OK;
}
 bool X2Dome::isLinked(void) const
{
	return m_bLinked;
}


//HardwareInfoInterface
void X2Dome::deviceInfoNameShort(BasicStringInterface& str) const
{
	str = "HuntsmanDome";
}
void X2Dome::deviceInfoNameLong(BasicStringInterface& str) const
{
	str = "Huntsman Telescope Dome Controller";
}
void X2Dome::deviceInfoDetailedDescription(BasicStringInterface& str) const
{
	str = "AAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH";
}
 void X2Dome::deviceInfoFirmwareVersion(BasicStringInterface& str)
 {
	 X2MutexLocker ml(GetMutex());
	 if(m_bLinked) {
			 str = "N/A";
	 }
	 else
			 str = "N/A";
 }
void X2Dome::deviceInfoModel(BasicStringInterface& str)
{
	X2MutexLocker ml(GetMutex());
	if(m_bLinked) {
			str = "N/A";
	}
	else
			str = "N/A";
}

//DriverInfoInterface
 void	X2Dome::driverInfoDetailedInfo(BasicStringInterface& str) const
{
	str = "Send help.";
}
double	X2Dome::driverInfoVersion(void) const
{
	return 1.0;
}

//DomeDriverInterface
int X2Dome::dapiGetAzEl(double* pdAz, double* pdEl)
{
	if (GetLogger())
		GetLogger()->out("X2Dome::dapiGetAzEl");

	return SB_OK;
}

int X2Dome::dapiGotoAzEl(double dAz, double dEl)
{
	int nErr = SB_OK;

	X2MutexLocker ml(GetMutex());

	if(!m_bLinked)
			return ERR_NOLINK;

	nErr = m_HuntsmanDome.GotoAzEl(dAz, dEl);
	if(nErr)
			return ERR_CMDFAILED;

	return nErr;
}
int X2Dome::dapiAbort(void)
{
	return SB_OK;
}
int X2Dome::dapiOpen(void)
{
	return SB_OK;
}
int X2Dome::dapiClose(void)
{
	return SB_OK;
}
int X2Dome::dapiPark(void)
{
	return SB_OK;
}

int X2Dome::dapiUnpark(void)
{
	return SB_OK;
}
int X2Dome::dapiFindHome(void)
{
	return SB_OK;
}
int X2Dome::dapiIsGotoComplete(bool* pbComplete)
{
	return SB_OK;
}

int X2Dome::dapiIsOpenComplete(bool* pbComplete)
{
	return SB_OK;
}
int	X2Dome::dapiIsCloseComplete(bool* pbComplete)
{
	return SB_OK;
}
int X2Dome::dapiIsParkComplete(bool* pbComplete)
{
	return SB_OK;
}
int X2Dome::dapiIsUnparkComplete(bool* pbComplete)
{
	return SB_OK;
}
int X2Dome::dapiIsFindHomeComplete(bool* pbComplete)
{
	return SB_OK;
}
int X2Dome::dapiSync(double dAz, double dEl)
{
	return SB_OK;

}

int X2Dome::queryAbstraction(const char* pszName, void** ppVal)
{
	*ppVal = NULL;

	//Add support for the optional LoggerInterface
	if (!strcmp(pszName, LoggerInterface_Name))
		*ppVal = GetLogger();

	return SB_OK;
}
