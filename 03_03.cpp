#include <iostream>
#include <array>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours){

    double suma = 0;

    for(auto x:hours){
        suma+=x;
    }

    return suma;
}

int best_day(const std::array<double, DAYS>& hours){

    int dan = 0;

    for(int i = 0;i<DAYS;i++){
        if(hours[i]>hours[dan]){
            dan=i;
        }
    }

    return (dan+1);
}

int main(){

    std::array<double, DAYS> tjedan1;
    std::array<double, DAYS> tjedan2;



    std::cout<<"Unesite sate ucenja za svaki dan: "<<std::endl;

    for(int i = 0;i<DAYS;i++){
        std::cin>>tjedan1[i];
    }

    std::cout<<"Ukpno sati: "<<total(tjedan1)<<std::endl;
    std::cout<<"Dan s najvise sati: "<<best_day(tjedan1)<<std::endl;

    tjedan2.fill(1.5);

    if(tjedan1==tjedan2){
        std::cout<<"Tjedni su jednaki"<<std::endl;
    }else{
        std::cout<<"Tjedni nisu jednaki"<<std::endl;
    }

    if(tjedan1<tjedan2){
        std::cout<<"Prvi tjedan je manji od drugog"<<std::endl;
    }else{
        std::cout<<"Prvi tjedan nije manji od drugog"<<std::endl;
    }

    tjedan1.swap(tjedan2);

    std::cout<<"Nakon swap-a: "<<std::endl;
    std::cout<<"Ukupno sati prvi tjedan: "<<total(tjedan1)<<std::endl;
    std::cout<<"Ukupno sati drugi tjedan: "<<total(tjedan2)<<std::endl;
    

    return 0;
}
