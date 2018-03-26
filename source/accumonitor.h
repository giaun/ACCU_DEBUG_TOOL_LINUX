#ifndef AccuMonitor_H
#define AccuMonitor_H

#include <QtSerialPort/QSerialPort>
#include <QObject>


class AccuMonitor : public QObject
{
	Q_OBJECT

public:

	Q_PROPERTY(QString port READ getPort WRITE setPort NOTIFY portChanged)
	Q_PROPERTY(QString baudRate READ getBaudRate WRITE setBaudRate)
	Q_PROPERTY(QString dataBits READ getDataBits WRITE setDataBits)
	Q_PROPERTY(qint32 parity READ getParity WRITE setParity)
	Q_PROPERTY(QString stopBits READ getStopBits WRITE setStopBits)
	Q_PROPERTY(qint32 flowControl READ getFlowControl WRITE setFlowControl)
	Q_PROPERTY(bool enableEcho READ getEnableEcho WRITE setEnableEcho NOTIFY enableEchoChanged)
	Q_PROPERTY(QString consoleData READ getConsoleData WRITE setConsoleData NOTIFY consoleDataChanged)

	Q_INVOKABLE bool consoleConnect();
	Q_INVOKABLE void consoleDisconnect();
	Q_INVOKABLE void foo();
	Q_INVOKABLE void writeConsole(QString data);
	Q_INVOKABLE void updateSettingInfo();

	explicit AccuMonitor(QObject *parent = nullptr);
	~AccuMonitor();

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



	QString getPort() const;
	void setPort(const QString &value);

	QString getBaudRate() const;
	void setBaudRate(const QString &value);

	QString getDataBits() const;
	void setDataBits(const QString &value);

	qint32 getParity() const;
	void setParity(const qint32 &value);

	QString getStopBits() const;
	void setStopBits(const QString &value);

	qint32 getFlowControl() const;
	void setFlowControl(const qint32 &value);

	bool getEnableEcho() const;
	void setEnableEcho(bool value);

	QString getConsoleData() const;
	void setConsoleData(const QString &value);

signals:
	void portChanged();
	void enableEchoChanged();
	void consoleDataChanged();
public slots:
	void readData();

private:

	Settings currentSetting;
	QSerialPort *serialPort;

	QString port;
	QString baudRate;
	QString dataBits;
	qint32 parity;
	QString stopBits;
	qint32 flowControl;
	bool enableEcho;

	QString consoleData;


};

#endif // AccuMonitor_H
