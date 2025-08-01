#include<iostream>
using namespace std;
int main(){
    string s ;
    cout<<"Enter your string : ";
    cin>>s;
    int start = 0; 
    int end = s.size()-1;

    while(start<end) 
    {
    if(s[start]!= s[end]){
        cout<<"It is not a palindrome: ";
        return 0;
    }
     start ++;
     end --;
}

     cout<<"It is palindrome :";
};