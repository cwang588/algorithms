#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

#define rint register int
#define int ll
#define ll long long
#define ld long double

#define clear(a) memset(a, 0, sizeof(a))

const int Maxn = 1e5 + 10;

using namespace std;

template <typename T> inline void read(T& x) {
    int w = 0; x = 0; char ch = getchar();
    while(!isdigit(ch)) w = (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    x = w ? -x : x;
}

template <typename T, typename... Args>

inline void read(T& x, Args&... args) { read(x); read(args...); }

int n, m, p; 
ll a[Maxn];

namespace SegmentTree {
	#define rt 1, n, 1
	#define ls l, mid, x << 1
	#define rs mid + 1, r, x << 1 | 1
	struct rec {
		int l, r; ll sum, add, mul;
		rec() {}
		rec(int inl, int inr, ll inv) { l = inl, r = inr, sum = inv, add = 0, mul = 1; }
	}T[Maxn << 2];
	rec operator + (const rec &A, const rec &B) { return rec(A.l, B.r, (A.sum + B.sum) % p); }
	inline void Upd(int x) { T[x] = T[x << 1] + T[x << 1 | 1]; }
	inline void Add(int x, ll v) { (T[x].add += v) %= p, (T[x].sum += v * (T[x].r - T[x].l + 1)%p)%= p; }
	inline void Mul(int x, ll v) { (T[x].add *= v) %= p; (T[x].mul *= v) %= p; (T[x].sum *= v) %= p; }
	inline void Push(int x) {
		if (T[x].mul != 1) Mul(x << 1, T[x].mul), Mul(x << 1 | 1, T[x].mul), T[x].mul = 1;
		if (T[x].add) Add(x << 1, T[x].add), Add(x << 1| 1, T[x].add), T[x].add = 0;
	}
	inline void Modify(int l, int r, int x, int sl, int sr, ll v, int opt) {
		if (sl <= l && r <= sr) { if (opt == 1) Mul(x, v); else Add(x, v); return; }
		Push(x); int mid = (l + r) >> 1;
		if (sl <= mid) Modify(ls, sl, sr, v, opt);
		if (sr > mid) Modify(rs, sl, sr, v, opt);
		Upd(x);
	}
	inline ll Query(int l, int r, int x, int sl, int sr) {
		if (sl <= l && r <= sr) return T[x].sum % p;
		Push(x); int mid = (l + r) >> 1;
		if (sl <= mid) {
			if (sr > mid) return (Query(ls, sl, sr) + Query(rs, sl, sr)) % p;
			else return Query(ls, sl, sr) % p;
		}
		if(sr>mid)return Query(rs, sl, sr) % p;
		return 0;
	}
	inline void Build(int l, int r, int x) {
		if (l == r) { T[x] = rec(l, r, a[l]); return; }
		int mid = (l + r) >> 1; 
		Build(ls); Build(rs); Upd(x);
	}
}

using namespace SegmentTree;

signed main() {
	read(n, m, p);
	for (rint i = 1; i <= n; ++ i) read(a[i]);
	Build(rt);
	for (rint i = 1; i <= m; ++ i) {
		int opt; read(opt);
		if (opt != 3) {
			int x, y; ll z;
			read(x, y, z);
			Modify(rt, x, y, z, opt);
		}
		else {
			int x, y;
			read(x, y);
			printf("%lld\n", Query(rt, x, y));
		}
	}
    return 0;
}
