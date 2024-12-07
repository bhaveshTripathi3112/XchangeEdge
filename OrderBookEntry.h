#pragma once
#include<string>
using namespace std;
enum class OrderBookType{bid,ask,unknown,asksale,bidsale};

class OrderBookEntry{
    public:
    OrderBookEntry(double price,double amount,
                string timestamp,string product,
                OrderBookType ordertype,
                string username = "dataset");
    static OrderBookType stringToOrderBookType( string s);
    
    static bool compareByTimestamp(OrderBookEntry &e1, OrderBookEntry &e2){
        return e1.timestamp < e2 .timestamp;
    }
    static bool compareByPriceAsc(OrderBookEntry &e1, OrderBookEntry &e2){
        return e1.price < e2 .price;
    }
    static bool compareByPriceDsc(OrderBookEntry &e1, OrderBookEntry &e2){
        return e1.price > e2 .price;
    }


    double price;
    double amount;
    string timestamp;
    string product;
    OrderBookType ordertype;
    string username;

};