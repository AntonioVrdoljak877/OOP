#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Song {
    std::string title;
    std::string artist;
    int year;
    int plays;



};



void print_song(const Song& p1){

std::cout<<"Izvodjac"<<p1.artist<<" naslov: "<<p1.title<<" godina: "<<p1.year<<" odslusano: "<<p1.plays;
}




int main() {
    std::vector<Song> pjesme = {
        {"Pjesma1", "Pjevac1", 2012, 199},
        {"Pjesma2", "Koko12", 2021, 56},
        {"HelloWorld", "Koko12", 2011, 5},
        {"DrugaPjesma", "Koko12", 2015, 300},
        {"Nepoznata21", "Random11212", 2015, 12}
    };


    std::sort(pjesme.begin(), pjesme.end(), [](const Song& p1, const Song& p2) {
        if (p1.year != p2.year) {
            return p1.year < p2.year;
        }
        return p1.title < p2.title;
    });


    std::string izvodjac;
    std::cout << "Unesi ime izvodjaca: ";
    std::getline(std::cin, izvodjac);




    auto iz1 = [&izvodjac](const Song& s1){

    return s1.artist == izvodjac;
    };

    auto counter = std::count_if(pjesme.begin(),pjesme.end(),iz1);



    if (counter > 0) {
        std::cout << "Izvodjac " << izvodjac << " ima " << counter <<std::endl;


    } else {
        std::cout << "Nema pjesama tog izvođača na popisu.";
    }


    auto najslusanija_it = std::max_element(pjesme.begin(), pjesme.end(), [](const Song& p1, const Song& p2) {
        return p1.plays < p2.plays;
    });

    if (najslusanija_it != pjesme.end()) {

        print_song(*najslusanija_it);
    }

    return 0;
}
