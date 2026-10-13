# ⏱️ Pomodoro POO
Uma aplicação de cronômetro **Pomodoro** desenvolvida em C/C++ utilizando os conceitos de **Programação Orientada a Objetos (POO)**. O projeto foi estruturado utilizando o ecossistema **PlatformIO**, garantindo uma organização modular, limpa e escalável para o microcontrolador **ESP32-S3**.

## 🎯 Objetivo do Projeto
O principal objetivo deste repositório é aplicar os pilares da POO (Abstração, Encapsulamento, Herança e Polimorfismo) no desenvolvimento de um firmware focado em produtividade. A técnica Pomodoro divide o tempo de trabalho em blocos de 25 minutos, separados por breves intervalos, ajudando a manter o foco e a agilidade mental.

## 🚀 Tecnologias e Ferramentas
* **Linguagem:** C / C++
* **Plataforma Alvo:** ESP32-S3
* **Paradigma:** Programação Orientada a Objetos (POO)
* **Ambiente de Desenvolvimento:** [PlatformIO](https://platformio.org) / Visual Studio Code
* **Estrutura:** Suporte a testes unitários (pasta `test`) e gerenciamento nativo de dependências.

## 📁 Estrutura do Repositório
A organização do código segue o padrão recomendado pelo PlatformIO:
* `src/`: Contém os arquivos de código-fonte principais (`.cpp`).
* `include/`: Arquivos de cabeçalho globais (`.h`).
* `lib/`: Componentes e bibliotecas privadas reutilizáveis, isoladas por classes.
* `test/`: Testes unitários para validação da lógica de contagem e estados do Pomodoro.
* `platformio.ini`: Arquivo de configuração do hardware ESP32-S3, dependências e compilação do projeto.

## 🕹️ Controle de Fluxo e Botões
A interface é baseada em estados dinâmicos controlados por múltiplos botões interativos através da lógica orientada a objetos:

* **Botão Mais (`+`) / Botão Menos (`-`):** Utilizados exclusivamente nas telas de configuração. Permitem ajustar o tempo inicial do ciclo de **Foco** e do tempo de **Descanso** antes do cronômetro iniciar.
* **Botão Confirmar:** Salva os tempos definidos, avança para a próxima tela de configuração e inicia a contagem regressiva do temporizador.
* **Comportamento Baseado em Estados:** O software gerencia a transição automática entre os modos de contagem, pausa/descanso e alertas de fim de ciclo de forma blindada, evitando interferências e travamentos no fluxo principal (`main.cpp`).

## 🔌 Esquema de Ligação (ESP32-S3)
O projeto utiliza um **Display LCD 20x4 acoplado a um módulo adaptador I2C** (endereço padrão `0x27`), reduzindo drasticamente a quantidade de pinos necessários para a comunicação.

### Pinagem de Conexão do Display

| Pino do LCD (I2C) | Conexão no ESP32-S3 | Descrição |
| :--- | :--- | :--- |
| **GND** | GND | Aterramento comum do circuito |
| **VCC** | 5V / VBUS | Alimentação do Display (5V necessário para o backlight) |
| **SDA** | GPIO 8 | Linha de Dados I2C Nativa do S3 |
| **SCL** | GPIO 9 | Linha de Clock I2C Nativa do S3 |

*Nota: Certifique-se de configurar os pinos corretos de SDA e SCL na inicialização do barramento `Wire.begin(8, 9);` dentro do código do seu firmware.*

## ⚙️ Como Executar o Projeto

### Pré-requisitos
1. Instale o [Visual Studio Code](https://code.visualstudio.com/).
2. Instale a extensão do **PlatformIO IDE** no VS Code.

### Passo a Passo
1. Clone este repositório em sua máquina local:
   ```bash
   git clone https://github.com/GuilhermeGaldino08/Pomodoro_POO
   ```
2. Abra a pasta do projeto no VS Code.
3. O PlatformIO identificará o arquivo `platformio.ini` e começará a carregar as dependências e o framework do ESP32 automaticamente.
4. Para compilar o código, clique no ícone de **Check (Build)** na barra inferior do PlatformIO.
5. Para carregar o firmware no seu ESP32-S3, conecte a placa ao computador e clique no ícone de **Seta para a direita (Upload)**.

## 🧪 Executando Testes
Para rodar os testes unitários configurados na pasta `test`, utilize o atalho de testes do PlatformIO na barra de tarefas inferior ou execute o comando abaixo no terminal do PIO:
```bash
pio test
```

## ✒️ Autor
* **Guilherme Galdino** - [Meu GitHub](https://github.com/GuilhermeGaldino08)
