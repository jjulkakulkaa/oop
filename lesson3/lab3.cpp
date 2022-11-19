#include <iostream>
#include <string>
using namespace std;
class Date;
class Movie
{
private:
    string title;
    string director;
    string releaseDate;
    string genre;
public:

    Movie(string t, string d,Date date, string g){
        title = t;
        director = d;
        releaseDate = date.date_to_string();
        genre = g;

    };

    string info(){
        return title, director, releaseDate, genre;
    };

};
class Date
{
    int day, month, year;
    public:
    Date(int d,int m,int y){
        day = d;
        month = m;
        year = y;

    };
    string date_to_string()
    {   
        std::string d = std::to_string(day);
        std::string m = std::to_string(month);
        std::string y = std::to_string(year);
        string date;
        date = d+"."+m+"."+y+"r.";
            return date;
    }
};


int main(){

}
