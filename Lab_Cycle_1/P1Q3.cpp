#include<iostream>
using namespace std;
void Reverse(const string& s, int i){
    if (i<0)
    return;
    else 
    {
        cout<<s[i];
        return(Reverse(s,i-1));
    }
}
int main(){
    string S;
    cout<<"Enter the String : ";
    cin>>S;
    int l = S.length();
    cout<<"The reverse of "<<S<<" is : ";
    Reverse(S,l);
    cout<<endl;
    return 0;
}
