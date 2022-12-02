// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

Producto::Producto(){ // Constructor por omision de la clase Producto
    claveT = "DF";
    nombreP = "DF";
    categoriaP = 0;
    precioP = 0;
    cantidadP = 0;
}


Producto::Producto(string clave, string nombre, int categoria, float precio){ // Constructor de la clase Producto con valores introducidos por el usuario o la aplicacion
    claveT = clave;
    nombreP = nombre;
    categoriaP = categoria;
    precioP = precio;
    cantidadP = 0;
}

Producto::~Producto(){} // Destructor de la clase

string Producto::getClaveT(){ // Este metodo obtiene la clave del producto
    return claveT;
}

string Producto::getNombreP(){ // Este metodo obtiene el nombre del producto
    return nombreP;
}

int Producto::getCategoriaP(){ // Este metodo obtiene la categoria  del producto
    return categoriaP;
}

float Producto::getPrecioP(){ // Este metodo obtiene el precio del producto
    return precioP;
}

int Producto::getCantidadP(){ // Este metodo obtiene la cantidad del producto
    return cantidadP;
}

void Producto::setClaveT(string clave){ // Este metodo establece la clave del producto por un valor dado
    claveT = clave;
}

void Producto::setNombreP(string nombre){ // Este metodo establece el nombre del producto por un valor dado
    nombreP = nombre;
}

void Producto::setCategoriaP(int categoria){ // Este metodo establece la categoria del producto por un valor dado
    categoriaP = categoria;
}

void Producto::setPrecioP(float precio){ // Este metodo establece el precio del producto por un valor dado
    precioP = precio;
}

void Producto::setCantidadP(int cantidad){ // Este metodo establece la cantidad del producto por un valor dado
    cantidadP = cantidad;
}

void Producto::setProducto(string clave, string nombre, int categoria, float precio, int cantidad){ // Este metodo establece todos los atributos del producto los valores dados
    claveT = clave;
    nombreP = nombre;
    categoriaP = categoria;
    precioP = precio;
    cantidadP = cantidad;
}

void Producto::imprimirProducto(){ // Este metodo imprime todos los atributos de un producto
    cout << "================= " << nombreP << " =================";
    cout << "\nLa clave es: " << claveT << endl;
    cout << "La categoria es: " << categoriaP << endl;
    cout << "El precio es: $" << precioP << endl;
}