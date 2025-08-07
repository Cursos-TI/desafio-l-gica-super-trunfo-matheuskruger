#include <stdio.h>
#include <string.h>

void impresao_comparativa(
    char nome1[50], char estado1[4], float valor1,
    char nome2[50], char estado2[4], float valor2,
    const char *criterio)
{
    printf("\n--- Comparação: %s ---\n", criterio);
    printf("Carta 1 - %s (%s): %.2f\n", nome1, estado1, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", nome2, estado2, valor2);
    printf("\nResultado: ");

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
    densidadepopulacionalcd1 = (float)populacaoCidade1 / areacd1;
    densidadepopulacionalcd2 = (float)populacaoCidade2 / areacd2;
    densidadeinversacd1 = areacd1 / (float)populacaoCidade1;
    densidadeinversacd2 = areacd2 / (float)populacaoCidade2;
    pibpercaptadc1 = (pibcd1 * 1000000000.0f) / populacaoCidade1;
    pibpercaptadc2 = (pibcd2 * 1000000000.0f) / populacaoCidade2;
    superpodercarta1 = (float)nptcd1 + (float)populacaoCidade1 + pibcd1 + pibpercaptadc1 + areacd1 + densidadeinversacd1;
    superpodercarta2 = (float)nptcd2 + (float)populacaoCidade2 + pibcd2 + pibpercaptadc2 + areacd2 + densidadeinversacd2;

    // chamha a Função que faz a impresão e comparação
    impresao_comparativa(nomecidade1, estado1, pibcd1, nomecidade2, estado2, pibcd2, "PIB");

    return 0;
}