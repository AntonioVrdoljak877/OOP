#include <iostream>


int& find_max(int arr[], int n){
    int max = 0;


    for(int i = 0;i<n;i++){
        if(arr[i]>arr[max]){
            max = i;
        }
    }

return arr[max];

}


int main(){

int numbers[] = {4, -7, 12, 0, 9, -3};


for(auto &x:numbers){
    std::cout<<x<<std::endl;
    if(x<0){
        x=-x;
    }
}


find_max(numbers,6) = 0;

for(auto a:numbers){
    std::cout<<a<<std::endl;
}


return 0;
}
