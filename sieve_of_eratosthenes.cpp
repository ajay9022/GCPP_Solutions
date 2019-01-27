#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod  90
void sieve_of_eratosthenes(vector<ll> &v, ll k){
	for(ll i=2;i<=sqrt(k);++i){
		for(ll j=i+1;j<=k;++j){
			if(j%i==0){
				v[j]=1;
			}
		}
	}
}
int main(){
	fast;
	ll k;
	cin>>k;
	vector<ll> v(k,0);
	sieve_of_eratosthenes(v, k);
	for(ll i=2;i<v.size();++i){
		if(v[i]==0){
			cout<<i<<endl;
		}
	}
	
	
	return 0;
}
/**/
