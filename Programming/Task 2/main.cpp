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
//конструктор без параметров
stack()
{
	top=-1;
	size=10;
	for(i=0;i<size;i++){
		num[i]=0;
	}
	cout<<"Создан стек размера "<<size<<"\n";
}
//конструктор с параментром
stack(int sizeU)
{
	top=-1;
	size=sizeU;
	for(i=0;i<size;i++){
		num[i]=0;
	}
	cout<<"Создан стек размера "<<size<<"\n";
}
//конструктор копирования
stack(const stack&s1)
{
	top=s1.top;
	size=s1.size;
	for(i=0;i<size;i++)
	{
		num[i]=s1.num[i];
	}
}
//перегрузка []//
int&operator[](int j)
	{
		return num[j];
	}
//перегрузка =//
stack&operator=(stack s1)
	{
		
		size=s1.size;
	
		for(int i=0;i<size;i++)
		{
			num[i]=s1.num[i];
		}
		return*this;
	}
//перегрузка ->//
int&operator->()
{
	stack s1;
	return s1.num[top];
}
//pseudo//
stack&operator=(int a){
		stack s2; 
		int sel=a;int count=10+rand()%9;
		cout<<"Этому элементу в стеке будет присвоено значение: "<<count<<"\n";
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
//ф-и класса//
void push(float el)
{
if(top!=size){
	top=top+1;
num[top]=el;
}
else{cout<<"Стек полон. Занесение не удалось.\n";}
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
	cout<<"Стек был успешно очищен\n";
}
void zero(int x){
	for(i=0;i<size;i++){
		if(i!=x){
			num[i]=0;}
	}
	top=-1;
}
};
//"дополнительные" ф-и//
int pick(){
	char s;
	cout<<"Введите символ 'y', если да и любой другой, если нет\nОжидание ввода: ";
	cin>>s;
	if(s=='y'){return 1;}
	else{return 0;}
}
void bye(){
	cout<<"До встречи!\n";
}
void work(stack s1){
	char formula[100];
	cout<<"Теперь Вы должны ввести выражение. Желатете ли сделать это вручную?\n";
	if(pick()==1){
		cout<<"Введите выражение:\n";
		cin.ignore();
		cin.getline(formula,200);
	cout<<"Хотите ли Вы сохранить это выражение в файле?\n";
	if(pick()==1){
			fstream f;
			f.open("save.txt", fstream::in | fstream::out);
			if(f == NULL){cout<<"Ошибка открытия файла!";}
			f<<formula;
			f.close();
	}
	}
	
	else
	{
		cout<<"Выражение будет считано из стандратного файла save.txt\n";
			fstream f;
			f.open("save.txt", fstream::in | fstream::out);
			if(f==NULL){cout<<"Ошибка открытия файла!\n";}
			f.getline(formula,200);
			cout<<"Мы считали строку: "<<formula<<endl;
			f.close();
		}
	cout<<"Начинаю обработку выражения...\n";
	int len=strlen(formula);
	for(int t=0;t<len;t++){
		cout<<t+1<<"-й символ: '"<<formula[t]<<"' - ";
		if(formula[t]!='1' && formula[t]!='2' && formula[t]!='3' && formula[t]!='4' && formula[t]!='5' && formula[t]!='6' && formula[t]!='7' && formula[t]!='8' && formula[t]!='9' && formula[t]!='0' && formula[t]!='+' && formula[t]!='*' && formula[t]!='-'){
			cout<<"пропускается за незначимостью\n";
		}
		if(formula[t]=='1' || formula[t]=='2' || formula[t]=='3' || formula[t]=='4' || formula[t]=='5' || formula[t]=='6' || formula[t]=='7' || formula[t]=='8' || formula[t]=='9' || formula[t]=='0')
		{
			cout<<"цифра и заносится в стек\n";
				s1.push(int(formula[t]-48));
				s1.show();
		}
		if(formula[t]=='+'){
			cout<<"операция и проводится над элементами стека\n";
			int a=s1.pop(); cout<<"достали первый элемент для операции: "<<a<<endl; 
			s1.show();
			int b=s1.pop(); cout<<"достали второй элемент для операции: "<<b<<endl; 
			s1.show();
			int result=a+b;
			cout<<a<<"+"<<b<<"="<<result<<endl;
			s1.push(result);
			s1.show();
		}
		if(formula[t]=='-'){
			cout<<"операция и проводится над элементами стека\n";
			int a=s1.pop(); cout<<"достали первый элемент для операции: "<<a<<endl; 
			s1.show();
			int b=s1.pop(); cout<<"достали второй элемент для операции: "<<b<<endl; 
			s1.show();
			int result=a-b;
			cout<<a<<"-"<<b<<"="<<result<<endl;
			s1.push(result);
			s1.show();
		}
		if(formula[t]=='*'){
			cout<<"операция и проводится над элементами стека\n";
			int a=s1.pop(); cout<<"достали первый элемент для операции: "<<a<<endl; 
			s1.show();
			int b=s1.pop(); cout<<"достали второй элемент для операции: "<<b<<endl; 
			s1.show();
			int result=a*b;
			cout<<a<<"*"<<b<<"="<<result<<endl;
			s1.push(result);
			s1.show();
		}
	}
	cout<<"Обработка выражения завершена\n";
	if(s1.top!=0){
		cout<<"Однако вычисление выражения не завершено\nт.к. кол-во операций больше кол-ва цифр\nпоэтому за ответ будет взят последний элемент стека: ";
		int score=s1.pop();
		cout<<score<<endl;
		cout<<"Очищение стека:";
		s1.zero();
		s1.show();
	}
	else{
		cout<<"Ответ: ";
		int score=s1.pop();
		cout<<score<<endl;
		cout<<"Очищение стека:\nСтек и так пуст";
		s1.show();
	}
}

