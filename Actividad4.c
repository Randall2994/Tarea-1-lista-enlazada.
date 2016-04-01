#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Structs.h"

void insertar_A(alien *head_alien);
void imp_A(alien *head_alien);


main(){
    alien *head_alien=malloc(sizeof(alien));
    strcpy(head_alien->nombre,"Kal EL");
    head_alien->id=12345;
    head_alien->especie=malloc(strlen("Kryptoniano"));
    strcpy(head_alien->especie,"Kryptoniano");
    insertar_A(head_alien);
    insertar_A(head_alien);
    imp_A(head_alien);
}

void insertar_A(alien *head_alien){
 
    alien *tmp;
    tmp =head_alien;
    while(tmp->siguiente!=NULL){
        tmp=tmp->siguiente;
    }
    tmp->siguiente=malloc(sizeof(alien));
    
    printf("%s","Digite un nombre: ");
    scanf("%s",tmp->siguiente->nombre);
    printf("%s","Digite un ID: ");
    scanf("%d",&tmp->siguiente->id);
    printf("%s","Digite el tipo de especie: ");    
    scanf("%s",tmp->siguiente->especie);
}

void imp_A(alien *head_alien){
    alien *tmp;
    tmp = head_alien;
    while(tmp!=NULL){
        printf("Nombre: %s \n", tmp->nombre);
        printf("Id: %d \n", tmp->id);
        printf("Especie: %s \n", tmp->especie);
        tmp = tmp->siguiente;
    }
}