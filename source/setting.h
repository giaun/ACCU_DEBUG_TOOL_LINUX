#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class Setting : public QObject
{
	Q_OBJECT
public:
	explicit Setting(QObject *parent = nullptr);

	struct Settings {
		QString name;
		qint32 baudRate;
		QString stringBaudRate;
		QSerialPort::DataBits dataBits;
		QString stringDataBits;
		QSerialPort::Parity parity;
		QString stringParity;
		QSerialPort::StopBits stopBits;
		QString stringStopBits;
		QSerialPort::FlowControl flowControl;
		QString stringFlowControl;
		bool localEchoEnabled;
	};

signals:

public slots:

private:
	Settings currentSetting;
};

#endif // SETTING_H
