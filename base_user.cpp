#include "base_user.h"

BASE_USER::BASE_USER(QWidget *parent) : QWidget(parent)
{
    initView();
    setView();
    layoutView();
    setSignalSlot();
}

QString BASE_USER::getstr_id()
{
    return le_user_id->text();
}

QString BASE_USER::get_str_name()
{
    return le_user_name->text();
}

QString BASE_USER::get_str_sex()
{
    return cb_user_sex->currentText();
}

QString BASE_USER::get_str_passwd()
{
    return le_user_passwd->text();
}

QString BASE_USER::get_str_birthday()
{
    return le_user_birthday->text();
}

QString BASE_USER::get_str_age()
{
    return le_user_age->text();
}

QString BASE_USER::get_str_phone()
{
    return le_user_phone->text();

}

QString BASE_USER::get_str_email()
{
    return le_user_email->text();
}

QString BASE_USER::get_str_address()
{
    return le_user_address->text();
}

QString BASE_USER::get_str_power()
{
    return cb_user_power->currentText();
}

void BASE_USER::initView()
{
    lb_user_id = new QLabel(tr("用户ID："));
    lb_user_name = new QLabel(tr("用户名字："));
    lb_user_sex = new QLabel(tr("性别："));
    lb_user_passwd = new QLabel(tr("密码："));
    lb_user_birthday = new QLabel(tr("生日："));
    lb_user_age = new QLabel(tr("年龄："));
    lb_user_phone = new QLabel(tr("电话："));
    lb_user_email = new QLabel(tr("邮箱："));
    lb_user_address = new QLabel(tr("地址："));
    lb_user_power= new QLabel(tr("权限："));

    le_user_id = new QLineEdit;
    le_user_name = new QLineEdit;
    cb_user_power = new QComboBox;
    cb_user_sex = new QComboBox;
    le_user_passwd = new QLineEdit;
    le_user_birthday = new QLineEdit;
    le_user_age = new QLineEdit;
    le_user_phone = new QLineEdit;
    le_user_email = new QLineEdit;
    le_user_address = new QLineEdit;

    hlayout_adduser = new QHBoxLayout;
    h8layout_adduser = new QHBoxLayout;
    h1layout_adduser = new QHBoxLayout;
    h2layout_adduser = new QHBoxLayout;
    h3layout_adduser = new QHBoxLayout;
    h4layout_adduser = new QHBoxLayout;
    h5layout_adduser = new QHBoxLayout;
    h6layout_adduser = new QHBoxLayout;
    h7layout_adduser = new QHBoxLayout;
    h9layout_adduser = new QHBoxLayout;
    h10layout_adduser = new QHBoxLayout;

    vlayout_adduser = new QVBoxLayout;
}

void BASE_USER::setView()
{
    le_user_id->setFixedWidth(120);
    le_user_name->setFixedWidth(120);
    cb_user_power->addItem(tr("管理员"));
    cb_user_power->addItem(tr("收银员"));
    cb_user_sex->setFixedWidth(120);
    cb_user_sex->addItem(tr("男"));
    cb_user_sex->addItem(tr("女"));
    cb_user_sex->addItem(tr("保密"));
    le_user_passwd->setFixedWidth(120);
    le_user_birthday->setFixedWidth(120);
    le_user_age->setFixedWidth(120);
    le_user_phone->setFixedWidth(120);
    le_user_email->setFixedWidth(120);
    le_user_address->setFixedWidth(120);

    pb_confirm = new QPushButton(tr("(&F)提交"));
    pb_cancel = new QPushButton(tr("(&A)取消"));

}

void BASE_USER::layoutView()
{
    hlayout_adduser->addWidget(lb_user_id);
    hlayout_adduser->addWidget(le_user_id);

    h1layout_adduser->addWidget(lb_user_name);
    h1layout_adduser->addWidget(le_user_name);

    h2layout_adduser->addWidget(lb_user_sex);
    h2layout_adduser->addWidget(cb_user_sex);

    h3layout_adduser->addWidget(lb_user_passwd);
    h3layout_adduser->addWidget(le_user_passwd);

    h4layout_adduser->addWidget(lb_user_birthday);
    h4layout_adduser->addWidget(le_user_birthday);

    h5layout_adduser->addWidget(lb_user_age);
    h5layout_adduser->addWidget(le_user_age);

    h6layout_adduser->addWidget(lb_user_phone);
    h6layout_adduser->addWidget(le_user_phone);

    h7layout_adduser->addWidget(lb_user_email);
    h7layout_adduser->addWidget(le_user_email);

    h8layout_adduser->addWidget(lb_user_address);
    h8layout_adduser->addWidget(le_user_address);

    h9layout_adduser->addWidget(pb_confirm);
    h9layout_adduser->addWidget(pb_cancel);

    h10layout_adduser->addWidget(lb_user_power);
    h10layout_adduser->addWidget(cb_user_power);

    vlayout_adduser->addLayout(hlayout_adduser);
    vlayout_adduser->addLayout(h1layout_adduser);
    vlayout_adduser->addLayout(h2layout_adduser);
    vlayout_adduser->addLayout(h10layout_adduser);
    vlayout_adduser->addLayout(h3layout_adduser);
    vlayout_adduser->addLayout(h4layout_adduser);
    vlayout_adduser->addLayout(h5layout_adduser);
    vlayout_adduser->addLayout(h6layout_adduser);
    vlayout_adduser->addLayout(h7layout_adduser);
    vlayout_adduser->addLayout(h8layout_adduser);
    vlayout_adduser->addLayout(h9layout_adduser);
    this->setLayout(vlayout_adduser);
//    this->getwi
}

void BASE_USER::setSignalSlot()
{
    connect(pb_cancel,SIGNAL(clicked(bool)),this,SLOT(close()));
}

