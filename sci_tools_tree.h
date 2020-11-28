#ifndef SCI_TOOLS_TREE_H
#define SCI_TOOLS_TREE_H

#include <list>

template<class T>
class sci_tree_node{
public:
    sci_tree_node():parent(NULL){
    }
    sci_tree_node(sci_tree_node* parent):parent(parent){
    }

    T data;

    sci_tree_node* parent;
    std::list<sci_tree_node* > children;

    bool add_son(T){
        children.push_back(sci_tree_node<T>(this));
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


template<class T>
class sci_tree
{
public:
    sci_tree();

};

#endif // SCI_TOOLS_TREE_H
