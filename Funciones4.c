#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Structs.h"

alien *root = NULL;


void imp_A();
void insertar_A_O(alien*head_alien);
void borrar_A(alien *head_alien);
void consultar_ID(alien *head_alien);
alien * consultar_Nombre(alien *head_alien);

void add_planeta(alien *head_alien);
void insertar_P(planeta *head_planeta);
void printpla(planeta *head_planet);

void add_idioma(alien *head_alien);
void insertar_I(idioma *head_idioma);
void printId(idioma *head_idioma);

void menu();


void insertar_A_O(alien*head_alien){

    alien *nuevo_nodo;
    alien *tmp;
    nuevo_nodo = malloc(sizeof(alien));
    tmp = head_alien;
    printf("%s","Digite un nombre: ");
    scanf("%s",nuevo_nodo->nombre);
    printf("%s","Digite un ID: ");
    scanf("%d",&nuevo_nodo->id);
    printf("%s","Digite el tipo de especie: ");
    scanf("%s",nuevo_nodo->especie);
    
    nuevo_nodo->planeta = malloc(sizeof(planeta));
    nuevo_nodo->idioma = malloc(sizeof(idioma));
    
    printf("Digite el planeta natal del alien: ");
    scanf("%s",nuevo_nodo->planeta->nombre);

    printf("Tiene agua? Y-N: ");
    
    getchar();
    nuevo_nodo->planeta->agua = getchar();
    printf("Hay oxigeno? Y-N: ");
    
    getchar();
    nuevo_nodo->planeta->oxigeno = getchar();
    printf("Digite el Star Wars code del planeta: ");
    scanf("%d", &nuevo_nodo->planeta->starwards_code);
    
    printf("Digite el idioma natal del alien: ");
    scanf("%s",nuevo_nodo->idioma->nombre);
    printf("Cantidad de simbolos?: ");
    scanf("%d",&nuevo_nodo->idioma->simbolos);
    printf("Tipo: ");
    scanf("%s",nuevo_nodo->idioma->tipo);
    

    
    
    if(tmp == NULL){
        root = nuevo_nodo;
    }
    else if(tmp->siguiente == NULL){
        if( nuevo_nodo->id <= tmp->id){
                nuevo_nodo->siguiente = tmp;
                root = nuevo_nodo;
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
            
            while(tmp->siguiente != NULL && nuevo_nodo->id >= tmp->siguiente->id){
                tmp = tmp->siguiente;
            }
                
            
            nuevo_nodo->siguiente = tmp->siguiente;
            tmp->siguiente = nuevo_nodo;  

        }
    }
          
}

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

void borrar_A(alien *head_alien){
    char consulta[30];
    printf("Digite el nombre del alien que desea borrar: ");
    scanf("%s", consulta);
    
    alien *tmp = head_alien;
    char flag = 'F';
    
    while(tmp->siguiente!=NULL){
        if(strcmp(tmp->siguiente->nombre,consulta)==0){
            flag = 'V';
            break;
        }
        else{
            tmp = tmp->siguiente;
        }
    }
    
    if(flag=='V'){
        if (tmp->siguiente->siguiente!=NULL){
            alien *aux;
            aux = tmp->siguiente->siguiente;
            free(tmp->siguiente);
            tmp->siguiente = aux;
            
        }
        else{
            free(tmp->siguiente);
            tmp->siguiente = NULL;
        }
    }
    else{
        printf("El alien no existe \n");
    }
}


void consultar_ID(alien *head_alien){
    int consulta;
    printf("Digite el ID del alien a buscar: ");
    scanf("%d", &consulta);
    
    alien *tmp = head_alien;
    
    char flag = 0;
    while(tmp!=NULL){
        if(tmp->id == consulta){
            printf("Se ha encontrado el alien: \n");
            printf("%s \n", tmp->nombre);
            printf("%d \n", tmp->id);
            printf("%s \n", tmp->especie);
            
            flag = 1;
            break;
        }
        else{
            tmp = tmp->siguiente;
        }
    }
    if(flag==0){
        printf("No se ha encontrado el alien\n");
    }
    
}

