#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <commonfile.h>

class USER_LOGIN : public QWidget
{
    Q_OBJECT
public:
    explicit USER_LOGIN(QWidget *parent = 0);

signals:

public slots:
    void displayTime();
    void slots_login();
    void slots_register();

public:
    ~USER_LOGIN();

    /*UI*/
private:
    QLabel * label_id;
    QLabel * label_passwd;
    QLabel * label_power;
    QLabel * label_picture;
    QLabel * label_time;
    QLabel * label_showtime;
    QLineEdit * linedit_id;
    QLineEdit * linedit_passwd;
    QComboBox * combobox_power;
    QHBoxLayout * hlayout;
    QHBoxLayout * h1layout;
    QHBoxLayout * h2layout;
    QHBoxLayout * h3layout;
    QHBoxLayout * h4layout;
    QHBoxLayout * h5layout;
    QHBoxLayout * layout_time;
    QVBoxLayout * vlayout;
    QGridLayout * glayout;
    QPushButton * pb_login;
    QPushButton * pb_register;
    QPushButton * pb_reset;
    QPushButton * pb_exit;
    QTimer *timer;
    private:
    void initView();
    void setView();
    void set_Layout();
    void setSignalSlot();

    /*back*/
private:
    QString m_UserID;
    QString m_UserPassword;
    QString m_UserPower;
    QSqlTableModel *userLoginModel;

};

#endif // LOGIN_H
