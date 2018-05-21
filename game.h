#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

int dansGrille(int ,int );
int jouable(int);
int saisircoup(int);
//void intiGame();
  void afficherGrille();
void afficherGrille1();
int estRemplieOuNon();

int adjacent(int , int ,int , int );

int partieEstGagneeOuPas(int ,int );
int adjacentX(int , int,int , int,char);
void calcul();
int LEsaisircoup();
  int LMsasisircoup();
  int LHsasisircoup();
  int Lsasisircoup(int);
  


#endif // GAME_H_INCLUDED
