#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long double det(vector<vector<long double> >& a) {
	int n = sz(a); long double res = 1;
	rep(i,0,n) {
		if (a[i][i] < 0) res *= -1;
		else if(a[i][i] == 0)res=0;
		if (res == 0){
			//assert(false);
			return 0;
		}
		rep(j,i+1,n) {
			long double v = a[j][i] / a[i][i];
//			for(int k=0;k<n;++k)a[j][k]*=1e130;
			if (v != 0) rep(k,i+1,n) a[j][k] -= v * a[i][k];
//			long double tmp=fabs(a[j][0]);
//			for(int k=1;k<n;++k)tmp=min(tmp,fabs(a[j][k]));
//			for(int k=0;k<n;++k)a[j][k]/=tmp;
		}
	}
	return res;
}
vector<vector<long double> > mat;
string s;
int main()
{
//	freopen("J.in", "r", stdin);
	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		cin >> s;
		mat.clear();
		long long Max=0;
		vector<vector<long double> >origin; 
		for (int i = 0; i < n; ++i) {
			vector<long double> tmp;
			long double x;
			for (int j = 0; j < n; ++j) {
				cin >> x;
				x*=1e30;
				tmp.push_back((long double)x);
			}
			mat.push_back(tmp);
		}
		origin=mat;
		int num1=0,num2=0;
		if (det(mat) > 0) {
			++num1;
		} else {
			++num2;
		}
		for(int i=1;i<=min(7,n);++i){
			mat=origin;
			swap(mat[0],mat[i-1]);
			if (det(mat) >= 0) {
				++num2;
			} else {
				++num1;
			}
		}
		if (num1>=num2) {
			cout << "+\n";
		} else {
			cout << "-\n";
		}
	}
	return 0;
}