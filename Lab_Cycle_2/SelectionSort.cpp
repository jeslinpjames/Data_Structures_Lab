#include<iostream>
using namespace std;
class SelectionSort{
    private:
    int n;
    string *s;
    public:
    void input();
    void display();
    void sort();
    SelectionSort(){}
    SelectionSort(int x){
        n=x;
        s = new string[n];
    }
};
void SelectionSort:: input(){
    cout<<"Enter the number of words : ";
    cin>>n;
    s= new string[n];
    cout<<"Enter the Elements of the Array : ";
    for(int i =0;i<n;i++){
        cin>>s[i];
    }
}
void SelectionSort:: display(){
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void SelectionSort::sort(){
    for(int i=0;i<n-1;i++){
        int min =i;     
        for(int j=i+1;j<n;j++){
            if(s[j]<s[min]){
                min=j;
            }
        }
        if(min!=i){
            string temp = s[min];
            s[min]=s[i];
            s[i]=temp;
        }
    }
}
int main(){
    SelectionSort ob;
    ob.input();
    ob.sort();
    cout<<"Sorted Array is : ";
    ob.display();
    return 0;
}

