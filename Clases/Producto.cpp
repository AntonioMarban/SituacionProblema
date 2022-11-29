// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

Producto::Producto(){
    claveT = "DF";
    nombreP = "DF";
    categoriaP = 0;
    precioP = 0;
    cantidadP = 0;
}


Producto::Producto(string clave, string nombre, int cat, float pre, int cant){
    claveT = clave;
    nombreP = nombre;
    categoriaP = cat;
    precioP = pre;
    cantidadP = cant;
}

Producto::~Producto(){}

string Producto::getClaveT(){
    return claveT;
}

string Producto::getNombreP(){
    return nombreP;
}

int Producto::getCategoriaP(){
    return categoriaP;
}

float Producto::getPrecioP(){
    return precioP;
}

int Producto::getCantidadP(){
    return cantidadP;
}

void Producto::setClaveT(string clave){
    claveT = clave;
}

void Producto::setNombreP(string nombre){
    nombreP = nombre;
}

void Producto::setCategoriaP(int categoria){
    categoriaP = categoria;
}

void Producto::setPrecioP(float precio){
    precioP = precio;
}

void Producto::setCantidadP(int cantidad){
    cantidadP = cantidad;
}

void Producto::setProducto(string claveIn, string nombreIn, int catIn, float precioIn, int cantIn){
    claveT = claveIn;
    nombreP = claveIn;
    categoriaP = catIn;
    precioP = precioIn;
    cantidadP = cantIn;
}

void Producto::imprimirProducto(){
    cout << "La clave es: " << claveT << endl;
    cout << "El nombre es:" << nombreP << endl;
    cout << "La categoria es: " << categoriaP << endl;
    cout << "El precio es: " << precioP << endl;
    cout << "La cantidad es: " << cantidadP << endl;
    cout << "=================================================================" << endl;
}