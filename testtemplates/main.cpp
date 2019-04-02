#include <iostream>
#include "templates.hpp"

using std::string;

int main() {
    Sequence<int, int> empty_seq;
    Sequence<int, int> x;
    x.push_back(1,1);
    x.push_back(3,3);
    x.push_back(5,5);
    x.print();
    
    Sequence<int, int> y;
    y.push_front(6,6);
    y.push_front(2,2);
    y.insert_at_pos(4, 4, 1);
    y.print();
    
    Sequence<int,int> f = produce(x,0,1,y,0,1,12);
    f.print();

    f = produce(x,0,1,y,0,1,6) = produce(x,0,3,y,0,3,6);
    f.print();
}
