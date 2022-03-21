#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListParent LP;
    ListChild LC;
    adr_parent p;
    infotype data;
    string nama;

    createList(LP, LC);

    int pilihan = 0;

    pilihan = selectMenu();
    while (pilihan != 0){
        switch(pilihan){
    case 1:
        cout<<"Nama orang: ";
        cin>>data;
        p = newParent(data);
        insertParent(LP, p);
        cout<<endl;
        pilihan = selectMenu();
        break;
    case 2:
        cout<<endl;
        cout<<"Menghapus orang terakhir..."<<endl<<endl;
        deleteParent(LP);
        pilihan = selectMenu();
        break;
    case 3:
        showParent(LP);
        pilihan = selectMenu();
        break;
    case 4:
        cout << "Masukkan nama orang yang ingin dicari: ";
        cin >> nama;
        p = findParent(LP, nama);
        pilihan = selectMenu();
        break;
    case 5:
        cout << "Masukkan nama orang yang ingin ditambahkan saudara: ";
        cin >> nama;
        p = findParent(LP, nama);
        if (p != NULL){
            insertChild(LP, LC, p);
        }
        pilihan = selectMenu();
        break;
    case 6:
        cout << "Masukkan nama orang yang ingin dihapuskan saudara: ";
        cin >> nama;
        p = findParent(LP, nama);
        deleteChild(LP, LC, p);
        pilihan = selectMenu();
        break;
    case 7:
        cout << "Masukkan nama orang yang ingin ditampilkan saudara: ";
        cin >> nama;
        p = findParent(LP, nama);
        showChild(LP, p);
        pilihan = selectMenu();
        break;
    case 8:
        cout << "Masukkan nama orang yang ingin ditelusuri: ";
        cin >> nama;
        p = findParent(LP, nama);
        cout << "Masukkan nama saudara yang ingin dicari: ";
        cin >> nama;
        findChild(LP, p, nama);
        pilihan = selectMenu();
        break;
    case 9:
        cout << "Masukkan nama saudara yang ingin dicari: ";
        cin >> nama;
        findAllChild(LC, nama);
        pilihan = selectMenu();
        break;
    case 10:
        sumChildParent(LP, LC);
        pilihan = selectMenu();
        break;

        }
    }
    cout<<endl;
    cout<<"==END OF MENU==";
    cout<<endl;
}
