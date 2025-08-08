#include <stdio.h>
#include <string.h>

// =========== Imprime e faza compração dos atributos =========//
void impresao_comparativa(
    char nome1[50], char estado1[4], float valor1,
    char nome2[50], char estado2[4], float valor2,
    const char *criterio, int numero)
{
    printf("\n--- Comparação: %s ---\n", criterio);
    printf("Carta 1 - %s (%s): %.2f\n", nome1, estado1, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", nome2, estado2, valor2);

    printf("\nResultado: ");
    if (numero != 0)
    {
        if (valor1 > valor2)
        {
            printf("Carta 1 (%s) venceu no critério %s!\n", nome1, criterio);
        }
        else if (valor2 > valor1)
        {
            printf("Carta 2 (%s) venceu no critério %s!\n", nome2, criterio);
        }
        else
        {
            printf("Empate no critério %s!\n", criterio);
        }
    }
    else if (numero == 0)
    {
        if (valor1 < valor2)
        {
            printf("Carta 1 (%s) venceu no critério %s!\n", nome1, criterio);
        }
        else if (valor2 < valor1)
        {
            printf("Carta 2 (%s) venceu no critério %s!\n", nome2, criterio);
        }
        else
        {
            printf("Empate no critério %s!\n", criterio);
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
    if (bolean != 0)
    {
        return (float)populacao / area;
    }
    return area / (float)populacao;
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
    char letracidade1, letracidade2;
    char nomecidade1[50], nomecidade2[50];
    char codigodacarta1[4], codigodacarta2[4], estado1[4], estado2[4];
    int nptcd1, nptcd2;
    unsigned long int populacaoCidade1, populacaoCidade2;
    float areacd1, areacd2, pibcd1, pibcd2;
    float densidadepopulacionalcd1, densidadepopulacionalcd2, densidadeinversacd1, densidadeinversacd2;
    float pibpercaptadc1, pibpercaptadc2, superpodercarta1, superpodercarta2;

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

    int opcao;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao > 7 || opcao < 1)
    {
        printf("Opção inválida!\n");
        return 0;
    }
    switch (opcao)
    {
    case 1:
        impresao_comparativa(nomecidade1, estado1, populacaoCidade1, nomecidade2, estado2, populacaoCidade2, "População", 1);
        break;
    case 2:
        impresao_comparativa(nomecidade1, estado1, areacd1, nomecidade2, estado2, areacd2, "Área", 1);
        break;
    case 3:
        impresao_comparativa(nomecidade1, estado1, pibcd1, nomecidade2, estado2, pibcd2, "PIB", 1);
        break;
    case 4:
        impresao_comparativa(nomecidade1, estado1, nptcd1, nomecidade2, estado2, nptcd2, "Pontos Turísticos", 1);
        break;
    case 5:
        impresao_comparativa(nomecidade1, estado1, densidadepopulacionalcd1, nomecidade2, estado2, densidadepopulacionalcd2, "Densidade Demográfica", 0);
        break;
    case 6:
        impresao_comparativa(nomecidade1, estado1, pibpercaptadc1, nomecidade2, estado2, pibpercaptadc2, "PIB per Capita", 1);
        break;
    case 7:
        impresao_comparativa(nomecidade1, estado1, superpodercarta1, nomecidade2, estado2, superpodercarta2, "Super Poder", 1);
        break;
    }

    return 0;
}
