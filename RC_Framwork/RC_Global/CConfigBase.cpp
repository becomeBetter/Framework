#include "CConfigBase.h"
#include <QFile>
#include <QDomDocument>
#include <QString>
#include <QDir>
CConfigBase::CConfigBase()
{
 
}
//Ω‚Œˆ≈‰÷√
bool CConfigBase::parse(const std::string& rootkey)
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

        onParse(root);

        bRet = true;
   }while(0);

    return bRet;
}

bool CConfigBase::onParse(const QDomElement &root)
{

    return true;
}
