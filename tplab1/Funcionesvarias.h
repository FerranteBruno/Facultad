#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>
#include <windows.h>

using namespace std;

///Declaro las funciones:

void ordenarDados(int d[5]);

void TirarDados(int d[5], int dG1[5], int &tirada);

void dadosEnCero(int d[], int tam);

void mostrarDados(int d[5]);

void guardarDados(int dG1[5], int dJ1[5], int descarte, int &tirada);

void seleccionTirada(int dJ1[5], int dG1[5], int categoriasJ1[11], int descarte, int &tirada);

void categorias(int categoriasJ1[10], int dJ1[5], int dG1[5], int &tirada, int &catGuardado);

void gotoxy(int x,int y);

void cuadro(int x1, int y1, int x2, int y2);

///Aca termina
void ordenarDados(int d[5]){
    int i, j, aux;

    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            if(d[j] > d[j+1]){
                aux = d[j];
                d[j] = d[j+1];
                d[j+1] = aux;
            }
        }
    }
    return;
}
//void TirarDados(int dJ1[5], int dG1[5], int descarte)
void TirarDados(int dJ1[5], int dG1[5], int &tirada, int &tiradaGuardada, int &eleccionTirada){
    int i;
    const int tam=6;

    if(tirada==1){
        ///vector en 0
        dadosEnCero(dJ1, tam);

        ///randomizo
        srand(time(NULL));
        for(i=0;i<5;i++){
            dJ1[i]=(rand()%6)+1;
        }
        ///los ordeno
        ordenarDados(dJ1);
        cout<<endl;
    }
    else{
        if(tiradaGuardada==0){
        dadosEnCero(dG1, tam);
        }
        srand(time(NULL));
        for(i=0;i<5;i++){
                if(dG1[i]==0){
                    dG1[i]=(rand()%6)+1;
                    }
                }
        ordenarDados(dG1);
        cout<<endl;
    }
    ///significa que quiere volver a tirar todos los dados!!!
    if(eleccionTirada==1){
        dadosEnCero(dG1, tam);

        srand(time(NULL));
        for(i=0;i<5;i++){
                if(dG1[i]==0){
                    dG1[i]=(rand()%6)+1;
                    }
                }
        ordenarDados(dG1);
        cout<<endl;
        }

    return;
}
///Pone todos los valores del vector en 0
void dadosEnCero(int d[], int tam){
    int i;
    for(i=0;i<tam;i++){
        d[i]=0;
    }
}
///Muestra el vector dados en pantalla
void mostrarDados(int d[5]){
    int i;
    for(i=0;i<5;i++){
        cout<<d[i]<<"\t";
    }
    cout<<endl;
    return;
}
void guardarDados(int dG1[5], int dJ1[5], int descarte, int &tirada){
    int i;

    if(tirada==1){
        for(i=0;i<5;i++){
            dG1[i]=dJ1[i];
            }
        }
    cout<<"Numero de dado a descartar de 1 a 5 (Para finalizar presione 0)"<<endl;
    cin>>descarte;///ingreso el dado para descartar

        ///Compruebo que elija el dado correcto
        if(descarte>5 || descarte < 0){
            cout<<"Numero ingresado invalido"<<endl;
            cout<<"Por favor ingrese un numero válido"<<endl;
            cin>>descarte; ///ingreso el dado para descartar
        }

        while(descarte!=0){
            dG1[descarte-1]=0;
            ///Llamo a mostrar dados para que aparezcan en pantalla
            mostrarDados(dG1);
            cout<<"Descartaste el dado: "<<descarte<<endl;
            cout<<endl;
            cin>>descarte;///ingreso el dado para descartar
            cout<<endl;
        }
    return;
}
void seleccionTirada(int dJ1[5],int dG1[5],int categoriasJ1[10],int descarte,int &tirada, int &turnos, int &tiradaGuardada, int &eleccionTirada, int &catGuardado){
    eleccionTirada=0;

    cout<<"\n¿Desea volver a tirar dados? \nPresiona 1 = TODOS LOS DADOS | Presiona 2 = SELECCIONAR DADOS\n | 3 = GUARDAR TIRADA | 9 = Ver Categorias\n Si tiene Generala servida, guarde la tirada"<<endl;
    mostrarDados(dG1);
    cin>>eleccionTirada;

    switch(eleccionTirada){
        int i;
            case 1:
                tirada++;
                tiradaGuardada++;
                break;

            case 2:
            ///ACA DEBEMOS DE ELEGIR LA TIRADA PARA GUARDAR!!!
                    cout<<"\nElija los dados a descartar"<<endl;
                    tirada++;///Hago tirada=2
                    tiradaGuardada++;
                    guardarDados(dG1, dJ1, descarte, tirada);
                break;
            case 3:
                cout<<"¿En que categoria quiere guardar?\n Categoria 1-6, presione 1-6.\t Categoria Escalera presione. 7\t Categoria Full presione. 8\t Categoria Poker presione. 9\t Categoria Generala presione 10. "<<endl;
                cin>>catGuardado;
                categorias(categoriasJ1, dJ1, dG1, tirada, catGuardado);
                catGuardado=0;
                turnos++;
                tirada+=3;
                break;

                case 9:
                    system("cls");
                    for(i=0;i<10;i++){
                        cout<<"\nCategoría "<<i+1<<": \t"<<"["<<categoriasJ1[i]<<"]"<<endl;
                        cout<<"*--------------------------------------------------------*"<<endl;
                }
                seleccionTirada(dJ1, dG1, categoriasJ1, descarte, tirada, turnos, tiradaGuardada, eleccionTirada, catGuardado);
                break;

            default:
                cout<<"Seleccione una opción válida!"<<endl;
                system("pause");
                break;

        }
    return;
    }

