#include<bits/stdc++.h>
using namespace std;

int kThMin(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}

int main()
 {
	//code

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<kThMin(arr,n,k)<<endl;
	return 0;
}