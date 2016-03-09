#include "CConfigBase.h"
#include <QFile>
#include <QDomDocument>
#include <QString>
#include <QDir>
CConfigBase::CConfigBase()
{
 
}
//Ω‚Œˆ≈‰÷√
bool CConfigBase::parse(const std::string& rootkey, const std::string& inskey)
{
    bool bRet = false;

	QFile file(QDir::currentPath() +"/"+ QString::fromStdString(m_strFilePath+"/"+m_strFileName));
	//qDebug()<<QDir::currentPath() +"/"+ QString::fromStdString(m_strFilePath+"/"+m_strFileName);
   do
   {
	   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            break;
        }

        QDomDocument dom;

        dom.setContent(&file);

        file.close();

        QDomElement root = dom.firstChildElement(QString::fromStdString(rootkey));

        if(!root.isElement())
        {
            break;
        }

		if (inskey.empty())
		{
			onParse(root);

			bRet = true;

			break;
		}

		QDomElement instance = root.firstChildElement(QString::fromStdString(inskey));

		if (!instance.isElement())
		{
			break;
		}else
		{
			onParse(instance);
		}

        bRet = true;
   }while(0);

    return bRet;
}

bool CConfigBase::onParse(const QDomElement &root)
{

    return true;
}
