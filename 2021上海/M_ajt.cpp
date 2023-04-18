#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("M.in", "r", stdin);
	freopen("M_ajt.out", "w", stdout);
	int n;
	cin >> n;
	int x = (n+2)/2;
	printf("%.9f\n", (1.0 - (1.0*((n-1) / 2)*(1.0/((n/2)+1))))/((n - (n - 1) / 2) * n));
	return 0;
}