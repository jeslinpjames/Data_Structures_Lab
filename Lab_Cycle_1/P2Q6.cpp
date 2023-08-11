#include<iostream>
using namespace std;

int* read_arr( int n)
{   int *arr = new int[n];
    cout<<"Enter the Elements : ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    return arr;
}

void print_arr(int  arr[] , int n){
    cout<<"The array is : ";
    for(int i =0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

bool search_arr(int arr[], int n, int elem){
    bool b = false;
    for(int i =0;i<n;i++){
        if(arr[i]==elem)
        b = true;
    }
    return b;
}

int get_max(int arr[], int n){
    int max = arr[0];
    for(int i = 1;i<n;i++)
    {
        if(arr[i]>max)
        max = arr[i];
    }
    return max;
}

int get_min(int arr[] , int n){
    int min = arr[0];
    for(int i= 1;i<n;i++)
    {
        if(arr[i]<min)
        min = arr[i];
    }
    return min;
}

int main(){
    int a;
    bool exit = false;
    int *arr = nullptr;
    int n = 0;
    
    do {
        cout<<"Enter 1 to accept array elements "<<endl
            <<"Enter 2 to Print the array elements "<<endl
            <<"Enter 3 to search for an element in the array  "<<endl
            <<"Enter 4 to Find the largest and smallest elements of the array "<<endl
            <<"Enter 5 to Exit"<<endl;
        cout<<"Enter your Choice : ";
        cin>>a;
        
        switch (a) {
            case 1: {
                cout<<"Enter the size of the array : ";
                cin>>n;
                arr = new int [n];
                arr = read_arr(n);
                break;
            }
            case 2:
                print_arr(arr,n);
                break;
            case 3: {
                int ele;
                cout<<"Enter Element to be searched : ";
                cin>>ele;
                bool b = search_arr(arr,n,ele);
                if (b)
                    cout<<"The Element is present in the array. "<<endl;
                else
                    cout<<"The Element is not present in the array."<<endl;
                break;
            }
            case 4: {
                int min = get_min(arr,n);
                int max = get_max(arr,n);
                cout<<"The largest element in the array is "<<max<<" and the smallest element in the array is "<<min<<"."<<endl;
                break;
            }
            case 5: 
                cout<<"Exiting..."<<endl;
                exit= true;
                break;
            default:
                cout<<"Wrong choice!"<<endl;
        }
        cout<<endl<<endl;
    } while(exit == false);
    
    return 0;
}
// Enter 1 to accept array elements
// Enter 2 to Print the array elements
// Enter 3 to search for an element in the array
// Enter 4 to Find the largest and smallest elements of the array
// Enter 5 to Exit
// Enter your Choice : 1
// Enter the size of the array : 5
// Enter the Elements : 1 2 3 4 5


// Enter 1 to accept array elements
// Enter 2 to Print the array elements
// Enter 3 to search for an element in the array
// Enter 4 to Find the largest and smallest elements of the array
// Enter 5 to Exit
// Enter your Choice : 2
// The array is : 1 2 3 4 5


// Enter 1 to accept array elements
// Enter 2 to Print the array elements
// Enter 3 to search for an element in the array
// Enter 4 to Find the largest and smallest elements of the array
// Enter 5 to Exit
// Enter your Choice : 3
// Enter Element to be searched : 4
// The Element is present in the array.


// Enter 1 to accept array elements
// Enter 2 to Print the array elements
// Enter 3 to search for an element in the array
// Enter 4 to Find the largest and smallest elements of the array
// Enter 5 to Exit
// Enter your Choice : 4
// The largest element in the array is 5 and the smallest element in the array is 1.


// Enter 1 to accept array elements
// Enter 2 to Print the array elements
// Enter 3 to search for an element in the array
// Enter 4 to Find the largest and smallest elements of the array
// Enter 5 to Exit
// Enter your Choice : 5
// Exiting...
