// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int>num = {2,4,6,7,8,9};
//     int target = 17;
//     for(int i = 0; i<num.size(); i++){
//         for(int j = i+1; j <num.size(); j++){
//             if(num[i]+num[j] == target) {
//                 cout<<"Pais of nubmer is "<<num[i]<< " + "<<num[j]<<" of this " <<target;
//                 return 0;
//             }
//         }
//     }
//     cout<<"There is no number in the array up to "<<target<<endl;
//     return 0;
// };


// optimize approach 


#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num = {2, 3, 5, 6, 7, 8};
    int target = 100;
    int n = num.size()-1;
    int i = 0;
    int j = n-1;
    while(i < j){
       int   ps = num[i] + num[j];
       if(ps<target){
           i++;
       }
       else if(ps>target){
           j--;
       }
       else{
           cout<<"this is the pair "<<num[i]<<" + " <<num[j]<<" of target "<<target;
           return 0;
       }
    }
    cout<<"Not any pair which is sum like this  " <<target<<endl;
    return 0;
};
