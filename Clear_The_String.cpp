/*
  Vivek Rathi
  CSE 2nd Year
  MNNIT
*/
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e18
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//-------------------------------Template--Above------------------------------------------------
ll n;
string s;
ll dp[501][501];
ll solve(ll i,ll j)
{
	if(i==j) return 1;
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ans=inf;
	ans=1+solve(i+1,j);
	for(ll k=i+1;k<=j;k++)
	{
		if(s[i]==s[k])ans=min(ans,solve(i+1,k-1)+solve(k,j));
	}
	return dp[i][j]=ans;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	boost
	cin>>n;
	cin>>s;
	cout<<solve(0,n-1)<<endl;
	return 0;
}
