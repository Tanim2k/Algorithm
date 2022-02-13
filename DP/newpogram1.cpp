#include<bits/stdc++.h>
using namespace std;
#define Nitro() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod=1e9;
int dp[10][1 << 10];
int recur(vector<vector<int>> &cost, int i , int mask , int n){
    if(mask == 0){
        return cost[i][0];
    }
    
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }
    
    int ans = INT_MAX;
    for(int j = 0; j < n ; j++){
        if(mask & 1 << j){
            ans = min(ans, cost[i][j] + recur(cost , j, mask ^ (1 << j), n));
        }
    }
    
    return dp[i][mask] = ans;
}


int32_t main(int argc, char const *argv[])
{
	Nitro();
	int n;
	cin>>n;
	vector<vector<int>>cost;
     for(int i=0;i<n;i++)
     {
     	for(int j=0;j<n;j++)
     		{
     			int x;
     			cin>>x;
     			cost[i][j]=x;
     		}
     }

	  
    memset(dp, -1 , sizeof(dp));
    int ans = recur(cost , 0 , ((1 << n) - 1) , n);
    cout<<ans<<endl;
}