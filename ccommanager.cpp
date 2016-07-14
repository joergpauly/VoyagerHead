/********************************************************************
*
*   File: ccommanager.cpp    Class: CComManager
*
*   This file is part of the MEGA-Series Project.
*   Copyright (C) 2016 Joerg Pauly
*   Created 14.07.2016 by joerg
*   All Rights reserved
*
*   Alle Programme der MEGA-Serie sind Freie Software:
*   Sie können sie unter den Bedingungen
*   der GNU Lesser General Public License, wie von der
*   Free Software Foundation, Version 3 der Lizenz oder
*   (nach Ihrer Option) jeder späteren veröffentlichten
*   Version, weiterverbreiten und/oder modifizieren.
*
*   Dieses Programm wird in der Hoffnung, dass es nützlich
*   sein wird, aber OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt;
*   sogar ohne die implizite Gewährleistung der MARKTFÄHIGKEIT
*   oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
*   Siehe die GNU Lesser General Public License für weitere Details.
*
*   Sie sollten eine Kopie der GNU Lesser General Public License
*   zusammen mit diesem Programm erhalten haben.
*   Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*
********************************************************************/
#include "ccommanager.h"

CComManager::CComManager(QObject *parent) : QObject(parent)
{
    m_Port = new QSerialPort(this);
    connect(m_Port, SIGNAL(readyRead()), this, SIGNAL(readData()));
    m_VECport = FindModule("VEC");
    m_VEMport = FindModule("VEM");
}

CComManager::~CComManager()
{

}

void CComManager::readData()
{
    m_Data = m_Port->readAll();
}

QSerialPort *CComManager::FindModule(QString pModul)
{
    QList<QSerialPortInfo> lPortlist = QSerialPortInfo::availablePorts();
    QList<QString> lPNl;
    for(int i = 0; i < lPortlist.count(); i++)
    {
        lPNl.append(lPortlist.at(i).portName());
        if(lPortlist.at(i).portName().left(6) != "ttyACM")
        {
            lPortlist.removeAt(i);
        }
    }

    if(lPortlist.count() > 0)
    {
        for(int i = 0; i < lPortlist.count(); i++)
        {
            m_Port = new QSerialPort(lPortlist.at(i));
            m_Port->setBaudRate(QSerialPort::Baud9600);
            if(m_Port->open(QIODevice::ReadWrite))
            {
                QByteArray lar = pModul.toLatin1();
                lar.append("HELLO");
                m_Port->write(lar);
            }
        }
    }
    return 0;
}

