#include "NodeList.h"

NodeList::NodeList() {
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

NodeList::~NodeList() {
  //  Node* p = Iterator::v;
//    while (p != trailer) { //?
//       // ?? как написать destructor для NodeList 
//    }
    delete header;
    delete trailer;
}

int NodeList::size() const {return n;}

bool NodeList::empty() const {return (n == 0);}

NodeList::Iterator NodeList::begin() const {return Iterator(header->next);}

NodeList::Iterator NodeList::end() const {return Iterator(trailer);}

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w; w->prev = v;
    v->prev = u; u->next = v;
    n++;
}

void NodeList::insertFront(const Elem& e) {insert(begin(),e);}

void NodeList::insertBack(const Elem& e) {insert(end(), e);}

void NodeList::erase(const Iterator& p) {
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w; w->prev = u;
    delete v;
    n--;
}

void NodeList::eraseFront() {
    erase (begin());
}

void NodeList::eraseBack() {
    erase(--end());
}


NodeList::Iterator::Iterator(Node* u) {
    v = u;
}

Elem& NodeList::Iterator::operator *() {
    return v->elem;
}

bool NodeList::Iterator::operator ==(const Iterator& p) const 
{ return v == p.v; }

bool NodeList::Iterator::operator !=(const Iterator& p) const 
{ return v != p.v; }

NodeList::Iterator& NodeList::Iterator::operator ++() {
    v = v->next; return *this; 
}

NodeList::Iterator& NodeList::Iterator::operator--() {
    v = v->prev; return *this;
}

//////////

void NodeList::display() {
    if (n!=0) {
        for (auto p = begin(); p != end(); ++p) {
            
            std::cout << *p << std::endl;
        }
    }
    else std::cout << "List is empty" << std::endl;
    
}

void NodeList::print() {
    if (n!=0) {
        for (Node* v = header->next; v != trailer; v = v->next) {
            
            std::cout << v->elem << std::endl;
        }
    }
    else std::cout << "List is empty" << std::endl;
    
}