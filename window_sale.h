#ifndef SALE_PAGE_H
#define SALE_PAGE_H

#include <QWidget>
#include <commonfile.h>
#include "QTableView"
class sale_page : public QWidget
{
    Q_OBJECT
public:
    explicit sale_page(QWidget *parent = 0);

    QHBoxLayout * hl_1_level_main;

    //左边布局元件
    QVBoxLayout * vl_3_level_left;
    QHBoxLayout * hl_3_level_left;
    QLabel *lb_left_operator;
    QLabel *lb_left_date;
    QLabel *lb_left_commodity_code;
    QLineEdit *le_left_commodity_code;
    QTableView *tv_left_commodity_view;

    //中间布局元件
    QVBoxLayout * vl_3_level_middle;
    QPushButton * pb_middle_check;
    QPushButton * pb_middle_numplus;
    QPushButton * pb_middle_numminus;
    QPushButton * pb_middle_multiply;
    QPushButton * pb_middle_discount;
    QPushButton * pb_middle_alter;
    QPushButton * pb_middle_return;
    QPushButton * pb_middle_check_commodity_info;
    QPushButton * pb_middle_check_inventory;
    QPushButton * pb_middle_alter_user_info;


    //右边布局元件
    QHBoxLayout * hl_3_level_right;
    QLabel *lb_right_commodity_chose;
    QVBoxLayout * vl_3_level_right;
    QComboBox * cb_right_commodity_chose;
    QTableView * tv_right_commodity_detail;

    void initView(void);
    void setView(void);
    void layoutView(void);
    void setLeftTabelView(void);
    void setRightTabelView(void);
    void setSignalSlot(void);
signals:

public slots:
    void commodity_check(void);
    void commodity_numplus(void);
    void commodity_numminus(void);
    void commodity_multiply(void);
    void commodity_discount(void);
    void commodity_alter(void);
    void commodity_return(void);

    void check_commodity_info(void);
    void check_inventory(void);
    void alter_user_info(void);
};

#endif // SALE_PAGE_H
