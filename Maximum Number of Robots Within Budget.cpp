#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int m,vector<pair<int,int> >&a,long long tot){
        int n=a.size();
        long long sum=0;
        deque<int>q;
        for(int i=0;i<n;++i){
        	if(i-m>=0)sum-=a[i-m].second;
            if(!q.empty()&&q.front()==i-m){
                q.pop_front();
            }
            while(!q.empty()&&a[q.back()].first<=a[i].first)q.pop_back();
            q.push_back(i);
            sum+=a[i].second;
            if(i>=m-1&&sum*m+a[q.front()].first<=tot)return true;
        }
        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        vector<pair<int,int> >a;
        for(int i=0;i<n;++i)a.push_back(make_pair(chargeTimes[i],runningCosts[i]));
        int l=0,r=n+1;
        while(l<r-1){
            int m=(l+r)>>1;
            if(check(m,a,budget))l=m;
            else r=m;
        }
        return l;
    }
};
int main(){
	Solution s;
	vector<int>a={8,76,74,9,75,71,71,42,15,58,88,38,56,59,10,11},b={1,92,41,63,22,37,37,8,68,97,39,59,45,50,29,37};
	cout<<s.maximumRobots(a,b,412);
	return 0;
}