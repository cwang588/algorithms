#include<bits/stdc++.h>
using namespace std;
int a[16];
bool usd[15];
char s[100005];
set<int>ans;
int calc(int n){
	stack<char>op;
	stack<int>num;
	for(int i=1;i<=n;++i){
		if(s[i]>='0'&&s[i]<='9'){
			int now=s[i]-'0';
			++i;
			while(s[i]>='0'&&s[i]<='9'){
				now=now*10+s[i]-'0';
				++i;
			}
			--i;
			num.push(now);
		}
		else{
			if(s[i]=='*'){
				while(!op.empty()&&op.top()=='*'){
					int now1=num.top(),now2;
					num.pop();
					now2=num.top();
					num.pop();
					num.push(now1*now2);
					op.pop();
				}
				op.push('*');
			}
			else{
				while(!op.empty()){
					int now2=num.top(),now1;
					num.pop();
					now1=num.top();
					num.pop();
					if(op.top()=='+')num.push(now1+now2);
					else if(op.top()=='-')num.push(now1-now2);
					else num.push(now1*now2);
					op.pop();
				}
				op.push(s[i]);
			}
		}
	}
	while(!op.empty()){
		int now2=num.top(),now1;
		num.pop();
		now1=num.top();
		num.pop();
		if(op.top()=='+')num.push(now1+now2);
		else if(op.top()=='-')num.push(now1-now2);
		else num.push(now1*now2);
		op.pop();
	}
	return num.top();
}
void dfs(int now,int cnt){
	if(cnt==4){
		bool ky=false;
		for(int i=1;i<=now;++i){
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
				ky=true;
				break;
			}
		}
		if(!ky)return;
		int num=calc(now);
		if(num>=0){
			ans.insert(num);
	//		for(int i=1;i<=now;++i)cout<<s[i];
	//		cout<<"="<<num<<endl;
		}
		return;
	}
	if(s[now]>='0'&&s[now]<='9'){
		s[now+1]='+';
		dfs(now+1,cnt);
		s[now+1]=0;
		s[now+1]='-';
		dfs(now+1,cnt);
		s[now+1]=0;
		s[now+1]='*';
		dfs(now+1,cnt);
		s[now+1]=0;
	}
	for(int i=1;i<=4;++i){
		if(!usd[i]){
			s[now+1]='0'+a[i];
			usd[i]=true;
			dfs(now+1,cnt+1);
			s[now+1]=0;
			usd[i]=false;
		}
	}
}
int main(){
	for(int i=1;i<=4;++i)cin>>a[i];
	dfs(0,0);
	cout<<ans.size()<<endl;
	return 0;
}
