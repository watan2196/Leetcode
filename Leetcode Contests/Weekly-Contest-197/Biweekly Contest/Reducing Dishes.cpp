#include <bits/stdc++.h>
using namespace std;
//Reducing Dishes..
//https://leetcode.com/contest/biweekly-contest-23/problems/reducing-dishes/
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>sat;
vector<vector<int> >dp;
int MaxSatisfaction(int indx,int time,vector<int> &sat)
{
	if(indx>= sat.size()) return 0; // base case
	
	if(dp[indx][time] != -1) return dp[indx][time];
	
	int nottaken=MaxSatisfaction(indx+1,time,sat);
	int taken=sat[indx]*time + MaxSatisfaction(indx+1,time+1,sat);
	
	return dp[indx][time]=max(taken,nottaken);
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;

	   cin>>n;
	   sat.resize(n);
	   
	   for(int i=0;i<n;i++) cin>>sat[i];
	   
	   sort(sat.begin(),sat.end());
	   dp.resize(n,vector<int>(n+1,-1));
	   
		cout<<MaxSatisfaction(0,1,sat)<<endl;
	return 0;
}

