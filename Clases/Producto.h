// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 21/11/2022

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Producto{
    string claveT;
    string nombreP;
    int categoriaP;
    float precioP;
    int cantidadP;
    public:
        // ======== Metodos constructores
        Producto();
        Producto(string, string, int, float);
        ~Producto();
        // ======== Metodos Getters
        string getClaveT();
        string getNombreP();
        int getCategoriaP();
        float getPrecioP();
        int getCantidadP();
        int getCantidadProductosC();
        // ======== Metodos Setters
        void setClaveT(string);
        void setNombreP(string);
        void setCategoriaP(int);
        void setPrecioP(float);
        void setCantidadP(int);
        void setProducto(string, string, int, float, int);
        // ======== Metodo de Impresion
        void imprimirProducto();
};