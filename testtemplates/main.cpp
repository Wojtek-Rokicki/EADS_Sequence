#include <iostream>
#include "templates.hpp"

using std::string;

int main() {
    // Test for functions that add
    Sequence<int, int> x;
    x.push_back(1,1);
    x.push_back(3,3);
    x.push_back(5,5);
    x.print_list();
    std::cout << x.size() << std::endl;
    
    Sequence<int, int> y;
    y.add_front(6,6);
    y.add_front(2,2);
    y.insert_at_pos(4, 4, 1);
    y.print_list();
    
    Sequence<int,int> f = produce(x,0,1,y,0,1,12);
    f.print_list();

    f = produce(x,0,1,y,0,1,6) = produce(x,0,3,y,0,3,6);
    f.print_list();
}
