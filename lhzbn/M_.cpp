#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Point {
	ll x, y, id;
	Point operator-(const Point& p) const {
		return Point{x - p.x, y - p.y};
	}
};
ll cross_prod(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}
Point Poly[maxn], Poly_sorted[maxn];
Point Op[maxn], ord;
struct Segment {
	int first, second, id;
	bool operator<(const Segment& s) const {
		if (first != s.first) return first < s.first;
		return second > s.second;
	}
};
vector<Segment> seg;
bool cmp(const Point& a, const Point& b) {
	return cross_prod(a - ord, b - ord) > 0;
}
int main()
{
	freopen("M.in", "r", stdin);
	cin.tie(0)->sync_with_stdio(0);
	ll T, n, m;
	cin >> T;
	while (T-- > 0) {
		cin >> n >> m;
		seg.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> Poly[i].x >> Poly[i].y;
			Poly[i].id = i;
			Poly_sorted[i] = Poly[i];
		}
		for (int i = 1; i <= m; ++i) {
			cin >> Op[i].x >> Op[i].y;
		}
		for (int i = 1; i <= m; ++i) {
			ord = Op[i];
			sort(Poly_sorted + 1, Poly_sorted + n + 1, cmp);
			if (Poly_sorted[1].id - 1 >= Poly_sorted[n].id) {
				seg.push_back(Segment{
					Poly_sorted[n].id,
					Poly_sorted[1].id - 1,
					i
				});
				seg.push_back(Segment{
					Poly_sorted[n].id + n,
					Poly_sorted[1].id + n - 1,
					i
				});
			} else {
				seg.push_back(Segment{
					Poly_sorted[n].id,
					Poly_sorted[1].id + n - 1,
					i
				});
				if (Poly_sorted[1].id == 1)
					seg.push_back(Segment{
						Poly_sorted[n].id + n,
						2 * n,
						i
					});
			}
		}
		sort(seg.begin(), seg.end());
//		cout << "segs:\n";
//		for (auto s : seg) {
//			cout << s.first << ' ' << s.second << endl;
//		}
//		cout << endl;
		vector<int> vec, ansvec;
		int ans = maxn;
		for (int l = 1; l <= n; ++l) {
			if (seg[0].first > l) continue;
			int i = 0;
			while (seg[i].first < l && i < seg.size()) ++i;
			if (i == seg.size() || seg[i].first != l) continue;
			// select i now
			assert(seg[i].first == l);
			int cnt = 1;
			vec.clear();
			vec.push_back(seg[i].id);
			int realr = seg[i].second, remr = seg[i].second, last = i, tosel = i;
			bool ok = false;
			for (i = i + 1; i < seg.size(); ++i) {
				if (seg[i].second <= remr) continue;
				if (seg[i].first > realr) {
					if (seg[i].first == realr + 1) {
						// select seg[i]
						cnt++;
						vec.push_back(seg[i].id);
						realr = remr = seg[i].second;
						last = i;
						tosel = i;
					} else {
						// left point > covered r + 1, hav a gap
						if (remr < seg[i].first - 1) {
							ok = false;
							break;
						}
						// select seg[tosel]
						cnt++;
						vec.push_back(seg[tosel].id);
						realr = seg[tosel].second;
						remr = seg[i].second;
						last = tosel;
						tosel = i;
					}
					if (realr >= l + n - 1) {
						ok = true;
						break;
					}
					if (remr >= l + n - 1) {
						ok = true;
						cnt++;
						vec.push_back(seg[tosel].id);
						break;
					}
				} else {
					tosel = i;
					remr = seg[i].second;
					if (remr >= l + n - 1) {
						ok = true;
						cnt++;
						vec.push_back(seg[tosel].id);
						break;
					}
				}
			}
			if (ok && cnt < ans) {
				ans = cnt;
				ansvec = vec;
			}
		}
		if (ans == maxn) {
			cout << "-1\n";
		} else {
			cout << ans << '\n';
			for (int i = 0; i < ansvec.size() - 1; ++i) {
				cout << ansvec[i] << ' ';
			}
			cout << ansvec[ansvec.size() - 1] << '\n';
		}
	}
	return 0;
}