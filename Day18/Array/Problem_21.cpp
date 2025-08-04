#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int Stock(vector<int>& price){
        int n = price.size();
        int maxprofit = 0, bestway = price[0];
        for(int i = 1; i<n; i++){
            if(bestway < price[i]){
                maxprofit = max(maxprofit,price[i]-bestway);
            }
            bestway = min(bestway,price[i]);
        }
        return maxprofit;
    }
};
int main(){
    Solution sol;
    vector<int> price = {2,3,4,5,4,6,7,8,2,3,4,5,4};
    sol.Stock(price);
    int profit = sol.Stock(price);
    cout<<"Max prfit : "<<profit<<endl;
    return 0;
};
