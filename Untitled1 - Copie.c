
#include <stdio.h>
#include <stdlib.h>
  int grille1[6][7];
  char grille[6][7];/*ce tableau represente une delimitation du nombre de case de la grille*/
  int remplissage[7];/* ce tableau définit le nombre de jeton qu'il y a  dans la colonne..maximum 6.*/

int dansGrille(int x,int y)
  /*la fonction prend 2 entiers x et y et renvoie vrai s'il existe une case de coordonnées(x,y)dans grille.*/
  {
      if ((x>=0)&&(x<=5)&&(y>=0)&&(y<=6))/* x appartient aux six cases d'une colone 0~5
                            y appartient aux septs case d'une ligne 0~6*/
       return 1;
      else return 0;
  }
 /* fonction qui renvoie vrai s'il est possible
  de poser un jeton dans la colonne x, j'utilise un tableau sur cette fonction*/
int jouable(int x)
  {

    if (x>=0 && (x<7) &&remplissage[x]>=0 && remplissage[x]<6)
    return 1;
    else return 0;

  }
  /*.............fonction saisir coup*/
int saisircoup()
  {
    int z;           // z colonne//

        do{


          printf("\t      rentrez une colonne entre <0-6>:\n\t essaies une autre si celle-ci est remplie!\n");
          scanf("%d",&z);
          if (jouable(z)==1)
          return z;

          }
        while(jouable(z)!=1);

  }
  /*..............*/
  void afficherGrille()
  {
    int i,j;

    printf("\t\t*********Puissance4*******\n\n\n\n");

    for(i=0;i<6;i++){
    printf("\t\t\t");
    printf("+-+-+-+-+-+-+-+");

    printf("\n");
    printf("\t\t\t");
    for (j=0;j<7;j++)

    printf("|%c",grille[5-i][j]);

    printf("|%d \n",i);// affiche les numéros horizontalement

                    }
    if (i==6)
    printf("\t\t\t");
    printf("+-+-+-+-+-+-+-+");
    printf("\n");
    printf("\t\t\t");
    for(j=0;j<=6;j++)
                     {
    printf(" %d",j);// affiche les numéro verticalement
                     }
    printf("\n\n\t\t");
}
void afficherGrille1()
  {
    int i,j;

    printf("\t\t***grille1***\n");

    for(i=0;i<6;i++){
    printf("\t\t\t");
    printf("+-+-+-+-+-+-+-+");

    printf("\n");
    printf("\t\t\t");
    for (j=0;j<7;j++)

    printf("|%d",grille1[5-i][j]);

    printf("|%d \n",i);// affiche les numéros horizontalement

                    }
    if (i==6)
    printf("\t\t\t");
    printf("+-+-+-+-+-+-+-+");
    printf("\n");
    printf("\t\t\t");
    for(j=0;j<=6;j++)
                     {
    printf(" %d",j);// affiche les numéro verticalement
                     }
    printf("\n\n\t\t");
}


int estRemplieOuNon()

{
     int x,comp=0;
     for(x=0;x<=6;x++)
     {
     if(jouable(x))
      {
           comp=comp+1;
      }
     }
     if (comp==0)   //nbre de colonne+1

      return 1;


     else return 0;

}

int adjacent(int c, int l,int dirV, int dirH)
{
    int n=0;

     if(dirV==0)
        {
        if(dirH==1)
           {
           while((grille[l][c])==(grille[l][c+1])&&(grille[l][c]!=' '))
              {
              n++;
              c++;
              }
           }
         else if(dirH==-1)
           {
           while((grille[l][c])==(grille[l][c-1])&&(grille[l][c]!=' '))
              {
              n++;
              c--;
              }
           }
        }
     if(dirV==1)
        {
        if(dirH==0)
           {
           while((grille[l][c])==(grille[l+1][c])&&(grille[l][c]!=' '))
              {
              n++;
              l++;
              }
           }
        else if(dirH==1)
           {
           while((grille[l][c])==(grille[l+1][c+1])&&(grille[l][c]!=' '))
              {
              n++;
              c++;
              l++;
              }
           }
           else if(dirH==-1)
              {
              while((grille[l][c])==(grille[l+1][c-1])&&(grille[l][c]!=' '))
                 {
                 n++;
                 c--;
                 l++;
                 }
              }
        }
     if(dirV==-1)
        {
        if(dirH==0)
           {
           while((grille[l][c])==(grille[l-1][c])&&(grille[l][c]!=' '))
              {
              n++;
              l--;
              }
           }
        else if(dirH==-1)
              {
              while((grille[l][c])==(grille[l-1][c-1])&&(grille[l][c]!=' '))
                 {
                 n++;
                 c--;
                 l--;
                 }
              }
              else if(dirH==1)
              {
              while((grille[l][c])==(grille[l-1][c+1])&&(grille[l][c]!=' '))
                 {
                 n++;
                 c++;
                 l--;
                 }
              }
        }
     return(n);

}

