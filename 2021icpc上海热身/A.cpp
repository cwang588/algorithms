#include<bits/stdc++.h>
using namespace std;
double y[100005], cost[100005], cost2[100005];
double premin[100005], sufmin[100005];
inline double sq(double a) {
	return a * a;
}
int main() {
    //cin.tie(0)->sync_with_stdio(0);
    int n;
	cin >> n;
	double tot = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> y[i];
    	tot += sqrt(1.0 + sq(y[i]-y[i-1]));
	}
	tot += sqrt(1.0+y[n]*y[n]);
    premin[0] = 1e9;
    double mincost2 = 1e9;
    for (int i = 1; i <= n; ++i) {
    	cost[i] =
			sqrt(sq(2.0) + sq(y[i+1] - y[i-1])) - 
			sqrt(1.0+sq(y[i]-y[i-1])) -
			sqrt(1.0+sq(y[i+1]-y[i]));
		premin[i] = min(premin[i-1],cost[i]);
    	cost2[i] = sqrt(sq(3.0)+sq(y[i+2]-y[i-1]))-
    		sqrt(1.0+sq(y[i]-y[i-1])) -
			sqrt(1.0+sq(y[i+1]-y[i])) - 
			sqrt(1.0+sq(y[i+2]-y[i+1]));
		if (i != n) mincost2 = min(mincost2, cost2[i]);
	}
	sufmin[n+1]=1e9;
	for (int i = n; i >= 1; --i) {
		sufmin[i] = min(sufmin[i+1], cost[i]);
	}
	for (int i = 2; i <= n - 1; ++i) {
		mincost2 = min(mincost2, cost[i] + min(premin[i-2],sufmin[i+2]));
	}
	mincost2 = min(cost[1] + sufmin[3], mincost2);
	mincost2 = min(cost[n] + premin[n-2], mincost2);
	printf("%.7f\n", tot + mincost2);
    return 0;
}