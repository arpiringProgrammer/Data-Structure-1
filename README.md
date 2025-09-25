#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PracticeFile.h"
#define INICIAL_SIZE 10


/*
Questão 03
Implemente um TAD Hora utilizando ponteiros para representar uma hora específica do dia,
armazenando horas, minutos e segundos como inteiros. O TAD deve incluir uma função de criação
para alocar dinamicamente uma hora e inicializar seus valores, realizando validação para garantir
que cada campo seja válido e, em caso de valores inválidos, atribuindo zero, e uma função de
destruição para liberar a memória alocada. Além disso, implemente funções setters para alterar cada
campo da hora, realizando validação dos valores antes de atribuí-los, e funções getters para acessar
os valores de horas, minutos e segundos. O TAD deve também conter uma função para avançar o
tempo em uma quantidade de segundos especificada, considerando sempre o intervalo de um dia,
uma função para comparar dois horários, retornando verdadeiro se forem iguais e falso caso
contrário, e uma função para retornar a hora no formato h:m:s. Adicionalmente, implemente funções
inc e dec para respectivamente aumentar ou diminuir a hora em um segundo, ajustando minutos e
horas conforme necessário. Por fim, escreva um programa que utilize e teste todas as operações do
TAD Hora.
*/



Date* realocateMemory(int newSize, Date* list) {
    Date* size = (Date*)realloc(list,sizeof(Date*) * newSize);
    if(!size) {
        return NULL;
    }
    return size;
}

void releaseMemory(Date* list) {
    free(list);
}

int setSecond(int second, Date* date, int size) {
    if(second > 0) {
        date[size].second = second;
        return 1;
    }
    return 0;
}

int setMinute(int minute, Date* date, int size) {
    if(minute > 0) {
        date[size].minute = minute;
        return 1;
    }
    return 0;
}

int setHour(int hour, Date* date, int size) {
    if(hour > 0) {
        date[size].hour = hour;
        return 1;
    }
    return 0;
}

int getSecond(int size, Date* date) {
    return date[size].second;
}

int getMinute(int size, Date* date) {
    return date[size].minute;
}

int getHour(int size, Date* date) {
    return date[size].hour;
}

int compareHours(int firstPosition, int secondPosition, Date* date) {
    if(date[firstPosition].second == date[secondPosition].second &&
       date[firstPosition].minute == date[secondPosition].minute &&
       date[firstPosition].hour == date[secondPosition].hour) {
        return 1;
    } else {
        return 0;
    }
}

void returnTime(Date* date, int position) {
    printf("%d:%d:%d.\n", date[position].hour,date[position].minute,date[position].second);
}

void increaseTime(Date* date, int position, int newSeconds) {
    while(newSeconds >= 3600) {
        newSeconds -= 3600;
        date[position].hour += 1;
    }

    while(newSeconds < 3600 && newSeconds >= 60) {
        if(date[position].minute < 60) {
            date[position].minute += 1;
        } else {
            date[position].hour += 1;
            date[position].minute = 0;
        }
        newSeconds -= 60;
    }

    date[position].second += newSeconds;
    if(date[position].second >= 60) {
        date[position].second -= 60;
        if(date[position].minute < 59) {
            date[position].minute += 1;
        } else {
            date[position].minute = 0;
            date[position].hour += 1;
        }
    }
}

void decreaseTime(Date* date, int position, int newSeconds) {
    while(newSeconds >= 3600) {
        if(date[position].hour > 0) {
            date[position].hour -= 1;
            newSeconds -= 3600;
        } else {
            date[position].minute = 0;
            date[position].second = 0;
            return;
        }
    }

    while(newSeconds >= 60) {
        if(date[position].minute > 0) {
            date[position].minute -= 1;
        } else if(date[position].hour > 0) {
            date[position].hour -= 1;
            date[position].minute = 59;
        } else {
            date[position].second = 0;
            return;
        }
        newSeconds -= 60;
    }

    if(date[position].second >= newSeconds) {
        date[position].second -= newSeconds;
    } else {
        int deficit = newSeconds - date[position].second;
        if(date[position].minute > 0) {
            date[position].minute -= 1;
            date[position].second = 60 - deficit;
        } else if(date[position].hour > 0) {
            date[position].hour -= 1;
            date[position].minute = 59;
            date[position].second = 60 - deficit;
        } else {
            date[position].second = 0;
        }
    }
}




