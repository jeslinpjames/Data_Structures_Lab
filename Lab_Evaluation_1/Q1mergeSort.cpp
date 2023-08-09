#include<iostream>
using namespace std;
void merge(int arr[], int left,int middle,int right){
    int n1 = middle-left+1;
    int n2 = right-middle;
    int L[n1],R[n2];
    for(int i =0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int j =0;j<n2;j++){
        R[j]=arr[middle+1+j];
    }
    int i =0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left,int rihgt){
    if(left>=rihgt){
        return;
    }
    int middle = left+(rihgt-left)/2;
    mergeSort(arr,left,middle);
    mergeSort(arr,middle+1,rihgt);
    merge(arr,left,middle,rihgt);
}
int* accept(int size){
    cout<<"Enter the elements of the array : ";
    int *ar = new int[size];
    for(int i =0;i<size;i++){
        cin>>ar[i];
    }
    return ar;    
}
void print_array(int arr[] ,int size){
    for(int i =0;i<size;i++)
    cout<<arr[i]<<" ";
}
int main(){
    cout<<"Enter the size of the array : ";
    int size;
    cin>>size;
    int *ar = new int[size];
    ar = accept(size);
    mergeSort(ar,0,size-1);
    cout<<"The sorted array is : ";
    print_array(ar,size);
    cout<<endl;
    delete[] ar;
    return 0;
}