#include <GL/glut.h>
#include"Game.h"

int gridX,gridY;

void initGrid(int rows,int columns)
{
    gridX=columns,gridY=rows;
}

void unit(int x,int y)
{

    
        glColor3f(0.0,0.0,1.0);
        glLineWidth(1.5);
    
    glBegin(GL_LINES);
        glVertex2d(x,y);    glVertex2d(x+1,y);
        glVertex2d(x+1,y);  glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1);glVertex2d(x,y+1);
        glVertex2d(x,y+1);  glVertex2d(x,y);
    glEnd();
}

void drawGrid()
{
	int x,y;
    for(x=1;x<gridX-1;x++)
    {
        for(y=1;y<gridY-1;y++)
        {
            unit(x,y);
        }
    }
}
