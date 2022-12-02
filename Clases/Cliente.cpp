// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Producto.cpp"
using namespace std;

Cliente::Cliente(){ // Constructor por omision de la clase Cliente
    identificadorC = "DF";
    nombreC = "DF";
    correoElectronicoC = "DF";
    telefonoC = "DF"; 
    cantidadProductosC = 0;
    totalC = 0;
}

Cliente::Cliente(string idIN, string nomIN, string corrIN, string telIN){ // Constructor de la clase Cliente con valores introducidos por el usuario o la aplicacion
    identificadorC = idIN;
    nombreC = nomIN;
    correoElectronicoC = corrIN;
    telefonoC = telIN;
    cantidadProductosC = 0;
    totalC = 0;
}

Cliente::~Cliente(){} // Destructor de la clase Cliente

string Cliente::getIdentificadorC() { // Este metodo obtiene el identificador del cliente
    return identificadorC;
}

string Cliente::getNombreC() { // Este metodo obtiene el nombre del cliente
    return nombreC;
}

string Cliente::getCorreoElectronicoC() { // Este metodo obtiene el correo electronico del cliente
    return correoElectronicoC;
}

string Cliente::getTelefonoC() { // Este metodo obtiene el telefono del cliente
    return telefonoC;
}

Producto Cliente::getCarritoC() { // Este metodo obtiene el arreglo del carrito del cliente
    return carritoC[numeroCarrito];
}

double Cliente::getTotalC() { // Este metodo obtiene el total del carrito del cliente
    return totalC;
}

int Cliente::getCantidadProductosC() { // Este metodo obtiene la cantidad de productos del carrito del cliente
    return cantidadProductosC;
}

void Cliente::setIdentificadorC(string identificadorC) { // Este metodo establece el identificador del cliente por un valor dado
    this ->identificadorC = identificadorC;
}

void Cliente::setNombreC(string nombreC) { // Este metodo establece el nombre del cliente por un valor dado
    this ->nombreC = nombreC;
} 

void Cliente::setCorreoElectronicoC(string correoElectronicoC) { // Este metodo establece el correo del cliente por un valor dado
    this ->correoElectronicoC = correoElectronicoC;
}

void Cliente::setTelefonoC(string telefonoC) { // Este metodo establece el telefono del cliente por un valor dado
    this ->telefonoC = telefonoC;
}

void Cliente::setCarritoC(Producto producto, int indice, int cantidad) { // Este metodo establece el arreglo del carrito del cliente por un valor dado
    carritoC[indice] = producto;
    carritoC[indice].setCantidadP(cantidad);

    cantidadProductosC++;
}

void Cliente::setTotalC(double totalC) { // Este metodo establece el total del cliente por un valor dado
    this ->totalC = totalC;
}

void Cliente::setCantidadProductosC(int cantidadProductos) { // Este metodo establece la cantidad de productos del cliente por un valor dado
    cantidadProductosC = cantidadProductos;
}

void Cliente::setCliente(string idIN, string nomIN, string corrIN, string telIN) { // Este metodo establece todos los atributos de un cliente por valores dados
    identificadorC = idIN;
    nombreC = nomIN;
    correoElectronicoC = corrIN;
    telefonoC = telIN;
    totalC = 0;
}

void Cliente::imprimirCliente() { // Este metodo imprime todos los atributos de un cliente
    cout << "\nEl identificador del cliente es: " << identificadorC << endl;
    cout << "Su nombre es: " << nombreC << endl;
    cout << "Su telefono es: " << telefonoC << endl;
    cout << "Su correo electronico es: " << correoElectronicoC << endl;
    cout << "La cantidad de productos que lleva es: " << cantidadProductosC << endl;
    cout << "El total de su compra es: $" << totalC << endl;
    cout << endl;

}

void Cliente::imprimirCarrito() {
    for (int i = 0; i < cantidadProductosC; i++) {
        cout << "\nProducto " << i+1 << endl;
        carritoC[i].imprimirProducto();
        cout << "La cantidad es: " << carritoC[i].getCantidadP() << endl;
    }
}

void Cliente::limpiarCarrito(){
    for (int i = 0; i<numeroCarrito; i++){
        carritoC[i].setClaveT("DF");
        carritoC[i].setNombreP("DF");
        carritoC[i].setCategoriaP(0);
        carritoC[i].setPrecioP(0);
        carritoC[i].setCantidadP(0);
        cantidadProductosC = 0;
        totalC = 0;
    }
}