#ifndef SCI_TOOLS_TREE_H
#define SCI_TOOLS_TREE_H

#include <list>
#include <QList>

template<class T>
class Sci_tree_node{
public:
    Sci_tree_node():parent(NULL){
    }
    Sci_tree_node(Sci_tree_node* parent):parent(parent){
    }

    T data;

    Sci_tree_node* parent;
    std::list<Sci_tree_node* > children;

    bool add_son(T){
        children.push_back(Sci_tree_node<T>(this));
        return true;
    }
    bool set_son(T d,int place){
        if(place>children.size())
            return false;
        if(place==children.size())
            add_son(d);

        children[place].data = d;

        return true;
    }

};


//template<class T>
//class Sci_tree
//{
//public:
//    Sci_tree();
//    Sci_tree_node <T> root;
//};

class Document;
class Library
{
public:
    Library();
    void add(Document* doc, Sci_tree_node<Document*>* father);
    void remove(Sci_tree_node <Document*>* doc);
    void move(Sci_tree_node <Document*>* doc, Sci_tree_node <Document*>* father);
private:
    Sci_tree_node <Document*> tree;
};

class LibraryList
{
public:
    LibraryList();
    void add(Library *lib);
    void remove(int index);
private:
    QList <Library*> library_list;
};
#endif // SCI_TOOLS_TREE_H
