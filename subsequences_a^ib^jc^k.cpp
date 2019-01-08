#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod  90
ll fun(string s,int n,int k,string b,ll d){
//cout<<k<<" "<<b<<"\n";
//static int po=0;
//++po;
	if(k>=n){
		return 0;
	}
	ll ans=0;
	
	if(b.empty()==true || b.back()=='a' || (k==0 && s[k]=='a')){
		//cout<<"\tx\n";
		for(ll i=k;i<n;++i){
			if(s[i]=='a'){
				//cout<<'-'<<endl;
				ans+= fun(s,n,i+1,b+'a',d+1);
				//cout<<"\ne"<<d<<" "<<ans<<" "<<b<<endl;
			}
			else if(s[i]=='b' && b.empty()==false){
				//cout<<<<endl;
				//cout<<'+'<<'('<<i<<" "<<d<<" "<<b<<')'<<endl;
				ans+= fun(s,n,i+1,b+'b',d+1);
			}

		}
		//cout<<"-"<<ans<<endl;
		return ans;
		//return po;
	}
	else if(b.back()=='b'){
		ll ans=0;
		//cout<<"\ty\n";
		for(ll i=k;i<n;++i){
			if(s[i]=='b' && b.back()=='b'){
				//cout<<b<<endl;
				ans+=fun(s,n,i+1,b+'b',d+1);

			}
			else if(s[i]=='c' && b.back()=='b'){
				//cout<<"="<<endl;
				ans+= 1+fun(s,n,i+1,b+'c',d+1);
				//cout<<"->"<<ans<<endl;
			}
		}
		//cout<<"*"<<ans<<endl;
		return ans;
		//return po;
	}
	else if(b.back()=='c'){
		//cout<<"\tz\n";
		ll ans=0;
		for(ll i=k;i<n;++i){
			if(s[i]=='c'){
				ans+= 1+fun(s,n,i+1,b+'c',d+1);
			}
		}
		return ans;
		//return po;
	}
	return ans;
	//return po;
}
int main(){
	
	//ll n;
	//cin>>n;
	
	
	string s="abcabc";
	ll n=s.length();
	//cout<<s[0];
	cout<<fun(s,n,0,"",0);

	return 0;
}
/*


*/
