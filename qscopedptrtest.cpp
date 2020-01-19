#include "qscopedptrtest.h"
#include <qdebug.h>

qscopedptrtest::qscopedptrtest(QObject *parent) : QObject(parent)
{
   // qInfo() << "Constructed" << this;
}

qscopedptrtest::~qscopedptrtest()
{
    //qInfo() << "Deconstructed" << this;
}
