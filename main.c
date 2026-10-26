#include <stdio.h>   // 🐒 Mamaco pega ferramenta pra falar (printf) e ouvir (scanf)
#include <stdlib.h>  // 🐒 Mamaco pega ferramenta extra pra mexer com sistema

char opcao; // 🐒 Gaveta pro mamaco guardar o botão que o humano apertou no menu

// 🎨 Tintas pro mamaco pintar o texto no terminal
#define COR_RESETAR "\033[0m"   // 🧼 Limpa as cor e volta pro normal
#define FUNDO_AZUL "\033[104m"  // 🟦 Pinta o fundo de azul
#define COR_VERMELHA "\033[31m" // 🟥 Pinta as letra de vermelho (alerta!)
#define COR_VERDE "\033[32m"    // 🟩 Pinta as letra de verde (sucesso!)
#define ARQUIVO_ESTOQUE "dados_estoque.txt" // 📝 Nome do papel onde mamaco anota as marmita pra não esquecer

// 💾 FUNÇÃO: MAMACO ESCREVE NO PAPEL (SALVAR)
void salvar_dados(int estoque[]) {
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "w"); // 📂 Abre o bloco de notas pra escrever ("w")
    if (arquivo == NULL) { // 🛑 Ih, o papel sumiu ou rasgou?
        return; // 🐒 Mamaco desiste e vai embora
    }
    for (int i = 0; i < 4; i++) { // 🔁 Passa pelos 4 tipo de marmita
        fprintf(arquivo, "%d\n", estoque[i]); // ✍️ Escreve no papel quantas sobrou de cada uma
    }
    fclose(arquivo); // 🔒 Fecha o bloco de notas pro vento não levar
}

// 📖 FUNÇÃO: MAMACO LÊ O PAPEL (CARREGAR)
void carregar_dados(int estoque[]) {
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "r"); // 📂 Abre o papel pra ler ("r")
    if (arquivo == NULL) { // 🛑 Não tem papel guardado ainda? (Primeira vez rodando)
        return; // 🐒 Mamaco usa o estoque padrão de 10 e vai embora
    }
    for (int i = 0; i < 4; i++) { // 🔁 Passa pelas 4 marmita
        fscanf(arquivo, "%d", &estoque[i]); // 🤓 Olha o papel e bota o número de volta nas gaveta de estoque
    }
    fclose(arquivo); // 🔒 Fecha o papel
}

// 🏢 FUNÇÃO: DESENHA A FACHADA DA LOJA COM BANNER BONITO
void nome_loja() {
    printf("\n" FUNDO_AZUL COR_VERMELHA); // 🎨 Ativa o fundo azul e letra vermelha
    printf(" ████╗ ████║██║██╔══██╗██╔══██╗████╗  ██║██║  ██║██╔══██╗\n"); // 🧱 Desenha "M" gigante
    printf(" ██╔████╔██║██║██████╔╝███████║██╔██╗ ██║███████║███████║\n"); // 🧱 Desenha "I" gigante
    printf(" ██║╚██╔╝██║██║██╔══██╗██╔══██║██║╚██╗██║██╔══██║██╔══██║\n"); // 🧱 Desenha "R" gigante
    printf(" ╚═╝ ╚═╝ ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝\n"); // 🧱 Termina o desenho doido
    printf(COR_RESETAR "\n"); // 🧼 Tira as cor pra não estragar o resto
    printf("====================================================\n"); // ➖ Linha bonita
    printf("             BEM-VINDO A MIRANHA MARMITAS           \n"); // 💬 Texto de boas-vindas
    printf("====================================================\n"); // ➖ Outra linha bonita
}

// 📦 AS GAVETAS DE COISAS DA LOJA (VETORES)
char produtos[4][30] = {"Marmita de frango", "Marmita de porco", "Marmita de boi", "Marmita de peixe"}; // 🍗 Prateleira com os nomes
float preco[4] = {20.00, 25.00, 30.00, 35.00}; // 💵 Etiquetas de preço de cada uma
int estoque[4] = {10, 10, 10, 10};      // 🎒 Quantas marmitas tem na cozinha pra vender
int compras[4] = {0, 0, 0, 0};          // 🛒 Carrinho de compras do cliente (começa vazio)

// 📋 FUNÇÃO: MOSTRAR O CARDÁPIO
void cardapio() {
    printf("\n >--- Cardapio ---<\n"); // 💬 Título do cardápio
    for (int i = 0; i < 4; i++) { // 🔁 Loop que conta: 0, 1, 2, 3...
        printf("%d - %s | R$ %.2f [Estoque: %d]\n", i, produtos[i], preco[i], estoque[i]); // 📢 Grita o número, o nome, o preço e o estoque de cada marmita
    }
}

