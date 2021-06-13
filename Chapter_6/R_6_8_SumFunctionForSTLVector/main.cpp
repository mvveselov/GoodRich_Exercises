#include <iostream>
#include <vector>


template<typename T>
T sum(const std::vector<T> & vec) {
    T sum = 0;
    for (typename std::vector<T>::const_iterator it = vec.cbegin(); it != vec.cend(); it ++)
        sum += *it;
    return sum;
}

 
int main()
{
	std::vector<double> vec {10.0, 20.1, 30.1, 40.1, 50.1, 60.1, 70.1, 80.1, 90.1, 100.1};
    std::cout << sum<double>(vec);
	return 0;
}
