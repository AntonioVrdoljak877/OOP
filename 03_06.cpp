#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text){

    std::vector<std::string> rijeci;

    int pocetak = 0;
    int poz = text.find(' ');

    while(poz != std::string::npos){

        if(poz>pocetak){
            rijeci.push_back(text.substr(pocetak,poz-pocetak));
        }

        pocetak = poz+1;
        poz = text.find(' ',pocetak);
    }

    if(pocetak<text.size()){
        rijeci.push_back(text.substr(pocetak));
    }

    return rijeci;
}

int main(){

    std::string recenica;

    std::cout<<"Unesite recenicu: "<<std::endl;
    std::getline(std::cin,recenica);

    std::vector<std::string> rijeci = split_words(recenica);

    std::string najdulja = rijeci[0];
    std::string prva = rijeci[0];

    for(auto x:rijeci){
        if(x.size()>najdulja.size()){
            najdulja = x;
        }
        if(x<prva){
            prva = x;
        }
    }

    std::string spojeno;

    for(int i = rijeci.size()-1;i>=0;i--){
        spojeno+=rijeci[i];
        if(i>0){
            spojeno+="-";
        }
    }

    std::cout<<"broj rijeci: "<<rijeci.size()<<std::endl;
    std::cout<<"najdulja: "<<najdulja<<std::endl;
    std::cout<<spojeno<<std::endl;
    std::cout<<"prva po abecedi: "<<prva<<std::endl;

    return 0;
}
