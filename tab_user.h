#ifndef TAB_USER_H
#define TAB_USER_H
#include "commonfile.h"
#include "base_tab.h"
#include "user_alter.h"
#include "user_add.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>

class USER : public BASE_TAB
{
    Q_OBJECT
public:
    bool SORT_STATE = false;
    explicit USER(BASE_TAB *parent = 0);

    void initData(void);
    void sortbaseui(int value);
    void setSignalSlot(void);
    void loadUserData();
    void setBaseVisible(void);
    void setTableHeader();
    QSqlTableModel * userModel;
    QTimer *timer;
    USER_ALTER * alter;
    USER_ADD * add;

    void doPrint(void);
    void doPrintPriview(void);
    void doCreatePDF(void);


public slots:

    /*过滤的方法*/
    void setUserFilter(const QString clause);
    void filterByName(void);
    void filterByAddress(void);
    void filterByID(void);
    void filterByPhone(void);
    void filterByEmail(void);
    void filterByAge(void);
    /*排序的方法*/
    void sortByNum(int num);
    void sortByUserId(void);
    void sortByUserName(void);
    void sortByUserAge(void);
    void sortByUserRegisterTime(void);

    void updateShow(void);
    void alterUser();
    void addUser();
    void delUser();

    /*数据导出的方法*/
    void exportText(void);
    void exportEXcel(void);

};

#endif // TAB_USER_H
