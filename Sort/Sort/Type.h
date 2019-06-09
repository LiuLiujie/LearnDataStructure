#pragma once

#define MAXSIZE 20
typedef int KeyType;
typedef char InfoType;

struct RedType{
    KeyType key;
    InfoType otherInfo;
};

struct SqList{
    RedType r[MAXSIZE + 1];//0Î»ÏÐÖÃ»òµ±ÉÚ±ø
    int length;
};