int partieEstGagneeOuPas(int c,int l)
{

  if  ((adjacent(c,l,0,1)+adjacent(c,l,0,-1))>=3 ||
  (adjacent(c,l,1,0)+adjacent(c,l,-1,0))>=3 ||
  (adjacent(c,l,1,1)+adjacent(c,l,-1,-1))>=3 ||
  (adjacent(c,l,1,-1) + adjacent(c,l,-1,1)>=3))
  return 1;
  else return 0;

}
int adjacentX(int c, int l,int dirV, int dirH,char h)
{
    int n=0;

     if(dirV==0)
        {
        if(dirH==1)
           {
           while((grille[l][c])==(grille[l][c+1])&&(grille[l][c]==h))
              {
              n++;
              c++;
              }
           }
         else if(dirH==-1)
           {
           while((grille[l][c])==(grille[l][c-1])&&(grille[l][c]==h))
              {
              n++;
              c--;
              }
           }
        }
     if(dirV==1)
        {
        if(dirH==0)
           {
           while((grille[l][c])==(grille[l+1][c])&&(grille[l][c]==h))
              {
              n++;
              l++;
              }
           }
        else if(dirH==1)
           {
           while((grille[l][c])==(grille[l+1][c+1])&&(grille[l][c]==h))
              {
              n++;
              c++;
              l++;
              }
           }
           else if(dirH==-1)
              {
              while((grille[l][c])==(grille[l+1][c-1])&&(grille[l][c]==h))
                 {
                 n++;
                 c--;
                 l++;
                 }
              }
        }
     if(dirV==-1)
        {
        if(dirH==0)
           {
           while((grille[l][c])==(grille[l-1][c])&&(grille[l][c]==h))
              {
              n++;
              l--;
              }
           }
        else if(dirH==-1)
              {
              while((grille[l][c])==(grille[l-1][c-1])&&(grille[l][c]==h))
                 {
                 n++;
                 c--;
                 l--;
                 }
              }
              else if(dirH==1)
              {
              while((grille[l][c])==(grille[l-1][c+1])&&(grille[l][c]==h))
                 {
                 n++;
                 c++;
                 l--;
                 }
              }


    }
     return(n);
}
void calcul(){
    int l,c;
    for (l=0;l<6;l++)
        for (c=0;c<7;c++)
        {
            if((adjacentX(c,l,0,-1,'O'))==2) grille1[l][c+1]=2;
       else if((adjacentX(c,l,0,1,'O'))==2) grille1[l][c-1]=2;
       else if((adjacentX(c,l,-1,0,'O'))==2) grille1[l+1][c]=2;
       else if((adjacentX(c,l,1,0,'O'))==2) grille1[l-1][c]=2;
       else if((adjacentX(c,l,-1,-1,'O'))==2) grille1[l+1][c+1]=2;
       else if((adjacentX(c,l,1,1,'O'))==2) grille1[l-1][c-1]=2;
       else if((adjacentX(c,l,-1,1,'O'))==2) grille1[l+1][c-1]=2;
       else if((adjacentX(c,l,1,-1,'O'))==2) grille1[l-1][c+1]=2;

       else if((adjacentX(c,l,0,-1,'X'))==2) grille1[l][c+1]=1;
       else if((adjacentX(c,l,0,1,'X'))==2) grille1[l][c-1]=1;
       else if((adjacentX(c,l,-1,0,'X'))==2) grille1[l+1][c]=1;
       else if((adjacentX(c,l,1,0,'X'))==2) grille1[l-1][c]=1;
       else if((adjacentX(c,l,-1,-1,'X'))==2) grille1[l+1][c+1]=1;
       else if((adjacentX(c,l,1,1,'X'))==2) grille1[l-1][c-1]=1;
       else if((adjacentX(c,l,-1,1,'X'))==2) grille1[l+1][c-1]=1;
       else if((adjacentX(c,l,1,-1,'X'))==2) grille1[l-1][c+1]=1;}
        }
int LEsaisircoup()
  {
    int z;           // z colonne//

        do{
        z=rand()%7;
        if (jouable(z)==1)
          return z;
          }
        while(jouable(z)!=1);
  }
  int LMsasisircoup(){
  int z;
  for(z=0;z<7;z++){
    if (jouable(z)&&grille1[remplissage[z]][z]==2){
        return z;
        break;
    }
  }
  return(LEsaisircoup());
  }
  int LHsasisircoup(){
  int z;
  for(z=0;z<7;z++){
    if (jouable(z)&&grille1[remplissage[z]][z]==2){
        return z;
        break;
    }
  }

  for(z=0;z<7;z++){
    if (jouable(z)&&grille1[remplissage[z]][z]==1){
        return z;
        break;
    }
  }
  return(LEsaisircoup());
  }



