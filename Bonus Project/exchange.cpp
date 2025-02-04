#include "exchange.hpp"
#include <algorithm>

void Exchange::MakeDeposit(const std::string &username, const std::string &asset, int amount) {  //Same as the last code, not much needed/checking for deposite
    user_accounts__[username].Deposit(asset, amount);  //Deposite the amount (and asset) to the user
}

void Exchange::PrintUserPortfolios(std::ostream &os) const {
    os << "User Portfolios (in alphabetical order):" << std::endl;
    for (const auto &[username, account] : user_accounts__) {  //Tried using this style instead of pair.first technique, this way its a bit easier to read. and we dont need to sort it as i said earlier
        os << username << "'s Portfolio: ";  //Print the name of the portfolio we are on
        account.PrintPortfolio(os);  //Using the helper function we made earlier in useraccounts print the info of the account
        os << std::endl;
    }
}

bool Exchange::MakeWithdrawal(const std::string &username, const std::string &asset, int amount) {
    if (user_accounts__.find(username) == user_accounts__.end()) return false;  //If we cannot find the username that we are trying to make a withdraw from return a false as in we couldnt do it
    return user_accounts__[username].Withdraw(asset, amount);  //Else return the withdawn amount using the useraccount withdraw member function
}

bool Exchange::AddOrder(const Order &order) {
    if (user_accounts__.find(order.username) == user_accounts__.end()) return false;  //Look for the account

    UserAccount &account = user_accounts__[order.username];  //After we find the account make a new obj using the account in the order
    if (order.side == "Buy") {  //if we are buying and we dont have enough USD
        if (!account.Withdraw("USD", order.amount * order.price)) return false;
    } else if (order.side == "Sell") {  //If we are selling and dont have enough of the asset
        if (!account.Withdraw(order.asset, order.amount)) return false;
    } else {
        return false;  //If not either buying or selling
    }

    ExecuteOrder(order);  //Move to the helper function
    return true;
}

void Exchange::ExecuteOrder(const Order &order) {
    auto &orders = open_orders__[order.asset];  
    auto iterator = orders.begin();  //Sets our iterator at the begingin of the orders, allows us to sequence through the line of orders
    int remaining_amount = order.amount;

    while (iterator != orders.end() && remaining_amount > 0) {  //Go through all the orders till we reach the end
        if ((order.side == "Buy" && iterator->side == "Sell" && order.price >= iterator->price) ||
            (order.side == "Sell" && iterator->side == "Buy" && order.price <= iterator->price)) {
            int trade_amount = std::min(remaining_amount, iterator->amount);
            int trade_price = iterator->price;

            //using ternary operations we make a new trade based of if the user is selling or buying
            Trade trade{order.side == "Buy" ? order.username : iterator->username, order.side == "Sell" ? order.username : iterator->username, order.asset, trade_amount, trade_price};
            trade_history__.push_back(trade);

            //after we make the trade and add it to the history execeute the trade using the helper function we make later
            ExecuteTrade(trade);
            filled_orders__[iterator->username].push_back(Order{iterator->username, iterator->side, iterator->asset, trade_amount, iterator->price});

            iterator->amount -= trade_amount; //Take that orders amount and minus it by the trade amount 
            remaining_amount -= trade_amount;

            (iterator->amount == 0) ? //Another ternary expression, if the amount is 0 add it to the filled orders and erase it from the orders. If its not complete move on
                (filled_orders__[iterator->username].push_back(*iterator), iterator = orders.erase(iterator)) : 
                ++iterator;
                
            if (order.amount == trade_amount) return;  
        } else {
            ++iterator;  //Move to next iterator
        }
    }

    if (remaining_amount > 0) {
        Order new_order = order;
        new_order.amount = remaining_amount;
        orders.push_back(new_order);
    }
    if (remaining_amount < order.amount){
        Order filled_order = order;
        filled_order.amount = order.amount - remaining_amount;
        filled_orders__[order.username].push_back(filled_order);
    }
}

void Exchange::ExecuteTrade(const Trade &trade) {  //Makes a trade offer that takes the buyers asset and gives the seller their money
    user_accounts__[trade.buyer_username].Deposit(trade.asset, trade.amount);
    user_accounts__[trade.seller_username].Deposit("USD", trade.amount * trade.price);  //Trades are always in USD in this case
}

void Exchange::PrintUsersOrders(std::ostream &os) const {  //Most the printing stuff is the same as the prior printing information 
    os << "Users Orders (in alphabetical order):" << std::endl;
    for (const auto &[username, account] : user_accounts__) {
        os << username << "'s Open Orders (in chronological order):" << std::endl;  //Should be in chronological already because we are just adding to the map (keeps it in order)
        PrintOrders(os, open_orders__, username);
        os << username << "'s Filled Orders (in chronological order):" << std::endl;
        PrintOrders(os, filled_orders__, username);
    }
}

void Exchange::PrintOrders(std::ostream &os, const std::map<std::string, std::vector<Order>> &orders, const std::string &username) const {  //Helper function for the printing 
    for (const auto &[asset, asset_orders] : orders) {  //Take the map of orders
        for (const auto &order : asset_orders) { //These next two lines match up the user to the orders so we dont print unecessary people 
            if (order.username == username) {
                os << order.side << " " << order.amount << " " << order.asset << " at " << order.price << " USD by " << order.username <<  std::endl;  //Formatting and print the info
            }
        }
    }
}

void Exchange::PrintTradeHistory(std::ostream &os) const {  //All the trade history
    os << "Trade History (in chronological order):" << std::endl;
    for (const auto &trade : trade_history__) {
        os << trade.buyer_username << " bought " << trade.amount << " " << trade.asset
           << " from " << trade.seller_username << " for " << trade.price << " USD " << std::endl;
    }
}

void Exchange::PrintBidAskSpread(std::ostream &os) const {
    os << "Asset Bid Ask Spread (in alphabetical order): " << std::endl;
    for (const auto &[asset, orders] : open_orders__) {
        int highest_buy = 0, lowest_sell = 2147483647;  //Max value for the ints on the selling to make sure the selling and buying are within range
        for (const auto &order : orders) {  //Matches each highest biding and selling points for all the orders in our map
            if (order.side == "Buy" && order.price > highest_buy) highest_buy = order.price;  //Sets higherst and lowest
            if (order.side == "Sell" && order.price < lowest_sell) lowest_sell = order.price;
        }  //Return to the os the highest and lowest via ternary expression and the set vaiables we had earlier
        os << asset << ": Highest Open Buy = " << (highest_buy ? std::to_string(highest_buy) : "NA") << " USD and Lowest Open Sell = "<< (lowest_sell != 2147483647 ? std::to_string(lowest_sell) : "NA") << " USD " << std::endl;
    }
}