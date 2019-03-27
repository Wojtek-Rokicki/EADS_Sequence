#ifndef templates_hpp
#define templates_hpp

#include <stdio.h>

template <class Key, class Info>
class Sequence {
    struct Node{
        Key key;
        Info val;
        Node* next = nullptr;
    };
    Node* head;
    
public:
    Sequence();
//    ~Sequence();
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
    void push_front(Key,Info);
//    void insert(Key,Info,int);
    void insert_after(Key af, Key k,Info v);
    
    Info& operator[](int);
};

template <class Key, class Info>
Sequence<Key, Info>::Sequence(){
    head = nullptr;
}


template <class Key, class Info>
void Sequence<Key,Info>::print() {
    Node* tmp = head;
    while(tmp){
        std::cout << tmp->key << " : " << tmp->val << std::endl;
        tmp = tmp->next;
    }
}


template <class Key, class Info>
void Sequence<Key, Info>::push_back(Key key, Info val){
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

template<class Key, class Info>
void Sequence<Key,Info>::push_front(Key key, Info val){
    if(!head){
        head = new Node;
        head->key = key;
        head->val = val;
    }
    else{
        Node* tmp = head;
        head = new Node;
        head->key = key;
        head->val = val;
        head->next = tmp;
    }
}
template<class Key, class Info>
Sequence<Key,Info> produce(const Sequence<Key,Info> &s1, int start1, int len1,
                           const Sequence<Key,Info> &s2, int start2, int len2,
                           int limit){
    
}
#endif /* templates_hpp */
