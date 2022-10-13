#include <iostream>
using namespace std;

class Human{
    public:
    string name;
    int age;
    string give_a_snack(string food){
        return food;
    };
};

class Cat{
    public:
    string name;
    string colour;
    int age;
    string fav_food;
    void ask_about_snack(){
        cout << "meow";
    };
};


int main(){
    Cat cat;
    cat.name="Sushi";
    cat.colour="black";
    cat.age=2;
    cat.fav_food="tuna";

    Human me;
    me.name = "Julka";
    me.age = 20;

}