#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"
using namespace std;

int main() {
    ArbolBinarioAVL<int> productos;

    int op = 0;
    while (op < 6) {
        cout << "Ingrese que desea hacer: " << endl;
        cout << " 1.	Insertar un codigo de producto." << endl;
        cout << "2.	Eliminar un codigo de producto." << endl;
        cout << "3.	Buscar un producto por codigo." << endl;
        cout << "4.	Imprimir el arbol (mostrando su estructura balanceada)." << endl;
        cout << "5.	Salir del programa." << endl;
        cin >> op;

        int codigo;
        switch (op) {
            case 1: cout << "ingrese codigo de producto: " << endl;
                cin >> codigo;
                try {
                    productos.put(codigo);
                    cout << "se inserto codigo" << endl;
                } catch (int e) {
                    if (e == 200) {
                        cout << "el codigo ya existe o es erroneo " << endl;
                    }
                }
                break;
            case 2:
                cout << "ingrese codigo de producto: " << endl;
                cin >> codigo;
                productos.remove(codigo);
                cout << "se removio codigo" << endl;
                break;
            case 3: cout << "ingrese codigo de producto: " << endl;
                cin >> codigo;
                try {
                    productos.search(codigo);
                    cout << "se encontro el codigo" << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "el codigo no se encontro  " << endl;
                    }
                }

                break;
            case 4: cout << "Se muestra Arbol Balanceado: " << endl;
                productos.print();
                cout << "balance: " << productos.getBalance();
                break;
            case 5:
                exit(-1);
            default: cout << "error en la respuesta" << endl;
        }
    }


    return 0;
}
