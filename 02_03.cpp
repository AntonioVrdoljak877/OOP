#include <iostream>


template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)){

    T tmp = 0;

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

template <typename T>
inline bool ascending(T a, T b){

    return a>b;

}

template <typename T>
inline bool descending(T a, T b){

    return a<b;

}


int main(){


    double niz[] = {2, 1, 4, 3, 5, 10};
    int n = 6;
    char niz2[] = {'a', 'b', 'c', 'd', 'e', 'f'};


    
    my_sort(niz,n,ascending<double>);


    
    for(int i = 0;i<n;i++){
        std::cout<<niz[i]<<" ";
    }
    
    my_sort(niz2,n,descending);


    for(int i = 0;i<n;i++){
        std::cout<<niz2[i]<<" ";
    }

    






}
