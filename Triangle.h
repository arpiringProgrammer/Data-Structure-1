#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED



// Defini��o da estrutura Retangulo (TAD)
typedef struct {
    float altura;
    float largura;
} Retangulo;

// Fun��o para inicializar os atributos do ret�ngulo
void inicializarRetangulo(Retangulo *r, float altura, float largura);

// Fun��o para calcular a �rea do ret�ngulo
float calcularArea(Retangulo *r);

// Fun��o para calcular o per�metro do ret�ngulo
float calcularPerimetro(Retangulo *r);

// Fun��o para imprimir as informa��es do ret�ngulo
void imprimirRetangulo(Retangulo *r);




#endif // TRIANGLE_H_INCLUDED
