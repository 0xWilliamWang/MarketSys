#include "window_sale.h"
#include "user_alter.h"
#include "user_register.h"
sale_page::sale_page(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle(tr("收银台"));
    initView();
    setView();
    layoutView();
    setSignalSlot();
}

void sale_page::initView()
{
    hl_1_level_main = new  QHBoxLayout;


    //左边布局元件
    hl_3_level_left = new  QHBoxLayout;
    vl_3_level_left = new QVBoxLayout;
    lb_left_operator = new QLabel;
    lb_left_commodity_code = new QLabel;
    lb_left_date = new QLabel;
    le_left_commodity_code = new QLineEdit;
    tv_left_commodity_view = new QTableView;


    //中间布局元件
    vl_3_level_middle = new QVBoxLayout;
    pb_middle_check = new QPushButton;
    pb_middle_numplus = new QPushButton;
    pb_middle_numminus = new QPushButton;
    pb_middle_multiply = new QPushButton;
    pb_middle_discount = new QPushButton;
    pb_middle_alter = new QPushButton;
    pb_middle_return = new QPushButton;
    //中间布局元件
    pb_middle_check_commodity_info = new QPushButton;
    pb_middle_check_inventory = new QPushButton;
    pb_middle_alter_user_info = new QPushButton;
    //右边布局元件
      hl_3_level_right = new  QHBoxLayout;
    lb_right_commodity_chose = new QLabel;
    vl_3_level_right = new QVBoxLayout;
    cb_right_commodity_chose = new QComboBox;
    tv_right_commodity_detail = new QTableView;
}

void sale_page::setView()
{
    //左边布局元件
    lb_left_date->setText(tr("日期:"));
    lb_left_operator->setText(tr("操作员:"));
    lb_left_commodity_code->setText(tr("商品编号:"));
    setLeftTabelView();
    //中间布局元件
    pb_middle_check->setText(tr("结算"));
    pb_middle_alter->setText(tr("改价"));
    pb_middle_numplus->setText(tr("数量+"));
    pb_middle_numminus->setText(tr("数量-"));
    pb_middle_multiply->setText(tr("数量*"));
    pb_middle_discount->setText(tr("折扣"));
    pb_middle_return->setText(tr("退货"));

    pb_middle_check_commodity_info->setText(tr("查看商品信息"));
    pb_middle_check_inventory->setText(tr("查看库存信息"));
    pb_middle_alter_user_info->setText(tr("修改用户信息"));
    //右边布局元件
    setRightTabelView();
    lb_right_commodity_chose->setText(tr("      商品类别:"));
}

void sale_page::layoutView()
{
    //左边布局元件
    hl_3_level_left->addWidget(lb_left_commodity_code);
    hl_3_level_left->addWidget(le_left_commodity_code);
    vl_3_level_left->addWidget(lb_left_date);
    vl_3_level_left->addWidget(lb_left_operator);
    vl_3_level_left->addLayout(hl_3_level_left);
    vl_3_level_left->addWidget(tv_left_commodity_view);
    //中间布局元件
    vl_3_level_middle->addWidget(pb_middle_check);
    vl_3_level_middle->addWidget(pb_middle_numplus);
    vl_3_level_middle->addWidget(pb_middle_numminus);
    vl_3_level_middle->addWidget(pb_middle_multiply);
    vl_3_level_middle->addWidget(pb_middle_discount);
    vl_3_level_middle->addWidget(pb_middle_alter);
    vl_3_level_middle->addWidget(pb_middle_return);
    vl_3_level_middle->addSpacing(100);
    vl_3_level_middle->addWidget(pb_middle_check_commodity_info);
    vl_3_level_middle->addWidget(pb_middle_check_inventory);
    vl_3_level_middle->addWidget(pb_middle_alter_user_info);
    //右边布局元件
    hl_3_level_right->addWidget(lb_right_commodity_chose);
    hl_3_level_right->addWidget(cb_right_commodity_chose);
    vl_3_level_right->addLayout(hl_3_level_right);
    vl_3_level_right->addWidget(tv_right_commodity_detail);

    //总布局

    hl_1_level_main->addLayout(vl_3_level_left);
    hl_1_level_main->addSpacing(50);
    hl_1_level_main->addLayout(vl_3_level_middle);
    hl_1_level_main->addSpacing(50);
    hl_1_level_main->addLayout(vl_3_level_right);
//    hl_1_level_main->setSpacing(50);
    this->setLayout(hl_1_level_main);
}

void sale_page::setLeftTabelView()
{
    QStandardItemModel  *model = new QStandardItemModel();

    model->setColumnCount(2);

    model->setHeaderData(0,Qt::Horizontal,tr("卡号"));

    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));

    tv_left_commodity_view->setModel(model);

    //表头信息显示居左

    tv_left_commodity_view->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //设置列宽不可变
    tv_left_commodity_view->setColumnWidth(0,101);

    tv_left_commodity_view->setColumnWidth(1,102);
    for(int i = 0; i < 3; i++)
    {
        model->setItem(i,0,new QStandardItem("2009441676"));
        //设置字符颜色
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        //设置字符位置
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(tr("哈哈")));
    }
}

void sale_page::setRightTabelView()
{
    QStandardItemModel  *model = new QStandardItemModel();

    model->setColumnCount(2);

    model->setHeaderData(0,Qt::Horizontal,tr("卡号"));

    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));

    tv_right_commodity_detail->setModel(model);

    //表头信息显示居左

    tv_right_commodity_detail->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //设置列宽不可变
    tv_right_commodity_detail->setColumnWidth(0,101);

    tv_left_commodity_view->setColumnWidth(1,102);
    for(int i = 0; i < 3; i++)
    {
        model->setItem(i,0,new QStandardItem("2009441676"));
        //设置字符颜色
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        //设置字符位置
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(tr("哈哈")));
    }
}

void sale_page::setSignalSlot()
{
    connect(pb_middle_check,SIGNAL(clicked(bool)),this,SLOT(commodity_check()));
    connect(pb_middle_numplus,SIGNAL(clicked(bool)),this,SLOT(commodity_numplus()));
    connect(pb_middle_numminus,SIGNAL(clicked(bool)),this,SLOT(commodity_numminus()));
    connect(pb_middle_multiply,SIGNAL(clicked(bool)),this,SLOT(commodity_multiply()));
    connect(pb_middle_discount,SIGNAL(clicked(bool)),this,SLOT(commodity_discount()));
    connect(pb_middle_alter,SIGNAL(clicked(bool)),this,SLOT(commodity_alter()));
    connect(pb_middle_return,SIGNAL(clicked(bool)),this,SLOT(commodity_return()));
    connect(pb_middle_check_commodity_info,SIGNAL(clicked(bool)),this,SLOT(check_commodity_info()));
    connect(pb_middle_check_inventory,SIGNAL(clicked(bool)),this,SLOT(check_inventory()));
    connect(pb_middle_alter_user_info,SIGNAL(clicked(bool)),this,SLOT(alter_user_info()));
}

void sale_page::commodity_check()
{

}

void sale_page::commodity_numplus()
{

}

void sale_page::commodity_numminus()
{

}

void sale_page::commodity_multiply()
{

}

void sale_page::commodity_discount()
{

}

void sale_page::commodity_alter()
{

}

void sale_page::commodity_return()
{

}

void sale_page::check_commodity_info()
{

}

void sale_page::check_inventory()
{

}

void sale_page::alter_user_info()
{
    USER_REGISTER * temp = new USER_REGISTER;
    temp->show();
}

