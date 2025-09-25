#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()


void apresentacaoSistema();
void menuPrincipal();
void menuVisualizarAtividadesFisicas(char diasDaSemana[][15]);
void menuVisualizarAtividadesFisicasDia(int dia, char diasDaSemana[][15], char atividadesFisicas[][2][11][30], int numeroCategorias);
void menuRegistrarAtividadeFisica(char diasDaSemana[][15]);
void menuRegistrarAtividadeFisicaDia(int dia, char diasDaSemana[][15], char atividadesFisicas[][2][11][30], int numeroCategorias);
int validaEntradaNumerica(int opcao, int returnOpcao, int menu);
void mensagemEncerramento();

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Definindo as variáveis de manipulação dos menus
    int menu = 0, returnMenu = 0;

    // Definindo as variáveis de manipulação das opções do menu    
    int opcao = 0, returnOpcao = 0;

    // Domingo a Sabado - 1 a 7 / Todos os dias - 8
    int dia = 0;

    // Declarando os dias da semana
    char diasDaSemana[][15] = {
        "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira",
        "Quinta-Feira", "Sexta-Feira", "Sábado"
    };    

    // Declarando as atividades físicas
    // até 10 categorias 
    // até 10 subcategorias
    // max 20 caracteres por item
    char atividadesFisicas[][2][11][30] =  {
        {
            "Cardiorespiratórios",
            "Corrida / Trote",
            "Caminhada",
            "Ciclismo",
            "Pular corda",
            "Natação",
            "Escalada indoor / step",
            "", "", "", ""
        },
        {
            "Força / Musculação",
            "Flexões (Push-ups)",
            "Agachamentos (Squats)",
            "Afundos (Lunges)",
            "Levantamento terra (Deadlift)",
            "Supino (Bench press)",
            "Remada (Row)",
            "Prancha (Plank) – para core",
            "", "", ""
        }
    };

    int numAtividades = sizeof(atividadesFisicas);
    // Número de categorias cadastradas
    int numeroCategorias = sizeof(atividadesFisicas[0]) / sizeof(atividadesFisicas[0][0]);    

    // Mensagem inicial
    apresentacaoSistema();

    // Loop principal do sistema
    // Verifica a variável opcao no final do loop while
    do {
        
        // Menu 0 - Menu principal - "Menu de opçoes"   
        // Loop que garante uma entrada numérica válida
        do {        
            // Menu principal -> "Menu de opções" 
            menuPrincipal();

            // Opcao selecionada pelo usuario
            returnOpcao = scanf("%d", &opcao);
            
            // Limpando o buffer de entrada!!!!
            while(getchar() != '\n');

        // Valida a entrada numerica antes de prosseguir
        } while (!validaEntradaNumerica(opcao, returnOpcao, menu));
        
        // Verifica qual opção do menu principal foi escolhida
        switch (opcao) {

            // Opção 1 - "Visualizar as atividades físicas"
            case 1:

                // Loop para retorno ao Menu 1
                do {
                    // Menu 1 - "Visualizar as atividades físicas"
                    // Loop que garante uma entrada numérica válida
                    do {                                
                        // Menu "Visualizar as atividades físicas"
                        // O usuário deve escolher um dia da semana
                        menu = 1;
                        menuVisualizarAtividadesFisicas(diasDaSemana);

                        // Opcao selecionada pelo usuario
                        returnOpcao = scanf("%d", &opcao);

                        // Limpando o buffer de entrada!!!!
                        while(getchar() != '\n');

                    // Valida a entrada numerica antes de prosseguir
                    } while (!validaEntradaNumerica(opcao, returnOpcao, menu));                

                    // Verifica qual opção do menu (dia da semana) foi escolhida
                    switch(opcao) {
                        case 1:                        
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                            // Domingo a Sabado - 1 a 7 / Todos os dias - 8
                            dia = opcao;
                            // Primeiro dígito (1) - Visualizar as atividades físicas
                            // Segundo dígito (opcao) - Identifica o dia da semana ou todos os dias
                            menu = opcao + 10;
                            break;
                        default:
                            // Opcao 9 - Voltar
                            // Volta para o menu principal
                            menu = 0;
                            break;
                    }

                    if (menu >= 11 && menu <= 18) {
                        // ------------------   
                        // Menu 11 a 18 - "Vizualizar as atividades físicas por dia"
                        // Mostra na tela as atividades físicas para o/os dias selecionados                    
                        // Primeiro dígito [1] - Visualizar as atividades físicas
                        // Segundo dígito [opcao] - Identifica o dia da semana [1-7] ou todos os dias [8]

                        // Loop que garante uma entrada numérica válida
                        do {                                
                            // Menu "Vizualizar atividades físicas por dia"                            
                            menuVisualizarAtividadesFisicasDia(dia, diasDaSemana, atividadesFisicas, numeroCategorias);

                            // Opcao selecionada pelo usuario
                            returnOpcao = scanf("%d", &opcao);

                            // Limpando o buffer de entrada!!!!
                            while(getchar() != '\n');

                            printf("Entre com a opção: ");

                        // Valida a entrada numerica antes de prosseguir
                        } while (!validaEntradaNumerica(opcao, returnOpcao, menu)); 

                        // Verifica de opção escolhida
                        if (opcao == 1) {
                            // volta para o menu alterior
                            menu = 1;
                        }
                    }
                                        
                // Fica no loop ate a opção voltar ser escolhida (menu = 0).
                } while (menu == 1);

                break;

            // 2 - Registrar uma atividade física
            case 2:

                // Loop para retorno ao menu 2
                do {
                    // menu 2 - "Registrar uma atividade física"
                    // Loop que garante uma entrada numérica válida
                    do {        
                        // Menu "Registrar uma atividade física"                            
                        menu = 2;
                        menuRegistrarAtividadeFisica(diasDaSemana);

                        // Opcao selecionada pelo usuario
                        returnOpcao = scanf("%d", &opcao);

                        // Limpando o buffer de entrada!!!!
                        while(getchar() != '\n');

                    // Valida a entrada numerica antes de prosseguir
                    } while (!validaEntradaNumerica(opcao, returnOpcao, menu));    

                    // Verifica qual opção do submenu foi escolhida
                    switch(opcao) {
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            break;
                        default:
                            // Opcao 8 - Voltar
                            // Volta para o menu principal
                            menu = 0;
                            break;
                    }

                // Fica no loop ate a opção voltar ser escolhida (menu = 0).
                } while (menu == 2);
                
                break;
            
            default:
                // Foi digitado a opção de sair (opcao igual a 3)
                // Define opcao igual a  para sair do loop while         
                opcao = 0;            
                break;
        }
    
    // Opcao igual a 0 encerra o sistema!
    } while (opcao != 0);

    return 0;
}

