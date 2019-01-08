#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod  90

ll fun(string s,ll x,string a,ll y){	
	ll sum=0;
	if(y>=a.length()){
		return 1;
	}
	if(x>=s.length()){
		return 0;
	}
	if(s[x]==a[y]){
		sum+=fun(s,x+1,a,y+1);
		sum+=fun(s,x+1,a,y);	
	}
	else{
		sum+=fun(s,x+1,a,y);
	}
	return sum;
}
int main(){
	
	string s;cin>>s;
	string a;cin>>a;

	
	
	cout<<fun(s,0,a,0);
	
	
	
	return 0;
}
/*


*/
