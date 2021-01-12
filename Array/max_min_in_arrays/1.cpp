#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set <int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    int ans;
    for(auto j:st){
        ans=j;
    }
    cout<<*st.begin()<<" "<<ans<<endl;
}