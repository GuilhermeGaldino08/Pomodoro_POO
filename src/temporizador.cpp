#include "temporizador.h"

Temporizador::Temporizador()
{
    _ultimoMillisegundo = 0;
    _segundosRestantes = 0;
    _estadoPomodoro = false;
}

void Temporizador::configurar(int minutos)
{
    _segundosRestantes = minutos * 60;
    _estadoPomodoro = false;
}

void Temporizador::iniciar()
{
    _estadoPomodoro = true;
    _ultimoMillisegundo = millis();
}

void Temporizador::pausar() { _estadoPomodoro = false; }

void Temporizador::atualizar()
{
    if (_estadoPomodoro && (millis() - _ultimoMillisegundo >= 1000))
    {
        if (_segundosRestantes > 0) { // CORREÇÃO: Garante que os segundos nunca fiquem negativos
            _segundosRestantes--;
        }
        _ultimoMillisegundo = millis();
    }
}

// CORREÇÃO: Verifica se é menor ou igual a 0 por segurança
bool Temporizador::concluido() { return _segundosRestantes <= 0; }

int Temporizador::getMinutos() { return _segundosRestantes / 60; }

int Temporizador::getSegundos() { return _segundosRestantes % 60; }