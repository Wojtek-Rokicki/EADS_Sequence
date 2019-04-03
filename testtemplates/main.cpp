#include <iostream>
#include "templates.hpp"

using std::string;

void tests() {
    // Test addition functions
    std::cout << "\nPush back" << std::endl;
    Sequence<int, int> x;
    x.push_back(1,1);
    x.push_back(3,3);
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    

    std::cout << "\nAdd front" << std::endl;
    x.add_front(6,6);
    x.add_front(2,2);
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    
    
    std::cout << "\nInsert at position" << std::endl;
    x.insert_at_pos(8,8, 0);
    try{
        x.insert_at_pos(8,8, 6);
    }catch(std::out_of_range ex){
        std::cout << ex.what() << std::endl;
    }
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    // Catches out of range because position 6 is too big
    
    
    std::cout << "\nInsert after key" << std::endl;
    x.insert_after_key(234, 234, 8);
    try{
        x.insert_after_key(256,256, 4);
    }catch(std::invalid_argument ex){
        std::cout << ex.what() << std::endl;
    }
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    
    // 2nd sequence needed for other tests
    Sequence<int,int> y;
    y.push_back(4, 4);
    y.push_back(5, 5);
    y.push_back(6, 6);
    
    std::cout << "\nExtend" << std::endl;
    x.extend(y);
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    
    // Removal functions
    // remove_back, remove_front and empty base on remove_pos so we test only that
    
    std::cout << "\nRemove pos" << std::endl;
    x.remove_pos(0);
    try{
        x.remove_pos(8);
    }catch(std::out_of_range ex){
        std::cout << ex.what() << std::endl;
    }
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    
    std::cout << "\nRemove by key" << std::endl;
    x.remove_by_key(4);
    try{
        x.remove_by_key(4);
    }catch(std::invalid_argument ex){
        std::cout << ex.what() << std::endl;
    }
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    
    // Get
    std::cout << "\nGet and brackets" << std::endl;
    std::cout << x[0].key << " : " << x[0].val << std::endl;
    x[0].key += 10;
    std::cout << x[0].key << " : " << x[0].val << std::endl;
    try{
        x[100];
    }catch(std::out_of_range ex){
        std::cout << ex.what() << std::endl;
    }
    
    // Operators
    std::cout << "\nAssignment" << std::endl;
    y.print_list();
    x = y;
    x.print_list();
    std::cout << "Length: " << x.size() << std::endl;
    
    std::cout << "\nEquality operator" << std::endl;
    if(x==y)
        std::cout << "Equal" << std::endl;
    y.add_front(2, 2);
    if(x==y)
        std::cout << "Equal" << std::endl;
    if(x!=y)
        std::cout << "Not equal" << std::endl;
    
    std::cout << "\nIs empty" << std::endl;
    if(x.is_empty())
        std::cout << "Empty" << std::endl;
    x.empty();
    if(x.is_empty())
        std::cout << "Empty" << std::endl;
    
    
    std::cout << "Get by key" << std::endl;
    try{
        x.get_by_key(4);
    }catch(std::invalid_argument ex){
        std::cout << ex.what() << std::endl;
    }
    
    
    // Check for other data types
    std::cout << "Check for other data types" << std::endl;
    Sequence<string,float> s_seq;
    s_seq.push_back("foo", 1);
    s_seq.add_front("bar", 2);
    s_seq.insert_at_pos("foobar", 1.5, 1);
    s_seq.print_list();
    std::cout << "Length: " << x.size() << std::endl;
}

int main(){
    std::cout << "TESTS" << std::endl;
    tests();
    std::cout << "\n" << std::endl;
    
    std::cout << "Produce function" << std::endl;
    Sequence<int,int> a;
    Sequence<int,int> b;
    for(int i=0; i<4;i++){
        a.push_back(i*2+1, (i*2+1)*10);
        b.push_back(i*2, i*20);
    }
    //1,3,5,7
    //0,2,4,6
    
    // Excpected 0,1,2,3,4,5,6,7
    produce(b, 0, 1, a, 0, 1, 8).print_list();
    std::cout << std::endl;
    
    // Expected 5,7,0,2,4,6,1,3,0,2,4,6,
    produce(a, 2, 2, b, 0, 4, 12).print_list();
    
    
}
