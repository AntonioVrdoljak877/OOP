#include <iostream>
#include <string>

struct Student{
    std::string ime;
    std::string jmbag;
    int godina_studija;
    int ECTS;
    double prosjek;

    


    
};


void ispisi(Student& s){

    std::cout<<"ime: "<<s.ime<<std::endl;
    std::cout<<"Jmbag: "<<s.jmbag<<std::endl;
    std::cout<<"Godina studija: "<<s.godina_studija<<std::endl;
    std::cout<<"Ects: "<<s.ECTS<<std::endl;
    std::cout<<"prosjek: "<<s.prosjek<<std::endl;

}


void povecaj(Student& s){
    s.godina_studija++;
}


auto polozen_ispit = [](const Student& s){
    return  s.ECTS > 0;
};


auto prosjek = [](const Student& s){


    return s.prosjek >= 3.5;
};


auto ects45 = [](const Student& s) {


    return s.ECTS >= 45;
};

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&)){
        for(int i = 0;i<n;i++){
            if(cond(s[i])){
                action(s[i]);
            }
        }
    }


int main(){




      Student s[] = {
        {"Ana", "1234567890", 1, 30, 4.2},
        {"Marko", "2345678901", 2, 45, 3.4},
        {"Iva", "3456789012", 1, 0, 4.8},
        {"Ivan", "4567890123", 3, 50, 3.7},
        {"Petra", "5678901234", 1, 15, 3.2}
    };

    

    std::cout<<"Polozili barem jedan ispti: "<<std::endl;
    filter_students(s,5,ispisi,polozen_ispit);
    std::cout<<std::endl;

    std::cout<<"Prosjek veci od 3.5 "<<std::endl;
    filter_students(s,5,ispisi,prosjek);
    std::cout<<std::endl;


      std::cout<<"Vise od 45 ects "<<std::endl;
    filter_students(s,5,ispisi,ects45);
    std::cout<<std::endl;











    return 0;
}
