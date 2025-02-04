#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "useraccount.hpp"
#include "utility.hpp"

class Exchange {
private: //Private information for the exhange
    std::map<std::string, UserAccount> user_accounts__;   //Using map so its sorting automatically using the keys/name. All the user accounts in one place
    std::vector<Trade> trade_history__;  //All the trading histroy
    std::map<std::string, std::vector<Order>> open_orders__;  //Open ordering, using the same idea with the user acounts 
    std::map<std::string, std::vector<Order>> filled_orders__;  //Same just with complete orders

    void ExecuteOrder(const Order &order);  //Made new member functions just to make it a bit easier to read and debug
    void ExecuteTrade(const Trade &trade);  //Both the execute trade and order help with clearing up the main memeber functions 
    void PrintOrders(std::ostream &os, const std::map<std::string, std::vector<Order>> &orders, const std::string &username) const;

public: //Member functions we need to use
    void MakeDeposit(const std::string &username, const std::string &asset, int amount);  
    void PrintUserPortfolios(std::ostream &os) const;
    bool MakeWithdrawal(const std::string &username, const std::string &asset, int amount);
    bool AddOrder(const Order &order);
    void PrintUsersOrders(std::ostream &os) const;
    void PrintTradeHistory(std::ostream &os) const;
    void PrintBidAskSpread(std::ostream &os) const;
};