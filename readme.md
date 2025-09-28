### [English version](#Versao em portugues)

# 📘 Sistema de Registro de Atividades Físicas Diárias v1.0

## Descrição do Projeto

Este projeto é um **sistema de registro e visualização de atividades físicas diárias**, desenvolvido em **C**, permitindo ao usuário:

- Registrar atividades físicas por **dia da semana**.

- Organizar as atividades em **categorias** e **subcategorias**.

- Adicionar **novas categorias** e **novas atividades físicas**.

- Visualizar o **Top Day**, ou seja, o dia mais ativo da semana.

- Visualizar atividades físicas **por dia** ou **semana inteira**.

O sistema é interativo, baseado em menus de texto, simulando uma experiência de software real em console.

---

## Tecnologias e Conceitos Utilizados

O código explora recursos avançados da linguagem **C** e do console **Windows**:

- **Estruturas de dados em arrays multidimensionais**

    - `char atividadesFisicas[10][11][50]` para armazenar categorias e atividades físicas.

    - `int atividadesFisicasSelecinadas[50][3]` para armazenar registros de atividades físicas.

- **Manipulação de strings**

    - `strcpy()`, `strlen()`, `strcspn()` para cópia, cálculo de tamanho e remoção de caracteres de fim de linha.

    - Função `trim()` para remover espaços em branco no início das strings.

    - `fgets()` para leitura de entrada do usuário com espaços.

- **Controle de fluxo**

    - Estruturas condicionais `if`, `else if`, `else`.

    - Loops `for` e `do-while` para iterar por menus, categorias, dias da semana e registros.

    - Validação de entrada do usuário com funções `validaEntradaNumerica()` e `validaEntradaCaracters()`.

- **Menus interativos**

    - Funções separadas para cada menu:

        - `menuPrincipal()`

        - `menuVisualizarAtividadesFisicas()`

        - `menuRegistrarAtividadeFisica()`

        - Menus específicos por dia, categoria e atividade.

    - Opção de **adicionar novas categorias** ou **atividades físicas** dinamicamente.

- **Manipulação de dados numéricos**

    - Controle de índices para acessar corretamente arrays multidimensionais.

    - Determinação do **Top Day** usando lógica de contagem de atividades.

- **Console Windows**

    - `#include <Windows.h>` para suporte a `SetConsoleOutputCP(CP_UTF8)`, garantindo exibição correta de caracteres acentuados.

- **Boas práticas de C**

    - Uso de constantes (`const int MAX_CATEGORIA`, `MAX_ATIVIADE_FISICA`, etc.) para definir limites de arrays.

    - Modularização do código através de funções específicas para cada ação do sistema.

    - Comentários detalhados explicando cada bloco do programa.

---

## Funcionalidades Principais

**1. Registro de atividades**

- Seleção de dia da semana (Domingo a Sábado).

- Escolha da categoria de atividade.

- Escolha ou criação de novas atividades físicas.

- Controle do máximo de registros por semana.

**2. Visualização de atividades**

- Exibição por dia da semana.

- Exibição da semana inteira.

- Indicação do **Top Day**, dia com maior número de atividades registradas.

**3. Gestão de categorias e atividades**

- Criação de até **10 categorias**.

- Criação de até **10 atividades físicas por categoria**.

- Limite de **50 registros semanais**.

---

## Estrutura do Projeto
    ├── main.c               # Código-fonte principal do sistema
    ├── README.md            # Documentação do projeto
    └── LICENSE              # (Opcional) Licença do projeto

---
## Como Executar

**1.** Compile o código em um compilador C (ex: GCC, Visual Studio).

**2.** Execute o arquivo compilado no terminal/console:

    $ exemplo.exe

**3.** Siga os menus interativos para:

- Registrar atividades físicas.

- Visualizar registros por dia ou semana.

- Adicionar categorias ou atividades.

---

## Observações

- O projeto é totalmente **console-based**, sem interface gráfica.

- Suporta **entrada de strings com espaços** e exibição correta de caracteres acentuados.

- Limite máximo de **categorias**, **atividades e registros** definido para evitar estouro de memória.

---

### [Versao em portugues](#English version)
# 📘 Daily Physical Activity Recording System v1.0

## Project Description

This project is a **system for registering and visualizing daily physical activities**, developed in **C**, allowing the user to:

- Register physical activities by **day of the week**.
- Organize activities into **categories** and **subcategories**.
- Add **new categories** and **new physical activities**.
- View the **Top Day**, i.e., the most active day of the week.
- View physical activities **by day** or for the **entire week**.

The system is interactive, menu-based, simulating a real console software experience.

---

## Technologies and Concepts Used

The code explores advanced features of **C** and the **Windows console**:

- **Data structures using multidimensional arrays**
    - `char atividadesFisicas[10][11][50]` to store categories and physical activities.
    - `int atividadesFisicasSelecinadas[50][3]` to store activity records.

- **String manipulation**
    - `strcpy()`, `strlen()`, `strcspn()` for copying, calculating length, and removing newline characters.
    - `trim()` function to remove leading spaces from strings.
    - `fgets()` for reading user input with spaces.

- **Flow control**
    - Conditional structures: `if`, `else if`, `else`.
    - Loops: `for` and `do-while` for iterating through menus, categories, days of the week, and records.
    - User input validation with functions `validaEntradaNumerica()` and `validaEntradaCaracters()`.

- **Interactive menus**
    - Separate functions for each menu:
        - `menuPrincipal()`
        - `menuVisualizarAtividadesFisicas()`
        - `menuRegistrarAtividadeFisica()`
        - Day-, category-, and activity-specific menus.
    - Option to **dynamically add new categories** or **physical activities**.

- **Numeric data management**
    - Index control to correctly access multidimensional arrays.
    - Determination of the **Top Day** using activity count logic.

- **Windows Console**
    - `#include <Windows.h>` for `SetConsoleOutputCP(CP_UTF8)` support, ensuring correct display of accented characters.

- **C Best Practices**
    - Use of constants (`const int MAX_CATEGORIA`, `MAX_ATIVIADE_FISICA`, etc.) to define array limits.
    - Code modularization through specific functions for each system action.
    - Detailed comments explaining each program block.

---

## Main Features

**1. Activity Registration**
- Select a day of the week (Sunday to Saturday).
- Choose an activity category.
- Select or create new physical activities.
- Control the maximum number of records per week.

**2. Activity Visualization**
- Display activities by day of the week.
- Display activities for the entire week.
- Highlight the **Top Day**, the day with the highest number of registered activities.

**3. Category and Activity Management**
- Create up to **10 categories**.
- Create up to **10 activities per category**.
- Limit of **50 weekly records**.

---

## Project Structure
    ├── main.c # Main source code of the system
    ├── README.md # Project documentation
    └── LICENSE # (Optional) Project license

---

## How to Run

**1.** Compile the code using a C compiler (e.g., GCC, Visual Studio).

**2.** Run the compiled file in the terminal/console:

$ exemplo.exe

markdown
Copiar código

**3.** Follow the interactive menus to:
- Register physical activities.
- View records by day or week.
- Add categories or activities.

---

## Notes

- The project is entirely **console-based**, with no graphical interface.
- Supports **input of strings with spaces** and correct display of accented characters.
- Maximum limits for **categories**, **activities**, and **records** are defined to prevent memory overflow.