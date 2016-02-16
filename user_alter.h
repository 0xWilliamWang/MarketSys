#ifndef USER_H
#define USER_H

#include <QWidget>
#include <commonfile.h>
#include "base_user.h"




class USER_ALTER : public BASE_USER
{
    Q_OBJECT
public:
    explicit USER_ALTER(BASE_USER *parent = 0);

    void setSignalSlot();
public:
    void initData(void);

signals:
    void userAlterSucceed(void);
public slots:
    void setData(void);
};

#endif // USER_H
