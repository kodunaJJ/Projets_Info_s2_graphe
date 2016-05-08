#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

Liste creer_liste(void) {
	return NULL;
}

int est_vide(Liste l) {
	return !l;
}

void visualiser_liste(Liste l) {
	Liste p;
	for(p=l; !est_vide(p); p=p->suiv) {
		affiche(&p->val_carte);
	}
}

Liste ajout_tete(CARTE c, Liste l) {
	Liste p;
	p = calloc(1,sizeof(*p));
	if(p==NULL) return NULL;
	p->val_carte = c;
	p->suiv = l;
	return p;
}

Liste supprimer_tete(Liste l) {
	if(!est_vide(l)) {
		Liste p;
		p=l->suiv;
		free(l);
		return p;
	}
	return NULL;
}

Liste ajout_queue(CARTE c, Liste l) {
	Liste p,p1;
	if(est_vide(l)) {
		return ajout_tete(c,l);
	}
	p1=l;

	while(!est_vide(p1->suiv)) {
		p1=p1->suiv;
	}
	p=calloc(1,sizeof(*p));
	p->suiv=NULL;
	p->val_carte=c;
	p1->suiv=p;
	return l;
	
}

Liste supprimen(int n, Liste l) {
	Liste p,p1;
	if(est_vide(l)) return NULL;
	int i=1;
	int nbr=1;
	p1=l;
	while(!est_vide(p1->suiv)) {
		nbr++;
		p1=p1->suiv;
	}
	p1=l;
	if(n==1) {
		return supprimer_tete(l);
	}
	else if(n<nbr) {
			while(i<(n-1)) {
				p1=p1->suiv;
				i++;
			}
			p=p1->suiv;
			p1->suiv=p->suiv;
			free(p);
			return l;
		}
		else if (n==nbr) {
				while(i<(n-1)) {
					p1=p1->suiv;
					i++;
				}
				free(p1->suiv);
				p1->suiv = NULL;
				return l;
			}
			else {
				puts("Erreur n trop grand");
				return l;
				}
}

Liste concat(Liste l1, Liste l2) {
	if(est_vide(l2)) return l1;
	if(est_vide(l1)) return l2;
	Liste p1,p2;
	p1=l1;
	p2=l2;
	while(!est_vide(p1->suiv)) {
		p1=p1->suiv;
	}
	p1->suiv=p2;
	return l1;
}

Liste copie(Liste l) {
	if (est_vide(l)) return creer_liste();
	Liste lcop,p;
	lcop=creer_liste();
	p=l;
	while(!est_vide(p->suiv)) {
		lcop=ajout_queue(p->val_carte, lcop);
		p=p->suiv;
	}
	lcop=ajout_queue(p->val_carte, lcop);
	return lcop;	
}


