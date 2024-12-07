#include<iostream>
#include<string>
#include<vector>
#include"OrderBookEntry.h"
#include"MerkelMain.h"
#include"CSVReader.h"
#include"wallet.h"
using namespace std;



int main() 
{
    MerkelMain app{};
    app.init();
    // Wallet wallet;
    // wallet.insertCurrency("BTC",10);
    // wallet.insertCurrency("USDT",10000);
    // //cout<<"Wallet has BTC "<<wallet.containsCurrency("USDT",10)<<endl;
    // cout<<wallet.toString()<<endl;
    // wallet.removeCurrency("USDT",1000);
    //  cout<<wallet.toString()<<endl;
    return 0;
    

}
//     // while(true)
//     // {
//     //     printMenu();
//     //     int userOption = getUserOption();
//     //     processUserOption(userOption);
//     // }

//     vector<OrderBookEntry> orders;
   
   
  
//     orders.push_back( OrderBookEntry{1000 , 0.02,"2020/03/17 17:01:24.884492","BTC/USDT",OrderBookType::bid});
//     orders.push_back( OrderBookEntry{3000 , 0.02,"2020/03/17 17:01:24.884492","BTC/USDT",OrderBookType::bid});
    
//     for(OrderBookEntry &order : orders){
//         cout<<"The prices :"<<order .price<<endl;
//     }

//     for(unsigned int i = 0 ; i < orders.size();++i){
//         cout<<"The prices :"<<orders[i] .price<<endl;
//     }

//     for(unsigned int i = 0 ; i < orders.size();++i){
//         cout<<"The prices :"<<orders.at(i) .price<<endl;
//     }
//     return 0 ;

// }