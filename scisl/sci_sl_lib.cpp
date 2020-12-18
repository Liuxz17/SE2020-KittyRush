#include "sci_sl_lib.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

#include "sci_sl_file_visitor_adaptor.h"
#include "scicore/sci_folder.h"
#include "scicore/sci_pdf_paper.h"


namespace scisl {

sci_sl_lib::sci_sl_lib(std::string path,scicore::sci_library* lib):_library(lib)
{
    set_path(path);
}

void sci_sl_lib::save(){

    scisl::save(_library->get_root(),_path);

}


void sci_sl_lib::load(){
    _library->set_root(scisl::load(_path));
}

void extend(scicore::sci_file* root,QJsonObject* obj){
    (*obj)["name"] = QString::fromStdString(root->get_name());
    sci_sl_file* file = sl_of_file.get_sl_file(root);

    (*obj)["type"] = file->type();
    (*obj)["path"] = file->path();
    (*obj)["desc"] = file->desc();

    delete file;
    QJsonArray child_arr;
    for(int i = 0; i<root->child_count(); i++){
        QJsonObject* child_obj = new QJsonObject;

        extend(root->get_child(i),child_obj);

        child_arr.append(*child_obj);
    }

    (*obj)["children"] = child_arr;
}

void save(scicore::sci_file* root,std::string path)
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
        if((*child)["type"] == 1){
            child_file = new scicore::sci_folder((*child)["name"].toString().toStdString(),file);
            sci_sl_file* file = sl_of_file.get_sl_file(child_file);

            file->read((char*)(*child)["path"].toString().toStdString().c_str());
        }
        else if((*child)["type"] == 2){
            child_file = new scicore::sci_pdf_paper((*child)["name"].toString().toStdString(),
                    (*child)["desc"].toString().toStdString(),file);

            sci_sl_file* file = sl_of_file.get_sl_file(child_file);

            file->read((char*)(*child)["path"].toString().toStdString().c_str());
        }
        //还有其他文件

        file->add_file(child_file);
        expand(child_file,child);
    }

}

scicore::sci_file* load(std::string path){
    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open failed!";
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
      return NULL;
    }


    QJsonObject obj = jdc.object();        //获取对象

    scicore::sci_file* root = new scicore::sci_folder(obj["name"].toString().toStdString());

    expand(root,&obj);

    return root;
}

}

