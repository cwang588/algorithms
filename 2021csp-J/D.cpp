#include<bits/stdc++.h>
using namespace std;
bool a[200005];
struct qj{
	int l,r;
	bool type;
	friend bool operator <(const qj &a,const qj &b){
		return a.l<b.l;
	}
};
struct solver{
	set<qj>s;
	bool type;
	int l;
};
bool operator <(const solver &a,const solver &b){
	return a.l<b.l;
}
solver Next[200005];
set<solver>s;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main(){
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	a[0]=2;
	int last=1;
	for(int i=2;i<=n;++i){
		if(a[i]!=a[i-1]){
			if(!last){
				last=i;
				continue;
			}
			set<qj>now;
			now.insert(qj{last,i-1,a[last]});
			s.insert(solver{now,a[i-1],last});
			last=i;
		}
	}
	if(last){
		set<qj>now;
		now.insert(qj{last,n,a[n]});
		s.insert(solver{now,a[n],last});
	}
	int id=0;
	while(!s.empty()){
		id=0;
		for(auto now:s){
			auto nowqj=*(now.s.begin());
			int l=nowqj.l,r=nowqj.r;
			bool type=nowqj.type;
			write(l);
			putchar(' ');
			now.s.erase(now.s.begin());
			if(l<r)now.s.insert(qj{l+1,r,type});
			if(!now.s.empty())Next[++id]=now;
		}
		s.clear();
		if(!id)return 0;
		solver tmp=Next[1];
		for(int i=2;i<=id;++i){
			if(tmp.type==Next[i].type){
				if(tmp.s.size()<Next[i].s.size())swap(tmp,Next[i]);
				for(auto now:Next[i].s)tmp.s.insert(now);
				tmp.l=min(tmp.l,Next[i].l);
			}
			else{
				s.insert(tmp);
				tmp=Next[i];
			}
		}
		s.insert(tmp);
		putchar('\n');
	}
	return 0;
}