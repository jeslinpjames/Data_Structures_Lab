#include<iostream>
using namespace std;
int sumofDigits(int n){
    if(n<10)
    return n;
    else
    return n%10 + sumofDigits(n/10);
}
int main(){
    int n;
    cout<<"Enter the value of N : ";
    cin>>n;
    cout<<"Sum of digits of "<<n<<" is "<<sumofDigits(n)<<endl;
    return 0; 
}

// Enter the value of N : 123
// Sum of digits of 123 is 6