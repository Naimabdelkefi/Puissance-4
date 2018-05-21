#include<GL/glut.h>
#include <Math.h>     // Needed for sin, cos
#define PI 3.14159265f
#include"Grid.h"
#include"Game.h"
#define ROWS 8
#define COLUMNS 9
#include <stdio.h>
#include <stdlib.h>

int joueur,colonne,ligne,lvl,score1,score2;
int fin,ai;
 int grille1[6][7];
char grille[6][7];/*ce tableau represente une delimitation du nombre de case de la grille*/
int remplissage[7];

void draw_cercle(GLfloat ballX,GLfloat ballY , char h)
{
     glTranslatef(ballX, ballY, 0.0f);
     glBegin(GL_TRIANGLE_FAN);
     if (h=='O')
      glColor3f(1.0f, 0.0f, 0.0f); 
     else if (h=='X')
      glColor3f(1.0f, 1.0f, 0.0f); 
	  glVertex2f(0,0);       
      int numSegments = 100;
      GLfloat angle;
      GLfloat ballRadius = 0.5f;
      int i;
      for (i = 0; i <= numSegments; i++) { 
         angle = i * 2.0f * PI / numSegments;  
         glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
      }
   glEnd();
    glTranslatef(-ballX, -ballY, 0.0f);

}
void drawText(float x, float y, char* textString) {
	glColor3f(0.0f, 0.0f, 0.0f);
    int le;
    int qs;  
    glRasterPos2f(x, y);
    le = (int) strlen(textString);
    for (qs = 0; qs < le; qs++) 
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, textString[qs]);
        
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawText(2.5,7,"*********Puissance4*******");
    glColor3f(1.0f, 0.0f, 0.0f);
  	glRectd(3,6,5.5,5);
  	drawText(3.5,5.5,"Contre Joueur");
  	glColor3f(1.0f, 1.0f, 0.0f);
  	glRectd(3,2,5.5,3);
  	drawText(3.7,2.5,"Contre PC");
	glutSwapBuffers();
}
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawText(2.5,7,"*********Puissance4*******");
    drawText(3.7,6.5,"Contre PC");
  	drawText(3.3,6,"Choose a level");
  	glColor3f(0.0f, 1.5f, 1.0f);
  	glRectd(3,5.5,5.5,4.5);
  	drawText(4,5,"EASY");
  	glColor3f(0.0f, 0.5f, 1.0f);
  	glRectd(3,3.5,5.5,2.5);
  	drawText(3.8,3,"MEDIUM");
  	glColor3f(0.0f, 0.0f, 1.0f);
  	glRectd(3,1.5,5.5,0.5);
  	drawText(4,1,"HARD");
	glutSwapBuffers();
}
void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    int i,j;
    for (i=0;i<6;i++)
     {
        for (j=0;j<7;j++)
        {
             if(grille[i][j]=='X')
             draw_cercle(j+1.5,i+1.5,'X');
			 else if (grille[i][j]=='O')
			 draw_cercle(j+1.5,i+1.5,'O');
		}
	}
	if(ai==1){
	char text[2];	
	if (joueur%2!=0)
	drawText(1,0.5,"Joueur 1 a toi de jouer");
	drawText(5,0.5,"Ton Score est");
	itoa (score1,text,10);
	drawText(7,0.5,text);
	}
	else if (ai==0)
	{
	if (joueur%2==0){
	char text[2];	
	drawText(1,0.5,"Joueur 1 a toi de jouer");
	drawText(5,0.5,"Ton Score est");
	itoa (score1,text,10);
	drawText(7,0.5,text);
	}
	else{
	char text[2];	
	drawText(1,0.5,"Joueur 2 a toi de jouer");
	drawText(5,0.5,"Ton Score est");
	itoa (score2,text,10);
	drawText(7,0.5,text);}
	}
	glutSwapBuffers();
	char* text;
	if(ai==1){
	if (joueur%2==0){
	  	text="Joueur 1 gagne";}
		else{
		text="PC gagne";	
		}
	}
	else if(ai==0){
	if (joueur%2==0){
	text="Joueur 2 gagne";
		  }
		else{
		text="Joueur 1 gagne";	
		}	
	}
		if(fin==1){
		int msg = MessageBox(NULL,text,"Game Over",MB_OK);
		if(msg == IDOK){
			fin=0;
			exit(0);
		}  
	} 

}

