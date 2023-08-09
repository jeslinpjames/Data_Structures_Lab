#include<iostream>
using namespace std;
int count_dupli(char arr[], int size){
    int Char_count [256] = {0};
    for(int i =0;i<size;i++){
        Char_count[arr[i]]++;
    }
    int no_of_dupli = 0 ;
    for(int i =0;i<256;i++){
        if(Char_count[i]>1){
        no_of_dupli ++;
        }
    }
    return no_of_dupli;
}
int main(){
    int size;
    cout<<"Enter the size of the character array : ";
    cin>>size;
    char *arr = new char[size];
    cout<<"Enter the Character array : ";
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    int dupli = count_dupli(arr,size);
    cout<<"The number of duplicate Elements in the character array is :"<<dupli<<endl;
    delete arr;
    return 0;
}


// Enter the size of the character array : 10
// Enter the Character array : helloworld
// The number of duplicate Elements in the character array is :2