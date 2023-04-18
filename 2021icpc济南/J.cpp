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
		int b = i;
		rep(j,i+1,n) if (fabs(a[j][i]) > fabs(a[b][i])) b = j;
		if (i != b) swap(a[i], a[b]), res *= -1;
		res *= a[i][i];
		if (res == 0) {
			return 0;
		}
		rep(j,i+1,n) {
			long double v = a[j][i] / a[i][i];
			if (v != 0) rep(k,i+1,n) a[j][k] -= v * a[i][k];
		}
//		if (a[i][i] < 0) res *= -1;
//		else if(a[i][i] == 0)res=0;
//		if (res == 0){
//			assert(false);
//			return 0;
//		}
//		rep(j,i+1,n) {
//			long double v = 1e130L*a[j][i] / a[i][i];
//			for(int k=0;k<n;++k)a[j][k]*=1e130L;
//			if (v != 0) rep(k,i+1,n) a[j][k] -= v * a[i][k];
//			long double tmp=fabs(a[j][0]);
//			for(int k=1;k<n;++k)tmp=min(tmp,fabs(a[j][k]));
//			for(int k=0;k<n;++k)a[j][k]/=tmp;
//		}
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
		long double dt = 0.0;
		for (int i = 0; i < s.length(); ++i) {
			dt = dt * 10.0L + (int)(s[i] - '0');
		}
		mat.clear();
		long long Max=0;
		for (int i = 0; i < n; ++i) {
			vector<long double> tmp;
			long long x;
			for (int j = 0; j < n; ++j) {
				cin >> x;
				Max=max(Max,abs(x));
				tmp.push_back((long double)x);
			}
			mat.push_back(tmp);
		}
		long double ans = det(mat);
//		cout << ans << ' '<< dt << endl;
		assert(fabs(fabs(ans) - fabs(dt)) / dt < 0.1L);
		if (ans >= 0) {
			cout << "+\n";
		} else {
			cout << "-\n";
		}
	}
	return 0;
}