#include<iostream>
using namespace std;
class Bubble_Sort{
    private:
    int n;
    double *arr;
    public:
    void input();
    void display();
    void sort();
    Bubble_Sort(int x){
        n=x;
        arr=new double[n];
    }
    Bubble_Sort(){
        n=0;
        arr = new double[n];
    }
};
void Bubble_Sort::  input(){
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    arr= new double[n];
    cout<<"Enter the Elements of the Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void Bubble_Sort:: display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Bubble_Sort:: sort(){
    for(int i =0;i<n-1;i++){
        bool swap =false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                double temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap = true;
            }
        }
        if(swap==false) 
                break;
    }
}
int main(){
    Bubble_Sort ob;
    ob.input();
    ob.sort();
    cout<<"Sorted Array is : ";
    ob.display();
    return 0;
}



// OUTPUT 
// Enter the number of elements in the array : 8
// Enter the Elements of the Array : 623.43 82.412 534.612 137.6 -733.216 28.16 363.532 8.34423
// Sorted Array is : -733.216 8.34423 28.16 82.412 137.6 363.532 534.612 623.43