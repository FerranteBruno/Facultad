/*#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>

using namespace std;

void categorias(int categoriasJ1[10], int dJ1[5], int dG1[5], int &tirada){
    int i, j;
    int escalera=0;
    const int tam=10;
    dadosEnCero(categoriasJ1, tam);

    ///Generali
    if(categoriasJ1[9]==0){
        for(i=1;i<7;i++){
            if(dG1[0]==i && dG1[1]==i && dG1[2]==i && dG1[3]==i && dG1[4]==i){
                if(tirada==1){
                    cout<<"Ganaste el juego!!"<<endl;
                }
                else{
                    cout<<"Guardaste tus puntos de GENERALA!!"<<endl;
                    categoriasJ1[9]+=50;
                    }
                }
            return;
        }
    }
    ///categor�a 1}
    if(categoriasJ1[0]==0){
        for(i=0;i<5;i++){
            if(dG1[i]==1){
                categoriasJ1[0]++;
            }
            cout<<"Guardaste"<<categoriasJ1[0]<<"en Categor�a 1!!"<<endl;
            return;
        }
    }
    ///categor�a 2
    if(categoriasJ1[1]==0){
        for(i=0;i<5;i++){
            if(dG1[i]==2){
                categoriasJ1[1]+=2;
            }
            cout<<"Guardaste"<<categoriasJ1[1]<<"en Categor�a 2!!"<<endl;
            return;
        }
    }
    ///categor�a 3
    if(categoriasJ1[2]==0){
        for(i=0;i<5;i++){
            if(dG1[i]==3){
                categoriasJ1[2]+=3;
            }
            cout<<"Guardaste"<<categoriasJ1[2]<<"en Categor�a 3!!"<<endl;
            return;
        }
    }
    ///categor�a 4
    if(categoriasJ1[3]==0){
        for(i=0;i<5;i++){
            if(dG1[i]==4){
                categoriasJ1[3]+=4;
            }
            cout<<"Guardaste"<<categoriasJ1[3]<<"en Categor�a 4!!"<<endl;
            return;
        }
    }
    ///categor�a 5
    if(categoriasJ1[4]==0){
        for(i=0;i<5;i++){
            if(dG1[i]==5){
                categoriasJ1[4]+=5;
            }
            cout<<"Guardaste"<<categoriasJ1[4]<<"en Categor�a 5!!"<<endl;
            return;
        }
    }
    ///categor�a 6
    if(categoriasJ1[5]==0){
        for(i=0;i<5;i++){
            if(dG1[i]==6){
                categoriasJ1[5]+=6;
            }
            cout<<"Guardaste"<<categoriasJ1[5]<<"en Categor�a 6!!"<<endl;
            return;
        }
    }
    ///escalera
    if(categoriasJ1[6]==0){
    for(j=0;j<3;j++){
        if(dG1[j]==j+1 && dG1[j+1]==j+2){
            escalera++;
            }
        }
        if(escalera==3){
            categoriasJ1[6]+=25;
            cout<<"Guardaste"<<categoriasJ1[6]<<"en Categor�a ESCALERA!!"<<endl;
            return;
            }
        else{
            escalera=0;
            for(j=1;j<4;j++){
                if(dG1[j]==j+1 && dG1[j+1]==j+2){
                    escalera++;
                }
            }
            if(escalera==3){
                categoriasJ1[6]+=25;
                cout<<"Guardaste"<<categoriasJ1[6]<<"en Categor�a ESCALERA!!"<<endl;
            return;
            }
        }
    }
    ///full
    ///compruebo que este llena la categor�a
        if(categoriasJ1[7]==0){
    ///busco los valores de los dados
            for(i=1;i<7;i++){
                if((dG1[0]==i && dG1[1]==i && dG1[2]==i && dG1[3]==dG1[4]) || (dG1[0]==dG1[1] && dG1[2]==i && dG1[3]==i && dG1[4]==i)){
                    categoriasJ1[7]+=30;
                }
            }
            cout<<"Guardaste"<<categoriasJ1[7]<<"en Categor�a Full!!"<<endl;
        return;
        }

    ///poker
    ///compruebo que este llena la categor�a
        if(categoriasJ1[8]==0){
            for(i=1;i<7;i++){
                if((dG1[0]==i && dG1[1]==i && dG1[2]==i && dG1[3]==i) || (dG1[1]==i && dG1[2]==i && dG1[3]==i && dG1[4]==i)){
                    categoriasJ1[8]+=40;
                }
            }
            cout<<"Guardaste"<<categoriasJ1[8]<<"en Categor�a Poker!!"<<endl;
        return;
        }
}

/***
Quer�a hacer un switch para
*/
