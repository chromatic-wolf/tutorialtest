#ifndef QSCOPEDPTRTEST_H
#define QSCOPEDPTRTEST_H

#include <QObject>

class qscopedptrtest : public QObject
{
    Q_OBJECT
public:
    explicit qscopedptrtest(QObject *parent = nullptr);
    ~qscopedptrtest();
signals:

};

#endif // QSCOPEDPTRTEST_H
