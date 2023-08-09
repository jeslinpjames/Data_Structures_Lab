// Given an array, arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in a range, but not the array. The missing elements should be printed in sorted order.  (Time complexity: O(n^2)- 3 marks, O(nlog n)-4 marks, O(n)-5 marks)
#include<iostream>
using namespace std;
int main(){
    int low,high;
    cout<<"Enter the lower bound : ";
    cin>>low;
    cout<<"Enter the upper bound : ";
    cin>>high;
    cout<<"Enter the number of elements in the array : ";
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of the array : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int *missing = new int[high+1];
    int j=0;
   
    for (int i = 0; i < n; i++) {
        if (arr[i] >= low && arr[i] <= high) {
            missing[arr[i]] = 1;
        }
    }
    cout << "The missing Elements are: ";
    for (int i = low; i <= high; i++) {
        if (missing[i] == 0) {
            cout << i << " ";
        }
    }
    delete[] arr;
    delete[] missing;
    return 0;    
}