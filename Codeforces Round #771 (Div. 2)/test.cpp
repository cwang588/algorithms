#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct p{
        int x,y;
    };
    static bool cmp(p a,p b){
        if(a.x!=b.x)return a.x<b.x;
        return a.y<b.y;
    }
    long long sum[2][1005];
    int lowbit(int x){
        return x&(-x);
    }
    void add(int pos,long long value,int id){
        while(pos<=1000){
            sum[id][pos]+=value;
            pos+=lowbit(pos);
        }
    }
    long long query(int pos,int id){
        long long re=0;
        while(pos){
            re+=sum[id][pos];
            pos-=lowbit(pos);
        }
        return re;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        p a[1005];
        int to[1005];
        memset(sum,0,sizeof(sum));
        int n=nums1.size();
        for(int i=0;i<n;++i)to[nums1[i]+1]=i+1;
        for(int i=0;i<n;++i){
            a[i+1]={to[nums1[i]+1],to[nums2[i]+1]};
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;++i)cout<<a[i].y<<" ";
        long long ans=0;
        for(int i=1;i<=n;++i){
            long long tmp1=query(a[i].y-1,0);
			long long tmp2=query(a[i].y-1,1);
            ans+=tmp2;
            add(a[i].y,1,0);
            add(a[i].y,tmp1,1);
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int>v1={13,14,10,2,12,3,9,11,15,8,4,7,0,6,5,1},v2={8,7,9,5,6,14,15,10,2,11,4,13,3,12,1,0};
	cout<<s.goodTriplets(v1,v2);
	return 0;
}