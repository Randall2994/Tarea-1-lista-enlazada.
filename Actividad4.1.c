#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Structs.h"

void insertar_A(alien *head_alien);
void imp_A(alien *head_alien);
void insertar_A_O(alien*head_alien);

main(){
    alien *head_alien=malloc(sizeof(alien));
    strcpy(head_alien->nombre,"Kal EL");
    head_alien->id=23445;
    head_alien->especie=malloc(strlen("Kryptoniano"));
    strcpy(head_alien->especie,"Kryptoniano");
    insertar_A_O(head_alien);
    
    imp_A(head_alien);
}

void insertar_A_O(alien*head_alien){
    char _especie[30];
    alien *nuevo_nodo;
    alien*tmp;
    nuevo_nodo=malloc(sizeof(alien));
    tmp=head_alien;
    printf("%s","Digite un nombre: ");
    scanf("%s",nuevo_nodo->nombre);
    printf("%s","Digite un ID: ");
    scanf("%d",&nuevo_nodo->id);
    printf("%s","Digite el tipo de especie: ");
    scanf("%s",_especie);
    nuevo_nodo->especie=malloc(strlen(_especie));
    nuevo_nodo->especie=_especie;
    if(nuevo_nodo->id>tmp->id){
        while(tmp->siguiente && tmp->siguiente->id<=nuevo_nodo->id){
            tmp=tmp->siguiente;  
            
        }
        nuevo_nodo->siguiente = tmp->siguiente;
        tmp->siguiente = nuevo_nodo;
    }
}   
    
  

void insertar_A(alien *head_alien){
    char _especie[30];
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
    scanf("%s",_especie);
    tmp->siguiente->especie=malloc(strlen(_especie));
    tmp->siguiente->especie=_especie;
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
