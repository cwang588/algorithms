#include<cstdio>
#include<stack>
#define N 300010
using namespace std;
int n,q,cnt,rt,ope[N],num[N],bfr[N],ls[N],rs[N],fa[N];
//若结点 i 为运算符，ope[i] 为 1(&)或2(|)或3(!)。
//若结点 i 为变量，num[i] 为变量编号
//bfr 为这棵子树的初值
//ls,rs,fa 分别为左子结点，右子结点（!运算符没有），父结点
int val[N],fls[N],tre[N],xfls[N],xtre[N];
//val 为变量初值
//fls 为 f(u,0)，tre 为 f(u,1)
//xfls[i] 为第 i 个变量为 0 时，整个表达式的值。xtre 反之。
//注意 xfls,xtre 是变量编号，fls,tre 是结点编号
stack<int>stk;
void read(){//读入并转树
	char ch=getchar();
	while(1){
		while(ch==' ') ch=getchar();
		if(ch=='\n') break;
		if(ch=='x'){
			int a=0; ch=getchar();
			while(ch>='0'&&ch<='9') { a=a*10+ch-'0'; ch=getchar(); }
			cnt++; num[cnt]=a; stk.push(cnt); continue;
		}
		cnt++;
		if(ch=='&'){
			ope[cnt]=1;
			rs[cnt]=stk.top(); fa[rs[cnt]]=cnt; stk.pop();
			ls[cnt]=stk.top(); fa[ls[cnt]]=cnt; stk.pop();
			stk.push(cnt);
		}
		if(ch=='|'){
			ope[cnt]=2;
			rs[cnt]=stk.top(); fa[rs[cnt]]=cnt; stk.pop();
			ls[cnt]=stk.top(); fa[ls[cnt]]=cnt; stk.pop();
			stk.push(cnt);
		}
		if(ch=='!'){
			ope[cnt]=3;
			ls[cnt]=stk.top(); fa[ls[cnt]]=cnt; stk.pop();
			stk.push(cnt);
		}
		ch=getchar();
	}
	rt=stk.top();
}
void dfs1(int u){//计算各子树初值
	if(num[u]) { bfr[u]=val[num[u]]; return; }
	dfs1(ls[u]); if(ope[u]!=3) dfs1(rs[u]);
	if(ope[u]==1) bfr[u]=bfr[ls[u]]&&bfr[rs[u]];
	if(ope[u]==2) bfr[u]=bfr[ls[u]]||bfr[rs[u]];
	if(ope[u]==3) bfr[u]=!bfr[ls[u]];
}
void dfs2(int u){//dp
	if(u==rt) { fls[u]=0; tre[u]=1; }
	else if(u==ls[fa[u]]){
		if(ope[fa[u]]==1){
			fls[u]=fls[fa[u]];
			tre[u]=bfr[rs[fa[u]]]?tre[fa[u]]:fls[fa[u]];
		}
		if(ope[fa[u]]==2){
			fls[u]=bfr[rs[fa[u]]]?tre[fa[u]]:fls[fa[u]];
			tre[u]=tre[fa[u]];
		}
		if(ope[fa[u]]==3){
			fls[u]=tre[fa[u]];
			tre[u]=fls[fa[u]];
		}
	}else{
		if(ope[fa[u]]==1){
			fls[u]=fls[fa[u]];
			tre[u]=bfr[ls[fa[u]]]?tre[fa[u]]:fls[fa[u]];
		}
		if(ope[fa[u]]==2){
			fls[u]=bfr[ls[fa[u]]]?tre[fa[u]]:fls[fa[u]];
			tre[u]=tre[fa[u]];
		}
		if(ope[fa[u]]==3){
			fls[u]=tre[fa[u]];
			tre[u]=fls[fa[u]];
		}
	}
	if(num[u]){
		xfls[num[u]]=fls[u];
		xtre[num[u]]=tre[u];
		return;
	}
	dfs2(ls[u]); if(ope[u]!=3) dfs2(rs[u]);
}
int main(){
	read();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	dfs1(rt); dfs2(rt);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int a; scanf("%d",&a);
		printf("%d\n",val[a]?xfls[a]:xtre[a]);
	}
	return 0;
}
