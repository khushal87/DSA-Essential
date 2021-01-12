#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int start,int end){
    if(start>end){
        return;
    }
    int temp = arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    solve(arr,start+1,end-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}