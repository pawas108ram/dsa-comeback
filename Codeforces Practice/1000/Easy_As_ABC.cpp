//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};
string s[3],ans="CCC";
bool vis[3][3];
void dfs(ll x,ll y,string cur)
{
	cur+=s[x][y];
	if(cur.size()==3)
	{
		ans=min(ans,cur);
		return;
	}
	ll i;
	vis[x][y]=true;
	for(i=0;i<8;i++)
	{
		ll tx=x+dx[i],ty=y+dy[i];
		if(tx>=0&&tx<3&&ty>=0&&ty<3&&(!vis[tx][ty]))
		{
			dfs(tx,ty,cur);
		}
	}
	vis[x][y]=false;
	return;
}
int main(){
	ll i,j;
	cin>>s[0]>>s[1]>>s[2];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			dfs(i,j,"");
		}
	}
	cout<<ans<<endl;
	return 0;
}