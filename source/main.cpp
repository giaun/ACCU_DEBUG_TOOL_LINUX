#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QDebug>
#include "accumonitor.h"
//#include "setting.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	AccuMonitor accu;
//	Setting	setting;
//	QObject::connect(&accu, SIGNAL(trangthaithaydoi(QString)), &settinggiau, SLOT(capnhattrangthai(QString)));

	/*QML register custom list model and contect cameralist to qml*/
	qmlRegisterType<AccuMonitor>("AccuMonitor", 1, 0, "AccuMonitor");
//	qmlRegisterUncreatableType<Setting>("Setting", 1, 0, "Setting", QStringLiteral("Setting should not be created in QML"));


	engine.rootContext()->setContextProperty(QStringLiteral("accumonitor"),&accu);
//	engine.rootContext()->setContextProperty(QStringLiteral("setting"),&setting);

	engine.load(QUrl(QLatin1String("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
