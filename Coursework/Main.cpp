#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ind=0;
int k=0;
//Abstract Factory
// Абстрактные базовые классы всех возможных видов воинов
class Infantryman
{
  public:
    virtual void info() = 0;     
    virtual ~Infantryman() {}
};
class Archer
{
  public:
    virtual void info() = 0;
    virtual ~Archer() {}
};
class Horseman
{
  public:    
    virtual void info() = 0;
    virtual ~Horseman() {}
};
// Классы всех видов воинов Римской армии
class RomanInfantryman: public Infantryman
{
  public:
    void info() { 
      cout << "RomanInfantryman" << endl; 
    }
};
class RomanArcher: public Archer
{
  public:
    void info() { 
      cout << "RomanArcher" << endl; 
    }
};
class RomanHorseman: public Horseman
{
  public:    
    void info() { 
      cout << "RomanHorseman" << endl; 
    }
};  
// Классы всех видов воинов армии Карфагена
class CarthaginianInfantryman: public Infantryman
{
  public:
    void info() { 
      cout << "CarthaginianInfantryman" << endl; 
    }
};
class CarthaginianArcher: public Archer
{
  public:
    void info() { 
      cout << "CarthaginianArcher" << endl; 
    }
}; 
class CarthaginianHorseman: public Horseman
{
  public:    
    void info() {
      cout << "CarthaginianHorseman" << endl;
    }
};
// Абстрактная фабрика для производства воинов
class ArmyFactory
{
  public:    
    virtual Infantryman* createInfantryman() = 0;
    virtual Archer* createArcher() = 0;
    virtual Horseman* createHorseman() = 0;
    virtual ~ArmyFactory() {}
};  
// Фабрика для создания воинов Римской армии
class RomanArmyFactory: public ArmyFactory
{
  public:    
    Infantryman* createInfantryman() { 
      return new RomanInfantryman; 
    }
    Archer* createArcher() { 
      return new RomanArcher; 
    }
    Horseman* createHorseman() { 
      return new RomanHorseman; 
    }
};
// Фабрика для создания воинов армии Карфагена
class CarthaginianArmyFactory: public ArmyFactory
{
  public:    
    Infantryman* createInfantryman() { 
      return new CarthaginianInfantryman; 
    }
    Archer* createArcher() { 
      return new CarthaginianArcher; 
    }
    Horseman* createHorseman() { 
      return new CarthaginianHorseman; 
    }
};
// Класс, содержащий всех воинов той или иной армии
class Army 
{
  public:    
   ~Army() {
      int i;
      for(i=0; i<vi.size(); ++i)  delete vi[i]; 
      for(i=0; i<va.size(); ++i)  delete va[i]; 
      for(i=0; i<vh.size(); ++i)  delete vh[i]; 
    }
    void info() {   
      int i;
      for(i=0; i<vi.size(); ++i)  vi[i]->info(); 
      for(i=0; i<va.size(); ++i)  va[i]->info(); 
      for(i=0; i<vh.size(); ++i)  vh[i]->info(); 
    }   
    vector<Infantryman*> vi; 
    vector<Archer*> va; 
    vector<Horseman*> vh;     
};
// Здесь создается армия той или иной стороны
class Game
{
  public:    
    Army* createArmy( ArmyFactory& factory ) {   
      Army* p = new Army;
      p->vi.push_back( factory.createInfantryman());
      p->va.push_back( factory.createArcher());
      p->vh.push_back( factory.createHorseman());
      return p;
    }   
};
//Optimistic Offline Lock
//класс элементов в таблице
class element{
public:
	int version;
	int data;
	bool changing;
	string name;
};
//таблица элементов, которую могут менять пользователи
class lane{
public:
	element*a;
	int size;
	void change();
	void del();
	bool changing;
	string us;
};
//класс пользователей, которые могут быть активны и менять данные таблицы в зависимости от своих свойств
class user{
public:
	int index;
	string name;
	bool active;
	void delel();
	void addel();
	user(char*imya){
		name=imya;
		index=ind;
		ind++;
		active=false;
	}
	user(){
		index=ind;
		ind++;
		char*q=new char[5];
		name=new char[6];
		q[0]='U';q[1]='s';q[2]='e';q[3]='r';q[4]=' ';q[5]=char(index-48);
		name=q;
		active=false;
	}
};
user*w=new user[10];
  void showusers(){
	  for(int i=0;i<k;i++){
		  cout<<w[k].index<<" - "<<w[k].name<<endl;
	  }
  }
  void pat(){
	int sel;
	int kolusers=0;
	int kolelement=0;
	int select=0;
	int*index=new int[100];
	bool*active=new bool[100];
	string*name=new string[100];
	int*data=new int[10];
	bool*sost=new bool[10];
	string*us=new string[10];
	int*extra=new int[10];
	for(int i=0;i<9;i++){
		data[i]=100+i+1;
		char*q="none";
		us[i]=q;
		sost[i]=false;
	}
	do{

		cout<<"Choose:\n1 - add user; 2 - delete user; 3 - select user; 4 - show users; \n5 - start make data; 6 - stop make data; 7 - show data; 0 - exit program:\n";
	cin>>sel;
	if(sel==1){
		index[kolusers]=kolusers;
		active[kolusers]=false;
		string imya;cout<<"Fill name of user: ";cin>>imya;
		name[kolusers]=imya;
		kolusers++;
	}
	if(sel==2){
		if(kolusers!=0){
		cout<<"Choose number of user:\n";
		for(int i=0;i<kolusers;i++){
			cout<<index[i]+1<<" - "<<name[i]<<" - ";
				if(active[i]){cout<<"active"<<endl;}
				else{cout<<"inactive"<<endl;}
		}
		int re;cin>>re;
		for(int i=re-1;i<kolusers;i++){
			index[i]=index[i+1];
			name[i]=name[i+1];
			active[i]=active[i+1];
		}
		kolusers--;}
		else{cout<<"There isn't any user.\n";}
	}
		if(sel==3){
			if(kolusers!=0){
			cout<<"Choose number of user:\n";
		for(int i=0;i<kolusers;i++){
			cout<<index[i]+1<<" - "<<name[i]<<" - ";
				if(active[i]){cout<<"active"<<endl;}
				
				else{cout<<"inactive"<<endl;}
		}
		int re;cin>>re;
		for(int i=0;i<kolusers;i++){
			if(i==(re-1)){active[i]=true;}
			//else{active[i]=false;}
		}
		select=re;}
			else{cout<<"There isn't any user.\n";}
		}
	if(sel==4){
		for(int i=0;i<kolusers;i++){
			cout<<index[i]+1<<" - "<<name[i]<<" - ";
				if(active[i]){cout<<"active"<<endl;}
				else{cout<<"inactive"<<endl;}
		}
	}
	if(sel==5){
		int anybody=0,body=0;
		for(int i=0;i<kolusers;i++){
			if(active[i]){anybody++;body=index[i];}
		}
		if(anybody){
		int re;
		cout<<"Choose number of data (1-9): ";cin>>re;
		if(sost[re-1]==false){
		sost[re-1]=true;
		us[re-1]=name[body];
		int y;cout<<"Fill new value: ";cin>>y; data[re-1]=y;
		}
		else{
			if(us[re-1]!=name[select-1]){int y;cout<<"Fill new value: ";cin>>y;
				for(int i=0;i<9;i++){
					if(i==re-1){cout<<i+1<<" - "<<y<<" - ";}
					else{
						cout<<i+1<<" - "<<data[i]<<" - ";}
			if(sost[i]){cout<<"changing by ";}
				else{cout<<"unchenging by ";}
				cout<<us[i]<<endl;
		}
				cout<<"But data willn't be saved cause it's already making by ";cout<<us[re-1]<<endl;}
			else{int y;cout<<"Fill new value: ";cin>>y; data[re-1]=y;}
		}
		
		}
		else{
			cout<<"Sorry, but there isn't active user.\n";}
	}
	if(sel==6){
		int re;
		cout<<"Choose number of data (1-9): ";cin>>re;
		if(sost[re-1]){
			if(us[re-1]==name[select-1]){sost[re-1]=false;us[re-1]="none";}
			else{cout<<"Can't stop making cause data is chenging by another user.\n";}
		}
		else{
			cout<<"Data isn't alredy changed.\n";
		}
	}
	if(sel==7){
		for(int i=0;i<9;i++){
			cout<<i+1<<" - "<<data[i]<<" - ";
			if(sost[i]){cout<<"changing by ";}
				else{cout<<"unchenging by ";}
				cout<<us[i]<<endl;
		}
	}
	}while(sel);
	
	}
