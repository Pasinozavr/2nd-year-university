#include <iostream>
#include "mod2.h"
int sum(int x, int y);
using namespace std;
int main(int argc, char*argv[]){
	int s=0;
	int p=1;
	cout<<"Hello, World!"<<endl;
	cout<<"Numbers were writed onto the console:"<<endl;
	for(int i=1;i<argc;i++){
		cout<<atoi(argv[i])<<endl;
		s=sum(s,atoi(argv[i]));
		p=umn(p,atoi(argv[i]));
	}
	cout<<"Sum="<<s<<endl;
	cout<<"Product="<<p<<endl;
	system("pause");
	return 0;
}