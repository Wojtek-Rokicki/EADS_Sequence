#include <iostream>
#include "templates.hpp"
#include <vector>

using std::vector;

int main() {
    Dictionary<int, int> x;
    x.push_back(5,5);
    x.push_back(4,4);
    x.push_back(3,3);
    x.print();
    vector<int> v;
}
