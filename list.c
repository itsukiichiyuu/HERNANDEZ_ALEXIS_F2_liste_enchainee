#include "list.h"

void initialisation (Liste * liste)
{
  liste->debut = NULL;
  liste->fin = NULL;
  liste->taille = ZERO;
}

/* insertion dans une liste vide */
int insListeVide (Liste * liste, point pts){

  Element *nouveau_element;

  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -UN;

  nouveau_element->pts.x=pts.x;
  nouveau_element->pts.y=pts.y;
  nouveau_element->pts.z=pts.z;
  nouveau_element->suivant = NULL;
  liste->debut = nouveau_element;
  liste->fin = nouveau_element;
  liste->taille++;
  return ZERO;
}

/* insertion au début de la liste */
int insDebutListe (Liste * liste, point pts){

 Element *nouveau_element;

  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -UN;
  nouveau_element->pts.x=pts.x;
  nouveau_element->pts.y=pts.y;
  nouveau_element->pts.z=pts.z;
  nouveau_element->suivant = liste->debut;
  liste->debut = nouveau_element;
  liste->taille++;
  return ZERO;
}

/*insertion à la fin de la liste */
int insFinListe (Liste * liste, Element * courant, point pts){

  Element *nouveau_element;

  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -UN;

  nouveau_element->pts.x=pts.x;
  nouveau_element->pts.y=pts.y;
  nouveau_element->pts.z=pts.z;
  courant->suivant = nouveau_element;
  nouveau_element->suivant = NULL;

  liste->fin = nouveau_element;

  liste->taille++;
  return ZERO;
}

/* insertion à la position demandée */
int insListe (Liste * liste, point pts, int pos){

  if (liste->taille < DEUX)
    return -UN;
  if (pos < UN || pos >= liste->taille)
    return -UN;

  Element *courant;
  Element *nouveau_element;

  int i;

  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -UN;

  nouveau_element->pts.x=pts.x;
  nouveau_element->pts.y=pts.y;
  nouveau_element->pts.z=pts.z;

  courant = liste->debut;
  for (i = UN; i < pos; ++i)
    courant = courant->suivant;

  if (courant->suivant == NULL)
    return -UN;


  nouveau_element->suivant = courant->suivant;
  courant->suivant = nouveau_element;
  liste->taille++;
  return 0;
}

/* suppression au début de la liste */
int suppDebut (Liste * liste){
  if (liste->taille == ZERO)
    return -UN;
  Element *supp_element;
  supp_element = liste->debut;
  liste->debut = liste->debut->suivant;
  if (liste->taille == UN)
    liste->fin = NULL;
  free (supp_element);
  liste->taille--;
  return 0;
}

/* supprimer un element après la position demandée */
int suppDansListe (Liste * liste, int pos){
  if (liste->taille <= UN || pos < UN || pos >= liste->taille)
    return -UN;
  int i;
  Element *courant;
  Element *supp_element;
  courant = liste->debut;

  for (i = UN; i < pos; ++i)
    courant = courant->suivant;

  supp_element = courant->suivant;
  courant->suivant = courant->suivant->suivant;
  if(courant->suivant == NULL)
          liste->fin = courant;
  free (supp_element);
  liste->taille--;
  return ZERO;
}

/* affichage de la liste */
void affiche (Liste * liste){
  Element *courant;
  courant = liste->debut;
  while (courant != NULL){
      printf ("%p - x:%d,y:%d,z:%d\n", courant, courant->pts.x,courant->pts.y,courant->pts.z);
      courant = courant->suivant;
  }
}

/* detruire la liste */
void detruire (Liste * liste){
  while (liste->taille > ZERO)
    suppDebut (liste);
}

int menu (Liste *liste,int *k){
  int choix;
  printf("********** MENU **********\n");
  if (liste->taille == ZERO){
    printf ("1. Ajout du 1er element\n");
    printf ("2. Quitter\n");
  }else if(liste->taille == UN || *k == UN){
    printf ("1. Ajout au debut de la liste\n");
    printf ("2. Ajout a la fin de la liste\n");
    printf ("4. Suppression au debut de la liste\n");
    printf ("6. Detruire la liste\n");
    printf ("7. Quitter\n");
  }else {
    printf ("1. Ajout au debut de la liste\n");
    printf ("2. Ajout a la fin de la liste\n");
    printf ("3. Ajout apres la position specifie\n");
    printf ("4. Suppression au debut de la liste\n");
    printf ("5. Suppression apres la position specifie\n");
    printf ("6. Detruire la liste\n");
    printf ("7. Quitter\n");
  }
  printf ("\n\nFaites votre choix : ");
  scanf ("%d", &choix);
  getchar();
  if(liste->taille == ZERO && choix == DEUX)
    choix = 7;
  return choix;
}
/* -------- FIN liste_function.h --------- */
