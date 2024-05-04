#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

using namespace std;
void crearArchivos(int cantidad);
void agregarTexto();
int contar();
int contar2();
void Detalles();
void Detalles2();

int main() {
    int opc;
    cout << "Bienvenidos a PROGRAMACION, Cayetano" << endl;
    do {
        cout << "Elija una opcion a realizar" << endl;
        cout << "[1] Crear Archivos" << endl;
        cout << "[2] Si, Desea ver el peso del documento" << endl;
        cout << "[0] Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Opcion seleccionada -> Crear Archivos" << endl;
                int cantidad;
                cout << "Cuantos Archivos desea crear?" << endl;
                cin >> cantidad;
                crearArchivos(cantidad);
                break;
            case 2:
                cout << "Opcion seleccionada -> Mostrar el peso de los archivos" << endl;
                Detalles();
                Detalles2();
                break;
            case 0:
                cout << "Gracias por Utilizar el Programa" << endl;
                break;
            default:
                cout << "Opcion incorrecta, vuelva a intentarlo" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}

void crearArchivos(int cantidad){
    string nombreArchivo = "File";
    if (cantidad % 2 == 0){
        cout << "Cantidad de Archivos par" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/JrCay/OneDrive/Escritorio/Par/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "Buen dia" << endl;
            }
            file.close();
        }
        cout << cantidad << " Archivos creados con Exito" << endl;
        contar();
    }else{
        cout << "Cantidad de Archivos impar" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/JrCay/OneDriv/Escritorio/Impar/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "Feliz Dia" << endl;
            }
            file.close();
        }
        cout << cantidad << " Archivos creados con Exito" << endl;
        contar2();
    }
}

void agregarTexto(){
    cout << "Agregando texto..." << endl;
}

int contar(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/JrCay/OneDrive/Escritorio/Par/", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Directorio Incorrecto" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

int contar2(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/JrCay/OneDrive/Escritorio/Impar/", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Directorio Incorrecto" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

void Detalles(){
    filesystem::directory_iterator directoryIterator("C:/Users/JrCay/OneDrive/Escritorio/Par/");
    cout <<"======================DIRECTORIO========================="<< endl;
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout<< endl;
            cout << "Peso: " << file_size(entry.path()) << " bytes" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
        }
    }
}

void Detalles2(){
    filesystem::directory_iterator directoryIterator("C:/Users/JrCay/OneDrive/Escritorio/Impar/");
    cout<< endl <<"======================DIRECTORIO========================="<< endl;
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout<< endl;
            cout << "Peso: " << file_size(entry.path()) << " bytes" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
        }
    }
}
