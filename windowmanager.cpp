#include "windowmanager.h"

windowmanager::windowmanager(QObject *parent) : QObject(parent),m_editor(NULL),m_database(NULL),maingen(NULL)
{
    m_editor=new struct_editor;
    m_database=new struct_database;
    maingen=new mainfilegenerator;
    m_editor->show();

    setupevent();
}

void windowmanager::setupevent()
{
    qRegisterMetaType<struct_description>("struct_description");
    connect(m_editor,SIGNAL(sig_new_struct_created(struct_description)),m_database,SLOT(slot_on_new_added(struct_description)));

    connect(m_editor,SIGNAL(sig_start_gen(QString)),m_database,SLOT(slot_on_generated(QString)));

}
