#include "Form1.h"
#include <vcclr.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Figures
{

class TMPoint
{
protected:
	int x,y;
public:
	gcroot<Form^> mainf;
	gcroot<Color> color;
	bool active;
	virtual void Draw(Color color)=0;
	virtual void DrawSL(int dx,int dy,Color cl, bool sled)=0;
	void Hide();
	virtual void Show();
	virtual void Move(int dx,int dy);
	virtual void ToDefault(){};
	virtual void Deformation(){};
	virtual bool check(bool sled)=0;
	virtual int GetRange(int c){return 0;};
	//virtual TMPoint * Clone()=0;
	//virtual int GetX() = 0;
	//virtual int GetY() = 0;
};

class TElepse:public TMPoint
{
	int rh,rv;
public:
	TElepse(int x,int y, Color cl,int r1,int r2,Form^ _mainf);
	void Draw(Color col);
	void ToDefault();
	void Deformation();
	void DrawSL(int dx,int dy,Color cl, bool sled);
	bool check(bool dirct);
	int GetRange(int c);
	//virtual TElepse * Clone();
	//int GetX();
    //int GetY();
};

class TRectangl:public TMPoint
{
	int width,height;
public:
	TRectangl(int x,int y,Color c, int wid, int hgt,Form^ _mainf);
	void Draw(Color col);
	void ToDefault();
	void Deformation();
	void DrawSL(int dx,int dy,Color cl, bool sled);
	bool check(bool sled);
	int GetRange(int c);
	//virtual TRectangl * Clone();
	//int GetX();
	//int GetY();
};

class TAgregat:public TMPoint
{
private:
	TAgregat * head;
	TAgregat * next;
	TMPoint * elem;
	void Draw(Color color);
public:
	int r1,r2,width,height;
	TAgregat();
	bool check(bool sled);
	void AddToAgregat(TMPoint * temp);
	void Move(int dx,int dy);
	void Show();
	void DrawSL(int dx,int dy,Color cl, bool sled);
void Deformation();
int GetRange(int c);

	//virtual TAgregat * Clone();
};

class TListF
{
	TListF * next;
	TMPoint * elem;
public:	
	TListF();
	TListF(bool fCreate);
	void AddElepse(int x,int y,Color c,int r1,int r2,Form^ _mainf);
	void AddRect(int x,int y,Color c, int wid, int hgt,Form^ _mainf);
	void MoveCurrent(int Dpos);
	void MoveCurrentSled(bool sled);
	void MakeAllInactive();
	void MakeAllActive();
	void MakeNextElementActive();
	void ActiveElementToDefault();
	void Deformation();
	bool CheckCurrent(bool sled);
	void ColorCheck(TListF * list,TListF * temp);
	void AgregateAll();
};

}
