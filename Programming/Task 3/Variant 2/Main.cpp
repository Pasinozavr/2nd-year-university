#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int k=1;
int min( int a, int b ) { 
return a < b ? a : b; 
}
int max( int a, int b ) { 
return a > b ? a : b; 
}
class map{
public:
	//список того, что будет содержать каждый объект
	string name;
	int i[100];
	double d[100];
	string s[100];
	char type[2];
	int n;int a1,b1;
	bool v;
	//конструктор без параметра
	map(){
		n=5;
		if(k!=1){cout<<"Map with standart size 5 was created\n";}
		}
	//конструктор с параметром кол-ва элементов отображения
	map(int kol){
		n=kol;
		cout<<"Map with special size "<<n<<" was created\n";
	}
	fstream&operator>>(map&m1){
		fstream f;
			f.open("save.txt", fstream::in | fstream::out);

			f>>m1.name>>m1.n>>m1.type[1]>>m1.type[2];
			for(int j=1;j<=n;j++){
			if(type[1]=='s'){f>>m1.s[j];}
			else if(type[1]=='d'){f>>m1.d[j];}
			else{f>>m1.i[j];}
		}
				cout << "fout was succesful\n";
	}
	fstream&operator<<(map&m1){
		fstream f;
			f.open("save.txt", fstream::in | fstream::out);

			f<<m1.name<<endl<<m1.n<<endl<<m1.type[1]<<endl<<m1.type[2];
			for(int j=1;j<=n;j++){
			if(type[1]=='s'){f<<m1.s[j]<<endl;}
			else if(type[1]=='d'){f<<m1.d[j]<<endl;}
			else{f<<m1.i[j]<<endl;}
		}
				cout << "fin was succesful\n";
	}
	void fill(){
		v=false;
		int t;
		cout<<"Enter name: ";cin>>name;
		cout<<"Please, choose the types...\nFill the input data type - 1 for int, 2 for double, else - for string: ";
		cin>>t;
		if(t==1){type[1]='i';}
		else if(t==2){type[1]='d';}
		else{type[1]='s';}
		do{
		cout<<"Fill the output data type, but remember they must not be repeated: ";
		cin>>t;
		if(t==1){type[2]='i';}
		else if(t==2){type[2]='d';}
		else{type[2]='s';}
		if(type[1]==type[2]){cout<<"Sorry, but types are repeated. Try to choose the output data type again...\n";}
		}while(type[1]==type[2]);
		cout<<"So, this map will have types: ";
		if(type[1]=='s'){cout<<"string - ";}else if(type[1]=='i'){cout<<"integer - ";}else{cout<<"double - ";}
		if(type[2]=='s'){cout<<"string\n";}else if(type[2]=='i'){cout<<"integer\n";}else{cout<<"double\n";}
		for(int j=1;j<=n;j++){
			cout<<j<<"el -- ";
			if(type[1]=='s'){
				cin>>s[j];
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				cin>>i[j];if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				cin>>d[j];
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}

		}
	}
	void fill(int nu){
		v=false;
		n=nu;
		int t;
		cout<<"Enter name: ";cin>>name;
		cout<<"Please, choose the types...\nFill the input data type - 1 for int, 2 for double, else - for string: ";
		cin>>t;
		if(t==1){type[1]='i';}
		else if(t==2){type[1]='d';}
		else{type[1]='s';}
		do{
		cout<<"Fill the output data type, but remember they must not be repeated: ";
		cin>>t;
		if(t==1){type[2]='i';}
		else if(t==2){type[2]='d';}
		else{type[2]='s';}
		if(type[1]==type[2]){cout<<"Sorry, but types are repeated. Try to choose the output data type again...\n";}
		}while(type[1]==type[2]);
		cout<<"So, this map will have types: ";
		if(type[1]=='s'){cout<<"string - ";}else if(type[1]=='i'){cout<<"integer - ";}else{cout<<"double - ";}
		if(type[2]=='s'){cout<<"string\n";}else if(type[2]=='i'){cout<<"integer\n";}else{cout<<"double\n";}
		for(int j=1;j<=n;j++){
			cout<<j<<"el -- ";
			if(type[1]=='s'){
				cin>>s[j];
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				cin>>i[j];if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				cin>>d[j];
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}

		}
	}
	void fill(map&s1,map&s2){
		v=false;
		type[1]=s1.type[1];type[2]=s2.type[2];
		n=max(s1.n,s2.n);
		cout<<"Enter name: ";cin>>name;
		for(int j=1;j<=min(s1.n,s2.n);j++){
			if(s1.n<s2.n){
				i[j]=s1.i[j];
				d[j]=s1.d[j];
				s[j]=s1.s[j];
			}
			else{
				i[j]=s2.i[j];
				d[j]=s2.d[j];
				s[j]=s2.s[j];
			}
		}
		for(int j=min(s1.n,s2.n)+1;j<=n;j++){
			if(s1.n>s2.n){
				i[j]=s1.i[j];
				d[j]=s1.d[j];
				s[j]=s1.s[j];
			}
			else{
				i[j]=s2.i[j];
				d[j]=s2.d[j];
				s[j]=s2.s[j];
			}
		}
	}
	void fill(map&s1){
		v=false;
	type[1]=s1.type[1];type[2]=s1.type[2];
		n=s1.n;
		for(int j=1;j<=s1.n;j++){
				i[j]=s1.i[j];
				d[j]=s1.d[j];
				s[j]=s1.s[j];
		}
	}
	void fill(string o){
		v=false;
		string save;
		cout<<"Fill the name of file for opening (without .txt): ";cin>>save;
		save+=".txt";
		const char* p = save.c_str();		
		FILE *file;
		file=fopen(p,"r"); 
		char str[10];
		fgets(str,80, file); 
		str[strlen(str)-1]='\0';
		name=(const char*)str;
		fscanf(file,"%d\n%c\n%c\n",&n,&type[1],&type[2]);
		for(int j=1;j<=n;j++){
			if(type[1]=='s'){
				//fscanf(file,"%s ",s[j].c_str());}
				fgets(str,80,file);
				str[strlen(str)-1]='\0';
				s[j]=(const char*)str;
				//strcpy(str,s[j].c_str());
			}
			else if(type[1]=='d'){fscanf(file,"%f\n",&d[j]);}
			else{fscanf(file,"%d\n",&i[j]);}
		}
	fclose(file);

		for(int j=1;j<=n;j++){
			
			if(type[1]=='s'){
				
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}
		}
	}
	void fill(char m){
		v=true;//v=false;
		int t;
		cout<<"Enter name: ";cin>>name;
		cout<<"Please, choose the types...\nFill the input data type - 1 for int, 2 for double, else - for string: ";
		cin>>t;
		if(t==1){type[1]='i';}
		else if(t==2){type[1]='d';}
		else{type[1]='s';}
		do{
		cout<<"Fill the output data type, but remember they must not be repeated: ";
		cin>>t;
		if(t==1){type[2]='i';}
		else if(t==2){type[2]='d';}
		else{type[2]='s';}
		if(type[1]==type[2]){cout<<"Sorry, but types are repeated. Try to choose the output data type again...\n";}
		}while(type[1]==type[2]);
		cout<<"So, this map will have types: ";
		if(type[1]=='s'){cout<<"string - ";}else if(type[1]=='i'){cout<<"integer - ";}else{cout<<"double - ";}
		if(type[2]=='s'){cout<<"string\n";}else if(type[2]=='i'){cout<<"integer\n";}else{cout<<"double\n";}

		for(int j=1;j<=n;j++){
			cout<<j<<"el -- ";
			if(type[1]=='s'){
				cin>>s[j];
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				cin>>i[j];if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				cin>>d[j];
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}

		}
		cout<<"We will use function map s1(a,b)=s2..\n";
		cout<<"Now, enter the a: ";int a;cin>>a;
		cout<<"And b: ";int b;cin>>b;
		a1=a;b1=b;
	}
	//деструктор
	~map(){
	delete[]i;delete[]d;delete[]s;delete[]type;n=0;k--;
	name="Deleted";	
	}
	//ф-я вывода на экран
	void show(){
		cout<<"Map '"<<name<<"'\n";
		if(type[1]=='s'){cout<<"string -- ";}else if(type[1]=='i'){cout<<"integer -- ";}else{cout<<"double -- ";}
		if(type[2]=='s'){cout<<"string\n";}else if(type[2]=='i'){cout<<"integer\n";}else{cout<<"double\n";}
		for(int j=1;j<=n;j++){
			if(type[1]=='s'){cout<<s[j]<<" --\t";}else if(type[1]=='i'){cout<<i[j]<<" --\t";}else{cout<<d[j]<<" --";}
			if(type[2]=='s'){cout<<s[j]<<"\n";}else if(type[2]=='i'){cout<<i[j]<<"\n";}else{cout<<d[j]<<"\n";}
		}
	}
	//перегрузка =
	map&operator=(map&s1){
		if(v==false){
		name=s1.name;
		n=s1.n;
		type[1]=s1.type[1];
		type[2]=s1.type[2];
		for(int j=1;j<=n;j++){
			i[j]=s1.i[j];
			d[j]=s1.d[j];
			s[j]=s1.s[j];
		}}
		else{
		for(int j=a1;j<=b1;j++){
			i[j]=s1.i[j];
			d[j]=s1.d[j];
			s[j]=s1.s[j];
		}
		}
		return*this;
	}
	//комбинация
	map(map&s1,map&s2){
		type[1]=s1.type[1];type[2]=s2.type[2];
		n=max(s1.n,s2.n);
		cout<<"Enter name: ";cin>>name;
		for(int j=1;j<=min(s1.n,s2.n);j++){
			if(s1.n<s2.n){
				i[j]=s1.i[j];
				d[j]=s1.d[j];
				s[j]=s1.s[j];
			}
			else{
				i[j]=s2.i[j];
				d[j]=s2.d[j];
				s[j]=s2.s[j];
			}
		}
		for(int j=min(s1.n,s2.n)+1;j<=n;j++){
			if(s1.n>s2.n){
				i[j]=s1.i[j];
				d[j]=s1.d[j];
				s[j]=s1.s[j];
			}
			else{
				i[j]=s2.i[j];
				d[j]=s2.d[j];
				s[j]=s2.s[j];
			}
		}
	}
	map(int a,int b){
		int t;
		cout<<"Enter name: ";cin>>name;
		cout<<"Please, choose the types...\nFill the input data type - 1 for int, 2 for double, else - for string: ";
		cin>>t;
		if(t==1){type[1]='i';}
		else if(t==2){type[1]='d';}
		else{type[1]='s';}
		do{
		cout<<"Fill the output data type, but remember they must not be repeated: ";
		cin>>t;
		if(t==1){type[2]='i';}
		else if(t==2){type[2]='d';}
		else{type[2]='s';}
		if(type[1]==type[2]){cout<<"Sorry, but types are repeated. Try to choose the output data type again...\n";}
		}while(type[1]==type[2]);
		cout<<"So, this map will have types: ";
		if(type[1]=='s'){cout<<"string - ";}else if(type[1]=='i'){cout<<"integer - ";}else{cout<<"double - ";}
		if(type[2]=='s'){cout<<"string\n";}else if(type[2]=='i'){cout<<"integer\n";}else{cout<<"double\n";}
		a1=a;b1=b;
	}
	map(char m){
		int t;
		cout<<"Enter name: ";cin>>name;
		cout<<"Please, choose the types...\nFill the input data type - 1 for int, 2 for double, else - for string: ";
		cin>>t;
		if(t==1){type[1]='i';}
		else if(t==2){type[1]='d';}
		else{type[1]='s';}
		do{
		cout<<"Fill the output data type, but remember they must not be repeated: ";
		cin>>t;
		if(t==1){type[2]='i';}
		else if(t==2){type[2]='d';}
		else{type[2]='s';}
		if(type[1]==type[2]){cout<<"Sorry, but types are repeated. Try to choose the output data type again...\n";}
		}while(type[1]==type[2]);
		cout<<"So, this map will have types: ";
		if(type[1]=='s'){cout<<"string - ";}else if(type[1]=='i'){cout<<"integer - ";}else{cout<<"double - ";}
		if(type[2]=='s'){cout<<"string\n";}else if(type[2]=='i'){cout<<"integer\n";}else{cout<<"double\n";}
		cout<<"Now, enter the a: ";int a;cin>>a;
		cout<<"And b: ";int b;cin>>b;
		a1=a;b1=b;
	}
	void change(){
		cout<<"What do you wanna do: 1 - add element, 2 - change exiting elemetnts smth else - delete: ";int nu;cin>>nu;
		if(nu==1){
			n++;
			int j=n;
			cout<<j<<"el -- ";
			if(type[1]=='s'){
				cin>>s[j];
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				cin>>i[j];if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				cin>>d[j];
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}
		}
		else if(nu==2){
			cout<<"Choose the number of changing element:";int h;cin>>h;
			cout<<"OK, now fill it: ";
			int j=h;h++;
			if(type[1]=='s'){
				cin>>s[j];
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				cin>>i[j];if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				cin>>d[j];
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}
		}
		else{
			if(n!=0){
			int o;
			do{cout<<"Choose the number of deleting element: ";cin>>o;if(o<1 || o>n){cout<<"Number must be >0 and <"<<n<<endl;}}while(o<1 || o>n);
			for(int j=o;j<n;j++){
			i[j]=i[j+1];
			d[j]=d[j+1];
			s[j]=s[j+1];
			}
			n--;
		}
			else{
				cout<<"There isn't elements for deleting\n";
			}
		}
	}
	void changeR(){
		cout<<"Enter the number of changin element: ";int t;cin>>t;
		if(type[2]=='s'){cout<<"Now enter the string: ";cin>>s[t];}
		else if(type[2]=='i'){cout<<"Now enter the integer: ";cin>>i[t];}
		else{cout<<"Now enter the double: ";cin>>d[t];}
		cout<<"Changing OK\n";
	}
	void save(){
		string save;
		cout<<"Fill the name of file for saving (without .txt): ";cin>>save;
		save+=".txt";
		const char* p = save.c_str();		
		FILE *file;
		file=fopen(p,"w"); 
		fprintf(file,"%s\n%d\n%c\n%c\n",name.c_str(),n,type[1],type[2]);
		for(int j=1;j<=n;j++){
			if(type[1]=='s'){fprintf(file,"%s\n",s[j].c_str());}
			else if(type[1]=='d'){fprintf(file,"%f\n",d[j]);}
			else{fprintf(file,"%d\n",i[j]);}
		}
		//SUDA
		fclose(file);

	}
	void open(){
		string save;
		cout<<"Fill the name of file for opening (without .txt): ";cin>>save;
		save+=".txt";
		const char* p = save.c_str();		
		FILE *file;
		file=fopen(p,"r"); 
		char str[10];
		fgets(str,80, file); 
		str[strlen(str)-1]='\0';
		name=(const char*)str;
		fscanf(file,"%d\n%c\n%c\n",&n,&type[1],&type[2]);
		for(int j=1;j<=n;j++){
			if(type[1]=='s'){
				//fscanf(file,"%s ",s[j].c_str());}
				fgets(str,80,file);
				str[strlen(str)-1]='\0';
				s[j]=(const char*)str;
				//strcpy(str,s[j].c_str());
			}
			else if(type[1]=='d'){fscanf(file,"%f\n",&d[j]);}
			else{fscanf(file,"%d\n",&i[j]);}
		}
	fclose(file);

		for(int j=1;j<=n;j++){
			
			if(type[1]=='s'){
				
				if(type[2]=='i'){i[j]=100+rand()%1000;}
				else{d[j]=rand()%100+rand()%10+(rand()%100)/1000;}
			}
			else if(type[1]=='i'){
				if(i[j]<0){i[j]*=-1;}
				if(type[2]=='s'){s[j]=char(i[j]);}
				else{d[j]=i[j];do{d[j]/=2;}while(d[j]>=1);}
			}
			else{
				
				if(type[2]=='s'){
					if(int(d[j])==13){s[j]+=char(int(d[j]+1));s[j]+=char(d[j]*10);}
					else{
						s[j]+=char(int(d[j]));s[j]+=char(d[j]*10);}}
				else{i[j]=int(d[j])+((d[j])*100);}
			}
		}
	}
	
	};
	//вывод вида {map a;cout<<a}
	std::ostream& operator << (std::ostream& os,map&s1) {
		string report;
		report+="Map '"+s1.name+"'\n";
		if(s1.type[1]=='s'){report+="string -- ";}else if(s1.type[1]=='i'){report+="integer -- ";}else{report+="double -- ";}
		if(s1.type[2]=='s'){report+="string\n";}else if(s1.type[2]=='i'){report+="integer\n";}else{report+="double\n";}
		for(int j=1;j<=s1.n;j++){
			if(s1.type[1]=='s'){report+=s1.s[j];report+=" --\t";}else if(s1.type[1]=='i'){report+=s1.i[j];report+=" --\t";}else{report+=s1.d[j];report+=" --";}
			if(s1.type[2]=='s'){report+=s1.s[j];report+="\n";}else if(s1.type[2]=='i'){report+=s1.i[j];report+="\n";}else{report+=s1.d[j];report+="\n";}
		}
		return os<<report;
}

