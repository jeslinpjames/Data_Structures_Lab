// Let A be an array containing N integers, with the first n of them being positive and the rest being negative. Give an algorithm to find n in O(log N). Can you find a solution in O(log n) ?
#include<iostream>
using namespace std;
int* accept(int size){
    cout<<"Enter the elements of the array : ";
    int *ar = new int[size];
    for(int i =0;i<size;i++){
        cin>>ar[i];
    }
    return ar;    
}
int findIndex(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) { 
        int middle = left + (right - left) / 2;
        if (arr[middle] < 0) {
            if (middle == 0 || arr[middle - 1] >= 0) {
                return middle;
            } else {
                right = middle - 1;
            }
        } else {
            left = middle + 1;
        }
    }

    return -1;
}
int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int *ar = new int[size];
    ar = accept(size);
    int index = findIndex(ar,size);
    cout<<"The index of the first negative element is : "<<index<<endl;
    delete[] ar;
    return 0;
}