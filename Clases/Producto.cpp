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


Producto::Producto(string clave, string nombre, int categoria, float precio, int cantidad){
    claveT = clave;
    nombreP = nombre;
    categoriaP = categoria;
    precioP = precio;
    cantidadP = cantidad;
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

void Producto::setProducto(string clave, string nombre, int categoria, float precio, int cantidad){
    claveT = clave;
    nombreP = nombre;
    categoriaP = categoria;
    precioP = precio;
    cantidadP = cantidad;
}

void Producto::imprimirProducto(){
    cout << "\n====================================== " << endl;
    cout << "\nLa clave de la tienda del producto es: " << claveT << endl;
    cout << "El nombre del producto es:" << nombreP << endl;
    cout << "La categoria del producto es: " << categoriaP << endl;
    cout << "El precio individual es: " << precioP << endl;
    cout << "\n====================================== " << endl;
}