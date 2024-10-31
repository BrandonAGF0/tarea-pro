#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_ESTUDIANTES = 3;

struct Estudiante {
    char nombre[50];
    float nota;
    char telefono[15];
    char direccion[100];
};

Estudiante estudiantes[MAX_ESTUDIANTES];
int indice = 0;

void consultar() {
    char nombre[50];
    cout << "Digite el nombre del estudiante: ";
    cin >> nombre;
    bool encontrado = false;
    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre, estudiantes[i].nombre) == 0) {
            cout << "La nota es de " << estudiantes[i].nota << endl;
            cout << "Telefono: " << estudiantes[i].telefono << endl;
            cout << "Direccion: " << estudiantes[i].direccion << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void ingresar() {
    char seguir;
    do {
        if (indice >= MAX_ESTUDIANTES) {
            cout << "Se ha alcanzado el numero maximo de estudiantes." << endl;
            break;
        }
        cout << "Digite el nombre: ";
        cin >> estudiantes[indice].nombre;
        cout << "Digite la nota: ";
        cin >> estudiantes[indice].nota;
        cout << "Digite el telefono: ";
        cin >> estudiantes[indice].telefono;
        cout << "Digite la direccion: ";
        cin >> estudiantes[indice].direccion;
        cout << "Desea continuar.....s/n: ";
        cin >> seguir;
        indice++;
    } while ((seguir == 's') || (seguir == 'S'));
}

void modificar() {
    char nombre[50];
    cout << "Digite el nombre del estudiante a modificar: ";
    cin >> nombre;
    bool encontrado = false;
    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre, estudiantes[i].nombre) == 0) {
            cout << "Digite la nueva nota: ";
            cin >> estudiantes[i].nota;
            cout << "Digite el nuevo telefono: ";
            cin >> estudiantes[i].telefono;
            cout << "Digite la nueva direccion: ";
            cin >> estudiantes[i].direccion;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void borrar() {
    char nombre[50];
    cout << "Digite el nombre del estudiante a borrar: ";
    cin >> nombre;
    bool encontrado = false;
    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre, estudiantes[i].nombre) == 0) {
            for (int j = i; j < indice - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            indice--;
            encontrado = true;
            cout << "Estudiante borrado." << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void reporte() {
    printf("\nNombre        Nota        Telefono        Direccion\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < indice; i++) {
        printf("%s        %f        %s        %s\n", estudiantes[i].nombre, estudiantes[i].nota, estudiantes[i].telefono, estudiantes[i].direccion);
    }
    printf("\n");
}

void menu() {
    char seguir = 's';
    int opcion = 0;
    do {
        cout << "\n";
        cout << "1- Ingresar Estudiantes\n";
        cout << "2- Consultar Estudiantes\n";
        cout << "3- Modificar Estudiantes\n";
        cout << "4- Borrar Estudiantes\n";
        cout << "5- Reporte Estudiantes\n";
        cout << "6- Salir\n";
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ingresar(); break;
            case 2: consultar(); break;
            case 3: modificar(); break;
            case 4: borrar(); break;
            case 5: reporte(); break;
            case 6: seguir = 'n'; break;
            default: cout << "Opcion no valida." << endl; break;
        }
    } while ((seguir == 's') || (seguir == 'S'));
}

int main() {
    menu();
    return 0;
}

