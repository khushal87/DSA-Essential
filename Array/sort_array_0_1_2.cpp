#include <bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int arr[n];
	    long long int x=0;
	    long long int y=0;
	    long long int z=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        if(arr[i]==0){
	            x++;
	        }
	        else if(arr[i]==1){
	            y++;
	        }
	        else{
	            z++;
	        }
	    }
	    for(int i=0;i<x;i++){
	        cout<<0<<" ";
	    }
	    for(int i=0;i<y;i++){
	        cout<<1<<" ";
	    }
	    for(int i=0;i<z;i++){
	        cout<<2<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}