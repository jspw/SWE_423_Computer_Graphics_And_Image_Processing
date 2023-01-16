#include <iostream>
#include <GLUT/glut.h>
#include <math.h>

using namespace std;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0f, 0.7f, 1.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawPixel(int x, int y)
{
    cout << "x : " << x << " | y : " << y << endl;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void MidPointAlgorithm(int centerX, int centerY, int radius)
{
    cout << "Drawing Circle using Mid Point Drawing Algorithm" << endl;

    int x = 0;
    int y = radius;
    float decision = 5 / 4 - radius;

    drawPixel(x + centerX, y + centerY);

    while (y > x)
    {
        x++;
        if (decision < 0)
        {
            decision += 2 * x + 3;
        }
        else
        {
            y--;
            decision += 2 * (x - y) + 5;
        }
        drawPixel(x + centerX, y + centerY);
        drawPixel(x + centerX, -y + centerY);
        drawPixel(-x + centerX, y + centerY);
        drawPixel(-x + centerX, -y + centerY);
        drawPixel(y + centerX, x + centerY);
        drawPixel(-y + centerX, x + centerY);
        drawPixel(y + centerX, -x + centerY);
        drawPixel(-y + centerX, -x + centerY);
    }

    cout
        << "Drawing Circle Completed" << endl;
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
    MidPointAlgorithm(100, 100, 100);
    // MidPointAlgorithm(50, 100, 150);
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
    glutCreateWindow("Mid Point Circle Draw");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(display);
    // glutWMCloseFunc(winCloseFunc);
    /* Keep displaying until the program is closed */
    glutMainLoop();
}