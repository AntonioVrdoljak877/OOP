#include <iostream>


void my_sort(int arr[], int n, bool (*cmp)(int, int)){

    int tmp = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1;j++){
                if(!cmp(arr[j+1],arr[j])){
                     tmp = arr[j+1];
                     arr[j+1]=arr[j];
                     arr[j]=tmp;
                }
        }
    }


    

}


inline bool ascending(int a, int b){

    return a>b;

}


inline bool descending(int a, int b){

    return a<b;

}


int main(){


    int niz[] = {2,1,4,3,5,10};
    int n = 6;


    
    my_sort(niz,n,ascending);


    
    for(int i = 0;i<n;i++){
        std::cout<<niz[i]<<" ";
    }
    
my_sort(niz,n,descending);


    for(int i = 0;i<n;i++){
        std::cout<<niz[i]<<" ";
    }

    






}
