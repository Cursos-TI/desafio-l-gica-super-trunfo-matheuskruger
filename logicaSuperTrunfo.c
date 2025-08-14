#include <stdio.h>
#include <string.h>

// =========== Faz a compração dos atributos =========//
int comparacao(float valor1, float valor2, int numero)
{

    if (numero != 0)
    {
        if (valor1 > valor2)
        {
            return 1;
        }
        else if (valor2 > valor1)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }

    else if (numero == 0)
    {
        if (valor1 < valor2)
        {
            return 1;
        }
        else if (valor2 < valor1)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

// =========== Faz o Calculo da Densidade =========//
float Calculo_densidade(unsigned long int populacao, float area, int bolean)
{
    if (area == 0 || populacao == 0)
    {
        printf("Erro: população ou área inválida para cálculo de densidade.\n");
        return 0.0f;
    }
    return bolean == 0 ? area / (float)populacao : (float)populacao / area;
}
// =========== Faz o Calculo do PIB per Capita =========//
float Calculo_PIB_Per_Capita(unsigned long int populacao, float pib)
{
    if (pib == 0 || populacao == 0)
    {
        printf("Erro: população ou PIB inválida para cálculo do PIB per Capita.\n");
        return 0.0f;
    }
    return (pib * 1000000000.0f) / (float)populacao;
}
// =========== Faz o Calculo do Super Poder =========//
float Calculo_super_Poder(unsigned long int populacao, float pib, int npt, float pibpercapta, float area, float densidadeinversa)
{
    return (float)npt + (float)populacao + pib + pibpercapta + area + densidadeinversa;
}

// =========== Faz a Limpeza do Buffer antes do Fgets  =========//
void limparBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // descarta os caracteres até o fim da linha ou EOF
    }
}

