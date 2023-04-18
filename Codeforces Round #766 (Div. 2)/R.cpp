#include<bits/stdc++.h>
using namespace std;

const int maxn=1000005;
int a[maxn],tl[maxn],nx[maxn];
long long d[maxn],s[maxn];
vector<int> vec[maxn];
int X[maxn];
map<pair<int,int>,int> mp;
int idx=0,ln=0;
typedef pair <long long,int> pr;
priority_queue <pr,vector<pr>,greater<pr> > q;
int getid(int A,int B){
	int id=0;
	if(mp.count({A,B})) id=mp[{A,B}];
	else{
		id=mp[{A,B}]=++idx;
		vec[A].push_back(B);
	}
	return id;
}
int main(){
	int T,n,m,k;
	scanf("%d",&T);
	while(T--){
		ln=idx=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&X[i]);
		}
		for(int i=1;i<=2*k+2;i++) tl[i]=++ln;
		getid(1,1);
		getid(n,m);
		for(int i=1;i<=k;i++){
			int A,B,C,D,H;
			scanf("%d%d%d%d%d",&A,&B,&C,&D,&H);
			int x=getid(A,B);
			int y=getid(C,D);
			a[tl[x]=nx[tl[x]]=++ln]=y;
			s[ln]=-H;
		}
		for(int i=1;i<=n;i++){
			sort(vec[i].begin(),vec[i].end());
			for(int j=1;j<vec[i].size();j++){
				int x=getid(i,vec[i][j-1]);
				int y=getid(i,vec[i][j]);
				a[tl[x]=nx[tl[x]]=++ln]=y;
				a[tl[y]=nx[tl[y]]=++ln]=x;
				s[ln-1]=s[ln]=1ll*(vec[i][j]-vec[i][j-1])*X[i];
			}
		}
		memset(d,0x3f,sizeof(d));
		int S=getid(1,1);
		q.push(make_pair(d[S]=0,S));
	    while(!q.empty()){
	        while(!q.empty()&&q.top().first>d[q.top().second]) q.pop();
	        if(q.empty()) break;
	        pr t=q.top();
	        q.pop();
	        int x=t.second;
	        for(int i=nx[x];i;i=nx[i]){
	            if(d[a[i]]>d[x]+s[i]){
	                d[a[i]]=d[x]+s[i];
	                q.push(make_pair(d[a[i]],a[i]));
	            }
	        }
	    }
	    int T=getid(n,m);
	    if(d[T]==d[0]){
	    	printf("NO ESCAPE\n");
	    }else printf("%d\n",d[T]);
	    for(int i=1;i<=n;i++) vec[i].clear();
	    mp.clear();
	    for(int i=0;i<=ln;i++) tl[i]=nx[i]=0;
	}
}