#include "header.h"

void createList(ListParent &LP, ListChild &LC){
    firstParent(LP) = NULL;
    firstChild(LC) = NULL;
}
adr_parent newParent(infotype info){
    adr_parent p;
    p = new parent;
    info(p) = info;
    nextOrtu(p) = NULL;
    nextAnak(p) = NULL;

    return p;
}
adr_child newChild(infotype info){
    adr_child c;
    c = new child;
    info(c) = info;
    nextAnak(c) = NULL;

    return c;
}
void insertParent(ListParent &LP, adr_parent p){
    if (firstParent(LP) == NULL){
        firstParent(LP) = p;
    }
    else{
        nextOrtu(p) = firstParent(LP);
        firstParent(LP) = p;
    }
}
void deleteParent(ListParent &LP){
    if (firstParent(LP) == NULL){
        cout<<"List Kosong!"<<endl<<endl;
    }
    else if (nextOrtu(firstParent(LP)) == NULL){
        firstParent(LP) = NULL;
    }
    else{
        adr_parent p = firstParent(LP);
        while(nextOrtu(nextOrtu(p)) != NULL){
            p = nextOrtu(p);
        }
        nextOrtu(p) = NULL;
    }
}
void showParent(ListParent LP){
    adr_parent p = firstParent(LP);
    cout<<endl;
    cout<<"List Orang : ";
    while(p != NULL){
        cout<<info(p)<<" ";
        p = nextOrtu(p);
    }
    cout<<endl;
    cout<<endl;
}
adr_parent findParent(ListParent LP, string parent){
    adr_parent p = firstParent(LP);
    while(p != NULL){
        if (info(p) == parent){
            cout<<endl;
            cout<<"Ditemukan! -> "<<info(p)<<endl<<endl;
            return p;
        }
        p = nextOrtu(p);
    }
    cout<<endl;
    cout<<"Orang ini tidak ada!"<<endl<<endl;
    return NULL;
}
void insertChild(ListParent &LP, ListChild &LC, adr_parent p){
    adr_child c;
    infotype nama;

    cout<<"Masukkan nama saudara: ";
    cin>>nama;
    cout<<endl;
    c = newChild(nama);

    nextAnak(c) = firstChild(LC);
    firstChild(LC) = c;

    if (nextAnak(p) == NULL){
        nextAnak(p) = c;
    }
    else{
        nextAnak(c) = nextAnak(p);
        nextAnak(p) = c;
    }
}
void deleteChild(ListParent &LP, ListChild &LC, adr_parent p){
    adr_child c;
    adr_child temp = firstChild(LC);

    if (nextAnak(p) == NULL){
        cout<<"Orang ini tidak memiliki saudara!"<<endl<<endl;
    }
    else if (nextAnak(nextAnak(p)) == NULL){
        cout<<"Menghapus saudara..."<<endl<<endl;
        if(temp == nextAnak(p)){
            firstChild(LC) = NULL;
        }
        else{
            while(nextAnak(temp) != nextAnak(p)){
                temp = nextAnak(temp);
            }
            nextAnak(temp) = nextAnak(nextAnak(temp));
        }
        nextAnak(p) = NULL;
    }
    else{
        c = nextAnak(p);
        while(nextAnak(nextAnak(c)) != NULL){
            c = nextAnak(c);
        }
        cout<<"Menghapus saudara..."<<endl<<endl;
        if(temp == nextAnak(p)){
            firstChild(LC) = NULL;
        }
        else{
            while(nextAnak(temp) != nextAnak(p)){
                temp = nextAnak(temp);
            }
            nextAnak(temp) = nextAnak(nextAnak(temp));
        }
        nextAnak(c) = NULL;
    }
}
void showChild(ListParent LP, adr_parent p){
    adr_child c;

    if (nextAnak(p) == NULL){
        cout<<"Orang ini tidak memiliki saudara!"<<endl<<endl;
    }
    else{
        c = nextAnak(p);
        cout<<"Saudara dari "<<info(p)<<" adalah : ";
        while(c != NULL){
            cout<<info(c)<<" ";
            c = nextAnak(c);
        }
        cout<<endl<<endl;
    }
}
adr_child findChild(ListParent LP, adr_parent p, string child){
    adr_child c;
    c = nextAnak(p);
        while(c != NULL){
            if (info(c) == child){
                cout<<endl;
                cout<<"Ditemukan! -> Saudara dari "<<child<<" adalah "<<info(p)<<endl<<endl;
                return c;
            }
            c = nextAnak(c);
        }
    cout<<endl;
    cout<<"Saudara tidak ditemukan pada parent ini!"<<endl<<endl;
    return NULL;
}
adr_child findAllChild(ListChild LC, string child){
    adr_child c = firstChild(LC);
    while(c != NULL){
        if(info(c) == child){
            cout<<endl;
            cout<<"Ditemukan!"<<endl<<endl;
            return c;
        }
        c = nextAnak(c);
    }
    cout<<endl;
    cout<<"Saudara tidak ditemukan!"<<endl<<endl;
    return NULL;
}
void sumChildParent(ListParent LP, ListChild LC){
    int x = 0;
    int y = 0;
    adr_parent p = firstParent(LP);
    adr_child c = firstChild(LC);

    while(p != NULL){
        x = x + 1;
        p = nextOrtu(p);
    }
     while(c != NULL){
        y = y + 1;
        c = nextAnak(c);
    }
    cout<<endl;
    cout<<"Total orang pada list adalah : "<<x<<endl;
    cout<<"Total saudara pada list adalah : "<<y<<endl;
    cout<<endl;
}
int selectMenu(){
    cout << "===== MENU ====="<<endl;
    cout << "1. Insert Parent"<<endl;
    cout << "2. Delete Parent"<<endl;
    cout << "3. Show Parent"<<endl;
    cout << "4. Find Parent"<<endl;
    cout << "5. Insert Child Of Parent X"<<endl;
    cout << "6. Delete Child Of Parent X"<<endl;
    cout << "7. Show Child Of Parent X"<<endl;
    cout << "8. Find Child Of Parent X"<<endl;
    cout << "9. Find Child Of All Parent"<<endl;
    cout << "10. Sum All Parent And Child"<<endl;

    cout<<endl;
    cout << "Masukkan menu: ";

    int input = 0;
    cin >> input;

    return input;
}
