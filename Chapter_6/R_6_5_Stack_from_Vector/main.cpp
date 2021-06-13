#include <iostream>
#include "Stack_Vector.h"
#include "RuntimeException.h"




int main()
{
    std::cout<<std::boolalpha;
    
    
	try {
        Stack_Vector<int> adapt {};
        std::cout << adapt.empty() << std::endl;
        adapt.push(10);
        std::cout << "Size: " << adapt.size()<< std::endl;
        std::cout << adapt.empty() << std::endl;
        std::cout << adapt.top() << std::endl;
        adapt.pop();
       // std::cout << adapt.top() << std::endl;
        adapt.pop();
        //после первого exception блок перестаёт выполняться, контроль переходит к catch блоку
    }
    catch(StackEmpty& ex) {
        std::cerr << "Error: " << ex.getMessage() << std::endl;
    }
    
	return 0;
}
