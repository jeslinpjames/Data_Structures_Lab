#include<iostream>
using namespace std;
long binary(long n){
    if(n<2)
    return n;
    else{
        if(n%2==0)
        return 10*binary(n/2);
        else
        return n%2+binary(n/2)*10;
    }
}
int main(){
    long n=0;
    cout<<"Enter the number : ";
    cin>>n;
    long b = binary(n);
    cout<<"The binary representation of "<<n<<" is "<<b<<endl;
    return 0;
}
// Enter the number : 15
// The binary representation of 15 is 1111