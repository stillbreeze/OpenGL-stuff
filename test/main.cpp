
#include<conio.h>
#include<stdio.h>
#include<GL/glut.h>


float x1=-2.0,x2=2.0, x3=0.0, x4=0.0;

static int flag=1, flag2 = 0;void initRendering()
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
    {}
}

void drawBall1()
{
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();

    glTranslatef(x1,0.0,-5.0);

    glutSolidSphere(0.4,20,20);

    glPopMatrix();
}

void drawBall2()
{
    glColor3f(0.0,0.0,1.0);

    glPushMatrix();

    glTranslatef(x2,0.0,-5.0);

    glutSolidSphere(0.4,20,20);

    glPopMatrix();

}

void drawBall3()
{
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();

    glTranslatef(x3,0.25,-5.0);

    glutSolidSphere(0.2,20,20);

    glPopMatrix();

}

void drawBall4()
{
    glColor3f(0.0,0.0,1.0);

    glPushMatrix();

    glTranslatef(x4,-0.25,-5.0);

    glutSolidSphere(0.2,20,20);

    glPopMatrix();

}

void drawBall5()
{
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();

    glTranslatef(x3,0.85,-5.0);

    glutSolidSphere(0.2,20,20);

    glPopMatrix();

}

void drawBall6()
{
    glColor3f(0.0,0.0,1.0);

    glPushMatrix();

    glTranslatef(x4,-0.85,-5.0);

    glutSolidSphere(0.2,20,20);

    glPopMatrix();

}

void update()
{
    if(flag)
        {
            x1+=0.001;
            x2-=0.001;
            if(x1>-0.35)
                flag=0;
        }
        /*
    if(!flag)
    {
        x1-=0.001;
        x2+=0.001;
        if(x1<-2.0)
            flag=1;
    }*/
}

void update2()
{
    flag2 = 1;
    if(flag2)
        {
            x4+=0.001;
            x3-=0.001;
            if(x4>2)
                flag2=0;
        }
        /*
    if(!flag2)
    {
        x4-=0.001;
        x3+=0.001;
        if(x4<-2.0)
            flag2=1;
    }*/
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //glShadeModel(GL_SMOOTH);
    if(flag2!=1)
    {
        drawBall1();

        drawBall2();

        update();
    }

    if(flag==0)
    {

        drawBall3();

        drawBall4();

        drawBall5();

        drawBall6();

        update2();

    }
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
