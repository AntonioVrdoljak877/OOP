#include <iostream>
#include <string>

std::string with_separators(std::string digits){

    int pocetak = 0;

    
    if(digits[0]=='-'){
        pocetak = 1;
    }

    for(int i = digits.size()-3;i>pocetak;i-=3){
        digits.insert(i,".");
    }

    return digits;
}

std::string without_separators(std::string text){

    int poz = text.find('.');

    while(poz != std::string::npos){
        text.erase(poz,1);
        poz = text.find('.');
    }

    return text;
}

int main(){

    std::string broj;


    std::cout<<"Unesite broj: "<<std::endl;
    std::cin>>broj;

    std::string s = with_separators(broj);

    std::cout<<"Sa tockama: "<<s<<std::endl;
    std::cout<<"Bez tocaka: "<<without_separators(s)<<std::endl;

    return 0;
}