void apresentacaoSistema() {
    // Apresnetação do sistema
    printf("\n=== Sistema de Registro de Atividades Físicas v1.0 ===\n");
    printf("\nSobre:\n");
    printf("Desenvolvido por Fabio Toledo Bonemer De Salvi\n");
    printf("\n");
    printf("* Visualize as suas atividades físicas diárias\n");
    printf("-> Visualize por dia da semana ou por semana inteira!\n");
    printf("-> Destaque para o dia mais ativo! \"Top Day\"!\n");
    printf("\n");
    printf("* Registre as suas atividades físicas diárias\n");
    printf("-> Escolha um dia da semana, uma categoria e uma atividade física!\n");
}

void menuPrincipal() {
    // Menu 0 - Menu principal
    // Menu inicial    
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Menu de opções:\n");
    printf("1 - Visualizar as atividades físicas\n");
    printf("2 - Registrar uma atividade física\n");            
    printf("3 - Sair\n");
    printf("Digite a opção desejada: ");
}

void menuVisualizarAtividadesFisicas(char diasDaSemana[][15]) {
    // Menu 1 - Opção 1 do menu principal
    // Vizualizar as atividades físicas
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Visualizar as Atividades Físicas\n");
    // Imprime os dias da semana
    for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
        printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
    printf("8 - Semana inteira\n");
    printf("9 - Voltar\n");
    printf("Visualizar as atividade físicas de qual(quais) dia(s)?\nEntre com a opção: ");
}

