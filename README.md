# ⏱️ Pomodoro POO

Uma aplicação de cronômetro **Pomodoro** desenvolvida em C/C++ utilizando os conceitos de **Programação Orientada a Objetos (POO)**. O projeto foi estruturado utilizando o ecossistema **PlatformIO**, garantindo uma organização modular, limpa e escalável para o microcontrolador **ESP32-S3**.

## 🎯 Objetivo do Projeto
O principal objetivo deste repositório é aplicar os conceitos de **Abstração**, **Encapsulamento** e **Máquina de Estados** no desenvolvimento de um firmware focado em produtividade. A técnica Pomodoro divide o tempo de trabalho em blocos de foco (padrão de 25 minutos), separados por breves intervalos (padrão de 5 minutos), ajudando a manter a concentração.

## 🚀 Tecnologias e Ferramentas
- **Linguagem:** C / C++
- **Plataforma Alvo:** ESP32-S3
- **Paradigma:** Programação Orientada a Objetos (POO)
- **Ambiente de Desenvolvimento:** [PlatformIO](https://platformio.org) / Visual Studio Code
- **Bibliotecas Principais:**
  - `LiquidCrystal_I2C` (Controle do Display)
  - `Botao` (Localizada em `lib/` — desenvolvida pelo Prof. Thiago, veja em [Créditos](#-créditos))

## 📁 Estrutura do Repositório
A organização do código segue o padrão recomendado pelo PlatformIO:
- `src/`: Contém a implementação principal (`main.cpp`), o controle de interface/estados (`telas.cpp`) e a lógica do cronômetro (`temporizador.cpp`).
- `include/`: Arquivos de cabeçalho globais (`estados.h`, `telas.h`, `temporizador.h`).
- `lib/`: Componentes e bibliotecas privadas reutilizáveis.
- `platformio.ini`: Arquivo de configuração do hardware ESP32-S3, dependências e compilação do projeto.

## 🕹️ Controle de Fluxo e Botões
A interface é baseada em uma máquina de 7 estados (`estados.h`) controlada por três botões interativos:

- **Botão Mais (`+`) / Botão Menos (`-`):** Utilizados nas telas de configuração para ajustar a duração (em minutos, com mínimo de 1 minuto) dos ciclos de **Foco** e **Descanso**.
- **Botão Confirmar:**
  - Nas telas de configuração: salva o tempo definido e avança para a próxima etapa.
  - Durante a contagem (Foco ou Descanso): **pausa ou retoma** o cronômetro.
  - Na tela de ciclo concluído: avança automaticamente para o próximo ciclo (alternando entre Foco e Descanso).

## 🔌 Esquema de Ligação (ESP32-S3)
O projeto utiliza um **Display LCD 20x4 acoplado a um módulo adaptador I2C** (endereço padrão `0x27`) e três botões físicos.

### Pinagem do Display (I2C)

| Pino do LCD (I2C) | Conexão no ESP32-S3 | Descrição |
| :--- | :--- | :--- |
| **GND** | GND | Aterramento comum do circuito |
| **VCC** | 3.3V (3V) | Alimentação do Display e módulo I2C |
| **SDA** | GPIO 8 | Linha de Dados I2C padrão do ESP32-S3 |
| **SCL** | GPIO 9 | Linha de Clock I2C padrão do ESP32-S3 |

### Pinagem dos Botões

| Componente | Conexão no ESP32-S3 | Função |
| :--- | :--- | :--- |
| **Botão Mais (`+`)** | GPIO 1 | Incrementa os minutos na configuração |
| **Botão Menos (`-`)** | GPIO 2 | Decrementa os minutos na configuração |
| **Botão Confirmar** | GPIO 3 | Avança telas, pausa/retoma e confirma ciclos |

> **⚠️ Nota sobre os pinos dos botões:** Os pinos GPIO 1, 2 e 3 declarados no arquivo `main.cpp` são **apenas demonstrativos** para testes iniciais de software. No projeto físico, eles devem ser alterados de acordo com a pinagem utilizada na sua montagem.

## ⚙️ Como Executar o Projeto

### Pré-requisitos
1. Instale o [Visual Studio Code](https://code.visualstudio.com/).
2. Instale a extensão do **PlatformIO IDE** no VS Code.

### Passo a Passo de Execução
1. **Clonar o Repositório:**
   Abra o terminal e execute o comando abaixo para baixar o projeto:
   ```bash
   git clone https://github.com/GuilhermeGaldino08/Pomodoro_POO
   ```
3. **Abrir o Projeto:**
   Abra a pasta clonada no Visual Studio Code. O PlatformIO irá reconhecer automaticamente o arquivo `platformio.ini` e começará a baixar o framework e as dependências.
5. **Compilar (Build):**
   Clique no ícone de **Check (✓)** na barra inferior do PlatformIO (ou execute `pio run` no terminal) para verificar se o código compila sem erros.
7. **Fazer o Upload (Gravação):**
   Conecte o seu ESP32-S3 ao computador através do cabo USB. Clique no ícone de **Seta para a direita (→)** na barra inferior para compilar e enviar o firmware para a placa.
9. **Monitor Serial (Opcional):**
    Caso queira debugar o comportamento, clique no ícone de **Tomada** na barra inferior para abrir o Monitor Serial.

## 🤝 Créditos
A biblioteca `Botao`, utilizada na pasta `lib/` para o controle eficiente dos estados físicos (*debounce* e leitura), não é de minha autoria. Ela foi desenvolvida e disponibilizada pelo **Professor Thiago**.
- [Acesse o GitHub do Professor Thiago aqui](https://github.com/professorThiago)

## ✒️ Autor
- **Guilherme Galdino** - [Meu GitHub](https://github.com/GuilhermeGaldino08)