#ifndef PRACTICEFILE_H
#define PRACTICEFILE_H

/*
Questão 03
Implemente um TAD Hora utilizando ponteiros para representar uma hora específica do dia,
armazenando horas, minutos e segundos como inteiros. O TAD deve incluir uma função de criação
para alocar dinamicamente uma hora e inicializar seus valores, realizando validação para garantir
que cada campo seja válido e, em caso de valores inválidos, atribuindo zero, e uma função de
destruição para liberar a memória alocada. Além disso, implemente funções setters para alterar cada
campo da hora, realizando validação dos valores antes de atribuí-los, e funções getters para acessar
os valores de horas, minutos e segundos. O TAD deve também conter uma função para avançar o
tempo em uma quantidade de segundos especificada, considerando sempre o intervalo de um dia,
uma função para comparar dois horários, retornando verdadeiro se forem iguais e falso caso
contrário, e uma função para retornar a hora no formato h:m:s. Adicionalmente, implemente funções
inc e dec para respectivamente aumentar ou diminuir a hora em um segundo, ajustando minutos e
horas conforme necessário. Por fim, escreva um programa que utilize e teste todas as operações do
TAD Hora.
*/

typedef struct {
     int second;
     int minute;
     int hour;
}Date;

Date* realocateMemory(int, Date*);
void releaseMemory(Date*);
int setSecond(int, Date*, int);
int setMinute(int, Date*, int);
int setHour(int, Date*, int);
int getSecond(int, Date*);
int getMinute(int, Date*);
int getHour(int, Date*);
int compareHours(int, int, Date*);
void returnTime(Date*, int);
void increaseTime(Date*, int, int);
void decreaseTime(Date*, int, int);


void whereThingsHappen();

#endif



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PracticeFile.h"


void whereThingsHappen() {
    int currentSize = 1;
    Date* date = (Date*)malloc(sizeof(Date*) * currentSize);
    if(!date) {
        exit(1);
    }
    
    setSecond(30, date, currentSize - 1);
    setMinute(20, date, currentSize - 1);
    setHour(10, date, currentSize - 1);
    printf("\nHour:%d\t",getHour(currentSize - 1, date));
    printf("\nMinute:%d\t",getMinute(currentSize - 1, date));
    printf("\nSecond:%d\t",getSecond(currentSize - 1, date));
    currentSize++;
    Date* secondDate = realocateMemory(currentSize, date);
    if(!secondDate) {
        exit(1);
    }
    date = secondDate;
    setSecond(50, date, currentSize - 1);
    setMinute(47, date, currentSize - 1);
    setHour(30, date, currentSize - 1);
    printf("\nHour:%d\t",getHour(currentSize - 1, date));
    printf("\nMinute:%d\t",getMinute(currentSize - 1, date));
    printf("\nSecond:%d\t",getSecond(currentSize - 1, date));
    
    int result = compareHours(0, 1, date);
    if (result) {
        printf("\nHoras são iguais!\n");
    } else {
        printf("\nHoras são diferentes!\n");
    }

    returnTime(date, currentSize - 1);
    increaseTime(date, currentSize - 1, 5000);
    printf("New time:\n");
    returnTime(date, currentSize - 1);
    decreaseTime(date, currentSize - 1, 300);
    returnTime(date, currentSize - 1);
    releaseMemory(date);

}

int main() {

    whereThingsHappen();

    return 0;
}
