#include "utility.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream & os, const Order& order){
    os << order.side << " " << order.amount << " " << order.asset << " at " << order.price << " USD by " << order.username;
    return os;
}

bool Order::operator==(const Order& other) const{
    return this->username == other.username && side == other.side && asset == other.asset && amount == other.amount && price == other.price;
}

//Default constructor
Order::Order(const std::string& username, const std::string& side, const std::string& asset, int amount, int price) : username(username), side(side), asset(asset), amount(amount), price(price) {}

Order::Order(const Order& other) : username(other.username), side(other.side), asset(other.asset), amount(other.amount), price(other.price) {}  //Copy constructor

Order& Order::operator=(const Order& other) {
    if (this != &other) {  //If theyre not equal to each other
        username = other.username;  //Just set everything equal to the other value
        side = other.side;
        asset = other.asset;
        amount = other.amount;
        price = other.price;
    }
    return *this;  //Return the self obj
}