/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: randall
 *
 * Created on March 13, 2016, 12:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Structs.h"


typedef struct nodo_t{
    int valor;
    struct nodo_t *siguiente;
}nodo;

void insertar(nodo *h, int v,);
void printlista(nodo *h);

int main() {

    
    nodo *head = malloc(sizeof(nodo));
    head->valor = 8;
    insertar(head, 4);
    
    insertar(head, 1);
    
    printlista(head);
}

void insertar(nodo *h, int v){
    if(h == NULL){
        h = malloc(sizeof(nodo));
        h->valor = v;
        
    }
    else{
        nodo *tmp;
        tmp = h;
        while(tmp->siguiente!=NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = malloc(sizeof(nodo));
        tmp->siguiente->valor = v;
        
    }

}

void printlista(nodo *h){
    nodo *tmp;
    tmp = h;
    while(tmp!=NULL){
        printf("Nodo: %d \n", tmp->valor);
        tmp = tmp->siguiente;
    }
}