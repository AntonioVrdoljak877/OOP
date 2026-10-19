#include <iostream>
#include <vector>



void input_vector(std::vector<int>& v)
{

    int n;
    std::cin>>n;

    v.push_back(n);

    while(n!=0)
    {
        v.push_back(n);
        std::cin>>n;
    }


}

void print_vector(const std::vector<int>& v)
{

    for(const auto x:v)
    {
        std::cout<<x<<std::endl;

    }

}

int main()
{

    std::vector <int> vek;
    input_vector(vek);
    print_vector(vek);

    for (auto e = vek.rbegin(); e != vek.rend(); ++e)
        std::cout << *e << " ";

        std::vector<int> vek2;

        for(int i = 0;i<20;i++){
            vek2.push_back(i);
            std::cout<<"Kaacitet"<<vek2.capacity()<<std::endl;
            std::cout<<"Velicina"<<vek2.size()<<std::endl;
        }

        std::vector<int> vek3;
        std::cout<<"                     "<<std::endl;

        vek3.reserve(100);
          for(int i = 0;i<20;i++){
            vek3.push_back(i);
            std::cout<<"Kaacitet"<<vek3.capacity()<<std::endl;
            std::cout<<"Velicina"<<vek3.size()<<std::endl;
        }

        vek3.shrink_to_fit();
        std::cout<<"Novi vektor kapacitet: "<<vek3.capacity();





    return 0;

}
