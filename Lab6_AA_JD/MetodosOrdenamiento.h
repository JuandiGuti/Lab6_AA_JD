#pragma once
#include "MetodosOrdenamiento.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class MetodosOrdenamiento{
public:
    int Selection_sort(string arreglo[][3], int QueOrdenar, int Pokenum) {
        int contador = 0;
        for (int i = 0; i < Pokenum;i++) {
            contador++;
            int min = i;
            for (int j = i + 1;j < Pokenum;j++) {
                if (arreglo[j][QueOrdenar] < arreglo[min][QueOrdenar]) {
                    min = j;
                }
                contador++;
            }
            if (min != i) {
                string temp = arreglo[i][QueOrdenar];
                arreglo[i][QueOrdenar] = arreglo[min][QueOrdenar];
                arreglo[min][QueOrdenar] = temp;

                if (QueOrdenar == 0) {
                    string tem_nombre = arreglo[i][1];
                    arreglo[i][1] = arreglo[min][1];
                    arreglo[min][1] = tem_nombre;

                    string tem_gen = arreglo[i][2];
                    arreglo[i][2] = arreglo[min][2];
                    arreglo[min][2] = tem_gen;
                }
                else if (QueOrdenar == 1) {
                    string tem_codigo = arreglo[i][0];
                    arreglo[i][0] = arreglo[min][0];
                    arreglo[min][0] = tem_codigo;

                    string tem_gen = arreglo[i][2];
                    arreglo[i][2] = arreglo[min][2];
                    arreglo[min][2] = tem_gen;
                }
                else if (QueOrdenar == 2) {
                    string tem_codigo = arreglo[i][0];
                    arreglo[i][0] = arreglo[min][0];
                    arreglo[min][0] = tem_codigo;

                    string tem_nombre = arreglo[i][1];
                    arreglo[i][1] = arreglo[min][1];
                    arreglo[min][1] = tem_nombre;
                }
                else {
                    cout << "error 4, el programa no sabe que ordenar" << endl;
                }
            }
        }
        return contador;
    }
    int Shell_sort(string arreglo[][3], int QueOrdenar, int Pokenum) {
        int contador = 0;
        string tem_nombre, tem_gen, tem_codigo;
        for (int split = Pokenum / 2;split > 0;split /= 2) {
            contador++;
            for (int j = split; j < Pokenum;j++) {
                contador++;
                string temp = arreglo[j][QueOrdenar];
                int i;
                if (QueOrdenar == 0) {
                    tem_nombre = arreglo[j][1];
                    tem_gen = arreglo[j][2];
                }
                if (QueOrdenar == 1) {
                    tem_codigo = arreglo[j][0];
                    tem_gen = arreglo[j][2];
                }
                if (QueOrdenar == 2) {
                    tem_codigo = arreglo[j][0];
                    tem_nombre = arreglo[j][1];
                }
                for (i = j;i >= split && arreglo[i - split][QueOrdenar] > temp;i -= split) {
                    contador++;
                    arreglo[i][QueOrdenar] = arreglo[i - split][QueOrdenar];
                    if (QueOrdenar == 0) {
                        arreglo[i][1] = arreglo[i - split][1];
                        arreglo[i][2] = arreglo[i - split][2];
                    }
                    if (QueOrdenar == 1) {
                        arreglo[i][0] = arreglo[i - split][0];
                        arreglo[i][2] = arreglo[i - split][2];
                    }
                    if (QueOrdenar == 2) {
                        arreglo[i][1] = arreglo[i - split][1];
                        arreglo[i][0] = arreglo[i - split][0];
                    }
                }
                arreglo[i][QueOrdenar] = temp;
                if (QueOrdenar == 0) {
                    arreglo[i][1] = tem_nombre;
                    arreglo[i][2] = tem_gen;
                }
                if (QueOrdenar == 1) {
                    arreglo[i][0] = tem_codigo;
                    arreglo[i][2] = tem_gen;
                }
                if (QueOrdenar == 2) {
                    arreglo[i][1] = tem_nombre;
                    arreglo[i][0] = tem_codigo;
                }
            }
        }
        return contador;
    }
    int divide(string arreglo[][3], int start, int end, int QueOrdenar, int & contador) {
        int left;
        int right;
        string pivot;
        string tem;

        pivot = arreglo[start][QueOrdenar];
        left = start;
        right = end;

        while (left < right) {
            contador++;
            while (arreglo[right][QueOrdenar] > pivot) {
                right--;
                contador++;
            }
            while ((left < right) && (arreglo[left][QueOrdenar] <= pivot)) {
                left++;
                contador++;
            }
            if (left < right) {
                tem = arreglo[left][QueOrdenar];
                arreglo[left][QueOrdenar] = arreglo[right][QueOrdenar];
                arreglo[right][QueOrdenar] = tem;
                if (QueOrdenar == 0) {
                    tem = arreglo[left][1];
                    arreglo[left][1] = arreglo[right][1];
                    arreglo[right][1] = tem;

                    tem = arreglo[left][2];
                    arreglo[left][2] = arreglo[right][2];
                    arreglo[right][2] = tem;
                }
                if (QueOrdenar == 1) {
                    tem = arreglo[left][0];
                    arreglo[left][0] = arreglo[right][0];
                    arreglo[right][0] = tem;

                    tem = arreglo[left][2];
                    arreglo[left][2] = arreglo[right][2];
                    arreglo[right][2] = tem;
                }
                if (QueOrdenar == 2) {
                    tem = arreglo[left][1];
                    arreglo[left][1] = arreglo[right][1];
                    arreglo[right][1] = tem;
                    
                    tem = arreglo[left][0];
                    arreglo[left][0] = arreglo[right][0];
                    arreglo[right][0] = tem;
                }
            }
        }
        tem = arreglo[right][QueOrdenar];
        arreglo[right][QueOrdenar] = arreglo[start][QueOrdenar];
        arreglo[start][QueOrdenar] = tem;
        if (QueOrdenar == 0) {
            tem = arreglo[right][1];
            arreglo[right][1] = arreglo[start][1];
            arreglo[start][1] = tem;

            tem = arreglo[right][2];
            arreglo[right][2] = arreglo[start][2];
            arreglo[start][2] = tem;
        }
        if (QueOrdenar == 1) {
            tem = arreglo[right][0];
            arreglo[right][0] = arreglo[start][0];
            arreglo[start][0] = tem;

            tem = arreglo[right][2];
            arreglo[right][2] = arreglo[start][2];
            arreglo[start][2] = tem;
        }
        if (QueOrdenar == 2) {
            tem = arreglo[right][1];
            arreglo[right][1] = arreglo[start][1];
            arreglo[start][1] = tem;

            tem = arreglo[right][0];
            arreglo[right][0] = arreglo[start][0];
            arreglo[start][0] = tem;
        }
        return right;
    }
    int Quicksort(string arreglo[][3], int start, int end, int QueOrdenar) {
        int pivot, contador = 0;
        if (start < end) {
            pivot = divide(arreglo, start, end, QueOrdenar, contador);
            Quicksort(arreglo, start, (pivot - 1), QueOrdenar);
            Quicksort(arreglo, (pivot + 1), end, QueOrdenar);
        }
        return contador;
    }
};


