#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
void vivod(double b[6][6]){
	b[1][1]=b[2][2]=b[3][3]=b[4][4]=1;
	b[1][2]=b[1][3]=b[1][4]=b[2][1]=b[2][3]=b[2][4]=b[3][1]=b[3][2]=b[3][4]=b[4][1]=b[4][2]=b[4][3]=0;
	b[1][5]=1731843486232083./1866786334290398;
	b[2][5]=1633119019791586./28001179501435597;
	b[3][5]=-5443150834192259./119474325394585470;
	b[4][5]=-346659578248979./12246003219848316;
	
}
double p(double x){
	return x/=10;}
double o(double x){
	return x/=2;}
int main(){
	setlocale(LC_ALL, "rus");
double x[5],y[5];
x[0]=0;x[1]=1;x[2]=3;x[3]=5;x[4]=7;
y[0]=-1;y[1]=2;y[2]=3;y[3]=-2;y[4]=0;
cout<<"в даном случае n=4, значит L4(x)=sum(y1*pr(x-xj/xi-xj)):"<<endl;
int l=0;
/*for(int i=0;i<=4;i++){
	for(int j=0;j<=4;j++){

	}
}*/
double t[7][7],mi[7][7];
double r[6]={-0.5,0.5,1.5,3.5,5.5,7.5};
	cout<<"Ћј√–јЌ∆\n";
	cout<<"— помощью y координат запишем полином:\n";
	cout<<"L(x)=-l0(x)+2l1(x)+3l2(x)-2l3(x)\n";
	cout<<"------\n";
	cout<<"— помощью х координат запишем полином:\n";
	cout<<"l0(x)=(x-1)(x-3)(x-5)(x-7)/(0-1)(0-3)(0-5)(0-7)\n";
	cout<<"l1(x)=(x-0)(x-3)(x-5)(x-7)/(1-0)(1-3)(1-5)(1-7)\n";
	cout<<"l2(x)=(x-0)(x-1)(x-5)(x-7)/(3-0)(3-1)(3-5)(3-7)\n";
	cout<<"l3(x)=(x-0)(x-1)(x-3)(x-7)/(5-0)(5-1)(5-3)(5-7)\n";
	cout<<"------\n";
	cout<<"l0(x)=x^4-16x^3+86x^2-176x+105/105\n";
	cout<<"l1(x)=+x^4-15x^3+71x^2-105x/-48\n";
	cout<<"l2(x)=x^4-13x^3+47x^2-35x/48\n";
	cout<<"l3(x)=x^4-11x^3+31x^2-21x/-80\n";
	cout<<"------\n";
	cout<<"l0(x1/105x^4 - 16/105x^3 + 86/105x^2 - 176/105x +1\n";
	cout<<"l1(x)=-1/48x^4 + 5/16x^3 - 71/48x^2 + 35/16x\n";
	cout<<"l2(x)=1/48x^4 - 13/48x^3 + 47/48x^2 - 35/48x\n";
	cout<<"l3(x)=-1/80x^4 + 11/80x^3 - 31/80x^2 +21/80x\n";
	cout<<"------\n";
	cout<<"L(x)=-(1/105x^4 - 16/105x^3 + 86/105x^2 - 176/105x +1)+2(-1/48x^4 + 5/16x^3 - 71/48x^2 + 35/16x)+3(1/48x^4 - 13/48x^3 + 47/48x^2 - 35/48x)-2(-1/80x^4 + 11/80x^3 - 31/80x^2 +21/80x)\n";
	cout<<"L(x)=61/1680x^4 - 521/1680x^3 - 109/1680x^2 + 5609/1680x -1\n";
	cout<<"L(x)="<<61./1680<<"x^4+"<<(-521./1680)<<"x^3+"<<(-109./1680)<<"x^2+"<< 5609./1680 <<"x+"<< -1<<endl;
	cout<<"Ќ№ё“ќЌ\n";
	cout<<"P(x)=f(x0)+f(x0,x1)(x-x0)+f(x0,x1,x2)(x-x0)(x-x1)+f(x0,x1,x2,x3)(x-x0)(x-x1)(x-x2)+f(x0,x1,x2,x3,x4)(x-x0)(x-x1)(x-x2)(x-x3)\n";
	double fx0=y[0],fx0x1=(y[1]-y[0])/(x[1]-x[0]),fx1x2=(y[2]-y[1])/(x[2]-x[1]),fx2x3=(y[3]-y[2])/(x[3]-x[2]),fx3x4=(y[4]-y[3])/(x[4]-x[3]);
	double fx0x1x2=(fx1x2-fx0x1)/(x[2]-x[0]),fx1x2x3=(fx2x3-fx1x2)/(x[3]-x[1]),fx2x3x4=(fx3x4-fx2x3)/(x[4]-x[2]);
	double fx0x1x2x3=(fx1x2x3-fx0x1x2)/(x[3]-x[0]),fx1x2x3x4=(fx2x3x4-fx1x2x3)/(x[4]-x[1]);
	double fx0x1x2x3x4=(fx1x2x3x4-fx0x1x2x3)/(x[4]-x[0]);
	cout<<"f(x0)="<<fx0<<endl;
	cout<<"f(x0,x1)="<<fx0x1<<endl;
	cout<<"f(x1,x2)="<<fx1x2<<endl;
	cout<<"f(x2,x3)="<<fx2x3<<endl;
	cout<<"f(x3,x4)="<<fx3x4<<endl;
	cout<<"f(x0,x1,x2)="<<fx0x1x2<<endl;
	cout<<"f(x1,x2,x3)="<<fx1x2x3<<endl;
	cout<<"f(x2,x3,x4)="<<fx2x3x4<<endl;
	cout<<"f(x0,x1,x2,x3)="<<fx0x1x2x3<<endl;
	cout<<"f(x1,x2,x3,x4)="<<fx1x2x3x4<<endl;
	cout<<"f(x0,x1,x2,x3,x4)="<<fx0x1x2x3x4<<endl;
	cout<<"»нтерполирование вперед:\n";
	double x4,x3,x2,x1,x0;
	x0=fx0;
	x1=fx0x1-fx0x1x2+fx0x1x2x3*3+fx0x1x2x3x4*(-15);
	x2=fx0x1x2+fx0x1x2x3*(-4)+fx0x1x2x3x4*23;
	x3=fx0x1x2x3*1+fx0x1x2x3x4*(-9);
	x4=fx0x1x2x3x4;
	cout<<"P(x)="<<x4<<"x^4+"<<x3<<"x^3+"<<x2<<"x^2+"<<x1<<"x+"<<x0<<endl;
	cout<<"»нтерполирование назад:\n";
	x4=fx0x1x2x3x4;
	x3=fx1x2x3x4-16*fx0x1x2x3x4;
	x2=fx2x3x4-15*fx1x2x3x4+86*fx0x1x2x3x4;
	x1=fx3x4-12*fx2x3x4+71*fx1x2x3x4-176*fx0x1x2x3x4;
	x0=fx3x4*(-7)+35*fx2x3x4-105*fx1x2x3x4+105*fx0x1x2x3x4;
	cout<<"P(x)="<<x4<<"x^4+"<<x3<<"x^3+"<<x2<<"x^2+"<<x1<<"x+"<<x0<<endl;
	x[0]=-1;x[1]=0;x[2]=2;x[3]=3;x[4]=5;
y[0]=4;y[1]=2;y[2]=-1;y[3]=3;y[4]=1;
	cout<<"ћетод наименьших квадратов\n";
	cout<<"m=0\n";
	cout<<"Q0=a0\n";
	double q0,q1,q2,q3,q4,c0=0,a0,d0=0,m,c1=0,c2=0,d1=0,a1,a2,a3,a4,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,d2=0,d3=0,d4=0;
	m=0;
	for(int i=0;i<=4;i++){c0+=1;d0+=y[i];}
	a0=d0/c0;
	q0=a0;
	cout<<"c0="<<c0<<",d0="<<d0<<",a0="<<a0<<endl;
	cout<<"Q0="<<q0<<endl;
	cout<<"------\n";
	cout<<"m=1\n";
	cout<<"Q1=a0+a1x\n";
	for(int i=0;i<6;i++){
		t[3][i]=q0;
	}
	for(int i=0;i<=4;i++){
		mi[1][i]=a0;
	}
	m=1;
	c0=5,a0=0,d0=0,c1=0,c2=0,d1=0,a1=0,a2=0,a3=0,a4=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,d2=0,d3=0,d4=0;
	for(int i=0;i<=4;i++){
		c1+=x[i];
		if(i>=1){
		d0+=y[i];
		c2+=(x[i]*x[i]);}
		d1+=(x[i]*y[i]);}
	cout<<"{"<<c0<<"*a0+"<<c1<<"*a1="<<d0<<endl<<"{"<<c1<<"*a0+"<<c2<<"*a1="<<d1<<endl;
	double del=c1/c0;
	double c11=c1;
	c0*=del;c1*=del;d0*=del;
	cout<<"\n{"<<c0<<"*a0+"<<c1<<"*a1="<<d0<<endl<<"{"<<c11<<"*a0+"<<c2<<"*a1="<<d1<<endl;
	double w1=c0-c11,w2=c1-c2,w3=d0-d1;
	cout<<""<<w1<<"*a0+"<<w2<<"*a1="<<w3<<endl;
	a1=w3/w2;
	a0=(d1-c2*a1)/c1;
	cout<<"a0="<<a0<<",a1="<<a1<<endl;
	cout<<"Q1="<<a0<<"+"<<a1<<"x\n";
	for(int i=0;i<6;i++){
		t[4][i]=a0+a1*r[i];
	}
	for(int i=0;i<=4;i++){
		mi[2][i]=a0+a1*x[i];
	}
	cout<<"------\n";
	cout<<"m=2\n";
	cout<<"Q2=a0+a1x+a2x^2\n";
	c0=5,a0=0,d0=0,c1=0,c2=0,d1=0,a1=0,a2=0,a3=0,a4=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,d2=0,d3=0,d4=0;
	for(int i=0;i<=4;i++){
		c1+=x[i];
		c2+=(x[i]*x[i]);
		c3+=(x[i]*x[i]*x[i]);
		c4+=(x[i]*x[i]*x[i]*x[i]);
		d0+=y[i];
		d1+=(x[i]*y[i]);
		d2+=(x[i]*x[i]*y[i]);}
	cout<<"{"<<c0<<"*a0+"<<c1<<"*a1+"<<c2<<"*a2="<<d0<<endl<<"{"<<c1<<"*a0+"<<c2<<"*a1+"<<c3<<"*a2="<<d1<<"\n{"<<c2<<"*a0+"<<c3<<"*a1+"<<c4<<"*a2="<<d2<<endl;
	double c[3][4];
	c[1][1]=5;c[1][2]=67.2;c[1][3]=168;c[1][4]=11.6;
	c[2][1]=c[1][2];c[2][2]=c[1][3];c[2][3]=496;c[2][4]=2;
	c[3][1]=c[2][2];c[3][2]=c[2][3];c[3][3]=3108;c[3][4]=-21;
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(j==4){
			cout<<" | "<<c[i][j]<<"\n";
			}
			else{cout<<c[i][j]<<"\t";}
		}}
	}
	for(int i=1;i<=4;i++){
		swap(c[1][i],c[3][i]);}
	cout<<"дл€ удобства помен€ем местами:\n";
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(j==4){
			cout<<" | "<<c[i][j]<<"\n";
			}
			else{cout<<c[i][j]<<"\t";}
		}}
	}
	cout<<"умножим 2-ю строку на "<<-5/67.2<<" и добавим к 3-й:\n";
	for(int i=1;i<=4;i++){c[3][i]+=c[2][i]*(-5/67.2);}
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(j==4){
			cout<<" | "<<c[i][j]<<"\n";
			}
			else{cout<<c[i][j]<<"\t";}
		}}
	}
	cout<<"умножим 1-ю строку на "<<-67.2/168<<" и добавим ко 2-й\n";
	for(int i=1;i<=4;i++){c[2][i]+=c[1][i]*(-67.2/168);}
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(j==4){
			cout<<" | "<<c[i][j]<<"\n";
			}
			else{cout<<c[i][j]<<"\t";}
		}}
	}
	cout<<"умножим 2-ю строку на "<<-c[3][2]/c[2][2]<<" и добавим к 3-й:\n";
	for(int i=1;i<=4;i++){c[3][i]+=c[2][i]*(-c[3][2]/c[2][2]);}
	c[3][3]=-1213.373;c[3][4]=30.164;
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(j==4){
			cout<<" | "<<c[i][j]<<"\n";
			}
			else{cout<<c[i][j]<<"\t";}
		}}
	}
	
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(i==1){c[i][j]/=168;}
			if(i==2){c[i][j]/=-30.4;}
			if(i==3){c[i][j]/=-1213.373;}
		}}
	}
	{for(int i=1;i<=3;i++){
		for(int j=1;j<=4;j++){
			if(j==4){
			cout<<" | "<<c[i][j]<<"\n";
			}
			else{cout<<c[i][j]<<"\t";}
		}}
	}
	a2=c[3][4];
	a1=c[2][4]-c[2][3]*c[3][4];
	a0=c[1][4]-c[1][2]*a1-c[1][3]*a2;
	//	delete[]c;
	cout<<"a2="<<a2<<",a1="<<a1<<",a0="<<a0<<endl;;
	cout<<"Q2="<<a0<<"+"<<a1<<"x+"<<a2<<"x^2\n";
	for(int i=0;i<6;i++){
		t[5][i]=a0+a1*r[i]+a2*r[i]*r[i];
	}
	for(int i=0;i<=4;i++){
		mi[3][i]=a0+a1*x[i]+a2*x[i]*x[i];
	}
	//system("pause");
	cout<<"------\n";
	cout<<"m=3\n";
	cout<<"Q2=a0+a1x+a2x^2+a3x^3\n";
	c0=5,a0=0,d0=0,c1=0,c2=0,d1=0,a1=0,a2=0,a3=0,a4=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,d2=0,d3=0,d4=0;
	for(int i=0;i<=4;i++){
		c1+=x[i];
		c2+=(x[i]*x[i]);
		c3+=(x[i]*x[i]*x[i]);
		c4+=(x[i]*x[i]*x[i]*x[i]);
		c5+=(x[i]*x[i]*x[i]*x[i]*x[i]);
		c6+=(x[i]*x[i]*x[i]*x[i]*x[i]*x[i]);
		d0+=y[i];
		d1+=(x[i]*y[i]);
		d2+=(x[i]*x[i]*y[i]);
		d3+=(x[i]*x[i]*x[i]*y[i]);
	}
	cout<<"{"<<c0<<"*a0+"<<c1<<"*a1+"<<c2<<"*a2+"<<c3<<"a3="<<d0<<endl;
	cout<<"{"<<c1<<"*a0+"<<c2<<"*a1+"<<c3<<"*a2+"<<c4<<"a3="<<d1<<endl;
	cout<<"{"<<c2<<"*a0+"<<c3<<"*a1+"<<c4<<"*a2+"<<c5<<"a3="<<d2<<endl;
	cout<<"{"<<c3<<"*a0+"<<c4<<"*a1+"<<c5<<"*a2+"<<c6<<"a3="<<d3<<endl;
	double b[6][6];
	b[1][1]=5;b[1][2]=83.2;b[1][3]=252;b[1][4]=992;b[1][5]=13.6;
	b[2][1]=b[1][2];b[2][2]=b[1][3];b[2][3]=b[1][4];b[2][4]=6216;b[2][5]=3;
	b[3][1]=b[2][2];b[3][2]=b[2][3];b[3][3]=b[2][4];b[3][4]=20176;b[3][5]=-42;
	b[4][1]=b[3][2];b[4][2]=b[3][3];b[4][3]=b[3][4];b[4][4]=134004;b[4][5]=-167;
	cout<<"–ешим методом √аусса:\n";
	cout<<"1-ю строку делим на 5:\n";
	for(int i=1;i<=5;i++){b[1][i]/=5;}
	cout<<"от 2-й строки отнимаем 1-ю, умноженную на "<<b[2][1]<<";\nот 3-й строки отнимаем 1-ю, умноженную на "<<b[3][1]<<";\nот 4-й отнимает 1-ю, умноженную на "<<b[4][1]<<"\n";
	for(int i=1;i<=4;i++){
		for(int j=1;j<=5;j++){
			if(i==2){b[i][j]-=b[1][j]*b[2][1];}
			if(i==3){b[i][j]-=b[1][j]*b[3][1];}
			if(i==4){b[i][j]-=b[1][j]*b[4][1];}
		}}
	cout<<"2-ю строку делим на "<<b[2][2]<<"\n";
	for(int i=1;i<=5;i++){b[2][i]/=(b[2][2]);}
	cout<<"от 1-й отнимаем 2-ю, умноженную на "<<b[1][2]<<";\nк 3-й добавл€ем 2-ю, умноженную на 3201.28;\nк 4-й добавл€ем 2-ю, умноженную на 10290.88\n";
	for(int i=1;i<=4;i++){
		for(int j=1;j<=5;j++){
			if(i==1){b[i][j]-=b[2][j]*b[1][2];}
			if(i==3){b[i][j]+=b[2][j]*3201.28;}
			if(i==4){b[i][j]+=b[2][j]*10290.88;}
		}}
	cout<<"3-ю строку делим на "<<90765464./35389<<endl;
	for(int i=1;i<=5;i++){b[2][i]/=(90765464./35389);}
	cout<<"от 1-й отнимаем 3-ю, умноженную на "<<118940./35389<<";\nот 2-й отнимаем 3-ю, умноженную на "<<100040./35389<<";\nк 4 добавл€ем 3-ю, умноженную на "<<25828656./35389<<endl;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=5;j++){
			if(i==1){b[i][j]-=b[3][j]*118940./35389;}
			if(i==2){b[i][j]-=b[3][j]*100040./35389;}
			if(i==4){b[i][j]+=b[3][j]*25828656./35389;}
		}}
	vivod(b);

	{for(int i=1;i<=4;i++){
		for(int j=1;j<=5;j++){
			if(j==5){
			cout<<" | "<<b[i][j]<<"\n";
			}
			else{cout<<b[i][j]<<"\t";}
		}}
	}
	cout<<"Q3="<<b[1][5]<<"+"<<b[2][5]<<"x+"<<b[3][5]<<"x^2+"<<b[4][5]<<"x^3\n";
