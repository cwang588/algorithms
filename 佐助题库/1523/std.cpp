#include<bits/stdc++.h>

using namespace std;

int n, m;
long long s1 = 1, s2 = 1;
long long ans;
#define maxn 20010
#define Rep(x, a, b) for(int x = a; x <= b; ++ x)

struct node{
    long long v, c;
}e[maxn];

bool cmp(node a, node b){
	return a.v > b.v;
}

int main(){
//	freopen("zz1523.in","r",stdin);
//	freopen("zz1523.out","w",stdout);
	scanf("%d%d", &n, &m);
	Rep(i, 1, n - 1){//��Ϊ�г�n*m�飬���Ժ�����n - 1�� 
		scanf("%lld", &e[i].v);
		e[i].c = 0;//������Ϊ0 
	}
	Rep(i, n, n + m - 2){//ͬ��������m-1�� 
		scanf("%lld", &e[i].v);
		e[i].c = 1;//������Ϊ1 
	} 
	sort(e + 1, e + n + m - 1, cmp);
	Rep(i, 1, n + m - 2){
		if(e[i].c == 0){
			ans += e[i].v * s2;
			++ s1;
		}
		else{
			ans += e[i].v * s1;
			++ s2;
		}
	}
	printf("%lld", ans);
	return 0;
}
