#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct alien_t{
	char nombre[30];
	int id;
	char especie[20];
	struct planetas_t *planetas;
	struct idiomas_t *idiomas;
	struct alien_t *siguiente;
	}alien;
typedef struct planetas_t{
	char nombre[30];
	int star_wars_code;
	char agua;
	char oxigeno;
	struct planetas_t *siguiente;
	}planetas;
typedef struct idiomas_t{
	char nombre[30];
	char tipo;
	int simbolos;
	struct idiomas_t *siguiente;
	struct planetas_t *planetas;
	}idioma;

main(){
	alien *lista_aliens;	
	lista_aliens=malloc(sizeof(alien));
	strcpy(lista_aliens->nombre,"Alien1:Superman");
	lista_aliens->id=40;
	strcpy(lista_aliens->especie,"Kryponiano");

	printf("%s\n",lista_aliens->nombre);
	printf("%d\n",lista_aliens->id);
	printf("%s\n",lista_aliens->especie);	
return 1;
}

