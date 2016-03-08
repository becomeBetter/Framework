#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
    m_strFilePath = "Config";

    m_strFileName = "RC_DTL_TCPServer.xml";

	m_iListenPort = 8888;
}

bool CConfig::onParse(const QDomElement &root)
{
	QDomElement port = root.firstChildElement("Port");

	if (port.isElement())
	{
		m_iListenPort = port.text().toInt();
	}
    return true;
}

int CConfig::getListenPort() const
{
	return m_iListenPort;
}
