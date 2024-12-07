#include "OrderBookEntry.h"
#include<string>

OrderBookEntry::OrderBookEntry(double price,
                            double amount,string timestamp,
                            string product,OrderBookType ordertype,
                            string username)
                            :price(price),amount(amount),
                            timestamp(timestamp),
                            product(product),
                            ordertype(ordertype),
                            username(username)
{

}
OrderBookType  OrderBookEntry::stringToOrderBookType(string s)
{
    if(s == "ask"){
        return OrderBookType::ask;
    }
    if(s=="bid"){
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}