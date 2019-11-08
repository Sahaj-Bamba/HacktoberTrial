#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1000000007;
ll arr[3][3][1000002]={0};
void multi(ll arr1[3][3],ll arr2[3][3])
{
	ll i,j,k;
	ll x[3][3];
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			x[i][j]=0;
			for(k=0; k<3; k++)
				x[i][j]=(x[i][j]+((arr1[i][k]*arr2[k][j])%mod))%mod;
		}
	}
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			arr1[i][j]=x[i][j];
}
ll power(ll F[3][3],ll n)
{
	ll B[3][3]={{1,0,0},{1,2,3},{0,3,5}};
	if(n==1)
		return 2*F[1][0]+3*F[2][0];
	ll xyz=power(F,n/2);
	if(n<1000000)
	{
		if(arr[0][0]==0)
		{
			multi(F,F);
			if(n%2!=0)
				multi(F,B);
			ll i,j;
			for(i=0; i<3; i++)
			{
				for(j=0; j<3; j++)
					arr[i][j][n]=F[i][j];
			}
		}
		else
		{
			ll i,j;
			for(i=0; i<3; i++)
			{
				for(j=0; j<3; j++)
					F[i][j]=arr[i][j][n];
			}
		}
	}
	else
	{
		multi(F,F);
		if(n%2!=0)
			multi(F,B);
	}
	return 2*F[1][0]+3*F[2][0];
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
	ll t,i;
	cin>>t;
	for(i=0; i<t; i++)
	{
		ll B[3][3]={{1,0,0},{1,2,3},{0,3,5}};
		ll n;
		cin>>n;
		ll ans;
		ans=power(B,n)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
