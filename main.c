#include <stdio.h>
#include <stdlib.h>
#include "Triangle.h"

int main()
{
    Retangulo ret;  // Declarando o ret�ngulo

    // Inicializando o ret�ngulo com altura e largura
    inicializarRetangulo(&ret, 5.0, 10.0);

    // Imprimindo as informa��es do ret�ngulo
    imprimirRetangulo(&ret);
    return 0;
}
