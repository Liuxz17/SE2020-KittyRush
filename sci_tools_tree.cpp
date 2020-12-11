#include "sci_tools_tree.h"

Library::Library()
{

}

void Library::add(Document* doc, Sci_tree_node<Document *> *father)
{
    (*father).add_son(doc);
}

void Library::remove(Sci_tree_node<Document *> *doc)
{
    // TODO
}

void Library::move(Sci_tree_node<Document *> *doc, Sci_tree_node<Document *> *father)
{
    // TODO
}

LibraryList::LibraryList()
{

}

void LibraryList::add(Library *lib)
{
    library_list.append(lib);
}

void LibraryList::remove(int index)
{
    library_list.removeAt(index);
}
