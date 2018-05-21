#include<GL/glut.h>
#include <Math.h>     // Needed for sin, cos
#define PI 3.14159265f
#include"Grid.h"
#include"Game.h"
#define ROWS 8
#define COLUMNS 9
int joueur=0,colonne,ligne;
int fin=0;


#include <stdio.h>
#include <stdlib.h>
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
	  glVertex2f(0,0);       // Center of circle
      int numSegments = 100;
      GLfloat angle;
      GLfloat ballRadius = 0.5f;
      int i;
      for (i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
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

	if (joueur%2==0){
		drawText(2.5,0.5,"Joueur 1");
	}
	else
	drawText(2.5,0.5,"Joueur 2");
	glutSwapBuffers();
	
		if(fin==1){
		
		//glutPostRedisplay(); 
		int msg = MessageBox(NULL,"text2","Game Over",MB_OK);
		
		if(msg == IDOK){
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

	glClearColor(1.0,1.0,1.0,0.0);
    initGrid(ROWS,COLUMNS);
}

void souris(int button, int state,int x,int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  { 
  if ((x < 365)&&(x>200)&&(y < 220)&&(y>150)){glutDisplayFunc(display_callback);
  }
  	else	
	  if (joueur%2==0){
	if ((x < 135)&&(x> 65)){
    colonne=saisircoup(0);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
		if( partieEstGagneeOuPas(colonne,ligne)==1)
      	{
      		fin=1;
      	}
	}
	else if ((x < 200)&&(x>136)){
    colonne=saisircoup(1);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
		if( partieEstGagneeOuPas(colonne,ligne)==1)
      	{
      		fin=1;
      	}
	}
		else if ((x < 265)&&(x>200)){
    colonne=saisircoup(2);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
		if( partieEstGagneeOuPas(colonne,ligne)==1)
      	{
      		fin=1;
      	}
	}	
	else if ((x < 330)&&(x>265)){
    colonne=saisircoup(3);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 395)&&(x>330)){
    colonne=saisircoup(4);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 460)&&(x>395)){
    colonne=saisircoup(5);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 525)&&(x>460)){
    colonne=saisircoup(6);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='O';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
			}
  		if (joueur%2!=0){
	if ((x < 135)&&(x> 65)){
    colonne=saisircoup(0);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
	fin=1;
      	}
	}
	else if ((x < 200)&&(x>136)){
    colonne=saisircoup(1);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 265)&&(x>200)){
    colonne=saisircoup(2);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 330)&&(x>265)){
    colonne=saisircoup(3);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 395)&&(x>330)){
    colonne=saisircoup(4);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 460)&&(x>395)){
    colonne=saisircoup(5);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
	else if ((x < 525)&&(x>460)){
    colonne=saisircoup(6);
    ligne=remplissage[colonne];
    grille[ligne][colonne]='X';
	remplissage[colonne]=remplissage[colonne]+1;
	
		if( partieEstGagneeOuPas(colonne,ligne)==1)// si la partie est gagnée
      	{
      		fin=1;
      	}
	}
			}	
	
	
joueur=joueur+1;
}

glutPostRedisplay();

		


}

int main(int argc,char **argv)
{
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
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("TEST");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape_callback);
    init();
    glutMouseFunc(souris);
	glutMainLoop();
   	
}

