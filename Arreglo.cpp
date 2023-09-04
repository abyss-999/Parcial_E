#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int numeros[300], n;
    int i, j, aux;

    cout << "Digite la cantidad de datos del arreglo (en este caso 30) ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Digite un numero: ";
        cin >> numeros[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

    cout << "Orden ascendente: "<<endl;
    for (i = 0; i < n; i++) {
        cout <<"posicion: "<< i+1 << "->" << numeros[i] << endl;
    } 

    getch();
    return 0;
}


























