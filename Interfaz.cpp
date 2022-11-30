// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 21/11/2022

#include <iostream>
#include <string>
#include "Clases/Producto.cpp"
#include "Clases/Cliente.cpp"
#include "Clases/Tienda.cpp"
using namespace std;

int main(){
    string identificadorTienda, nombreTienda, direccionTienda, nombreArchivo;
    cout << "\nBienvenido! Por favor ingrese el identificador de la tienda: " << endl;
    cin >> identificadorTienda;
    cout << "\nA continuacion ingrese el nombre de la tienda: " << endl;
    cin >> nombreTienda;
    cout << "\nIngrese la direccion de la tienda: " << endl;
    cin >> direccionTienda;
    cout << "\nPor ultimo, ingrese el nombre del archivo que contendra los datos de los productos." << endl;
    cin >> nombreArchivo;

    Tienda tiendita(identificadorTienda, nombreTienda, direccionTienda); // Genero un objeto tipo Tienda.h con los parametros que ingresó el usuario.

    cout << "\n\nBienvenido a la tienda virtual de \"" << tiendita.getNombreT() << "\"" << endl;

    int eleccion;
    do {
        cout << "\nPor favor elija una opcion del menu" << endl;
        cout << "\n[1] Agregar productos desde archivo" << endl;
        cout << "[2] Agregar productos uno a uno" << endl;
        cout << "[3] Agregar clientes" << endl;
        cout << "[4] Comprar productos" << endl;
        cout << "[5] Realizar cierre del dia" << endl;
        cout << "[6] Salir\n" << endl;

        cin >> eleccion;
        if (eleccion > 6 || eleccion < 0) {
            cout << "\nEsa no es una opcion valida." << endl;
        }
        else if (eleccion == 1) {
            // Agregar productos desde archivo
        }
        else if (eleccion == 2) {

        }
    }
    while(eleccion > 6 || eleccion < 0);    
}