#pragma once 
#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class EveryOther{
    private:
        std::vector<T> items;
        bool count{true};
    public:
        EveryOther():count{true}{}  //Default Cons

        EveryOther(std::initializer_list<T> list):count{true}{  //Init_list Con
            for (const T & item: list){
                if(count) items.push_back(item);  //Add the item if true
                count = !count;  //Switch between false and true
            }
        }

        friend std::ostream & operator<<(std::ostream & os, const EveryOther<T>& object){
            os<<"EveryOther(";
            for(size_t i{0};i<object.items.size();++i){//For each item in the list
                os<<object.items.at(i);  //Pass to the ostream
                os<<", ";
            }
            os<<")";
            return os;
        }

        void push_back(const T & value){
            if(count) items.push_back(value);  //If true add the item
            count = !count;  //Switch to true if false and vice versa
        }

        size_t size() const{
            return items.size();  //Return the size
        }

};