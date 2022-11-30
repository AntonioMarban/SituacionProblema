// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Producto.cpp"
using namespace std;

Cliente::Cliente(){
    identificadorC = "DF";
    nombreC = "DF";
    correoElectronicoC = "DF";
    telefonoC = "DF"; 
    cantidadProductosC = 0;
    totalC = 0;
}

Cliente::Cliente(string idIN, string nomIN, string corrIN, string telIN){
    identificadorC = idIN;
    nombreC = nomIN;
    correoElectronicoC = corrIN;
    telefonoC = telIN;
    cantidadProductosC = 0;
    totalC = 0;
}

Cliente::~Cliente(){}

string Cliente::getIdentificadorC() {
    return identificadorC;
}

string Cliente::getNombreC() {
    return nombreC;
}

string Cliente::getCorreoElectronicoC() {
    return correoElectronicoC;
}

string Cliente::getTelefonoC() {
    return telefonoC;
}

Producto Cliente::getCarritoC() {
    return carritoC[numeroCarrito];
}

double Cliente::getTotalC() {
    return totalC;
}

int Cliente::getCantidadProductosC() {
    return cantidadProductosC;
}

void Cliente::setIdentificadorC(string identificadorC) {
    this ->identificadorC = identificadorC;
}

void Cliente::setNombreC(string nombreC) {
    this ->nombreC = nombreC;
} 

void Cliente::setCorreoElectronicoC(string correoElectronicoC) {
    this ->correoElectronicoC = correoElectronicoC;
}

void Cliente::setTelefonoC(string telefonoC) {
    this ->telefonoC = telefonoC;
}

void Cliente::setCarritoC(Producto carritoC) {
    this ->carritoC[numeroCarrito] = carritoC;
}

void Cliente::setTotalC(double totalC) {
    this ->totalC = totalC;
}

void Cliente::setCantidadProductosC(int cantidadProductos) {
    cantidadProductosC = cantidadProductos;
}

void Cliente::setCliente(string idIN, string nomIN, string corrIN, string telIN) {
    identificadorC = idIN;
    nombreC = nomIN;
    correoElectronicoC = corrIN;
    telefonoC = telIN;
    totalC = 0;
}

void Cliente::imprimirCliente() {
    cout << "\nEl identificador del cliente es: " << identificadorC << endl;
    cout << "Su nombre es: " << nombreC << endl;
    cout << "Su telefono es: " << telefonoC << endl;
    cout << "Su correo electronico es: " << correoElectronicoC << endl;
    // cout << "Su carrito es: " << carritoC << endl;
    cout << "La cantidad de productos que lleva es: " << cantidadProductosC << endl;
    cout << "El total de su compra es : " << totalC << endl;
}