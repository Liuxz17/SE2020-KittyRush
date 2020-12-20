#include "sci_sl_file.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QDateTime>

namespace scisl {

sci_sl_file::sci_sl_file()
{

}

char* sci_sl_file::path(){
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyyMMdd_hhmmss_zzzddd") + ".info";
    return (char*)current_date.toStdString().c_str();
}

}
