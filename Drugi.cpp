#include <iostream>
#include <string>



int main(){

int godina;
std::string ime_prezime;
int counter = 0;


std::cin>>godina;
 
std::cin.ignore(1000,'\n');

std::getline(std::cin,ime_prezime);

std::cout<<ime_prezime[0]<<".";

for(int i = 0;i<ime_prezime.length();i++){
    if(ime_prezime[i] == ' '){
        std::cout<<ime_prezime[i+1]<<std::endl;
        break;
    }
}

for(auto i:ime_prezime){
    if(i != ' '){
        counter++;
    }
}

std::cout<<"Broj znakova: "<<counter<<std::endl;
std::cout<<"Osoba navrsava: "<<(2026-godina)<<" godina ove godine.";



    return 0;
}
