#include<bits/stdc++.h>
using namespace std;
struct point{
	int a,id;
}p[5];
bool cmp(point x,point y){
	return x.a>y.a;
}
char s[3][2005];
void print(int x,int n){
	for(int i=1;i<=n;++i)cout<<s[x][i];
	cout<<endl;
}
int main(){
	for(int i=1;i<=3;++i){
		cin>>p[i].a;
		p[i].id=i;
	}
	sort(p+1,p+1+3,cmp);
	int n;
	cin>>n;
	if(n-p[1].a<p[2].a-p[3].a)return !printf("NO\n");
	for(int i=1;i<=p[1].a;++i)s[1][i]=s[2][i]='a';
	for(int i=p[1].a+1;i<=n;++i)s[1][i]='c',s[2][i]='d';
	for(int i=1;i<=p[3].a;++i)s[3][i]='a';
	for(int i=p[3].a+1;i<=p[1].a;++i)s[3][i]='b';
	for(int i=1;i<=p[2].a-p[3].a;++i)s[3][p[1].a+i]='c';
	for(int i=p[1].a+p[2].a-p[3].a+1;i<=n;++i)s[3][i]='e';
	if(p[1].id==1){
		if(p[2].id==2){
			print(2,n);
			print(1,n);
			print(3,n);
		}
		else{
			print(1,n);
			print(2,n);
			print(3,n);
		}
	}
	else if(p[1].id==2){
		if(p[2].id==1){
			print(3,n);
			print(1,n);
			print(2,n);
		}
		else{
			print(3,n);
			print(2,n);
			print(1,n);
		}
	}
	else{
		if(p[2].id==1){
			print(1,n);
			print(3,n);
			print(2,n);
		}
		else{
			print(2,n);
			print(3,n);
			print(1,n);
		}
	}
	return 0;
}
