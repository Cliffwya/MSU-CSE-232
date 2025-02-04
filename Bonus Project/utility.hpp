#pragma once
#include <string>
#include <iostream>

struct Order {
  std::string username;
  std::string side;  // Can be "Buy" or "Sell"
  std::string asset;
  int amount;
  int price;
  Order(const std::string& username, const std::string& side, const std::string& asset, int amount, int price);
  Order(const Order& other);
  Order& operator=(const Order& other);
  bool operator==(const Order& other) const;
  friend std::ostream& operator<<(std::ostream & os, const Order& order);
};

struct Trade {
  std::string buyer_username;
  std::string seller_username;
  std::string asset;
  int amount;
  int price;
};