void seleccionTirada2(int dJ1[5],int dG1[5],int categoriasJ1[10],int descarte,int &tirada, int &turnos2, int &tiradaGuardada, int &eleccionTirada, int &catGuardado){
    eleccionTirada=0;

    cout<<"\n¿Desea volver a tirar dados? \nPresiona 1 = TODOS LOS DADOS | Presiona 2 = SELECCIONAR DADOS | 3 = GUARDAR TIRADA | 9 = Ver Categorias\n Si tiene Generala servida, guarde la tirada"<<endl;
    mostrarDados(dG1);
    cin>>eleccionTirada;


    switch(eleccionTirada){
        int i;
            case 1:
                tirada++;
                tiradaGuardada++;
                break;

            case 2:
            ///ACA DEBEMOS DE ELEGIR LA TIRADA PARA GUARDAR!!!
                    cout<<"\nElija los dados a descartar"<<endl;
                    guardarDados(dG1, dJ1, descarte, tirada);
                    tirada++;///Hago tirada=2
                    tiradaGuardada++;
                break;
            case 3:
                cout<<"¿En que categoria quiere guardar?\n Categoria 1-6, presione 1-6.\t Categoria Escalera presione. 7\t Categoria Full presione. 8\t Categoria Poker presione. 9\t Categoria Generala presione 10. "<<endl;
                cin>>catGuardado;
                categorias(categoriasJ1, dJ1, dG1, tirada, catGuardado);
                catGuardado=0;
                turnos2++;
                tirada+=3;
                break;

            case 9:
                system("cls");
                for(i=0;i<10;i++){
                    cout<<"\nCategoría "<<i+1<<": \t"<<"["<<categoriasJ1[i]<<"]"<<endl;
                    cout<<"*--------------------------------------------------------*"<<endl;
                }
                seleccionTirada2(dJ1, dG1, categoriasJ1, descarte, tirada, turnos2, tiradaGuardada, eleccionTirada, catGuardado);
                break;
            default:
                cout<<"Seleccione una opción válida!"<<endl;
                system("pause");
                break;

        }
    return;
    }

