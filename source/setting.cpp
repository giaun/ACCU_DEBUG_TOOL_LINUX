#include "setting.h"
#include <QDebug>

Setting::Setting(QObject *parent) : QObject(parent)
{
	qDebug() << "Setting()";
}
