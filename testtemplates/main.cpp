#include <iostream>
#include "templates.hpp"

using std::string;

int main() {
    Sequence<int, int> x;
    x.push_back(1,1);
    x.push_back(3,3);
    x.push_back(5,5);
    
    x.insert_at_pos(2,2,1);
    x.print();
    
}
    
    
//    Sequence<int, int> y;
//    y.push_back(2, 2);
//    y.push_back(4, 4);
//    y.push_back(6, 6);
//
//    Sequence<int, int> z = produce(x, 0, 1, y, 0, 1, 12);
//    z.print();
//
//
//    try{
//        z[11].print();
//    } catch(std::out_of_range ex){
//        std::cout << ex.what() << std::endl;
//    }
//

