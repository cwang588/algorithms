#include<cstdio>

typedef long long LL;
LL n,mo,l,r,u,v,ans;
int q;
LL max(LL x,LL y)
{
	return x>y?x:y;
}
LL min(LL x,LL y)
{
	return x<y?x:y;
}
int main()
{
	scanf("%lld%d%lld",&n,&q,&mo);
	LL mid=n-n/2;
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld%lld",&l,&r,&u,&v);
		if(r<=mid)
		{
			if(u%2==0) u++;
			if(v%2==0) v--;
			LL ll=max(u,2*l-1);
			LL rr=min(v,2*r-1);
			if(rr<ll) ans=0;
			else ans=((rr-ll+2)/2%mo*((ll+rr)/2%mo))%mo;
		}
		else if(l>mid)
		{
			if(u%2) u++;
			if(v%2) v--;
			LL ll=max(u,2*(l-mid));
			LL rr=min(v,2*(r-mid));
			if(rr<ll) ans=0;
			else ans=((rr-ll+2)/2%mo*((ll+rr)/2%mo))%mo;
		}
		else
		{
			LL uu=u,vv=v;
			if(u%2==0) uu++;
			if(v%2==0) vv--;
			LL ll=max(uu,2*l-1);
			LL rr=min(vv,n);
			if(rr<ll) ans=0;
			else ans=((rr-ll+2)/2%mo*((ll+rr)/2%mo))%mo;
			uu=u,vv=v;
			if(u%2) uu=u+1;
			if(v%2) vv=v-1;
			ll=max(uu,2);
			rr=min(vv,2*(r-mid));
			if(rr>=ll) ans+=((rr-ll+2)/2%mo*((ll+rr)/2%mo))%mo;
			ans%=mo;
		}
		printf("%lld\n",ans%mo);
	}
	return 0;
} 

