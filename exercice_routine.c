#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isspace()
#include <Windows.h> // SetConsoleOutputCP()

// Número de categorias cadastradas
const int MAX_CATEGORIA = 10;    
const int MAX_ATIVIADE_FISICA = 10;
const int MAX_CARACTERES = 30;

void apresentacaoSistema();
void menuPrincipal();
void menuVisualizarAtividadesFisicas(char diasDaSemana[7][15]);
void menuVisualizarAtividadesFisicasDia(int diaSelecionado, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroCategorias);
void menuRegistrarAtividadeFisica(char diasDaSemana[7][15]);
void menuRegistrarAtividadeFisicaDia(int diaSelecionado, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroCategorias);
void menuRegistrarAtividadeFisicaDiaCategoria(int diaSelecionado, int categoriaSelecionada, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroAtividadesFisicas);
void menuRegistrarAtividadeFisicaDiaNovaCategoria(int diaSelecionado, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroCategorias);
void menuRegistrarAtividadeFisicaDiaNovaAtividadeFisica(int diaSelecionado, int categoriaSelecionada, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroCategorias);
int validaEntradaNumerica(int opcao, int opcaoMinMax[2], int returnOpcao);
int validaEntradaCaracters(char *caracteres, char *returnNovoCaracteres);
void mensagemEncerramento();
void trim(char *s);

