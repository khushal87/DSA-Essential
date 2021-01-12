#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        if(arr[start]<0&&arr[end]<0){
            start++;
        }
        else if(arr[start]>0&&arr[end]>0){
            end--;
        } else if(arr[start]>0&&arr[end]<0){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        else{
            start++;
            end--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}