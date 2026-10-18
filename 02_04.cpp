#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)){

        for(int i = 0;i<n;i++){            
            arr[i]=f(arr[i]);

        }

}


int twice(int x){
    return x*2;
}



int main(){

    int arr[] = {1,2,3,4,5};
    int arr2[] = {2,3,4,5,6};
    int arr3[] = {1,2,3,4,5};
    int n = 5;

    my_transform(arr,n,twice);

    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<std::endl;
    }
    std::cout<<"------"<<std::endl;

    auto lamnda_funkcija = [](int arr[],int n){
        for(int i = 0;i<n;i++){
            if(arr[i]%2==0){
                arr[i]=(arr[i])/2;

            }else{

                arr[i]=2*(arr[i]);
            }
        }
    };

    lamnda_funkcija(arr2,n);

    for(int i = 0;i<n;i++){
        std::cout<<arr2[i]<<std::endl;
    }



    auto suma_produkt = [&](){
        int suma = 0;
        int produkt = 1;

        for(int i = 0;i<n;i++){
            suma+=arr3[i];
            produkt*=arr3[i];
        }
        std::cout<<"---------"<<std::endl;
        std::cout<<"Produkt niza: "<<produkt;
        std::cout<<"Suma niza: "<<suma;
        std::cout<<"------"<<std::endl;

    };

    suma_produkt();

    int s = 0;
    int prag = 2;


    auto lambda_3 = [prag, &s](int n, int arr3[]){
        for(int i = 0;i<n;i++){
            if(arr3[i]>prag){
                s+=arr3[i];
            }
        }

        std::cout<<"Suma clanova niza vecih od "<<prag<<" je: "<<s;

        
    };

    lambda_3(n,arr3);

    return 0;
}