int main() {

    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Definindo as variáveis de manipulação dos menus
    int menu = 0, returnMenu = 0;
    int sairMenu = 0;

    // Definindo as variáveis de manipulação das opções do menu    
    int opcao = 0, returnOpcao = 0;
    // Faixa de opções do menu
    int opcaoMinMax[2] = {0,0};

    // Categoria digitada pelo usuário
    char novaCategoria[50] = {""};
    // Array para armazenar o retorno da função fgets() [Erro -> NULL | Success -> aponta para a variável utilizada como buffer]
    char *returnNovaCategoria;
    
    // Nova atividade física digitada pelo usuário
    char novaAtividadeFisica[50] = {""};
    // Array para armazenar o retorno da função fgets() [Erro -> NULL | Success -> aponta para a variável utilizada como buffer]
    char *returnNovaAtividadeFisica;



    // Opções elecionadas pelo usuário
    // Domingo a Sabado - 1 a 7 / Todos os dias - 8
    int diaSelecionado = 0;
    // Categoria Selecionada
    int categoriaSelecionada = 0;
    // Atividade Selecionada
    int atividade = 0;

    // Declarando os dias da semana
    char diasDaSemana[7][15] = {
        "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira",
        "Quinta-Feira", "Sexta-Feira", "Sábado"
    };    

    // Declarando as atividades físicas
    // até 10 categorias 
    // até 10 subcategorias
    // max 20 caracteres por item
    int numeroCategorias = MAX_CATEGORIA;
    int numeroAtividadesFisicas = MAX_ATIVIADE_FISICA;
    // {"Categoria",
    //  "Atividade1", "Atividade2", "Atividade3", "Atividade4", "Atividade5", "Atividade6", "Atividade7", "Atividade8", "Atividade9", "Atividade10"
    // }
    char atividadesFisicas[10][11][50] =  {
        {
            "Cardiorespiratórios",
            "Corrida / Trote", "Caminhada", "Ciclismo", "Pular corda", "Natação", "Escalada indoor / step", "", "", "", ""
        },
        {
            "Força / Musculação",
            "Flexões (Push-ups)", "Agachamentos (Squats)", "Afundos (Lunges)", "Levantamento terra (Deadlift)", "Supino (Bench press)", "Remada (Row)", "Prancha (Plank) - para core", "", "", ""
        },
        {
            "Exercícios de Flexibilidade / Alongamento",
            "Alongamento de pernas", "Alongamento de braços e ombros", "Yoga básico", "Pilates", "", "", "", "", "", ""
        },       
        {
            "Exercícios Funcionais / HIIT",
            "Burpees", "Mountain climbers", "Jump squats", "Kettlebell swings (se houver equipamento)", "Exercícios com TRX (suspensão)", "", "", "", "", ""
        },    
        {
            "Atividades de Equilíbrio / Core",
            "Prancha lateral", "Ponte (Glute bridge)", "Abdominais (Crunches, Bicycle crunch)", "Exercícios com bola suíça", "", "", "", "", "", ""
        },    
        {"", "", "", "", "", "", "", "", "", "", ""},    
        {"", "", "", "", "", "", "", "", "", "", ""},    
        {"", "", "", "", "", "", "", "", "", "", ""},    
        {"", "", "", "", "", "", "", "", "", "", ""},    
        {"", "", "", "", "", "", "", "", "", "", ""}
    };

    // Mensagem inicial
    apresentacaoSistema();

    // Menu 0 - Menu principal
    menu = 0;
    sairMenu = 0;

    // Loop dos menus
    do {
        if (menu == 0) {
            // Menu 0 - Menu principal - "Menu de opçoes" 
            // Loop que garante uma entrada numérica válida
            do {        
                // Menu principal -> "Menu de opções" 
                menuPrincipal();

                // Opcao selecionada pelo usuario
                printf("Digite a opção desejada: ");
                returnOpcao = scanf("%d", &opcao);

                // Opções do menu
                opcaoMinMax[0] = 1;
                opcaoMinMax[1] = 3;            
                
                // Limpando o buffer de entrada!!!!
                while(getchar() != '\n');

            // Valida a entrada numerica antes de prosseguir
            } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao));  
            
            // Analisa a opção selecionada
            switch(opcao) {
                    case 1:
                    case 2:
                        menu = opcao;
                        break;

                    case 3:
                    default:
                        sairMenu = 1;
                        break;
                }
        
        } else if ( menu == 1) {
            // Menu 1 - "Visualizar as atividades físicas"
            // Loop que garante uma entrada numérica válida
            do {                                
                // Menu "Visualizar as atividades físicas"
                // O usuário deve escolher um dia da semana
                menuVisualizarAtividadesFisicas(diasDaSemana);

                // Opcao selecionada pelo usuario
                printf("Entre com a opção: ");
                returnOpcao = scanf("%d", &opcao);

                // Opções do menu
                opcaoMinMax[0] = 1;
                opcaoMinMax[1] = 9;

                // Limpando o buffer de entrada!!!!
                while(getchar() != '\n');

            // Valida a entrada numerica antes de prosseguir
            } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao));                

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
                    diaSelecionado = opcao;
                    // Primeiro dígito (1) - "Visualizar as atividades físicas"
                    // Segundo dígito (opcao) - Identifica o dia da semana ou todos os dias
                    menu = opcao + 10;
                    break;
                default:
                    // Opcao 9 - Voltar
                    // Volta para o menu principal
                    menu = 0;
                    break;
            }
                    
        } else if (menu >= 11 & menu <= 18) {
            // Menu 11 a 18 - "Visualizar as atividades físicas por dia"
            // Mostra na tela as atividades físicas para o/os dias selecionados
            // Primeiro dígito [1] - Visualizar as atividades físicas
            // Segundo dígito [opcao] - Identifica o dia da semana [1-7] ou todos os dias [8]             
            // Loop que garante uma entrada numérica válida
            do {                                
                // Menu "Vizualizar atividades físicas por dia"                            
                menuVisualizarAtividadesFisicasDia(diaSelecionado, diasDaSemana, atividadesFisicas, numeroCategorias);

                // Opcao selecionada pelo usuario
                printf("Entre com a opção: ");    
                returnOpcao = scanf("%d", &opcao);

                // Opções do menu
                opcaoMinMax[0] = 1;
                opcaoMinMax[1] = 1;                            

                // Limpando o buffer de entrada!!!!
                while(getchar() != '\n');

            // Valida a entrada numerica antes de prosseguir
            } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao)); 

            // Verifica a opção escolhida
            if (opcao == 1) {
                    // volta para o menu alterior
                    menu = 1;
                }           
       
        } else if (menu == 2) {
            // Selecionar o dia da semana

            // Menu 2 - "Registrar uma atividade física"
            // Loop que garante uma entrada numérica válida
            do {        
                // Menu "Registrar uma atividade física"
                menuRegistrarAtividadeFisica(diasDaSemana);

                // Opcao selecionada pelo usuario
                printf("Entre com a opção: ");  
                returnOpcao = scanf("%d", &opcao);

                // Opções do menu
                opcaoMinMax[0] = 1;
                opcaoMinMax[1] = 8;                            

                // Limpando o buffer de entrada!!!!
                while(getchar() != '\n');

            // Valida a entrada numerica antes de prosseguir
            } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao));    

            // Verifica qual opção foi escolhida (dia da semana)
            switch(opcao) {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        // Domingo a Sabado - 1 a 7
                        diaSelecionado = opcao;
                        // Primeiro dígito (2) - "Registrar uma atividade física"
                        // Segundo dígito (opcao) - Identifica o dia da semana
                        menu = opcao + 20;       
                        // Atualiza o número de categorias
                        for (numeroCategorias = 0; numeroCategorias < MAX_CATEGORIA; numeroCategorias++) {
                            if(strlen((char*) atividadesFisicas[numeroCategorias][0]) == 0)
                                break;
                        }        
                        break;
                    default:
                        // Opcao 8 - Voltar
                        // Volta para o menu principal
                        menu = 0;
                        break;
                }
        
        } else if ( menu >= 21 && menu <= 27) {        
            // Selecionar uma categoria

            // Menu 21 a 27 - "Registar uma atividade física"
            // Primeiro dígito [2] - Visualizar as atividades físicas
            // Segundo dígito [opcao] - Identifica o diaSelecionado da semana [1-7]            
            // Loop que garante uma entrada numérica válida
            do {
                // Menu "Registrar atividades físicas por dia"                            
                menuRegistrarAtividadeFisicaDia(diaSelecionado, diasDaSemana, atividadesFisicas, numeroCategorias);

                printf("Entre com a opção: ");  
                // Opcao selecionada pelo usuario
                returnOpcao = scanf("%d", &opcao);

                // Opções do menu
                opcaoMinMax[0] = 1;
                // Verifica quantas categrias estão cadastradas
                if (numeroCategorias < MAX_CATEGORIA) {
                    // Número de categorias + opção adicionar categoria + opção voltar
                    opcaoMinMax[1] = numeroCategorias + 2; 
                } else {
                    // Número de categorias + opção voltar
                    opcaoMinMax[1] = numeroCategorias + 1; 
                }

                // Limpando o buffer de entrada!!!!
                while(getchar() != '\n');

            } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao));

            // Verifica a opção escolhida
            if (((opcao == numeroCategorias + 1) && (numeroCategorias == MAX_CATEGORIA)) || 
                ((opcao == numeroCategorias + 2) && (numeroCategorias < MAX_CATEGORIA))) {
                // Voltar para o menu alterior                
                menu = 2;
            // } else if (opcao == numeroCategorias + 1) {        
            //     // Adicionar categoria                     
            } else {
                // Primeiro e segundo dígitos [22] - "Registrar uma atividade física"
                // Terceiro dígito [opcao] - Identifica a categoria
                categoriaSelecionada = opcao;                
                menu = categoriaSelecionada + 220;
   
                // Atualiza o número de atividades físicas
                for (numeroAtividadesFisicas = 0; numeroAtividadesFisicas < MAX_ATIVIADE_FISICA; numeroAtividadesFisicas++) {
                    if(strlen((char*) atividadesFisicas[categoriaSelecionada - 1][numeroAtividadesFisicas + 1]) == 0)
                        break;
                }     
            }

        } else if (menu >= 221 && menu <= 220 + numeroCategorias) {
            // Selecionar uma atividade física

            // Menu 221 a [220 + numeroCategorias] - "Registar uma atividade física"
            // Primeiro e segundo dígitos [22] - "Registrar uma atividade física"
            // Terceiro dígito [opcao] - Identifica a categoria            
            // Loop que garante uma entrada numérica válida
            do {
                // Menu "Registrar atividades físicas por dia"                            
                menuRegistrarAtividadeFisicaDiaCategoria(diaSelecionado, categoriaSelecionada, diasDaSemana, atividadesFisicas, numeroAtividadesFisicas);
                
                printf("Entre com a opção: ");  
                // Opcao selecionada pelo usuario
                returnOpcao = scanf("%d", &opcao);

                // Opções do menu
                opcaoMinMax[0] = 1;

                // Verifica quantas atividades físicas estão cadastradas
                if (numeroAtividadesFisicas < MAX_ATIVIADE_FISICA) {
                    // Número de atividades físicas + opção adicionar atividade física + opção voltar
                    opcaoMinMax[1] = numeroAtividadesFisicas + 2; 
                } else {
                    // Número de categorias + opção voltar
                    opcaoMinMax[1] = numeroAtividadesFisicas + 1; 
                }                

                // Limpando o buffer de entrada!!!!
                while(getchar() != '\n');

            } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao));

            // Verifica a opção escolhida
            if (((opcao == numeroAtividadesFisicas + 1) && (numeroAtividadesFisicas == MAX_ATIVIADE_FISICA)) || 
                ((opcao == numeroAtividadesFisicas + 2) && (numeroAtividadesFisicas < MAX_ATIVIADE_FISICA))) {
                // volta para o menu alterior
                menu = 20 + diaSelecionado;
            //  } else if (opcao == numeroAtividadesFisicas + 1) {
            //      // Adicionar uma nova atividade física                
            } else {
                // Primeiro, segundo e terceiro dígito (222) - "Registrar uma atividade física"
                // Quarto dígito (opcao) - Identifica a categoria
                atividade = opcao;                
                menu = atividade + 2220;
                
            }
        } else if (menu == 220 + numeroCategorias + 1) {
            // Adicionar uma nova categoria

            // Menu [220 + numeroCategorias + 1] - "Registar uma atividade física"
            // Primeiro e segundo dígitos [22] - Visualizar as atividades físicas
            // Terceiro dígito [numeroCategorias + 1] - Adicionar uma nova categoria           
            // Loop que garante uma entrada numérica válida
            do {
                // Menu "Registrar atividades físicas por dia"  
                // Adicionar uma nova categoria                          
                menuRegistrarAtividadeFisicaDiaNovaCategoria(diaSelecionado, diasDaSemana, atividadesFisicas, numeroCategorias);

                printf("Digite uma nova categoria: ");  
                // Nova categoria digitada pelo usuário
                // A função fgets foi utilizada para obter strings com espaços.
                returnNovaCategoria = fgets(novaCategoria, 50, stdin);

                // Eliminando '\n' da string
                novaCategoria[strcspn(novaCategoria, "\n")] = 0;


            } while (!validaEntradaCaracters(novaCategoria, returnNovaCategoria));   

            if (strlen(novaCategoria) > 0) {
                // Adicina a nova categoria ao array de atividadesFisicas
                //numeroCategorias = categoria;
                numeroCategorias++;
                strcpy(atividadesFisicas[numeroCategorias-1][0], novaCategoria);
            }
            // Retorna ao menu anterior
             menu = 20 + diaSelecionado;                    

        } else if (menu >= 2221 && menu <= 2220 + numeroAtividadesFisicas) {
            // Selecionar uma atividade física

            // Atualiza o menu                
            menu = categoriaSelecionada + 220;

        } else if (menu == 2220 + numeroAtividadesFisicas + 1) {
            // "Registar uma atividade física" -> "Selecionar uma categoria" -> "Adicionar uma nova atividade física"

            // Menu [2220 + numeroAtividadeFisica + 1]
            // Primeiro, segundo e tercier dígitos [222] - Visualizar as atividades físicas
            // Quarto dígito [numeroCategorias + 1] - Adicionar uma nova categoria           
            // Loop que garante uma entrada de caracteres válida
            do {
                // Menu "Registar uma atividade física" -> "Selecionar uma categoria" -> "Adicionar uma nova atividade física"  
                // Adicionar uma nova atividade física                          
                menuRegistrarAtividadeFisicaDiaNovaAtividadeFisica(diaSelecionado, categoriaSelecionada, diasDaSemana, atividadesFisicas, numeroCategorias);

                printf("Digite uma nova atividade física: ");  
                // Nova atividade física digitada pelo usuário
                // A função fgets foi utilizada para obter strings com espaços.
                returnNovaAtividadeFisica = fgets(novaAtividadeFisica, 50, stdin);

                // Eliminando '\n' da string
                novaAtividadeFisica[strcspn(novaAtividadeFisica, "\n")] = 0;

            } while (!validaEntradaCaracters(novaAtividadeFisica, returnNovaAtividadeFisica));   

            if (strlen(novaAtividadeFisica) > 0) {
                // Adiciona a nova atividade fisica ao array de atividadesFisicas
                
                numeroAtividadesFisicas++;
                strcpy(atividadesFisicas[categoriaSelecionada-1][numeroAtividadesFisicas], novaAtividadeFisica);                
            }
            // Retorna ao menu anterior
             menu = 220 + categoriaSelecionada;          

        } else {
            // Menu principal
            menu = 0;
        } 


        // Sair - sairMenu igual a 1 encerra o sistema! 
    } while (!sairMenu);

    return 0;
}