// 🛍️ FUNÇÃO: FAZER COMPRA (BOTAR NO CARRINHO)
void compra() {
    int item, qtd; // 📦 Gavetinhas temporárias pra guardar o que o humano quer agora
    printf("\nDigite o numero do produto:\n"); // 💬 Pergunta qual marmita quer (0 a 3)
    
    if (scanf("%d", &item) != 1) { // 🤔 Humano digitou letra em vez de número?
        printf("\n" COR_VERMELHA "Entrada invalida! Digite apenas numeros." COR_RESETAR "\n"); // 🟥 Grita erro vermelho
        while (getchar() != '\n'); // 🧹 Limpa a bagunça que o humano digitou
        return; // 🐒 Mamaco cancela a operação e volta pro menu
    }
    while (getchar() != '\n'); // 🧹 Limpa o "Enter" que sobrou no teclado
    
    if(item < 0 || item > 3) { // 🤔 Humano digitou um número que não tem no cardápio? (tipo 5 ou 9)
        printf("\n" COR_VERMELHA "Produto invalido!" COR_RESETAR "\n"); // 🟥 Grita erro
        return; // 🐒 Mamaco cancela
    }
    
    printf("Digite a quantidade:\n"); // 💬 Pergunta quantas marmitas ele quer levar
    if (scanf("%d", &qtd) != 1) { // 🤔 Digitou besteira de novo?
        printf("\n" COR_VERMELHA "Quantidade invalida!" COR_RESETAR "\n"); // 🟥 Grita quantidade errada
        while (getchar() != '\n'); // 🧹 Limpa o teclado
        return; // 🐒 Mamaco cancela
    }
    while (getchar() != '\n'); // 🧹 Limpa o "Enter" do teclado de novo
    
    if (qtd <= estoque[item] && qtd > 0) { // 🤔 Tem marmita suficiente na cozinha E a quantidade é maior que zero?
        compras[item] += qtd; // 🛒 Coloca as marmitas dentro do carrinho do cliente
        estoque[item] -= qtd; // 📉 Tira as marmitas da geladeira da cozinha
        
        salvar_dados(estoque); // 📝 Anota na hora no papel pra não perder o estoque se a energia acabar
        
        printf("\n" COR_VERDE "Sucesso: %d unidades de '%s' adicionadas!" COR_RESETAR "\n", qtd, produtos[item]); // 🟩 Grita sucesso verde!
    } else { // ❌ Se não tiver estoque suficiente ou digitou número negativo...
        printf("\n" COR_VERMELHA "Erro! So temos %d unidades no estoque." COR_RESETAR "\n", estoque[item]); // 🟥 Grita que acabou
    }
}

// 🧾 FUNÇÃO: EMITIR NOTA FISCAL (FECHAR CONTA)
void fechar_pedido() {
    float total = 0; // 💵 Moedas totais que o cliente vai pagar (começa em zero)
    printf("\n==================================\n");
    printf("           NOTA FISCAL            \n"); 
    printf("==================================\n");
    
    for (int i = 0; i < 4; i++) {   // 🔁 Mamaco revista as 4 posições do carrinho do cliente
        if (compras[i] > 0) { // 🤔 O cliente colocou essa marmita no carrinho?
            float subtotal = compras[i] * preco[i];  // 🧮 Conta rápida: Quantidade vezes Preço dela
            printf("%s x %d = R$ %.2f\n", produtos[i], compras[i], subtotal);  // 📢 Mostra a linha do que ele comprou
            total += subtotal; // 💰 Soma esse valor no dinheirão total
        }
    }
    
    printf("----------------------------------\n");
    printf("TOTAL A PAGAR: R$ %.2f\n", total);             // 📢 Mostra o valor final do estrago
    printf("==================================\n");
}

// 🕹️ O CORAÇÃO DO JOGO: ONDE TUDO COMEÇA
int main() {          
    carregar_dados(estoque); // 🤓 Primeira coisa: Abre o papel antigo pra ver se tinha estoque guardado
    nome_loja(); // 🏢 Desenha o letreiro da loja na tela
    
    do { // 🔁 FAZ ISSO AQUI EM BAIXO... (Começo do Loop do Menu)
        printf("\n=== Sistema de Marmitas ===\n");         // 📋 Mostra o título do menu
        printf("1 - Ver cardapio\n");                     // 📋 Opção 1
        printf("2 - Fazer uma compra\n");                  // 📋 Opção 2
        printf("3 - Finalizar e emitir nota\n");           // 📋 Opção 3
        printf("Escolha uma opcao: ");                     // 💬 Pede pro humano escolher
        
        scanf(" %c", &opcao); // 👁️ Mamaco fica olhando qual letra/número o usuário vai apertar
        while (getchar() != '\n'); // 🧹 Limpa o Enter pra não bugar a próxima leitura
        
        switch(opcao) { // 🔀 Dependendo do botão que o humano apertou...
            case '1': // 🔘 Se apertou '1':
                cardapio(); // 📋 Chama o garçom pra mostrar o cardápio
                break; // 🛑 Sai do Switch e vai checar o while lá embaixo
            case '2': // 🔘 Se apertou '2':
                cardapio(); // 📋 Mostra o cardápio primeiro pro humano não escolher às cegas
                compra(); // 🛍️ Abre a barraca de vendas
                break; // 🛑 Sai do Switch
            case '3': // 🔘 Se apertou '3':
                fechar_pedido(); // 🧾 Fecha a conta e mostra o preço
                break; // 🛑 Sai do Switch
            default: // 🔀 Se apertou qualquer outra tecla errada (tipo 'X' ou '9'):
                printf("\n" COR_VERMELHA "Opcao invalida! Tente novamente." COR_RESETAR "\n"); // 🟥 Grita reclamação vermelha
                break; // 🛑 Sai do Switch
        }
    } while(opcao != '3'); // 🔁 ...ENQUANTO o botão apertado for DIFERENTE de '3'. (Se for igual a '3', o loop quebra!)
    
    return 0; // 👌 Fim do programa! Mamaco vai comer banana porque o trabalho acabou.
}
