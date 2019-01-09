#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod  90

ll fun(string s,string x,string y,ll a,ll b){	
	if(a>=s.length() || b>=s.length()){
		if(x==y && x!=""){
			return x.length();
			
		}
		else{
			return 0;
		}
	}
	ll ans=0;
	if(s[a]==s[b] && a==b){
		//cout<<"+";
		ans=max(fun(s,x,y,a,b+1),fun(s,x,y,a+1,b));
		//ans+=;

	}
	else if(s[a]==s[b] && a!=b){
		//cout<<"/";
		ans=fun(s,x+s[a],y+s[b],a+1,b+1);
	}
	else if(s[a]!=s[b]){
		//cout<<"\n-";
		ans=max(fun(s,x,y,a+1,b),fun(s,x,y,a,b+1));
	}
	return ans;
}
int main(){
	
	string s;cin>>s;
	//string a;cin>>a;

	

	//ll mat[50][50];
	//memset(mat,0,sizeof(mat));
	
	cout<<fun(s,"","",0,0);
	
	
	
	return 0;
}
