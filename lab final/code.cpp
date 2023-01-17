#include <iostream>
#include <GLUT/glut.h>
#include <math.h>

using namespace std;

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glPointSize(4.0);
    glVertex2i(x, y);
    glEnd();
}

void BresenhumAlgorithm(int centerX, int centerY, int radius)
{
    cout << "Drawing Circle using Bresenham Circle Drawing Algorithm" << endl;

    int x = 0;
    int y = radius;
    float decision = 3 - 2 * radius;

    drawPixel(x + centerX, y + centerY);

    while (y > x)
    {
        x++;
        if (decision < 0)
        {
            decision += 4 * x + 6;
        }
        else
        {
            y--;
            decision += 4 * (x - y) + 10;
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

void BLDX(int x1, int y1, int x2, int y2, bool isDotted)
{
    cout << "Drawing Line using Bresenham Line Drawing Algorithm" << endl;
    cout << x1 << "," << y1 << "," << x2 << "," << y2 << endl;

    int count = 0;

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
        if (isDotted)
        {
            if (count % 5 == 0)
                drawPixel(x, y);
        }
        else
        {
            drawPixel(x, y);
        }

        while (x < x2)
        {
            count++;
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
            if (isDotted)
            {
                if (count % 2 == 0)
                    drawPixel(x, y);
            }
            else
            {
                drawPixel(x, y);
            }
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

        if (isDotted)
        {
            if (count % 2 == 0)
                drawPixel(x, y);
        }
        else
        {
            drawPixel(x, y);
        }
        while (y < y2)
        {
            count++;
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
            if (isDotted)
            {
                if (count % 2 == 0)
                    drawPixel(x, y);
            }
            else
            {
                drawPixel(x, y);
            }
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

void drawSUST()
{
    // S
    BLDX(250, 250, 300, 300, false);
    BLDX(250, 250, 300, 250, true);
    BLDX(250, 200, 300, 250, false);

    // U
    BLDX(350, 200, 350, 300, false);
    BLDX(350, 200, 400, 200, false);
    BLDX(400, 200, 400, 300, false);

    // s
    BLDX(450, 300, 500, 300, false);
    BLDX(450, 300, 450, 250, false);
    BLDX(450, 250, 500, 250, false);
    BLDX(500, 250, 500, 200, false);
    BLDX(450, 200, 500, 200, false);

    // t

    BLDX(550, 300, 600, 300, true);
    BLDX(550, 300, 600, 300, true);
    BLDX(575, 300, 575, 200, true);
}

void drawJanina()
{
    BLDX(100, 50, 550, 50, true);

    // l
    BLDX(75, 75, 100, 50, true);
    // r
    BLDX(550, 50, 575, 75, true);

    // line
    BLDX(75, 75, 575, 75, false);

    // l
    BLDX(50, 100, 75, 75, false);

    // r

    BLDX(575, 75, 600, 100, false);

    // line

    BLDX(50, 100, 600, 100, false);

    // 1st pillar

    BLDX(125, 100, 125, 300, false);
    BLDX(125, 300, 175, 300, false);
    BLDX(175, 100, 175, 300, false);

    // 2nd pillar
    BLDX(250, 100, 250, 300, false);

    // BLDX(275, 100, 250,300,false);
    // draw circle

    BresenhumAlgorithm(325, 200, 50);
    BLDX(325, 100, 325, 150, false);
    BLDX(325, 250, 325, 300, false);

    BLDX(400, 100, 400, 300, false);

    // head 1st
    BLDX(250, 300, 300, 350, false);
    BLDX(325, 300, 375, 350, false);
    BLDX(400, 300, 450, 350, false);
    // upper line of head
    BLDX(300, 350, 450, 350, false);

    // 3rd pillar

    BLDX(525, 100, 525, 300, false);
    BLDX(475, 100, 475, 300, false);
    BLDX(475, 300, 525, 300, false);
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

    // drawSUST();
    drawJanina();

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
    glutCreateWindow("Image Processing Lab Final");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(display);
    // glutWMCloseFunc(winCloseFunc);
    /* Keep displaying until the program is closed */
    glutMainLoop();
}