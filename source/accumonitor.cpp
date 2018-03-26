#include "accumonitor.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QQmlProperty>
#include <QDebug>

AccuMonitor::AccuMonitor(QObject *parent) : QObject(parent)
{
	qDebug() << "AccuMonitor()";
	serialPort = new QSerialPort(this);
	connect(serialPort, &QSerialPort::readyRead, this, &AccuMonitor::readData);


}

AccuMonitor::~AccuMonitor()
{
	consoleDisconnect();
	qDebug() << "~AccuMonitor()";
}

void AccuMonitor::updateSettingInfo()
{
	const auto infos = QSerialPortInfo::availablePorts();
	for (const QSerialPortInfo &info : infos) {
		port = info.portName();
		emit portChanged();
//		QStringList list;
//		QString blankString = "unknow";
//		QString description = info.description();
//		QString manufacturer = info.manufacturer();
//		QString serialNumber = info.serialNumber();
//		list << info.portName()
//			 << (!description.isEmpty() ? description : blankString)
//			 << (!manufacturer.isEmpty() ? manufacturer : blankString)
//			 << (!serialNumber.isEmpty() ? serialNumber : blankString)
//			 << info.systemLocation()
//			 << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
//			 << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

		qDebug() << port;
	}
}

QString AccuMonitor::getPort() const
{
	return port;
}

void AccuMonitor::setPort(const QString &value)
{

	if (port != value)
	{
		currentSetting.name = value;
		port = value;
		emit portChanged();
	}

}

QString AccuMonitor::getBaudRate() const
{
	return baudRate;
}

void AccuMonitor::setBaudRate(const QString &value)
{
	currentSetting.baudRate = value.toInt();
	currentSetting.stringBaudRate = value;
	baudRate = value;
}

QString AccuMonitor::getDataBits() const
{
	return dataBits;
}

void AccuMonitor::setDataBits(const QString &value)
{
	currentSetting.dataBits = static_cast <QSerialPort::DataBits> (value.toInt());
	currentSetting.stringDataBits = value;
	dataBits = value;
}

qint32 AccuMonitor::getParity() const
{
	return parity;
}

void AccuMonitor::setParity(const qint32 &value)
{
	currentSetting.parity = static_cast <QSerialPort::Parity> (value);
//	currentSetting.stringParity = currentSetting.parity;
	parity = value;
}

QString AccuMonitor::getStopBits() const
{
	return stopBits;
}

void AccuMonitor::setStopBits(const QString &value)
{
	currentSetting.stopBits = static_cast <QSerialPort::StopBits> (value.toInt());
	currentSetting.stringStopBits = value;
	stopBits = value;
}

qint32 AccuMonitor::getFlowControl() const
{
	return flowControl;
}

void AccuMonitor::setFlowControl(const qint32 &value)
{
	currentSetting.flowControl = static_cast <QSerialPort::FlowControl> (value);
//	currentSetting.stringFlowControl = value;
	flowControl = value;
}

bool AccuMonitor::getEnableEcho() const
{
	return enableEcho;
}

void AccuMonitor::setEnableEcho(bool value)
{
	if (enableEcho != value){
		currentSetting.localEchoEnabled = value;
		enableEcho = value;
		emit enableEchoChanged();
	}
}

QString AccuMonitor::getConsoleData() const
{
	return consoleData;
}

void AccuMonitor::setConsoleData(const QString &value)
{
	serialPort->write(value.toLocal8Bit());
//	consoleData = value;
//	emit consoleDataChanged();
}

void AccuMonitor::readData()
{
	QByteArray data = serialPort->readAll();
	qDebug() << data;
	consoleData = (QString(data));
	qDebug() << consoleData;
	emit consoleDataChanged();
}

bool AccuMonitor::consoleConnect()
{
	serialPort->setPortName(currentSetting.name);
	serialPort->setBaudRate(currentSetting.baudRate);
	serialPort->setDataBits(currentSetting.dataBits);
	serialPort->setParity(currentSetting.parity);
	serialPort->setStopBits(currentSetting.stopBits);
	serialPort->setFlowControl(currentSetting.flowControl);
	return serialPort->open(QSerialPort::ReadWrite);
}

void AccuMonitor::consoleDisconnect()
{
	serialPort->close();
}


void AccuMonitor::foo()
{
	qDebug() << "foo";
}

void AccuMonitor::writeConsole(QString data)
{
	serialPort->write(data.toLocal8Bit());

	//	qDebug() << on_txtConsole_Accepted();
}


