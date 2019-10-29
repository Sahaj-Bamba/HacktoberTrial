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
    int n,i,ct=0,exp;
    cin>>n;
    vector<int> a(n), b(n);
    map<int, int> h;
    set<int> s;
    For(i, 0, n){
        cin>>a[i];
        h[a[i]] = i;
    }
    For(i, 0, n){
        cin>>b[i];
    }
    for(i=n-1;i>-1;i--){
        if(s.upper_bound(-1*h[b[i]]) != s.end())
            ct++;
        s.insert(-1*h[b[i]]);
    }
    cout<<ct<<endl;
    return 0;
}

