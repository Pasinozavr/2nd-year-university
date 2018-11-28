#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
	
class stack{
public:
int top;
int num[100];
int size;
int i;
//����������� ��� ����������
stack()
{
	top=-1;
	size=10;
	for(i=0;i<size;i++){
		num[i]=0;
	}
	cout<<"������ ���� ������� "<<size<<"\n";
}
//����������� � �����������
stack(int sizeU)
{
	top=-1;
	size=sizeU;
	for(i=0;i<size;i++){
		num[i]=0;
	}
	cout<<"������ ���� ������� "<<size<<"\n";
}
//����������� �����������
stack(const stack&s1)
{
	top=s1.top;
	size=s1.size;
	for(i=0;i<size;i++)
	{
		num[i]=s1.num[i];
	}
}
//���������� []//
int&operator[](int j)
	{
		return num[j];
	}
//���������� =//
stack&operator=(stack s1)
	{
		
		size=s1.size;
	
		for(int i=0;i<size;i++)
		{
			num[i]=s1.num[i];
		}
		return*this;
	}
//���������� ->//
int&operator->()
{
	stack s1;
	return s1.num[top];
}
//pseudo//
stack&operator=(int a){
		stack s2; 
		int sel=a;int count=10+rand()%9;
		cout<<"����� �������� � ����� ����� ��������� ��������: "<<count<<"\n";
		for(int i=0;i<10;i++){
			s2.push(pop());
		}
		for(int t=0;t<10;t++){
			push(s2.pop());
			if(t==(9-sel)){push(count);s2.pop();}
		}
		return*this;
}
stack(int i1, int j1, stack s1){
	top=-1;
	size=10;
	for(i=0;i<size;i++){
		num[i]=0;
	}
	for(i=(i1);i<i1+j1;i++){
		num[i]=s1.num[i];
	}
}
//�-� ������//
void push(float el)
{
if(top!=size){
	top=top+1;
num[top]=el;
}
else{cout<<"���� �����. ��������� �� �������.\n";}
}
float pop()
{
float el;
top--;
el=num[top+1];
num[top+1]=0;
return el;
}
void show()
{
	cout<<" | ";
	for(i=size-1;i>=0;i--){
		cout<<num[i]<<" | ";
	}
	cout<<endl;
}
void zero(){
	for(i=0;i<size;i++){
		num[i]=0;
	}
	top=-1;
	cout<<"���� ��� ������� ������\n";
}
void zero(int x){
	for(i=0;i<size;i++){
		if(i!=x){
			num[i]=0;}
	}
	top=-1;
}
};
//"��������������" �-�//
int pick(){
	char s;
	cout<<"������� ������ 'y', ���� �� � ����� ������, ���� ���\n�������� �����: ";
	cin>>s;
	if(s=='y'){return 1;}
	else{return 0;}
}
void bye(){
	cout<<"�� �������!\n";
}
void work(stack s1){
	char formula[100];
	cout<<"������ �� ������ ������ ���������. �������� �� ������� ��� �������?\n";
	if(pick()==1){
		cout<<"������� ���������:\n";
		cin.ignore();
		cin.getline(formula,200);
	cout<<"������ �� �� ��������� ��� ��������� � �����?\n";
	if(pick()==1){
			fstream f;
			f.open("save.txt", fstream::in | fstream::out);
			if(f == NULL){cout<<"������ �������� �����!";}
			f<<formula;
			f.close();
	}
	}
	
	else
	{
		cout<<"��������� ����� ������� �� ������������ ����� save.txt\n";
			fstream f;
			f.open("save.txt", fstream::in | fstream::out);
			if(f==NULL){cout<<"������ �������� �����!\n";}
			f.getline(formula,200);
			cout<<"�� ������� ������: "<<formula<<endl;
			f.close();
		}
	cout<<"������� ��������� ���������...\n";
	int len=strlen(formula);
	for(int t=0;t<len;t++){
		cout<<t+1<<"-� ������: '"<<formula[t]<<"' - ";
		if(formula[t]!='1' && formula[t]!='2' && formula[t]!='3' && formula[t]!='4' && formula[t]!='5' && formula[t]!='6' && formula[t]!='7' && formula[t]!='8' && formula[t]!='9' && formula[t]!='0' && formula[t]!='+' && formula[t]!='*' && formula[t]!='-'){
			cout<<"������������ �� �������������\n";
		}
		if(formula[t]=='1' || formula[t]=='2' || formula[t]=='3' || formula[t]=='4' || formula[t]=='5' || formula[t]=='6' || formula[t]=='7' || formula[t]=='8' || formula[t]=='9' || formula[t]=='0')
		{
			cout<<"����� � ��������� � ����\n";
				s1.push(int(formula[t]-48));
				s1.show();
		}
		if(formula[t]=='+'){
			cout<<"�������� � ���������� ��� ���������� �����\n";
			int a=s1.pop(); cout<<"������� ������ ������� ��� ��������: "<<a<<endl; 
			s1.show();
			int b=s1.pop(); cout<<"������� ������ ������� ��� ��������: "<<b<<endl; 
			s1.show();
			int result=a+b;
			cout<<a<<"+"<<b<<"="<<result<<endl;
			s1.push(result);
			s1.show();
		}
		if(formula[t]=='-'){
			cout<<"�������� � ���������� ��� ���������� �����\n";
			int a=s1.pop(); cout<<"������� ������ ������� ��� ��������: "<<a<<endl; 
			s1.show();
			int b=s1.pop(); cout<<"������� ������ ������� ��� ��������: "<<b<<endl; 
			s1.show();
			int result=a-b;
			cout<<a<<"-"<<b<<"="<<result<<endl;
			s1.push(result);
			s1.show();
		}
		if(formula[t]=='*'){
			cout<<"�������� � ���������� ��� ���������� �����\n";
			int a=s1.pop(); cout<<"������� ������ ������� ��� ��������: "<<a<<endl; 
			s1.show();
			int b=s1.pop(); cout<<"������� ������ ������� ��� ��������: "<<b<<endl; 
			s1.show();
			int result=a*b;
			cout<<a<<"*"<<b<<"="<<result<<endl;
			s1.push(result);
			s1.show();
		}
	}
	cout<<"��������� ��������� ���������\n";
	if(s1.top!=0){
		cout<<"������ ���������� ��������� �� ���������\n�.�. ���-�� �������� ������ ���-�� ����\n������� �� ����� ����� ���� ��������� ������� �����: ";
		int score=s1.pop();
		cout<<score<<endl;
		cout<<"�������� �����:";
		s1.zero();
		s1.show();
	}
	else{
		cout<<"�����: ";
		int score=s1.pop();
		cout<<score<<endl;
		cout<<"�������� �����:\n���� � ��� ����";
		s1.show();
	}
}