void categorias(int categoriasJ1[10], int dJ1[5], int dG1[5], int &tirada, int &catGuardado){
    int i, j;
    int escalera=0;
    int bandera=0;


    while(bandera==0){

        switch(catGuardado){
        ///Generali
        case 10:
        if(categoriasJ1[9]==0){
            for(i=1;i<7;i++){
                if(dG1[0]==i && dG1[1]==i && dG1[2]==i && dG1[3]==i && dG1[4]==i){
                    if(tirada==1){
                        cout<<"Felicidades! \nGenerala Servida!!"<<endl;
                        categoriasJ1[9]+=999;
                        system("pause");
                    }
                    else{
                        categoriasJ1[9]+=50;
                        cout<<"Obtuviste en esta ronda: "<<categoriasJ1[9]<<" puntos de GENERALA!!"<<endl;
                        system("pause");
                        }
                        bandera=1;
                    return;
                    }
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 8:
        ///full
        ///compruebo que este llena la categoría
            if(categoriasJ1[7]==0){
        ///busco los valores de los dados
                for(i=1;i<7;i++){
                    if((dG1[0]==i && dG1[1]==i && dG1[2]==i && dG1[3]==dG1[4]) || (dG1[0]==dG1[1] && dG1[2]==i && dG1[3]==i && dG1[4]==i)){
                        categoriasJ1[7]+=30;
                        cout<<"Obtuviste en esta ronda: "<<categoriasJ1[7]<<" en Categoría Full!!"<<endl;
                        system("pause");
                        bandera=1;
                    return;
                    }
            }
            }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 9:
        ///poker
        ///compruebo que este llena la categoría
            if(categoriasJ1[8]==0){
                for(i=1;i<7;i++){
                    if((dG1[0]==i && dG1[1]==i && dG1[2]==i && dG1[3]==i) || (dG1[1]==i && dG1[2]==i && dG1[3]==i && dG1[4]==i)){
                        categoriasJ1[8]+=40;
                        cout<<"Obtuviste en esta ronda: "<<categoriasJ1[8]<<" en Categoría Poker!!"<<endl;
                        system("pause");
                        bandera=1;
                    return;
                    }
                }
            }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 1:
        ///categoría 1}
        if(categoriasJ1[0]==0){
            for(i=0;i<5;i++){
                if(dG1[i]==1){
                    categoriasJ1[0]++;
                }
            }
            if(categoriasJ1[0]!=0){
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[0]<<" en Categoría 1!!"<<endl;
                system("pause");
                bandera=1;
            return;
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 2:
        ///categoría 2
        if(categoriasJ1[1]==0){
            for(i=0;i<5;i++){
                if(dG1[i]==2){
                    categoriasJ1[1]+=2;
                    }
            }
            if(categoriasJ1[1]!=0){
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[1]<<" en Categoría 2!!"<<endl;
                system("pause");
                bandera=1;
                return;
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 3:
        ///categoría 3
        if(categoriasJ1[2]==0){
            for(i=0;i<5;i++){
                if(dG1[i]==3){
                    categoriasJ1[2]+=3;
                    }
            }
            if(categoriasJ1[2]!=0){
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[2]<<" en Categoría 3!!"<<endl;
                system("pause");
                bandera=1;
                return;
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 4:
        ///categoría 4
        if(categoriasJ1[3]==0){
            for(i=0;i<5;i++){
                if(dG1[i]==4){
                    categoriasJ1[3]+=4;
                    }
            }
            if(categoriasJ1[3]!=0){
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[3]<<" en Categoría 4!!"<<endl;
                system("pause");
                bandera=1;
                return;
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 5:
        ///categoría 5
        if(categoriasJ1[4]==0){
            for(i=0;i<5;i++){
                if(dG1[i]==5){
                    categoriasJ1[4]+=5;
                    }
            }
            if(categoriasJ1[4]!=0){
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[4]<<" en Categoría 5!!"<<endl;
                system("pause");
                bandera=1;
                return;
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 6:
        ///categoría 6
        if(categoriasJ1[5]==0){
            for(i=0;i<5;i++){
                if(dG1[i]==6){
                    categoriasJ1[5]+=6;
                    }
            }
            if(categoriasJ1[5]!=0){
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[5]<<" en Categoría 6!!"<<endl;
                system("pause");
                bandera=1;
                return;
            }
        }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 7:
        ///escalera
        if(categoriasJ1[6]==0){
            if((dG1[0]==1 && dG1[1]==2 && dG1[2]==3 && dG1[3]==4 && dG1[4]==5) || (dG1[0]==2 && dG1[1]==3 && dG1[2]==4 && dG1[3]==5 && dG1[4]==6)){
                escalera++;
                }
            if(escalera==1){
                categoriasJ1[6]+=25;
                cout<<"Obtuviste en esta ronda: "<<categoriasJ1[6]<<" en Categoría ESCALERA!!"<<endl;
                system("pause");
                escalera==0;
                bandera=1;
                return;
                }
            }
            cout<<"Su tirada no se puede ingresar en esta categoria, ingrese otra nueva"<<endl;
            cin>>catGuardado;
        break;
        case 11:
            cout<<"*-----------------------------------SIN PUNTUACION--------------------------------------*"<<endl;
            cout<<"*----------------------------------FINALIZA EL TURNO------------------------------------*"<<endl;
            bandera=1;
            system("pause");
        break;
        default:
            cout<<"Categoría incorrecta, ingrese nuevamente"<<endl;
            cin>>catGuardado;
                }
            }
        }
void turnoJugador1(int dJ1[5], int categoriasJ1[10], int &turnos, int dG1[5], int descarte, int &tirada, int &tiradaGuardada, int eleccionTirada, string nJ1, string aJ1, int &catGuardado){
            int i;
            ///TIRADA 1
            ///NOTA: Tirada entra con valor 1
            tiradaGuardada=0;
            tirada=1;
            system("cls");
            cout<<nJ1<<" "<<aJ1<<endl;
            cout<<"Turno numero: "<<turnos<<endl;
            cout<<"*---------------------------------------------------------------*"<<endl;
            cout<<"Primera tirada!"<<endl;
            ///Realizo una tirada
            TirarDados(dJ1, dG1, tirada, tiradaGuardada, eleccionTirada);
            ///guarda los dados de la primera tirada en dG1
            for(i=0;i<5;i++){
                    dG1[i]=dJ1[i];
                }
                ///Muestro esa tirada
            mostrarDados(dJ1);
            ///pongo un system pause, porque sino sigue tirando el mismo numero
            system("pause");
            seleccionTirada(dJ1, dG1, categoriasJ1, descarte, tirada, turnos, tiradaGuardada, eleccionTirada, catGuardado);

            if(tirada==2){
                ///TIRADA 2
                system("cls");
                cout<<nJ1<<" "<<aJ1<<endl;
                cout<<"Turno numero: "<<turnos<<endl;
                cout<<"Segundo tiro"<<endl;
                cout<<"*------------------------------------------------*!"<<endl;
                system("pause");
                ///Realizo una tirada
                TirarDados(dJ1, dG1, tirada, tiradaGuardada, eleccionTirada);
                ///Muestro esa tirada
                mostrarDados(dG1);
                ///pongo un system pause, porque sino sigue tirando el mismo numero
                system("pause");
                seleccionTirada(dJ1, dG1, categoriasJ1, descarte, tirada, turnos, tiradaGuardada, eleccionTirada, catGuardado);
            }
            ///hago que tire solamente si no guardo categoría (2)
            if(tirada==3){
                ///TIRADA 3
                system("cls");
                cout<<nJ1<<" "<<aJ1<<endl;
                cout<<"Turno numero: "<<turnos<<endl;
                cout<<"Tercer tiro"<<endl;
                cout<<"*------------------------------------------------*"<<endl;
                system("pause");
                ///Realizo una tirada
                TirarDados(dJ1, dG1, tirada, tiradaGuardada, eleccionTirada);
                ///Muestro esa tirada
                mostrarDados(dG1);
                cout<<"*------------------------------------------------*"<<endl;
                cout<<"\nFinaliza el turno"<<endl;
                cout<<"*------------------------------------------------*"<<endl;
                turnos++;
                tirada=1;
                cout<<"¿En que categoria quiere guardar?\n Categoria 1-6, presione 1-6.\t Categoria Escalera presione. 7\t Categoria Full presione. 8\n Categoria Poker presione. 9\t Categoria Generala presione 10.\t Continuar sin guardar presione 11 "<<endl;
                cin>>catGuardado;
                categorias(categoriasJ1, dJ1, dG1, tirada, catGuardado);
                catGuardado=0;
                }
}

void turnoJugador2(int dJ1[5], int categoriasJ2[10], int &turnos2, int dG2[5], int descarte, int &tirada, int &tiradaGuardada, int eleccionTirada, string nJ2, string aJ2, int &catGuardado){
            int i;
            ///TIRADA 1
            ///NOTA: Tirada entra con valor 1
            tiradaGuardada=0;
            tirada=1;
            system("cls");
            cout<<nJ2<<" "<<aJ2<<endl;
            cout<<"Turno numero: "<<turnos2<<endl;
            cout<<"*------------------------------------------------*!"<<endl;
            cout<<"Primera tirada!"<<endl;
            ///Realizo una tirada
            TirarDados(dJ1, dG2, tirada, tiradaGuardada, eleccionTirada);
            ///Muestro esa tirada
            for(i=0;i<5;i++){
                    dG2[i]=dJ1[i];
                }
            mostrarDados(dJ1);
            ///pongo un system pause, porque sino sigue tirando el mismo numero
            system("pause");
            seleccionTirada2(dJ1, dG2, categoriasJ2, descarte, tirada, turnos2, tiradaGuardada, eleccionTirada, catGuardado);

            if(tirada==2){
                ///TIRADA 2
                system("cls");
                cout<<nJ2<<" "<<aJ2<<endl;
                cout<<"Turno numero: "<<turnos2<<endl;
                cout<<"Segundo tiro"<<endl;
                cout<<"*------------------------------------------------*!"<<endl;
                system("pause");
                ///Realizo una tirada
                TirarDados(dJ1, dG2, tirada, tiradaGuardada, eleccionTirada);
                ///Muestro esa tirada
                mostrarDados(dG2);
                ///pongo un system pause, porque sino sigue tirando el mismo numero
                system("pause");
                seleccionTirada2(dJ1, dG2, categoriasJ2, descarte, tirada, turnos2, tiradaGuardada, eleccionTirada, catGuardado);
            }
            ///hago que tire solamente si no guardo categoría (2)
            if(tirada==3){
                ///TIRADA 3
                system("cls");
                cout<<nJ2<<" "<<aJ2<<endl;
                cout<<"Turno numero: "<<turnos2<<endl;
                cout<<"Tercer tiro"<<endl;
                cout<<"*------------------------------------------------*"<<endl;
                system("pause");
                ///Realizo una tirada
                TirarDados(dJ1, dG2, tirada, tiradaGuardada, eleccionTirada);
                ///Muestro esa tirada
                mostrarDados(dG2);
                cout<<"*------------------------------------------------*"<<endl;
                cout<<"\nFinaliza el turno"<<endl;
                cout<<"*------------------------------------------------*"<<endl;
                turnos2++;
                tirada=1;
                cout<<"¿En que categoria quiere guardar?\n Categoria 1-6, presione 1-6.\t Categoria Escalera presione. 7\t Categoria Full presione. 8\n Categoria Poker presione. 9\t Categoria Generala presione 10.\t Continuar sin guardar presione 11 "<<endl;
                cin>>catGuardado;
                categorias(categoriasJ2, dJ1, dG2, tirada, catGuardado);
                catGuardado=0;
                }
}

///* Acá empieza el juego*///
void runJ1(int dJ1[5], int categoriasJ1[10], int &turnos, int dG1[5], int descarte, int &tirada, int &tiradaGuardada, int eleccionTirada, string nJ1, string aJ1, int &catGuardado){
    int puntajeFinal=0;
    int i;
    gotoxy(28,17);
    cout<<"Pulse cualquier tecla para jugar"<<endl;
    gotoxy(28,18);
    system("pause");
    const int tam=10;
    dadosEnCero(categoriasJ1, tam);

    ///while(categoriasJ1[0]==0 || categoriasJ1[1]==0 || categoriasJ1[2]==0 || categoriasJ1[3]==0 || categoriasJ1[4]==0 || categoriasJ1[5]==0 || categoriasJ1[6]==0 ||categoriasJ1[7]==0 || categoriasJ1[8]==0 || categoriasJ1[9]==0){
            while(turnos<=10){
            turnoJugador1(dJ1, categoriasJ1, turnos, dG1, descarte, tirada, tiradaGuardada, eleccionTirada, nJ1, aJ1, catGuardado);
        }

        system("cls");
        cout<<"FINALIZO EL JUEGO"<<endl;
        if(categoriasJ1[9]>50){
                           cout<<"Gano "<<nJ1<<" "<<aJ1<<endl;
                           return;
                        }
        cout<<"Puntaje por categoria:"<<endl;
        for(i=0;i<10;i++){
            cout<<"\nCategoría "<<i+1<<": \t"<<"["<<categoriasJ1[i]<<"]"<<endl;
            cout<<"*--------------------------------------------------------*"<<endl;
        }
        for(i=0;i<10;i++){
        puntajeFinal= puntajeFinal+categoriasJ1[i];
        }
        cout<<"\nTu puntaje total es: "<<puntajeFinal;

    return;
}

void runJ2(int dJ1[5], int categoriasJ1[10], int categoriasJ2[10], int &turnos, int &turnos2, int dG1[5], int dG2[5], int descarte, int &tirada, int &tiradaGuardada, int eleccionTirada, string nJ1, string aJ1, string nJ2, string aJ2, int &catGuardado){
    int start=0;
    int puntajeFinal=0, puntajeFinal2=0;
    int i;
    cout<<"Ingrese '1' para tirar los dados"<<endl;
    cin>>start;
    const int tam=10;
    dadosEnCero(categoriasJ1, tam);
    dadosEnCero(categoriasJ2, tam);

    ///while(categoriasJ1[0]==0 || categoriasJ1[1]==0 || categoriasJ1[2]==0 || categoriasJ1[3]==0 || categoriasJ1[4]==0 || categoriasJ1[5]==0 || categoriasJ1[6]==0 ||categoriasJ1[7]==0 || categoriasJ1[8]==0 || categoriasJ1[9]==0){
            while(turnos<=20 && turnos2<=20){

                turnoJugador1(dJ1, categoriasJ1, turnos, dG1, descarte, tirada, tiradaGuardada, eleccionTirada, nJ1, aJ1, catGuardado);
                turnoJugador2(dJ1, categoriasJ2, turnos2, dG2, descarte, tirada, tiradaGuardada, eleccionTirada, nJ2, aJ2, catGuardado);

                if(categoriasJ1[9]>50 && categoriasJ2[9]>50 && categoriasJ1[9]==categoriasJ2[9]){
                    cout<<"Empate!"<<endl;
                    return;
                }else{
                    if(categoriasJ1[9]!=0 || categoriasJ2[9]!=0){
                        if((categoriasJ1[9]>categoriasJ2[9]) && categoriasJ1[9]>50){
                           cout<<"Gano "<<nJ1<<" "<<aJ1<<endl;
                           return;
                        }
                        else{
                            if((categoriasJ1[9]<categoriasJ2[9]) && categoriasJ2[9]>50){
                            cout<<"Gano "<<nJ2<<" "<<aJ2<<endl;
                            }
                        }
                    }
                }

        }
        system("cls");
        cout<<"FINALIZO EL JUEGO"<<endl;
        cout<<"Puntajes por categorias"<<endl;
        for(i=0;i<10;i++){
            cout<<"\nCategoría "<<i+1<<" de "<<nJ1<<" "<<aJ1<<": \t"<<"["<<categoriasJ1[i]<<"]"<<"\t\t\tCategoría "<<i+1<<" de "<<nJ2<<" "<<aJ2<<": \t"<<"["<<categoriasJ2[i]<<"]"<<endl;
            cout<<"*-----------------------------------------------------------------------------------------*"<<endl;
        }
        for(i=0;i<10;i++){
        puntajeFinal= puntajeFinal+categoriasJ1[i];
        puntajeFinal2= puntajeFinal2+categoriasJ2[i];
        }
        cout<<"\nCantidad de turnos de "<<nJ1<<" "<<aJ1<<" es: "<<turnos-1<<"\t\tCantidad de turnos de "<<nJ2<<" "<<aJ2<<" es: "<<turnos2-1;
        cout<<"\nEl puntaje total de "<<nJ1<<" "<<aJ1<<" es: "<<puntajeFinal<<"\t\tEl puntaje total de "<<nJ2<<" "<<aJ2<<" es: "<<puntajeFinal2;
        if(puntajeFinal>puntajeFinal2){
            cout<<"\nGano el jugador "<<nJ1<<" "<<aJ1;
        }
        if(puntajeFinal2>puntajeFinal){
            cout<<"\nGano el jugador "<<nJ2<<" "<<aJ2;
            }
        if(puntajeFinal2==puntajeFinal){
           cout<<"\nHabeis empatao, tío"<<endl;
        }
        cout<<"\n*------------------------------------F I N---------------------------------------*"<<endl;
    return;
}

void cuadro(int x1, int y1, int x2, int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1);printf("Ä") ; //linea horizontal superior
		gotoxy(i,y2);printf("Ä") ; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i);printf("³") ; //linea vertical izquierda
		gotoxy(x2,i);printf("³") ; //linea vertical derecha
    }

    gotoxy(x1,y1); printf("Ú"); //Esquinas del cuadro
    gotoxy(x1,y2); printf("À");
    gotoxy(x2,y1); printf("¿");
    gotoxy(x2,y2); printf("Ù");
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
