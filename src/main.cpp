#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Botao.h>
#include "Telas.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

Botao btnMais(1);   
Botao btnMenos(2);  
Botao btnConfirmar(3);  

void setup()
{
    lcd.init();
    lcd.backlight();

    btnMais.iniciar();
    btnMenos.iniciar();
    btnConfirmar.iniciar();
}

void loop()
{
    btnMais.atualizar();
    btnMenos.atualizar();
    btnConfirmar.atualizar();

    if (btnMais.pressionou())
    {
        acionarBotaoMais();
    }

    if (btnMenos.pressionou())
    {
        acionarBotaoMenos();
    }

    if (btnConfirmar.pressionou())
    {
        acionarBotaoConfirmar();
    }

    gerenciarCicloPomodoro();
}