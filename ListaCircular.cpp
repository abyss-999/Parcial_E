#include <iostream>
#include <conio.h>
using namespace std;

struct Elemento {
    int num;
    Elemento* siguiente;
};

Elemento* pi = nullptr;

void insertar_dato(int dato) {
    Elemento* nuevo = new Elemento;
    nuevo->num = dato;

    if (pi == nullptr) {
        pi = nuevo;
        nuevo->siguiente = pi;
    } else {
        Elemento* temp = pi;
        while (temp->siguiente != pi) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = pi;
    }
}
int Actualizar(int valor, int actualizar) {
    Elemento* temp = pi;
    int encontrado = 0;

    do {
        if (temp->num == valor) {
            temp->num = actualizar;
            encontrado = 1;
        }
        temp = temp->siguiente;
    } while (temp != pi);

    return encontrado;
}
void mostrarlista() {
    int i = 0, band = 0;
    Elemento* temp = pi;

    if (temp != nullptr) {
        do {
            cout << "nodo: " << i++ << "->" << temp->num << endl << endl;
            temp = temp->siguiente;
        } while (temp != pi);
    }
}

int main(){
    int dato, actualizar;
    char respuesta;

    do
    {
        cout<<"Ingresar nodos a la lista: "<<endl;cin>>dato;
        insertar_dato(dato);
        cout<<"Deseas seguir ingresando nodos a la lista? (s/n)"<<endl;
        respuesta = getch();
    } while(respuesta == 's');
    cout<<"\nElementos de la lista:"<<endl;
    mostrarlista();
    
    do {
        cout << endl << "Deseas actualizar un nodo? (s/n)";
        respuesta = getch();
        if (respuesta == 's') {
            cout <<endl<< "Pon el nodo que quieres cambiar: ";
            cin >> dato;
            cout << "Aca el numero por el que quieres actualizar el nodo: ";
            cin >> actualizar;
            if (Actualizar(dato, actualizar) == 1) {
                cout << "El nodo se ha actualizado" << endl;
                mostrarlista();
            } else {
                cout << "El nodo no se encontro" << endl;
            }
        }
    } while (respuesta == 's');
    return 0;
}