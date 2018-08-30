#ifndef listaEnlazada_h
#define listaEnlazada_h
#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstddef>

using namespace std;

namespace listaenlazada
{
    struct Nodo
    {
        string Nombre;
        string Pais;
        char Formato;
        int Categoria;
        int Year;
        int Cantidad;
        Nodo *siguiente;
    };
    
    typedef Nodo* NodoPtr;
    
    class ListaEnlazadaSimple
    {
        public:
        ListaEnlazadaSimple();
        ~ListaEnlazadaSimple();
        
        bool listaVacia();
        
        void Entrada();
        
        void Insertar_Posicion();//PorPosicion
        
        NodoPtr Buscar_Posicion(NodoPtr desps_demi, int Posicion);//buscarPosicion
        
        void Agregar_aLista(NodoPtr Despues, int cuantos);
        
        void Buscar_Cantidad();//buscarCantidad
        
        void Desea_Alquilar();//alquilar
        
        void Escribir_Lista();// escribir
        
        void Elimi_Pelicula();//eliminar
        
        void Buscar_Pais();
        
        NodoPtr cabeza;
        
    };
    
}
#endif