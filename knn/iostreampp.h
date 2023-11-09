#ifndef IOPP
#define IOPP

#include<iostream>
#include<vector>
template<typename T>  
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)  
{  
    os << "[";  
    for (int i = 0; i < v.size(); ++i) {  
        os << v[i];  
        if (i != v.size() - 1)  
            os << ", ";  
    }  
    os << "]\n";  
    return os;  
}  

#endif