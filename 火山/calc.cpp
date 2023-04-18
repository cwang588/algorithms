//2018.01.23 04:00:00.0+291=2018.01.23 04:04:51.0
#include<bits/stdc++.h>
const double e=7.265803404152e-3;
const double eps=1e-12;
const double GM=3.986005e14;
const double sqrtA=5.153672639847e3;
const double delta_n=4.631978654789e-9;
const double M_0=4.868047425601e-1;
const double omega=6.180119852398e-1;
const double C_uc=-1.842156052589e-6;
const double C_us=4.503875970840e-6;
const double C_rc=2.959687500000e2;
const double C_rs=-3.468750000000e1;
const double C_ic=8.009374141693e-8;
const double C_is=1.024454832077e-7;
const double i_0=9.701109867537e-1;
const double i_dot=-9.714690370133e-11;
const double OMEGA_0=-4.923911132206e-1;
const double omega_e=7.292115147e-5;
const double OMEGA_dot=-8.381777706114e-9;
const double toe=187200;
const double t=187491;
using namespace std;
//vector<string>data;
//double GetNum(int line,int rank){
//	int e_cnt=0;
//	string now=data[line];
//	double num1=0.0,num2=0.0;
//	for(int i=4+19*(rank-1);i<=19*rank-1;++i)
//}
int main(){
//	freopen("brdm0230.18p","r",stdin);
//	string tmp;
//	while(getline(cin,tmp))data.push_back(tmp);
	double n_0=sqrt(GM)/(sqrtA*sqrtA*sqrtA);
	double n=n_0+delta_n;
	cout<<"n=";
	printf("%.13lf\n",n);
	double M_t=M_0+n*291;
	cout<<"M(t)=";
	printf("%.13lf\n",M_t);
	double E_t=0.0,E_tmp=0.0;
	do{
		E_t=E_tmp;
		E_tmp=M_t+e*sin(E_t);
	}while(abs(E_t-E_tmp)>eps);
	cout<<"E(t)=";
	printf("%.13lf\n",E_t);
	double f_t;
	f_t=atan(sqrt(1.0-e*e)*sin(E_t)/(cos(E_t)-e));
	cout<<"f(t)="<<f_t<<endl;
	printf("%.13lf\n",f_t);
	double uu_t=omega+f_t;
	cout<<"u'(t)=";
	printf("%.13lf\n",uu_t);
	double rr_t=sqrtA*sqrtA*(1.0-e*cos(E_t));
	cout<<"r'(t)=";
	printf("%.13lf\n",rr_t);
	double delta_u_t=C_uc*cos(2.0*uu_t)+C_us*sin(2.0*uu_t);
	double delta_r_t=C_rc*cos(2.0*uu_t)+C_rs*sin(2.0*uu_t);
	double delta_i_t=C_ic*cos(2.0*uu_t)+C_is*sin(2.0*uu_t);
	cout<<"��u(t)=";
	printf("%.13lf\n",delta_u_t);
	cout<<"��r(t)=";
	printf("%.13lf\n",delta_r_t);
	cout<<"��i(t)=";
	printf("%.13lf\n",delta_i_t);
	double u_t=uu_t+delta_u_t;
	double r_t=rr_t+delta_r_t;
	double i_t=i_0+i_dot*291.0+delta_i_t;
	cout<<"u(t)=";
	printf("%.13lf\n",u_t);
	cout<<"r(t)=";
	printf("%.13lf\n",r_t);
	cout<<"i(t)=";
	printf("%.13lf\n",i_t);
	double x_t=r_t*cos(u_t);
	double y_t=r_t*sin(u_t);
	cout<<"x(t)=";
	printf("%.13lf\n",x_t); 
	cout<<"y(t)=";
	printf("%.13lf\n",y_t);
	double L_t=OMEGA_0+(OMEGA_dot-omega_e)*t-OMEGA_dot*toe;
	cout<<"L(t)=";
	printf("%.13lf\n",L_t);
	double X=x_t*cos(L_t)-y_t*cos(i_t)*sin(L_t); 
	double Y=x_t*sin(L_t)+y_t*cos(i_t)*cos(L_t); 
	double Z=y_t*sin(i_t); 
	cout<<"���꣺"<<endl;
	cout<<"X=";
	printf("%.13lf\n",X);
	cout<<"Y=";
	printf("%.13lf\n",Y);
	cout<<"Z=";
	printf("%.13lf\n",Z);
	return 0;
}