void menuVisualizarAtividadesFisicasDia(int dia, char diasDaSemana[][15], char atividadesFisicas[][2][11][30], int numeroCategorias) {
    // Menu  11 ao 18 - Vizualizar as atividades físicas por dia 
    // Opção 1 a 7 - [Domingo ao Sábado]
    // ou
    // Opção 8 - [Semana inteira]
    printf("\n=== Vizualizar as Atividades Físicas ===\n");
    // Imprime as atrividades físicas               
    if (dia == 8) {
        for (int indexDia = 0; indexDia <= 6; indexDia++) {
            if (indexDia > 0 && indexDia < 6)
                printf(">> Atividades físicas da %s:\n", diasDaSemana[indexDia]);
            else
                printf(">> Atividades físicas do %s:\n", diasDaSemana[indexDia]);
        }
        
    } else {
        if (dia > 1 && dia < 7)
            printf(">> Atividades físicas da %s:\n", diasDaSemana[dia-1]);
        else
            printf(">> Atividades físicas do %s:\n", diasDaSemana[dia-1]);
    }
    // Imprime as atrividades físicas               
    printf("1 - Voltar\n");
    printf("Entre com a opção: ");    
}

void menuRegistrarAtividadeFisica(char diasDaSemana[][15]) {
    // Menu 2 - Opção 2 do menu menu principal
    // Registrar atividade física
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Escolha um dia para adicionar a atividade física:\n");
    // Imprime os dias da semana
    for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
        printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
    printf("8 - Voltar\n");
    printf("Entre com a opção: ");
}

void menuRegistrarAtividadeFisicaDia(int dia, char diasDaSemana[][15], char atividadesFisicas[][2][11][30], int numeroCategorias) {
    // Registrar uma atividade física (menu = 1)
    // Opção 1 - Segunda-Feira
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Registrar Atividades Físicas\n");
    printf(">> %s\n", diasDaSemana[dia-10-1]);
    // Imprime as categorias de atividade física
    for (int indiceCategoria = 0;
            indiceCategoria < numeroCategorias;
            indiceCategoria++)
        printf("%d - %s\n", indiceCategoria + 1, atividadesFisicas[indiceCategoria]);            
    printf("%d - Voltar\n", numeroCategorias + 1);
    printf("Entre com a opção: ");  
}

int validaEntradaNumerica(int opcao, int returnOpcao, int menu) {
    
    // Verifica se apenas um valor inteiro foi digitado
    if (returnOpcao != 1) {
        printf("\nValor inválido!\n");
        return 0; // Entrada inválida
    }

    // Verifica se a opção digitada esta disponível no menu
    switch(menu) {        
        case 1:
            // Item do menu 1
            // "Visualizar as atividades físicas"
            if (opcao < 1 || opcao > 9) {
                printf("\nOpção inválida!\n");
                return 0; // Opção inválida
            }
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            // Item do menu 11 ao 18
            // "Visualizar atividades físicas por dia"
            if (opcao != 1) {
                printf("\nOpção inválida!\n");
                return 0; // Opção inválida
            }
            break;
        case 2:
            // Item do menu 2
            // Sub-menu -> Registrar uma atividade física
            if (opcao < 1 || opcao > 8) {
                printf("\nOpção inválida!\n");
                return 0; // Opção inválida
            }
            break;        
        default:
            // Menu principal (opcao = 0)
            if (opcao < 1 || opcao > 3) {
                printf("\nOpção inválida!\n");
                return 0; // Opção inválida
            }
            break;
    }

    return 1; // Entrada numérica Ok
}

void mensagemEncerramento() {

}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%

// Exercícios Cardiorrespiratórios

// Corrida / Trote

// Caminhada

// Ciclismo

// Pular corda

// Natação

// Escalada indoor / step

// 2️⃣ Exercícios de Força / Musculação

// Flexões (Push-ups)

// Agachamentos (Squats)

// Afundos (Lunges)

// Levantamento terra (Deadlift)

// Supino (Bench press)

// Remada (Row)

// Prancha (Plank) – para core

// 3️⃣ Exercícios de Flexibilidade / Alongamento

// Alongamento de pernas

// Alongamento de braços e ombros

// Yoga básico

// Pilates

// 4️⃣ Exercícios Funcionais / HIIT

// Burpees

// Mountain climbers

// Jump squats

// Kettlebell swings (se houver equipamento)

// Exercícios com TRX (suspensão)

// 5️⃣ Atividades de Equilíbrio / Core

// Prancha lateral

// Ponte (Glute bridge)

// Abdominais (Crunches, Bicycle crunch)

// Exercícios com bola suíça


// printf( %d - %d - %d - %d - %d", numeroCategorias, sizeof(atividadesFisicas[0]), sizeof(atividadesFisicas[0][0]), sizeof(atividadesFisicas[0][0][0]), sizeof(atividadesFisicas[0][0][0][0]));            
