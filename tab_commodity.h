#ifndef COMMODITY_H
#define COMMODITY_H

#include <QWidget>
#include "base_tab.h"
class COMMODITY : public BASE_TAB
{
    Q_OBJECT
public:
    explicit COMMODITY(BASE_TAB *parent = 0);

    void initViewData();
    void createCommodityTable(void);
    void setViewVisible(void);

signals:

public slots:
};

#endif // COMMODITY_H
