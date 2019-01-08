#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod  90
ll fun(string s,string a,ll k,ll i,ll inc){	
	if(i>=s.length()-1){
		
		if(a!="" && inc==0 && stoi(a)%k==0){
			cout<<a<<endl;
			return 1;
		}
		if(inc==1 && stoi(a+s[i])%k==0){
			cout<<a+s[i]<<endl;
			return 1;
		}
		else
			return 0;
	}
	ll sum=0;
	if(inc==0){
		sum+=fun(s,a,k,i+1,0);
		sum+=fun(s,a,k,i+1,1);
	}
	else{
		
		sum+=fun(s,a+s[i],k,i+1,0);	
		sum+=fun(s,a+s[i],k,i+1,1);	
		
	}
	
	return sum;
}
int main(){
	
	string s;
	s="676";
	
	ll k;
	k=6;

	ll sum=0;
	
	sum+=fun(s,"",k,0,0);
	
	sum+=fun(s,"",k,0,1);
	
	return 0;
}
/*


*/
