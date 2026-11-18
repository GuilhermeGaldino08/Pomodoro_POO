#include "telas.h"
#include "estados.h"
#include "temporizador.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int estadoAtual = _configFoco;
int tempoConfigFoco = 25;
int tempoConfigDescanso = 5;

Temporizador cronometro;

int ultimoEstadoSalvo = -1;
int ultimoSegundoSalvo = -1;
int ultimoTempoConfigFoco = -1;      // CORREÇÃO: Variável para atualizar a tela ao apertar + ou -
int ultimoTempoConfigDescanso = -1;  // CORREÇÃO: Variável para atualizar a tela ao apertar + ou -
int faseAnterior = -1;               // CORREÇÃO: Variável para saber se o alerta veio do Foco ou do Descanso

void desenharTelaConfigFoco()
{
    lcd.setCursor(5, 0);
    lcd.print("Tempo de Foco");
    lcd.setCursor(6, 2);
    if (tempoConfigFoco < 10) lcd.print("0"); 
    lcd.print(tempoConfigFoco);
    lcd.print(" min "); 
}

void desenharTelaConfigDescanso()
{
    lcd.setCursor(3, 0);
    lcd.print("Tempo de descanso");
    lcd.setCursor(6, 2);
    if (tempoConfigDescanso < 10) lcd.print("0"); 
    lcd.print(tempoConfigDescanso);
    lcd.print(" min "); 
}

void desenharTelaCronometroFoco()
{
    lcd.setCursor(8, 0);
    lcd.print("Foco");
    lcd.setCursor(7, 2);
    int minutos = cronometro.getMinutos();
    int segundos = cronometro.getSegundos();
    if (minutos < 10) lcd.print("0");
    lcd.print(minutos);
    lcd.print(":");
    if (segundos < 10) lcd.print("0");
    lcd.print(segundos);
}

void desenharTelaCronometroDescanso()
{
    lcd.setCursor(7, 0);
    lcd.print("Pausa");
    lcd.setCursor(7, 2);
    int minutos = cronometro.getMinutos();
    int segundos = cronometro.getSegundos();
    if (minutos < 10) lcd.print("0");
    lcd.print(minutos);
    lcd.print(":");
    if (segundos < 10) lcd.print("0");
    lcd.print(segundos);
}

void desenharTelaAlertaFim()
{
    lcd.setCursor(4, 0);
    lcd.print("Ciclo concluido");
    lcd.setCursor(2, 2);
    lcd.print("Toque para avancar");
}

void gerenciarCicloPomodoro()
{
    cronometro.atualizar();
    int segundoAtual = cronometro.getSegundos();

    bool mudouEstado = (estadoAtual != ultimoEstadoSalvo);
    bool mudouSegundo = (segundoAtual != ultimoSegundoSalvo);
    bool mudouConfigFoco = (estadoAtual == _configFoco && tempoConfigFoco != ultimoTempoConfigFoco);
    bool mudouConfigDescanso = (estadoAtual == _configDescanso && tempoConfigDescanso != ultimoTempoConfigDescanso);

    if (mudouEstado || mudouSegundo || mudouConfigFoco || mudouConfigDescanso)
    {
        ultimoEstadoSalvo = estadoAtual;
        ultimoSegundoSalvo = segundoAtual;
        ultimoTempoConfigFoco = tempoConfigFoco;
        ultimoTempoConfigDescanso = tempoConfigDescanso;

        lcd.clear();

        switch (estadoAtual)
        {
        case _configFoco:           desenharTelaConfigFoco(); break;
        case _configDescanso:       desenharTelaConfigDescanso(); break;
        case _contandoFoco:         desenharTelaCronometroFoco(); break;
        case _pausadoFoco:          desenharTelaCronometroFoco();  break;
        case _contandoDescanso:     desenharTelaCronometroDescanso(); break;
        case _pausadoDescanso:      desenharTelaCronometroDescanso(); break;
        case _alertaFim:            desenharTelaAlertaFim(); break;
        }
    }

    if (cronometro.concluido() && (estadoAtual == _contandoFoco || estadoAtual == _contandoDescanso))
    {
        faseAnterior = estadoAtual; // CORREÇÃO: Salva de onde viemos antes de ir para o alerta
        cronometro.pausar();        // CORREÇÃO: Pausa o cronômetro para não contar negativo
        estadoAtual = _alertaFim;
    }
}

void acionarBotaoMais()
{
    switch (estadoAtual)
    {
    case _configFoco: tempoConfigFoco++; break;
    case _configDescanso: tempoConfigDescanso++; break;
    }
}

void acionarBotaoMenos()
{
    switch (estadoAtual)
    {
    case _configFoco: tempoConfigFoco = (tempoConfigFoco > 1) ? (tempoConfigFoco - 1) : 1; break;
    case _configDescanso: tempoConfigDescanso = (tempoConfigDescanso > 1) ? (tempoConfigDescanso - 1) : 1; break;
    }
}

void acionarBotaoConfirmar()
{
    switch (estadoAtual)
    {
    case _configFoco:
        estadoAtual = _configDescanso;
        break;

    case _configDescanso:
        cronometro.configurar(tempoConfigFoco);
        cronometro.iniciar();
        estadoAtual = _contandoFoco;
        break;

    case _contandoFoco:
        cronometro.pausar();
        estadoAtual = _pausadoFoco;
        break;

    case _pausadoFoco:
        cronometro.iniciar();
        estadoAtual = _contandoFoco;
        break;

    case _contandoDescanso:
        cronometro.pausar();
        estadoAtual = _pausadoDescanso;
        break;

    case _pausadoDescanso:
        cronometro.iniciar();
        estadoAtual = _contandoDescanso;
        break;

    case _alertaFim:
        // CORREÇÃO: Verifica de onde o alerta veio para decidir qual é o próximo passo
        if (faseAnterior == _contandoFoco) {
            cronometro.configurar(tempoConfigDescanso);
            cronometro.iniciar();
            estadoAtual = _contandoDescanso;
        } else {
            // Se acabou o descanso, inicia um novo ciclo de Foco automaticamente
            cronometro.configurar(tempoConfigFoco);
            cronometro.iniciar();
            estadoAtual = _contandoFoco;
        }
        break;
    }
}