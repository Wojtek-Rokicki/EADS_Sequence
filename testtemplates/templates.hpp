#ifndef templates_hpp
#define templates_hpp

#include <stdio.h>

template <class Key, class Info>
class Dictionary {
    struct Node{
        Key key;
        Info val;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    
public:
//    Dictionary();
//    ~Dictionary();
//    
//    void empty();
//    void erase();
//    
//    void find(Key);
//    
//    void remove_key(Key);
//    void remove_pos(int);
//    void pop();
    void print();
    
    void push_back(Key,Info);
//    void push_front(Key,Info);
//    void insert(Key,Info,int);
    
    Info& operator[](int);
};


template <class Key, class Info>
void Dictionary<Key,Info>::print() {
    Node* tmp = head;
    while(tmp){
        std::cout << tmp->key << " : " << tmp->val << std::endl;
        tmp = tmp->next;
    }
}


template <class Key, class Info>
void Dictionary<Key, Info>::push_back(Key key, Info val){
    if(!head){
        head = new Node;
        head->key = key;
        head->val = val;
    }
    else{
        Node* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Node;
        tmp->next->key = key;
        tmp->next->val = val;
    }
}


#endif /* templates_hpp */
