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

using namespace std;
using namespace listaenlazada;

void menu()
{
    cout << "\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout << "1: INSERTAS POSICION" << endl;
    cout << "2: ALQUILAR PELICULA" << endl;
    cout << "3: ESCRIBIR CANTIDAD DE PELICULA" << endl;
    cout << "4: ESCRIBIR LISTA" << endl;
    cout << "5: ELIMINAR PELICULA" << endl;
    cout << "6: CANTIDAD DE PELICULA POR PAIS" << endl;
    cout << "0: SALIR" << endl;
    
    cout << "\n INGRESE OPCION: ";
}

int main()
{
    ListaEnlazadaSimple EMP;
    
    EMP.Entrada();
    
    int choice;
    
    do
    {
        menu();
        cin >> choice;
        
        if (choice < 0 || choice > 6)
        {
            cout << "\nPORFAVOR SOMETER UNA ENTRADA VALIDA\n"<< endl;
        }
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            choice = 10;
            
            cout << "\nPORFAVOR SOMETER UNA ENTRADA VALIDA\n"<< endl;
        }
        
        switch(choice)
        {
            case 1:
                EMP.Insertar_Posicion();
                break;
            case 2:
                EMP.Desea_Alquilar();
                break;
            case 3:
                EMP.Buscar_Cantidad();
                break;
            case 4:
                EMP.Escribir_Lista();
                break;
            case 5:
                EMP.Elimi_Pelicula();
                break;
            case 6:
                EMP.Buscar_Pais();
                break;
            case 0:
                cout << "FIN DEL PROGRAMA" << endl << endl;
                break;
        }
        cout << endl;
    }while(choice!=0);
    return 0;
}