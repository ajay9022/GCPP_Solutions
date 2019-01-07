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

ll fun(ll arr[][4],ll c,ll count,ll visited[]){
	if(c==3){
		return count;
	}

	ll flag=0;
	ll mn=10000;
	for(ll i=0;i<10;++i){
		if(arr[c][i]==1 && visited[i]==0){
			visited[i]=1;
			mn=min(mn,fun(arr,i,count+1,visited));

			visited[i]=0;
			flag=1;
		}
	}
	if(flag==0){
		return -1;
	}
	return mn;
}
int main(){
	
///*
	//ll start,end;
	//cin>>start>>end;
/*
	ll arr[10][10]=
	{{0,0,1,0,0,0,0,0,0,0},
	 {0,0,0,0,1,0,0,1,0,0},
	 {0,1,0,0,1,0,0,1,0,0},
	 {0,0,0,0,0,0,0,0,1,1},
	 {0,0,0,0,0,0,0,0,0,0},
	 {0,0,0,1,0,0,0,1,0,0},
	 {0,0,0,0,1,0,0,0,0,1},
	 {0,0,0,0,0,0,1,0,0,0},
	 {0,0,0,0,1,0,0,0,0,1},
	 {0,0,0,0,0,1,0,0,0,0},
	};
*/
	ll arr[][4]=
	{	{0,1,0,0},
		{0,1,1,0},
		{1,0,0,0},
		{0,0,1,0}
	};	
	ll visited[10];
	memset(visited,0,sizeof(visited));
	visited[0]=1;
	cout<<fun(arr,0,0,visited);
	return 0;
}

/*








*/
