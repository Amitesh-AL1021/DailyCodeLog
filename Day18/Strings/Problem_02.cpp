#include<iostream>
using namespace std;
int main () {
    string name = "Amitesh";
    
    int start = 0; 
    int end = name.size()-1;
    while(start<end){
        swap(name[start],name[end]);
        start ++;
         end --;
    }
    cout<<name;
    int size = 0;
    // last character which are present in the string end by defualt '\0';
    while(name[size]!='\0')
    {
        size++;
    }
    cout<<endl;
    cout<<size<<" ";
    return 0;
}