#include "commonfile.h"
#include "window_admin.h"
#include "tab_customer.h"
admin::admin(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(tr("超市管理系统"));
    initView();
    setView();
    layoutView();
    setView_Commodity();
    user->loadUserData();
    loadCommodityrData();
}

admin::~admin()
{

}

void admin::initView()
{
    tabWidget = new QTabWidget;
    user = new USER;
    setting = new SETTING;
    commodity = new COMMODITY;
    glayouy_home = new QGridLayout;
    base_tab = new BASE_TAB;
    customer = new CUSTOMER;

}

void admin::setView()
{
    tabWidget->addTab(user,tr("(&U)用户栏目"));
    tabWidget->addTab(commodity,tr("(&C)商品栏目"));
    tabWidget->addTab(customer,tr("(&C)顾客栏目"));
    tabWidget->addTab(setting,tr("(&S)系统设置"));
    tabWidget->addTab(base_tab,tr("DEMO"));
}

void admin::setView_Commodity()
{

}

void admin::layoutView()
{
    glayouy_home->addWidget(tabWidget);
    this->setLayout(glayouy_home);
}


void admin::loadCommodityrData()
{
    commodityModel = new QSqlTableModel(this);
    commodityModel->setTable("CommodityInformationTable");
    commodityModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    commodityModel->select();

    commodityModel->setHeaderData(0, Qt::Horizontal, tr("商品编号"));
    commodityModel->setHeaderData(1, Qt::Horizontal, tr("商品名称"));
    commodityModel->setHeaderData(2, Qt::Horizontal, tr("型号规格"));
    commodityModel->setHeaderData(3, Qt::Horizontal, tr("进价"));
    commodityModel->setHeaderData(4, Qt::Horizontal, tr("批发价"));
    commodityModel->setHeaderData(5, Qt::Horizontal, tr("零售价"));
    commodityModel->setHeaderData(6, Qt::Horizontal, tr("保质期"));
    commodityModel->setHeaderData(7, Qt::Horizontal, tr("供应商编号"));
    commodityModel->setHeaderData(8, Qt::Horizontal, tr("保质期截止时间"));

    commodity->tableview0->setModel(commodityModel);
    commodity->tableview0->resizeColumnsToContents();

}

