#include <iostream>
using namespace std;

class Table
{
    string type_of_material;
    string colour;
    int weight;
    int price;

    public:
    Table(string type_of_material = "", string colour = "", int weight = 0, int price = 0){
        this->type_of_material = type_of_material;
        this->colour = colour;
        this->weight = weight;
        this->price = price;   
    }
    void atributes(){
        cout<< "This table is made of "+ this->type_of_material +"\nColour : "+ this->colour +"\nWeight : " + to_string( this->weight ) + "\nPrice: "+ to_string( this->price ) + "\n";
    }
};





int main(){
    Table table("wood","black",3,3000);
    table.atributes();

    Table table2("glass");
    table2.atributes();
