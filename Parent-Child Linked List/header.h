#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define nextOrtu(P) (P)->nextOrtu
#define nextAnak(P) (P)->nextAnak

#define firstParent(L) ((L).firstParent)
#define firstChild(L) ((L).firstChild)

typedef struct parent* adr_parent;
typedef struct child* adr_child;
typedef string infotype;

struct parent{
    infotype info;
    adr_parent nextOrtu;
    adr_child nextAnak;
};
struct child{
    infotype info;
    adr_child nextAnak;
};
struct ListParent{
    adr_parent firstParent;
};
struct ListChild{
    adr_child firstChild;
};

void createList(ListParent &LP, ListChild &LC);
adr_parent newParent(infotype info);
adr_child newChild(infotype info);
void insertParent(ListParent &LP, adr_parent p);
void deleteParent(ListParent &LP);
void showParent(ListParent LP);
adr_parent findParent(ListParent LP, string parent);
void insertChild(ListParent &LP, ListChild &LC, adr_parent p);
void deleteChild(ListParent &LP, ListChild &LC, adr_parent p);
void showChild(ListParent LP, adr_parent p);
adr_child findChild(ListParent LP, adr_parent p, string child);
adr_child findAllChild(ListChild LC, string child);
void sumChildParent(ListParent LP, ListChild LC);
int selectMenu();


#endif // HEADER_H_INCLUDED