//главная ф-я//
int main(){
	setlocale(LC_ALL, "rus");
	cout<<"Здравствуйте, пользователь! Желаете ли Вы начать работу с классом?\n";
	
	if(pick()==0)
	{
		bye();
	}
	
	else
	{
	cout<<"Итак, мы будем работать со стеком\nХотите ли Вы ограничить его размеры?\n";
	
	if(pick()==0)
	{
		stack s1;
		work(s1);
	}
	else
	{
		int max;
		cout<<"Каков будет максимальный размер стека?\nОжидание ввода: ";
		cin>>max;
		stack s1(max);
		work(s1);
	}
	cout<<"Хотите ли Вы поработать с псевдопеременными?\n";
	if(pick()==1)
	{
		int a;
		cout<<"В таком случае нам понадобится два стека:\n";
		stack s1;
		stack s2;
		cout<<"Теперь первый из них нужно заполнить\nЖелаете ли Вы сделать это вручную?\n";
		if(pick()==1){
			cout<<"Тогда введите:\n";
			for(int t=0;t<10;t++){
				cout<<t<<"-й элемент: ";cin>>a;s1.push(a);
			}
			cout<<"Спасибо, теперь первый стек заполнен:\n";
			s1.show();
		}
		else{
			cout<<"Тогда первый стек будет заполнен случайными числами:\n";
			for(int t=0;t<10;t++){
				s1.push(1+rand()%10);
			}
			s1.show();
		}
		cout<<"Теперь, во-первых, выберите значение i от 1 до 10 (с конца): ";
		int sel;cin>>sel;
		cout<<"Этому элементу в стеке будет присвоено значение: ";
		int count;cin>>count;
		for(int i=0;i<10;i++){
			s2.push(s1.pop());
		}
		cout<<"Стеки:\n";s1.show();s2.show();

		for(int t=0;t<10;t++){
			s1.push(s2.pop());
			if(t==(9-sel)){s1.push(count);s2.pop();cout<<"Стеки:\n";s1.show();s2.show();}
		}
		cout<<"Стеки:\n";s1.show();s2.show();
	cout<<"Во-вторых, сейчас Вы вызовите ф-ю s1(i,j)=s2\nгде в стеке s1 начиная с i-го символа\nj элементов заменяются на стек s2\n";
	cout<<"Для этого введите i: ";int i;cin>>i;
	cout<<"И введите j: ";int j;cin>>j;
	cout<<"Для наглядности один из массивов будет содержать числа, другой же - их квадрат\n";
	cout<<"Очистим стеки:\n";
	s1.zero();
	s2.zero();
	
	for(int t=0;t<10;t++){
				s1.push(t+1);
			}
	for(int t=0;t<10;t++){
				s2.push((t+1)*(t+1));
			}
	cout<<"Стеки:\n";s1.show();s2.show();
	cout<<"Для реализации этого создадим третий стек\n";
	stack s3;
	cout<<"Стеки:\n";s1.show();s2.show();s3.show();
	int t;
	for(t=0;t<10-j-i+1;t++){
		s3.push(s1.pop());
	}
	cout<<"Стеки:\n";s1.show();s2.show();s3.show();
	for(t=0;t<j;t++){s1.pop();}
	cout<<"Стеки:\n";s1.show();s2.show();s3.show();

	for(t=0;t<10-(i+j-1);t++)
	{
		s2.pop();
	}
	cout<<"Стеки:\n";s1.show();s2.show();s3.show();
	for(t=0;t<j;t++){
		s3.push(s2.pop());
	}
	cout<<"Стеки:\n";s1.show();s2.show();s3.show();
	for(t=0;t<10-i+j-1;t++){
		s1.push(s3.pop());
	}
	cout<<"Стеки:\n";s1.show();s2.show();s3.show();
	s1.zero();s2.zero();s3.zero();
	}
	
cout<<"Хотители Вы поработать с библиотекой lib?\n";
if(pick()==0){}
else{
#include "function.h"
	stack s2;
	work(s2);
	cout<<"Как видите, даже при работе с функциями из библиотеки, все выполняется правильно..\n";
}
stack s1;s1.show();
cout<<"Работа с псевдопеременными напрямую. Часть 1.\n Введите номер элемента: ";
int e;cin>>e;
s1=e;
cout<<"Стеки\n";s1.show();
cout<<"Часть 2.\n Введите i: ";int i2;cin>>i2;
cout<<"Введите j: ";int j2; cin>>j2;
stack s2(i2,j2,s1);s1=s2;
s1.show();
cout<<"Как видите, даже при прямом обращении к псевдопеременным все исправно работает.\n";
}
	system("pause");
	return 0;
	}