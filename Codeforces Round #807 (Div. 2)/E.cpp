#include<bits/stdc++.h>
using namespace std;
const int N=2e5+30;
int a[200005],sum[200105];
struct qj{
	int l,r,x;
	bool operator <(const qj& b)const{
		if(l!=b.l)return l<b.l;
		if(r!=b.r)return r<b.r;
		return x<b.x;
	}
};
set<qj>s;
void add(int pos){
	auto it=upper_bound(s.begin(),s.end(),qj{pos,pos,0});
	if(it->l>pos)--it;
	if((it->x)==0){
		int tl=it->l,tr=it->r;
		if(tl==tr){
			if(it!=s.begin()){
				--it;
				tl=it->l;
				auto pre=it;
				++it;
				s.erase(pre);
			}
			++it;
			if(it!=s.end()){
				tr=it->r;
				auto nxt=it;
				--it;
				s.erase(nxt);
			}
			s.erase(it);
			s.insert(qj{tl,tr,1});
		}
		else{
			if(tl==pos){
				int nowl=tl,nowr=pos;
				if(it!=s.begin()){
					--it;
					nowl=it->l;
					auto pre=it;
					++it;
					s.erase(pre);
				}
				s.insert(qj{nowl,nowr,1});
				s.erase(it);
				s.insert(qj{pos+1,tr,0});
			}
			else if(tr==pos){
				int nowl=tl,nowr=pos;
				++it;
				if(it!=s.end()){
					nowr=it->r;
					auto nxt=it;
					--it;
					s.erase(nxt);
				}
				s.insert(qj{nowl,nowr,1});
				s.erase(it);
				s.insert(qj{tl,pos-1,0});
			}
			else{
				s.erase(it);
				s.insert(qj{tl,pos-1,0});
				s.insert(qj{pos+1,tr,0});
				s.insert(qj{pos,pos,1});
			}
		}
	}
	else{
		int tl=it->l,tr=it->r;
		++it;
		auto nxt=it;
		int nowl=it->l,nowr=it->r;
		--it;
		s.erase(nxt);
		if(nowl<nowr)s.insert(qj{nowl+1,nowr,0});
		s.insert(qj{nowl,nowl,1});
		auto now=s.find(qj{nowl,nowl,1});
		++now;
		if(now!=s.end()&&now->x==1){
			auto tmp=now;
			--now;
			int tmpl=nowl,tmpr=tmp->r;
			s.erase(tmp);
			s.erase(now);
			s.insert(qj{tmpl,tmpr,1});
		}
		nowr=nowl-1;
		nowl=pos;
		s.erase(it);
		s.insert(qj{tl,pos-1,1});
		s.insert(qj{nowl,nowr,0});
	}
}
void sub(int pos){
	auto it=upper_bound(s.begin(),s.end(),qj{pos,pos,0});
	if(it->l>pos)--it;
	if((it->x)==1){
		int tl=it->l,tr=it->r;
		if(tl==tr){
			if(it!=s.begin()){
				--it;
				tl=it->l;
				auto pre=it;
				++it;
				s.erase(pre);
			}
			++it;
			if(it!=s.end()){
				tr=it->r;
				auto nxt=it;
				--it;
				s.erase(nxt);
			}
			s.erase(it);
			s.insert(qj{tl,tr,0});
		}
		else{
			if(tl==pos){
				int nowl=tl,nowr=pos;
				if(it!=s.begin()){
					--it;
					nowl=it->l;
					auto pre=it;
					++it;
					s.erase(pre);
				}
				s.insert(qj{nowl,nowr,0});
				s.erase(it);
				s.insert(qj{pos+1,tr,1});
			}
			else if(tr==pos){
				int nowl=tl,nowr=pos;
				++it;
				if(it!=s.end()){
					nowr=it->r;
					auto nxt=it;
					--it;
					s.erase(nxt);
				}
				s.insert(qj{nowl,nowr,0});
				s.erase(it);
				s.insert(qj{tl,pos-1,1});
			}
			else{
				s.erase(it);
				s.insert(qj{tl,pos-1,1});
				s.insert(qj{pos+1,tr,1});
				s.insert(qj{pos,pos,0});
			}
		}
	}
	else{
		int tl=it->l,tr=it->r;
		++it;
		auto nxt=it;
		int nowl=it->l,nowr=it->r;
		--it;
		s.erase(nxt);
		if(nowl<nowr)s.insert(qj{nowl+1,nowr,1});
		s.insert(qj{nowl,nowl,0});
		auto now=s.find(qj{nowl,nowl,0});
		++now;
		if(now!=s.end()&&now->x==0){
			auto tmp=now;
			--now;
			int tmpl=nowl,tmpr=tmp->r;
			s.erase(tmp);
			s.erase(now);
			s.insert(qj{tmpl,tmpr,0});
		}
		nowr=nowl-1;
		nowl=pos;
		s.erase(it);
		s.insert(qj{tl,pos-1,0});
		s.insert(qj{nowl,nowr,1});
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++sum[a[i]];
	}
	for(int i=1;i<N;++i){
		sum[i+1]+=sum[i]/2;
		sum[i]%=2;
	}
	int last=1;
	for(int i=2;i<=N;++i){
		if(sum[i]!=sum[i-1]){
			s.insert(qj{last,i-1,sum[i-1]});
			last=i;
		}
	}
	s.insert(qj{last,N,sum[N]});
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		add(y);
		sub(a[x]);
		a[x]=y;
		auto it=s.rbegin();
		if((it->x)==0)--it;
		cout<<it->r<<"\n";
	}
	return 0;
}