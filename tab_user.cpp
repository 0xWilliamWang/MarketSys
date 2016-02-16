#include "tab_user.h"
#include "QWidget"
#include "user_alter.h"
#include "QPrintDialog"

USER::USER(BASE_TAB *parent) : BASE_TAB(parent)
{
    initData();
    setSignalSlot();
    setBaseVisible();
}

void USER::initData()
{
    alter = new USER_ALTER();
    add = new USER_ADD();
    setPushButton0Name("修改用户");
    setPushButton1Name("删除用户");
    setPushButton2Name("增加用户");
    setPushButton8Name("导出数据");

    setPushButton4Name("用户编号排序");
    setPushButton5Name("用户姓名排序");
    setPushButton6Name("用户年龄排序");
    setPushButton7Name("注册时间排序");

    setLabel0Name("检索地址");
    setLabel1Name("检索名字");
    setLabel2Name("检索编号");
    setLabel3Name("检索电话");
    setLabel4Name("检索邮箱");
    setLabel5Name("检索年龄");
}

void USER::alterUser()
{

    QString str_id;
    QString str_name;
    QString str_sex;
    QString str_passwd;
    QString str_birthday;
    QString str_age;
    QString str_phone;
    QString str_email;
    QString str_address;
    QString str_power;

    QSqlQuery query;
    int curRow = this->tableview0->currentIndex().row();
    qDebug()<<"curRow = "<<curRow;
    query.exec(QString("select * from UserInformationTable limit %1,1").arg(curRow));
    if(query.next()){
        str_id = query.value(0).toString();
        str_name = query.value(1).toString();
        str_passwd = query.value(2).toString();
        str_power = query.value(3).toString();
        str_sex = query.value(4).toString();
        str_age = query.value(5).toString();
        str_birthday = query.value(6).toString();
        str_phone = query.value(7).toString();
        str_email = query.value(8).toString();
        str_address = query.value(9).toString();
    }

    alter->le_user_id->setText(str_id);
    alter->le_user_name->setText(str_name);
    alter->cb_user_sex->addItem(str_sex);
    alter->le_user_passwd->setText(str_passwd);
    alter->le_user_birthday->setText(str_birthday);
    alter->le_user_age->setText(str_age);
    alter->le_user_phone->setText(str_phone);
    alter->le_user_email->setText(str_email);
    alter->le_user_address->setText(str_address);
    alter->show();

}

void USER::addUser()
{
    add->show();
}

void USER::delUser()
{
    QSqlQuery query;
    int curRow = this->tableview0->currentIndex().row();
    qDebug()<<"curRow = "<<curRow;
    userModel->removeRow(curRow);
    bool ok = QMessageBox::warning(this,tr("删除当前行！"),tr("您确定要删除当前行吗？"));
    if(ok){
        userModel->submitAll();
    }else{
        userModel->revertAll();
    }
    updateShow();
}

void USER::exportText()
{
    QSqlQuery query;
    bool ok = query.exec(".output ata.csv");
    qDebug()<<"lastError = "<<query.lastError();
    ok = query.exec(".separator ,");
    ok = query.exec("select * from UserInformationtable;");
    ok = query.exec(".output stdout");
}

void USER::exportEXcel()
{

}


void USER::setSignalSlot()
{
    connect(this->LineEdit0,SIGNAL(textEdited(QString)),this,SLOT(filterByAddress()));
    connect(this->LineEdit1,SIGNAL(textChanged(QString)),this,SLOT(filterByName()));
    connect(this->LineEdit2,SIGNAL(textEdited(QString)),this,SLOT(filterByID()));
    connect(this->LineEdit3,SIGNAL(textEdited(QString)),this,SLOT(filterByPhone()));
    connect(this->LineEdit4,SIGNAL(textEdited(QString)),this,SLOT(filterByEmail()));
    connect(this->LineEdit5,SIGNAL(textEdited(QString)),this,SLOT(filterByAge()));
    connect(alter,SIGNAL(userAlterSucceed()),this,SLOT(updateShow()));
    connect(add,SIGNAL(userAddSucceed()),this,SLOT(updateShow()));
    connect(this->PushButton0,SIGNAL(clicked(bool)),this,SLOT(alterUser()));
    connect(this->PushButton1,SIGNAL(clicked(bool)),this,SLOT(delUser()));
    connect(this->PushButton2,SIGNAL(clicked(bool)),this,SLOT(addUser()));

    connect(this->PushButton4,SIGNAL(clicked(bool)),this,SLOT(sortByUserId()));
    connect(this->PushButton5,SIGNAL(clicked(bool)),this,SLOT(sortByUserName()));
    connect(this->PushButton6,SIGNAL(clicked(bool)),this,SLOT(sortByUserAge()));
    connect(this->PushButton7,SIGNAL(clicked(bool)),this,SLOT(sortByUserRegisterTime()));
    connect(this->PushButton8,SIGNAL(clicked(bool)),this,SLOT(exportText()));
//    connect(this->PushButton8,SIGNAL(clicked(bool)),this,SLOT(exportEXcel()));
}