// int main2() {
//     SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

//     // Definindo as variáveis de manipulação dos menus
//     int menu = 0, returnMenu = 0;

//     // Definindo as variáveis de manipulação das opções do menu    
//     int opcao = 0, returnOpcao = 0;
//     // Faixa de opções do menu
//     int opcaoMinMax[] = {0,0};

//     // Domingo a Sabado - 1 a 7 / Todos os dias - 8
//     int dia = 0;

//     // Declarando os dias da semana
//     char diasDaSemana[][15] = {
//         "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira",
//         "Quinta-Feira", "Sexta-Feira", "Sábado"
//     };    

//     // Declarando as atividades físicas
//     // até 10 categorias 
//     // até 10 subcategorias
//     // max 20 caracteres por item
//     char atividadesFisicas[2][11][30] =  {
//         {
//             "Cardiorespiratórios",
//             "Corrida / Trote",
//             "Caminhada",
//             "Ciclismo",
//             "Pular corda",
//             "Natação",
//             "Escalada indoor / step",
//             "", "", "", ""
//         },
//         {
//             "Força / Musculação",
//             "Flexões (Push-ups)",
//             "Agachamentos (Squats)",
//             "Afundos (Lunges)",
//             "Levantamento terra (Deadlift)",
//             "Supino (Bench press)",
//             "Remada (Row)",
//             "Prancha (Plank) – para core",
//             "", "", ""
//         }
//     };

