#include "sci_sl_file.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

sci_sl_file::sci_sl_file()
{

}

void extend(scicore::sci_file* root,QJsonObject* obj){
    (*obj)["name"] = QString::fromStdString(root->get_name());
    (*obj)["content"] = QString::fromStdString(root->write());

    QJsonArray child_arr;
    for(int i = 0; i<root->child_count(); i++){
        QJsonObject* child_obj = new QJsonObject;

        extend(root->get_child(i),child_obj);

        child_arr.append(*child_obj);
    }

    (*obj)["children"] = child_arr;
}

void sci_sl_file::save(scicore::sci_file* root,std::string path)
{
    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "File open failed!";
    } else {
        qDebug() <<"File open successfully!";
    }

    QJsonObject obj;
    extend(root,&obj);

    QJsonDocument jdoc;
    jdoc.setObject(obj);
    file.write(jdoc.toJson(QJsonDocument::Indented)); //Indented:表示自动添加/n回车符
    file.close();
}

//file已经创建好了
void expand(scicore::sci_file* file, QJsonObject* obj){

    if(!file){
        return;
    }

    QJsonArray child_array = (*obj)["children"].toArray();

    for(int i = 0; i < child_array.size(); i++){
        QJsonObject* child= new QJsonObject(child_array[i].toObject());
        scicore::sci_file* child_file;
        if((*child)["content"] == "folder"){
            child_file = new scicore::sci_folder((*child)["name"].toString().toStdString(),file);
        }
        //还有其他文件

        file->add_file(child_file);
        expand(child_file,child);
    }

}

scicore::sci_file* sci_sl_file::load(std::string path){
    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open failed!";
    } else {
        qDebug() <<"File open successfully!";
    }
    QJsonParseError *error=new QJsonParseError;
    QJsonDocument jdc=QJsonDocument::fromJson(file.readAll(),error);

    //判断文件是否完整
    if(error->error!=QJsonParseError::NoError)
    {
      qDebug()<<"parseJson:"<<error->errorString();
      return NULL;
    }


    QJsonObject obj = jdc.object();        //获取对象

    scicore::sci_file* root = new scicore::sci_folder(obj["name"].toString().toStdString());

    expand(root,&obj);

    //qDebug() <<"object size:"<<obj.size();


    return root;
}