/*6*/
main ()
{

     int i,j,joueur=0,colonne,ligne;
     int y=0,compt1=0;
     const N=50;
     char nom1[N],nom2[N],recom,a;
        printf("Contre Joueur ou PC J/P\n");
        scanf("%c",&a);
 if(a=='J'){
     printf("nom du premier joueur!!\n");
     scanf("%s",&nom1[N]);

     printf("nom du deuxiem jouer\n");
     scanf("%s",&nom2[N]);
     afficherGrille();
  //   afficherGrille1();
 do
 {
     for (i=0;i<6;i++)
     {
        for (j=0;j<7;j++)
        {
             grille[i][j]=' ';
             grille1[i][j]=0;
        }
     }

     for(j=0;j<7;j++)
        {
     remplissage[j]=0;/* on initialise remplissage à zéro, car 0 est sa premiere valeur*/
        }
    do
    {
     if (joueur%2==0)// evident
     {
     printf("%s, posez votre pion\n",&nom1[N]);// on rentre son nom
     colonne=saisircoup();
     ligne=remplissage[colonne];//remplissage définit les lignes de la colonne
     grille[ligne][colonne]='O';
   //printf("adjacentX de %d %d est %d",colonne,ligne,adjacentX(colonne,ligne,0,-1,'O'));
     //printf("(adjacentX(%d,%d,1,-1) + adjacentX(%d,%d,-1,1))est %d",colonne,ligne,colonne,ligne,(adjacent(colonne,ligne,1,-1) + adjacent(colonne,ligne,-1,1)));
        calcul();
     remplissage[colonne]=remplissage[colonne]+1;
     compt1++;

     system("cls");
     afficherGrille();
    afficherGrille1();
     if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      {
      printf("%s gagne au %deme coup\n",&nom1[N],compt1/2+1);
      }
     }
       if(joueur%2!=0)
     {
     printf("%s, posez votre pion\n",&nom2[N]);
     colonne=saisircoup();
     ligne=remplissage[colonne];
     grille[ligne][colonne]='X';
     remplissage[colonne]=remplissage[colonne]+1;
    calcul();
     compt1++;
     system("cls");// efface
     afficherGrille();
    afficherGrille1();
     if( partieEstGagneeOuPas(colonne,ligne)==1)
      {
      printf("%s gagne au %deme coup\n",&nom2[N],compt1/2);
      }

     }

     joueur=joueur+1;//on incremente le joueur


    } while(( !estRemplieOuNon() && !partieEstGagneeOuPas(colonne,ligne) ) );// répéter tant que c'est pas rempli

        printf("le score de %s est %d\n",&nom1[N]);
        printf("le score de %s est %d\n",&nom2[N]);

      do
        { fflush(stdin);
         printf("\t\tVoulez-vous recommencer ? (o/n) : ");
         scanf("%c",&recom);
        }while(recom!='o' && recom!='n');

        printf("\n");
 }while (recom=='o');



}
else if(a=='P'){
     printf("Votre Nom?\n");
     scanf("%s",&nom2[N]);

  //   afficherGrille1();
 do
 {
     for (i=0;i<6;i++)
     {
        for (j=0;j<7;j++)
        {
             grille[i][j]=' ';
             grille1[i][j]=0;
        }
     }

     for(j=0;j<7;j++)
        {
     remplissage[j]=0;/* on initialise remplissage à zéro, car 0 est sa premiere valeur*/
        }
    do
    {
     if (joueur%2==0)// evident
     {
        // on rentre son nom
     colonne=LHsasisircoup();
     ligne=remplissage[colonne];//remplissage définit les lignes de la colonne
     grille[ligne][colonne]='O';
        calcul();
     remplissage[colonne]=remplissage[colonne]+1;
     compt1++;

     //system("cls");
     afficherGrille();
        afficherGrille1();
     if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      {
      printf("Le pc gagne au %deme coup\n",compt1/2+1);
      }
     }
       if(joueur%2!=0)
     {
     printf("%s, posez votre pion\n",&nom2[N]);
     colonne=saisircoup();
     ligne=remplissage[colonne];
     grille[ligne][colonne]='X';
     remplissage[colonne]=remplissage[colonne]+1;
    calcul();
     compt1++;
     //system("cls");// efface
     afficherGrille();
    afficherGrille1();
     if( partieEstGagneeOuPas(colonne,ligne)==1)
      {
      printf("%s gagne au %deme coup\n",&nom2[N],compt1/2);
      }

     }

     joueur=joueur+1;//on incremente le joueur


    } while(( !estRemplieOuNon() && !partieEstGagneeOuPas(colonne,ligne) ) );// répéter tant que c'est pas rempli

        printf("le score de %s est %d\n",&nom1[N]);
        printf("le score de %s est %d\n",&nom2[N]);

      do
        { fflush(stdin);
         printf("\t\tVoulez-vous recommencer ? (o/n) : ");
         scanf("%c",&recom);
        }while(recom!='o' && recom!='n');

        printf("\n");
 }while (recom=='o');
}
}
