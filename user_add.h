#ifndef USER_ADD_H
#define USER_ADD_H
#include <QWidget>
#include <commonfile.h>
#include "base_user.h"

class USER_ADD : public BASE_USER
{
    Q_OBJECT
public:
    USER_ADD();
signals:
    void userAddSucceed();
public slots:
    void setUserData(void);
};

#endif // USER_ADD_H
