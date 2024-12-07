#pragma once
 #include"OrderBookEntry.h"
 #include"CSVReader.h"
 #include<string>
 #include<vector>

class OrderBook{

    public:

    // construct reading a csv data fuke 
    OrderBook(string filename);
    //vector of all known products in a data set
    vector<string> getKnownProducts();
    //return vector of orders according to send filters
    vector<OrderBookEntry>getOrders(OrderBookType type,
                        string product,
                        string timestamp);

    /**returns the earliest time in the orderbook**/
    string  getEarliestTime();
    /**returns the next time after the sent time in the orderbook 
     * if there is no next timetamp ,wraps around to the start **/
    string getNextTime(string timestamp);

    void insertOrder(OrderBookEntry &order);

    vector<OrderBookEntry>matchAsksToBids(string product ,string timestamp);

    static double getHighPrice(vector<OrderBookEntry>& orders);
    static double getLowPrice(vector<OrderBookEntry>& orders);
    private:
    vector<OrderBookEntry>orders;

};