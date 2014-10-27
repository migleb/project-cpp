#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

using namespace std;

template <typename some_type>
void print(some_type &o){
	cout << o.to_string();
}

#endif