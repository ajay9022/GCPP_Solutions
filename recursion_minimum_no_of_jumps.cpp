//https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
//by recursion
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod  90
ll gcd(ll a,ll b){
	if(a==0 || b%a==0)
		return a;
	else	
		return gcd(b%a,a);
}

ll fun(ll arr[],ll n,ll k,ll L[]){
	static int f=1;
	++f;
	if(k==n-1){
		return 0;
	}
	ll mn=10000;
	for(ll i=1;i<=arr[k] && i+k<n;++i){
		/*
		if(L[k]!=-1){
			mn=min(mn,L[k]);
			cout<<k<<" "<<L[k]<<endl;
		}
		else{
			mn = min(mn,1+fun(arr,n,i+k,L));	
		}
		*/
		mn = min(mn,1+fun(arr,n,i+k,L));	
	}
	L[k]=mn;
	return mn;//returning f gives the no. of calls to fun()
}
int main(){
	

	ll n;
	ll arr[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5}; 
	n=sizeof(arr)/sizeof(ll);
	
	//cout<<n;
	ll L[n];

	memset(L,-1,sizeof(arr));
	L[n-1]=0;
	cout<<fun(arr,n,0,L);
	
	
	
	


	return 0;
}
/*


*/
