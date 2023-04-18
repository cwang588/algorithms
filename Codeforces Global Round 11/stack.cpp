#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
void push(int x){
	a[++cnt]=x;
	int now=cnt;
	while(now!=1&&a[now]<a[now/2]){
		swap(a[now],a[now/2]);
		now/=2;
	}
}
int top(){
	return a[1];
}
void pop(){
	a[1]=a[cnt--];
	int now=1;
	while((a[now]>a[now<<1]&&now*2<=cnt)||(a[now]>a[now<<1|1]&&now*2+1<=cnt)){
		if(now*2+1<=cnt){
			if(a[now*2]<a[now*2+1]){
				swap(a[now*2],a[now]);
				now=now*2;
			}
			else{
				swap(a[now*2+1],a[now]);
				now=now*2+1;
			}
		}
		else{
			swap(a[now],a[now*2]);
			now*=2;
		}
	}
}
int main(){
	//freopen("stack.in","r",stdin);
	//freopen("stack.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			scanf("%d",&x);
			push(x);
		}
		else if(t==2)printf("%d\n",top());
		else pop();
	}
	return 0;	
}
