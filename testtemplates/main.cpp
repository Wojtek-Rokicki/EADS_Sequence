#include <iostream>
#include "templates.hpp"

using std::string;


int main() {
    Sequence<int, int> x;
    x.push_back(1,1);
    x.push_back(3,3);
    x.push_back(5,5);
    Sequence<int, int> y;
    y.push_back(2, 2);
    y.push_back(4, 4);
    y.push_back(6, 6);
    
    Sequence<int, int> z = produce(x, 0, 1, y, 0, 1, 6);
    z.print();

}
