#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<char>deck;
char response[]="DK";
struct card{
	char type;
	bool usd;
};
struct player{
	int type,hp;
	bool covered,inf_att,attacked,dead;
	int impression[15];
	vector<card>hand;	
	player(){
		hp=4;
		covered=true;
	}
	void reset(){
		attacked=false;
	}
	void draw(){
		hand.push_back(card{deck.front(),false});	
		if(deck.size()>1)deck.pop();
	}
	void remake(){
		hand.clear();
		inf_att=false;
	}
}pig[15];
int dis(int x,int y){
	int cnt=0;
	for(int i=1;;++i){
		int now=x+i;
		if(now>n)now-=n;
		if(!pig[now].dead)++cnt;
		if(now==y)return cnt;
	}
}
bool attack_MP(int now){
	return dis(now,1)<=1;
}
int find_K_target(int now){
	if(pig[now].type==0||pig[now].type==1){
		for(int i=1;i<n;++i){
			int t=i+now;
			if(t>n)t-=n;
			if(pig[t].dead)continue;
			if(pig[now].impression[t]==2&&dis(now,t)<=1)return t;
		}
		return 0;
	}
	else{
		if(attack_MP(now))return 1;
		else{
			for(int i=1;i<n;++i){
				int t=i+now;
				if(t>n)t-=n;
				if(pig[t].dead)continue;
				if(pig[now].impression[t]==1&&dis(now,t)<=1)return t;
			}
		}
		return 0;
	}
}
int find_F_target(int now){
	if(pig[now].type==0||pig[now].type==1){
		for(int i=1;i<n;++i){
			int t=i+now;
			if(t>n)t-=n;
			if(pig[t].dead)continue;
			if(pig[now].impression[t]==2)return t;
		}
		return 0;
	}
	else return 1;
}
void Kill(int x,int y){
	if(pig[y].type==1){
		if(x==1)pig[x].remake();
	}
	else{
		for(int i=1;i<=3;++i)pig[x].draw();
	}
}
void death(int now){
	for(int i=0;i<pig[now].hand.size();++i){
		if(pig[now].hand[i].usd)continue;
		if(pig[now].hand[i].type=='P'){
			++pig[now].hp;
			pig[now].hand[i].usd=true;
			return;
		}
	}
	pig[now].dead=true;
}
void print(){
	for(int i=1;i<=n;++i){
		if(pig[i].dead)cout<<"DEAD\n";
		else{
			for(auto now:pig[i].hand){
				if(!now.usd)cout<<now.type<<" ";
			}
			cout<<"\n";
		}
	}
//	while(!deck.empty()){
//		cout<<deck.front()<<" ";
//		deck.pop();
//	}
//	cout<<deck.size()<<"\n";
	exit(0);
}
void conclude(){
	if(pig[1].dead){
		cout<<"FP\n";
		print();
	}
	else{
		for(int i=1;i<=n;++i){
			if(pig[i].type==2&&!pig[i].dead)return;
		}
		cout<<"MP\n";
		print();
	}
}
void attack(int x,int y){
	for(int i=0;i<pig[y].hand.size();++i){
		if(pig[y].hand[i].usd)continue;
		if(pig[y].hand[i].type=='D'){
			pig[y].hand[i].usd=true;
			return;
		}
	}
	--pig[y].hp;
	if(pig[y].hp==0)death(y);
	conclude();
	if(pig[y].dead)Kill(x,y);
}
void discard_K(int now,int num){
	if(!num)return;
	for(int i=0;i<pig[now].hand.size();++i){
		if(!pig[now].hand[i].usd&&pig[now].hand[i].type=='K'){
			--num;
			pig[now].hand[i].usd=true;
			if(!num)return;
		}
	}
}
void uncover(int now){
	if(!pig[now].covered)return;
	pig[now].covered=false;
	for(int i=1;i<=n;++i)pig[i].impression[now]=max(1,pig[now].type);
}
bool blocked(int from,int to,int type){
	for(int i=0;i<n;++i){
		int t=from+i;
		if(t>n)t-=n;
		if(pig[t].dead)continue;
		bool ky=false;
		if(type==0){
			if(pig[t].impression[to]==pig[t].type)ky=true;
		}else{
			if(pig[t].impression[from]!=pig[t].type)ky=true;
		}
		if(!ky)continue;
		for(int j=0;j<pig[t].hand.size();++j){
			if(pig[t].hand[j].usd)continue;
			if(pig[t].hand[j].type=='J'){
				pig[t].hand[j].usd=ky=true;
				uncover(t);
				return blocked(t,from,1)?false:true;
			}
		}
	}
	return false;
}
void solo(int x,int y){
	if(blocked(x,y,0))return;
	int cntx=0,cnty=0;
	for(auto now:pig[x].hand){
		if(!now.usd&&now.type=='K')++cntx;
	}
	for(auto now:pig[y].hand){
		if(!now.usd&&now.type=='K')++cnty;
	}
	if(cntx>=cnty||pig[y].impression[x]==pig[y].type){
		if(pig[y].impression[x]!=pig[y].type){
			discard_K(x,cnty);
			discard_K(y,cnty);
		}
		--pig[y].hp;
		if(pig[y].hp==0)death(y);
		conclude();
		if(pig[y].dead)Kill(x,y);
	}
	else{
		discard_K(x,cntx);
		discard_K(y,cntx+1);
		--pig[x].hp;
		if(pig[x].hp==0)death(x);
		conclude();
		if(pig[x].dead)Kill(y,x);
	}
}
void aoe(int type,int now){
	for(int i=1;i<n;++i){
		int t=i+now;
		if(t>n)t-=n;
		if(pig[t].dead||blocked(now,t,0))continue;
		bool ky=false;
		for(int j=0;j<pig[t].hand.size();++j){
			if(pig[t].hand[j].usd)continue;
			if(pig[t].hand[j].type==response[type]){
				pig[t].hand[j].usd=true;
				ky=true;
				break;
			}
		}
		if(!ky){
			--pig[t].hp;
			if(pig[t].hp==0)death(t);
			conclude();
			if(pig[t].dead)Kill(now,t);
			if(t==1&&pig[now].covered)pig[1].impression[now]=2;
		}
	}
}


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		string type;
		cin>>type;
		if(type=="MP")pig[i].type=1;
		else if(type=="ZP")pig[i].type=1;
		else pig[i].type=2;
		for(int j=1;j<=4;++j){
			char t;
			cin>>t;
			pig[i].hand.push_back(card{t,false});
		}
	}
	for(int i=1;i<=m;++i){
		char t;
		cin>>t;
		deck.push(t);
	}
	uncover(1);
	int now=0;
	while(1){
		++now;
		if(now>n)now-=n;
		if(pig[now].dead)continue;
		for(int i=1;i<=2;++i)pig[now].draw();
		while(!pig[now].dead){
			bool chu=false;
			for(int i=0;i<pig[now].hand.size();++i){
				if(pig[now].hand[i].usd)continue;
				if(pig[now].hand[i].type=='P'){
					if(pig[now].hp<4){
						pig[now].hand[i].usd=true;
						++pig[now].hp;
						chu=true;
					}
				}else if(pig[now].hand[i].type=='K'){
					if(pig[now].attacked)continue;
					int to=find_K_target(now);
					if(!to)continue;
					pig[now].hand[i].usd=true;
					chu=true;
					uncover(now);
					attack(now,to);
					if(!pig[now].inf_att)pig[now].attacked=true;
				}else if(pig[now].hand[i].type=='D'||pig[now].hand[i].type=='J'){
					continue;
				}else if(pig[now].hand[i].type=='Z'){
					pig[now].hand[i].usd=true;
					pig[now].attacked=false;
					chu=true;
					pig[now].inf_att=true;
					pig[now].hand[i].usd=true;
					i=-1;
				}else if(pig[now].hand[i].type=='F'){
					int to=find_F_target(now);
					if(!to)continue;
					pig[now].hand[i].usd=true;
					chu=true;
					uncover(now);
					solo(now,to);					
				}else{
					pig[now].hand[i].usd=true;
					chu=true;
					aoe(pig[now].hand[i].type=='W'?0:1,now);
				}
				if(chu)break;
			}
			if(!chu)break;
		}
		pig[now].reset();
	}
	return 0;
}