//     int numAtividades = sizeof(atividadesFisicas);
//     // Número de categorias cadastradas
//     int numeroCategorias = sizeof(atividadesFisicas[0]) / sizeof(atividadesFisicas[0][0]);    

//     // Mensagem inicial
//     apresentacaoSistema();

//     // Loop principal do sistema
//     // Verifica a variável opcao no final do loop while
//     do {
        
//         // Menu 0 - Menu principal - "Menu de opçoes"   
//         // Loop que garante uma entrada numérica válida
//         do {        
//             // Menu principal -> "Menu de opções" 
//             menuPrincipal();

//             // Opcao selecionada pelo usuario
//             returnOpcao = scanf("%d", &opcao);

//             // Opções do menu
//             opcaoMinMax[0] = 1;
//             opcaoMinMax[1] = 3;            
            
//             // Limpando o buffer de entrada!!!!
//             while(getchar() != '\n');

//         // Valida a entrada numerica antes de prosseguir
//         } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao, menu));
        
//         // Verifica qual opção do menu principal foi escolhida
//         switch (opcao) {

//             // Opção 1 - "Visualizar as atividades físicas"
//             case 1:

//                 // Loop para retorno ao Menu 1
//                 do {
//                     // Menu 1 - "Visualizar as atividades físicas"
//                     // Loop que garante uma entrada numérica válida
//                     do {                                
//                         // Menu "Visualizar as atividades físicas"
//                         // O usuário deve escolher um dia da semana
//                         menu = 1;
//                         menuVisualizarAtividadesFisicas(diasDaSemana);

