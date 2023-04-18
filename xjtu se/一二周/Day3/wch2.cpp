#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, step, c;
} st;
int n, t, Ans;
int mapp[1003][1003], vis[1003][1003][4];
int fx[4] = {0, 0, -1, 1};
int fy[4] = {-1, 1, 0, 0};

inline void bfs() {
	queue<node> q;
	memset(vis, 0x3f, sizeof(vis));
	st.x = 1, st.y = 1, st.step = 0, st.c = 0;
	vis[1][1][0] = 0;
	q.push(st);
	while(q.size()) {
		node u = q.front();
		q.pop();
		for(register int i = 0; i < 4; i++) {
			int xi = u.x + fx[i], yi = u.y + fy[i];
			if (xi >= 1 && xi <= n && yi >= 1 && yi <= n) {
				node d;
				d.step = (u.step + 1) % 3;
				if (d.step == 0) d.c = u.c + t + mapp[xi][yi];
				else d.c = u.c + t;
				if (d.c < vis[xi][yi][d.step]) {
					d.x = xi, d.y = yi;
					vis[xi][yi][d.step] = d.c;
					q.push(d);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> t;
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= n; j++) {
			cin >> mapp[i][j];
		} 
	}
	bfs();
	Ans = min(vis[n][n][0], min(vis[n][n][1], vis[n][n][2]));
	cout << Ans;
	return 0;
} 
