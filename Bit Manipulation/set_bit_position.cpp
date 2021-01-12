#include <bits/stdc++.h>
using namespace std;

int check(int N){
    if(N==0){
        return false;
    } else{
        if((N&(N-1))==0){
            return true;
        } else {
            return false;
        }
    }
}
  
int findPosition(int N) {
    // code here
    if(check(N)==true){
        return log2(N)+1;
    } else {
        return -1;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<findPosition(n)<<endl;
    }
}