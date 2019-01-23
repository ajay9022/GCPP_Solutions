//https://www.geeksforgeeks.org/shortest-common-supersequence/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod  90
ll mat[100][100];


ll lcsuperseq(string a,string b){
	for(ll i=0;i<=a.length();++i){
		mat[i][0]=i;
	}
	for(ll i=0;i<=b.length();++i){
		mat[0][i]=i;
	}
	for(ll i=1;i<=a.length();++i){
		for(ll j=1;j<=b.length();++j){
			if(a[i-1]==b[j-1])
				mat[i][j] = 1+mat[i-1][j-1];
			else
				mat[i][j]=1+min(mat[i-1][j],mat[i][j-1]);
		}
	}
	for(ll i=0;i<=a.length();++i){
		for(ll j=0;j<=b.length();++j){
			cout<<mat[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;

	return mat[a.length()][b.length()];
}
ll lcs(string a,string b,ll i,ll j){
	if(i>=a.length()){
		return b.length()-j;
	}
	if(j>=b.length()){
		return a.length()-i;
	}
	if(a[i]==b[j]){
		return 1+lcs(a,b,i+1,j+1);
	}
	else{
		return 1+min(lcs(a,b,i,j+1),lcs(a,b,i+1,j));
	}
}
void printlcsuperseq(string a,string b){
	string s="";
	for(ll i=a.length(),j=b.length();i>0 && j>0;){
		cout<<i<<" "<<j<<endl;
			//s=char+s;
		if(a[i-1]==b[j-1]){
			s=a[i-1]+s;
			--i;
			--j;
		}
		else{
			if(mat[i-1][j] > mat[i][j-1]){
				s=b[j-1]+s;
				--j;
			}
			else{
				s=a[i-1]+s;
				--i;
			}
		}
	
	}
	cout<<s;
}
int main(){
	fast;
	string a,b;
	cin>>a>>b;
	cout<<lcs(a,b,0,0)<<endl;
	cout<<lcsuperseq(a,b)<<endl;
	printlcsuperseq(a,b);
	
	return 0;
}
/**/
