#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max_so_far=0;
    int max_ending_here=0;
    for(int i=1;i<prices.size();i++){
        max_ending_here+=prices[i]-prices[i-1];
        if(max_ending_here>max_so_far){
            max_so_far=max_ending_here;
        }
        if(max_ending_here<0){
            max_ending_here=0;
        }
    }
    return max_so_far;
}

int main(){
    int n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<maxProfit(v)<<endl;
}