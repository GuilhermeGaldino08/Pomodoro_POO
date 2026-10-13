#ifndef TELAS_H
#define TELAS_H

#include <LiquidCrystal_I2C.h>
extern LiquidCrystal_I2C lcd;

void gerenciarCicloPomodoro();

void acionarBotaoMais();
void acionarBotaoMenos();
void acionarBotaoConfirmar();

#endif                                                                          