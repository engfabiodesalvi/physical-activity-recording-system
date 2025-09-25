#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()


void apresentacaoSistema();
void menuPrincipal();
void menuVisualizarAtividadesFisicas(char diasDaSemana[][15]);
void menuRegistroAtividadeFisica(char diasDaSemana[][15]);
void listaMenus(int menu, char diasDaSemana[][15], char atividadesFisicas[][2][11][25]);
int validaEntradaNumerica(int opcao, int returnOpcao, int menu);
void mensagemEncerramento();

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Definindo as variáveis de manipulação dos menus
    int menu = 0, returnMenu = 0;

    // Definindo as variáveis de manipulação das opções do menu    
    int opcao = 0, returnOpcao = 0;

    // Declarando os dias da semana
    char diasDaSemana[][15] = {
        "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira",
        "Quinta-Feira", "Sexta-Feira", "Sábado"
    };    

    // Declarando as atividades físicas
    // até 10 categorias 
    // até 10 subcategorias
    // max 20 caracteres por item
    char atividadesFisicas[][2][11][25] =  {
        {
            "Cardiorespiratórios",
            "Corrida / Trote",
            "Caminhada",
            "Ciclismo",
            "Pular corda",
            "Natação",
            "Escalada indoor / step",
            "a", "a", "a", "a"
        },
        {
            "Cardiorespiratórios",
            "Corrida / Trote",
            "Caminhada",
            "Ciclismo",
            "Pular corda",
            "Natação",
            "Escalada indoor / step",
            "a", "a", "a", "a"
        }        
    };

    int numAtividades = sizeof(atividadesFisicas);

    // Mensagem inicial
    apresentacaoSistema();

    // Loop principal do sistema
    // Verifica a variável opcao no final do loop while
    do {

        // Inicia o sistema com o menu 0     

        // Loop que garante uma entrada numérica válida
        do {        
            // Menu principal de opções
            menuPrincipal();

            // Opcao selecionada pelo usuario
            returnOpcao = scanf("%d", &opcao);

            // IMPORTANTE!!!!!!!!!
            // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
            while(getchar() != '\n');

        // Valida a entrada numerica antes de prosseguir
        } while (!validaEntradaNumerica(opcao, returnOpcao, menu));

        // Verifica qual opção do menu principal foi escolhida
        switch (opcao) {

            // 1 - Visualizar as atividades físicas
            case 1:

                // Loop principal do menu
                do {

                    // Loop que garante uma entrada numérica válida
                    do {        
                        // Submenu da opção 1 do menu principal
                        // Visualizar as atividades físicas
                        menu = 1;
                        menuVisualizazAtividadesFisicas(diasDaSemana);

                        // Opcao selecionada pelo usuario
                        returnOpcao = scanf("%d", &opcao);

                        // IMPORTANTE!!!!!!!!!
                        // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
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
                        case 8:
                            menu = opcao + 10;
                            break;
                        default:
                            // Opcao 9 - Voltar
                            // Volta para o menu principal
                            menu = 0;
                            break;
                    }

                    // Loop que garante uma entrada numérica válida
                    do {        
                        // Submenu das opções do menu Visualizar as atividades físicas                        

                        listaMenus(menu, diasDaSemana, atividadesFisicas);

                        // Opcao selecionada pelo usuario
                        returnOpcao = scanf("%d", &opcao);

                        // IMPORTANTE!!!!!!!!!
                        // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
                        while(getchar() != '\n');

                        printf("Entre com a opção: %d", sizeof(atividadesFisicas));

                    // Valida a entrada numerica antes de prosseguir
                    } while (!validaEntradaNumerica(opcao, returnOpcao, menu));                         

                // Fica no loop ate a opção voltar ser escolhida (menu = 0).
                } while (menu != 0);

                break;

            // 2 - Registrar uma atividade física
            case 2:

                // Loop principal do sub menu
                do {

                    // Loop que garante uma entrada numérica válida
                    do {        
                        // Submenu da opção 2 do menu principal                            
                        menu = 2;
                        menuRegistroAtividadeFisica(diasDaSemana);

                        // Opcao selecionada pelo usuario
                        returnOpcao = scanf("%d", &opcao);

                        // IMPORTANTE!!!!!!!!!
                        // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
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
                } while (menu != 0);
                
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
    // Padrão (menu == 0)
    // Menu inicial    
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Menu de opções:\n");
    printf("1 - Visualizar as atividades físicas\n");
    printf("2 - Registrar uma atividade física\n");            
    printf("3 - Sair\n");
    printf("Digite a opção desejada: ");
}

void menuVisualizarAtividadesFisicas(char diasDaSemana[][15]) {
    // Opção 1 do menu principal
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

void menuVisualizarAtividadesFisicasDia(int dia, char diasDaSemana[][15], char atividadesFisicas[][2][11][25]) {
    // Vizualizar as atividades físicas (menu = 1)
    // Opção 1 - Segunda-Feira
    printf("\n=== Vizualizar as Atividades Físicas ===\n");
    printf(">> Visualizar as Atividades Físicas\n");
    printf(">> %s\n", diasDaSemana[dia-10-1]);
    // Imprime as atrividades físicas
    int numeroCategorias = sizeof(atividadesFisicas[0]) / sizeof(atividadesFisicas[0][0]);
    for (int indiceAtividade = 0;
            indiceAtividade < numeroCategorias;
            indiceAtividade++)
        printf("%d - %s\n", indiceAtividade + 1, atividadesFisicas[indiceAtividade]);            
    printf("%d - Voltar\n", numeroCategorias + 1);
    printf("Entre com a opção: ");    
}

void menuRegistroAtividadeFisica(char diasDaSemana[][15]) {
    // Opção 2 do menu menu principal
    // Registrar atividade física
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Registrar Atividades Físicas\n");
    // Imprime os dias da semana
    for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
        printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
    printf("8 - Voltar\n");
    printf("Em qual dia será inserido a atividade física?\nEntre com a opção: ");
}

void menuRegistroAtividadeFisicaDia(int dia, char diasDaSemana[][15], char atividadesFisicas[][2][11][25]) {
    // Registrar uma atividade física (menu = 1)
    // Opção 1 - Segunda-Feira
    printf("\n=== Registro de Atividades Físicas ===\n");
    printf(">> Registrar Atividades Físicas\n");
    printf(">> %s\n", diasDaSemana[dia-10-1]);
    // Número de categorias
    int numeroCategorias = sizeof(atividadesFisicas[0]) / sizeof(atividadesFisicas[0][0]);
    // Imprime as categorias de atividade física
    for (int indiceCategoria = 0;
            indiceCategoria < numeroCategorias;
            indiceCategoria++)
        printf("%d - %s\n", indiceCategoria + 1, atividadesFisicas[indiceCategoria]);            
    printf("%d - Voltar\n", numeroCategorias + 1);
    printf("Entre com a opção: ");  
}

void listaMenus(int menu, char diasDaSemana[][15], char atividadesFisicas[][2][11][25]) {
    // // Declarando os dias da semana
    // char diasDaSemana[][15] = {
    //     "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira",
    //     "Quinta-Feira", "Sexta-Feira", "Sábado"
    // };    
    int numeroCategorias;

    switch(menu) {
        case 1:
            // Opção 1 do menu principal
            // Vizualizar as atividades físicas
            printf("\n=== Registro de Atividades Físicas ===\n");
            printf(">> Visualizar as Atividades Físicas\n");
            // Imprime os dias da semana
            for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
                printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
            printf("8 - Semana inteira\n");
            printf("9 - Voltar\n");
            printf("Visualizar as atividade físicas de qual(quais) dia(s)?\nEntre com a opção: ");
            break;

        case 2:
            // Opção 2 do menu menu principal
            // Registrar atividade física
            printf("\n=== Registro de Atividades Físicas ===\n");
            printf(">> Registrar Atividades Físicas\n");
            // Imprime os dias da semana
            for (int indiceDia = 0; indiceDia < strlen((char*)diasDaSemana); indiceDia++)
                printf("%d - %s\n", indiceDia + 1, diasDaSemana[indiceDia]);
            printf("8 - Voltar\n");
            printf("Em qual dia será inserido a atividade física?\nEntre com a opção: ");
            break;
        
        case 11:
            // Vizualizar as atividades físicas (menu = 1)
            // Opção 1 - Segunda-Feira
            printf("\n=== Vizualizar as Atividades Físicas ===\n");
            printf(">> Visualizar as Atividades Físicas\n");
            printf(">> %s\n", diasDaSemana[menu-10-1]);
            // Imprime as atrividades físicas
            numeroCategorias = sizeof(atividadesFisicas[0]) / sizeof(atividadesFisicas[0][0]);
            for (int indiceAtividade = 0;
                    indiceAtividade < numeroCategorias;
                    indiceAtividade++)
                printf("%d - %s\n", indiceAtividade + 1, atividadesFisicas[indiceAtividade]);            
            printf("%d - Voltar\n", numeroCategorias + 1);
            printf("Entre com a opção: ");            
            break;

        case 21:
            // Registrar uma atividade física (menu = 1)
            // Opção 1 - Segunda-Feira
            printf("\n=== Registro de Atividades Físicas ===\n");
            printf(">> Registrar Atividades Físicas\n");
            printf(">> %s\n", diasDaSemana[menu-10-1]);
            // Número de categorias
            numeroCategorias = sizeof(atividadesFisicas[0]) / sizeof(atividadesFisicas[0][0]);
            // Imprime as categorias de atividade física
            for (int indiceCategoria = 0;
                    indiceCategoria < numeroCategorias;
                    indiceCategoria++)
                printf("%d - %s\n", indiceCategoria + 1, atividadesFisicas[indiceCategoria]);            
            printf("%d - Voltar\n", numeroCategorias + 1);
            printf("Entre com a opção: ");            
            break;            

        default:
            // Padrão (menu == 0)
            // Menu inicial
            printf("\n=== Registro de Atividades Físicas ===\n");
            printf(">> Menu de opções:\n");
            printf("1 - Visualizar as atividades físicas\n");
            printf("2 - Registrar uma atividade física\n");            
            printf("3 - Sair\n");
            printf("Digite a opção desejada: ");
            break;        
    }

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
            // Item no menu principal = 1
            // Sub-menu -> Vizualizar as atividades físicas
            if (opcao < 1 || opcao > 9) {
                printf("\nOpção inválida!\n");
                return 0; // Opção inválida
            }
            break;
        case 2:
            // Item no menu principal = 2
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
