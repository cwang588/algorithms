#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int n, m, k;
int cas;
int mp[maxn][maxn];
void cg1(int x, int y) 
{
	int t = mp[x][y];
	mp[x][y] = mp[x][y + 1];
	mp[x][y + 1] = mp[x + 1][y + 1];
	mp[x + 1][y + 1] = mp[x + 1][y];
	mp[x + 1][y] = t;
}
void cg2(int x, int y) 
{
	int t = mp[x + 1][y];
	mp[x + 1][y] = mp[x + 1][y + 1];
	mp[x + 1][y + 1] = mp[x][y + 1];
	mp[x][y + 1] = mp[x][y];
	mp[x][y] = t;
}
int resum(int x, int y) 
{
	return mp[x][y] + mp[x + 1][y] + mp[x][y + 1] + mp[x + 1][y + 1];
}
int dfs(int u) 
{
	if(u > 2 * k)
	 return 0;
	int ans = 0;
	if(u & 1) 
	{
		ans = 0;
		for (int i = 1; i <= 3; i ++) 
		{
			for (int j = 1; j <= 3; j ++) 
			{
				cg1(i, j);
				ans = max(ans, dfs(u + 1) + resum(i, j));
				cg2(i, j);
			}
		}
	} else 
	{
		ans = INF;
		for (int i = 1; i <= 3; i ++) 
		{
			for (int j = 1; j <= 3; j ++) 
			{
				cg1(i, j);
				ans = min(ans, dfs(u + 1) + resum(i, j));
				cg2(i, j);
			}
		}
	}
	return ans;
}
signed main() 
{
	scanf("%d", &cas);
	while(cas --) 
	{
		scanf("%d", &k);
		for (int i = 1; i <= 4; i ++)
		 for (int j = 1; j <= 4; j ++)
		 scanf("%d", &mp[i][j]);
		cout << dfs(1) << endl;
	}
	return 0;
}
