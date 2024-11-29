//created execption for when the payer doesnt have enough coins to buy a third chain 
#include <iostream>
#include <string>
using namespace std; 
class NotEnoughCoins{
    string message; 
    public:
    NotEnoughCoins(const char* msg): message(msg){}

    const char* what() const throw(){
        return message.c_str();
    }

}; 