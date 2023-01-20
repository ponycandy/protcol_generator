#ifndef META_STRUCT_LIST_H
#define META_STRUCT_LIST_H

#include "metafile.h"
#include "QMap"
class meta_struct_list
{
public:
    meta_struct_list();
     QMap<int,metafile*> contents;
     QString self_name;
};

#endif // META_STRUCT_LIST_H
