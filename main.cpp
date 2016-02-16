#include <QApplication>
#include <tab_commodity.h>
#include <user_login.h>
bool openDatabases(void);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(openDatabases() == 1){
        qDebug()<<"database open succeed";
    }else{
        qDebug()<<"database open failure";
    }
    USER_LOGIN w;
    w.show();
    return a.exec();
}
bool openDatabases(void)
{
    QSqlDatabase m_Db;
    m_Db=QSqlDatabase::addDatabase("QSQLITE");
    m_Db.setDatabaseName("SupermarketManagemantSystem.db");
    if(m_Db.open())
        return true;
    else
        return false;
}
