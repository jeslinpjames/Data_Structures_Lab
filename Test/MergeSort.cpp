#include<iostream>
using namespace std;
class MergeSort{
    private:
    int n;
    double *arr;
    public:
    void display();
    void input();
    void sort( int left, int right);
    void merge(int left, int right, int mid);
     int getN(){
        return n;
    }
    MergeSort(){}
    MergeSort(int x){
        n=x;
        arr=new double[n];
    }
};
void MergeSort::input(){
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    arr= new double[n];
    cout<<"Enter the Elements of the Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void MergeSort::display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void MergeSort::sort(int left,int right){
    if(left<right){
        int mid = left+(right-left)/2;
        sort(left,mid);
        sort(mid+1,right);
        merge(left,right,mid);
    }
}

void MergeSort::merge(int left,int right,int mid){
    int l1=mid-left+1;
    int l2 =right-mid;
    int *ar1= new int[l1];
    int *ar2 = new int[l2];
    for(int i=0;i<l1;i++)
        ar1[i]=arr[i+left];
    for(int i=0;i<l2;i++)
        ar2[i]=arr[i+mid+1];
    int i=0,j=0,k=left;
    while(j<l1&&k<l2){
        if(ar1[i]<=ar2[j]){
            arr[k++]=  ar1[i++];
        }
        else{
            arr[k++]= ar2[j++];
        }
    }
    while(i<l1){
        arr[k++]=ar1[i++];
    }
    while(j<l2){
        arr[k++]=ar2[j++];
    }
    delete []ar1;
    delete []ar2;
}
int main(){
    MergeSort ob;
    ob.input();
    int n= ob.getN();
    ob.sort(0,n-1);
    cout<<"Sorted Array is : ";
    ob.display();
    return 0;
}
