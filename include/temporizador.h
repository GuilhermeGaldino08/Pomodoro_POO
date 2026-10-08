#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include <Arduino.h>

class Temporizador
{
private:
    unsigned long _ultimoMillisegundo; 
    int _segundosRestantes;             
    bool _estadoPomodoro;             

public:
    Temporizador();
    
    void configurar(int minutos);     
    void iniciar();                    
    void pausar();                 
    void atualizar();               
    bool concluido();               

    int getMinutos();                  
    int getSegundos();                 
};

#endif