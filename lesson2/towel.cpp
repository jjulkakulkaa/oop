#include <iostream>
using namespace std;

class Towel{
    string colour;
    string material;
    string size;
    bool is_dirty;

    public:
    Towel(string colour = "", string material = "",string size = "0x0" ,bool dirty = false ){
        this->colour = colour;
        this->material = material;
        this->size = size;
        this->is_dirty = is_dirty;
    }

    void wash(){
        if(is_dirty = true){
            this->is_dirty = false;
        }
    }
    void use(){
        if(is_dirty = false){
            this->is_dirty = true;
        }
    }
    void repaint(string colour){
        this->colour = colour;
    }
    void info(){
        
        cout << "Colour: " + this->colour + "\n Material "+ this->material + "\nSize: " + this->size + "\n";
        if(this->is_dirty){
            cout << "This towel is not dirty\n";
        }
        else{
            cout << "This towel is dirty\n";
        }
    }
};

int main(){
    Towel towel("white", "wool", "100x50", true);
    towel.info();
    towel.wash();
    towel.info();

    Towel towel2("black", "wool");
    towel2.info();
    towel2.repaint("pink");
    towel2.use();
    towel2.info();
    

}

