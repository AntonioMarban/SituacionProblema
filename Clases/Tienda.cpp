// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 28/11/2022

#include <iostream>
#include <string>
#include <fstream>
#include "Tienda.h"
#include "Cliente.cpp"
#include "Producto.cpp"
using namespace std;

Tienda::Tienda(){ // Constructor por omision de la clase Tienda
    identificadorT = "DF";
    nombreT = "DF";
    direccionT = "DF";
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    ingresoDiarioT = 0;
}

Tienda::Tienda(string idIn, string nomIn, string dirIn){ // Constructor con valores determinados por el usuario o aplicacion
    identificadorT = idIn;
    nombreT = nomIn;
    direccionT = dirIn;
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    ingresoDiarioT = 0;
}

Tienda::~Tienda(){} // Destructor de la clase

string Tienda::getIdentificadorT(){ // Este metodo obtiene el identificador de la tienda
    return identificadorT;
}

string Tienda::getNombreT(){ // Este metodo obtiene el nombre de la tienda
    return nombreT;
}

string Tienda::getDireccionT(){ // Este metodo obtiene la direccion de la tienda
    return direccionT;
}

int Tienda::getCantidadProductosT(){ // Este metodo obtiene la cantidad de la tienda
    return cantidadProductosT;
}

int Tienda::getCandidadClientesT(){ // Este metodo obtiene la cantidad de clientes de la tienda
    return cantidadClientesT;
}

Producto Tienda::getProductosT(){ // Este metodo obtiene la lista de los productos de la tienda
    return productosT[PT];
}

Cliente Tienda::getClientesT(){ // Este metodo obtiene la lista de los clientes de la tienda
    return clientesT[CT];
}

double Tienda::getIngresoDiarioT(){ // Este metodo obtiene el ingreso del día de la tienda
    return ingresoDiarioT;
}

void Tienda::setIdentificadorT(string idIn){ // Este metodo establece el identificador de la tienda en un valor que es introducido
    identificadorT = idIn;
}

void Tienda::setNombreT(string nomIn){ // Este metodo establece el nombre de la tienda en un valor que es introducido
    nombreT = nomIn;
}

void Tienda::setDireccionT(string dirIn){ // Este metodo establece la direccion de la tienda en un valor que es introducido
    direccionT = dirIn;
}

void Tienda::setCantidadProductosT(int cantProd){ // Este metodo establece la cantidad de productos de la tienda en un valor que es introducido
    cantidadClientesT = cantProd;
}

void Tienda::setCantidadClientesT(int cantCli){ // Este metodo establece la cantidad de clientes de la tienda en un valor que es introducido
    cantidadClientesT = cantCli;
}

void Tienda::setProductosT(Producto prod){ // Este metodo establece el arreglo de los productos de la tienda en un valor que es introducido
    productosT[cantidadProductosT] = prod;
}

void Tienda::setClientesT(Cliente cli, int indice){ // Este metodo establece el arreglo de clientes de la tienda en un valor que es introducido
    clientesT[indice] = cli;
}

void Tienda::setIngresoDiarioT(double ingIn){ // Este metodo establece el ingreso del dia de la tienda en un valor que es introducido
    ingresoDiarioT = ingIn;
}

void Tienda::imprimirTienda() { // Este metodo imprime todos los atributos de la clase tienda
    cout << "\nSu identificador es: " << identificadorT << endl;
    cout << "Su nombre es: " << nombreT << endl;
    cout << "Su direccion es: " << direccionT << endl;
    cout << "La tienda tiene " << cantidadProductosT << " productos" << endl;
    cout << "La tienda tiene " << cantidadClientesT << " clientes"<< endl;
}

void Tienda::imprimirClientes() { // Este metodo imprime todos los atributos de los clientes de la tienda
    for (int i = 0; i < cantidadClientesT; i++) {
        clientesT[i].imprimirCliente();
    }
}

