#pragma once
#include<string>
#include<map>
#include"OrderBookEntry.h"
using namespace std;

class Wallet{
    public:
    Wallet();
    //**insert cuurency to the wallet */
    void insertCurrency(string type, double amount);
    //**remove cuurency from the wallet */
    bool removeCurrency(string type, double amount);
    /** check if the wallet comntains this much cuurency or not*/ 
    bool containsCurrency(string type, double amount);
    /**checks if the wallet can cope with this ask or bid */
    bool canFullfillOrder(OrderBookEntry order);
    /**update the contents of the wallet
     * assumes the order was made by the owner of the wallet
     */
    void processSale(OrderBookEntry& sale);
    /**generate a string representation of the wallet */
    string toString();

    private:
    map<string,double> currencies;

};