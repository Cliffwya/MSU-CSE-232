#pragma once
#include <iostream>
#include <map>
#include <string>

class UserAccount {  //Each single persons portfolio where we can do all our transactions and store their money
private:
    std::map<std::string, int> portfolio__;  //Removed the username and just kept it in the portfolio

public:
    void Deposit(const std::string &asset, int amount);
    bool Withdraw(const std::string &asset, int amount);
    void PrintPortfolio(std::ostream &os) const;
};