#include "user_login.h"
#include "window_admin.h"
#include "window_sale.h"
#include "user_register.h"
#include "qdesktopwidget.h"
USER_LOGIN::USER_LOGIN(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("超市管理系统登录");
    initView();
    setView();
    set_Layout();
    setSignalSlot();
}

USER_LOGIN::~USER_LOGIN(){

}
void USER_LOGIN::initView()
{
    label_id = new QLabel;
    label_passwd = new QLabel;
    label_power= new QLabel;
    label_picture = new QLabel;
    label_showtime= new QLabel;
    label_time= new QLabel;
    linedit_id = new QLineEdit;
    linedit_passwd = new QLineEdit;
    linedit_passwd->setEchoMode(QLineEdit::Password);
    timer = new QTimer(this);
    timer->start(1000);
    combobox_power = new QComboBox;
    pb_exit = new QPushButton;
    pb_login= new QPushButton;
    pb_register = new QPushButton;
    pb_reset = new QPushButton;

    hlayout = new QHBoxLayout;
    h1layout = new QHBoxLayout;
    h2layout = new QHBoxLayout;
    h3layout = new QHBoxLayout;
    h4layout = new QHBoxLayout;
    h5layout = new QHBoxLayout;
    layout_time = new QHBoxLayout;
    vlayout = new QVBoxLayout;
    glayout = new QGridLayout;
}

void USER_LOGIN::setView()
{

    label_id->setText(tr("(&I)用户ID:"));
    label_id->setFixedWidth(80);
    label_passwd->setText(tr("(&P)用户密码:"));
    label_passwd->setFixedWidth(80);
    label_power->setText(tr("(&O)权限:"));
    label_power->setFixedWidth(80);
    label_time->setText(tr("当前时间:"));
    label_time->setFixedWidth(80);
    label_showtime->setFixedWidth(120);
    label_picture->setStyleSheet(QString::fromUtf8("border-image:url(:/new/picture/picture/loginPicture.jpg)"));
    label_picture->setFixedHeight(128);
    label_picture->setFixedWidth(150);
    label_id->setBuddy(linedit_id);
    label_passwd->setBuddy(linedit_passwd);
    label_power->setBuddy(combobox_power);


    combobox_power->addItem(tr("收银员"));
    combobox_power->addItem(tr("管理员"));

    linedit_id->setFixedWidth(120);
    linedit_passwd->setFixedWidth(120);
    combobox_power->setFixedWidth(120);

    pb_exit->setText(tr("(&E)退出"));
    pb_reset->setText(tr("(&T)重置"));
    pb_register->setText(tr("(&R)注册"));
    pb_login->setText(tr("(&L)登录"));


}

void USER_LOGIN::set_Layout()
{
    hlayout->addWidget(label_id);
    hlayout->addWidget(linedit_id);
    h1layout->addWidget(label_power);
    h1layout->addWidget(combobox_power);

    h2layout->addWidget(label_passwd);
    h2layout->addWidget(linedit_passwd);

    h3layout->addWidget(pb_register);
    h3layout->addWidget(pb_login);
    h3layout->addWidget(pb_reset);
    h3layout->addWidget(pb_exit);

    h5layout->addWidget(label_picture);

    layout_time->addWidget(label_time);
    layout_time->addWidget(label_showtime);

    vlayout->addLayout(layout_time);
    vlayout->addLayout(h1layout);
    vlayout->addLayout(hlayout);
    vlayout->addLayout(h2layout);

    glayout->addLayout(vlayout,0,0,1,1);
    glayout->addLayout(h5layout,0,1,1,1);
    glayout->addLayout(h3layout,1,0,1,2);
//    glayout->setContentsMargins(0,0,0,0);
    this->setLayout(glayout);

    this->resize(450,250);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setWindowOpacity(0.9); //全体透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明
//    QDesktopWidget * pDw = new QDesktopWidget;  //获得桌面窗体
//    QRect rect = pDw->screenGeometry();  //获得分辨率
//    qDebug()<<"rect.width()"<<rect.width();
//    qDebug()<<"rect.height()"<<rect.height();
//    qint32 height = (rect.width() - this->width())/2;
//    qint32 width = (rect.height() - this->height())/2;
//    this->move(width,height);
    qDebug()<<"this->width( = "<<this->width();
    qDebug()<<"this->height() = "<<this->height();
//    qDebug()<<"width = "<<width;
//    qDebug()<<"height = "<<height;
}

void USER_LOGIN::setSignalSlot()
{
    connect(pb_exit,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(pb_reset,SIGNAL(clicked(bool)),linedit_id,SLOT(clear()));
    connect(pb_reset,SIGNAL(clicked(bool)),linedit_passwd,SLOT(clear()));
    connect(pb_login,SIGNAL(clicked(bool)),this,SLOT(slots_login()));
    connect(pb_register,SIGNAL(clicked(bool)),this,SLOT(slots_register()));
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
}

void USER_LOGIN::slots_login()
{
    userLoginModel = new QSqlTableModel;

    m_UserID = linedit_id->text();
    m_UserPassword = linedit_passwd->text();
    m_UserPower = combobox_power->currentText();
    userLoginModel->setTable("UserInformationtable");
    userLoginModel->select();
    for(int i = 0; i < userLoginModel->rowCount(); i++)
    {
        QSqlRecord temp = userLoginModel->record(i);
        QString tempID = temp.value("UserID").toString();
        QString tempPassword = temp.value("UserPassword").toString();
        QString tempPower = temp.value("UserLimit").toString();
        if((m_UserID == tempID)&&(m_UserPassword == tempPassword)&&(m_UserPower == tempPower))
        {
            qDebug()<<"login succeed";
            if(tempPower == "收银员"){
                sale_page * sale = new sale_page();
                sale->show();
            }else{
                admin * homePage  = new admin();
                homePage->show();
            }


            this->close();
        }
    }

}

void USER_LOGIN::slots_register()
{
    USER_REGISTER * temp = new USER_REGISTER;
    temp->show();
}

void USER_LOGIN::displayTime()
{
    QDateTime dt;
    QTime time;
    QDate date;

    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("yyyy:MM:dd:hh:mm:ss");
    label_showtime->setText(currentDate);
}
