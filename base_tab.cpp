#include "base_tab.h"

BASE_TAB::BASE_TAB(QWidget *parent) : QWidget(parent)
{
    initView();
    setViewWidthLengh();
    layoutView();
}

void BASE_TAB::initView()
{
    GridLayout0 = new QGridLayout;
    GridLayout1 = new QGridLayout;;
    GridLayout2 = new QGridLayout;;
    GridLayout3 = new QGridLayout;;
    GridLayout4 = new QGridLayout;;

    tableview0 = new QTableView;

    PushButton0 = new QPushButton(tr("PushButton0"));
    PushButton1 = new QPushButton(tr("PushButton1"));
    PushButton2 = new QPushButton(tr("PushButton2"));
    PushButton3 = new QPushButton(tr("PushButton3"));

    PushButton4 = new QPushButton(tr("PushButton4"));
    PushButton5 = new QPushButton(tr("PushButton5"));
    PushButton6 = new QPushButton(tr("PushButton6"));
    PushButton7 = new QPushButton(tr("PushButton7"));

    PushButton8 = new QPushButton(tr("PushButton8"));
    PushButton9 = new QPushButton(tr("PushButton9"));
    PushButton10 = new QPushButton(tr("PushButton10"));
    PushButton11 = new QPushButton(tr("PushButton11"));

    Label0 = new QLabel(tr("Label0"));
    Label1 = new QLabel(tr("Label1"));
    Label2 = new QLabel(tr("Label2"));
    Label3 = new QLabel(tr("Label3"));
    Label4 = new QLabel(tr("Label4"));
    Label5 = new QLabel(tr("Label5"));

    LineEdit0 = new QLineEdit;
    LineEdit1 = new QLineEdit;
    LineEdit2 = new QLineEdit;
    LineEdit3 = new QLineEdit;
    LineEdit4 = new QLineEdit;
    LineEdit5 = new QLineEdit;

    HBoxLayout0 = new QHBoxLayout;
    HBoxLayout1 = new QHBoxLayout;
    HBoxLayout2 = new QHBoxLayout;
    HBoxLayout3 = new QHBoxLayout;
    HBoxLayout4 = new QHBoxLayout;
    HBoxLayout5 = new QHBoxLayout;
}

void BASE_TAB::setViewWidthLengh()
{
    PushButton0->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton1->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton2->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton3->setFixedHeight(PUSHBUTTON_HEIGHT);

    PushButton0->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton1->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton2->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton3->setFixedWidth(PUSHBUTTON_WIDTH);

    PushButton4->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton5->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton6->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton7->setFixedHeight(PUSHBUTTON_HEIGHT);

    PushButton4->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton5->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton6->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton7->setFixedWidth(PUSHBUTTON_WIDTH);

    PushButton8->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton9->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton10->setFixedHeight(PUSHBUTTON_HEIGHT);
    PushButton11->setFixedHeight(PUSHBUTTON_HEIGHT);

    PushButton8->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton9->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton10->setFixedWidth(PUSHBUTTON_WIDTH);
    PushButton11->setFixedWidth(PUSHBUTTON_WIDTH);

    LineEdit0->setFixedHeight(LINEEDIT_HEIGHT);
    LineEdit1->setFixedHeight(LINEEDIT_HEIGHT);
    LineEdit2->setFixedHeight(LINEEDIT_HEIGHT);
    LineEdit3->setFixedHeight(LINEEDIT_HEIGHT);
    LineEdit4->setFixedHeight(LINEEDIT_HEIGHT);
    LineEdit5->setFixedHeight(LINEEDIT_HEIGHT);

    LineEdit0->setFixedWidth(LINEEDIT_WIDTH);
    LineEdit1->setFixedWidth(LINEEDIT_WIDTH);
    LineEdit2->setFixedWidth(LINEEDIT_WIDTH);
    LineEdit3->setFixedWidth(LINEEDIT_WIDTH);
    LineEdit4->setFixedWidth(LINEEDIT_WIDTH);
    LineEdit5->setFixedWidth(LINEEDIT_WIDTH);

    Label0->setFixedHeight(LABEL_HEIGHT);
    Label1->setFixedHeight(LABEL_HEIGHT);
    Label2->setFixedHeight(LABEL_HEIGHT);
    Label3->setFixedHeight(LABEL_HEIGHT);
    Label4->setFixedHeight(LABEL_HEIGHT);
    Label5->setFixedHeight(LABEL_HEIGHT);


    Label0->setFixedWidth(LABEL_WIDTH);
    Label1->setFixedWidth(LABEL_WIDTH);
    Label2->setFixedWidth(LABEL_WIDTH);
    Label3->setFixedWidth(LABEL_WIDTH);
    Label4->setFixedWidth(LABEL_WIDTH);
    Label5->setFixedWidth(LABEL_WIDTH);
}

