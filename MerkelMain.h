#pragma once
#include<vector>
#include"OrderBookEntry.h"
#include"OrderBook.h"
#include"wallet.h"
class MerkelMain{

    public:
        MerkelMain();
        //call this to start the simulation
        void init();
    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);

        string currentTime;
        
        OrderBook orderBook{"20200317.csv"};
        Wallet wallet;

        //vector<OrderBookEntry> orders;

};