//                         // Opcao selecionada pelo usuario
//                         returnOpcao = scanf("%d", &opcao);

//                         // Opções do menu
//                         opcaoMinMax[0] = 1;
//                         opcaoMinMax[1] = 9;

//                         // Limpando o buffer de entrada!!!!
//                         while(getchar() != '\n');

//                     // Valida a entrada numerica antes de prosseguir
//                     } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao, menu));                

//                     // Verifica qual opção do menu (dia da semana) foi escolhida
//                     switch(opcao) {
//                         case 1:                        
//                         case 2:
//                         case 3:
//                         case 4:
//                         case 5:
//                         case 6:
//                         case 7:
//                         case 8:
//                             // Domingo a Sabado - 1 a 7 / Todos os dias - 8
//                             dia = opcao;
//                             // Primeiro dígito (1) - "Visualizar as atividades físicas"
//                             // Segundo dígito (opcao) - Identifica o dia da semana ou todos os dias
//                             menu = opcao + 10;
//                             break;
//                         default:
//                             // Opcao 9 - Voltar
//                             // Volta para o menu principal
//                             menu = 0;
//                             break;
//                     }

//                     // Menu 11 a 18 - "Visualizar as atividades físicas por dia"
//                     if (menu >= 11 && menu <= 18) {
//                         // Menu 11 a 18 - "Visualizar as atividades físicas por dia"
//                         // Mostra na tela as atividades físicas para o/os dias selecionados                    
//                         // Primeiro dígito [1] - Visualizar as atividades físicas
//                         // Segundo dígito [opcao] - Identifica o dia da semana [1-7] ou todos os dias [8]

