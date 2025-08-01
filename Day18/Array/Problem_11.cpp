#include<iostream>
using namespace std;
void fun(int arr[], int n){
    cout<<sizeof(arr)<<endl;
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
}
int main(){
    int arr[5] = {3,2,4,5,4};
    cout<<sizeof(arr)<<endl;
    fun(arr,5);
}