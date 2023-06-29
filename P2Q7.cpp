#include<iostream>
using namespace std;
int Second_largest(int arr[], int size){
    for( int i=0;i<size;i++){
        for (int j = i+1;j<size;j++){
            if(arr[j]>arr[i]){
                int temp = arr[j];
                arr[j]= arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr[1];
}
int  main(){
    int size;
    cout<<"Enter the size of the array  : ";
    cin>> size;
    int *arr = new int [size];
    cout<<"Enter the Elements of the array : ";
    for( int i =0 ;i<size; i++){
        cin>> arr[i];
    }
    if(size>1)
    {
        cout<<"The second largest element of the array is : "<<Second_largest(arr,size)<<endl;
    }
    else
    cout<<"The array doesnt have 2 elements "<<endl;
    return 0;
}

// Enter the size of the array  : 5
// Enter the Elements of the array : 11 22 33 44 55
// The second largest element of the array is : 44