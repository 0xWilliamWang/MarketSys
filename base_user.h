#ifndef BASE_USER_H
#define BASE_USER_H

#include <QWidget>
#include <commonfile.h>

class BASE_USER : public QWidget
{
    Q_OBJECT
public:
    explicit BASE_USER(QWidget *parent = 0);

    QLabel * lb_user_id;
    QLabel * lb_user_name;
    QLabel * lb_user_sex;
    QLabel * lb_user_passwd;
    QLabel * lb_user_birthday;
    QLabel * lb_user_age;
    QLabel * lb_user_phone;
    QLabel * lb_user_email;
    QLabel * lb_user_address;
    QLabel * lb_user_power;

    QComboBox * cb_user_power;
    QLineEdit * le_user_id;
    QLineEdit * le_user_name;
    QComboBox * cb_user_sex;
    QLineEdit * le_user_passwd;
    QLineEdit * le_user_birthday;
    QLineEdit * le_user_age;
    QLineEdit * le_user_phone;
    QLineEdit * le_user_email;
    QLineEdit * le_user_address;

    QHBoxLayout * hlayout_adduser;
    QHBoxLayout * h1layout_adduser;
    QHBoxLayout * h2layout_adduser;
    QHBoxLayout * h3layout_adduser;
    QHBoxLayout * h4layout_adduser;
    QHBoxLayout * h5layout_adduser;
    QHBoxLayout * h6layout_adduser;
    QHBoxLayout * h7layout_adduser;
    QHBoxLayout * h8layout_adduser;
    QHBoxLayout * h9layout_adduser;
    QHBoxLayout * h10layout_adduser;

    QPushButton * pb_confirm;
    QPushButton * pb_cancel;

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

    QVBoxLayout * vlayout_adduser;

    QString getstr_id(void);
    QString get_str_name(void);
    QString get_str_sex(void);
    QString get_str_passwd(void);
    QString get_str_birthday(void);
    QString get_str_age(void);
    QString get_str_phone(void);
    QString get_str_email(void);
    QString get_str_address(void);
    QString get_str_power(void);

public:
    void initView(void);
    void setView(void);
    void layoutView(void);
    void setSignalSlot(void);
signals:

public slots:
};
#endif // BASE_USER_H
