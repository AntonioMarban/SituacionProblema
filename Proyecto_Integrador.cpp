// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 21/11/2022

#include <iostream>
#include <string>
#include "Clases/Producto.cpp"
#include "Clases/Cliente.cpp"
#include "Clases/Tienda.cpp"
using namespace std;

int main(){
    // Pruebas de la clase "Producto"
    Producto P1;
    // P1.imprimirProducto();
    // P2.imprimirProducto();
    // P1.setCantidadP(24);
    // P1.imprimirProducto();
    // P2.setCantidadP(56);
    // P2.imprimirProducto();
    // string claveP2 = P2.getClaveT();
    // cout << "La clave del P2 con el metodo get es: " << claveP2 << endl;

    // Pruebas de la clase "Cliente"

    Tienda Prueba;
    // Prueba.agregarLosProductos("MiCarrito.txt");
    Prueba.agregarCliente();
    Prueba.imprimirTienda();
    Prueba.imprimirClientes();

}