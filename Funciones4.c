#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Structs.h"

alien *root = NULL;

void crear_Alien(alien*head_alien);
void insertar_A(alien *head_alien);
void imp_A();
void insertar_A_O(alien*head_alien);

main(){
    
    
    insertar_A_O(root);
    insertar_A_O(root);
    insertar_A_O(root);
    insertar_A_O(root);
    
    imp_A();
}
/*
void crear_Alien(alien*head_alien){
  
    alien *nuevo_nodo;
    nuevo_nodo=malloc(sizeof(alien));
    printf("%s","Digite un nombre: ");
    scanf("%s",nuevo_nodo->nombre);
    printf("%s","Digite un ID: ");
    scanf("%d",nuevo_nodo->id);
    printf("%s","Digite el tipo de especie: ");
*/
    

void insertar_A_O(alien*head_alien){

    alien *nuevo_nodo;
    alien *tmp;
    nuevo_nodo=malloc(sizeof(alien));
    tmp=head_alien;
    printf("%s","Digite un nombre: ");
    scanf("%s",nuevo_nodo->nombre);
    printf("%s","Digite un ID: ");
    scanf("%d",&nuevo_nodo->id);
    printf("%s","Digite el tipo de especie: ");
    scanf("%s",nuevo_nodo->especie);

    
    
    if(tmp == NULL){
        root = nuevo_nodo;
    }
    else if(tmp->siguiente == NULL){
        if( nuevo_nodo->id <= tmp->id){
                nuevo_nodo->siguiente = tmp;
                head_alien = nuevo_nodo;
        }
        else{
                tmp->siguiente = nuevo_nodo;      
         }
    }
    
    else{
      
        if( nuevo_nodo->id <= tmp->id){
            
            nuevo_nodo->siguiente = tmp;
            root = nuevo_nodo;
        }
        else{  
            alien *tmp2= NULL;
            while(tmp->siguiente != NULL){
                if( nuevo_nodo->id <= tmp->id){
                    nuevo_nodo->siguiente = tmp;
                    tmp2 = tmp;
                    tmp->siguiente = NULL;                    
                }
                
            }
            if(tmp2->siguiente == NULL){
                tmp2->siguiente = nuevo_nodo;
            }
                 
        }
        
        
             
    }
}
    /**
    
        while(tmp->siguiente && tmp->siguiente->id<=nuevo_nodo->id){
            tmp=tmp->siguiente;  
            
        }
        
        nuevo_nodo->siguiente = tmp->siguiente;
        tmp->siguiente = nuevo_nodo;
    
    **/


    
  
/*
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
  */  
   
    
    


void imp_A(){
    alien *tmp;
    tmp = root;
    while(tmp!=NULL){
        printf("Nombre: %s \n", tmp->nombre);
        printf("Id: %d \n", tmp->id);
        printf("Especie: %s \n", tmp->especie);
        tmp = tmp->siguiente;
    }
}
