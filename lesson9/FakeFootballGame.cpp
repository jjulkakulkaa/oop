#include <string.h>
#include <iostream>
#include <stdexcept>
using namespace std;

class Game {
public:
    virtual string result() = 0;
};

class FakeFootballGame : public Game
{
private:
    
public:
   string result() override {
        return "0:15";
   }
};


int main(){
    FakeFootballGame footballGame;
    try {
        string score = footballGame.result();
        if(score != "0:15"){
            throw runtime_error("wrong score returned");
        }
        cout << score << endl;
    }
    catch(const exception& ex){
        cout << ex.what() << endl;
        return(1);
    }
    return(0);
}