alien * consultar_Nombre(alien *head_alien){
    char consulta[30];
    printf("Digite el nombre del alien que desea buscar: ");
    scanf("%s", consulta);
    
    alien *tmp = head_alien;
    
    char flag = 0;
    while(tmp!=NULL){
        if(strcmp(tmp->nombre,consulta)==0){
            printf("Se ha encontrado el alien: ");
            printf("%s \n", tmp->nombre);
            printpla(tmp->planeta);
            printId(tmp->idioma);
            flag = 1;
            return tmp;
            break;
        }
        else{
            tmp = tmp->siguiente;
        }
    }
    if(flag==0){
        printf("No se ha encontrado el alien \n");
        return NULL;
    }
    
}


void add_planeta(alien *head_alien){
    alien *current = consultar_Nombre(head_alien);
    if(current!=NULL){
        insertar_P(current->planeta);
    }

}

void insertar_P(planeta *head_planeta){
    
    planeta *tmp = head_planeta;
    while(tmp->siguiente!=NULL){
        tmp = tmp->siguiente;
    }
    tmp->siguiente = malloc(sizeof(planeta));
    printf("Digite el nombre del planeta: ");
    scanf("%s", tmp->siguiente->nombre);
    printf("Tiene agua? 'Y'/'N': ");
    getchar();
    tmp->siguiente->agua = getchar();
    printf("Tiene oxigeno? 'Y'/'N': ");
    getchar();
    tmp->siguiente->oxigeno = getchar();
    printf("Digite el Star Wars code del planeta: ");
    scanf("%d",&tmp->siguiente->starwards_code);
}

void printpla(planeta *head_planet){
    planeta *tmp = head_planet;
    printf("Los nombres de los planetas que ha visitado el alien son: \n");
    while(tmp!=NULL){
        printf("%s \n", tmp->nombre);
        tmp = tmp->siguiente;
    }
}

void add_idioma(alien *head_alien){
    alien *current = consultar_Nombre(head_alien);
    if(current!=NULL){
        insertar_I(current->idioma);
    }
    
}


void insertar_I(idioma *head_idioma){
    idioma *tmp = head_idioma;
    while(tmp->siguiente!=NULL){
        tmp = tmp->siguiente;
    }
    tmp->siguiente = malloc(sizeof(idioma));
    printf("Digite el idioma: ");
    scanf("%s",tmp->siguiente->nombre);
    printf("Cantidad de simbolos?: ");
    scanf("%d",&tmp->siguiente->simbolos);
    printf("Tipo: ");
    scanf("%s",tmp->siguiente->tipo);
    
}

void printId(idioma *head_idioma){
    idioma *tmp = head_idioma;
    printf("Los nombres de los idiomas que sabe el alien son: \n");
    while(tmp!=NULL){
        printf("%s \n", tmp->nombre);
        tmp = tmp->siguiente;
    }
}

void menu(){
    alien *tmp = root;
    printf("1. Insertar un alien\n");
    printf("2. Consultar un alien por ID\n");
    printf("3. Borrar un alien\n");
    printf("4. Agregar un planeta a un alien\n");
    printf("5. Agregar un idioma a un alien\n");
    printf("6. Imprimir lista\n");
    
    int opcion;
    printf("R: ");
    scanf("%d", &opcion);
    if(opcion==1){
        insertar_A_O(tmp);
        
        menu();
        
    }
    else if(opcion==2){
        consultar_ID(tmp);
        printpla(tmp->planeta);
        printId(tmp->idioma);
        menu();
        
    }
    else if(opcion==3){
        borrar_A(tmp);
        menu();
    }
    else if(opcion==4){
        add_planeta(tmp);
        menu();
        
    }
    else if(opcion==5){
        add_idioma(tmp);
        menu();
    }
    else if(opcion==6){
        imp_A();
        menu();
    }
    else{
        printf("Inserta una opcion valida\n");
        menu();
    }
}
