#include <iostream>



int main(){


    int n{};

    std::cout<<"Unesite broj dana: "<<std::endl;

    std::cin>>n;
    
    std::vector<double> temperatura(n);

    std::cout<<"Unesite temperature: "<<std::endl;

    for(int i = 0;i<n;i++){
        std::cin>>temperatura[i];
    }

    std::vector<double> razlika_tempratura(n-1);
    razlika_tempratura.reserve(n-1);

    int i = 0;
    for(auto it=temperatura.begin();it!=temperatura.end();++it){
        if(it+1 != temperatura.end()){
            razlika_tempratura[i]=(*(it+1)-*(it));
        i++;
        }
        

    }

   
    std::cout<<"Promjene temperatura: "<<std::endl;

    for(auto x:razlika_tempratura){
        std::cout<<x<<std::endl;
    }

    if(n>7){
        temperatura.resize(7);
    }else{
        for(int i = 0;i<(7-n);i++){
            temperatura.push_back(temperatura[n-1]);
        }
    }

    std::cout<<"Izvjestaj: "<<std::endl;

    for(auto x:temperatura){
        std::cout<<x;
    }
   
    


}