//������� �-�//
int main(){
	setlocale(LC_ALL, "rus");
	cout<<"������������, ������������! ������� �� �� ������ ������ � �������?\n";
	
	if(pick()==0)
	{
		bye();
	}
	
	else
	{
	cout<<"����, �� ����� �������� �� ������\n������ �� �� ���������� ��� �������?\n";
	
	if(pick()==0)
	{
		stack s1;
		work(s1);
	}
	else
	{
		int max;
		cout<<"����� ����� ������������ ������ �����?\n�������� �����: ";
		cin>>max;
		stack s1(max);
		work(s1);
	}
	cout<<"������ �� �� ���������� � �����������������?\n";
	if(pick()==1)
	{
		int a;
		cout<<"� ����� ������ ��� ����������� ��� �����:\n";
		stack s1;
		stack s2;
		cout<<"������ ������ �� ��� ����� ���������\n������� �� �� ������� ��� �������?\n";
		if(pick()==1){
			cout<<"����� �������:\n";
			for(int t=0;t<10;t++){
				cout<<t<<"-� �������: ";cin>>a;s1.push(a);
			}
			cout<<"�������, ������ ������ ���� ��������:\n";
			s1.show();
		}
		else{
			cout<<"����� ������ ���� ����� �������� ���������� �������:\n";
			for(int t=0;t<10;t++){
				s1.push(1+rand()%10);
			}
			s1.show();
		}
		cout<<"������, ��-������, �������� �������� i �� 1 �� 10 (� �����): ";
		int sel;cin>>sel;
		cout<<"����� �������� � ����� ����� ��������� ��������: ";
		int count;cin>>count;
		for(int i=0;i<10;i++){
			s2.push(s1.pop());
		}
		cout<<"�����:\n";s1.show();s2.show();

		for(int t=0;t<10;t++){
			s1.push(s2.pop());
			if(t==(9-sel)){s1.push(count);s2.pop();cout<<"�����:\n";s1.show();s2.show();}
		}
		cout<<"�����:\n";s1.show();s2.show();
	cout<<"��-������, ������ �� �������� �-� s1(i,j)=s2\n��� � ����� s1 ������� � i-�� �������\nj ��������� ���������� �� ���� s2\n";
	cout<<"��� ����� ������� i: ";int i;cin>>i;
	cout<<"� ������� j: ";int j;cin>>j;
	cout<<"��� ����������� ���� �� �������� ����� ��������� �����, ������ �� - �� �������\n";
	cout<<"������� �����:\n";
	s1.zero();
	s2.zero();
	
	for(int t=0;t<10;t++){
				s1.push(t+1);
			}
	for(int t=0;t<10;t++){
				s2.push((t+1)*(t+1));
			}
	cout<<"�����:\n";s1.show();s2.show();
	cout<<"��� ���������� ����� �������� ������ ����\n";
	stack s3;
	cout<<"�����:\n";s1.show();s2.show();s3.show();
	int t;
	for(t=0;t<10-j-i+1;t++){
		s3.push(s1.pop());
	}
	cout<<"�����:\n";s1.show();s2.show();s3.show();
	for(t=0;t<j;t++){s1.pop();}
	cout<<"�����:\n";s1.show();s2.show();s3.show();

	for(t=0;t<10-(i+j-1);t++)
	{
		s2.pop();
	}
	cout<<"�����:\n";s1.show();s2.show();s3.show();
	for(t=0;t<j;t++){
		s3.push(s2.pop());
	}
	cout<<"�����:\n";s1.show();s2.show();s3.show();
	for(t=0;t<10-i+j-1;t++){
		s1.push(s3.pop());
	}
	cout<<"�����:\n";s1.show();s2.show();s3.show();
	s1.zero();s2.zero();s3.zero();
	}
	
cout<<"�������� �� ���������� � ����������� lib?\n";
if(pick()==0){}
else{
#include "function.h"
	stack s2;
	work(s2);
	cout<<"��� ������, ���� ��� ������ � ��������� �� ����������, ��� ����������� ���������..\n";
}
stack s1;s1.show();
cout<<"������ � ����������������� ��������. ����� 1.\n ������� ����� ��������: ";
int e;cin>>e;
s1=e;
cout<<"�����\n";s1.show();
cout<<"����� 2.\n ������� i: ";int i2;cin>>i2;
cout<<"������� j: ";int j2; cin>>j2;
stack s2(i2,j2,s1);s1=s2;
s1.show();
cout<<"��� ������, ���� ��� ������ ��������� � ���������������� ��� �������� ��������.\n";
}
	system("pause");
	return 0;
	}