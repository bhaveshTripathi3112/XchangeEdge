#include"MerkelMain.h"
#include<iostream>
#include<vector>
#include"OrderBookEntry.h"
#include"CSVReader.h"
#include<string>
using namespace std;
MerkelMain::MerkelMain(){

}
void MerkelMain::init(){
    //loadOrderBook();
    int input;
    currentTime= orderBook . getEarliestTime();

    wallet.insertCurrency("BTC",10);
    while (true)
    {
       printMenu();
       input=getUserOption();
       processUserOption(input);
    }
    
}
// void MerkelMain::loadOrderBook(){
//     orders = CSVReader :: readCSV("20200317.csv");
   
// }
void MerkelMain::printMenu()
{
    // 1 print help
    cout<<"1: Print help"<<endl;
    // 2 print exchange stats
    cout<<"2: Print exchange stats"<<endl;
    // 3 make an offer 
    cout<<"3: Make an offer"<<endl;
    // 4 make a bid
    cout<<"4: Make a bid"<<endl;
    // 5 print wallet
    cout<<"5: Print wallet"<<endl;
    // 6 continue
    cout<<"6: Continue"<<endl;
    
    cout<<"============================================"<<endl;

    cout<<"Current time is : "<<currentTime<<endl;
    
}
void MerkelMain::printHelp()
{
    cout<<"help - Your aim is to make money . Analyze the market and make bids and offers, "<<endl;
}

void  MerkelMain:: printMarketStats()
{
    for(string const& p : orderBook.getKnownProducts()){
        cout<<"Products : "<<p <<endl;
        vector<OrderBookEntry > entries = orderBook.getOrders(OrderBookType::ask,
                                                            p ,currentTime);
        cout<<"Asks for products seen : "<<entries.size()<<endl;
        cout<<"Max Ask : "<<OrderBook::getHighPrice(entries)<<endl;
        cout<<"Min Ask : "<<OrderBook::getLowPrice(entries)<<endl;
    }
    // cout<<"Order Book Contains : "<<orders.size()<<" entries "<<endl;

    // unsigned int bids = 0 , asks = 0;
    // for(OrderBookEntry &e :orders){
    //     if(e.ordertype == OrderBookType::ask){
    //         asks++;
    //     }
    //     if(e.ordertype == OrderBookType::bid){
    //         bids++;
    //     }
       
    // }
    //  cout<<"Order Book asks : "<<asks <<endl<<"Order Book bids : "<<bids<<endl;

}

void  MerkelMain::enterAsk()
{
    cout<<"Make a ask - enter the amount : product,price,amount, eg: ETH/BTC,200,0.05 "<<endl;
    string input;
    
    getline(cin,input);
    vector<string>tokens = CSVReader::tokenise(input,',');
    if(tokens.size()!= 3 ){
        cout<<"MerkelMain::enterAsk Bad input ! "<<input<<endl;
        
    }
    else{
        try{
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],
                                                    tokens[2],currentTime,
                                                    tokens[0],OrderBookType::ask); 
            obe.username = "simuser";                       
            if(wallet.canFullfillOrder(obe)){
                cout<<"Wallet Looks good. "<<endl;
                orderBook.insertOrder(obe);
            }
            else{
                cout<<"Insufficient funds in wallet. "<<endl;
            }
            
        }catch(const exception &e)
        {
            cout<<"MerkelMain::enterAsk Bad Input ! "<<input<<endl;
        }
    }   
    cout<<"You typed :"<<input<<endl;
}

void  MerkelMain::enterBid()
{
    cout<<"Make a bid - enter the amount : product,price,amount, eg: ETH/BTC,200,0.05 "<<endl;
    string input;
    
    getline(cin,input);
    vector<string>tokens = CSVReader::tokenise(input,',');
    if(tokens.size()!= 3 ){
        cout<<"MerkelMain::enterBid Bad input ! "<<input<<endl;
        
    }
    else{
        try{
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],
                                                    tokens[2],currentTime,
                                                    tokens[0],OrderBookType::bid);                                 
            obe.username = "simuser";
            if(wallet.canFullfillOrder(obe)){
                cout<<"Wallet Looks good. "<<endl;
                orderBook.insertOrder(obe);
            }
            else{
                cout<<"Insufficient funds in wallet. "<<endl;
            }
            
        }catch(const exception &e)
        {
            cout<<"MerkelMain::enterBid Bad Input ! "<<input<<endl;
        }
    }   
    
    //cout<<"Make a bid - enter the amount "<<endl;
}
void  MerkelMain::printWallet()
{
    
    //cout<<"Your wallet is empty"<<endl;
    cout<<wallet.toString()<<endl;
}

void  MerkelMain::gotoNextTimeFrame()
{
    cout<<"Going to next time frame"<<endl;
    vector <OrderBookEntry>sales = orderBook.matchAsksToBids("ETH/BTC",currentTime);
    cout<<"Sales : "<<sales.size()<<endl;
    for(OrderBookEntry &sale :sales){
        cout<<"Sale price : "<<sale.price <<" amount  : "<<sale.amount<<endl;
        if(sale.username == "simuser"){
            //update the waalet
            wallet.processSale(sale);
        }
    }
    currentTime = orderBook.getNextTime(currentTime);
}

int  MerkelMain::getUserOption()
{
    int userOption=0;;
    string line;
    cout<<"Type in 1-6"<<endl;
    getline(cin,line);
     /**  if we enter  wrong option  so the
      *  userOprion will automatic set to  zero **/
    try{
        userOption = stoi(line);
    }catch(const exception &e )
    {
        //
    }
    //cin>>userOption;
    cout<<"You choose : "<<userOption<<endl;
    return userOption;
}

void  MerkelMain::processUserOption(int userOption)
{
    if(userOption == 0 ){
        cout<<"Invalid choice ! choose 1-6"<<endl;
    }
    if(userOption == 1 ){

        printHelp();
    }
    if(userOption == 2 ){
        printMarketStats();
        
    }
    if(userOption == 3 ){
        enterAsk();
       
    }if(userOption == 4 ){
        enterBid();
        
    }if(userOption == 5){
        printWallet();
       
    }
    if(userOption == 6 ){
        gotoNextTimeFrame();
        
    }
}