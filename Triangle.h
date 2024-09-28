#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED



// Definição da estrutura Retangulo (TAD)
typedef struct {
    float altura;
    float largura;
} Retangulo;

// Função para inicializar os atributos do retângulo
void inicializarRetangulo(Retangulo *r, float altura, float largura);

// Função para calcular a área do retângulo
float calcularArea(Retangulo *r);

// Função para calcular o perímetro do retângulo
float calcularPerimetro(Retangulo *r);

// Função para imprimir as informações do retângulo
void imprimirRetangulo(Retangulo *r);




#endif // TRIANGLE_H_INCLUDED
