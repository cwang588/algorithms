#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("J.in", "w", stdout);
	cout << "1\n100\n1000\n";
	for (int i = 1; i<= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if(i == j)cout << "1000000000 ";
			else cout << "-1000000000 ";
		}
		cout << '\n';
	}
	return 0;
}