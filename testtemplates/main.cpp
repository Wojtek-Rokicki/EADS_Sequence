#include <iostream>
#include "templates.hpp"



int main() {
    Sequence<int, int> x;
    x.push_back(5,5);
    x.push_back(4,4);
    x.push_back(3,3);
    x.print();
    x.push_front(3,3);
    x.print();
}
