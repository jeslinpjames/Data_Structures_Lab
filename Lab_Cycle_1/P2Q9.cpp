#include<iostream>
using namespace std;
int* sort(int ar1[],int ar2[],int merged[], int size){
   int k =0;
   for(int i =0;i<size;i++){
    merged[k]=ar1[i];
    merged[k+size] = ar2[i];
    k++;
   }
   if(ar1[0]>ar1[size-1]){
    for( int i=0;i<size*2;i++){
            for (int j = i+1;j<size*2;j++){
                if(merged[j]<merged[i]){
                    int temp = merged[j];
                    merged[j]= merged[i];
                    merged[i] = temp;
                }
            }
        }
   }
   else{
    for( int i=0;i<size*2;i++){
            for (int j = i+1;j<size*2;j++){
                if(merged[j]>merged[i]){
                    int temp = merged[j];
                    merged[j]= merged[i];
                    merged[i] = temp;
                }
            }
        }

   }
    return merged;
}
int* read_arr(int size){
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
    int size ;
    cout<<"Enter the size of the two arrays : ";
    cin>>size;
    int *ar3= new int[size*2];
    cout<<"Enter the first sorted array : ";
    int *ar1=read_arr(size);
    cout<<"Enter the second sorted array : ";
    int *ar2= read_arr(size);
    ar3=sort(ar1,ar2,ar3,size);
    cout<<"The merged array is : ";
    print_array(ar3, size * 2); 
    cout<<endl; 
    delete[] ar1;
    delete[] ar2;
    delete[] ar3;  
    return 0;

}

