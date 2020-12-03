#ifndef BASIC_H
#define BASIC_H

#include <QString>
#include <QList>

class Document;
template<class T>
class sci_tree;

class Folder_Info
{
public:
    Folder_Info();
    void add(Document *new_doc);
    void remove(int index);
    QString get_fold_name();
    void set_fold_name(QString new_name);
private:
    QString fold_name;
    QList <Document*> son_info;
};

class Doc_Info
{
public:
    Doc_Info();
    Doc_Info(QString _doc_name, QList <QString> _authors, QList <QString> _keywords, int _publish_year, QList <Doc_Info*> _reference);
    QString get_doc_name();
    QList <QString> get_authors();
    QList <QString> get_keywords();
    int get_publish_year();
    QList <Doc_Info>* get_reference();
private:
    QString doc_name;
    QList <QString> authors;
    QList <QString> keywords;
    int publish_year;
    QList <Doc_Info*> reference;
};

class File
{
public:
    File();
    bool move(QString new_path);
private:
    QString file_path;
    Doc_Info* analyse();
    void online_match();
    void download();
};

class Document
{
public:
    Document(bool _is_folder);
    void set_info(Doc_Info info);
    QString get_annotation();
    void set_annotation(QString ann);
private:
    Doc_Info doc_info;
    Folder_Info folder_info;
    File file;
    QString annotation;
    void analyse();
    bool is_folder; // 是文件夹还是文件
};

class Buffer
{
public:
    Buffer();
    void add(Doc_Info *doc);
    void remove(int index);
    Doc_Info* search();
private:
    QList <Doc_Info*> doc_buffer;
};

class Online_Buffer: public Buffer
{
public:
    Online_Buffer();
    float score();
    Doc_Info* recommend();
};
#endif // BASIC_H
