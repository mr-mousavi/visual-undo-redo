#ifndef HISTORY_H
#define HISTORY_H

#include "action.h"
#include <QVector>

static QVector <Action *> undoList;
static QVector <Action *> redoList;

 class History
{
public:
    History();
};

#endif // HISTORY_H
