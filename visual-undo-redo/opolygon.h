#ifndef OPOLYGON_H
#define OPOLYGON_H

#include <QtWidgets/QWidget>
#include <QVector>
#include "onode.h"

class OPolygon : public QWidget
{
    Q_OBJECT
public:
    explicit OPolygon(QWidget *parent = 0);
    ~OPolygon();
    QByteArray toByte();
    void fill(QDataStream *stream);
    void setIsClosed(bool connect);
    bool isClosed();

    QVector <ONode *> onePoly;
    qint32 Id;
    bool visibility;
    bool endToFirst;

};

#endif // OPOLYGON_H
