#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MetodosOrdenamiento.h"

using namespace std;

int leerarchivo(string direccion, string lista_codigos[], string lista_nombres[], string lista_generacion[]) {
    ifstream archivo(direccion);
    string linea;
    char delimitador = ',';
    int contador = 0;
    if (archivo.is_open()) {
        cout << "Se abrio el archivo correctamente..." << endl;
        getline(archivo, linea);
        while (getline(archivo, linea)) {
            stringstream stream(linea);
            string codigo, nombre, generacion;
            while (getline(stream, codigo, delimitador) && getline(stream, nombre, delimitador) && getline(stream, generacion, delimitador)) {
                //add
                lista_codigos[contador] = codigo;
                lista_nombres[contador] = nombre;
                lista_generacion[contador] = generacion;
            }
            contador++;
        }
        return contador;
    }
    else {
        cout << "Error 2, no se encontro el archivo" << endl;
        return 0;
    }
}

int main()
{
    string direccion;

    string lista_codigos[100];
    string lista_nombres[100];
    string lista_generacion[100];

    string lista_global[100][3];
    int Pokenum;
    cout << "Usar archivo base o ingresar uno propio" << endl;
    cout << "1. Base" << endl;
    cout << "2. Propio" << endl;
    cin >> direccion;
    if (direccion == "1") {
        Pokenum = leerarchivo("archivo.txt", lista_codigos, lista_nombres, lista_generacion);
    }
    else if (direccion == "2") {
        cout << "Ingrese la direccion donde se encuentra el archivo..." << endl;
        cout << "Ejemplo: C:\\Users\\juand\\OneDrive\\Documents\\Pokemon.txt" << endl;
        cin >> direccion;
        Pokenum = leerarchivo(direccion, lista_codigos, lista_nombres, lista_generacion);
    }
    else {
        cout << "Error 1, seleccion de opcion mala..." << endl;
        return 0;
    }
    if (Pokenum == 0) {
        cout << "Error 3, 0 elementos para utilizar" << endl;
        return 0;
    }
    for (int i = 0; i < Pokenum; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                lista_global[i][j] = lista_codigos[i];
            }
            else if (j == 2) {
                lista_global[i][j] = lista_generacion[i];
            }
            else {
                lista_global[i][j] = lista_nombres[i];
            }
        }
    }
    //ordenamiento

    int QueOrdenamos;
    MetodosOrdenamiento ordenar;

    cout << "Elige por que deseas ordenar" << endl;
    cout << "1. Numero Regional" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Generacion" << endl;
    cin >> direccion;
    if (direccion == "1") {
        QueOrdenamos = 0;
    }
    else if (direccion == "2") {
        QueOrdenamos = 1;
    }
    else if (direccion == "3") {
        QueOrdenamos = 2;
    }
    else {
        cout << "Error 1, seleccion de opcion mala..." << endl;
        return 0;
    }
    int comp_selection_sort, comp_shell_sort, comp_quick_sort;

    comp_selection_sort = ordenar.Selection_sort(lista_global, QueOrdenamos, Pokenum);
    comp_shell_sort = ordenar.Shell_sort(lista_global, QueOrdenamos, Pokenum);
    comp_quick_sort = ordenar.Quicksort(lista_global, 0, (Pokenum-1), QueOrdenamos);
    cout << endl;
    cout << "Iteraciones Selection Sort: " << comp_selection_sort << endl;
    cout << "Iteraciones Shell Sort: " << comp_shell_sort << endl;
    cout << "Iteraciones Quick Sort: " << comp_quick_sort << endl;
    cout << endl;
    cout << "Documento ordenado..." << endl;
    for (int i = 0; i < Pokenum; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                cout << lista_global[i][j] << " ";
            }
            else if (j == 1) {
                cout << lista_global[i][j] << " ";
            }
            else {
                cout << lista_global[i][j] << endl;
            }
        }
    }
}
