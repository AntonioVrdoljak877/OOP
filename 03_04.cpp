#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain){

    int poz = email.find('@');

    if(poz == std::string::npos){
        return false;
    }

    if(email.find('@') != email.rfind('@')){
        return false;
    }

    if(poz == 0 || poz == email.size()-1){
        return false;
    }

    std::string d = email.substr(poz+1);

    if(d.find('.') == std::string::npos){
        return false;
    }

    user = email.substr(0,poz);
    domain = d;

    return true;
}

int main(){

    std::string email;
    std::string user;
    std::string domain;

    std::cout<<"Unesite email: "<<std::endl;
    std::getline(std::cin,email);

    if(split_email(email,user,domain)==true){
        std::cout<<"korisnik: "<<user<<", domena: "<<domain<<std::endl;
    }else{
        std::cout<<"neispravna adresa"<<std::endl;
    }

    return 0;
}