//                         // Loop que garante uma entrada numérica válida
//                         do {                                
//                             // Menu "Vizualizar atividades físicas por dia"                            
//                             menuVisualizarAtividadesFisicasDia(dia, diasDaSemana, atividadesFisicas, numeroCategorias);

//                             // Opcao selecionada pelo usuario
//                             returnOpcao = scanf("%d", &opcao);

//                             // Opções do menu
//                             opcaoMinMax[0] = 1;
//                             opcaoMinMax[1] = 1;                            

//                             // Limpando o buffer de entrada!!!!
//                             while(getchar() != '\n');

//                         // Valida a entrada numerica antes de prosseguir
//                         } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao, menu)); 

//                         // Verifica a opção escolhida
//                         if (opcao == 1) {
//                             // volta para o menu alterior
//                             menu = 1;
//                         }
//                     }
                                        
//                 // Fica no loop ate a opção voltar ser escolhida (menu = 0).
//                 } while (menu == 1);

//                 break;

//             // 2 - Registrar uma atividade física
//             case 2:

//                 // Loop para retorno ao menu 2
//                 do {
//                     // menu 2 - "Registrar uma atividade física"
//                     // Loop que garante uma entrada numérica válida
//                     do {        
//                         // Menu "Registrar uma atividade física"                            
//                         menu = 2;
//                         menuRegistrarAtividadeFisica(diasDaSemana);

//                         // Opcao selecionada pelo usuario
//                         returnOpcao = scanf("%d", &opcao);

//                         // Opções do menu
//                         opcaoMinMax[0] = 1;
//                         opcaoMinMax[1] = 8;                            

//                         // Limpando o buffer de entrada!!!!
//                         while(getchar() != '\n');

//                     // Valida a entrada numerica antes de prosseguir
//                     } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao, menu));    

//                     // Verifica qual opção foi escolhida (dia da semana)
//                     switch(opcao) {
//                         case 1:
//                         case 2:
//                         case 3:
//                         case 4:
//                         case 5:
//                         case 6:
//                         case 7:
//                             // Domingo a Sabado - 1 a 7
//                             dia = opcao;
//                             // Primeiro dígito (2) - "Registrar uma atividade física"
//                             // Segundo dígito (opcao) - Identifica o dia da semana
//                             menu = opcao + 20;                    
//                             break;
//                         default:
//                             // Opcao 8 - Voltar
//                             // Volta para o menu principal
//                             menu = 0;
//                             break;
//                     }

//                     // Menu 21 a 27- "Registar as atividades físicas por dia"
//                     // Selecionar o dia da semana
//                     if (menu >= 21 && menu <= 27) {

//                         // Menu 21 a 27- "Registar as atividades físicas"
//                         // Selecionar um dia da semana para adicinar uma atividade física     
//                         // Primeiro dígito [2] - Visualizar as atividades físicas
//                         // Segundo dígito [opcao] - Identifica o dia da semana [1-7]
//                         do {
//                             // Menu "Registrar atividades físicas por dia"                            
//                             menuRegistrarAtividadeFisicaDia(dia, diasDaSemana, atividadesFisicas, numeroCategorias);

//                             // Opcao selecionada pelo usuario
//                             returnOpcao = scanf("%d", &opcao);

//                             // Opções do menu
//                             opcaoMinMax[0] = 1;
//                             opcaoMinMax[1] = numeroCategorias + 1;

//                             // Limpando o buffer de entrada!!!!
//                             while(getchar() != '\n');

//                         } while (!validaEntradaNumerica(opcao, opcaoMinMax, returnOpcao, menu));

