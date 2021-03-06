/********************************************************************
*
*   File: ccommanager.h    Class: CComManager
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
#ifndef CCOMMANAGER_H
#define CCOMMANAGER_H

#include <QObject>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QList>
#include <wiringSerial.h>

class CComManager : public QObject
{
    Q_OBJECT

    QSerialPort* m_VECport;
    QSerialPort* m_VEMport;
    QByteArray   m_Data;

    QSerialPort *m_Port;

public:
    explicit CComManager(QObject *parent = 0);
    ~CComManager();
public slots:
    void readData();
private:
    QSerialPort *FindModule(QString pModul);

};

#endif // CCOMMANAGER_H
