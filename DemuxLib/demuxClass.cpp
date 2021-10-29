/*
    Autor: Tiago André Lachman
    Biblioteca com o objetivo de otimizar e simplificar o uso do Demultiplexador.
*/


#include <MuxClass.h>

Mux::Mux(//Construct do Demux
    int* pinInhEnables,
    int sizeInhEnables,
    int* pinControls,
    int sizeControls
    ){
    this -> inhEnables = pinInhEnables;
    this -> controls = pinControls;
    this -> numControls = sizeControls;
    this -> numInhEnables = sizeInhEnables;

    this -> potControls = pow(2, sizeControls);
    this -> numSaidas = potControls * sizeInhEnables - 1;
}

int Mux::ligarSaida(int numOut){
    if(numOut < 0 || numOut > numSaidas) return NOT_IN_RANGE;

    bool statusControls[numControls];
    bool statusEnables[numInhEnables];

    for(int i=0;i<numInhEnables;i++){//Desliga todas as saídas
        statusEnables[i] = 1;
        digitalWrite(inhEnables[i], 1);
    }

    paraBin(numOut, statusControls, numControls);//Transforma o valor da saída requisitada em bits
    
    for(int i=1;i<=numInhEnables;i++){//Verifica qual CI do demux deverá ser acionado
        if(numOut < (i * potControls) && numOut >= ((i-1) * potControls)){
            statusEnables[i-1] = 0;
            break;
        } else if (i==numInhEnables){
            return UNKNOWN;
        }
    }
    for(int i = numControls-1; i >=0 ; i--){//Liga as portas de controle correspondente ao valor
        digitalWrite(controls[2-i], statusControls[i]);
    }
    for(int i = 0; i < numInhEnables; i++){//Manda ligar o CI correspondente ao valor
        digitalWrite(inhEnables[i], statusEnables[i]);
    }
    return  MUX_OK;//Função executada sem falhas
}

int Mux::maxSaidas(){
    return this->numSaidas;
}