#include "xnetbasiclibstatic.h"
#include <QMessageBox>
#include <QString>

Xnetbasiclibstatic::Xnetbasiclibstatic()
{
}



QString Xnetbasiclibstatic::stringToQstring(std::string string)
{
    return QString::fromStdString(string);
}

QString Xnetbasiclibstatic::numberToQstring(int number)
{
    return QString::number(number);
}

QString Xnetbasiclibstatic::numberToQstring(short number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(float number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(double number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(long number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(qint8 number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(qint64 number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(quint8 number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(quint16 number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(quint32 number)
{
    return QString::number(number);

}

QString Xnetbasiclibstatic::numberToQstring(quint64 number)
{
    return QString::number(number);
}

void Xnetbasiclibstatic::messagebox(QString message)
{
    QMessageBox messagebox;
    messagebox.setText(message);
    messagebox.exec();
}

void Xnetbasiclibstatic::messagebox(std::string message)
{
    QMessageBox messagebox;
    messagebox.setText(Xnetbasiclibstatic::stringToQstring(message));
    messagebox.exec();
}

bool Xnetbasiclibstatic::messageboxYN(QString message, QString Title)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(Title);
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Yes:
    {
        return true;
    }

    case QMessageBox::No:
    {
        return false;
    }
    }
    return NULL;
}

bool Xnetbasiclibstatic::messageboxYN(std::string message, std::string title)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(Xnetbasiclibstatic::stringToQstring(title));
    msgBox.setText(Xnetbasiclibstatic::stringToQstring(message));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Yes:
    {
        return true;
    }

    case QMessageBox::No:
    {
        return false;
    }
    }
    return NULL;
}



