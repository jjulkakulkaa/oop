#include <iostream>
using namespace std;

class Towel{
    public:

    string colour;
    string material;
    int width;
    bool is_dirty;
    
    Towel(string c = "white", string m = "wool",int  w = 100 ,bool dirty = false ){
        colour = c;
        material = m;
        width = w;
        is_dirty = dirty;
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
    void repaint(int c){
        this->colour = c;
    }

};

int main(){

}