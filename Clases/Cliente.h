// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 23/11/2022

#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

const int numeroCarrito = 10;

class Cliente{
    string productoAniadido;
    string identificadorC;
    string nombreC;
    string correoElectronicoC;
    string telefonoC;
    int cantidadProductosC;
    Producto carritoC[numeroCarrito];
    double totalC;
    public:
        // ======== Metodos constructores
        Cliente();
        Cliente(string, string, string, string);
        ~Cliente();
        // ======== Metodos Getters
        string getIdentificadorC();
        string getNombreC();
        string getCorreoElectronicoC();
        string getTelefonoC();
        Producto getCarritoC();
        int getCantidadProductosC();
        double getTotalC();
        // ======== Metodos Setters
        void setIdentificadorC(string);
        void setNombreC(string);
        void setCorreoElectronicoC(string);
        void setTelefonoC(string);
        void setCarritoC(Producto, int);
        void setTotalC(double);
        void setCantidadProductosC(int);
        void setCliente(string, string, string, string);
        // ======== Metodo de Impresion
        void imprimirCliente();
        void imprimirCarrito();
        void limpiarCarrito();
};