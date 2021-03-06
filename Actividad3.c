/*
Instituto Tecnologico de Costa Rica - Sede Central
Escuela de Computacion - Estructuras de Datos
Profesor: Esteban Arias
Actividad 3

Alejandro Pacheco Quesada - 2015171007
Randall Moya Madrigal - 2015183025

Fecha de entrega: 18-3-16
I Semestre, 2016

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Alien_t.h"

alien * add_Alien(alien *lista, const char *name, int ID, const char *esp);
planetas * add_Planeta(planetas *lista, const char *name, int code, char water, char oxigen);
idioma * add_idioma(idioma *lista, const char *name, char type, int symbols);
void get_Datos(alien*listaA,planetas*listaP,idioma*listaI);

int main(){
	
	alien *lista_alien;
	planetas *lista_planetas;
	idioma *lista_idiomas;
	

	lista_alien = add_Alien(lista_alien, "Superman", 80, "Kryptonian");
	lista_planetas = add_Planeta(lista_planetas, "Krypton", 78452, 'Y', 'N');
	lista_idiomas = add_idioma(lista_idiomas, "Ingles", '9', 26);


	get_Datos(lista_alien, lista_planetas, lista_idiomas);

	
	lista_alien->planetas = lista_planetas;
	lista_alien->idiomas = lista_idiomas;

	printf("Idioma que habla el alien: %s\n", lista_alien->idiomas->nombre);
	printf("Planeta donde vive el alien: %s\n", lista_alien->planetas->nombre);

return 1;
}

//Declaracion de las funciones//
alien * add_Alien(alien *lista, const char *name, int ID, const char *esp){
	
	lista = malloc(sizeof(alien));
	strcpy(lista->nombre, name);
	lista->id = ID;
	lista->especie = malloc(strlen(esp));
	strcpy(lista->especie, esp);

	return lista;

}

planetas * add_Planeta(planetas *lista, const char *name, int code, char water, char oxigen){

	lista = malloc(sizeof(planetas));
	strcpy(lista->nombre, name);
	lista->star_wars_code = code;
	lista->agua = water;
	lista->oxigeno = oxigen;

	return lista;
	
	
}

idioma * add_idioma(idioma *lista, const char *name, char type, int symbols){

	lista = malloc(sizeof(idioma));
	strcpy(lista->nombre, name);
	lista->tipo = type;
	lista->simbolos = symbols;

	return lista;
}


void get_Datos(alien*listaA,planetas*listaP,idioma*listaI){
	printf("Alien: \n");
	printf("Nombre: %s\n",listaA->nombre);
	printf("ID: %d\n",listaA->id);
	printf("Especie: %s\n",listaA->especie);
	printf("\n");
	
	printf("Planeta: \n");
	printf("Nombre: %s\n",listaP->nombre);
	printf("Star wars code: %d\n",listaP->star_wars_code);
	printf("Agua?: %c\n",listaP->agua);
	printf("Oxigeno?: %c\n",listaP->oxigeno);
	printf("\n");

	printf("Idioma: \n");
	printf("Nombre: %s\n",listaI->nombre);
	printf("Tipo: %c\n",listaI->tipo);
	printf("Simbolos: %d\n",listaI->simbolos);
	printf("\n");
	
}