int main()
{
    // ====== Declarção da Variaveis ==========//
    const char *criterio1, *criterio2;
    char letracidade1, letracidade2;
    char nomecidade1[50], nomecidade2[50];
    char codigodacarta1[4], codigodacarta2[4], estado1[4], estado2[4];
    int nptcd1, nptcd2, resultado1, resultado2;
    unsigned long int populacaoCidade1, populacaoCidade2;
    float areacd1, areacd2, pibcd1, pibcd2;
    float densidadepopulacionalcd1, densidadepopulacionalcd2, densidadeinversacd1, densidadeinversacd2;
    float pibpercaptadc1, pibpercaptadc2, superpodercarta1, superpodercarta2;
    float soma1, soma2, valor1a, valor1b, valor2a, valor2b;

    // ===== CARTA 1 =====
    printf("Entrada das Informações da carta 1:\n");

    printf("Informe uma letra para identificar o estado:\n");
    scanf(" %c", &letracidade1);

    printf("Informe o código:\n");
    scanf("%3s", codigodacarta1);
    // Limpa buffer antes do fgets
    limparBuffer();
    printf("Informe a sigla do Estado:\n");
    fgets(estado1, sizeof(estado1), stdin);
    if (estado1[strlen(estado1) - 1] == '\n')
    {
        estado1[strlen(estado1) - 1] = '\0';
    }

    printf("Informe o nome da cidade:\n");
    fgets(nomecidade1, sizeof(nomecidade1), stdin);
    if (nomecidade1[strlen(nomecidade1) - 1] == '\n')
    {
        nomecidade1[strlen(nomecidade1) - 1] = '\0';
    }

    printf("Informe a população da cidade:\n");
    scanf("%lu", &populacaoCidade1);

    printf("Informe a área da cidade:\n");
    scanf("%f", &areacd1);

    printf("Informe o PIB da cidade:\n");
    scanf("%f", &pibcd1);

    printf("Informe o número de pontos turísticos da cidade:\n");
    scanf("%d", &nptcd1);

    // ===== CARTA 2 =====
    printf("\nEntrada das Informações da carta 2:\n");

    printf("Informe uma letra para identificar o estado:\n");
    scanf(" %c", &letracidade2);

    printf("Informe o código:\n");
    scanf("%3s", codigodacarta2);

    // Limpa buffer antes do fgets
    limparBuffer();
    printf("Informe a sigla do Estado:\n");
    fgets(estado2, sizeof(estado2), stdin);
    if (estado2[strlen(estado2) - 1] == '\n')
    {
        estado2[strlen(estado2) - 1] = '\0';
    }

    printf("Informe o nome da cidade:\n");
    fgets(nomecidade2, sizeof(nomecidade2), stdin);
    if (nomecidade2[strlen(nomecidade2) - 1] == '\n')
    {
        nomecidade2[strlen(nomecidade2) - 1] = '\0';
    }

    printf("Informe a população da cidade:\n");
    scanf("%lu", &populacaoCidade2);

    printf("Informe a área da cidade:\n");
    scanf("%f", &areacd2);

    printf("Informe o PIB da cidade:\n");
    scanf("%f", &pibcd2);

    printf("Informe o número de pontos turísticos da cidade:\n");
    scanf("%d", &nptcd2);

    // ==== Realiza os calulos ========
    densidadepopulacionalcd1 = Calculo_densidade(populacaoCidade1, areacd1, 1);
    densidadepopulacionalcd2 = Calculo_densidade(populacaoCidade2, areacd2, 1);
    densidadeinversacd1 = Calculo_densidade(populacaoCidade1, areacd1, 0);
    densidadeinversacd2 = Calculo_densidade(populacaoCidade2, areacd2, 0);
    pibpercaptadc1 = Calculo_PIB_Per_Capita(populacaoCidade1, pibcd1);
    pibpercaptadc2 = Calculo_PIB_Per_Capita(populacaoCidade2, pibcd2);
    superpodercarta1 = Calculo_super_Poder(populacaoCidade1, pibcd1, nptcd1, pibpercaptadc1, areacd1, densidadeinversacd1);
    superpodercarta2 = Calculo_super_Poder(populacaoCidade2, pibcd2, nptcd2, pibpercaptadc2, areacd2, densidadeinversacd2);

    // exibe o Menu

    int opcao1;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    if (opcao1 > 7 || opcao1 < 1)
    {
        printf("Opção inválida!\n");
        return 0;
    }
    switch (opcao1)
    {
    case 1:
        resultado1 = comparacao(populacaoCidade1, populacaoCidade2, 1);
        criterio1 = "População";
        valor1a = populacaoCidade1;
        valor2a = populacaoCidade2;
        break;
    case 2:
        resultado1 = comparacao(areacd1, areacd2, 1);
        criterio1 = "Área";
        valor1a = areacd1;
        valor2a = areacd2;
        break;
    case 3:
        resultado1 = comparacao(pibcd1, pibcd2, 1);
        criterio1 = "PIB";
        valor1a = pibcd1;
        valor2a = pibcd2;
        break;
    case 4:
        resultado1 = comparacao(nptcd1, nptcd2, 1);
        criterio1 = "Pontos Turísticos";
        valor1a = nptcd1;
        valor2a = nptcd2;
        break;
    case 5:
        resultado1 = comparacao(densidadepopulacionalcd1, densidadepopulacionalcd2, 0);
        criterio1 = "Densidade Demográfica";
        valor1a = densidadepopulacionalcd1;
        valor2a = densidadepopulacionalcd2;
        break;
    case 6:
        resultado1 = comparacao(pibpercaptadc1, pibpercaptadc2, 1);
        criterio1 = "PIB per Capita";
        valor1a = pibpercaptadc1;
        valor2a = pibpercaptadc2;

        break;
    case 7:
        resultado1 = comparacao(superpodercarta1, superpodercarta2, 1);
        criterio1 = "Super Poder";
        valor1a = superpodercarta1;
        valor2a = superpodercarta2;
        break;
    }
    int opcao2;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2)
    {
        printf("Criterio ja escolhido !\n");
        return 0;
    }

    if (opcao2 > 7 || opcao2 < 1)
    {
        printf("Opção inválida!\n");
        return 0;
    }
    switch (opcao2)
    {
    case 1:
        resultado2 = comparacao(populacaoCidade1, populacaoCidade2, 1);
        criterio2 = "População";
        valor1b = populacaoCidade1;
        valor2b = populacaoCidade2;
        break;
    case 2:
        resultado2 = comparacao(areacd1, areacd2, 1);
        criterio2 = "Área";
        valor1b = areacd1;
        valor2b = areacd2;
        break;
    case 3:
        resultado2 = comparacao(pibcd1, pibcd2, 1);
        criterio2 = "PIB";
        valor1b = pibcd1;
        valor2b = pibcd2;
        break;
    case 4:
        resultado2 = comparacao(nptcd1, nptcd2, 1);
        criterio2 = "Pontos Turísticos";
        valor1b = nptcd1;
        valor2b = nptcd2;
        break;
    case 5:
        resultado2 = comparacao(densidadepopulacionalcd1, densidadepopulacionalcd2, 0);
        criterio2 = "Densidade Demográfica";
        valor1b = densidadepopulacionalcd1;
        valor2b = densidadepopulacionalcd2;
        break;
    case 6:
        resultado2 = comparacao(pibpercaptadc1, pibpercaptadc2, 1);
        criterio2 = "PIB per Capita";
        valor1b = pibpercaptadc1;
        valor2b = pibpercaptadc2;
        break;
    case 7:
        resultado2 = comparacao(superpodercarta1, superpodercarta2, 1);
        criterio2 = "Super Poder";
        valor1b = superpodercarta1;
        valor2b = superpodercarta2;
        break;
    }

    soma1 = valor1a + valor1b;
    soma2 = valor2a + valor2b;

    // Resultado do primeiro critério
    printf("\n--- Resultado do critério 1 (%s) ---\n", criterio1);
    if (resultado1 == 1)
    {
        printf("%s (%s) venceu! Valor: %.2f\n", nomecidade1, estado1, valor1a);
    }
    else if (resultado1 == 2)
    {
        printf("%s (%s) venceu! Valor: %.2f\n", nomecidade2, estado2, valor2a);
    }
    else
    {
        printf("Empate!\n");
    }

    // Resultado do segundo critério
    printf("\n--- Resultado do critério 2 (%s) ---\n", criterio2);
    if (resultado2 == 1)
    {
        printf("%s (%s) venceu! Valor: %.2f\n", nomecidade1, estado1, valor1b);
    }
    else if (resultado2 == 2)
    {
        printf("%s (%s) venceu! Valor: %.2f\n", nomecidade2, estado2, valor2b);
    }
    else
    {
        printf("Empate!\n");
    }

    printf("\n=== Resultado Final ===\n");
    if (soma1 > soma2)
        printf("%s (%s) é a vencedora! Soma: %.2f x %.2f\n", nomecidade1, estado1, soma1, soma2);
    else if (soma2 > soma1)
        printf("%s (%s) é a vencedora! Soma: %.2f x %.2f\n", nomecidade2, estado2, soma2, soma1);
    else
        printf("Empate geral! Soma: %.2f\n", soma1 );

    return 0;
}