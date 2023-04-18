#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct edge{
        int from,to,nxt;
    }e[205];
    int Head[105],cnt=0;
    int degree[105];
    void add(int x,int y){
        ++degree[y];
        ++cnt;
        e[cnt].from=x;
        e[cnt].to=y;
        e[cnt].nxt=Head[x];
        Head[x]=cnt;
    }
    int n,m;
    int getid(int x,int y){
        return x*m+y+1;
    }
    int dp[105];
    int countPaths(vector<vector<int>>& grid) {
    	memset(Head,0,sizeof(Head));
    	memset(degree,0,sizeof(degree));
    	memset(dp,0,sizeof(dp));
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m-1;++j){
                if(grid[i][j]>grid[i][j+1])add(getid(i,j),getid(i,j+1));
                if(grid[i][j]<grid[i][j+1])add(getid(i,j+1),getid(i,j));
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n-1;++j){
                if(grid[j][i]>grid[j+1][i])add(getid(j,i),getid(j+1,i));
                if(grid[j][i]<grid[j+1][i])add(getid(j+1,i),getid(j,i));
            }
        }
        queue<int>q;
        for(int i=1;i<=n*m;++i){
            if(!degree[i])q.push(i);
        }
        while(!q.empty()){
            int now=q.front();
            q.pop();
            ++dp[now];
            for(int i=Head[now];i;i=e[i].nxt){
                int to=e[i].to;
                dp[to]+=dp[now];
                --degree[to];
                if(!degree[to])q.push(to);
            }
        }
        int ans=0;
        for(int i=1;i<=n*m;++i)ans+=dp[i];
        return ans;
    }
};
int main(){
	vector<vector<int>>now={{1,1},{3,4}};
	Solution a;
	cout<<a.countPaths(now);
	return 0;
}