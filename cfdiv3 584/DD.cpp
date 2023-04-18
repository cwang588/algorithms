#include<bits/stdc++.h>
#define ll long long
#define re long double
using namespace std;
const int Maxn = 2e5;
int s[Maxn];
int n, k;
vector <int> arr[Maxn + 1];
int maxval;
void init()
{
	for (int i = 1; i <= n; ++i) 
	{
		int t = s[i];
		int times = 0;
		while (t) {
			arr[t].push_back(times);
			t >>= 1;
			++times;
		}
	}
}
int res;
void work()
{	
	for (int i = 0; i <= maxval; ++i) {
		if (arr[i].size() < k) 
			continue;
		sort(arr[i].begin(), arr[i].end());
		int t = 0; 
		for (int j = 0; j < k; ++j) t += arr[i][j];
		res = min(res, t);
	}
}
int main() 
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> s[i], maxval = max(maxval, s[i]);
	init();
	res = 1e9 + 7;
	work();
	cout << res;
	return 0;
}
