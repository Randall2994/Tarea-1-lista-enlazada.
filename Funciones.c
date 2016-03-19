include "Alien_t.h"
include <string.h>

//Funciones que guardan los datos//
void alien add_Alien(alien *lista ,char nombre, int id, char especie);
void add_Planeta(planetas *lista, char nombre, int code, char agua, char oxigen);
void add_idioma(idioma *lista, char nombre, char tipo, int simbolos);
//Funcion para imprimir datos//
void get_Datos(alien*listaA,planeta*listaP,idioma*listaI);

//Declaracion de las funciones//
void add_Alien(alien *lista, char name, int ID, char esp){
	
	lista = malloc(sizeof(alien));
	strcpy(lista->nombre, name);
	lista->id = ID;
	lista->especie = malloc(strlen(esp));
	strcpy(lista->especie, esp);

}

void add_Planeta(planetas *lista, char name, int code, char water, char oxigen){

	lista = malloc(sizeof(planetas));
	strcpy(lista->nombre, name);
	lista->star_wars_code = code;
	lista->agua = water;
	lista->oxigeno = oxigen;
	
	
}

void add_idioma(idioma *lista, char name, char type, int symbols){

	lista = malloc(sizeof(idioma));
	strcpy(lista->nombre, name);
	lista->tipo = type;
	lista->simbolos = symbols;

}

void get_Datos(alien*listaA,planeta*listaP,idioma*listaI){
	printf("%s\n",listaA->nombre);
	printf("%d\n",listaA->id);
	printf("%s\n",listaA->especie);

	printf("%s\n",listaP->nombre);
	printf("%d\n",listaP->star_wars_code);
	printf("%c\n",listaP->agua);
	printf("%c\n",listaP->oxigeno);

	printf("%d\n",listaI->nombre);
	printf("%c\n",listaI->tipo);
	printf("%d\n",listaI->simbolos);
}







