#include <iostream>
#include "list.h"
using namespace std;
int main() {
    List lista;
    char command;
    while (cin >> command) {
        if (command == 'i') {
            int wartosc;
            cin >> wartosc;
            lista.addAfter(wartosc);
        }
        if(command == 'd')
            lista.deleteFirst();
        if(command == 's') {
            int wartosc;
            cin >> wartosc;
            cout << lista.getIndex(wartosc) << endl;
        }
        if(command == 'q') {
            lista.deleteAll();
            return 0;
        }
    }
    return 0;
}
