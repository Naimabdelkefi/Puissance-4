#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
   void dessine(int *tableau);
   int jeton (int colonne,int *tableau);
   int verifgagnant(int *tableau,int a);
   int ordi(int *tableau,int *colpleine);
   int otejeton (int colonne,int *tableau);

int main(void)
{
int rejouez=1;
while (rejouez==1)
        {
        int tableau[8][7]={0};
        char joueur1[100];
        char joueur2[100]="l'ordinateur";
        char joueurgagnant[100];
        int gagnant=0,i,j,tour=1,colonne,ligneremplie,mode,nbcoups=0;
        int colpleine[8]={0};
        srand(time(NULL));
        const long MAX = 7, MIN = 1,MAX2=2;


        printf("\t\t\t ****PUISSANCE 4****\n\n");
        printf("Choisissez le mode: tapez 1 pour jouer contre l ordi\n");
        printf("ou une autre touche pour jouer entre humain\n");
        scanf("%d",&mode);

        printf("Entrer le prenom du joueur 1: ");
        scanf("%s",joueur1);
        if (mode!=1)
           {joueur2[0]='\0';
           printf("Entrer le prenom du joueur 2: ");
           scanf("%s",joueur2);}
    dessine(*tableau);
        tour=(rand() % (MAX2 - MIN + 1)) + MIN;      // hasard pour le 1er a jouer.
        while(gagnant==0)
                {
                nbcoups=nbcoups+1;
                if (tour==3)
                {tour=1;}
                if (tour==1)
                        {printf(" Au tour de  %s de jouer: choisissez la colonne ou placer le pion.\n",joueur1);}
                if (tour==2)
                        {printf(" Au tour de %s de jouer: ",joueur2);}
                if (mode!=1){printf("choisissez la colonne ou placer le pion.\n");}
                else printf("\n");
                if (tour==2 && mode==1)
                        {
                        //      colonne=ordi(*tableau,*colpleine);
                        }
                else
                {scanf("%d",&colonne);}

                if(colonne<1 || colonne>7){printf("valeur incorrecte: rentrez un chiffre entre 1 et 7\n");}
                else if (colpleine[colonne]==6)
                {printf("              ###Colonne pleine, choisissez en une autre.###\n");}

                else
                        {
                        ligneremplie=jeton(colonne,*tableau);
                        tableau[ligneremplie][colonne]=tour;
                                        // on repere les pions par colonnes pour empecher de jouer qd elles sont pleines
                        colpleine[colonne]=colpleine[colonne]+1;
                        gagnant=verifgagnant(*tableau,tour);
                        dessine(*tableau);

                        printf("%d",*colpleine);

                        if (gagnant==1)
                                 {if (tour==1)
                               {strcpy(joueurgagnant,joueur1);}
                                 else if (tour==2)
                               {strcpy(joueurgagnant,joueur2);}

                                printf("Victoire pour %s en %d coups. Bravo a lui!!:\n",joueurgagnant,nbcoups);
                               }
                   tour=tour+1;
                   }
                }

        printf("    Souhaitez-vous rejouez? Si oui tapez 1.\n");
        scanf("%d",&rejouez);
  }
  printf("          Merci d avoir jouer a PUISSANCE 4   \n\n");
                system("PAUSE");
      return 0;
}


  void dessine(int *tableau)
   {}//ca ca marche je l enleve ca fera moin long^^

int jeton (int colonne,int *tableau)
        {int i=1,place=0;
         while (place==0 && i<7)
                {if (tableau[7*i+colonne]==1 || tableau[7*i+colonne]==2)
                        {place=i-1;}
                i=i+1;}
                if (place==0){place=6;}
                return place;
        }
int otejeton (int colonne,int *tableau)
{int i=6,ligneavider=0;
         while (i>0 && ligneavider==0)
                {if (tableau[7*i+colonne]==0 )
                        {i=i-1;}
                else{ligneavider=i;}
                }

return ligneavider;
}

