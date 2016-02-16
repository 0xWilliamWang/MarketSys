#include "user_add.h"

USER_ADD::USER_ADD()
{
    connect(this->pb_confirm,SIGNAL(clicked(bool)),this,SLOT(setUserData()));
}

void USER_ADD::setUserData()
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

    qDebug()<<"str_id:"<< str_id;

    QSqlQuery query;
    QString str = QString("insert into UserInformationtable(UserID,UserName,\
                           UserPassword,UserLimit,UserSex,UserAge,UserBirthday,\
                            UserPhone,UserEmail,UserAddress) "\
                          "VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')")\
                            .arg(str_id).arg(str_name).arg(str_passwd).arg(str_power)\
                            .arg(str_sex).arg(str_age).arg(str_birthday).arg(str_phone).arg(str_email).arg(str_address);

    bool ok = query.exec(str);
    if(true == ok){
        QMessageBox::warning(this,tr("提示！"),tr("用户添加成功"));
        emit userAddSucceed();
        this->close();
    }
}

