#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main()
{
	for (int i = 1; i <= 500; ++i) {
		auto is = fstream("M.in");
		is << i << '\n';
		is.close();
		system("M.exe");
		system("M_ajt.exe");
		if (system("fc M.out M_ajt.out")) {
			printf("WA on i=%d\n", i);
			return 0;
		}
	}
	printf("AC\n");
	return 0;
}