//                         // Verifica a opção escolhida
//                         if (opcao == numeroCategorias + 1) {
//                             // volta para o menu alterior
//                             menu = 2;
//                         } 
//                         // else {

//                         //     do {

//                         //     } while (1);
//                         // }                      
//                     } 

//                     // Ficar no loop até a opção volter ser escolhida (faz menu = 2).

//                 // Fica no loop até a opção voltar ser escolhida (faz menu = 0).
//                 } while (menu == 2);                

//                 break;
            
//             default:
//                 // Foi digitado a opção de sair (opcao igual a 3)
//                 // Define opcao igual a 0 para sair do loop while.
//                 opcao = 0;            
//                 break;
//         }
    
//     // Sair - Opção igual a 0 encerra o sistema! 
//     } while (opcao > 0);

//     return 0;
// }

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
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf(">> Menu de opções:\n");
    printf("1 - Visualizar as atividades físicas\n");
    printf("2 - Registrar uma atividade física\n");            
    printf("3 - Sair\n");    
}

void menuVisualizarAtividadesFisicas(char diasDaSemana[7][15]) {
    // Menu 1 - Opção 1 do menu principal
    // Vizualizar as atividades físicas
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Visualizar as Atividades Físicas ===\n");    
    printf(">> Visualizar as atividades físicas de qual(quais) dia(s)?\n");
    // Imprime os dias da semana
    for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
        printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
    printf("8 - Semana inteira\n");
    printf("9 - Voltar\n");    
}

void menuVisualizarAtividadesFisicasDia(int diaSelecionado, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroCategorias) {
    // Menu  11 ao 18 - Vizualizar as atividades físicas por dia 
    // Opção 1 a 7 - [Domingo ao Sábado]
    // ou
    // Opção 8 - [Semana inteira]
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Visualizar as Atividades Físicas ===\n");
    // Imprime as atividades físicas               
    if (diaSelecionado == 8) {
        for (int indexDia = 0; indexDia <= 6; indexDia++) {
            if (indexDia > 0 && indexDia < 6)
                printf(">> Atividades físicas da %s:\n", diasDaSemana[indexDia]);
            else
                printf(">> Atividades físicas do %s:\n", diasDaSemana[indexDia]);
        }
        
    } else {
        if (diaSelecionado > 1 && diaSelecionado < 7)
            printf(">> Atividades físicas da %s:\n", diasDaSemana[diaSelecionado-1]);
        else
            printf(">> Atividades físicas do %s:\n", diasDaSemana[diaSelecionado-1]);
    }
    // Imprime as atividades físicas               
    printf("1 - Voltar\n");
}

void menuRegistrarAtividadeFisica(char diasDaSemana[7][15]) {
    // Menu 2 - Opção 2 do menu menu principal
    // Registrar um atividade física
    // Mostra os dias da semana
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Registrar uma atividade física ===\n");
    printf(">> Escolha um dia:\n");
    // Imprime os dias da semana
    for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
        printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
    printf("8 - Voltar\n");
}

void menuRegistrarAtividadeFisicaDia(int diaSelecionado, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroCategorias) {
    // Registrar uma atividade física (Menu 21 a 27)
    // Mostra o dia selecionado
    // Mostra as categorias cadastradas
    // Mostra a opção de adicionar categoria
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Registrar uma atividade física ===\n");
    // Imprime o dia da semana selecionado
    printf(">> Dia selecionado: %s.\n", diasDaSemana[diaSelecionado-1]);
    printf(">> Selecione uma categoria:\n");
    // Imprime as categorias de atividade física
    for (int indiceCategoria = 0;
            indiceCategoria < numeroCategorias;
            indiceCategoria++)
        printf("%d - %s\n", indiceCategoria + 1, atividadesFisicas[indiceCategoria][0]);          
    // Imprime a opção de adicionar categoria
    if (numeroCategorias < MAX_CATEGORIA)
        printf("%d - Adicionar uma categoria\n", numeroCategorias + 1 );
    // Imprime a opção voltar
    printf("%d - Voltar\n", (numeroCategorias < MAX_CATEGORIA ) ? numeroCategorias + 2 : numeroCategorias + 1);
}

