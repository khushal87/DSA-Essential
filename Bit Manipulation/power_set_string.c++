#include <bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s){
    int sz = s.length();
    int num= pow(2,sz);
    multiset <string> mst;
    for(int i=0;i<num;i++){
        string te;
        for(int j=0;j<sz;j++){
            if(i&(1<<j)){
                te+=s[j];
            }
        }
        mst.insert(te);
    }
    vector <string> v;
    for(auto j:mst){
        if(j!="")
            v.push_back(j);
    }
    return v;
}

int main(){
    string s;
    cin>>s;
    vector <string> ans = AllPossibleStrings(s);
    for(auto j:ans){
        cout<< j << " ";
    }
    cout<<endl;
}