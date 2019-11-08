/*
  Vivek Rathi
  CSE 3rd Year
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
#define flush fflush(stdout);
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
//-------------------------------Template--Above------------------------------------------------
vector<ll> v[1000001];
ll dp[4001][4001];
int main()
{
	boost
	ll n;
	cin>>n;
	ll b[n];
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
		v[b[i]].pb(i);
	}
	ll maxi=1;
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			ll diff=b[j]-b[i];
			if(dp[v[b[i]][0]][v[b[j]][0]]!=0)
			{
				continue;
			}
			ll prev=j,flag=0,co=2;
			while(prev<n)
			{
				if(flag==0)
				{
					ll low=0,high=v[b[i]].size()-1,ans=n;
					while(low<=high)
					{
						ll mid=(low+high)/2;
						if(v[b[i]][mid]>prev)
						{
							ans=v[b[i]][mid];
							high=mid-1;
						}
						else
							low=mid+1;
					}
					if(ans!=n)
						co++;
					prev=ans;
					flag=1;
				}
				else
				{
					ll low=0,high=v[b[j]].size()-1,ans=n;
					while(low<=high)
					{
						ll mid=(low+high)/2;
						if(v[b[j]][mid]>prev)
						{
							ans=v[b[j]][mid];
							high=mid-1;
						}
						else
							low=mid+1;
					}
					if(ans!=n)
						co++;
					flag=0;
					prev=ans;
				}
			}
			dp[v[b[i]][0]][v[b[j]][0]]=co;
			maxi=max(maxi,co);
		}
	}
	cout<<maxi<<endl;
	return 0;
}
