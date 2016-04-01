/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Structs.h
 * Author: randall
 *
 * Created on March 31, 2016, 1:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct planetas_t{
    char nombre[30];
    int starwards_code;
    char agua;
    char oxigeno;
    struct planetas_t *siguiente;
    
}planeta;


typedef struct idiomas_t{
    char nombre[30];
    char tipo;
    int simbolos;
    struct idiomas_t * siguiente;
    struct planetas_t *planeta;
}idioma;

typedef struct alien_t{
    char nombre[30];
    int id;
    char *especie;
    struct planetas_t *planeta;
    struct idiomas_t *idioma;
    struct alien_t *siguiente;
}alien;

