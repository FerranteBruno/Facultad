#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "funcionesvarias.h"
#include "CategoriasGral.h"

using namespace std;

int main(){
    system("color 57");
    int cantidadJugadores, dJ1[5], categoriasJ1[10], categoriasJ2[10], turnos=1, turnos2=1, dG1[5], dG2[5], tirada=1, eleccionTirada, catGuardado=0;
    ///bandera de tirada alternativa
    int descarte=0, tiradaGuardada;
    string nJ1="",aJ1="",nJ2="",aJ2="";
///bandera while de carga
    int b=1;


///MANTENGO LA INTERFAZ QUEITA
    while(b!=0){
///INGRESO DE LOS JUGADORES
        cuadro(10,3,78,24);
        gotoxy(32,5);
        cout<<"Bienvenidos a la generala"<<endl;
        gotoxy(28,6);
        cout<<"---------------------------------"<<endl;
        gotoxy(28,7);
        cout<<"Ingresar la cantidad de jugadores"<<endl;
        gotoxy(28,8);
        cout<<"---------------------------------"<<endl;
        gotoxy(28,9);
        cin>>cantidadJugadores;

        gotoxy(28,10);
        system("pause");

        switch(cantidadJugadores){

        case 1:
            gotoxy(28,11);
        cout<<"Ingrese el nombre del jugador"<<endl;
        gotoxy(28,12);
        cin>>nJ1;
        gotoxy(28,13);
        cout<<"Ingrese el apellido del jugador"<<endl;
        gotoxy(28,14);
        cin>>aJ1;
        gotoxy(28,15);
        cout<<"Jugador 1:"<<endl;
        gotoxy(28,16);
        cout<<nJ1<<" "<<aJ1<<endl;
        b=0;

        ///comienza el juego:
        runJ1(dJ1, categoriasJ1, turnos, dG1, descarte, tirada, tiradaGuardada, eleccionTirada, nJ1, aJ1, catGuardado);
        return 0;
        break;

        case 2:

        //Jug 1
        cout<<"Ingrese el nombre del jugador 1:"<<endl;
        cin>>nJ1;
        cout<<"Ingrese el apellido del jugador 1:"<<endl;
        cin>>aJ1;
        cout<<"Jugador 1:"<<endl;
        cout<<nJ1<<" "<<aJ1<<endl;
        //Jug 2
        cout<<"Ingrese el nombre del jugador 2:"<<endl;
        cin>>nJ2;
        cout<<"Ingrese el apellido del jugador 2:"<<endl;
        cin>>aJ2;
        cout<<"Jugador 2:"<<endl;
        cout<<nJ2<<" "<<aJ2<<endl;
        b=0;
        runJ2(dJ1, categoriasJ1, categoriasJ2,turnos, turnos2, dG1, dG2, descarte, tirada, tiradaGuardada, eleccionTirada, nJ1, aJ1, nJ2, aJ2, catGuardado);
        break;

        default:
            cout<<"Numero invalido de jugadores"<<endl;
        break;
        }
    }
}
