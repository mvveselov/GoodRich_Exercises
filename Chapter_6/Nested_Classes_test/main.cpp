#include <iostream>
#include "NodeList.h"

int main()
{
	NodeList list;
//    list.insertFront(10);
//    list.insertBack(20);
//    list.display();
list.print();
  NodeList::Iterator it ( list.begin() );
  std::cout << *it << std::endl;
  it = list.end();
  std::cout << *it << std::endl;
  
 // NodeList::Node n (list.header);
    
    
	return 0;
}
