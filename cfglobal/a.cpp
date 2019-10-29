#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define null NULL
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e17
#define si 400005
#define For(i,a,b) for(i=a;i<b;i++)
#define piv pair<int ,vector<int>>


ll powmod(ll a, ll b){ ll ans = 1; while(b){if(b&1)ans=(ans%M*a%M)%M; a=(a%M*a%M)%M; b=b>>1;}return ans;}

int main(){
    boost
    int n, i, t, ct, a[200000], b[200000];
    cin>>n;
    For(i, 0, n){
        cin>>a[i];
        b[i] = a[i]/2;
    }
    ct = 0;
    For(i, 0, n){
        ct += b[i];
    }
    int s = 0;
    if(ct < 0)
        s = -1;
    if(ct > 0)
        s = 1;
    int absct = abs(ct);
    For(i, 0, n){
        t = abs(a[i]);
        if((absct>0)&&(t&1)&&(s == 1)&&(a[i]<0)){
            b[i] = b[i]-1;
            absct--;
        }
        else if((absct>0)&&(t&1)&&(s == -1)&&(a[i]>0)){
            b[i] = b[i]+1;
            absct--;
        }
        cout<<b[i]<<" ";
    }
    return 0;
}

