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
#define flush fflush(stdout);
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
// From Errichto Tutorial
ll nxt[300001][20];
ll recent[20];
int main()
{
	boost
	ll n,q;
	cin>>n>>q;
	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<20;i++)
	{
		recent[i]=n;
	}
	for(ll i=n-1;i>=0;i--)
	{
		for(ll j=0;j<20;j++)
		{
			nxt[i][j]=n;
		}
		for(ll j=0;j<20;j++)
		{
			if(a[i]&(1<<j))
			{
				ll where=recent[j];// index nearest whose suffix is reachable 
				if(where!=n)
				{
					nxt[i][j]=min(nxt[i][j],where);
					for(ll k=0;k<20;k++)
					{
						nxt[i][k]=min(nxt[i][k],nxt[where][k]);
					}
				}
				recent[j]=i;
			}
		}
	}
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		l--,r--;
		ll flag=0;
		for(ll i=0;i<20;i++)
		{
			if(a[r]&(1<<i))
			{
				if(nxt[l][i]<=r)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			cout<<"Shi"<<endl;
		else
			cout<<"Fou"<<endl;
	}
	return 0;
}
