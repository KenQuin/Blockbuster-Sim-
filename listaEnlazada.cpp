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
#include "listaEnlazada.h"

namespace listaenlazada
{
    string name, ubicacion, done;
    int categ, anio,cuantos;
    char forma;
    
    ListaEnlazadaSimple::ListaEnlazadaSimple()
    {
        cabeza = NULL;
    }
    
    ListaEnlazadaSimple::~ListaEnlazadaSimple()
    {
        NodoPtr nodoActual = cabeza, sig;
        
        while(nodoActual!=NULL)
        {
            sig = nodoActual->siguiente;
            delete nodoActual;
            nodoActual = sig;
        }
    }
    
    bool ListaEnlazadaSimple::listaVacia()
    {
        if(cabeza==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void ListaEnlazadaSimple::Entrada()
    {
        ifstream entrada;
        NodoPtr aqui = NULL;
        string el;
        entrada.open("peliculas.txt");
        
        cout << "Peliculas Invalidas: " << endl;
        
        while(!entrada.eof())
        {
            getline(entrada, name, '*');
            getline(entrada, ubicacion, '*');
            entrada >> forma >> categ >> anio >> cuantos;
            getline(entrada, el, '\n');
            
            if((forma == 'B' || forma == 'D') && (categ >= 7 && categ <= 11) && (anio > 0) && (cuantos >= 0))
            {
                if(cabeza == NULL)
                {
                    NodoPtr temp_Ptr;
                    temp_Ptr = new Nodo;
                    
                    temp_Ptr->Nombre = name;
                    temp_Ptr->Pais = ubicacion;
                    temp_Ptr->Formato = forma;
                    temp_Ptr->Categoria = categ;
                    temp_Ptr->Year = anio;
                    temp_Ptr->Cantidad = cuantos;
                    
                    temp_Ptr->siguiente = cabeza;
                    
                    cabeza = temp_Ptr;
                }
                else
                {
                    aqui = cabeza;
                    while((aqui->Nombre != name) && (aqui->siguiente != NULL))
                    {
                        aqui = aqui->siguiente;
                    }
                    
                    if((aqui->Nombre == name) && (aqui->Formato == forma))
                    {
                        cout << "Valor incorrecto de la pelicula: " << name << endl;
                    }
                    else
                    {
                        
                        NodoPtr temp_Ptr;
                        temp_Ptr = cabeza;
                        
                        while(temp_Ptr->siguiente != NULL)
                        {
                            temp_Ptr = temp_Ptr->siguiente;
                        }
                        
                        temp_Ptr->siguiente = new Nodo;
                        temp_Ptr->siguiente->Nombre = name;
                        temp_Ptr->siguiente->Pais = ubicacion;
                        temp_Ptr->siguiente->Formato = forma;
                        temp_Ptr->siguiente->Categoria = categ;
                        temp_Ptr->siguiente->Year = anio;
                        temp_Ptr->siguiente->Cantidad = cuantos;
                        temp_Ptr->siguiente->siguiente = NULL;
                    }
                }
            }
            else
            {
                cout << "Valor incorrecto de la pelicula: " << name << endl;
            }
        }
        
        cout << endl;
    }
    
    
    void ListaEnlazadaSimple::Escribir_Lista()
    {
        NodoPtr temp_ptr;
        int i = 0;
        
        if(listaVacia() == true)
        {
            cout << "Lista Vacia" << endl;
        }
        else
        {
            cout << "Lista de peliculas: " << endl;
            
            for(temp_ptr = cabeza; temp_ptr != NULL; temp_ptr = temp_ptr->siguiente)
            {
                i++;
                cout << "Pelicula:" << i << endl;
                cout << "Nombre:" << temp_ptr->Nombre << endl;
                cout << "Formato:" << temp_ptr->Formato << endl;
                cout << "Categoria:" << temp_ptr->Categoria << endl;
                cout << "Pais:" << temp_ptr->Pais << endl;
                cout << "Anio de Produccion:" << temp_ptr->Year << endl;
                cout << "Cantidad de Peliculas:" << temp_ptr->Cantidad << endl;
                cout << endl;
                
            }

        }
    
    }
    
    void ListaEnlazadaSimple::Insertar_Posicion()
    {
        NodoPtr Position;
        NodoPtr aqui = cabeza;
        int pos;
        
        cout << "Favor escribir el Nombre la Pelicula: " << endl;
        cin.ignore();
        getline(cin, name, '\n');
    
        cout << "Favor escribir el Formato de la Pelicula: " << endl;
        cin >> forma;

        
        while(forma != 'B' && forma != 'D')
        {
            cout << "Formato invalido. Favor escribir el Formato de la Pelicula B o D:" << endl;
            cin >> forma;
        }
    
        while((aqui->Nombre != name || aqui->Formato != forma) && aqui->siguiente !=NULL)
        {
            aqui = aqui->siguiente;
        }
        
        if((aqui->Nombre == name) && (aqui->Formato == forma))
        {
            cout << endl;
            cout << "Error. Pelicula duplicada." << endl;
        }
        else
        {
            cout << "Favor escribir la Categoria de la Pelicula: " << endl;
            cin >> categ;
            
            while((categ < 7 || categ > 11))
            {
                cout << "Categoria invalida. Favor escribir una Categoria valida del 7 al 11:" << endl;
                cin.clear();
                cin.ignore();
                cin >> categ;
            }
            
            cout << "Favor escribir el Pais donde fue realizada la Pelicula: " << endl;
            cin.ignore();
            getline(cin, ubicacion);
            
            cout << "Favor escribir el Year que fue realizada la Pelicula: " << endl;
            cin >> anio;
            
            while(anio <= 0)
            {
                cout << "Error. Year no puede ser menor o igual a cero. Intente de nuevo: " << endl;
                cin >> anio;
            }
            
            cout << "Favor escribir la Cantidad de Peliculas: " << endl;
            cin >> cuantos;
            
            while(cuantos < 0)
            {
                cout << "Cantidad invalida. Favor introducir una o mas Peliculas: " << endl;
                cin >> cuantos;
            }
            
            cout << "Escriba la posicion en la lista que quiere tener la Pelicula: " << endl;
            cin >> pos;
            
            if(pos==1)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo;
                
                temp_Ptr->Nombre = name;
                temp_Ptr->Pais = ubicacion;
                temp_Ptr->Formato = forma;
                temp_Ptr->Categoria = categ;
                temp_Ptr->Year = anio;
                temp_Ptr->Cantidad = cuantos;
                
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                Position = Buscar_Posicion(cabeza, pos - 1);
                if(Position != NULL)
                Agregar_aLista(Position, cuantos);
            }
        }
    }
    
    NodoPtr ListaEnlazadaSimple::Buscar_Posicion(NodoPtr desps_demi, int Posicion)
    {
        NodoPtr Aqui = desps_demi;
        int i = 1;
        
        while(i < Posicion && Aqui->siguiente != NULL)
        {
            Aqui = Aqui->siguiente;
            i++;
        }
        
        if(i == Posicion && Aqui->siguiente != NULL)
        {
            return Aqui;
        }
        else
        {
            cout << endl;
            cout << "Posicion invalida" << endl;
            return NULL;
        }

    }
    
    
    
    void ListaEnlazadaSimple::Agregar_aLista(NodoPtr Despues, int cuantos)
    {
        NodoPtr temp_Ptr;
        
        temp_Ptr = new Nodo;
        temp_Ptr->Nombre = name;
        temp_Ptr->Pais = ubicacion;
        temp_Ptr->Formato = forma;
        temp_Ptr->Categoria = categ;
        temp_Ptr->Year = anio;
        temp_Ptr->Cantidad = cuantos;
        
        temp_Ptr->siguiente = Despues->siguiente;
        Despues->siguiente = temp_Ptr;

    }
    
    void ListaEnlazadaSimple::Buscar_Cantidad()
    {
        NodoPtr aqui = cabeza;
        
        if(listaVacia()==true)
        {
            cout << "Lista Vacia" << endl;
        }
        else
        {
            cout << "Favor escribir el Nombre la Pelicula: " << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Favor escribir el formato de la pelicula: " << endl;
            cin >> forma;
            
            while(forma != 'B' && forma != 'D')
            {
                cout << "Formato invalido. Favor escribir el Formato de la Pelicula B o D:" << endl;
                cin >> forma;
            }
            
            while((aqui->Nombre != name || aqui->Formato != forma) && aqui->siguiente !=NULL)
            {
                aqui = aqui->siguiente;
            }
            
            if(aqui->Nombre == name && aqui->Formato== forma)
            {
                cout << "La cantidad disponible de la pelicula " << name << " es: " << aqui->Cantidad << endl;
            }
            else
            {
                cout << "La Pelicula " << name << " no existe" << endl;
            }
        }
    }
    
    void ListaEnlazadaSimple::Desea_Alquilar()
    {
        NodoPtr aqui = cabeza;
        
        if(listaVacia()==true)
        {
            cout << "Lista Vacia" << endl;
        }
        else
        {
            cout << "Favor escribir el nombre la pelicula: " << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Favor escribir el formato de la pelicula: " << endl;
            cin >> forma;
            
            while(forma != 'B' && forma != 'D')
            {
                cout << "Formato invalido. Formatos: B = Blu-ray o D = DVD  Intente de nuevo:" << endl;
                cin >> forma;
            }
            
            cout << "Favor escribir la cantidad de peliculas que desea alquilar: " << endl;
            cin >> cuantos;
            
            while(cuantos <= 0)
            {
                cout << "Cantidad invalida. Favor introducir una o mas peliculas: " << endl;
                cin >> cuantos;
            }
            
            while((aqui->Nombre != name || aqui->Formato != forma) && aqui->siguiente !=NULL)
            {
                aqui = aqui->siguiente;
            }
            
            if(aqui->Nombre == name && aqui->Formato== forma)
            {
                if(cuantos > aqui->Cantidad)
                {
                    cout << endl;
                    cout << "Lo siento, no hay disponible esa cantidad de peliculas disponibles." << endl;
                }
                else
                {
                    aqui->Cantidad = aqui->Cantidad - cuantos;
                }
            }
            else
            {
                cout << "La Pelicula " << name << " no existe" << endl;
            }
        }
        
    }
    
    void ListaEnlazadaSimple::Elimi_Pelicula()
    {
        NodoPtr anterior, nodo;
        if(listaVacia()==true)
        {
            cout << "Lista Vacia" << endl;
        }
        else
        {
            cout << "Favor escribir el nombre la pelicula que desee eliminar: " << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Favor escribir el formato de la pelicula: " << endl;
            cin >> forma;
            
            while(forma != 'B' && forma != 'D')
            {
                cout << "Formato invalido. Formatos: B = Blu-ray o D = DVD  Intente de nuevo:" << endl;
                cin >> forma;
            }
            
            nodo = cabeza;
            anterior = NULL;
            
            while((nodo->Nombre != name || nodo->Formato != forma) && nodo->siguiente !=NULL)
            {
                anterior = nodo;
                nodo = nodo->siguiente;
            }
            if(nodo->Nombre == name && nodo->Formato== forma)
            {
                if(!anterior)
                {
                    cabeza = nodo->siguiente;
                }
                else
                {
                    anterior->siguiente = nodo->siguiente;
                }
                delete(nodo);
            }
            else
            {
                cout << "La Pelicula " << name << " no existe" << endl;
            }
        }
    }
    
    void ListaEnlazadaSimple::Buscar_Pais()
    {
        NodoPtr aqui = cabeza;
        NodoPtr find = cabeza;
        int formatoB = 0;
        int formatoD = 0;
        int done = 0;
        
        if(listaVacia()==true)
        {
            cout << "Lista Vacia" << endl;
        }
        else
        {
            cout << "Favor escribir el pais: " << endl;
            cin.ignore();
            getline(cin, ubicacion);
            
            while((find->Pais != ubicacion) && find->siguiente !=NULL)
            {
                find = find->siguiente;
            }
            
            if(find->Pais == ubicacion)
            {
                for(aqui = cabeza; aqui != NULL; aqui = aqui->siguiente)
                {
                    if(aqui->Pais == ubicacion && aqui->Formato == 'B')
                    {
                        formatoB = aqui->Cantidad + formatoB;
                    }
                    else if(aqui->Pais == ubicacion && aqui->Formato == 'D')
                    {
                        formatoD = aqui->Cantidad + formatoD;
                    }
                    else
                    {
                        done = done + aqui->Cantidad;
                    }
                }
                cout << "La cantidad de peliculas por pais es:" << endl;
                cout << "Peliculas en DVD: " << formatoD << endl;
                cout << "Peliculas en Blue Ray: " << formatoB << endl;

            }
            else
            {
                cout << "El Pais " << ubicacion << " no existe" << endl;
            }
        }

    }
}
