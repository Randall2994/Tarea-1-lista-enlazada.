
typedef struct alien_t{
	char nombre[30];
	int id;
	char *especie;
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

