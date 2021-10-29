/*
    Autor: Tiago André Lachman
    Biblioteca com o objetivo de otimizar o uso do Demultiplexador.
*/


#include <Arduino.h>

#ifndef MuxClass.h
#define MuxClass.h

//Erros do demux
#define MUX_OK          520
#define UNKNOWN         521
#define NOT_IN_RANGE    522
#define WRONG_MODE      523


//Tipos de controle disponíveis do Demux
#define MUX     0
#define DEMUX   1


class Mux{
private:
    int mode;
    int* common;//Pino comum do mux
    int* inhEnables;//Pinos dos inhEnables do mux/demux
    int* controls;//Pinos de comando do mux/demux
    int numInhEnables;//Tamanho do vetor inhEnables
    int numControls;//Tamanho do vetor controls
    int numSaidas;//Números de saídas/entradas disponíveis para controle do mux/demux
    int potControls;//Variavel para armazenar quantas combinações são 
                    //possiveis dado o numero de pinos de controle do mux/demux

public:
    Mux(
        int* pinInhEnables,
        int sizeInhEnables,
        int* pinControls,
        int sizeControls,
        int mode
    );
    Mux(
        int* pinInhEnables,
        int sizeInhEnables,
        int* pinControls,
        int sizeControls,
        int* pinCom,
        int mode
    );

    int ligarSaida(int numOut);//Liga uma saída do multiplexador
    int lerEntrada(int numOut);//Lê uma entrada do multiplexador


    int maxSaidas();//Retorna o número de saídas disponíveis

    int showMode();//Retorna o modo definido

protected:
    void paraBin(int num, bool* vetor, int tam=3){ //Decimal para binário
        for(int i=0;i<tam;i++){
            vetor[i] = num%2;
            num = num/2;
        }
    }

};


#endif
