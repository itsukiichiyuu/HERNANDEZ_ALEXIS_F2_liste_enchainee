#include "list.h"


//au lieu d'un entier, on entre un point xyz


int main (void)
{
  char choix;
  point Pt;
  Liste *liste;
  //Element *courant;

  if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
    return -UN;

  //courant = NULL;
  choix = 'o';

  initialisation (liste);
  int pos, k;

  while (choix != 7){
      choix = menu (liste, &k);
      switch (choix){
        case UN:
          printf ("Entrez un element : \n");
          printf ("Entrez le x : ");
          scanf ("%d", &Pt.x);
          printf ("Entrez le y : ");
          fflush(stdin);
          scanf ("%d", &Pt.y);
          printf ("Entrez le z : ");
          fflush(stdin);
          scanf ("%d", &Pt.z);

          if (liste->taille == ZERO)
            insListeVide(liste, Pt);
          else
            insDebutListe (liste, Pt);
          printf ("%d elements:debx=%d,deby=%d,debz=%d,finx=%d,finy=%d,finz=%d\n", liste->taille,
                  liste->debut->pts.x,liste->debut->pts.y,liste->debut->pts.z,
                  liste->fin->pts.x,liste->fin->pts.y,liste->fin->pts.z);
          affiche (liste);
          break;
        case DEUX:
          printf ("Entrez un element : \n");
          printf ("Entrez le x : ");
          scanf ("%d", &Pt.x);
          printf ("Entrez le y : ");
          scanf ("%d", &Pt.y);
          printf ("Entrez le z : ");
          scanf ("%d", &Pt.z);
          insFinListe (liste, liste->fin, Pt);
          printf ("%d elements:debx=%d,deby=%d,debz=%d,finx=%d,finy=%d,finz=%d\n", liste->taille,
                  liste->debut->pts.x,liste->debut->pts.y,liste->debut->pts.z,
                  liste->fin->pts.x,liste->fin->pts.y,liste->fin->pts.z);
          affiche (liste);
          break;
        case 3:
          printf ("Entrez un element : \n");
          printf ("Entrez le x : ");
          scanf ("%d", &Pt.x);
          printf ("Entrez le y : ");
          scanf ("%d", &Pt.y);
          printf ("Entrez le z : ");
          scanf ("%d", &Pt.z);;
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < UN || pos > liste->taille);
          getchar ();
          if (liste->taille == UN || pos == liste->taille){
              k = UN;
              printf("-----------------------------------------------\n");
              printf("Insertion echouée.Utilisez le menu {1|2}  \n");
              printf("-----------------------------------------------\n");
              break;
     }
          insListe (liste, Pt, pos);
          printf ("%d elements:debx=%d,deby=%d,debz=%d,finx=%d,finy=%d,finz=%d\n", liste->taille,
                  liste->debut->pts.x,liste->debut->pts.y,liste->debut->pts.z,
                  liste->fin->pts.x,liste->fin->pts.y,liste->fin->pts.z);
          affiche (liste);
          break;
        case 4:
          suppDebut (liste);
          if (liste->taille != ZERO)
          printf ("%d elements:debx=%d,deby=%d,debz=%d,finx=%d,finy=%d,finz=%d\n", liste->taille,
                  liste->debut->pts.x,liste->debut->pts.y,liste->debut->pts.z,
                  liste->fin->pts.x,liste->fin->pts.y,liste->fin->pts.z);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 5:
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < UN || pos > liste->taille);
          getchar ();
          suppDansListe (liste, pos);
          if (liste->taille != ZERO)
          printf ("%d elements:debx=%d,deby=%d,debz=%d,finx=%d,finy=%d,finz=%d\n", liste->taille,
                  liste->debut->pts.x,liste->debut->pts.y,liste->debut->pts.z,
                  liste->fin->pts.x,liste->fin->pts.y,liste->fin->pts.z);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 6:
          detruire (liste);
          printf ("la liste a ete detruite : %d elements\n", liste->taille);
          break;
      }
  }
  return ZERO;
}
