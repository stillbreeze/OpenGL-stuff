
#include<conio.h>
#include<stdio.h>
#include<GL/glut.h>


float x1=-1.2,lkey=0,rkey=0;

static int flag=1;void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45,w/h,1,200);

}


void keyPressed(int key,int x,int y)
{
    if(key==GLUT_KEY_LEFT)
        lkey = 1;
    else
        lkey = 0;
    if(key==GLUT_KEY_RIGHT)
        rkey = 1;
    else
        rkey = 0;
}

void drawBall()
{
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();

    glTranslatef(x1,0.0,-5.0);

    glutSolidSphere(0.2,20,20);

    glPopMatrix();
}

void drawLine()
{
    glLineWidth(2.5);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(-1.2, -0.2, -5.0);
    glVertex3f(1.2, -0.2, -5.0);
    glEnd();
}

void update()
{
    if(flag && rkey)
        {
            x1+=0.001;
            if(x1>1.10)
                flag=0;
        }

    if(!flag && lkey)
    {
        x1-=0.001;
        if(x1<-1.10)
            flag=1;
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //glShadeModel(GL_SMOOTH);

    drawBall();

    drawLine();

    update();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(500,500);

    glutCreateWindow("Collision Window");

    initRendering();

    glutDisplayFunc(display);

    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutSpecialFunc(keyPressed);

    glutMainLoop();

    return(0);
}
