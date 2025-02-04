#include "header.hpp"

void Flip(Node* n){
    Node* current_node = n;  //Set it to the current node
    while(current_node){  //While theres a node
        current_node->on = !current_node->on;  //Flip the on to false if true and vice versa
        current_node = current_node->next;  //Set the current node to the next node
    }
}