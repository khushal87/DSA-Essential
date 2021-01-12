#include <bits/stdc++.h>
using namespace std;

void solveBalancedPar(string s){
    stack<char> st;
    for(auto j:s){
        if(j=='('||j=='['||j=='{'){
            st.push(j);
        }
        else{
            if(st.empty()){
                st.push(j);
                continue;
            }
            char x=st.top();
            if((j==']'&&x=='[')||(j=='}'&&x=='{')||(j==')'&&x=='(')){
                st.pop();
                continue;
            }
            st.push(j);
        }
    }
    if(st.size()>0){
        cout<<"not balanced"<<endl;
    }else {
        cout<<"balanced"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        solveBalancedPar(s);
    }
    return 0;
}