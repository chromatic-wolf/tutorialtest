#ifndef QPOINTERTEST_H
#define QPOINTERTEST_H

#include <QObject>
#include <QDebug>
#include <QPointer>

class qpointertest : public QObject
{
    Q_OBJECT
public:
    explicit qpointertest(QObject *parent = nullptr);

    QPointer<QObject> widget;

    void useWidget();

signals:

};

#endif // QPOINTERTEST_H
