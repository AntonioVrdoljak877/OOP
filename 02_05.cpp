#include <iostream>


inline double add (double x1, double x2){
    return x1+x2;
}

inline double subtract (double x1, double x2){
    return x1-x2;
}

inline double multiply (double x1, double x2){
    return x1*x2;
}

inline double divide (double x1, double x2){
    return x1/x2;
}


int main(){


    double(*ptr[])(double,double)={add,subtract,multiply,divide};

    int a = 0;

    std::cin>>a;
    double x {2};
    double y {0};

    switch(a){
        case 0:
        std::cout<<"Rezultat zbrajanja: "<<ptr[0](x,y);
        break;

        case 1:
        std::cout<<"Rezultat oduzimanja: "<<ptr[1](x,y);
        break;

        case 2:
        std::cout<<"Rezultat mnozenja: "<<ptr[2](x,y);
        break;

        case 3:
        if(y!=0){
            std::cout<<"Rezultat dijeljenja: "<<ptr[3](x,y);
        }else{
            std::cout<<"Pokusaj dijeljenja sa nulom";
        }
        
        break;

        default:
        std::cout<<"Greska";
        break;


    }

    
    



    return 0;
}
