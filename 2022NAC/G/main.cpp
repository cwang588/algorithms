#include <bits/stdc++.h>

using namespace std;
char a[505][505];
int n, m;

int getId(int x, int y) {
    return m * (x - 1) + y;
}

int num[505][505], num_cnt;
vector<int> spot[505][505];
const int mov[][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

bool in_bound(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

int getOrientation(char c) {
    if (c == '<')return 3;
    if (c == '>')return 1;
    if (c == '^')return 2;
    return 0;
}

int col[505][505];

void dfs(int x, int y) {
    int orientation = getOrientation(a[x][y]), tox = x + mov[orientation][0], toy = y + mov[orientation][1];
    if()
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                num[i][j] = ++num_cnt;
                for (auto k: mov) {
                    int x = i + k[0], y = j + k[1];
                    if (in_bound(x, y))spot[x][y].push_back(num[i][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != '.' && a[i][j] != '#' && !col[i][j])dfs(i, j);
        }
    }
    return 0;
}
