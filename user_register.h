#ifndef USER_REGISTER_H
#define USER_REGISTER_H

#include "commonfile.h"
#include "base_user.h"
class USER_REGISTER : public BASE_USER
{
    Q_OBJECT
public:
    explicit USER_REGISTER(BASE_USER *parent = 0);

signals:

public slots:
    void slots_register_confirm(void);
};


#endif // USER_REGISTER_H
