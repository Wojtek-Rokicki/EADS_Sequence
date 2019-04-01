#ifndef templates_hpp
#define templates_hpp

#include <stdio.h>
#include <stdexcept>
#include <exception>

template<class Key, class Info>
class Sequence {
private:
    // Definition of node element of sequence
    struct Node{
        Key key;
        Info val;
        Node* next = nullptr;
        
        // Constructors
        Node():next(nullptr){}
        Node(Key& k, Info& v, Node* next_ptr = nullptr){
            key = k;
            val = v;
            next = next_ptr;
        }
        
        // Copy constructor
        Node(Node const &x){
            key = x.key;
            val = x.val;
            next = nullptr;
        }
        
        // Print function, requires the Key and Value to have << operator defined
        void print(){
            std::cout << key << " : " << val << std::endl;
        }
    };
    
    Node* head;
    int length;
    
    void push_back(Node);               //done
    void push_front(Node x);            //done
    void insert_at_pos(Node,int pos);   //done
    void insert_after_key(Node,Key);    //done
public:
    Sequence():head(nullptr),length(0){}
    Sequence(Sequence const &);
    ~Sequence();
    
    void print();
    bool is_empty();
    int size(){return length;}
    
    void push_back(Key,Info);   //done
    void push_front(Key,Info);  //done
    void insert_at_pos(Key,Info,int pos);   //done
    void insert_after_key(Key,Info,Key);    //done
    
    void remove_pos(int);           //
    void remove_back();             //
    void remove_front();            //
    void remove_by_key(Key);        //
    void remove_by_val(Info);       //
    void empty();                   //
    void erase();                   //
    
    Node& get(int pos) const;           //done
    Node& looping_get(int pos) const;   //done
    Node& operator[](int pos) const;    //done
};


// Copy contructor
template <class Key, class Info>
Sequence<Key,Info>::Sequence(Sequence const &x){
    head = nullptr;
    length = 0;
    Node* tmp = x.head;
    while(tmp){
        this->push_back(*tmp);
        tmp = tmp->next;
    }
}


// Destructor, loops over nodes and deletes them
template <class Key, class Info>
Sequence<Key,Info>::~Sequence(){
    Node* tmp;
    while(head){
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

// Print function, prints a list of nodes in format "Key : Value", mostly for debugging
template <class Key, class Info>
void Sequence<Key,Info>::print() {
    Node* tmp = head;
    while(tmp){
        tmp->print();
        tmp = tmp->next;
    }
}

// Returns true if empty and false if not
template <class Key, class Info>
bool Sequence<Key,Info>::is_empty(){
    if(head)
        return 0;
    return 1;
}

// Adds element to the end of sequence
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

// Adds element to the end of sequence by Node
template <class Key, class Info>
void Sequence<Key, Info>::push_back(Node x){
    this->push_back(x.key, x.val);
}

// Adds element to the front of sequence
template<class Key, class Info>
void Sequence<Key,Info>::push_front(Key key, Info val){
    head = new Node(key,val,head);
    length++;
}

// Adds element to the front of sequence by Node
template<class Key, class Info>
void Sequence<Key,Info>::push_front(Node x){
    this->push_front(x.key, x.val);
}

// Inserts element at given position
template <class Key, class Info>
void Sequence<Key, Info>::insert_at_pos(Key k, Info val, int pos){
    if(pos > length)
        throw std::out_of_range("Sequence out of range");
    Node* tmp = head;
    if(pos==0){
        head = new Node(k,val,tmp);
    }
    else{
        for(int i=0;i < pos-1;i++){
            tmp = tmp->next;
        }
        tmp->next = new Node(k,val,tmp->next);
    }
}

// Inserts by node
template <class Key, class Info>
void Sequence<Key, Info>::insert_at_pos(Node n, int pos){
    this->insert_at_pos(n.key, n.val, pos);
}


// Inserts a node after first node with a given key
template <class Key, class Info>
void Sequence<Key, Info>::insert_after_key(Key k, Info val, Key x){
    Node* tmp = head;
    bool found = 0;
    while(tmp){
        if(tmp->key == x){
            tmp->next = new Node(k,val,tmp->next);
            found = 1;
            break;
        }
        tmp = tmp->next;
    }
    if(!found){
        throw std::invalid_argument("Sequence doesn't contain elements with given key");
    }
}


template <class Key, class Info>
void Sequence<Key, Info>::insert_after_key(Node n, Key x){
    this->insert_after_key(n.key, n.val, x);
}


// Returns element from given position
template<class Key, class Info>
typename Sequence<Key,Info>::Node& Sequence<Key,Info>::get(int pos) const{
    Node* tmp = head;
    if(pos >= length)
        throw std::out_of_range("Sequence out of range");
    for(int i=0;i < pos; i++){
        tmp = tmp->next;
    }
    return *tmp;
}

// Same as Get but loops the position
template<class Key, class Info>
typename Sequence<Key,Info>::Node& Sequence<Key,Info>::looping_get(int pos) const{
    return this->get(pos%length);
}

// Brackets operator, calls get
template<class Key, class Info>
typename Sequence<Key,Info>::Node& Sequence<Key,Info>::operator[](int pos) const{
    return this->get(pos);
}

// Creates a new sequence made from 2 other sequences
// For each sequence it takes the start and length of the snip as an argument
// It takes as many from the sequences as it can until it reaches the specified limit
template<class Key, class Info>
Sequence<Key,Info> produce(const Sequence<Key,Info> &s1, int start1, int len1,
                           const Sequence<Key,Info> &s2, int start2, int len2,
                           int limit){
    Sequence<Key,Info> result;
    int i=0,j;
    int i_1 = start1, i_2 = start2;
    
    while(1){
        if(i>=limit)
            break;
        for(j=0; j < len1; j++, i++){
            if(i>=limit)
                break;
            result.push_back(s1.looping_get(i_1++));
        }
        for(j=0; j < len2; j++, i++){
            if(i>=limit)
                break;
            result.push_back(s2.looping_get(i_2++));
        }
    }
    return result;
}

#endif /* templates_hpp */
