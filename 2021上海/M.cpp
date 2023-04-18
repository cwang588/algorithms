#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("M.in", "r", stdin);
//	freopen("M.out", "w", stdout);
	int n;
	cin >> n;
	int x = (n+2)/2;
	if(n&1)printf("%.9f\n", (2.0*x-n)/(x*x*n));
	else printf("%.9f\n", (1.0-(n/2)*(1.0/(n/2+1)))/(1.0*(n/2)*n));
	return 0;
}