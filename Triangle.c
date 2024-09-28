#include <stdio.h>
#include "Triangle.h"

// Função para inicializar os atributos do retângulo
void inicializarRetangulo(Retangulo *r, float altura, float largura) {
    r->altura = altura;
    r->largura = largura;
}

// Função para calcular a área do retângulo
float calcularArea(Retangulo *r) {
    return r->altura * r->largura;
}

// Função para calcular o perímetro do retângulo
float calcularPerimetro(Retangulo *r) {
    return 2 * (r->altura + r->largura);
}

// Função para imprimir as informações do retângulo
void imprimirRetangulo(Retangulo *r) {
    printf("Altura: %.2f\n", r->altura);
    printf("Largura: %.2f\n", r->largura);
    printf("Área: %.2f\n", calcularArea(r));
    printf("Perímetro: %.2f\n", calcularPerimetro(r));
}
