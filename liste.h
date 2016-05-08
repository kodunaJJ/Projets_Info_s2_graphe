
#ifndef _Liste
#define _Liste

#include "carte.h"

struct cellule {
	CARTE val_carte;
	struct cellule* suiv;
};
typedef struct cellule Maillon;
typedef Maillon* Liste;

Liste creer_liste(void);

int est_vide(Liste l);

void visualiser_liste(Liste l);

Liste ajout_tete(CARTE c, Liste l);

Liste supprimer_tete(Liste l) ;

Liste ajout_queue(CARTE c, Liste l);

Liste supprimen(int n, Liste l);

Liste concat(Liste l1, Liste l2);

Liste copie(Liste l);

#endif
