#include "qpointertest.h"

qpointertest::qpointertest(QObject *parent) : QObject(parent)
{

}

void qpointertest::useWidget()
{
    //see if there is a pointer
    if(!widget.data())
    {
        qInfo() << "No Pointer!!!";
        return;
    }

    qInfo() << "Widget = " << widget.data();

    //Access the pointer
    widget.data()->setObjectName("swag object");

}
