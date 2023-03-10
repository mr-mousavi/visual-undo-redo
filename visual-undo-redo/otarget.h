#ifndef OTARGET_H
#define OTARGET_H

#include <QPoint>
#include <QVector>
#include "onode.h"
#include <QByteArray>

class OTarget
{
public:
    OTarget();
    QVector <ONode*> coordinate;     //error: 'QWidget& QWidget::operator=(const QWidget&)' is private   neshan midahad k copy constructor nadarad.k bayad ONode* tarif kionim.
    qint32 Id;
    qint32 speed ;

    QByteArray toByte();
    void fill(QDataStream *stream);

};

#endif // OTARGET_H
