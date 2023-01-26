#include <iostream>
using namespace std;

class Table
{
    string type_of_material;
    string colour;
    double weight;
    double price;

    public:
    
    Table(string type_of_material = "", string colour = "", int weight = 0, int price = 0){
        this->type_of_material = type_of_material;
        this->colour = colour;
        this->weight = double(weight);
        this->price = double(price);   
    }

    Table(string type_of_material = "", string colour = "", double weight = 0, double price = 0){
        this->type_of_material = type_of_material;
        this->colour = colour;
        this->weight = weight;
        this->price = price;   
    }


    void atributes(){
        cout<< "This table is made of "+ this->type_of_material +"\nColour : "+ this->colour +"\nWeight : " + to_string( this->weight ) + "kg \nPrice: "+ to_string( this->price ) + "\n";
    }
};





int main(){
    Table table("wood","black",3,3000);
    table.atributes();

    Table table2("wood","black",3.25,3000.34);
    table2.atributes();


}
