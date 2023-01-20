
#include <QApplication>
#include "windowmanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    windowmanager *m_manager=new windowmanager;
    return a.exec();
}
