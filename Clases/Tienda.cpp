// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

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

void Tienda::setClientesT(Cliente cli, int indice){
    clientesT[indice] = cli;
}

void Tienda::setIngresoDiarioT(double ingIn){
    ingresoDiarioT = ingIn;
}

void Tienda::imprimirTienda() {
    cout << "\nSu identificador es: " << identificadorT << endl;
    cout << "Su nombre es: " << nombreT << endl;
    cout << "Su direccion es: " << direccionT << endl;
    cout << "La tienda tiene " << cantidadProductosT << " productos" << endl;
    cout << "La tienda tiene " << cantidadClientesT << " clientes"<< endl;
}

void Tienda::imprimirClientes() {
    for (int i = 0; i < cantidadClientesT; i++) {
        clientesT[i].imprimirCliente();
    }
}

void Tienda::agregarLosProductos(string nombreArchivo){
    ifstream miArchivo; // objeto de tipo archivos de entrada
    miArchivo.open(nombreArchivo.c_str(), ios::out | ios::in);
    // el archivo cuyo nombre llega como parametro, se abre para lectura
    cout<<"\nLleno el arreglo con los datos del archivo de texto\n";
    string clave, nombre;   
    int categoria, i = cantidadProductosT;
    float precio;
    while (!miArchivo.eof()){ // cuido no llegar al fin del archivo 
    // y no rebasar el tamanio de mi arreglo
        miArchivo >> clave >> nombre >> categoria >> precio; // obtengo los valores del archivo y 
        // los paso a mis variables previamente definidas con el tipo requerido
        cout << clave << " " << nombre << " " << categoria << " " << precio << endl;
        productosT[i++].setProducto(clave, nombre, categoria, precio, 0); // actualizo el iesimo registro de personas
    }
    cantidadProductosT += i;
    miArchivo.close();
}

void Tienda::agregarElProducto(){
    int agregados = 0;
    cout << "Cuantos productos vas a agregar?" << endl;
    cin >> agregados;
    cantidadProductosT += agregados;
    for (int i = 0; i<cantidadProductosT; i++){
        cout << "\n****** Producto " << i+1 << " ********" << endl;
        string claveTIn, nombrePIn;
        int categoriaPIn, cantidadPIn;
        float precioPIn;
        cout << "\nClave de la tienda del producto: ";
        cin >> claveTIn;
        cout << "\nNombre del producto: ";
        cin >> nombrePIn;
        cout <<  "\nCategoria del producto: ";
        cin >> categoriaPIn;
        cout << "\nPrecio del producto: ";
        cin >> precioPIn;
        cout << "\nCantidad a comprar: ";
        cin >> cantidadPIn;
        productosT[i].setProducto(claveTIn, nombrePIn, categoriaPIn, precioPIn, cantidadPIn);
    }
}

void Tienda::agregarCliente(){
    string identificador = to_string(cantidadClientesT);
    string nombre, correoElectronico, telefono;
    cout << "\nIngrese el nombre del cliente: " << endl;
    cin >> nombre;
    cout << "\nIngrese el correo electronico del cliente: " << endl;
    cin >> correoElectronico;
    cout << "\nIngrese el telefono del cliente: " << endl;
    cin >> telefono;
    clientesT[cantidadClientesT].setCliente(identificador, nombre, correoElectronico, telefono);
    cout << "\nCliente agregado con exito!" << endl;
    clientesT[cantidadClientesT].imprimirCliente();

    cantidadClientesT += 1;
}

void Tienda::llenarCarrito(){
    string identificadorC, nombreP;
    char respuestaP;
    int categoriaP, cantidadCompra;
    bool opcionP = true, registroCliente = true;
    int indiceCliente;
    do{
        bool hayCliente = false;
        cout << "\nPor favor, dame un identificador de cliente: ";
        cin >> identificadorC;
        int i = 0;
        do {
            if (identificadorC == clientesT[i].getIdentificadorC()) { // Cuando el cliente no este en la lista le pido que se registre
                hayCliente = true;
                indiceCliente = i;
            }
            i++;
        } while (hayCliente == false && i < cantidadClientesT);
        
        if (!hayCliente) { // Cuando el cliente no este en la lista le pido que se registre
            cout << "\nLa venta esta solo disponible para clientes registrados, lo invitamos a registrarse para disfrutar de nuestros maravillosos productos." << endl;
            registroCliente = false;
        }else{
            do{
                cout << "\nPor favor, indiqueme cual es el departamento en el que desea buscar su producto \n1) Frutas y verduras, 2) Electrodomesticos, 3) Abarrotes, 4) Higiene personal y 5) Jardineria: " << endl;
                cin >> categoriaP;
            }while (categoriaP>5 || categoriaP<1); // Me aseguro que escoja categoria valida
            for (int c = 0; c<cantidadProductosT; c++){
                if (categoriaP == productosT[c].getCategoriaP()){ // Cuando coincide con la categoria, lo imprimo
                    productosT[c].imprimirProducto();
                }
            }
            cout << "\nPor favor, indiqueme el nombre del producto que desea comprar: ";
            cin >> nombreP;
            cout << "\nTambien indiqueme la cantidad que quiere comprar: ";
            cin >> cantidadCompra;
            bool productoEncontrado = false;
            for (int n = 0; n<cantidadProductosT; n++){ // Me aseguro que el nombre introducido este en la lista
                if (nombreP == productosT[n].getNombreP()){ // Cuando coincide le añado a su carrito ese producto
                    clientesT[indiceCliente].setCarritoC(productosT[n],clientesT[indiceCliente].getCantidadProductosC(), cantidadCompra); // Se lo añado en el indice que sea igual a la cantidad de productos
                    clientesT[indiceCliente].setTotalC(clientesT[indiceCliente].getTotalC()+productosT[n].getPrecioP()*cantidadCompra);
                    ingresoDiarioT += clientesT[indiceCliente].getTotalC()+productosT[n].getPrecioP()*cantidadCompra;
                    cout << "\nCliente con identificador: " << indiceCliente << endl;
                    clientesT[indiceCliente].imprimirCarrito();
                    cout << "Su total hasta ahora es: $" << clientesT[indiceCliente].getTotalC() << endl;   
                    productoEncontrado = true;
                    break;
                }
            }
        }
        if (registroCliente){
        do{
            cout << "\nQuieres agregar otro producto? [S] [N]: ";
            cin >> respuestaP;
        }while(respuestaP != 'S' && respuestaP != 'N'); // Para que solo pueda elegir entre "S" o "N"
        }
        else{
            cout << "\nNo hay cliente registrado con ese identificador" << endl;
        }
        if (respuestaP == 'S'){
            opcionP = true;
        }
        else{
            opcionP = false;
        }
    }while(opcionP == true); // Para que el usuario continue comprando o pare
    if (registroCliente){
    imprimirTicketCompra(indiceCliente); // Finalmente imprimo con el metodo de impresion de ticket
    clientesT[indiceCliente].imprimirCarrito();
    clientesT[indiceCliente].limpiarCarrito(); // Limpio su carrito para que después haga más compras
    }
}

void Tienda::imprimirTicketCompra(int indice){
    cout << "\nTu ticket es: " << endl;
    clientesT[indice].imprimirCliente(); // Imprimo el cliente en el indice que me sea indicado por llenarCarrito
}

void Tienda::cerrarOperaciones(){
    cout << "\nEl ingreso total de la tienda el dia de hoy son: " << ingresoDiarioT << " pesos" << endl;
}

void Tienda::imprimirProductos(){
    for (int i = 0; i<cantidadProductosT; i++){
        productosT[i].imprimirProducto();
    }
}
