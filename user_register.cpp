#include "user_register.h"
#include "user_login.h"
USER_REGISTER::USER_REGISTER(BASE_USER *parent) : BASE_USER(parent)
{
    this->setWindowTitle(tr("用户注册！"));
    connect(this->pb_confirm,SIGNAL(clicked(bool)),this,SLOT(slots_register_confirm()));
}

void USER_REGISTER::slots_register_confirm()
{
    str_id = this->getstr_id();
    str_name = this->get_str_name();
    str_sex = this->get_str_sex();
    str_passwd = this->get_str_passwd();
    str_birthday = this->get_str_birthday();
    str_age = this->get_str_age();
    str_phone = this->get_str_phone();
    str_email = this->get_str_email();
    str_address = this->get_str_address();
    str_power= this->get_str_power();

    qDebug()<<"str_id = "<< str_id;
    qDebug()<<"str_name = "<< str_name;
    qDebug()<<"str_sex = "<< str_sex;
    qDebug()<<"str_passwd = "<< str_passwd;
    qDebug()<<"str_birthday = "<< str_birthday;
    qDebug()<<"str_age = "<< str_age;
    qDebug()<<"str_phone = "<< str_phone;
    qDebug()<<"str_email = "<< str_email;
    qDebug()<<"str_address = "<< str_address;

    QRegExp rx("^[0-9]{1,4}$");
    int x = rx.indexIn(str_id);
    if(x == 0){
        QSqlQuery query;
        query.exec("CREATE TABLE UserInformationtable(\
                   UserID text primary key,\
                   UserName text default 'unkonwn',\
                   UserPassword text not null,\
                   UserLimit text not null,\
                   UserSex text default 'unkonwn',\
                   UserAge integer check (UserAge > 0),\
                   UserBirthday text default 'unknown',\
                   UserPhone text default 'unknown',\
                   UserEmail text default 'unknown',\
                   UserAddress text default 'unknown',\
                   UserRegisterTime text default current_timestamp)");
                QString str = QString("insert into UserInformationtable(UserID,UserName,\
                                      UserPassword,UserLimit,UserSex,UserAge,UserBirthday,\
                                      UserPhone,UserEmail,UserAddress) "\
                                                                       "VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")\
                .arg(str_id).arg(str_name).arg(str_passwd).arg(str_power)\
                .arg(str_sex).arg(str_age).arg(str_birthday).arg(str_phone).arg(str_email).arg(str_address);
        if(1 == query.exec(str)){
            QMessageBox::warning(this,tr("注册成功"),tr("请登录"));
            USER_LOGIN * lg = new USER_LOGIN;
            lg->show();
            this->close();
        }
    }
    else{
        QMessageBox::warning(this,tr("注册遇到意外"),tr("用户ID必须是4位数字"));
    }

}
