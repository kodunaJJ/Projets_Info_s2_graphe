#include <stdio.h>

// structure de l'arc

typedef struct{
	unsigned int num_arc; // numéro de l'arc
	double poids;    //poid de l'arc
	unsigned int SA; // sommet d'arrivé 
	unsigned int SD; // sommet de départ
	}*ARC;

// structure du noeud 

typedef struct{

	unsigned int numero; // numéro de la station
	double lat;	     // lattitude	
	double longit;	     // longitude						
	char nom_ligne;      
	char nom_station;
	}*NOEUD;

// structure graphe

typedef struct{

	unsigned int nX; //nombre de noeud dans le graphe
	unsigned int nA; // nombre d'arc dans le graphe
	liste* arc;	 // liste des arcs qui partent de la station	
	}*GRAPHE;

// prototypes fonctions

GRAPHE nouveau_graphe(unsigned int nX, unsigned int nA);

void affiche_graphe(GRAPHE g);

void detruit_graphe(GRAPHE g);

void graphe_ecrire_poids_arc(GRAPHE g, unsigned int SD, unsigned int SA, double val);

double graphe_lire_poids_arc(GRAPHE g, unsigned int SD, unsigned int SA, double val);




GRAPHE ajouter_arc(GRAPHE g, double poids, unsigned int SD, unsigned int SA, unsigned int num_arc);

GRAPHE lit_graphe(char* fichier);

double graphe_pcc(GRAPHE g, unsigned int SD, unsigned int SA);

