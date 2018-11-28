#include "stdafx.h"
#include "Form1.h"
#include <time.h>
#include <stdlib.h>

using namespace Figures;

void TMPoint::Show()
{
	Draw(color);
}

void TMPoint::Move(int dx,int dy)
{
	Hide();
	x+=dx; y+=dy;
	Show();
}

void TMPoint::Hide()
{
	Color inv = mainf->BackColor;
	Draw(inv);
}

TElepse::TElepse(int x,int y, Color cl,int r1,int r2,Form^ _mainf)
{
	this->x=x;
	this->y=y;
	this->rh=r1;
	this->rv=r2;
	color=cl;
	mainf=_mainf;
	active=false;
	Show();
}

void TElepse::Draw(Color col)
{
	Graphics^ g = Graphics::FromHwnd(mainf->Handle);
	SolidBrush^ myBrush = gcnew SolidBrush(col);
	g->FillEllipse(myBrush, x-rh, y-rv, 2*rh, 2*rv);
}

void TElepse:: DrawSL(int dx,int dy,Color cl, bool sled)
{
	Hide();
	Graphics^ g = Graphics::FromHwnd(mainf->Handle);
	Pen^ newPen = gcnew Pen(cl,1.0f );
	if (sled==true) g->DrawLine( newPen, x-2*rh,y, x+dx,y+dy );
	else g->DrawLine( newPen, x+2*rh,y, x+dx,y+dy );
	x+=dx; y+=dy;
	Show();
}

void TElepse::ToDefault()
{
	x=150;
	y=125;
	rh=20;
	rv=50;
	color=Color::Green;
	Show();
}

void TElepse::Deformation()
{
	Hide();
	rh+=5;
	if (rh>200) rh-=5;
	if (rv>300) rv-=2;
	rv+=2;
	Show();
}

bool TElepse::check(bool dirct) //проверка выхода за форму, при анимации
{
	if (dirct) if ((y+rv+21)>mainf->Height) return false;
	if (!dirct) if (y-rv-5<0) return false;
	return true;
}

/*TElepse * TElepse::Clone()
{
	TElepse *temp;
	temp=new TElepse(x,y,color,rh,rv,mainf);
	return temp;
};*/

int TElepse::GetRange(int c)
{
	switch(c)
	{
	case 1: return x-rh; break;
	case 2: return x+rh; break;
	case 3: return y-rv; break;
	case 4: return y+rv; break;
	default: return 0;
	}
}
/*int TElepse::GetX()
{
return x-rh;
}

int TElepse::GetY()
{
return y-rv;
}*/

TRectangl::TRectangl(int x,int y,Color c, int wid, int hgt,Form^ _mainf)
{
	this->x=x;
	this->y=y;
	color=c;
	width=wid;
	height=hgt;
	mainf=_mainf;
	active=false;
	Show();
}

void TRectangl::Draw(Color col)
{
	Graphics^ g = Graphics::FromHwnd(mainf->Handle);
	SolidBrush^ myBrush = gcnew SolidBrush(col);
	g->FillRectangle(myBrush, x, y, width, height);
}

void TRectangl::DrawSL(int dx,int dy,Color cl, bool sled)
{
	Hide();
	Graphics^ g = Graphics::FromHwnd(mainf->Handle);
	Pen^ newPen = gcnew Pen(cl, 1.0f);
	if (sled==true) g->DrawLine( newPen, x,y+height,x+dx,y+dy+height);
	else g->DrawLine( newPen, x+width,y+height,x+dx,y+dy+height);
	x+=dx; y+=dy;
	Show();
}

void TRectangl::ToDefault()
{
	x=y=200;
	height=50;
	width=80;
	color=Color::Yellow;
	Show();
}

bool TRectangl::check(bool dirct)
{
	if (dirct) if ((y+height+21>mainf->Height)) return false;
	if (!dirct) if (y-5<0) return false;
	return true;
}

void TRectangl::Deformation()
{
	Hide();
	width+=5;
	if (height-5>2)	height-=5;
	Show();
}

int TRectangl::GetRange(int c)
{
	switch (c)
	{
	case 1: return x; break;
	case 2: return x+width; break;
	case 3: return y; break;
	case 4: return y+height; break;
	default: return 0;
	}
}

/*TRectangl * TRectangl::Clone()
{
	TRectangl * temp;
	temp=new TRectangl(x,y,color,width,height,mainf);
	return temp;
}*/

TListF::TListF()
{
	next=NULL;
}

TListF::TListF(bool fCreate)
{
	next=NULL;
	elem=NULL;
}

void TListF::AddElepse(int x,int y,Color c,int r1,int r2,Form^ _mainf)
{
	TListF *temp=this;
	while (temp->next!=NULL) temp=temp->next;
	temp->next = new TListF();
	temp->next->elem = new TElepse(x,y,c,r1,r2,_mainf);
	temp->next->elem->active=true;
	
}

void TListF::AddRect(int x,int y,Color c, int wid, int hgt,Form^ _mainf)
{
	TListF *temp=this;
	while (temp->next!=NULL) temp=temp->next;
	temp->next = new TListF();
	temp->next->elem = new TRectangl(x,y,c,wid,hgt,_mainf);
	temp->next->elem->active=true;
}

void TListF::MoveCurrent(int Dpos)
{
	TListF *temp=this->next;
	bool found=false;
	while (temp!=NULL && found==false)
	{
		if (temp->elem->active==true)
			{
				found=true;
				ColorCheck(this->next,temp);
				if (Dpos==2) temp->elem->Move(0,10);
				if (Dpos==4) temp->elem->Move(-10,0);
	            if (Dpos==6) temp->elem->Move(10,0);
				if (Dpos==8) temp->elem->Move(0,-10);
		    }
		temp=temp->next;	
	}	
}

