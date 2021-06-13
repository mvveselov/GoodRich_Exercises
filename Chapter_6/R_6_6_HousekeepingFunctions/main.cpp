#include <iostream>
#include "ArrayVector.h"




int main() {
    ArrayVector<int> vec {};
    
//    std::cout << vec;
    vec.insert(0, 1);
//    std::cout << vec;
	vec.insert(1, 10);
//    std::cout << vec;
    vec.insert(2, 20);
   
    vec.insert(1000, 100);
    std::cout << vec;
    ArrayVector<int> arr {vec};
    std::cout << "Array:" << arr;
    std::cout << "Vector:" << vec;
    arr.insert(3, 30);
    arr.insert(4, 40);
    std::cout << "Array:" << arr;
    arr = vec;
    std::cout << "Array:" << arr;
    std::cout << "INsertion" << std::endl;
    vec.insert(3,30);
    std::cout << "Vector:" << vec;
    std::cout << "Array:" << arr;

	return 0;
}
