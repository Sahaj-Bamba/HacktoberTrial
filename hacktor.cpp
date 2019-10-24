#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 200005
#define mod 1000000007
#define vll         vector < ll >
#define vpll        vector < pair < ll ,ll> >
#define pii         pair < ll,int >
#define pll         pair < ll,ll >
#define fi          first
#define se          second
#define pb(x)       push_back(x)
#define endl        "\n"
#define mem1(x)     memset(x,-1,sizeof x)
#define mem(x)      memset(x,0,sizeof x)
#define mem63(x)    memset(x,63,sizeof x)

int a[size1];

int main()
{
    boost1;
    //boost2;
    ll n,m,i,j,t,x,q,y,w,k=1;
    vector<ll> v;
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
       // mem(a);
        map<ll,ll> mp;
        for(i=0;i<m;i++){
            cin>>x;
            a[x] = 1;
            v.push_back(x);
        }
        for(i=0;i<q;i++){
            cin>>x;
            mp[x]++;
        }
        ll ans = 0;
        for(auto x : mp){
            for(i=x.first;i <= n;i += x.first){
                if(a[i]){
                    continue;
                }
                ans += x.second;
            }
        }
        cout<<"Case #"<<k++<<": "<<ans<<endl;
        for(i=0;i<v.size();i++){
            a[v[i]] = 0;
        }
        v.clear();
    }
    return 0;
}
