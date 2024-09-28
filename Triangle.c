#include <stdio.h>
#include "Triangle.h"

// Fun��o para inicializar os atributos do ret�ngulo
void inicializarRetangulo(Retangulo *r, float altura, float largura) {
    r->altura = altura;
    r->largura = largura;
}

// Fun��o para calcular a �rea do ret�ngulo
float calcularArea(Retangulo *r) {
    return r->altura * r->largura;
}

// Fun��o para calcular o per�metro do ret�ngulo
float calcularPerimetro(Retangulo *r) {
    return 2 * (r->altura + r->largura);
}

// Fun��o para imprimir as informa��es do ret�ngulo
void imprimirRetangulo(Retangulo *r) {
    printf("Altura: %.2f\n", r->altura);
    printf("Largura: %.2f\n", r->largura);
    printf("�rea: %.2f\n", calcularArea(r));
    printf("Per�metro: %.2f\n", calcularPerimetro(r));
}
