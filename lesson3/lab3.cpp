#include <iostream>
#include <string>
using namespace std;

class Date{

    string day;
    string month;
    string year;
    public:
    Date(string day, string month, string year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    Date(int day, int month, int year){
        if(day <10){
            this->day = "0"+to_string(day);
        }
        else{
            this->day = to_string(day);
        }

        if(month <10){
            this->month = "0"+to_string(month);
        }
        else{
            this->month = to_string(month);
        }
    
        this->year = to_string(year);
    }
    string displayedDate(){
        return this->day+"."+this->month+"."+this->year+"r.";
    }
};
class Movie
{
    string title;
    string director;
    string releaseDate;
    //Date &releaseDate;
    string genre;

public:

    Movie(string title, string director, Date &date, string genre){
        this->title = title;
        this->director = director;
        this->releaseDate = date.displayedDate();
        this->genre = genre;

    };

    void info(){
        cout << "Title: "+this->title+"\nDirector: "+ this->director + "\nRelease date:  "+ this->releaseDate+"\nGenre : "+this->genre;
        };

};

int main(){
    Date intDate(14,2,2018);
    Date stringDate("14","02","2018");
    Movie movie("Black panter","Ryan Coogler",stringDate,"sience fiction");
    movie.info();
    Movie sameMovie("Black panter","Ryan Coogler",intDate,"sience fiction");
    sameMovie.info();
}
