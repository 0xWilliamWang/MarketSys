#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QWidget>
#include "tab_setting.h"
#include "user_alter.h"
#include "base_tab.h"
#include "tab_commodity.h"
#include "base_user.h"
#include "tab_user.h"
#include "tab_customer.h"
class admin : public QWidget
{
    Q_OBJECT

    public:
    admin(QWidget *parent = 0);
    ~admin();

    QTabWidget * tabWidget;
    USER * user;
    BASE_TAB * base_tab;
    SETTING * setting;
    COMMODITY * commodity;
    CUSTOMER * customer;
    QGridLayout * glayouy_home;


    // 主界面的方法
    void initView();
    void setView();
    void setView_Commodity();
    void layoutView(void);

    // 用户子界面的方法
public:



    // 商品子界面的方法
public:
    QSqlTableModel * commodityModel;
    void loadCommodityrData();
};

#endif // HOME_PAGE_H
