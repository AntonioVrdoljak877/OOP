#include <iostream>

namespace geo{
    const double PI = 3.14;

    double area(double r){
        return r*r*PI;
    }

    double area(double a, double b){
        return a*b;
    }

    int area(int a){
        return a*a;
    }

    

}

void print_line(char c = '-', int length = 30){

    std::cout<<std::endl;

        for(int i = 0;i<length;i++){
            std::cout<<c;
        }
    }

int main(){

    std::cout<<geo::area(5);
    print_line();
    std::cout<<geo::area(5.0);
    print_line();
    std::cout<<geo::area(2,3);
    print_line();
    std::cout<<geo::area('A');
    print_line();


    return 0;
}
