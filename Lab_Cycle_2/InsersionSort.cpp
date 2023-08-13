#include<iostream>
using namespace std;
class InsersionSort{
    private:
    int n;
    double *arr;
    public:
    void input();
    void display();
    void sort();
    InsersionSort(int x){
        n=x;
        arr= new double[n];
    }
    InsersionSort(){}
};
void InsersionSort:: input(){
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    arr = new double[n];
    cout<<"Enter the Elements of the Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void InsersionSort:: display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void InsersionSort::sort(){
for (int i =1;i<n;i++){
    double key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]<key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
}
int main(){
    InsersionSort ob;
    ob.input();
    ob.sort();
    cout<<"Sorted Array is : ";
    ob.display();
    return 0;
}


// OUTPUT
// Enter the number of elements in the array : 8
// Enter the Elements of the Array : 623.43 82.412 534.612 137.6 -733.216 28.16 363.532 8.34423
// Sorted Array is : 623.43 534.612 363.532 137.6 82.412 28.16 8.34423 -733.216

