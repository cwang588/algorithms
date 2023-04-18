#include<bits/stdc++.h>
using namespace std;
int m,n,k;
bool usd[1005][1005];
int a[1005][1005];
int mov[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int> >q[1002];
bool check(int mid){
    memset(usd,0,sizeof(usd));
    for(int i=0;i<=k;++i){
    	while(!q[i].empty())q[i].pop();
	}
    for(int i=1;i<=m;++i){
        usd[1][i]=true;
        if(a[1][i]<mid)q[1].push(make_pair(1,i));
		else q[0].push(make_pair(1,i));
    }
    for(int i=0;i<=k;++i){
        while(!q[i].empty()){
            auto p=q[i].front();
            q[i].pop();
            if(p.first==n)return true;
            for(int j=0;j<4;++j){
                int tox=p.first+mov[j][0],toy=p.second+mov[j][1];
                if(tox<1||toy<1||tox>n||toy>m||usd[tox][toy])continue;
            	usd[tox][toy]=true;
                if(a[tox][toy]<mid)q[i+1].push(make_pair(tox,toy));
				else q[i].push(make_pair(tox,toy));
            }
        }
    }
    return false;
}


int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    int l=0,r=1000000008;
    while(l<r-1){
        int mid=(l+r)>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}

