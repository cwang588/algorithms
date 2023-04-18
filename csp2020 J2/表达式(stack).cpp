#include<cstdio>
#include<stack>
#define N 300010
using namespace std;
int n,q,cnt,rt,ope[N],num[N],bfr[N],ls[N],rs[N],fa[N];
//����� i Ϊ�������ope[i] Ϊ 1(&)��2(|)��3(!)��
//����� i Ϊ������num[i] Ϊ�������
//bfr Ϊ��������ĳ�ֵ
//ls,rs,fa �ֱ�Ϊ���ӽ�㣬���ӽ�㣨!�����û�У��������
int val[N],fls[N],tre[N],xfls[N],xtre[N];
//val Ϊ������ֵ
//fls Ϊ f(u,0)��tre Ϊ f(u,1)
//xfls[i] Ϊ�� i ������Ϊ 0 ʱ���������ʽ��ֵ��xtre ��֮��
//ע�� xfls,xtre �Ǳ�����ţ�fls,tre �ǽ����
stack<int>stk;
void read(){//���벢ת��
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
void dfs1(int u){//�����������ֵ
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
