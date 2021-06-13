#include <iostream>
#include "RuntimeException.h"



void function (int i) {
    try {
    if (i == 0) {
        throw RuntimeException{"Zero Value"};
    }
    else std::cout << "All good" << std::endl; 
    }
    catch ( RuntimeException& s) {
        std::cerr << "Error: " << s.getMessage() << std::endl;
    }
}

void func (int i) {
    try{
        if(i==0) throw ("Zero VAlue"); else std::cout << "All good";
    }
    catch (const char* s) {
            std::cerr << "Error: " << s << std::endl;
        }
    }
    
void foo (int i) {
    if (i == 0) throw RuntimeException{"Exception"}; else std::cout << "All good";
  
}

int main()
{
	//function(0);
    //func(0);
   try {
   foo(0);}
   catch (RuntimeException& ex) { 
       std::cout << ex.getMessage();
   }
    
   
	return 0;
}