int main()
{        
	int qwe;
	do{
	cout<<"Choose task: 1 - Abstract Factory, 2 - Optimistic Offline Lock, 0 - exit: ";cin>>qwe;
	if(qwe==1){
	cout<<"Abstract Factory!\n";
    Game game;
    RomanArmyFactory ra_factory;
    CarthaginianArmyFactory ca_factory;
     
    Army * ra = game.createArmy( ra_factory);
    Army * ca = game.createArmy( ca_factory);
    cout << "Roman army:" << endl;
    ra->info();
    cout << "\nCarthaginian army:" << endl;
    ca->info();
    // ...
	}
	if(qwe==2){
		int kolusers=0,index=0,re=0,sel=0,select=0;
		cout<<"\nOptimistic Offline Lock!\n";																																																																																					if(qwe==2){pat();}else{

			cout<<"Choose:\n1 - add user; 2 - delete user; 3 - select user; 4 - show users; \n5 - start make data; 6 - stop make data; 7 - show data; 0 - exit program:\n";
	cin>>sel;
	if(sel==1){
		string imya;cout<<"Fill name of user: ";cin>>imya;
		w[kolusers].name=imya;
		kolusers++;
	}
	if(sel==2){
		if(kolusers!=0){
		cout<<"Choose number of user:\n";
		for(int i=0;i<kolusers;i++){
			cout<<w[i].index+1<<" - "<<w[i].name<<" - ";
				if(w[i].active){cout<<"active"<<endl;}
				else{cout<<"inactive"<<endl;}
		}
		int re;cin>>re;
		for(int i=re-1;i<kolusers;i++){
			w[i]=w[i+1];
		}
		kolusers--;}
		else{cout<<"There isn't any user.\n";}
	}
		if(sel==3){
			if(kolusers!=0){
			cout<<"Choose number of user:\n";
		for(int i=0;i<kolusers;i++){
			cout<<w[i].index+1<<" - "<<w[i].name<<" - ";
				if(w[i].active){cout<<"active"<<endl;}
				else{cout<<"inactive"<<endl;}
		}
		int re;cin>>re;
		for(int i=0;i<kolusers;i++){
			if(i==(re-1)){w[i].active=true;}
			else{w[i].active=false;}
		}
		}
			else{cout<<"There isn't any user.\n";}
		}
	if(sel==4){
		for(int i=0;i<kolusers;i++){
			cout<<index+1<<" - "<<w[i].name<<" - ";
				if(w[i].active){cout<<"active"<<endl;}
				else{cout<<"inactive"<<endl;}
		}
	}
	if(sel==5){
		int anybody=0,body=0;
		for(int i=0;i<kolusers;i++){
			if(w[re].active){anybody++;body=index;}
		}
		if(anybody){
		int re;
		cout<<"Choose number of data (1-9): ";cin>>re;
		int y;cout<<"Fill new value: ";cin>>y; 
		{
			if(w[re].active!=w[re].active){cout<<"Can't change data cause it's already making by ";}
			else{int y;cout<<"Fill new value: ";cin>>y;y;}
		}
		
		}
		else{
			cout<<"Sorry, but there isn't active user.\n";}
	}
	if(sel==6){
		cout<<"Choose number of data (1-9): ";cin>>re;
		if(w[re].active){
			if(w[re].name==w[select-1].name){w[re].active=false;w[re].name="none";}
			else{cout<<"Can't stop making cause data is chenging by another user.\n";}
		}
		else{
			cout<<"Data isn't alredy changed.\n";
		}
	}
	if(sel==7){
		
		for(int i=0;i<9;i++){
			cout<<i+1<<" - "<<w[re].index<<" - ";
			if(w[re].active){cout<<"changing by ";}
				else{cout<<"unchenging by ";}
				cout<<w[i].active<<endl;
		}
	}
	}while(sel);
		}
	
	if(qwe==0){return 0;}
	}while(qwe);
}