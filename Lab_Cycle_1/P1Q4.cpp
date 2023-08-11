#include<iostream>
using namespace std;
bool palindrome(const string& s, int left, int right){
    if(left>=right)
    return true;
    else if(s[left]==s[right])
    return(palindrome(s,left+1,right-1));
    else 
    return false;
}
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    bool b = palindrome(s, 0,s.length()-1);
    if(b){
    cout<<"The string "<<s<<" is palindrome."<<endl;
    }
    else{
    cout<<"The string "<<s<<" is not palindrome."<<endl;
    }
    return 0;
}
// Enter the string : dogeeseseegod
// The string dogeeseseegod is palindrome.