#include <iostream>
using namespace std;

class Human{
    string name;
    int age;
    public:
    Human(string name, int age){
        this->name = name;
        this->age = age;
    }
    string give_a_snack(string food){
        cout << "here is your " + food +"\n";
        return food;
    };
};

class Cat{
    string name;
    string colour;
    int age;
    string fav_food;
    public:
    Cat(string name, string colour, int age, string fav_food){
        this->name = name;
        this->colour = colour;
        this->age = age;
        this->fav_food = fav_food;
    }
    void ask_about_snack(){
        cout << "meow\n";
    };
    void consume_snack(string snack){
        if(snack == "tuna"){
            cout << "meow meow\n";
        }
        else{
            cout << "meow";
        }
    }
};


int main(){
    Cat cat("Sushi", "Black", 2, "tuna");
    Human me("Julka", 20);
    
    cat.ask_about_snack();
    cat.consume_snack(me.give_a_snack("tuna"));

    cat.ask_about_snack();
    cat.consume_snack(me.give_a_snack("chicken"));


    
}