int verifgagnant(int *tableau,int a)
{
return result;                  //pareil je resume
}

int ordi(int *tableau,int *colpleine)
{
int valeur,colonne,ligneremplie,temp;
int i,j,k,l,m;
int tab[7][7][7][7][7]={0};
int grille[7][8], colpleinebis={0};
const long MAX = 7, MIN = 1,MAX2=2;
                                 // on copie les tableaux pour pas les changer et les perdre
for (i=1;i<7;i++)
                {for (j=1;j<7;j++)
                                {grille[i][j]=tableau[7*i+j];}
                //      colpleinebis[i]=*colpleine;
                }
         // a partir de la grille actuelle: trouver ttes les dispositions possibles sur les 5 coups a venir et les evaluer .
for (i=1;i<7;i++)                             // coup 1: l ordi
     {if (colpleine[i]=!6)
       {ligneremplie=jeton(i,*grille);
        grille[ligneremplie][i]=2;
        if(verifgagnant(*grille,2)==1)
            {tab[i][0][0][0][0]=1000;}
        else                                        // si pas gagnant coup 2: l humain
            {for (j=1;j<7;i++)
                {if (colpleine[j]=!6)
                      {ligneremplie=jeton(j,*grille);
                       grille[ligneremplie][j]=1;
                       if(verifgagnant(*grille,1)==1)
                                  {tab[i][0][0][0][0]=-100;}
                       else                        //si pas perdant coup 3:l ordi
                            {for (k=1;k<7;k++)
                                {if (colpleine[k]=!6)
                                     {ligneremplie=jeton(k,*grille);
                                      grille[ligneremplie][k]=2;
                                      if(verifgagnant(*grille,2)==1)
                                          {tab[i][j][k][0][0]=10;}
                                      else           // si pas gagnant coup 4:l humain
                                          {for (l=1;l<7;l++)
                                             {if (colpleine[k]=!6)
                                                {ligneremplie=jeton(k,*grille);
                                                 grille[ligneremplie][k]=1;
                                                 if(verifgagnant(*grille,1)==1)
                                                     {tab[i][j][k][l][0]=-9;}
                                                 else             //si pas perdant coup 5:l ordi
                                                    {for (m=1;m<7;m++)
                                                     {if(colpleine[m]=!6                                 {ligneremplie=jeton(m,*grille);
                                                                                                                                                grille[ligneremplie][m]=2;
                                                                                                                                                if(verifgagnant(*grille,2)==1)
                                         {tab[i][j][k][l][m]=5;}
                                       else
                                          tab[i][j][k][l][m]=1;}                                         otejeton(m,*grille);
                            }} }
                   otejeton(l,*grille);
                    } } }
               otejeton(k,*grille);
                } } }
            otejeton(j,*grille);
           } }}
        otejeton(i,*grille);
        }
// et maintenant on redescend les donnees!!
temp=0;
for (i=1;i<7;i++)
          {for (j=1;j<7;i++)
                 {for (k=1;k<7;k++)
                        {for (l=1;l<7;l++)
                               {for (m=1;m<7;m++)
                                      {tab[i][j][k][l][0]=tab[i][j][k][l][0]+tab[i][j][k][l][m];}
                                tab[i][j][k][0][0]=tab[i][j][k][0][0]+tab[i][j][k][l][0];}
                       tab[i][j][0][0][0]=tab[i][j][0][0][0]+tab[i][j][k][0][0];}
                tab[i][0][0][0][0]=tab[i][0][0][0][0]+tab[i][j][0][0][0];}
       if(tab[i][0][0][0][0]>temp){temp=tab[i][0][0][0][0],colonne=i;}
       else if (tab[i][0][0][0][0]==temp)                              // si egalite on prend au pif
                 {valeur=(rand() % (MAX2 - MIN + 1)) + MIN;
                  if((valeur/2)*2==valeur){temp=tab[i][0][0][0][0],colonne=i;}}
                }
scanf("%d",&temp);
 return colonne;

}
