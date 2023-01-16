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

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y, p;

    x = x1;
    y = y1;
    if (x1 < x2)
    {
        if (y1 < y2)
        {
            p = 2 * dy - dx;
            while (x < x2)
            {
                x++;
                if (p < 0)
                {
                    p = p + 2 * dy;
                }
                else
                {
                    y++;
                    p = p + 2 * (dy - dx);
                }
                drawPixel(x, y);
            }
        }
        else
        {
            p = 2 * dy + dx;
            while (x < x2)
            {
                x++;
                if (p < 0)
                {
                    y--;
                    p = p + 2 * (dy + dx);
                }
                else
                {
                    p = p + 2 * dy;
                }
                drawPixel(x, y);
            }
        }
    }
    else
    {
        if (y1 > y2)
        {
            p = 2 * dy + dx;
            while (x > x2)
            {
                x--;
                if (p < 0)
                {
                    p = p + 2 * dy;
                }
                else
                {
                    y--;
                    p = p + 2 * (dy + dx);
                }
                drawPixel(x, y);
            }
        }
        else
        {
            p = 2 * dy - dx;
            while (x > x2)
            {
                x--;
                if (p < 0)
                {
                    y++;
                    p = p + 2 * (dy - dx);
                }
                else
                {
                    p = p + 2 * dy;
                }
                drawPixel(x, y);
            }
        }
    }
}

void BLD(int x1, int y1, int x2, int y2)
{
    cout << "Drawing Line using Bresenham Line Drawing Algorithm" << endl;
    cout << x1 << "," << y1 << "," << x2 << "," << y2 << endl;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (dx >= dy)
    {
        int d = 2 * dy - dx;
        int ds = 2 * dy;
        int dt = 2 * (dy - dx);

        if (x1 > x2)
        {
            x = x2;
            y = y2;
            x2 = x1;
        }
        else
        {
            x = x1;
            y = y1;
        }

        drawPixel(x, y);
        while (x < x2)
        {
            x++;
            if (d < 0)
            {
                d += ds;
            }
            else
            {
                if (y1 < y2)
                {
                    y++;
                }
                else
                {
                    y--;
                }
                d += dt;
            }
            drawPixel(x, y);
        }
    }
    else
    {
        int d = 2 * dx - dy;
        int ds = 2 * dx;
        int dt = 2 * (dx - dy);

        if (y1 > y2)
        {
            x = x2;
            y = y2;
            y2 = y1;
        }
        else
        {
            x = x1;
            y = y1;
        }

        drawPixel(x, y);
        while (y < y2)
        {
            y++;
            if (d < 0)
            {
                d += ds;
            }
            else
            {
                if (x1 < x2)
                {
                    x++;
                }
                else
                {
                    x--;
                }
                d += dt;
            }
            drawPixel(x, y);
        }
    }

    cout
        << "Drawing Line Completed" << endl;
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
    // BLD(56, 100, 89, 300);
    // BLD(50, 50, 1, 1);
    // BLD(150, 150, 200, 200);
    // BLD(200, 200, 250, 250);
    // BLD(300, 300, 250, 250);
    // BLD(300, 300, 250, 250);
    BLD(250, 250, 300, 300);
    // BLD(100, 100, 400, 400);
    // BLD(400, 400, 100, 100);
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
    glutCreateWindow("BRA ALGORITHM");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(display);
    // glutWMCloseFunc(winCloseFunc);
    /* Keep displaying until the program is closed */
    glutMainLoop();
}