#include <time.h>
#include <stdio.h>
#include <stdlib.h>
  int grille1[6][7];
  char grille[6][7];
  int remplissage[7];

int dansGrille(int x,int y)
  {
      if ((x>=0)&&(x<=5)&&(y>=0)&&(y<=6))
       return 1;
      else return 0;
  }
 
int jouable(int x)
  {
    if (x>=0 && (x<7) &&remplissage[x]>=0 && remplissage[x]<6)
    return 1;
    else return 0;
  }

int saisircoup(int z)
  {
          if (jouable(z)==1)
          return z;

          }
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
     if (comp==0)  

      return 1;


     else return 0;

}

int adjacent(int c, int l,int dirV, int dirH)
{
    int n=0;
if(c==0 && dirH==-1) return 0;
else if(c==6 && dirH==1) return 0;
else
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
if(c==0 && dirH==-1) return 0;
else if(c==6 && dirH==1) return 0;
else
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
            if((adjacentX(c,l,0,-1,'O'))==2) grille1[l][c+1]=3;
       else if((adjacentX(c,l,0,1,'O'))==2) grille1[l][c-1]=3;
       else if((adjacentX(c,l,-1,0,'O'))==2) grille1[l+1][c]=3;
       else if((adjacentX(c,l,1,0,'O'))==2) grille1[l-1][c]=3;
       else if((adjacentX(c,l,-1,-1,'O'))==2) grille1[l+1][c+1]=3;
       else if((adjacentX(c,l,1,1,'O'))==2) grille1[l-1][c-1]=3;
       else if((adjacentX(c,l,-1,1,'O'))==2) grille1[l+1][c-1]=3;
       else if((adjacentX(c,l,1,-1,'O'))==2) grille1[l-1][c+1]=3;

       else if((adjacentX(c,l,0,-1,'O'))==1) grille1[l][c+1]=2;
       else if((adjacentX(c,l,0,1,'O'))==1) grille1[l][c-1]=2;
       else if((adjacentX(c,l,-1,0,'O'))==1) grille1[l+1][c]=2;
       else if((adjacentX(c,l,1,0,'O'))==1) grille1[l-1][c]=2;
       else if((adjacentX(c,l,-1,-1,'O'))==1) grille1[l+1][c+1]=2;
       else if((adjacentX(c,l,1,1,'O'))==1) grille1[l-1][c-1]=2;
       else if((adjacentX(c,l,-1,1,'O'))==1) grille1[l+1][c-1]=2;
       else if((adjacentX(c,l,1,-1,'O'))==1) grille1[l-1][c+1]=2;

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
    int z;          
	srand(time(NULL));
        do{
        z=rand()% 7;
        if (jouable(z)==1)
          return z;
          }
        while(jouable(z)!=1);
  }
  int LMsasisircoup(){
  int z;
  for(z=0;z<7;z++){
    if (jouable(z)&&grille1[remplissage[z]][z]==3){
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
  int LHsasisircoup(){
  int z;
  for(z=0;z<7;z++){
    if (jouable(z)&&grille1[remplissage[z]][z]==3){
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
  for(z=0;z<7;z++){
    if (jouable(z)&&grille1[remplissage[z]][z]==2){
        return z;
        break;
    }
  }

  return(LEsaisircoup());
  }
  int  Lsasisircoup(int lvl){
  	if (lvl==0) return(LEsaisircoup());
  	else if(lvl==1) return(LMsasisircoup());
  	else if(lvl==2) return(LHsasisircoup());
  }
        


