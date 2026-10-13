# ⏱️ Pomodoro POO
Uma aplicação de cronômetro **Pomodoro** desenvolvida em C/C++ utilizando os conceitos de **Programação Orientada a Objetos (POO)**. O projeto foi estruturado utilizando o ecossistema **PlatformIO**, garantindo uma organização modular, limpa e escalável para sistemas embarcados.

## 🎯 Objetivo do Projeto
O principal objetivo deste repositório é aplicar os pilares da POO (Abstração, Encapsulamento, Herança e Polimorfismo) no desenvolvimento de um firmware focado em produtividade. A técnica Pomodoro divide o tempo de trabalho em blocos de 25 minutos, separados por breves intervalos, ajudando a manter o foco e a agilidade mental.

## 🚀 Tecnologias e Ferramentas
* **Linguagem:** C / C++
* **Paradigma:** Programação Orientada a Objetos (POO)
* **Ambiente de Desenvolvimento:** [PlatformIO](https://platformio.org) / Visual Studio Code
* **Estrutura:** Suporte a testes unitários (pasta `test`) e gerenciamento nativo de dependências.

## 📁 Estrutura do Repositório
A organização do código segue o padrão recomendado pelo PlatformIO:
* `src/`: Contém os arquivos de código-fonte principais (`.cpp`).
* `include/`: Arquivos de cabeçalho globais (`.h`).
* `lib/`: Componentes e bibliotecas privadas reutilizáveis, isoladas por classes.
* `test/`: Testes unitários para validação da lógica de contagem e estados do Pomodoro.
* `platformio.ini`: Arquivo de configuração de hardware, dependências e compilação do projeto.

## ⚙️ Como Executar o Projeto

### Pré-requisitos
1. Instale o [Visual Studio Code](https://visualstudio.com).
2. Instale a extensão do **PlatformIO IDE** no VS Code.

### Passo a Passo
1. Clone este repositório em sua máquina local:
   ```bash
   git clone https://github.com
   ```
2. Abra a pasta do projeto no VS Code.
3. O PlatformIO identificará o arquivo `platformio.ini` e começará a carregar as dependências automaticamente.
4. Para compilar o código, clique no ícone de **Check (Build)** na barra inferior do PlatformIO.
5. Para carregar o firmware na sua placa de desenvolvimento, clique no ícone de **Seta para a direita (Upload)**.

## 🧪 Executando Testes
Para rodar os testes unitários configurados na pasta `test`, utilize o atalho de testes do PlatformIO na barra de tarefas inferior ou execute o comando abaixo no terminal do PIO:
```bash
pio test
```

## ✒️ Autor
* **Guilherme Galdino** - [Seu GitHub](https://github.com/GuilhermeGaldino08)