void TListF::MakeAllInactive()
{
	TListF *temp=this->next;
	while (temp!=NULL)
	{
		temp->elem->active=false;
		temp->elem->Hide();
		temp=temp->next;
	}
}

void TListF::MakeAllActive()
{
	TListF *temp=this->next;
	while (temp!=NULL)
	{
		temp->elem->active=true;
		temp->elem->Show();
		temp=temp->next;
	}
}

void TListF::MakeNextElementActive()
{
	TListF *temp=this->next;
	if (temp==NULL) return;
	bool t=false;
	while (!t)
	{
		if (temp->elem->active==true) 
		{
			t=true;
			temp->elem->active=false;
			
			temp->elem->Hide();
		}
		if (temp->next==NULL) temp=this->next;
		else temp=temp->next;
		if (t) 
		{
			temp->elem->active=true;
			temp->elem->Show();
		}
	}
}

void TListF::ActiveElementToDefault()
{
	TListF *temp=this->next;
	bool found=false;
	while (temp!=NULL && found==false)
	{
		if (temp->elem->active==true)
			{
				found=true; 
				temp->elem->Hide();
				temp->elem->ToDefault();
				temp->elem->Show();
		    }
		temp=temp->next;	
	}	
}

void TListF::Deformation()
{
	TListF *temp=this->next;
	bool found=false;
	while (temp!=NULL && found==false)
	{
		if (temp->elem->active==true)
			{
				found=true; 
				temp->elem->Deformation();
		    }
		temp=temp->next;	
	}	
}


bool TListF::CheckCurrent(bool sled)
{
	TListF *temp=this->next;
	bool found=false;
	bool check;
	while (temp!=NULL && found==false)
	{
		if (temp->elem->active==true)
			{
				found=true; 
				check=temp->elem->check(sled);
		    }
		temp=temp->next;	
	}	
	return check;
}


bool TAgregat::check(bool direction)
{
	TAgregat *temp=this->next;
	bool b;
	while (temp!=NULL)
	{
		b=temp->elem->check(direction);
		if (!b) return false;
		temp=temp->next;	
	}
	return true;
}

void TListF::ColorCheck(TListF * list,TListF * temp)
{
  while (list!=NULL)
  {
	if (list==temp) { list=list->next; continue; }
	int x0,x1,x2,x3,y0,y1,y2,y3;
	x0=temp->elem->GetRange(1); y0=temp->elem->GetRange(3);
	x1=temp->elem->GetRange(2); y1=temp->elem->GetRange(4);
	x2=list->elem->GetRange(1); y2=list->elem->GetRange(3);
	x3=list->elem->GetRange(2); y3=list->elem->GetRange(4);
	if(!(x0>=x3||x2>=x1||y3<=y0||y1<=y2))
	{
		srand (unsigned (time(0)));
	    temp->elem->color=Color::FromArgb(rand() % 255,rand() % 255,rand() % 255);
		
	}    
	list=list->next;
  }
}


void TListF::AgregateAll()
{
	TListF *temp=this->next;
	TListF *temp1=this->next;
	TAgregat * tempagr = new TAgregat();
	while (temp!=NULL)
	{
		tempagr->AddToAgregat(temp->elem);
		temp=temp->next;
	}
	
	MakeAllInactive();
	temp=this->next;
	if (temp==NULL) return;
	tempagr->mainf=temp->elem->mainf;
	temp->elem=tempagr;
	temp->elem->active=true;
	temp->elem->Show();
	temp->next=NULL;
}

TAgregat::TAgregat()
{
	next=NULL;
}

void TAgregat::AddToAgregat(TMPoint * temp)
{
	TAgregat *tempagr=this;
	while (tempagr->next!=NULL) tempagr=tempagr->next;

	tempagr->next = new TAgregat();
	tempagr->next->elem=temp;
}

void TAgregat::Move(int dx,int dy)
{
	TAgregat *temp=this->next;

	while (temp!=NULL)
	{
		temp->elem->Move(dx,dy);
		temp=temp->next;	
	}
	temp=this->next;
	while (temp!=NULL)
	{
		temp->elem->Show();
		temp=temp->next;	
	}
}

void TAgregat::Show()
{
	TAgregat *temp=this->next;
	while (temp!=NULL)
	{
		temp->elem->Show();
		temp=temp->next;
	}
}

void TAgregat::Draw(Color color)
{
	TAgregat *temp=this->next;
	while (temp!=NULL)
	{
		temp->elem->Draw(color);
		temp=temp->next;
	}
}

void TAgregat::DrawSL(int dx,int dy,Color cl, bool sled)
{
	TAgregat *temp=this->next;
	int min1, min3;
	min1 = temp->elem->GetRange(1);
		min3 = temp->elem->GetRange(3);
	while (temp!=NULL)
	{
		if (min1>temp->elem->GetRange(1) && min3>temp->elem->GetRange(3))
		{
			min1 = temp->elem->GetRange(1);
			min3 = temp->elem->GetRange(3);
			temp=temp->next;
		}
		temp=temp->next;
	}
		temp->elem->DrawSL(dx,dy,cl,sled);
	
		
}
void TAgregat::Deformation()
{
	TAgregat *temp=this->next;
	while (temp!=NULL)
	{
		temp->elem->Deformation();
		temp=temp->next;
	}
}

int TAgregat::GetRange(int c)
{
	TAgregat *temp=this->next;
	while (temp!=NULL)
	{return temp->elem->GetRange(c);
		temp=temp->next;
	}
}

