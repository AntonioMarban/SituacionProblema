// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Tienda.h"
#include "Cliente.cpp"
#include "Producto.cpp"
using namespace std;

Tienda::Tienda(){
    identificadorT = "DF";
    nombreT = "DF";
    direccionT = "DF";
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    ingresoDiarioT = 0;
}

Tienda::Tienda(string idIn, string nomIn, string dirIn){
    identificadorT = idIn;
    nombreT = nomIn;
    direccionT = dirIn;
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    ingresoDiarioT = 0;
}

Tienda::~Tienda(){}

string Tienda::getIdentificadorT(){
    return identificadorT;
}

string Tienda::getNombreT(){
    return nombreT;
}

string Tienda::getDireccionT(){
    return direccionT;
}

int Tienda::getCantidadProductosT(){
    return cantidadProductosT;
}

int Tienda::getCandidadClientesT(){
    return cantidadClientesT;
}

Producto Tienda::getProductosT(){
    return productosT[PT];
}

Cliente Tienda::getClientesT(){
    return clientesT[CT];
}

double Tienda::getIngresoDiarioT(){
    return ingresoDiarioT;
}

void Tienda::setIdentificadorT(string idIn){
    identificadorT = idIn;
}

void Tienda::setNombreT(string nomIn){
    nombreT = nomIn;
}

void Tienda::setDireccionT(string dirIn){
    direccionT = dirIn;
}

void Tienda::setCantidadProductosT(int cantProd){
    cantidadClientesT = cantProd;
}

void Tienda::setCantidadClientesT(int cantCli){
    cantidadClientesT = cantCli;
}

void Tienda::setProductosT(Producto prod){
    productosT[PT] = prod;
}

void Tienda::setClientesT(Cliente cli){
    clientesT[CT] = cli;
}

void Tienda::setIngresoDiarioT(double ingIn){
    ingresoDiarioT = ingIn;
}

void Tienda::agregarLosProductos(string nombreArchivo){
    ifstream miArchivo; // objeto de tipo archivos de entrada
    miArchivo.open(nombreArchivo.c_str(), ios::out | ios::in);
    // el archivo cuyo nombre llega como parametro, se abre para lectura
    if (!miArchivo) // si el archivo no se encuentra, marcara error 
        cout<<"\nEl archivo no existe\n";
    else{
        cout<<"\nLleno el arreglo con los datos del archivo de texto\n";
        string clave, nombre;
        int categoria, cantidad, i = 0;
        float precio;
        while (!miArchivo.eof() && i < PT){ // cuido no llegar al fin del archivo 
        // y no rebasar el tamanio de mi arreglo
            miArchivo >> clave >> nombre >> categoria, precio, cantidad; // obtengo los valores del archivo y 
            // los paso a mis variables previamente definidas con el tipo requerido
            cout << clave << " " << nombre << " " << categoria << " " << precio << " " << cantidad << endl;
            productosT[i++].setProducto(clave, nombre, categoria, precio, cantidad); // actualizo el iesimo registro de personas
        }
    }
}

void Tienda::agregarElProducto(){
    cout << "Cuantos productos vas a agregar?" << endl;
    cin >> cantidadProductosT;
    for (int i; i<cantidadProductosT; cantidadProductosT++){
        cout << "****** Producto " << i+1 << " ********" << endl;
        // Pendiente de terminar, llenado de productos uno a uno.
        
    }
}

void Tienda::agregarCliente(){

}

void Tienda::llenarCarrito(){

}

void Tienda::imprimirTicketCompra(){

}

void Tienda::cerrarOperaciones(){

}
