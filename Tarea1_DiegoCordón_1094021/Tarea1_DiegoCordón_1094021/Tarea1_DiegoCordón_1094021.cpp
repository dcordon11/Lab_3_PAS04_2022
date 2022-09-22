// Tarea1_DiegoCordón_1094021.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace std;

int Ejercicio1(int multiplicador, int multiplicando)
{
    if (multiplicador == 0)
    {
        return (1);
    }
    else if (multiplicador == 1)
    {
        return multiplicando;
    }
    else
    {
        return  multiplicando + Ejercicio1(multiplicando, multiplicador - 1);
    }
    return (0);
}

vector<string> LeerPalabrasDelArchivo() {
    ifstream infile("archivoCSV.csv");

    string line = "";

    vector<string> dataFile;

    while (getline(infile, line)) {
        stringstream stringStream(line);
        string palabra = "";
        while (getline(stringStream, palabra, ',')) {
            dataFile.push_back(palabra);
        }
    }
    return dataFile;
}
//Referencia: https://www.youtube.com/watch?v=bal7cn-YvfU

void Ejercicio2CastearArreglo()
{
    int longitudArregloPalabras=LeerPalabrasDelArchivo().size();
    cout << longitudArregloPalabras << endl;
    //leer arreglo
    for (int i = 0; i < longitudArregloPalabras; i++)
    {
        cout << LeerPalabrasDelArchivo()[i] << endl;;
        
    }
    
}

void Ejercicio2Recursivo()
{
    string resultado;
    int contador = 0;

    if (contador >= 0)
    {
        resultado += LeerPalabrasDelArchivo()[contador];
    }
    if (LeerPalabrasDelArchivo()[contador] == resultado)
    {
        cout << "Las palabras no son todas palindromas";
    }
    else 
    {
        cout << "Las palabras no son todas palindromas";
    }
    
}

int Ejercicio3(int baseO, int numeroC, int baseD)
{
    int potencia = 1;
    int resultado = 0;
    int residuo, res;
    double decimal;
    int arreglo[10];
    double total;
    
    if (numeroC != 0)
    {


        residuo = numeroC % 10;
        numeroC = numeroC / 10;
        resultado = resultado + (residuo + potencia);

        res = resultado % baseD;

        total = Ejercicio3(baseO, numeroC / baseD, baseD);
        return (total);
    }
    else
    {
        return 0;
    }


}
//No estoy seguro de que funcione ):

int main()
{
    
    int opcionesMenu;
    cout << "Bienvenido";
    cout << "\n";
    cout << "Seleccione la opcion que desea usar segun su numero";
    cout << "\n";
    cout << "Ejercicio 1 = 1, Ejercicio 2 = 2, Ejercicio 3 = 3, Salir = 4";
    cout << "\n";
    cin >> opcionesMenu;

    switch (opcionesMenu)
    {
    case 1:
        int multiplicador, multiplicando;
        cout << "Ingrese el numero del multiplicador";
        cout << "\n";
        cin >> multiplicador;
        cout << "\n";
        cout << "Ingrese el valor del multiplicando";
        cout << "\n";
        cin >> multiplicando;
        cout << "\n";
        cout << "El resultado es: " << Ejercicio1(multiplicador, multiplicando) << endl;
        break;
    case 2:
        
        
        cout << "\n";
        Ejercicio2CastearArreglo();
        Ejercicio2Recursivo();
        cout << "\n";
        
        break;
    case 3:
        int baseOrigen, numeroConvertir, baseDestino;
        cout << "Ingrese la base de origen";
        cin >> baseOrigen;
        cout << "\n";
        cout << "Ingrese el número que desea convertir";
        cout << "\n";
        cout << "Ingrese la base de destino";
        cin >> baseDestino;
        cout << "\n";
        cout << "El resultado en la base " << baseDestino << "es " << Ejercicio3(baseOrigen, numeroConvertir, baseDestino) << endl;
        break;

    case 4:
        exit;
        break;
    default:
        cout << "La opcion seleccionada es incorrecta";
        break;
    }
    cout << "\n";
}