void menuRegistrarAtividadeFisicaDiaCategoria(int diaSelecionado, int categoriaSelecionada, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroAtividadesFisicas) {
    // Registrar uma atividade física (menu = 2)
    // Opção 1 - Segunda-Feira
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Registrar uma atividade física ===\n");
    // Imprime o dia da semana selecionado
    printf(">> Dia selecionado: %s.\n", diasDaSemana[diaSelecionado-1]);
    // Imprime a categoria selecionada
    printf(">> Categoria selecionada: %s.\n", atividadesFisicas[categoriaSelecionada - 1][0]);
    // Imprime as atividades físicas
    for (int indiceAtividadeFisica = 1;
            indiceAtividadeFisica <= numeroAtividadesFisicas;
            indiceAtividadeFisica++)
        printf("%d - %s\n", indiceAtividadeFisica, atividadesFisicas[categoriaSelecionada - 1][indiceAtividadeFisica]); 
    // Imprime a opção de adicionar atividade física
    if (numeroAtividadesFisicas < MAX_ATIVIADE_FISICA)          
        printf("%d - Adicionar uma atividade física\n", numeroAtividadesFisicas + 1);        
    printf("%d - Voltar\n", (numeroAtividadesFisicas < MAX_ATIVIADE_FISICA)? numeroAtividadesFisicas + 2 : numeroAtividadesFisicas + 1);
}

void menuRegistrarAtividadeFisicaDiaNovaCategoria(int diaSelecionado, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroAtividadesFisicas) {
    // Registrar uma atividade física (menu = 2)
    // Opção 1 - Segunda-Feira
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Registrar uma atividade física ===\n");
    // Imprime o dia da semana selecionado
    printf(">> Dia selecionado: %s.\n", diasDaSemana[diaSelecionado - 1]);
    // Imprime a mensagem nova categoria
    printf(">> Nova categoria.\n");
}

void menuRegistrarAtividadeFisicaDiaNovaAtividadeFisica(int diaSelecionado, int categoriaSelecionada, char diasDaSemana[7][15], char atividadesFisicas[10][11][50], int numeroAtividadesFisicas) {
    // Registrar uma atividade física (menu = 2)
    // Opção 1 - Segunda-Feira
    printf("\n#### Registro de Atividades Físicas ####\n");
    printf("=== Registrar uma atividade física ===\n");
    // Imprime o dia da semana selecionado
    printf(">> Dia selecionado: %s.\n", diasDaSemana[diaSelecionado-1]);
    // Imprime a categoria selecionada
    printf(">> Categoria selecionada: %s.\n", atividadesFisicas[categoriaSelecionada - 1][0]);
    // Imprime a mensagem nova atividade física
    printf(">> Nova atividade física.\n");
}

int validaEntradaNumerica(int opcao, int opcaoMinMax[2], int returnOpcao) {
    
    // Verifica se apenas um valor inteiro foi digitado
    if (returnOpcao != 1) {
        printf("\nValor inválido!\n");
        return 0; // Entrada inválida
    }

    // Verifica se a opção digitada esta disponível no menu
    if (opcao < opcaoMinMax[0] || opcao > opcaoMinMax[1]) {
        printf("\nOpção inválida!\n");
        return 0; // Opção inválida
    }                

    return 1; // Entrada numérica Ok
}

int validaEntradaCaracters(char *caracteres, char *returnNovoCaracteres) {
 
    // Verifica se apenas um valor de caracteres foi digitado
    if (!(strlen(returnNovoCaracteres) > 0)) {
        printf("\nValor inválido!\n");
        return 0; // Entrada inválida
    }             

    return 1; // Entrada caracteres Ok    

}

void mensagemEncerramento() {

}

// Remove espaços em branco do inicio da string
void trim(char *s) {
    int i = 0;
    // Find the first non-whitespace character
    while (isspace((unsigned char)s[i])) {
        i++;
    }
    // Shift the remaining characters to the beginning of the string
    if (i > 0) {
        int j = 0;
        while ((s[j++] = s[i++]) != '\0');
    }
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%

// Como verificar o tamanho de arrays
// printf( %d - %d - %d - %d - %d", numeroCategorias, sizeof(atividadesFisicas[0]), sizeof(atividadesFisicas[0][0]), sizeof(atividadesFisicas[0][0][0]), sizeof(atividadesFisicas[0][0][0][0]));            
