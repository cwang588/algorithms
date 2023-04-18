#include<bits/stdc++.h>
using namespace std;
map<long long,bool>usd;
map<long long,long long>last;
int main(){
	long long a=997,b=120;
	queue<long long>q;
	usd[a]=true;
	q.push(a);
	while(!q.empty()){
		long long now=q.front();
		if(now==b)break;
		q.pop();
		if(now%2==0){
			if(!usd[now/2]){
				usd[now/2]=true;
				last[now/2]=now;
				q.push(now/2);
			}
		}
		if(!usd[now+1]){
			usd[now+1]=true;
			last[now+1]=now;
			q.push(now+1);
		}
		if(!usd[now*2]){
			usd[now*2]=true;
			last[now*2]=now;
			q.push(now*2);
		}
	}
	long long tmp=b;
	while(tmp!=a){
		cout<<last[tmp]<<"\n";
		tmp=last[tmp];
	}
	return 0;
}