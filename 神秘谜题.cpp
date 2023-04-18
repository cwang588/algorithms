#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

class Trie {
public:
	int cnt;
	int next[2];
};

void insert(int x);
void update(int index, int depth);
int query();

const int MAXN = 2e5 + 5, MAXBIT = 32, MAX = MAXN * MAXBIT;
Trie trie[MAX];
int sum1[MAXBIT];
int trcnt;

int main() {
	//freopen("test.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		// ��ʼ��
		memset(sum1, 0, sizeof(sum1));
		trcnt = 0;
		// ��ѭ��
		int opt;
		int x;
		while (n --) {
			// ����
			scanf("%d", &opt);
			// �޸�
			if (opt == 1) {
				update(0, 0);
			}
			// ����
			if (opt == 2) {
				scanf("%d", &x);
				insert(x);
			}
			// ���
			int res = query();
			printf("%d\n", res);
		}
		// ��ʼ��
		memset(trie, 0, (trcnt+1)*sizeof(Trie));
	}
	return 0;
}
// ����
void insert(int x) {
	int index = 0;
	for (int i = 0; i <= 31; i ++) {
		// ��ȡ�ӽڵ�
		int k = (x >> i) & 1;
		int & pos = trie[index].next[k];
		// ����
		if (!pos) {
			pos = ++trcnt; 
		}
		trie[index].cnt ++;
		if (k == 1) sum1[i] ++;
		// �ݽ�
		index = pos;
	}
}
// �޸�
void update(int index, int depth) {
	// �ݹ�
	if (trie[index].next[1]) {
		update(trie[index].next[1], depth + 1);
	}
	// ���´�
	if (trie[index].next[0]) sum1[depth] += trie[trie[index].next[0]].cnt;
	if (trie[index].next[1]) sum1[depth] -= trie[trie[index].next[1]].cnt;
	// ����
	swap(trie[index].next[0], trie[index].next[1]);
}
// ��ѯ
int query() {
	int res = 0;
	for (int i = 0; i <= 31; i ++) {
		res |= ((sum1[i] & 1) << i);
	}
	return res;
}
