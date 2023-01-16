#include <iostream>
#include <GLUT/glut.h>
#include <math.h>

using namespace std;

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA(int x1, int y1, int x2, int y2)
{
    cout << "Drawing Line using DDA Line Drawing Algorithm" << endl;
    cout << x1 << "," << y1 << "," << x2 << "," << y2 << endl;
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    int xInc = dx / (float)steps;
    int yInt = dy / (float)steps;

    drawPixel(x, y);

    for (int i = 0; i < steps; i++)
    {
        x += xInc;
        y += yInt;

        drawPixel(x, y);
    }

    cout << "Drawing Line Completed" << endl;
}

void init()
{
    /* Set clear color to white */
    glClearColor(1.0, 1.0, 1.0, 0);
    /* Set fill color to black */
    glColor3f(0.0, 0.0, 0.0);
    /* glViewport(0 , 0 , 640 , 480); */
    /* glMatrixMode(GL_PROJECTION); */
    /* glLoadIdentity(); */
    gluOrtho2D(0, 640, 0, 480);
}

void input()
{
    // int x1, y1, x2, y2;
    // cout << "Enter x1,y1,x2,y2 : ";
    // cin >> x1 >> y1 >> x2 >> y2;
    // DDA(x1, y1, x2, y2);
}

void display()
{
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);
    // int lines;
    // cout << "Enter number of lines : ";
    // cin >> lines;
    // for (int i = 0; i < lines; i++)
    // {
    //     input();
    // }
    // DDA(250, 250, 300, 300);
    // DDA(300, 300, 150, 150);
    // DDA(150, 150, 200, 200);
    // DDA(200, 200, 250, 250);
    // DDA(56, 100, 89, 300);
    // DDA(50, 50, 1, 1);
    DDA(250, 250, 300, 300);
    DDA(250, 250, 300, 300);
    glFlush();
}

// void winCloseFunc()
// {
//     glutDestroyWindow(g_windowId);
//     exit(0);
// }

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("DDA_Line");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(display);
    // glutWMCloseFunc(winCloseFunc);
    /* Keep displaying until the program is closed */
    glutMainLoop();
}