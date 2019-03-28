#ifndef templates_hpp
#define templates_hpp

#include <stdio.h>

// Node structue
// it's outisde because we have a function that will need to access the structure of it
template<class Key, class Info>
struct Node{
    Key key;
    Info val;
    Node* next = nullptr;

    Node<Key,Info>(){
        next = nullptr;
    }
    
    Node<Key,Info>(Key& k, Info& v, Node<Key,Info>* next_ptr=nullptr){
        key = k;
        val = v;
        next = next_ptr;
    }
};



template<class Key, class Info>
class Sequence {
    Node<Key,Info>* head;
    Node<Key,Info>* tail;
public:
    class iterator {
        friend class Sequence;
    private:
        Node<Key,Info> *node_ptr;
        Node<Key,Info> *prev;
        iterator(Node<Key,Info>* ptr){
            node_ptr = ptr;
            prev = nullptr;
        }
        void next(){
            prev = node_ptr;
            node_ptr = node_ptr->next;
        }
    };
    
    Sequence();
    
    iterator begin(){
        return iterator(head);
    }
    
    void print();
    void push_back(Key,Info);
    void push_front(Key,Info);
    
    bool is_empty(){
        if(!head)
            return 1;
        return 0;
    }
};

template <class Key, class Info>
Sequence<Key, Info>::Sequence(){
    head = nullptr;
    tail = nullptr;
}


template <class Key, class Info>
void Sequence<Key,Info>::print() {
    Node<Key,Info>* tmp = head;
    while(tmp){
        std::cout << tmp->key << " : " << tmp->val << std::endl;
        tmp = tmp->next;
    }
}


template <class Key, class Info>
void Sequence<Key, Info>::push_back(Key key, Info val){
    if(!head){
        head = new Node<Key,Info>(key,val);
    }
    else{
        Node<Key,Info>* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Node<Key,Info>(key,val);
    }
}

template<class Key, class Info>
void Sequence<Key,Info>::push_front(Key key, Info val){
    head = new Node<Key,Info>(key,val,head);
}

/*
 *  (1,2,3,4),(5,6,7,8)
 *  produce(s1,2,2,s2,1,2,10)
 *  3,4,6,7,1,2,8,5,3,4|
 *
 */
template<class Key, class Info>
Sequence<Key,Info> produce(const Sequence<Key,Info> &s1, int start1, int len1,
                           const Sequence<Key,Info> &s2, int start2, int len2,
                           int limit){
    
}

#endif /* templates_hpp */
