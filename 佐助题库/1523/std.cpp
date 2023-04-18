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
	Rep(i, 1, n - 1){//因为切成n*m块，所以横着切n - 1次 
		scanf("%lld", &e[i].v);
		e[i].c = 0;//把其标记为0 
	}
	Rep(i, n, n + m - 2){//同理，竖着切m-1次 
		scanf("%lld", &e[i].v);
		e[i].c = 1;//把其标记为1 
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
