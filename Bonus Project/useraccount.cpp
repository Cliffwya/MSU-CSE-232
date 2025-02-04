#include "useraccount.hpp"
#include <algorithm>
#include <iomanip>

void UserAccount::Deposit(const std::string &asset, int amount) {
    portfolio__[asset] += amount;  //Add the given amount to the asset 
}

bool UserAccount::Withdraw(const std::string &asset, int amount) {  //I made this a boolean instead just to make it easier
    if (portfolio__[asset] >= amount) {   //If the asset in the portoflio is greater than the amount we are trying to withdraw 
        portfolio__[asset] -= amount;
        return true;  //If we can withdraw it do it and return that we did it successfully
    }
    return false;  //Else return that we didn't
}

void UserAccount::PrintPortfolio(std::ostream &os) const {  //Fix this for the os error (?)
    for (const auto &[asset, amount] : portfolio__) { //Take the maps key and values 
        if (amount > 0) {  //If the value is greater than 0 print the key and value. That way were arent printing assests we dont have
            os << amount << " " << asset << ", ";
        }
    }
}