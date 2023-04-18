#include<bits/stdc++.h>
#define lson l,m,rt<<1  //ʡ��ʡʱ��
#define rson m+1,r,rt<<1|1
using namespace std;
long long z[1000005<<2|1],sum[1000005<<2|1],add[1000005<<2|1],mul[1000005<<2|1]; //һ��Ҫ����4�� ��Ȼ���ܱ�
long long n,m,a,p;
void update(int rt)//rt��ʾ��ǰ�Ľڵ�
{
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p; //sum��ʾ�߶����ýڵ㣨��ʾһ�����䣩�ĺͣ�������Ӻ��Ҷ������
    return;//�����м���̱�int �������б�������long long Ȼ����ʱȡ%
} 
void color(int l,int r,int rt,int x,int y)  //��Ǹ��� ����ÿһ�ζ����ɰ�������������� *a + b����aȻ�����b��
{                                                     //��ӷ�ʱ y���1  ����˷�ʱ x=0
    sum[rt] = ((sum[rt]*y)+(1ll*(r-l+1)*x))%p; //����sum 
    mul[rt] = (mul[rt]*y)%p; //���³˷����
    add[rt] = (add[rt]*y+x)%p;//���¼ӷ���� �����˳���
    return;
} 
void push_col(int l,int r,int rt)//�·ű�� rt��ʾ��ǰ�Ľڵ�
{
    if(mul[rt]!=1 || add[rt]!=0)//�ж��Ƿ��б��
    {
        int m=(l+r)>>1;//��һ�� �߶���˼��
        color(lson,add[rt],mul[rt]); //���˵Ŀ�������define
        color(rson,add[rt],mul[rt]);
        add[rt]=0; //�·����Ǻ� �ָ���ʼ״̬
        mul[rt]=1; 
    } 
    return;
} 
void build(int l,int r,int rt)//���� ǧ��ע���ʼ��Ӧ����if������ ����һ�����Ͼ���Ϊ���
{
    mul[rt]=1; 
    add[rt]=0;
    if(l==r)
    { 
        sum[rt] = z[l];//������Ľڵ�=z[���������˵�] �����Ŀ��Ի�һ��ͼ���� z��������main ������
        return;
    }
    int m = (l+r)>>1;//(l+r)/2 
    build(lson);//�ݹ齨��
    build(rson);
    update(rt); //���������sum
} 
void modify(int l,int r,int rt,int nowl,int nowr,int x,int y) //�޸ĺ��� nowl �� nowr����Ҫ�޸ĵ����� x,y ͬ��
{ 
    if(nowl<=l && r<=nowr)//������ǵĻ� �Ϳ���ȫ��ȡ�� �����޸�˼��
    {
        color(l,r,rt,x,y); 
        return; 
    } 
    if(mul[rt]!=1 || add[rt]!=0) //�·�
        push_col(l,r,rt); 
    int m=(l+r)>>1;
    if(nowl<=m) //��������н��� ���������
        modify(lson,nowl,nowr,x,y);
    if(m<nowr) //���Ҷ����н��� ���Ҷ�����
        modify(rson,nowl,nowr,x,y); 
    update(rt);//����
} 
long long query(int l,int r,int rt,int nowl,int nowr)//��ѯ����
{
    if(nowl<=l && r<=nowr)//���Ǿͷ���
    {
        return (sum[rt])%p; 
    }
    if(mul[rt]!=1 || add[rt]!=0) //�б�ǵĻ���Ҫ�·� ����õ����û�и��¹���
        push_col(l,r,rt);
    int m=(l+r)>>1;
    long long ans = 0;//��long long ��ֹ��
    if(nowl<=m) ans+=query(lson,nowl,nowr)%p;//�ܺ���� �ҵ��˾ͼ��� %pΪ�˷���
    if(m<nowr) ans+=query(rson,nowl,nowr)%p;
    return ans%p; 
} 
int main()
{
    long long x,y,k;
    scanf("%lld %lld %lld",&n,&m,&p);//���� n m p
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&z[i]); //��������
    } 
    build(1,n,1);//����
    for(int i=1;i<=m;i++)//while(m--) Ҳһ��
    { 
        scanf("%d",&a);//�� case Ҳ��
        if(a==1)//�˷� 
        { 
            scanf("%lld %lld %lld",&x,&y,&k);
            modify(1,n,1,x,y,0,k); //�ӷ��� ��0
        } 
        if(a==2)//�ӷ� 
        {
            scanf("%lld %lld %lld",&x,&y,&k);
            modify(1,n,1,x,y,k,1);//�˷��� ��1������
        } 
        if(a==3)
        {
            scanf("%lld %lld",&x,&y); 
            printf("%lld\n",(query(1,n,1,x,y))%p);//��ѯ ���
        } 
    } 
    return 0; 
} 
