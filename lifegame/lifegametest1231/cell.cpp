#include "cell.h"

Cell::Cell(QWidget *parent,int row, int column)
	: QFrame(parent)
{
	this->type = DEAD;          //all is DEAD(initializing) 
	setFrameStyle(QFrame::Box);    

	this->button = new QPushButton(this);  //make button
	this->button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);      
	this->button->setFixedSize(1280/column, 720/row);
	QHBoxLayout *layout = new QHBoxLayout();    //���η������ϴ� ���̾ƿ��� ����      
	layout->addWidget(this->button); //��ư�� ���̾ƿ��� �ֱ�
	setLayout(layout);//

	layout->setStretchFactor(this->button, 1);   //��ư�� �ø����ڸ� 1�� ����

	layout->setContentsMargins(0, 0, 0, 0);//���� 0
	layout->setSpacing(0);//space = 0

	connect(this->button, SIGNAL(clicked()), this, SLOT(click()));  // ��ư�� ������ �� �۾�
	set_color();           
}

Cell::~Cell()
{
	delete this->button;
}

void Cell::click() //when button clicked, this event will occur
{                                   
	if (this->type == DEAD)        
		type = LIVE;
	else
		type = DEAD;                 

	settype(type);   
}

cell_type Cell::gettype() const
{
	return(this->type);
}

void Cell::settype(cell_type type)
{
	this->type = type;
	set_color();
}

GlobalColor Cell::get_color()
{
	switch (this->type)
	{
	default:
	case DEAD:
		return white;
	case LIVE:
		return black;
	}
}

void Cell::set_color() //click�� �ϸ�  type�� ���Ѵ�. �׸��� �� Ÿ���� �������� ���� �׿� ���缭 ���ؾ� �Ѵ�. �� �۾��� �ϴ� ���̴�.
{
	GlobalColor color = get_color();        
	this->button->setPalette(QPalette(color, color));        
	this->button->setAutoFillBackground(true);
	this->button->setFlat(true);                        
}
