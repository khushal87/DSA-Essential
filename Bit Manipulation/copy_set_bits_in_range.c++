#include <bits/stdc++.h>
using namespace std;

int copy_set_bits(int x,int y,int l,int r){
    if(l<1||r>32){
        return -1;
    }
    for(int i=l;i<=r;i++){
        int mask = 1<<(i-1);
        if(y&mask){
            x = x | mask;
        }
    }
    return x;
}

int main(){
    int x,y,l,r;
    cin>>x>>y>>l>>r;
    cout << copy_set_bits(x,y,l,r)<<endl;
    return 0;
}