void BASE_TAB::layoutView()
{
    HBoxLayout0->addWidget(Label0);
    HBoxLayout0->addWidget(LineEdit0);
    HBoxLayout1->addWidget(Label1);
    HBoxLayout1->addWidget(LineEdit1);
    HBoxLayout2->addWidget(Label2);
    HBoxLayout2->addWidget(LineEdit2);
    HBoxLayout3->addWidget(Label3);
    HBoxLayout3->addWidget(LineEdit3);
    HBoxLayout4->addWidget(Label4);
    HBoxLayout4->addWidget(LineEdit4);
    HBoxLayout5->addWidget(Label5);
    HBoxLayout5->addWidget(LineEdit5);

    GridLayout0->addWidget(PushButton0,0,0);
    GridLayout0->addWidget(PushButton1,1,0);
    GridLayout0->addWidget(PushButton2,2,0);
    GridLayout0->addWidget(PushButton3,3,0);
    GridLayout0->setSpacing(MAIN_SPACING);

    GridLayout1->addWidget(PushButton4,0,0);
    GridLayout1->addWidget(PushButton5,1,0);
    GridLayout1->addWidget(PushButton6,2,0);
    GridLayout1->addWidget(PushButton7,3,0);
    GridLayout1->setSpacing(MAIN_SPACING);

    GridLayout2->addLayout(HBoxLayout0,0,0);
    GridLayout2->addLayout(HBoxLayout1,1,0);
    GridLayout2->addLayout(HBoxLayout2,2,0);
    GridLayout2->addLayout(HBoxLayout3,3,0);
    GridLayout2->addLayout(HBoxLayout4,4,0);
    GridLayout2->addLayout(HBoxLayout5,5,0);
    GridLayout2->setSpacing(MAIN_SPACING);

    GridLayout3->addWidget(PushButton8,0,0);
    GridLayout3->addWidget(PushButton9,1,0);
    GridLayout3->addWidget(PushButton10,2,0);
    GridLayout3->addWidget(PushButton11,3,0);
    GridLayout3->setSpacing(MAIN_SPACING);


    GridLayout4->addLayout(GridLayout0,0,0);
    GridLayout4->addLayout(GridLayout1,1,0);
    GridLayout4->addLayout(GridLayout2,2,0);
    GridLayout4->addLayout(GridLayout3,3,0);
    GridLayout4->addWidget(tableview0,0,1,5,3);
    GridLayout4->setSpacing(CHILD_SPACING);
    this->setLayout(GridLayout4);
}

void BASE_TAB::setLabelHeight_Width(int Height, int Width)
{
    LABEL_HEIGHT = Height;
    LABEL_WIDTH = Width;
    setViewWidthLengh();
}

void BASE_TAB::setPushButton0Name(QString src)
{
    PushButton0->setText(src);
}
void BASE_TAB::setPushButton1Name(QString src)
{
    PushButton1->setText(src);
}
void BASE_TAB::setPushButton2Name(QString src)
{
    PushButton2->setText(src);
}
void BASE_TAB::setPushButton3Name(QString src)
{
    PushButton3->setText(src);
}
void BASE_TAB::setPushButton4Name(QString src)
{
    PushButton4->setText(src);
}
void BASE_TAB::setPushButton5Name(QString src)
{
    PushButton5->setText(src);
}
void BASE_TAB::setPushButton6Name(QString src)
{
    PushButton6->setText(src);
}
void BASE_TAB::setPushButton7Name(QString src)
{
    PushButton7->setText(src);
}
void BASE_TAB::setPushButton8Name(QString src)
{
    PushButton8->setText(src);
}
void BASE_TAB::setPushButton9Name(QString src)
{
    PushButton9->setText(src);
}
void BASE_TAB::setPushButton10Name(QString src)
{
    PushButton10->setText(src);
}
void BASE_TAB::setPushButton11Name(QString src)
{
    PushButton11->setText(src);
}

void BASE_TAB::setLabel0Name(QString src)
{
    Label0->setText(src);
}
void BASE_TAB::setLabel1Name(QString src)
{
    Label1->setText(src);
}
void BASE_TAB::setLabel2Name(QString src)
{
    Label2->setText(src);
}
void BASE_TAB::setLabel3Name(QString src)
{
    Label3->setText(src);
}
void BASE_TAB::setLabel4Name(QString src)
{
    Label4->setText(src);
}
void BASE_TAB::setLabel5Name(QString src)
{
    Label5->setText(src);
}

QString BASE_TAB::getLineEdit0Text()
{
    return LineEdit0->text();
}
QString BASE_TAB::getLineEdit1Text()
{
    return LineEdit1->text();
}
QString BASE_TAB::getLineEdit2Text()
{
    return LineEdit2->text();
}
QString BASE_TAB::getLineEdit3Text()
{
    return LineEdit3->text();
}
QString BASE_TAB::getLineEdit4Text()
{
    return LineEdit4->text();
}
QString BASE_TAB::getLineEdit5Text()
{
    return LineEdit5->text();
}