void USER::loadUserData()
{

    userModel = new QSqlTableModel(this);
    userModel->setTable("UserInformationTable");
    userModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    userModel->select();
    setTableHeader();
    tableview0->setModel(userModel);
    tableview0->resizeColumnsToContents();


}

void USER::setBaseVisible()
{
    PushButton3->setVisible(false);
//    PushButton9->setVisible(false);
    PushButton10->setVisible(false);
    PushButton11->setVisible(false);
}

void USER::setTableHeader()
{
    userModel->setHeaderData(0, Qt::Horizontal, tr("用户编号"));
    userModel->setHeaderData(1, Qt::Horizontal, tr("用户名"));
    userModel->setHeaderData(2, Qt::Horizontal, tr("用户密码"));
    userModel->setHeaderData(3, Qt::Horizontal, tr("用户权限"));
    userModel->setHeaderData(4, Qt::Horizontal, tr("性别"));
    userModel->setHeaderData(5, Qt::Horizontal, tr("年龄"));
    userModel->setHeaderData(6, Qt::Horizontal, tr("生日"));
    userModel->setHeaderData(7, Qt::Horizontal, tr("电话"));
    userModel->setHeaderData(8, Qt::Horizontal, tr("邮箱"));
    userModel->setHeaderData(9, Qt::Horizontal, tr("地址"));
    userModel->setHeaderData(10, Qt::Horizontal, tr("注册时间"));

}

void USER::doPrint()
{

}

void USER::doPrintPriview()
{

}

void USER::doCreatePDF()
{

}
void USER::setUserFilter(const QString clause)
{
    userModel->setTable("UserInformationtable");
    setTableHeader();
    userModel->setFilter(clause);
    /* Sets the current filter to filter.
     * The filter is a SQL WHERE clause without the keyword WHERE
     */
    userModel->select();
    this->tableview0->setModel(userModel);
    tableview0->resizeColumnsToContents();
}

void USER::filterByName()
{
    if(LineEdit1->text()!=""){
        setUserFilter(QString("UserName = %1").arg(LineEdit1->text()));
    }else{
        loadUserData();
    }
}

void USER::filterByAddress()
{
    if(LineEdit0->text()!=""){
        setUserFilter(QString("UserAddress = %1").arg(LineEdit0->text()));
    }else{
        loadUserData();
    }
}

void USER::filterByID()
{
    if(LineEdit2->text()!=""){
        setUserFilter(QString("UserID = %1").arg(LineEdit2->text()));
    }else{
        loadUserData();
    }
}

void USER::filterByPhone()
{
    if(LineEdit3->text()!=""){
        setUserFilter(QString("UserPhone = %1").arg(LineEdit3->text()));
    }else{
        loadUserData();
    }
}

void USER::filterByEmail()
{
    if(LineEdit4->text()!=""){
        setUserFilter(QString("UserEmail = %1").arg(LineEdit4->text()));
    }else{
        loadUserData();
    }
}

void USER::filterByAge()
{
    if(LineEdit5->text()!=""){
        setUserFilter(QString("UserAge = %1").arg(LineEdit5->text()));
    }else{
        loadUserData();
    }
}

void USER::sortByNum(int num)
{
    SORT_STATE = !SORT_STATE;
    if(SORT_STATE){
        userModel->setSort(num,Qt::AscendingOrder);
    }else{
        userModel->setSort(num,Qt::DescendingOrder);
    }
    userModel->select();
}

void USER::sortByUserId()
{
    sortByNum(0);
}

void USER::sortByUserName()
{
    sortByNum(1);
}

void USER::sortByUserAge()
{
    sortByNum(5);
}

void USER::sortByUserRegisterTime()
{
    sortByNum(10);
}

void USER::updateShow()
{
    loadUserData();
}

