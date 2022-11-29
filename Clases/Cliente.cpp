// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022
// Waaaaaaaaaaaaaaaaaaaa
// Tercer commit
//waaa
// Esto es un test

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
    totalC = 0;
}

Cliente::Cliente(string idIN, string nomIN, string corrIN, string telIN){
    identificadorC = idIN;
    nombreC = nomIN;
    correoElectronicoC = corrIN;
    telefonoC = telIN;
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

void Cliente::imprimirCliente() {
    cout << "El identificador del cliente es: " << identificadorC << endl;
    cout << "Su nombre es: " << nombreC << endl;
    cout << "Su telefono es: " << telefonoC << endl;
    cout << "Su correo electronico es: " << correoElectronicoC << endl;
    cout << "Su carrito es: " << carritoC << endl;
    cout << "El total de su compra es : " << totalC << endl;
}