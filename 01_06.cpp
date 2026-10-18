#include <iostream>

struct Fraction{
    int numerator, denominator;

    void reduce(){
    int a = numerator;
    int b = denominator;

    while(b!=0){
        int x=b;
        b=a%b;
        a=x;
    }

    numerator = numerator/a;
    denominator = denominator/a;

    }


    double value(){
        return numerator/denominator;
    }

    void print(){
        std::cout<<numerator<<"/"<<denominator;
    }


};


Fraction sum(const Fraction& a, const Fraction& b){
    Fraction nova = {a.numerator*b.denominator + b.numerator*a.denominator,a.denominator*b.denominator};

    nova.reduce();
    return nova;
}


int main(){


    Fraction a = {25,17};
    Fraction b = {60,40};
    

    Fraction y = sum(a,b);

    y.print();




    return 0;
}
