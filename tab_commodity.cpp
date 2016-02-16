//#include <QWidget>
#include "tab_commodity.h"

COMMODITY::COMMODITY(BASE_TAB *parent)
{
    initViewData();
}

void COMMODITY::initViewData()
{
    setPushButton0Name("增加商品");
    setPushButton1Name("删除商品");
    setPushButton2Name("更新商品信息");

    setPushButton4Name("按商品编号排序");
    setPushButton5Name("按进价排序");
    setPushButton6Name("按零售价排序");
    setPushButton7Name("按保质期排序");

    setLabel0Name("检索商品编号");
    setLabel1Name("检索商品名称");
    setLabel2Name("检索商品进价");
    setLabel3Name("检索商品批发价");
    setLabel4Name("检索商品零售价");
    setLabel5Name("检索商品供应商编号");

    setPushButton8Name("导出数据");
    setLabelHeight_Width(20,120);
    createCommodityTable();
    setViewVisible();
}

void COMMODITY::createCommodityTable()
{
    QSqlQuery query;
    bool ok = query.exec("CREATE TABLE CommodityInformationtable(\
               CommodityID text primary key,\
               CommodityName text not null,\
               CommoditySpecification text not null,\
               CommodityPrice integer check (CommodityPrice >= 0),\
               CommodityWholesaleprice integer check (CommodityWholesaleprice >= 0),\
               CommodityRetailPrice integer check (CommodityRetailPrice >= 0),\
               CommodityShelfLife integer check (CommodityShelfLife >= 0),\
               ProviderID text default 'unknown',\
               CommodityShelfEndTime text check (CommodityShelfEndTime >= 0))");
    if(ok){
        qDebug()<<"商品信息表创建成功";
    }else{
        qDebug()<<"lastError() = "<<query.lastError();
}
}

void COMMODITY::setViewVisible()
{
    PushButton3->setVisible(false);
    PushButton9->setVisible(false);
    PushButton10->setVisible(false);
    PushButton11->setVisible(false);
}
