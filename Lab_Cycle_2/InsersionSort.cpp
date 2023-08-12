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
    cout<<"Array is : ";
    ob.display();
    ob.sort();
    cout<<"Sorted Array is : ";
    ob.display();
    return 0;
}

