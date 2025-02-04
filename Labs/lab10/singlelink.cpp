#include<iostream>
#include<sstream>
#include<stdexcept>
#include<string>
#include <algorithm>

#include "singlelink.hpp"

SingleLink::SingleLink(){
  head_= nullptr;
  tail_= nullptr;
}

SingleLink::SingleLink(int dat){
  Node*s1 = new Node(dat);
  s1->next_ = nullptr;
  head_=s1;
  tail_=s1;
}

void SingleLink::append_back(int x){
  Node*s2 = new Node(x);
  s2->next_ = nullptr;
  tail_ = s2;
}

std::ostream & operator<<(std::ostream &out, const SingleLink &s){
  Node*ptr = s.head_;
  while(ptr->next_!=nullptr){
    out << ptr->data_;
    ptr = ptr->next_;
  }
  return out;
}

bool SingleLink::del(int val){
    Node*ptr = head_;
    while(ptr->next_ && ptr->next_->data_ != val){
        ptr = ptr->next_;
    }
    if(!ptr->next_)return false;
    Node*new_temp=ptr->next_;
    ptr->next_=new_temp->next_;
    delete new_temp;
    return true;
}

/*Node& operator[](size_t index){
    Node*new_temp=head_;
    size_t new_temp=0;
}*/