void reshape_callback(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void init()
{
	score1=21;
	score2=21;
	joueur=0;
	fin=0;
	glClearColor(1.0,1.0,1.0,0.0);
    initGrid(ROWS,COLUMNS);
    	int i,j;
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
     remplissage[j]=0;
        }
}
void input(int x,int x1,int x2,int z,char h){
	if ((x <x1)&&(x> x2)){
    colonne=saisircoup(z);
    ligne=remplissage[colonne];
    grille[ligne][colonne]=h;
    		if((estRemplieOuNon()==1)||( partieEstGagneeOuPas(colonne,ligne)==1))
      	{
      		fin=1;
      		
     	}
     	
	remplissage[colonne]=remplissage[colonne]+1;

}
}
void inputAI(int lvl){
    colonne=Lsasisircoup( lvl);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
    		if((estRemplieOuNon()==1)||( partieEstGagneeOuPas(colonne,ligne)==1))
      	{
      		fin=1;
     	}
	remplissage[colonne]=remplissage[colonne]+1;

}
void souris1(int , int ,int ,int );
void souris2(int , int ,int ,int );
void souris3(int , int ,int ,int );
void souris(int button, int state,int x,int y)
{	
	char h;
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  { 
    if ((x < 365)&&(x>200)&&(y < 220)&&(y>150))
	{
		ai=0;
	glutDisplayFunc(display_callback);
	glutMouseFunc(souris2);
  }
  	else  if ((x < 365)&&(x>200)&&(y < 450)&&(y>380)){
	  glutDisplayFunc(display2);	
  		glutMouseFunc(souris1);
  		ai=1;
  }
}
	glutPostRedisplay();
	
}
void souris1(int button, int state,int x,int y){
	 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  { 
	
   if ((x < 365)&&(x>200)&&(y > 185)&&(y<260)){
	lvl=0;
	glutDisplayFunc(display_callback);
	glutMouseFunc(souris3);
	}
  else 	 if ((x < 365)&&(x>200)&&(y >335)&&(y<410)){
	lvl=1;
	glutDisplayFunc(display_callback);
	glutMouseFunc(souris3);
	}
	 else 	 if ((x < 365)&&(x>200)&&(y >485)&&(y<560)){
	lvl=2;
	glutDisplayFunc(display_callback);
	glutMouseFunc(souris3);
	}
}
	glutPostRedisplay();
}
void souris2(int button, int state,int x,int y){
	char h;
	 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  { 
	if (joueur%2==0){
	  	h='O';
		  	joueur++;
			  score1--;}
		else{
		h='X';
			joueur++;
		score2--;
		}
		
	  	input(x,135,65,0,h);
	  	input(x,200,136,1,h);
		input(x,265,200,2,h);
		input(x,330,265,3,h);
		input(x,395,330,4,h);
		input(x,460,395,5,h);
		input(x,525,460,6,h);
		}
		glutPostRedisplay();

	}
void souris3(int button, int state,int x,int y){
	char h;
	printf("%d",joueur);
	 if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  { 
  			
		if (joueur%2!=0){
		h='X';
		score2--;
		}
	  	input(x,135,65,0,h);
	  	input(x,200,136,1,h);
		input(x,265,200,2,h);
		input(x,330,265,3,h);
		input(x,395,330,4,h);
		input(x,460,395,5,h);
		input(x,525,460,6,h);
		calcul();
		joueur++;	
		}
		else {
		joueur++;	
		inputAI(lvl);		
		calcul();
		//afficherGrille1();
		//afficherGrille();
		score1--;
		}	
			glutPostRedisplay();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Puissance4");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape_callback);
    init();
    glutMouseFunc(souris);
	glutMainLoop();
   	
}