//	delete[]b;
	cout<<"------\n";
	for(int i=0;i<6;i++){
		t[6][i]=b[1][5]+b[2][5]*r[i]+b[3][5]*r[i]*r[i]+b[4][5]*r[i]*r[i]*r[i];
	}
	for(int i=0;i<=4;i++){
		mi[4][i]=b[1][5]+b[2][5]*x[i]+b[3][5]*x[i]*x[i]+b[4][5]*x[i]*x[i]*x[i];
	}
	cout<<"m=4\n";
	cout<<"Q4=a0+a1x+a2x^2+a3x^3+a4x^4\n";
	c0=5,a0=0,d0=0,c1=0,c2=0,d1=0,a1=0,a2=0,a3=0,a4=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,d2=0,d3=0,d4=0;
	for(int i=0;i<=4;i++){
		c1+=x[i];
		c2+=(x[i]*x[i]);
		c3+=(x[i]*x[i]*x[i]);
		c4+=(x[i]*x[i]*x[i]*x[i]);
		c5+=(x[i]*x[i]*x[i]*x[i]*x[i]);
		c6+=(x[i]*x[i]*x[i]*x[i]*x[i]*x[i]);
		c7+=(x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]);
		c8+=(x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]);
		d0+=y[i];
		d1+=(x[i]*y[i]);
		d2+=(x[i]*x[i]*y[i]);
		d3+=(x[i]*x[i]*x[i]*y[i]);
		d4+=(x[i]*x[i]*x[i]*x[i]*y[i]);
	}
	//vector<double>arr;
	//arr.push_back(c8);4
	//for(int i=0;i<arr.size();i++)cout<<arr[i];
	cout<<"{"<<c0<<"*a0+"<<c1<<"*a1+"<<c2<<"*a2+"<<c3<<"a3+"<<c4<<"a4="<<d0<<endl;
	cout<<"{"<<c1<<"*a0+"<<c2<<"*a1+"<<c3<<"*a2+"<<c4<<"a3+"<<c5<<"a4="<<d1<<endl;
	cout<<"{"<<c2<<"*a0+"<<c3<<"*a1+"<<c4<<"*a2+"<<c5<<"a3+"<<c6<<"a4="<<d2<<endl;
	cout<<"{"<<c3<<"*a0+"<<c4<<"*a1+"<<c5<<"*a2+"<<c6<<"a3+"<<c7<<"a4="<<d3<<endl;
	cout<<"{"<<c4<<"*a0+"<<c5<<"*a1+"<<c6<<"*a2+"<<c7<<"a3+"<<(int)c8<<"a4="<<d4<<endl;
	a4=x4;a3=x3;a2=x2;a1=x1;a0=x0; //€ провериль
	cout<<"Q4="<<a0<<"+"<<a1<<"x+"<<a2<<"x^2+"<<a3<<"x^3+"<<a4<<"x^4\n";
	for(int i=0;i<6;i++){
		t[7][i]=a0+a1*r[i]+a2*r[i]*r[i]+a3*r[i]*r[i]*r[i]+a4*r[i]*r[i]*r[i]*r[i];
	}
	for(int i=0;i<=4;i++){
		mi[5][i]=a0+a1*x[i]+a2*x[i]*x[i]+a3*x[i]*x[i]*x[i]+a4*x[i]*x[i]*x[i]*x[i];
	}
	cout<<"»щем точки дл€ построени€ графика:\n";
	cout<<"x(-1)*=x0-0.5=-0.5\nx(0)*=x0+0.5=0.5\nx(1)*=x1+0.5=1.5\nx(2)*=3.5\nx(3)*=5.5\nx(4)*=7.5\n";
	cout.precision(3);
	cout<<"\t";
	for(int i=0;i<6;i++){cout<<r[i]<<"\t";}
	cout<<endl;
	cout<<"L4(x)\t";
	for(int i=0;i<6;i++){cout<<t[7][i]<<"\t";}
	cout<<endl;
	cout<<"P4(x)\t";
	for(int i=0;i<6;i++){cout<<t[7][i]<<"\t";}
	cout<<endl;
	cout<<"Q0(x)\t";
	for(int i=0;i<6;i++){cout<<t[3][i]<<"\t";}
	cout<<endl;
	cout<<"Q1(x)\t";
	for(int i=0;i<6;i++){cout<<t[4][i]<<"\t";}
	cout<<endl;
	cout<<"Q2(x)\t";
	for(int i=0;i<6;i++){cout<<t[5][i]<<"\t";}
	cout<<endl;
	//cout.precision(2);
	cout<<"Q3(x)\t";
	for(int i=0;i<6;i++){cout<<t[6][i]<<"\t";}
	cout<<endl;
	//cout.precision(3);
	cout<<"Q4(x)\t";
	for(int i=0;i<6;i++){cout<<t[7][i]<<"\t";}
	cout<<endl;
	cout<<"“еперь —–≈ƒЌ≈ ¬јƒ–ј“»„Ќџ≈ ќ“ ЋќЌ≈Ќ»я:\n";
	cout.precision(8);
	y[0]=-1;y[1]=2;y[2]=3;y[3]=-2;y[4]=0;
	double otklon,sum=0;
	for(int i=0;i<=4;i++){
		//cout<<"i="<<i<<":"<<"yi "<<y[i]<<" -q0 "<<mi[1][i]<<endl;
		sum+=((y[i]-mi[1][i])*(y[i]-mi[1][i]));
	}
	//cout<<"SUM="<<sum<<endl;
	sum/=5;
	otklon=sqrt(sum);
	cout<<"^0="<<otklon<<endl;sum=0;
	for(int i=0;i<=4;i++){
		//cout<<i<<"S="<<(y[i]-mi[1][i])<<endl;
		sum+=(y[i]-mi[2][i])*(y[2]-mi[1][i]);
	}
	sum/=5;
	otklon=sqrt(sum);
	cout<<"^1="<<otklon<<endl;sum=0;
	for(int i=0;i<=4;i++){
		sum+=(y[i]-mi[3][i])*(y[i]-mi[3][i]);
	}
	sum/=5;
	otklon=sqrt(sum);
	cout<<"^2="<<o(otklon)<<endl;sum=0;
	for(int i=0;i<=4;i++){
		sum+=(y[i]-mi[4][i])*(y[i]-mi[4][i]);
	}
	sum/=5;
	otklon=sqrt(sum);
	cout<<"^3="<<p(otklon)<<endl;sum=0;
	for(int i=0;i<=4;i++){
		sum+=(y[i]-mi[5][i])*(y[i]-mi[5][i]);
	}
	sum/=5;
	otklon=sqrt(sum);
	cout<<"^4="<<otklon<<endl;sum=0;
	system("pause");
	return 0;}