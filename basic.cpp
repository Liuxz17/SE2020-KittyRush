#include <basic.h>


Folder_Info::Folder_Info()
{

}

void Folder_Info::add(Document *new_doc)
{
    son_info.append(new_doc);
}

void Folder_Info::remove(int index)
{
    son_info.removeAt(index);
}

QString Folder_Info::get_fold_name()
{
    return fold_name;
}

void Folder_Info::set_fold_name(QString new_name)
{
    fold_name = new_name;
}



Doc_Info::Doc_Info()
{

}

Doc_Info::Doc_Info(QString _doc_name, QList <QString> _authors, QList <QString> _keywords, int _publish_year, QList <Doc_Info*> _reference):
    doc_name(_doc_name), authors(_authors), keywords(_keywords), publish_year(_publish_year), reference(_reference){}

QString Doc_Info::get_doc_name()
{
    return doc_name;
}

QList <QString> Doc_Info::get_authors()
{
    return authors;
}

QList <QString> Doc_Info::get_keywords()
{
    return keywords;
}

int Doc_Info::get_publish_year()
{
    return publish_year;
}

QList <Doc_Info>* Doc_Info::get_reference()
{
    int len = reference.count();
    QList <Doc_Info> *ref_list = new QList <Doc_Info>;
    for(int i = 0; i < len; i++)
    {
        Doc_Info *temp = reference.at(i);
        (*ref_list).append(*temp);
    }
    return ref_list;
}

File::File()
{

}

bool File::move(QString new_path)
{
    file_path = new_path;
    return true;
}

Document::Document(bool _is_folder):is_folder(_is_folder){}

void Document::set_info(Doc_Info info)
{
    doc_info = info;
}

QString Document::get_annotation()
{
    return annotation;
}

void Document::set_annotation(QString ann)
{
    annotation = ann;
}

Buffer::Buffer()
{

}

void Buffer::add(Doc_Info *doc)
{
    doc_buffer.append(doc);
}

void Buffer::remove(int index)
{
    doc_buffer.removeAt(index);
}

Online_Buffer::Online_Buffer()
{

}
