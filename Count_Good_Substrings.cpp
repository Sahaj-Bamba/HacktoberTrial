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
//-------------------------------Template--Above-----------------------------------------------

int main()
{
	boost
	string s;
	cin>>s;
	ll n=s.length();
	ll has[2][2]={0};
	for(ll i=0;i<s.length();i++)
	{
		has[i%2][(s[i]-'a')%2]++;
	}
	ll od=n,ev=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			od+=has[i%2][0];
			ev+=has[(i%2+1)%2][0];
		}
		else if(s[i]=='b')
		{
			od+=has[i%2][1];
			ev+=has[(i%2+1)%2][1];
		}
	}
	cout<<ev/2<<" "<<od/2<<endl;
	return 0;
}
