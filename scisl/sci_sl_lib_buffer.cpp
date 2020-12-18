#include "sci_sl_lib_buffer.h"

namespace scisl {

sci_sl_lib_buffer::sci_sl_lib_buffer()
{

}

sci_sl_lib_buffer::sci_sl_lib_buffer(std::string path){
    set_path(path);
}

sci_sl_lib_buffer::~sci_sl_lib_buffer(){
    //save();
}

bool sci_sl_lib_buffer::add_library(std::string path){
    for(int i = 0; i<_name_list.size(); i++){
        if(path == _name_list[i]){
            return false;
        }
    }

    _name_list.push_back(path);
    return true;
}

void sci_sl_lib_buffer::save(){
    QFile file(QString::fromStdString(_path));
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "File open failed! path: "<<QString::fromStdString(_path);
        return;
    } else {
        qDebug() <<"File open successfully!";
    }

    QJsonArray lib_array;

    for(int i = 0; i <= _name_list.size(); i++){
        QJsonObject lib_obj;
        //存入信息
        lib_obj["path"] = QString::fromStdString(_name_list[i]);

        lib_array.append(lib_obj);
    }

    QJsonObject obj;
    obj["library"] = lib_array;

    QJsonDocument jdoc;
    jdoc.setObject(obj);
    file.write(jdoc.toJson(QJsonDocument::Indented)); //Indented:表示自动添加/n回车符
    file.close();
}

void sci_sl_lib_buffer::load(){
    _name_list.clear();
    QFile file(QString::fromStdString(_path));
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open failed! path: "<<QString::fromStdString(_path);
        return;
    } else {
        qDebug() <<"File open successfully!";
    }
    QJsonParseError *error=new QJsonParseError;
    QJsonDocument jdc=QJsonDocument::fromJson(file.readAll(),error);
    file.close();
    //判断文件是否完整
    if(error->error!=QJsonParseError::NoError)
    {
      qDebug()<<"parseJson:"<<error->errorString();
      return;
    }

    QJsonObject obj = jdc.object();

    QJsonArray lib_array = obj["library"].toArray();

    for(int i = 0; i < lib_array.size(); i++){
        QJsonObject file_obj(lib_array[i].toObject());
        _name_list.push_back(file_obj["path"].toString().toStdString());
    }

    return;
}


}
