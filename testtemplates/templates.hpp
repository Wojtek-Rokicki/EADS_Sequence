#ifndef templates_hpp
#define templates_hpp

#include <stdio.h>

template<class Key, class Info>
class Sequence {
private:
    struct Node{
        Key key;
        Info val;
        Node* next = nullptr;
        
        Node():next(nullptr){}
        Node(Key& k, Info& v, Node* next_ptr = nullptr){
            key = k;
            val = v;
            next = next_ptr;
        }
        Node(Node const &x){
            key = x.key;
            val = x.val;
            next = nullptr;
        }
        void print(){
            std::cout << key << " : " << val << std::endl;
        }
    };
    Node* head;
    int length;
public:
    Sequence():head(nullptr),length(0){}

    void print();
    void push_back(Key,Info);
    void push_back(Node);
    void push_front(Key,Info);
    
    Node& looped_get(int pos) const;
    
    bool is_empty(){
        if(!head)
            return 1;
        return 0;
    }
};


template <class Key, class Info>
void Sequence<Key,Info>::print() {
    Node* tmp = head;
    while(tmp){
        tmp->print();
        tmp = tmp->next;
    }
}


template <class Key, class Info>
void Sequence<Key, Info>::push_back(Key key, Info val){
    if(!head){
        head = new Node(key,val);
    }
    else{
        Node* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Node(key,val);
    }
    length++;
}

template <class Key, class Info>
void Sequence<Key, Info>::push_back(Node x){
    if(!head){
        head = new Node(x);
    }
    else{
        Node* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Node(x);
    }
    length++;
}

template<class Key, class Info>
void Sequence<Key,Info>::push_front(Key key, Info val){
    head = new Node(key,val,head);
    length++;
}

template<class Key, class Info>
typename Sequence<Key,Info>::Node& Sequence<Key,Info>::looped_get(int pos) const{
    Node* tmp = head;
    for(int i=0; i < pos%length; i++){
        if(tmp->next){
            tmp = tmp->next;
        }
        else{
            tmp = head;
        }
    }
    return *tmp;
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
    Sequence<Key,Info> result;
    
    int i=0,j;
    int i_1 = start1;
    int i_2 = start2;
    while(1){
        if(i>=limit)
            break;
        for(j=0; j < len1; j++, i++){
            if(i>=limit)
                break;
            result.push_back(s1.looped_get(i_1++));
        }
        for(j=0; j < len2; j++, i++){
            if(i>=limit)
                break;
            result.push_back(s2.looped_get(i_2++));
        }
    }
    
    return result;
}

#endif /* templates_hpp */
