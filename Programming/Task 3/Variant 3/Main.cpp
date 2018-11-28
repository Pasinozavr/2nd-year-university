#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;
int ps=0,pd=0;
class menu{
public:
	int n,i,j;
	string el[10];
	int a[10];
	int pozH,pozV;
	bool c[10];
	string b[10][10];
	bool d[10][10];
	string e[10][10][8];
	int a1,b1;
	void admin(){
		el[1]="Par-";
		el[2]="Par+";
		el[3]="Open";
		el[4]="Pseu";
		el[5]="Lib";
		el[6]="Add";
		el[7]="Del";
		el[8]="Exit";
	}
	menu(){
		pozH=1;pozV=1;
			n=5;
			
		cout<<"Sized "<<n<<" menu was created\n";
		int c1;cout<<"Fill on menu: 1 - keyboard, not 1 - standart: ";cin>>c1;
		if(c1==1){
			for(i=1;i<=10;i++){c[i]=false;}
			for(i=1;i<=n;i++){cout<<"Fill el #"<<i<<": ";cin>>el[i];cout<<"And it will have much subelements: ";int y;do{cin>>y;if(y>10){cout<<"This number can't be>10. Try again...\n";}}while(y>10);a[i]=y;}
			el[n]="Exit";
			a[n]=0;
		}
		else{
			for(i=1;i<=10;i++){c[i]=true;}
			for(i=1;i<=n;i++){el[i]="El#";el[i]+=48+i;a[i]=i;}
			for(int i=1;i<n;i++){
				for(int j=1;j<=a[i];j++){
				b[j][i]+=48+i;b[j][i]+=".";b[j][i]+=48+j;
				d[i][j]=false;
			}
			}
			el[n]="Exit";
			a[n]=0;
		}
	}
	menu(int size, char type){
		if(type=='a'){
			pozH=1;pozV=1;
			n=8;
			for(i=1;i<=10;i++){c[i]=false;}
		cout<<"Sized "<<n<<" menu was created\n";
		admin();
		}
		
		if(type=='s'){
			pozH=1;pozV=1;
			n=size;
			
		cout<<"Sized "<<n<<" menu was created\n";
		int c1;cout<<"Fill on menu: 1 - keyboard, not 1 - standart: ";cin>>c1;
		if(c1==1){
			for(i=1;i<=10;i++){c[i]=false;}
			for(i=1;i<n;i++){cout<<"Fill el #"<<i<<": ";cin>>el[i];cout<<"And it will have much subelements: ";int y;do{cin>>y;if(y>10){cout<<"This number can't be>10. Try again...\n";}}while(y>10);a[i]=y;}
			el[n]="Exit";
			a[n]=0;
		}
		else{
			for(i=1;i<=10;i++){c[i]=true;}
			for(i=1;i<=n;i++){el[i]="El#";el[i]+=48+i;a[i]=i;}
			for(int i=1;i<n;i++){
				for(int j=1;j<=a[i];j++){
				b[j][i]+=48+i;b[j][i]+=".";b[j][i]+=48+j;
				d[i][j]=false;
			}
			}
			el[n]="Exit";
			a[n]=0;
		}
		}
		if(type=='o'){
			fstream f;
		f.open("save.txt", fstream::in | fstream::out);
			if(f == NULL){cout<<"open file error!";}
			else{
				f>>n;
			for(i=1;i<=n;i++){f>>el[i];}
			for(i=1;i<=n;i++){f>>a[i];}
			for(i=1;i<=n;i++){f>>c[i];}
			f>>pozV>>pozH;	
			for(i=1;i<=n;i++){
				for(j=1;j<=a[i];j++){
				
				f>>b[j][i];}}
			for(i=1;i<n;i++){
				for(j=1;j<=a[j];j++){
					f>>d[i][j];
				}}
			for(i=1;i<n;i++){
				for(j=1;j<=a[i];j++){
					for(int z=1;z<=8;z++){
						f>>e[i][j][z];
					}}}
			f.close();
			a[n]=0;
			cout<<"open was succesful\n";}
	}
		}
	void save(){
		fstream f;
			f.open("save.txt", fstream::in | fstream::out);
			if(f == NULL){cout<<"open file error!";}
			else{
			f<<n<<"\n";
			for(i=1;i<=n;i++){f<<el[i]<<"\n";}
			for(i=1;i<=n;i++){f<<a[i]<<"\n";}
			for(i=1;i<=n;i++){f<<c[i]<<"\n";}
			f<<pozV<<"\n"<<pozH<<"\n";
			for(i=1;i<=n;i++){
				for(j=1;j<=a[j];j++){
				f<<b[j][i]<<"\n";}
			}
			for(i=1;i<n;i++){
				for(j=1;j<=a[j];j++){
					f<<d[i][j]<<endl;
				}}
			for(i=1;i<n;i++){
				for(j=1;j<=a[i];j++){
					for(int z=1;z<=8;z++){
						f<<e[i][j][z]<<endl;
					}}}
			f.close();
			cout<<"saved was succesful\n";}
	}
	void open(){
		fstream f;
		f.open("save.txt", fstream::in | fstream::out);
			if(f == NULL){cout<<"open file error!";}
			else{
				f>>n;
			for(i=1;i<=n;i++){f>>el[i];}
			for(i=1;i<=n;i++){f>>a[i];}
			for(i=1;i<=n;i++){f>>c[i];}
			
			for(i=1;i<=n;i++){
				for(j=1;j<=a[j];j++){
					
				f>>b[i][j];}}
			for(i=1;i<=n;i++){
				for(j=1;j<=a[j];j++){
					f>>d[i][j];
				}}
			for(i=1;i<=n;i++){
				for(j=1;j<=a[j];j++){
					for(int z=1;z<=8;z++){
						f>>e[i][j][z];
					}}}
			f.close();
			cout<<"open was succesful\n";}
	}
	menu(menu&m0){
		n=m0.n;
		for(int i=1;i<=10;i++){
			el[i]=m0.el[i];
			a[i]=m0.a[i];
			c[i]=m0.c[i];
			for(int j=1;j<=10;j++){
				b[i][j]=m0.b[i][j];
			}
		}
		pozH=m0.pozH;
		pozV=m0.pozV;
	}
	menu(int a2,int b2){
		pozH=1;pozV=1;
		a1=a2;b1=b2;
		n=8;

		for(i=1;i<=10;i++){c[i]=true;}
			for(i=1;i<=n;i++){el[i]="El#";el[i]+=48+i;a[i]=i;}
			for(int i=1;i<n;i++){
				for(int j=1;j<=a[i];j++){
				b[j][i]+=48+i;b[j][i]+=".";b[j][i]+=48+j;
			}
			}
			el[n]="Exit";

	}
	menu&operator=(menu&m1){
		if(ps==1){
		for(int i=a1;i<=b1;i++){
			el[i]=m1.el[i];
			a[i]=0;
			c[i]=false;
		}}
		else{
			n=m1.n;pozH=m1.pozH;pozV=m1.pozV;a1=m1.a1;b1=m1.b1;
			for(int i=1;i<=n;i++){c[i]=m1.c[i];a[i]=m1.a[i];}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=10;j++){
				b[i][j]=m1.b[i][j];
				}
				el[i]=m1.el[i];
			}

		}

		return*this;
}
	void showH(){
		for(i=1;i<=n;i++){
			cout<<i<<"."<<el[i]<<"\t";
		}
	}
	void showV(){
		for(i=1;i<=n;i++){
			cout<<i<<"."<<el[i]<<"\t";
		}
		for(i=1;i<=n;i++){
			cout<<endl;
			for(j=1;j<=10;j++){

				if(c[j]==true){if(j!=pozV || i!=pozH){if(d[i][j]==true){cout<<"!"<<b[i][j]<<"\t";}else{cout<<""<<b[i][j]<<"\t";}}else{if(d[i][j]==true){cout<<"<!"<<b[i][j]<<"\t";}else{cout<<"<"<<b[i][j]<<"\t";}}}
			else{cout<<"\t";}
			}
		}
	}
	void showG(int q,int w){
		if(d[q][w]==true){
			cout<<"Podpod: ";
			for(int i=1;i<=8;i++){
				cout<<e[q][w][i]<<" ";
			}
			cout<<"\nDo you wanna change some podpod? 1 - Y, !1 - N: ";int yp;cin>>yp;if(yp==1){
				do{cout<<"What from podpod you wanna to change?: ";cin>>yp;if(yp<1  || yp>8){cout<<"Error. Just >1 and <8, plz. Try again\n";}}while(yp<1  || yp>8);
				cout<<"Now fill this podpod: ";string podpod;cin>>podpod;
				e[q][w][yp]=podpod;
			}
		}
		else{doto(q,w);}
	}
	int cH(){
		cout<<"\nChoose number of horisontal menu: ";int c;
		do{
			cin>>c;
			if(c>n){cout<<"This number can't be>"<<n<<". Try again...\n";}
		}while(c>n);
		return c;
	}
	void move(int pozV){
		char code;
	M:
	code=getch();
	switch(getch()){	
	case 72: if(pozH!=1) pozH--;showV();goto M;//up
	case 80:  if(pozH!=a[pozV]) pozH++;showV();goto M;//down
	case 77: showG(pozH,pozV);break;
	case 75: showG(pozH,pozV);break;
	}
	
	}
	
	void add(int num){
		cout<<"Fill the name: ";string str;cin>>str;
		
		a[num]+=1;
		c[num]=true;
		b[a[num]][num]=str;
		cout<<"Added was successful\n";
	}
	void del(int num){
		cout<<"Last element of that column will be deleted\n";
		b[a[num]][num]="";
		a[num]-=1;
		c[num]=true;
		
		cout<<"Deleted was successful\n";
	}
	void doto(int q,int w){
		d[q][w]=true;
		for(int i=1;i<=8;i++){
			e[q][w][i]="Podpod";e[q][w][i]+=i+48;
		}
		cout<<"Podpod was activated and created\n";
	}
};
int main(){
	menu m0(0,'a');
	pd=1;
	menu m10(8,'o');
	pd=1;
	int r;
	do{
		m0.showH();
		r=m0.cH();
		
	if(r==1){
		menu m1;
		m10=m1;
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
		cout<<"Do you want to save this menu? 1 - Y, not 1 - N: ";int u;cin>>u;if(u==1){m10.save();}
		
		
	}
	if(r==2){
		cout<<"Enter size: ";int size;do{cin>>size;if(size>10){cout<<"Size can't be >8. try again\n";}}while(size>10);
		menu m1(size,'s');
		m10=m1;
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
		cout<<"Do you want to save this menu? 1 - Y, not 1 - N: ";int u;cin>>u;if(u==1){m10.save();}
			}
	if(r==3){
		menu m1(8,'o');
		m10=m1;
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
	}
	if(r==4){
		ps=1;
		cout<<"we will use m1(a,b)=m2; enter a: ";
		int a;do{cin>>a;if(a>3){cout<<"a must be<3. try again";}}while(a>3);
		cout<<"enter b: ";
		int b;do{cin>>b;if(b>6){cout<<"a must be<6. try again";}}while(b>6);
		menu m1(a,b);
		m1=m0;
		m10=m1;
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
		ps=0;
	}
	if(r==5){	
		cout<<"include library: ";
#include "q.h"
		cout<<"completed\n";
		menu m1;
		m10=m1;
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
		cout<<"Do you want to save this menu? 1 - Y, not 1 - N: ";int u;cin>>u;if(u==1){m10.save();}
	}
	if(r==6){
		int ny;
		do{cout<<"What's el will be added?: ";cin>>ny;if(ny<0 || ny>8){cout<<"Error. Must be >0 and <8. Try again\b";}}while(ny<0 || ny>8);
		m10.add(ny);
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
		cout<<"Do you want to save this menu? 1 - Y, not 1 - N: ";int u;cin>>u;if(u==1){m10.save();}

	}
	if(r==7){
		int ny;
		do{cout<<"What's el will be deleted?: ";cin>>ny;if(ny<0 || ny>8){cout<<"Error. Must be >0 and <8. Try again\b";}}while(ny<0 || ny>8);
		m10.del(ny);
		m10.showV();
		int d1;
		while((d1=m10.cH())!=m10.n){
			if(m10.c[d1]==false){
			m10.c[d1]=true;
			for(int i=1;i<=m10.a[d1];i++){
				cout<<"Fill element #"<<i<<": ";cin>>m10.b[i][d1];
			}
			}
			else{
				m10.pozV=d1;
				m10.showV();
				m10.move(d1);
			}
		};
		m10.showV();
		cout<<"Do you want to save this menu? 1 - Y, not 1 - N: ";int u;cin>>u;if(u==1){m10.save();}
	}
	}while(r!=m0.n);

	cout<<endl;	system("pause");
	return 0;
}