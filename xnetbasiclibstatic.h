#ifndef XNETBASICLIBSTATIC_H
#define XNETBASICLIBSTATIC_H
#include <iostream>

#include "xnetbasiclibstatic_global.h"



class XNETBASICLIBSTATIC_EXPORT Xnetbasiclibstatic
{    
public:
    Xnetbasiclibstatic();

    //converts a std::string to QString
    QString stringToQstring(std::string string);
// different number types to QString
    QString numberToQstring(int number);
    QString numberToQstring(short number);
    QString numberToQstring(float number);
    QString numberToQstring(double number);
    QString numberToQstring(long number);
    QString numberToQstring(qint8 number);
   // QString numberToQstring(qint16 number);
   // QString numberToQstring(qint32 number);
    QString numberToQstring(qint64 number);
    QString numberToQstring(quint8 number);
    QString numberToQstring(quint16 number);
    QString numberToQstring(quint32 number);
    QString numberToQstring(quint64 number);
//

    //creates a simple message box with a ok button
    void messagebox(QString message);
    void messagebox(std::string message);
    //creates a simple message box with yes and no buttons, returns true for yes
    //returns NULL if yes or no is not selected(if possible)
    bool messageboxYN(QString message, QString title);
    bool messageboxYN(std::string message, std::string title);


};

#endif // XNETBASICLIBSTATIC_H