int menu(){
	int c;
	k--;
	do{
		
	cout<<"==Menu==\n1.Create map with standart size\n2.Create map with special size\n3.Create map as copy\n4.Create map as combination\n5.Change existing map\n6.Delete existing map\n7.Save in file\n8.Open from file\n9.Use pseudo\n10.Use library\n11. Show the map\n12.Change right part\nsmth else - exit\nChoose number: ";
	cin>>c;
	//проверка по кол-ву существующих объектов
	if(c==3 && k<1){cout<<"Can't create nem map cause haven't parent. Try again\n";}
	if(c==4 && k<2){cout<<"Can't create combination cause haven't parents. Try again\n";}
	if((c==5 && k<1) || (c==6 && k<1)){cout<<"Can't change map cause haven't exiting map\n";}
	if(c==7 && k<1){cout<<"Can't save map cause haven't exiting map\n";}
	if(c==9 && k<1){cout<<"Can't use pseudo without parent\n";}
	}while((c==3 && k<1)||(c==4 && k<2)||(c==5 && k<1)||(c==6 && k<1)||(c==7 && k<1) || (c==9 && k<1));
	k++;
	return c;
}
int main(){
	//автоматическая рандомизация
	srand(time(0));
	map*a=new map[100];
	int q;
	do{
	q=menu();
	if (q==1){
		a[k].fill();
		k++;
		//АНДРЕЙ, ВОТ ЭТА ФИГНЯ С ВЫВОДОМ И ОНА РАБОТАЕТ, ЕСЛИ НУЖНО БУДЕТ РАСКОММЕНТИ
		//cout<<a[k-1];
		//
	}
	if(q==2){
		int nu;
		do{cout<<"Enter the number of map's elements: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <10";}}while(nu<1 && nu>10);
		a[k].fill(nu);
		k++;
	}
	if(q==3){
		cout<<"Choose the parent map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);
		a[k]=a[nu];
		k++;
	}
	if(q==4){
		cout<<"Choose the parent #1 map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu1;
		do{cout<<"Enter the number: ";cin>>nu1;if(nu1<1&&nu1>10){cout<<"Number must be >1 and <"<<k;}}while(nu1<1 && nu1>k);

		cout<<"Choose the parent #2 map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu2;
		do{cout<<"Enter the number: ";cin>>nu2;if(nu2<1&&nu2>10){cout<<"Number must be >1 and <"<<k;}}while(nu2<1 && nu1>2);
		if(a[nu1].type[1]!=a[nu2].type[1] || a[nu2].type[2]!=a[nu1].type[2]){cout<<"Sorry, but i-o types aren't repeated.";}
		else{
			a[k].fill(a[nu1],a[nu2]);
			k++;
		}
	}
	if(q==5){
		cout<<"Choose the map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);
		a[nu].change();
	}
	if(q==6){
		cout<<"Choose the map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);
		for(int j=nu;j<k;j++){
			a[j].fill(a[j+1]);
		}
		k--;
	}
	if(q==7){
		cout<<"Choose the map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);
		a[nu].save();
		}
	if(q==8){
		string o;
		a[k].fill(o);
		k++;
	}
	if(q==9){
		char t='t';
		a[k].fill(t);

		cout<<"Choose the parent map from list: \n";
		for(int j=0;j<k;j++){
			cout<<j+1<<"."<<a[j+1].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);

		if(a[nu].type[1]!=a[k].type[1] || a[nu].type[2]!=a[k].type[2]){cout<<"Sorry, but i-o types aren't repeated.\n";}
		if(a[k].v==false){
		cout<<"Now, enter the a: ";int r;cin>>r;
		cout<<"And b: ";int b;cin>>b;
			map q(r,b);
			a[k]=q;
			k++;
		}
		a[k]=a[nu];
		k++;
	}
	if(q==10){
//#include "functions.h";
		cout<<"Library was added well done\n";
	}
	if(q==11){
		k--;
		if(k){
		cout<<"Choose the map from list: \n";
		for(int j=0;j<k;j++){
			cout<<j+1<<"."<<a[j+1].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);
		a[nu].show();
		k++;}
		else{cout<<"There are'n maps\n";}
	}
	if(q==12){
		cout<<"Choose the map from list: \n";
		for(int j=1;j<k;j++){
			cout<<j<<"."<<a[j].name<<endl;
		}
		int nu;
		do{cout<<"Enter the number: ";cin>>nu;if(nu<1&&nu>10){cout<<"Number must be >1 and <"<<k;}}while(nu<1 && nu>k);
		a[nu].changeR();
	}
	}while(q<=12);
	return 0;
}