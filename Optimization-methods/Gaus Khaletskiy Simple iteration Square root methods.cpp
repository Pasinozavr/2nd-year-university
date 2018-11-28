#include <iostream>
#include <math.h>
using namespace std;
void out(int a11,int a12,int a13,int a21,int a22,int a23,int a31,int a32,int a33,int b1,int b2,int b3){
	cout<<"|"<<a11<<"\t"<<a12<<"\t"<<a13<<"\t"<<b1<<"|"<<endl;
	cout<<"|"<<a21<<"\t"<<a22<<"\t"<<a23<<"\t"<<b2<<"|"<<endl;
	cout<<"|"<<a31<<"\t"<<a32<<"\t"<<a33<<"\t"<<b3<<"|"<<endl;
}
void xnext(float&eps,float&zzz,int t){
	if(t==6){
		zzz=eps-1;
	}
}

float normamatrix(float a[3][3])
{
    float tmp, sum=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if(i!=j) sum+=((a[i][j]/a[i][i])*(a[i][j]/a[i][i]));
            }
        }
    tmp=sqrt(sum);
    return tmp;
    }

float vnorm(float x[3])
{
    return sqrt(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]);
    }
void prost(){
	float b[3][3];
    b[0][0]=3; b[0][1]=1; b[0][2]=-1;
    b[1][0]=-2; b[1][1]=4; b[1][2]=-1;
    b[2][0]=1; b[2][1]=1; b[2][2]=-4;
    float f[3];
    f[0]=3; f[1]=1; f[2]=-2;
    float x0[3], x1[3];  
    int yi=0;
    float eps=0.0001;
    float norm=normamatrix(b);

    x0[0]=0; x0[1]=0; x0[2]=0;
        for(int i=0; i<3; i++)
    {
    float summm=0;
    for (int j=0; j<3; j++)
        {
            if(j!=i)
            {
                float tmp=(b[i][j]/b[i][i])*x0[j];
                summm+=tmp;
                }
        }
        summm=0-summm;
        x1[i]=summm+f[i]/b[i][i];
    }

    float doit=norm/(1-norm);
    float x2[3]; x2[0]=x1[0]-x0[0]; x2[1]=x1[1]-x0[1]; x2[2]=x1[2]-x0[2];
    float doit2=vnorm(x2);
    doit*=doit2;
	
while(doit>=eps)
{
	yi++;
    x0[0]=x1[0]; x0[1]=x1[1]; x0[2]=x1[2];
    for(int i=0; i<3; i++)
    {
    float summm=0;
    for (int j=0; j<3; j++)
        {
            if(j!=i)
            {
                float tmp=(b[i][j]/b[i][i])*x0[j];
                summm+=tmp;
                }
        }
        summm=0-summm;
        x1[i]=summm+f[i]/b[i][i];
    }

    doit/=doit2;
    x2[0]=x1[0]-x0[0]; x2[1]=x1[1]-x0[1]; x2[2]=x1[2]-x0[2];
    doit2=vnorm(x2);
    doit*=doit2;
    }
cout<<"На "<<yi<<" шаге: "<<endl;
        for(int i=0; i<3; i++)
			
    cout << "x[" << i+1 << "]=" << x1[i] << endl; 
float m[3];
    for(int i=0; i<3; i++)
    {
        m[i]=0;
        for(int j=0; j<3; j++)
        m[i]+=b[i][j]*x1[j];
        }
    for(int i=0; i<3; i++) m[i]-=f[i];
    
    cout << "Вектор отклонения:" << endl;
    for(int i=0; i<3; i++) cout << m[i]<<" ";
    cout << endl;

}
int main(){
	setlocale(LC_ALL, "rus");
	cout.precision(2);
	int a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3;
	//задание 2.1 - Гаус, Холецкий, простая итерация
	
	//задание 2.2 - квадратный корень
	//...//
	
	int met;
	do{
	a11=3;a12=1;a13=-1;b1=3;
	a21=1;a22=1;a23=-4;b2=-2;
	a31=-2;a32=4;a33=-1;b3=1;
		cout<<"Выберите метод:\n1.Гауса\n2.Холецького\n3.Простой итерации\n4.Квадратного корня\n0.Выход\n# ";
		cin>>met;
		if(met==1||met==2||met==3){
			//типа красивый вывод
			cout<<"("<<a11<<")"<<"*x1+"<<"("<<a12<<")"<<"*x2+"<<"("<<a13<<")"<<"*x3="<<"("<<b1<<")"<<endl;
			cout<<"("<<a21<<")"<<"*x1+"<<"("<<a22<<")"<<"*x2+"<<"("<<a23<<")"<<"*x3="<<"("<<b2<<")"<<endl;
			cout<<"("<<a31<<")"<<"*x1+"<<"("<<a32<<")"<<"*x2+"<<"("<<a33<<")"<<"*x3="<<"("<<b3<<")"<<endl;
		}
		if(met==1){
			cout<<"Расширенная матрица системы:\n";
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"для удобства 2-ю строку домножаем на (-3):\n";
			a21*=-3;a22*=-3;a23*=-3;b2*=-3;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"складываем 1-й и 2-й столбцы:\n";
			a21+=a11;a22+=a12;a23+=a13;b2+=b1;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"делаем первые коэффициенты 1-го и 3-го стобца одинаковыми:\nдомножаем 1-й на (2), а 3-й на (3):\n";
			a11*=2;a12*=2;a13*=2;b1*=2;
			a31*=3;a32*=3;a33*=3;b3*=3;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"складываем 1-й и 3-й столбцы:\n";
			a31+=a11;a32+=a12;a33+=a13;b3+=b1;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);		
			cout<<"делаем вторые коэффициенты 2-го и 3-го стобца одинаковыми:\nдомножаем 2-й на (14), а 3-й на (2):\n";
			//ребята, вы можете на что-нибудь нажать? а то дышать темно
			//самостоятельную работу я вам не придумала, так что будет на следующий раз // ой, какая жалость
			a21*=14;a22*=14;a23*=14;b2*=14;
			a31*=2;a32*=2;a33*=2;b3*=2;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);		
			cout<<"складываем 2-й и 3-й столбцы\nи получаем треугольную матрицу:\n";
			a31+=a21;a32+=a22;a33+=a23;b3+=b2;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"приводим к более простому виду (делим на 2, 14 и 144 соотв):\n";
			a31/=144;a32/=144;a33/=144;b3/=144;
			a21/=14;a22/=14;a23/=14;b2/=14;
			a11/=2;a12/=2;a13/=2;b1/=2;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"умножаем 3-ю строку на 11, отнимаем из 2-й 3-ю\nи возвращаем 3-ю к начальному виду:\n";
			a31*=11;a32*=11;a33*=11;b3*=11;
			a21-=a31;a22-=a32;a23-=a33;b2-=b3;
			a31/=11;a32/=11;a33/=11;b3/=11;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"приводим к более простому виду (делим 2-ю на (-2)):\n";
			a21/=-2;a22/=-2;a23/=-2;b2/=-2;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"складываем 1-ю с 3-й и вычитаем из 1-й 2-ю:\n";
			a11+=a31;a12+=a32;a13+=a33;b1+=b3;
			a11-=a21;a12-=a22;a13-=a23;b1-=b2;
			a11/=3;a12/=3;a13/=3;b1/=3;
			out(a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3);
			cout<<"выходит последний столбец это искомые корни:\nx1="<<b1<<",x2="<<b2<<",x3="<<b3<<endl;
			cout<<"вектор отклонения: "<<endl;
				float q1,q2,q3,x1=b1,x2=b2,x3=b3;
			q1=a11*x1+a12*x2+a13*x3-b1;
			q2=a21*x1+a22*x2+a23*x3-b2;
			q3=a31*x1+a32*x2+a33*x3-b3;
			cout<<q1<<"\t"<<q2<<"\t"<<q3<<endl;
		}
		if(met==2){
			float b11,b12,b13,b21,b22,b23,b31,b32,b33,c11,c12,c13,c21,c22,c23,c31,c32,c33;
			cout<<"предст матрицы А как произв В и С:\n";
			cout<<"|b11  0    0| |1 c12 c13| |"<<""<<a11<<" "<<a12<<" "<<a13<<"|"<<endl;
			cout<<"|b21 b22   0|*|0   1 c23|"<<"=|"<<a21<<" "<<a22<<" "<<a23<<"|"<<endl;
			cout<<"|b31 b32 b33| |0   0   1| |"<<""<<a31<<" "<<a32<<" "<<a33<<"|"<<endl;
			cout<<"bi1=ai1 (i=1,2,3) и c1j=a1j/b11 (j=2,3):\n";
			b12=b13=b23=c21=c31=c32=0;
			c11=c22=c33=1;
			b11=a11;
			b21=a12;
			b31=a31;
			c12=a12/b11;
			c13=a13/b11;
			cout<<"b11="<<b11<<"\nb21="<<b21<<"\nb31="<<b31<<"\nc12="<<c12<<"\nc13="<<c13<<endl;
			b22=a22-b21*c12;
			c23=(a23-c13)/b22;
			b32=a32-b31*c12;
			b33=(a33-b31*c13-b32*c23);
			cout<<"b22="<<b22<<"\nc23="<<c23<<"\nb32="<<b32<<"\nb33="<<b33<<endl;
			cout<<"матрица В:\n";
			cout<<"|"<<b11<<"\t"<<b12<<"\t"<<b13<<"|"<<endl;
			cout<<"|"<<b21<<"\t"<<b22<<"\t"<<b23<<"|"<<endl;
			cout<<"|"<<b31<<"\t"<<b32<<"\t"<<b33<<"|"<<endl;
			cout<<"матрица C:\n";
			cout<<"|"<<c11<<"\t"<<c12<<"\t"<<c13<<"|"<<endl;
			cout<<"|"<<c21<<"\t"<<c22<<"\t"<<c23<<"|"<<endl;
			cout<<"|"<<c31<<"\t"<<c32<<"\t"<<c33<<"|"<<endl;
			cout<<"B*C*x=f и C*x=y: B*y=f\n";
			float y1,y2,y3;
			cout<<"|"<<b11<<"\t"<<b12<<"\t"<<b13<<"| |y1| |"<<b1<<"|"<<endl;
			cout<<"|"<<b21<<"\t"<<b22<<"\t"<<b23<<"|*|y2|=|"<<b2<<"|"<<endl;
			cout<<"|"<<b31<<"\t"<<b32<<"\t"<<b33<<"| |y3| |"<<b3<<"|"<<endl;
			cout<<b11<<"*y1="<<b1<<endl;
			cout<<b21<<"*y1+"<<b22<<"*y2="<<b2<<endl;
			cout<<b31<<"*y1+"<<b32<<"*y2+"<<b33<<"*y3="<<b3<<endl;
			y1=b1/b11;
			y2=(b2-b21*y1)/b22;
			y3=(b3-b31*y1-b32*y2)/b33;
			cout<<"y1="<<y1<<"\ny2="<<y2<<"\ny3="<<y3<<endl;
			cout<<"C*x=y:\n";
			cout<<"|"<<c11<<"\t"<<c12<<"\t"<<c13<<"| |x1| |"<<y1<<"|"<<endl;
			cout<<"|"<<c21<<"\t"<<c22<<"\t"<<c23<<"|*|x2|=|"<<y2<<"|"<<endl;
			cout<<"|"<<c31<<"\t"<<c32<<"\t"<<c33<<"| |x3| |"<<y3<<"|"<<endl;
			float x1,x2,x3;
			x3=y3;
			x2=y2-c23*x3;
			x1=y1-c12*x2-c13*x3;
			cout<<"x1="<<x1<<"\nx2="<<x2<<"\nx3="<<x3<<endl;
			cout<<"вектор отклонения: "<<endl;
				float q1,q2,q3;
			q1=a11*x1+a12*x2+a13*x3-b1;
			q2=a21*x1+a22*x2+a23*x3-b2;
			q3=a31*x1+a32*x2+a33*x3-b3;
			cout<<q1<<"\t"<<q2<<"\t"<<q3<<endl;
		}
		if(met==3){
			  /*
			
	cout<<"|"<<a11<<"\t"<<a12<<"\t"<<a13<<"| |x1| |"<<b1<<"|"<<endl;
	cout<<"|"<<a21<<"\t"<<a22<<"\t"<<a23<<"|*|x2|=|"<<b2<<"|"<<endl;
	cout<<"|"<<a31<<"\t"<<a32<<"\t"<<a33<<"| |x3| |"<<b3<<"|"<<endl;
			cout<<"система не имеет диагонального доминирования и не явл положительно опр.\n";
			cout<<"умножим обе части на трансп матрицу системы:\n";
			float b11,b12,b13,b21,b22,b23,b31,b32,b33,c11,c12,c13,c21,c22,c23,c31,c32,c33,c1,c2,c3;
			b11=a11;b12=a21;b13=a31;
			b21=a12;b22=a22;b23=a32;
			b31=a13;b32=a23;b33=a33;
			//умножение матриц
c11 = a11 * b11 + a12 * b21 + a13 * b31;
c12 = a11 * b12 + a12 * b22 + a13 * b32;
c13 = a11 * b13 + a12 * b23 + a13 * b33;
c21 = a21 * b11 + a22 * b21 + a23 * b31;
c22 = a21 * b12 + a22 * b22 + a23 * b32;
c23 = a21 * b13 + a22 * b23 + a23 * b33;
c31 = a31 * b11 + a32 * b21 + a33 * b31;
c32 = a31 * b12 + a32 * b22 + a33 * b32;
c33 = a31 * b13 + a32 * b23 + a33 * b33;

c1 = b11 * b1 + b12 * b2 + b13 * b3;
c2 = b21 * b1 + b22 * b2 + b23 * b3;
c3 = b31 * b1 + b32 * b2 + b33 * b3;

cout<<"|"<<c11<<"\t"<<c12<<"\t"<<c13<<"| |x1| |"<<c1<<"|"<<endl;
cout<<"|"<<c21<<"\t"<<c22<<"\t "<<c23<<"|*|x2|=|"<<c2<<"|"<<endl;
cout<<"|"<<c31<<"\t"<<c32<<"\t"<<c33<<"| |x3| |"<<c3<<"|"<<endl;
cout<<"эта матрица симм и положительно опр\n";
/*
int a1=0,a2=0,a3=0;
int sum1=0,sum2=0,sum3=0,sum=0,summ=0,summm=0;
int a[3][3]={3,1,-1,1,1,-4,-2,4,-1};
	for(int j=0;j<3;j++){
		sum1+=abs(a[0][j]);
	}
	for(int j=0;j<3;j++){
		sum2+=abs(a[1][j]);
	}
	for(int j=0;j<3;j++){
		sum3+=abs(a[2][j]);
	}
	
	sum=max(sum1,sum2);
	sum=max(sum,sum3);
	summ=sum;
	int q=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(abs(a[i][j])>q){q=abs(a[i][j]);}
		}}
	summm=3*q;
	cout<<"||a||i=||a||ii="<<sum<<endl<<"||a||iii="<<summm<<endl;
	//float w=1/12;cout<<w;
	double alpha=1./(max(sum,summm));
	//cin.precision(10);
	cout<<"alpha="<<alpha<<endl;
	cout<<"B=E-alpha*A'':\n";
	int f11=1,f12=0,f13=0,f21=0,f22=1,f23=0,f31=0,f32=0,f33=1;
	b11=f11-alpha*c11;b12=f12-alpha*c12;b13=f13-alpha*c13;
	b21=f21-alpha*c21;b22=f22-alpha*c22;b23=f23-alpha*c23;
	b31=f31-alpha*c31;b32=f32-alpha*c32;b33=f33-alpha*c33;
			cout<<"|"<<b11<<"\t"<<b12<<"\t"<<b13<<"|"<<endl;
			cout<<"|"<<b21<<"\t"<<b22<<"\t"<<b23<<"|"<<endl;
			cout<<"|"<<b31<<"\t"<<b32<<"\t"<<b33<<"|"<<endl;
float g1,g2,g3;
g1=c1*alpha;g2=c2*alpha;g3=c3*alpha;
cout<<"g=alpha*f'':\n";
cout<<"|"<<g1<<"|\n";
cout<<"|"<<g2<<"|\n";
cout<<"|"<<g3<<"|\n";
float x1=g1,x2=g2,x3=g3;
float b[3][3];
b[1][1]=b11;b[1][2]=b12;b[1][3]=b13;
b[2][1]=b21;b[2][2]=b22;b[2][3]=b23;
b[3][1]=b31;b[3][2]=b32;b[3][3]=b33;
//точность тут
float eps=0.0001,zzz;
int t=0;
float q7=0,q8=0,q9=0;
cout<<"система приведена к удобному для нас виду: x=B*x+g\nx(0)=g, критерий остановки: ||x(k)-x(k-1)||i<eps\nx(1)=B*x(0)+g:\n";
float x1p,x2p,x3p;
float b1=0;

	for(int j=1;j<=3;j++){
		q7+=abs(b[1][j]);
		q8+=abs(b[2][j]);
		q9+=abs(b[3][j]);
	}

	if(q7>=q8 && q7>=q9){b1=q7;}
	if(q8>=q7 && q8>=q9){b1=q8;}
	if(q9>=q7 && q9>=q8){b1=q9;}
	cout<<"b'="<<b1<<endl;
	q9=0;
	do{
	//cout<<".";
	t++;
	q9++;
	x1p=x1;x2p=x2;x3p=x3;
	

			x1=b11*x1p+b21*x2p+b31*x3p+g1;
			x2=b12*x1p+b22*x2p+b32*x3p+g2;
			x3=b13*x1p+b23*x2p+b33*x3p+g3;
				
if(abs(x1-x1p)>=abs(x2-x2p) && abs(x1-x1p)>=abs(x3-x3p)){zzz=abs(x1-x1p);}
if(abs(x2-x2p)>=abs(x1-x1p) && abs(x2-x2p)>=abs(x3-x3p)){zzz=abs(x2-x2p);}
if(abs(x3-x3p)>=abs(x1-x1p) && abs(x3-x3p)>=abs(x2-x2p)){zzz=abs(x3-x3p);}

//xnext(eps,zzz,t);
//if(q9==100){
//cout<<"x1("<<t<<")="<<x1<<endl;
//cout<<"x2("<<t<<")="<<x2<<endl;
//cout<<"x3("<<t<<")="<<x3<<endl;
//}
}while(zzz>=((1-b1)*eps)/b1);
cout<<"на "<<t<<"-м шаге условие критерий остановки вып и получаем:\n";
cout<<"x1="<<x1<<endl;
cout<<"x2="<<x2<<endl;
cout<<"x3="<<x3<<endl;

cout<<"вектор отклонения: "<<endl;
			float q1,q2,q3;
			q1=a11*x1+a12*x2+a13*x3-b1;
			q2=a21*x1+a22*x2+a23*x3-b2;
			q3=a31*x1+a32*x2+a33*x3-b3;
			cout<<q1<<"\t"<<q2<<"\t"<<q3<<endl;
			*/
prost();
		}
		if(met==4){
			a11=1;a12=2;a13=-3;b1=1;
			a21=2;a22=8;a23=-10;b2=2;
			a31=-3;a32=-10;a33=14;b3=3;
			int min1=a11,min2=a11*a22-a12*a21,min3=a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a13*a22*a31 - a11*a23*a32 - a12*a21*a33;
			int opr=min3;
			cout<<"миноры матрицы: "<<min1<<", "<<min2<<", "<<min3<<endl;
			cout<<"разложение матрицы системы:\n";
			cout<<"|"<<a11<<"\t"<<a12<<"\t"<<a13<<"|  |s11  0  0 | |s11 s12 s13|"<<endl;
			cout<<"|"<<a21<<"\t"<<a22<<"\t"<<a23<<"|=|s1  s22  0|*|0  s22 s23|"<<endl;
			cout<<"|"<<a31<<"\t"<<a32<<"\t"<<a33<<"| |s13 s23 s33| |0  0  s33|"<<endl;
			float s11,s12,s13,s21=0,s22,s23,s31=0,s32=0,s33;
			s11=sqrt(double(a11));
			s12=a12/s11;
			s13=a13/s11;

			s22=sqrt(a22-s12*s12);
			s23=(a23-s12*s13)/s22;
			s33=sqrt(a33-s13*s13-s23*s23);
			cout<<"матрица S:\n";
			cout<<"|"<<s11<<"\t"<<s12<<"\t"<<s13<<"|"<<endl;
			cout<<"|"<<s21<<"\t"<<s22<<"\t"<<s23<<"|"<<endl;
			cout<<"|"<<s31<<"\t"<<s32<<"\t"<<s33<<"|"<<endl;
			cout<<"S(T)*S*x=f\nS*x=y\n";
			cout<<"|"<<s11<<"\t"<<s21<<"\t"<<s31<<"| |y1| |"<<b1<<"|"<<endl;
			cout<<"|"<<s12<<"\t"<<s22<<"\t"<<s32<<"|*|y2|=|"<<b2<<"|"<<endl;
			cout<<"|"<<s13<<"\t"<<s23<<"\t"<<s33<<"| |y3| |"<<b3<<"|"<<endl;
			int y1,y2,y3;
			y1=b1/s11;
			y2=(b2-s12*y1)/s22;
			y3=(b3-s13*y1-s22*y2)/s33;
			cout<<"y1="<<y1<<", y2="<<y2<<", y3="<<y3<<endl;
			cout<<"|"<<s11<<"\t"<<s12<<"\t"<<s13<<"| |x1| |"<<y1<<"|"<<endl;
			cout<<"|"<<s21<<"\t"<<s22<<"\t"<<s23<<"|*|x|=|"<<y2<<"|"<<endl;
			cout<<"|"<<s31<<"\t"<<s32<<"\t"<<s33<<"| |x3| |"<<y3<<"|"<<endl;
			int x1,x2,x3;
			x3=y3/s33;
			x2=(y2-s23*x3)/s22;
			x1=(y1-s12*x2-s13*x3)/s11;
			cout<<"x1="<<x1<<", x2="<<x2<<", x3="<<x3<<endl;
			cout<<"вектор отклонения: "<<endl;
				int q1,q2,q3;
			q1=a11*x1+a12*x2+a13*x3-b1;
			q2=a21*x1+a22*x2+a23*x3-b2;
			q3=a31*x1+a32*x2+a33*x3-b3;
			cout<<q1<<"\t"<<q2<<"\t"<<q3<<endl;
		}
		if(met==0){return 0;}
	}while(met!=0);
	system("pause");
return 0;
}