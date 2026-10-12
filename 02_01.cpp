#include <iostream>
#define MAX(a, b) a > b ? a : b

inline int my_max(int a, int b){
    return (a>b) ? a:b;
}

template <typename T>
T my_max(T a, T b){

    return (a>b) ? a:b;

}




int main()
{

    int a = MAX(3,5);
    //int b = 2 * MAX(3, 5); neispravno
    int b = 2 * (MAX(3, 5));
    int c = MAX(3, 5) + 1;


    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;

    int i = 3;

    int r1 = MAX(++i,2);
    std::cout<<"i nakon poziva makra: "<<i<<std::endl;

    int r2 = my_max(++i,2);

    std::cout<<"i nakon poziva inline: "<<i<<std::endl;

    std::cout<<"Rezultat makra: "<<r1<<std::endl;
    std::cout<<"Rezultat inline: "<<r2<<std::endl;

    std::cout<<"Rezultat template-a: "<<my_max<>(2,4)<<std::endl;
    std::cout<<"Rezultat template-a: "<<my_max<>(2.4,5.6)<<std::endl;
    std::cout<<"Rezultat template-a: "<<my_max<>('a','b')<<std::endl;

      std::cout<<"Rezultat template-a: "<<my_max<>("hello","world")<<std::endl;









    return 0;
}
