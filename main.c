#define COR_RESETAR            "\033[0m"
#define RESET "\033[0m"
#define COR_VERMELHO           "\033[31m"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char produtos[4][30] = {
    "Marmita de frango",
    "Marmita de porco",
    "Marmita de peixe",
    "Marmita de boi"
};

float preco[4] = {
    20.00,
    25.00,
    35.00,
    30.00
};

int estoque[4] = {
    10,
    10,
    10,
    10
};

int compra[4] = {
    0,
    0,
    0,
    0
};


char bebidas[4][30] = {
    "Coca lata",
    "Guarana lata",
    "Fanta lata",
    "Sprite lata"
};

float preco_bebida[4] = {
    6.00,
    6.00,
    6.00,
    6.00
};

int estoque_bebida[4] = {
    10,
    10,
    10,
    10
};

int compra_bebida[4] = {
    0,
    0,
    0,
    0
};
void carrega_produto() {
    FILE *arquivo = fopen("estoque.txt", "r");
   
    if (arquivo != NULL) {
        for (int i = 0; i < 4; i++) {
            fscanf(arquivo, "%d", &estoque[i]);
        }
        for (int i = 0; i < 4; i++) {
            fscanf(arquivo, "%d", &estoque_bebida[i]);
        }  
        fclose(arquivo);
    } else {
        printf("\n[Aviso] Arquivo de estoque nao encontrado. Usando valores padrao (10 unidades).\n");
    }
}

void salva_produto(){
    FILE *arquivo = fopen("estoque.txt", "w");
    
    if (arquivo != NULL){
        for (int i = 0; i < 4; i++){
            fprintf(arquivo, "%d\n", estoque[i]);
        }
         for (int i = 0; i < 4; i++){
            fprintf(arquivo, "%d\n", estoque_bebida[i]);
        }
        fclose(arquivo);
    } else {
        printf("\n[Aviso] Arquivo de estoque nao encontrado. Usando valores padrao (10 unidades).\n");
    }
}


void nome_loja() {

    printf("\n");
    printf( COR_VERMELHO"███╗   ███╗██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ \n");
    printf("████╗ ████║██║██╔══██╗██╔══██╗████╗  ██║██║  ██║██╔══██╗\n");
    printf("██╔████╔██║██║██████╔╝███████║██╔██╗ ██║███████║███████║\n");
    printf("██║╚██╔╝██║██║██╔══██╗██╔══██║██║╚██╗██║██╔══██║██╔══██║\n");
    printf("██║ ╚═╝ ██║██║██║  ██║██║  ██║██║ ╚████║██║  ██║██║  ██║\n");
    printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝\n");

    printf("\n");
    printf("███╗   ███╗ █████╗ ██████╗ ███╗   ███╗██╗████████╗ █████╗ ███████╗\n");
    printf("████╗ ████║██╔══██╗██╔══██╗████╗ ████║██║╚══██╔══╝██╔══██╗██╔════╝\n");
    printf("██╔████╔██║███████║██████╔╝██╔████╔██║██║   ██║   ███████║███████╗\n");
    printf("██║╚██╔╝██║██╔══██║██╔══██╗██║╚██╔╝██║██║   ██║   ██╔══██║╚════██║\n");
    printf("██║ ╚═╝ ██║██║  ██║██║  ██║██║ ╚═╝ ██║██║   ██║   ██║  ██║███████║\n");
    printf("╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝\n" RESET);

    printf("\n");
    printf("============================================\n");
    printf("          BEM-VINDO A MIRANHA MARMITAS\n");
    printf("============================================\n");
}


void mostra_marmitas(){
    
        printf("\n--- MARMITAS ---\n");

    for (int i = 0; i < 4; i++) {
        printf("%d - %s -- R$ %.2f -- Estoque: %d\n",
               i ,
               produtos[i],
               preco[i],
               estoque[i]);
    }
}

void mostra_bebidas() {

    printf("\n--- BEBIDAS ---\n");

    for (int i = 0; i < 4; i++) {
        printf("%d - %s -- R$ %.2f -- Estoque: %d\n",
               i ,
               bebidas[i],
               preco_bebida[i],
               estoque_bebida[i]);
    }
}


