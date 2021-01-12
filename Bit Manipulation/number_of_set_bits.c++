#include <bits/stdc++.h>
using namespace std;

int solve(int N){
    int ctr=0;
    while(N>0){
        ctr+=N&1;
        N>>=1;
    }
    return ctr;
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}