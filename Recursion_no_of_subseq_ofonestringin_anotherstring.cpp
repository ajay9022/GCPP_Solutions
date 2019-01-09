//https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ull;

ll fun(string s,string t,string a,ll k,ll inc){	
	if(k==s.length()-1){
		if(inc==0){
			if(t==a){
				return 1;
			}
			else
				return 0;
		}
		else{
			if(a+s[k]==t){
				return 1;
			}
			else{
				return 0;
			}
		}
		cout<<k<<endl;
		
	}
	if(k>=s.length() && t!=a){
		return 0;
	}
	ll ans=0;
	if(inc==0){
		ans+=fun(s,t,a,k+1,0) + fun(s,t,a,k+1,1);	
	}
	else if(inc==1){
		ans+=fun(s,t,a+s[k],k+1,0) + fun(s,t,a+s[k],k+1,1);
	}
	return ans;
}
int main(){
	
	string s;cin>>s;
	string t;cin>>t;
	
	ll n=s.length();
/*
	ll visited[256];
	ll L[n];
	memset(visited,-1,sizeof(visited));
	memset(L,-1,sizeof(L));
*/	
	ll ans=0;
	ans=fun(s,t,"",0,0)+fun(s,t,"",0,1);
	cout<<ans;
	/*
	for(ll i=0;i<n;++i){
		std::cout<<L[i]<<" ";
	}
	*/

	return 0;
}