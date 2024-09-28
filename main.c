#include <stdio.h>
#include <stdlib.h>
#include "Triangle.h"

int main()
{
    Retangulo ret;  // Declarando o retângulo

    // Inicializando o retângulo com altura e largura
    inicializarRetangulo(&ret, 5.0, 10.0);

    // Imprimindo as informações do retângulo
    imprimirRetangulo(&ret);
    return 0;
}
