/*
    Autor: Tiago André Lachman
    Biblioteca com o objetivo de otimizar o uso do Demultiplexador.
*/


#include <Arduino.h>

#ifndef MuxClass.h
#define MuxClass.h

//Erros do demux
#define MUX_OK        0
#define UNKNOWN         1
#define NOT_IN_RANGE    2


//Tipos de controle disponíveis do Demux
#define MUX     0
#define DEMUX   1


class Mux{
private:
    int* inhEnables;//Pinos dos inhEnables
    int* controls;//Pinos de comando do mux
    int numInhEnables;//Tamanho do vetor inhEnables
    int numControls;//Tamanho do vetor controls
    int numSaidas;//Números de saídas/entradas disponíveis para controle
    int potControls;//Variavel para armazenar quantas combinações são 
                    //possiveis dado o numero de pinos de controle

public:
    Mux(
        int* pinInhEnables,
        int sizeInhEnables,
        int* pinControls,
        int sizeControls
    );

    int ligarSaida(int numOut);//Liga uma saída do multiplexador
    int lerEntrada(int numOut);//Lê uma entrada do multiplexador


    int maxSaidas();//Retorna o número de saídas disponíveis

protected:
    void paraBin(int num, bool* vetor, int tam=3){ //Decimal para binário
        for(int i=0;i<tam;i++){
            vetor[i] = num%2;
            num = num/2;
        }
    }

};


#endif