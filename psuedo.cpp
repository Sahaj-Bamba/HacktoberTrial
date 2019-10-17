#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 9223372036854775807
#define mini 9223372036854775807
ll tree1[4000006];
ll tree2[4000006];
ll lazy1[4000006];
ll lazy2[4000006];
void updateMin(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != mini)
    { 
        tree[node]=min(tree[node],lazy[node]);   
        if(start != end)
        {
            lazy[node*2] =min(lazy[node],lazy[2*node]);  
            lazy[node*2+1]=min(lazy[node],lazy[2*node+1]);
        }
        lazy[node] = mini;                                
    }
    if(start > end or start > r or end < l)              
        return;
    if(start >= l and end <= r)
    {
        tree[node]=min(tree[node],val);
        if(start != end)
        {
            lazy[node*2]=min(lazy[node*2],val);
            lazy[node*2+1]=min(lazy[node*2+1],val);
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateMin(node*2, start, mid, l, r, val);    
    updateMin(node*2 + 1, mid + 1, end, l, r, val); 
    tree[node] = min(tree[node*2],tree[node*2+1]);       
}

ll queryMin(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;      
    if(lazy[node] != mini)
    { 
        tree[node]=min(tree[node],lazy[node]);   
        if(start != end)
        {
            lazy[node*2] =min(lazy[node],lazy[2*node]);  
            lazy[node*2+1]=min(lazy[node],lazy[2*node+1]);
        }
        lazy[node] = mini;                                
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryMin(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryMin(node*2 + 1, mid + 1, end, l, r); // Query right child
    return min(p1,p2);
}
void updateMax(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        tree[node]=max(tree[node],lazy[node]);   
        if(start != end)
        {
            lazy[node*2] =max(lazy[node],lazy[2*node]);  
            lazy[node*2+1]=max(lazy[node],lazy[2*node+1]);
        }
        lazy[node] = 0;                                
    }
    if(start > end or start > r or end < l)              
        return;
    if(start >= l and end <= r)
    {
        tree[node]=max(tree[node],val);
        if(start != end)
        {
            lazy[node*2]=max(lazy[node*2],val);
            lazy[node*2+1]=max(lazy[node*2+1],val);
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateMax(node*2, start, mid, l, r, val);    
    updateMax(node*2 + 1, mid + 1, end, l, r, val); 
    tree[node] = max(tree[node*2],tree[node*2+1]);       
}

ll queryMax(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;      
    if(lazy[node] != 0)
    { 
        tree[node]=max(tree[node],lazy[node]);   
        if(start != end)
        {
            lazy[node*2] =max(lazy[node],lazy[2*node]);  
            lazy[node*2+1]=max(lazy[node],lazy[2*node+1]);
        }
        lazy[node] = 0;                                
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return max(p1,p2);
}
int main()
{
    boost
    ll t,i;
    cin>>t;
    for(i=0; i<t; i++)
    {
    
    }
    return 0;
}
