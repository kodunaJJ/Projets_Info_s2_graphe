#include <stdio.h>




GRAPHE nouveau_graphe(unsigned int nX, unsigned int nA)
{	GRAPHE g;
	g=calloc(1,sizeof(*g));
	g->arc=calloc(nX,sizeof(*g->arc));

}

void detruit_graphe(GRAPHE g)
{free(g);}			

void affiche_graphe(GRAPHE g)
{	int i;
	if (g == NULL)
	{puts("pas de graphe a afficher");}
	else
	{	printf("nombre de sommet: %d\n",g->nX);
		printf("nombre d'arc : %d\n",g->nA);
		for (i=0;i<nX;i++)
		{	printf("sommet numero: %d --> ",i)
			visualiser_liste((g->arc)[i]);
			puts("");
		}
	}
}


void graphe_ecrit_nX(GRAPHE g,unsigned int nX)
{g->nX=nX;}

void graphe_ecrit_nA(GRAPHE g,unsigned int nX)
{g->nA;}

unsigned int lire_nX(unsigned int nX)
{return nX;}

unsigned int lire_nA(unsigned int nA)
{return nA;}


