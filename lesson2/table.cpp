#include <iostream>
using namespace std;

class Table
{
    public:

    string type_of_material;
    string colour;
    int weight;
    int price;
    Table(string type = "no", string c = "no", int w = 0, int p = 0){
        type_of_material = type;
        colour = c;
        weight = w;
        price = p;
    }

};
class UsedTable : public Table
{
    string type_of_material;
    string colour;
    int weight;
    int price;
    public:
    UsedTable(string type, string c, int w){
    this->type_of_material=type;
    this->colour=c;
    this->weight=w;
    }
};




int main(){
    Table table("wood","black",3,3000);

}