void Tienda::agregarLosProductos(string nombreArchivo){ // Este metodo agrega los productos desde un archivo de texto a la clase tienda
    ifstream miArchivo; // objeto de tipo archivos de entrada
    miArchivo.open(nombreArchivo.c_str(), ios::out | ios::in);
    // el archivo cuyo nombre llega como parametro, se abre para lectura
    cout<<"\nLleno el arreglo con los datos del archivo de texto\n";
    string clave, nombre;   
    int categoria, i = 0;
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

void Tienda::agregarElProducto(){ // Este metodo hace que el usuario agregue los productos uno a uno
    int agregados = 0;
    cout << "Cuantos productos vas a agregar?" << endl;
    cin >> agregados;
    cantidadProductosT += agregados;
    for (int i = 0; i<agregados; i++){
        cout << "\n****** Producto " << i+1 << " ********" << endl;
        string claveTIn, nombrePIn;
        int categoriaPIn, cantidadPIn;
        float precioPIn;
        cout << "\nNombre del producto: ";
        cin >> nombrePIn;
        cout <<  "\nCategoria del producto: ";
        cin >> categoriaPIn;
        cout << "\nPrecio del producto: ";
        cin >> precioPIn;
        
        productosT[i].setProducto(identificadorT, nombrePIn, categoriaPIn, precioPIn, 0);
    }
}

void Tienda::agregarCliente(){ // Este metodo agrega clientes a la lista de clientes de la tienda
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

void Tienda::llenarCarrito(){ // Este metodo dependiendo del identificador de un cliente añade productos que quiera comprar a su carrito
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
            cout << "\nPor favor, indiqueme el nombre del producto que desea comprar: " << endl;
            cout << ">";
            cin >> nombreP;
            cout << "\nTambien indiqueme la cantidad que quiere comprar: " << endl;
            cout << ">";
            cin >> cantidadCompra;
            bool productoEncontrado = false;
            for (int n = 0; n<cantidadProductosT; n++){ // Me aseguro que el nombre introducido este en la lista
                if (nombreP == productosT[n].getNombreP()){ // Cuando coincide le añado a su carrito ese producto
                    clientesT[indiceCliente].setCarritoC(productosT[n],clientesT[indiceCliente].getCantidadProductosC(), cantidadCompra); // Se lo añado en el indice que sea igual a la cantidad de productos
                    clientesT[indiceCliente].setTotalC(clientesT[indiceCliente].getTotalC()+productosT[n].getPrecioP()*cantidadCompra); // Al total de su carrito le añado el total de lo que compre
                    ingresoDiarioT += productosT[n].getPrecioP()*cantidadCompra; // El total de su carrito se lo sumo al ingreso de la tienda
                    cout << "\nCliente con identificador: " << indiceCliente << endl;
                    clientesT[indiceCliente].imprimirCarrito(); // Imprimo su carrito para que verifique la compra
                    cout << "Su total hasta ahora es: $" << clientesT[indiceCliente].getTotalC() << endl; // Imprimo el total de su carrito
                    productoEncontrado = true;
                    break;
                }
            }
        }
        if (registroCliente){
        do{
            cout << "\nQuieres agregar otro producto? [S] [N]: " << endl;
            cout << ">";
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
    // clientesT[indiceCliente].imprimirCarrito();
    clientesT[indiceCliente].limpiarCarrito(); // Limpio su carrito para que después haga más compras
    }
}

void Tienda::imprimirTicketCompra(int indice){ // Este metodo imprime el ticket del cliente que hace la compra
    cout << "\n=============== Ticket =============== " << endl;
    clientesT[indice].imprimirCliente(); // Imprimo el cliente en el indice que me sea indicado por llenarCarrito
    cout << "\n====================================== " << endl;
}

void Tienda::cerrarOperaciones(){ // Este metodo imprime el ingreso del dia de la tienda
    cout << "\nEl ingreso total de la tienda el dia de hoy son: " << ingresoDiarioT << " pesos" << endl;
}

void Tienda::imprimirProductos(){ // Este metodo imprime todos los atributos de todos los productos de la tienda
    for (int i = 0; i<cantidadProductosT; i++){
        productosT[i].imprimirProducto();
    }
}
