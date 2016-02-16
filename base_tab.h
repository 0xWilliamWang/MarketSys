#ifndef H
#define H

#include <QWidget>
#include <commonfile.h>


class BASE_TAB : public QWidget
{
    Q_OBJECT
public:
    explicit BASE_TAB(QWidget *parent = 0);

    QGridLayout * GridLayout0;
    QGridLayout * GridLayout1;
    QGridLayout * GridLayout2;
    QGridLayout * GridLayout3;
    QGridLayout * GridLayout4;
    QTableView * tableview0;

    QPushButton * PushButton0;
    QPushButton * PushButton1;
    QPushButton * PushButton2;
    QPushButton * PushButton3;

    QPushButton * PushButton4;
    QPushButton * PushButton5;
    QPushButton * PushButton6;
    QPushButton * PushButton7;

    QPushButton * PushButton8;
    QPushButton * PushButton9;
    QPushButton * PushButton10;
    QPushButton * PushButton11;

    QHBoxLayout * HBoxLayout0;
    QHBoxLayout * HBoxLayout1;
    QHBoxLayout * HBoxLayout2;
    QHBoxLayout * HBoxLayout3;
    QHBoxLayout * HBoxLayout4;
    QHBoxLayout * HBoxLayout5;

    QLineEdit * LineEdit0;
    QLineEdit * LineEdit1;
    QLineEdit * LineEdit2;
    QLineEdit * LineEdit3;
    QLineEdit * LineEdit4;
    QLineEdit * LineEdit5;

    QLabel * Label0;
    QLabel * Label1;
    QLabel * Label2;
    QLabel * Label3;
    QLabel * Label4;
    QLabel * Label5;


public:
    void initView(void);
    void setViewWidthLengh(void);
    void layoutView(void);
    void setLabelHeight_Width(int Height,int Width);
    int PUSHBUTTON_HEIGHT = 20;
    int PUSHBUTTON_WIDTH = 100;
    int LINEEDIT_HEIGHT = 20;
    int LINEEDIT_WIDTH = 70;
    int LABEL_HEIGHT = 20;
    int LABEL_WIDTH = 70;
    int CHILD_SPACING = 30;
    int MAIN_SPACING = 0;

signals:

public slots:


public:

    void setPushButton0Name(QString src);
    void setPushButton1Name(QString src);
    void setPushButton2Name(QString src);
    void setPushButton3Name(QString src);
    void setPushButton4Name(QString src);
    void setPushButton5Name(QString src);
    void setPushButton6Name(QString src);
    void setPushButton7Name(QString src);
    void setPushButton8Name(QString src);
    void setPushButton9Name(QString src);
    void setPushButton10Name(QString src);
    void setPushButton11Name(QString src);

    void setLabel0Name(QString src);
    void setLabel1Name(QString src);
    void setLabel2Name(QString src);
    void setLabel3Name(QString src);
    void setLabel4Name(QString src);
    void setLabel5Name(QString src);

    QString getLineEdit0Text(void);
    QString getLineEdit1Text(void);
    QString getLineEdit2Text(void);
    QString getLineEdit3Text(void);
    QString getLineEdit4Text(void);
    QString getLineEdit5Text(void);
};

#endif // H