void mostra_compra() {
    float total = 0;
    int comprou_algo = 0;

    printf("\n");
    printf("============================================\n");
    printf("                NOTA FISCAL                 \n");
    printf("============================================\n");

    for (int i = 0; i < 4; i++) {
        if (compra[i] != 0) {
            float pagar = compra[i] * preco[i];
            printf("%-20s x%d  --  Subtotal: R$ %.2f\n", produtos[i], compra[i], pagar);
            total += pagar;
            comprou_algo = 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (compra_bebida[i] != 0) {
            float pagar = compra_bebida[i] * preco_bebida[i];
            printf("%-20s x%d  --  Subtotal: R$ %.2f\n", bebidas[i], compra_bebida[i], pagar);
            total += pagar;
            comprou_algo = 1;
        }
    }

    if (!comprou_algo) {
        printf("Nenhum item foi comprado.\n");
    }

    printf("============================================\n");
    printf("TOTAL A PAGAR: R$ %.2f\n", total);
    printf("============================================\n");
}

void escolha_marmita(){
    int produto;
    int quantidade;

    printf("\nEscolha o numero da marmita: ");
    scanf("%d", &produto);
    if (produto < 0 || produto > 3){
        printf("[Erro] Marmita invalida\n");
        return;
    }
    printf("Escolha a quantidade: ");
    scanf("%d", &quantidade);
    
    if (quantidade <= 0) {
        printf("[Erro] Quantidade invalida!\n");
        return;
    }

    if (quantidade > estoque[produto]) {
        printf("\n[Erro] Desculpe, so temos %d unidades de %s no estoque!\n", estoque[produto], produtos[produto]);
    } else {
        compra[produto] += quantidade;
        estoque[produto] = estoque[produto] - quantidade;
        printf("\n[Sucesso] %dx %s adicionada ao carrinho!\n", quantidade, produtos[produto]);
    }
}

void escolha_bebida(){
    int produto;
    int quantidade;

    printf("\nEscolha o numero da bebida: ");
    scanf("%d", &produto);
    if (produto < 0 || produto > 3){
        printf("[Erro] Bebida invalida\n");
        return;
    }
    printf("Escolha a quantidade: ");
    scanf("%d", &quantidade);
    
    if (quantidade <= 0) {
        printf("[Erro] Quantidade invalida!\n");
        return;
    }

    if (quantidade > estoque_bebida[produto]) {
        printf("\n[Erro] Desculpe, so temos %d unidades de %s no estoque!\n", estoque_bebida[produto], bebidas[produto]);
    } else {
        compra_bebida[produto] += quantidade;
        estoque_bebida[produto] = estoque_bebida[produto] - quantidade;
        printf("\n[Sucesso] %dx %s adicionada ao carrinho!\n", quantidade, bebidas[produto]);
    }
}
void restoque_marmita(){
    int produto;
    int quantidade;
    mostra_marmitas();

    printf("\nEscolha o numero da marmita para repor: ");
    scanf("%d", &produto);

    if (produto < 0 || produto > 3) {
        printf("[Erro] Marmita invalida!\n");
        return;
    }

    printf("Quantidade a adicionar ao estoque: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("[Erro] Quantidade invalida!\n");
        return;
    }

    estoque[produto] += quantidade;
    printf("\n[Sucesso] Estoque de %s atualizado para %d unidades!\n", produtos[produto], estoque[produto]);
}

void restoque_bebida(){
    int produto;
    int quantidade;
    mostra_bebidas();

    printf("\nEscolha o numero da bebida para repor: ");
    scanf("%d", &produto);

    if (produto < 0 || produto > 3) {
        printf("[Erro] Bebida invalida!\n");
        return;
    }

    printf("Quantidade a adicionar ao estoque: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("[Erro] Quantidade invalida!\n");
        return;
    }

    estoque_bebida[produto] += quantidade;
    printf("\n[Sucesso] Estoque de %s atualizado para %d unidades!\n", bebidas[produto], estoque_bebida[produto]);
}

void restoque(){
    
    int tipo;
    
    printf("\n--- MODO ADMINISTRADOR: RESTOCAR ---\n");
    printf("1 - Restocar Marmitas\n");
    printf("2 - Restocar Bebidas\n");
    printf("3 - Voltar ao Menu\n");
    printf("Escolha o tipo de produto: ");
    scanf("%d", &tipo);
    
    switch (tipo){
        case 1:
            restoque_marmita();
            break;
        case 2:
            restoque_bebida();
            break;
        case 3:
            break;
        default:
            printf("\n[Erro] Opcao invalida! Tente novamente.\n");
            break;
    }
}


int main()
{
    int opcao;
    carrega_produto();
    nome_loja();
    while(opcao != 4){
        
         printf("\n--- MENU PRINCIPAL ---\n");
        printf("1 - Comprar Marmita\n");
        printf("2 - Comprar Bebida\n");
        printf("3 - Abrir Menu de ADMINISTRADOR\n");
        printf("4 - Finalizar Compra e Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
         switch (opcao) {
            case 1:
                mostra_marmitas();
                escolha_marmita();
                break;
            case 2:
                mostra_bebidas();
                escolha_bebida();
                break;
            case 3:
                restoque();
                break;
            case 4:
                break;
            default:
                printf("\n[Erro] Opcao invalida! Tente novamente.\n");
                break;
        }
    }
    mostra_compra();
    salva_produto();
    

    return 0;
}
