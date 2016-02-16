#include "commonfile.h"
#include "user_alter.h"
#include "user_login.h"




USER_ALTER::USER_ALTER(BASE_USER *parent)
{
    initData();
    setSignalSlot();
}

void USER_ALTER::setSignalSlot()
{
    connect(this->pb_confirm,SIGNAL(clicked(bool)),this,SLOT(setData()));
}

void USER_ALTER::initData()
{

}

void USER_ALTER::setData()
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
    QSqlQuery query;

    bool ok = query.exec(QString("update UserInformationTable set UserName = '%1',UserPassword = '%2',UserLimit = '%3',UserSex = '%4',UserAge = '%5',UserBirthday = '%6',UserPhone = '%7',UserEmail = '%8',UserAddress = '%9' where UserID = '%10';").arg(str_name).arg(str_passwd).arg(str_power).arg(str_sex).arg(str_age).arg(str_birthday).arg(str_phone).arg(str_email).arg(str_address).arg(str_id));
    if(true == ok){
        QMessageBox::warning(this,tr("提示！"),tr("用户信息修改成功"));
        emit userAlterSucceed();
        this->close();
    }
}
