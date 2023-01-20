#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>
#include <struct_editor.h>
#include <struct_database.h>
#include <mainfilegenerator.h>
class windowmanager : public QObject
{
    Q_OBJECT
public:
    explicit windowmanager(QObject *parent = nullptr);
    struct_editor *m_editor;
    struct_database *m_database;
    mainfilegenerator *maingen;
    void setupevent();

signals:

};

#endif // WINDOWMANAGER_H
