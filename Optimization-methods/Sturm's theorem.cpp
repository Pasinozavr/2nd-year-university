/*	Задано алгебраїчне рівняння   з дійсними коефіцієнтами Використовуючи теорему Штурма відокремити дійсні корені алгебраїчного рівняння.
1. 	Розробити підпрограми уточнення відокремлених коренів такими ітераційними методами: метод ділення навпіл, метод простої ітерації, 
метод дотичних, метод хорд.
2. 	За допомогою розроблених та відлагоджених підпрограм добути розв’язки конкретних рівнянь з заданою точністю eps=10^-5.
3. 	Провести аналіз результатів.
x^3-3x^2+x-2=0*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int a0,a1,a2,a3,b0,b1,b2,b3,c0,c1,c2,c3;

float fss(float x){
	return c2*x+c3;
}
float fs(float x){
	return b1*x*x+b2*x+b3;
}
float f(float x){
	return a0*x*x*x+a1*x*x+a2*x+a3;
}


int main(){
	
	cout<<"f(x)=a0*x^3+a1*x^2+a2*x+a3=0\nin my variant: a0=1, a1=-3, a2=1, a3=-2\n";
	//cout<<"input that data:\na0=";cin>>a0;cout<<"a1=";cin>>a1;cout<<"a2=";cin>>a2;cout<<"a3=";cin>>a3;
	a0=2;a1=-6;a2=+4;a3=-3;
	cout<<"("<<a0<<")*x^3+"<<"("<<a1<<")*x^2+"<<"("<<a2<<")*x+"<<"("<<a3<<")\n";
	b0=a0*3;
	b1=a1*2;
	b2=a2;
	b3=0;
	cout<<"f=f0(x)=("<<a0<<")*x^3+"<<"("<<a1<<")*x^2+"<<"("<<a2<<")*x+"<<"("<<a3<<")\n";
	cout<<"f1(x)=f0'(x)=("<<b0<<")*x^2+"<<"("<<b1<<")*x+"<<"("<<b2<<")\n";
	cout<<"f2=-(f0%f1)\n";
	cout<<"("<<a0<<")*x^3+"<<"("<<a1<<")*x^2+"<<"("<<a2<<")*x+"<<"("<<a3<<")|("<<b0<<")*x^2+"<<"("<<b1<<")*x+"<<"("<<b2<<")\n";
	if(a0%b0){
		cout<<"multiplication for convenience\n";
		int a0c=a0;
		a0*=b0;a1*=b0;a2*=b0;a3*=b0;
		b0*=a0c;b1*=a0c;b2*=a0c;b3*=a0c;
	}
	cout<<"("<<a0<<")*x^3+"<<"("<<a1<<")*x^2+"<<"("<<a2<<")*x+"<<"("<<a3<<")|("<<b0<<")*x^2+"<<"("<<b1<<")*x+"<<"("<<b2<<")\n";
	c2=a0/b0;
	int pr0,pr1,pr2,pr3;
	pr0=b0*c2;pr1=b1*c2;pr2=b2*c2;
	//cout<<"f2: ("<<c0<<")*x+(?)\n";
	cout<<"("<<a0<<")*x^3+"<<"("<<a1<<")*x^2+"<<"("<<a2<<")*x+"<<"("<<a3<<")\n-\n";
	cout<<"("<<pr0<<")*x^3+"<<"("<<pr1<<")*x^2+"<<"("<<pr2<<")*x\n";
	cout<<"_____\n";
	pr0=a0-pr0;
	pr1=a1-pr1;
	pr2=a2-pr2;
	pr3=a3;
	cout<<"("<<pr0<<")*x^3+"<<"("<<pr1<<")*x^2+"<<"("<<pr2<<")*x+"<<"("<<pr3<<")\n";
	/*if(pr1%b1){		cout<<"multiplication for convenience\n";
		pr1*=b0;pr2*=b0;pr3*=b0;
	}*/
	c3=pr1/b0;
	int dr0,dr1,dr2,dr3;
	dr1=b0*c3;dr2=b1*c3;dr3=b2*c3;
	cout<<"("<<pr1<<")*x^2+"<<"("<<pr2<<")*x+"<<"("<<pr3<<")\n-\n";
	cout<<"("<<dr1<<")*x^2+"<<"("<<dr2<<")*x+"<<"("<<dr3<<")\n";
	cout<<"_____\n";
	dr1=pr1-dr1;
	dr2=pr2-dr2;
	dr3=pr3-dr3;
	cout<<"("<<dr1<<")*x^2+"<<"("<<dr2<<")*x+"<<"("<<dr3<<")\n";
	//здесь я стираю целую часть от деления
	c2=dr2*(-1);c3=dr3*(-1);
	//делим на положит число
	if(!(c2%2)&&!(c3%2)){c2/=2;c3/=2;}
	if(!(c2%3)&&!(c3%3)){c2/=3;c3/=3;}
	cout<<"f2=("<<c2<<")*x+"<<"("<<c3<<")\n";
	cout<<"f3=-(f1%f2)\n";
	int d0,d1,d2,d3;
	//вот тут была некоторая путаница, потому что я не сдвинул нумерацию b
	b3=b2;b2=b1;b1=b0;
	cout<<"("<<b1<<")*x^2+"<<"("<<b2<<")*x+"<<"("<<b3<<")|("<<c2<<")*x+"<<"("<<c3<<")\n";
	if(b1%c2){
		cout<<"multiplication for convenience\n";
		int b1c=b1;
		b1*=c2;b2*=c2;b3*=c2;
		//c2*=b1c;c3*=b1c;
	}
	cout<<"("<<b1<<")*x^2+"<<"("<<b2<<")*x+"<<"("<<b3<<")|("<<c2<<")*x+"<<"("<<c3<<")\n";
	d2=b1/c2;
	pr1=c2*d2;pr2=c3*d2;pr3=b3;
	cout<<"("<<b1<<")*x^2+"<<"("<<b2<<")*x+"<<"("<<b3<<")\n-\n";
	cout<<"("<<pr1<<")*x^2+"<<"("<<pr2<<")*x+("<<pr3<<")\n";
	cout<<"_______\n";
	pr1=b1-pr1;pr2=b2-pr2;
	cout<<"("<<pr1<<")*x^2+"<<"("<<pr2<<")*x+("<<pr3<<")\n";
	cout<<"("<<pr2<<")*x+("<<pr3<<")|("<<c2<<")*x+"<<"("<<c3<<")\n";
	if(pr2%c2){
		cout<<"multiplication for convenience\n";
		pr2*=c2;pr3*=c2;
	}
	cout<<"("<<pr2<<")*x+("<<pr3<<")\n-\n";
	d3=pr2/c2;
	dr2=c2*d3;dr3=c3*d3;
	cout<<"("<<dr2<<")*x+("<<dr3<<")\n";
	cout<<"_____\n";
	dr2=pr2-dr2;dr3=pr3-dr3;
	cout<<"("<<dr2<<")*x+("<<dr3<<")\n";
	//стриаем промежуточные варианты
	d3=dr3*(-1);
	cout<<"f3="<<d3<<"=";d3/=abs(d3);cout<<d3<<"\n";
	//убираем последствия умножения для удобного деления
	a0/=b0;a1/=b0;a2/=b0;a3/=b0;
	b1/=c2;b2/=c2;b3/=c2;
	cout<<"So:\n";
	cout<<"f0=("<<a0<<")*x^3+"<<"("<<a1<<")*x^2+"<<"("<<a2<<")*x+"<<"("<<a3<<")\n";
	cout<<"f1=("<<b1<<")*x^2+"<<"("<<b2<<")*x+"<<"("<<b3<<")\n";
	cout<<"f2=("<<c2<<")*x+"<<"("<<c3<<")\n";
	cout<<"f3="<<d3<<endl;
	char f0m,f0n,f0p,f1m,f1n,f1p,f2m,f2n,f2p,f3m,f3n,f3p;
	int nm=0,nn=0,np=0;
	//заполнение таблички
	if(a0>0){f0m='-';}else{f0m='+';}
	if(a3>0){f0n='+';}else{f0n='-';}
	if(f0m=='-'){f0p='+';}else{f0p='-';}
	if(b1<0){f1m='-';}else{f1m='+';}
	f1p=f1m;
	if(b3>0){f1n='+';}else{f1n='-';}
	if(c2<0){f2m='+';}else{f2m='-';}
	if(c3>0){f2n='+';}else{f2n='-';}
	if(f2m=='-'){f2p='+';}else{f2p='-';}
	if(d3<0){f3m=f3n=f3p='-';}else{f3m=f3n=f3p='+';}
	//вычисленине кол-ва знакоперемен
	if(f0m!=f1m){nm++;}
	if(f1m!=f2m){nm++;}
	if(f2m!=f3m){nm++;}

	if(f0n!=f1n){nn++;}
	if(f1n!=f2n){nn++;}
	if(f2n!=f3n){nn++;}

	if(f0p!=f1p){np++;}
	if(f1p!=f2p){np++;}
	if(f2p!=f3p){np++;}
	//вывод таблицы
	cout<<"x\tf0\tf1\tf2\tf3\tN\n";
	cout<<"+inf"<<"\t"<<f0m<<"\t"<<f1m<<"\t"<<f2m<<"\t"<<f3m<<"\t"<<nm<<endl;
	cout<<"0"<<"\t"<<f0n<<"\t"<<f1n<<"\t"<<f2n<<"\t"<<f3n<<"\t"<<nn<<endl;
	cout<<"+inf"<<"\t"<<f0p<<"\t"<<f1p<<"\t"<<f2p<<"\t"<<f3p<<"\t"<<np<<endl;
	//находим кол-во действительных корней
	cout<<"|N(-inf)-N(+inf)|="<<abs(nm-np)<<" real root\n";
	int ntotal=abs(nm-np),nminus=abs(nn-nm),nplus=abs(np-nn);
	cout<<"N-=|N(0)-N(-inf)|="<<nminus<<endl<<"N+=|N(+inf)-N(0)|="<<nplus<<endl;
	cout<<"D=1+A/abs(a0)\n";
	int A; 
	if(abs(a0)>=abs(a1) && abs(a0)>=abs(a2)){A=abs(a0);}
	if(abs(a1)>=abs(a0) && abs(a1)>=abs(a2)){A=abs(a1);}
	if(abs(a2)>=abs(a1) && abs(a2)>=abs(a0)){A=abs(a2);}
	cout<<"A=max|ai|="<<A<<endl;
	int D=1+A/abs(a0);
	cout<<"D=1+"<<A<<"/"<<abs(a0)<<"="<<D<<endl;
	cout<<"So: -"<<D<<"<ksi<"<<D<<" => ";
	int a,b,npr;
	if(nminus==ntotal){cout<<(-1)*D<<"<ksi<0\n";
	
	cout<<"x\tf0\tf1\tf2\tf3\tN\n";
	for(int x=D*(-1);x<=0;x++){
		int f0,f1,f2,f3,N=0;
		f0=a0*x*x*x+a1*x*x+a2*x+a3;
		f1=b1*x*x+b2*x+b3;
		f2=c2*x+c3;
		f3=d3;
		if(f0*f1<0){N++;}
		if(f1*f2<0){N++;}
		if(f2*f3<0){N++;}
		cout<<x<<"\t"<<f0<<"\t"<<f1<<"\t"<<f2<<"\t"<<f3<<"\t"<<N<<endl;
		if(x){if(npr!=N){a=x-1;b=x;}}
		npr=N;
	}
	cout<<a<<"<ksi<"<<b<<endl;
	}
	if(nplus==ntotal){cout<<"0<ksi<"<<D<<endl;
	
	cout<<"x\tf0\tf1\tf2\tf3\tN\n";
	for(int x=0;x<=D;x++){
		int f0,f1,f2,f3,N=0;
		f0=a0*x*x*x+a1*x*x+a2*x+a3;
		f1=b1*x*x+b2*x+b3;
		f2=c2*x+c3;
		f3=d3;
		if(f0*f1<0){N++;}
		if(f1*f2<0){N++;}
		if(f2*f3<0){N++;}
		cout<<x<<"\t"<<f0<<"\t"<<f1<<"\t"<<f2<<"\t"<<f3<<"\t"<<N<<endl;
		if(x){if(npr!=N){a=x-1;b=x;}}
		npr=N;
	}
	cout<<a<<"<ksi<"<<b<<endl;
	}
	setlocale(LC_ALL, "Russian");
	cout<<"Метод половинного деления\n";
	float eps=0.00001,aq=a,bq=b;
	float kol=log((b-a)/eps)/log(2.0)-1;
	int k=kol;k++;
	cout<<"Количество итераций n>log2((b-a)/eps)-1="<<kol<<", т.е. n="<<k<<endl<<"xn=(an+bn)/2\n";
	cout<<"n\tan\txn\tbn\tf(an)\t\tf(xn)\t\tf(bn)\n";
	float ksi;
	
	for(int i=1;i<=k;i++){
		cout<<i<<"\t"<<aq<<"\t"<<(aq+bq)/2<<"\t"<<bq<<"\t"<<f(aq)<<"\t"<<f((aq+bq)/2)<<"\t"<<f(bq)<<endl;
		ksi=((aq+bq)/2);	
		if(f((aq+bq)/2)){
			if(f((aq+bq)/2)*f(aq)<0){bq=((aq+bq)/2);}
			else if(f((aq+bq)/2)*f(bq)<0){aq=((aq+bq)/2);}
		}	
		
	}
	
	cout<<"Т.к. (b16-a16)/2="<<(bq-aq)/2<<"<10^(-5), то мы можем взять в качестве приблизительного значения корня x*="<<ksi<<endl;
	cout<<"Метод простой итерации\n";
	float M1=0,m1=10000,alpha;
	for(float i=a;i<=b;i+=0.5){
		if(abs(fs(i))>M1){M1=abs(fs(i));}
		if(abs(fs(i))<m1){m1=abs(fs(i));}
	}
	if(fs(a)>0 && fs(b)>0){alpha=2/(m1+M1);}
	if(fs(a)<0 && fs(b)<0){alpha=-2/(m1+M1);}
	cout<<"a="<<a<<" b="<<b<<" m1="<<m1<<" M1="<<M1<<" alpha="<<alpha<<endl;
	float*x=new float[100];int i=1;
	x[i]=2;
	cout<<"n\txn\tstop\n";
	do{
		cout<<i<<"\t"<<x[i]<<"\t"<<(abs(f(x[i]))/m1)<<endl;
		x[i+1]=x[i]-alpha*f(x[i]);
			i++;
	}while((abs(f(x[i]))/m1)>0.00001);
	cout<<"В качестве  корня можно взять x*="<<x[i-1]<<endl;
	cout<<"Метод Ньютона\n";
	float y[100];i=1;y[1]=2;
	float M2=0;m1=10000;
	for(float i=a;i<=b;i+=0.05){
		if(abs(fss(i))>M2){M2=abs(fss(i));}
		if(abs(fs(i))<m1){m1=abs(fs(i));}
	}
	cout<<"M2="<<M2<<" m1="<<m1<<endl;
	cout<<"n\txn\t|x(n)-x(n-1)|\n";
	cout<<"1\t"<<y[1]<<"\t-"<<endl;
	do{
		cout<<i<<"\t"<<y[i]<<"\t"<<abs(y[i]-y[i-1])<<endl;
		y[i+1]=y[i]-f(y[i])/fs(y[i]);
		i++;
	//	}while(f(y[i])/m1>eps);
	}while(abs(y[i]-y[i-1])>sqrt(2*m1*eps/M2));
	cout<<"Значит, в качестве приблизительного корня можно взять x*="<<y[i-1]<<endl;
	cout<<"Метод хорд\n";
	cout<<"a="<<a<<" b="<<b<<" m1="<<m1<<" M1="<<M1<<endl;
	float z[150];i=1;z[1]=2;
	cout<<"n\txn\t|x(n)-x(n-1)|\n";
	cout<<"1\t"<<z[1]<<"\t-\n";
	do{
		cout<<i<<"\t"<<z[i]<<"\t"<<z[i]-z[i-1]<<endl;
		//z[i+1]=z[i]-(f(z[i])*(z[i]-a))/(f(z[i])-f(a));
		z[i+1]=z[i]-f(z[i])*(b-z[i])/(f(b)-f(z[i]));
		i++;
	//}while(f(z[i])/m1>eps);
	}while(abs(z[i]-z[i-1])>(m1*eps	)/(M1-m1));
	cout<<"Значит, в качестве приблизительного корня можно взять x*="<<z[i-1]<<endl;
	system("pause");
	return 0;
}
