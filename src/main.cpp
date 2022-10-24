#include "generador.h"
#include "vectores.h"
#include <string>
#include <vector>

using namespace std;


int main() {
    // Prueba de la función divide()
    bool salida = 0;
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
    v.push_back(16);
    v.push_back(32);
    salida = divide(v,2);
    std :: cout << " El resultado es : " << salida << std :: endl;

    // Prueba de la función mayor()
    int salida2 = mayor(v);
    std :: cout << " El máximo del vector es : " << salida2 << std :: endl;

    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp
    return 0;
}
