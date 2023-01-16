#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <cmath>

using namespace std;

static GLfloat spin = 0.0;
static float tx = 10.0;
static float ty = 0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    // glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(tx, ty, 0);
    glRectf(-250.0, -250.0, 25.0, 25.0);
    glPopMatrix();
    glFlush();
}

void spinDisplay_left(void)
{
    spin = 5;
    glutPostRedisplay();
    glRotatef(spin, 0.0, 0.0, 1.0);
}

void spinDisplay_right(void)
{
    spin = -5;
    glutPostRedisplay();
    glRotatef(spin, 0.0, 0.0, 1.0);
}
void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'l':
        spinDisplay_left();
        break;

    case 'r':
        spinDisplay_right();
        break;

    case 's':
        glutIdleFunc(NULL);
        break;

    default:
        break;
    }
}

void spe_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_LEFT:
        tx -= 5;
        glutPostRedisplay();
        break;

        // spinDisplay_left();
        // break;

    case GLUT_KEY_RIGHT:
        tx += 5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:
        ty += 5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        ty -= 5;
        glutPostRedisplay();
        break;

        // spinDisplay_right();
        // break;

    default:
        break;
    }
}

void my_mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
        // glutIdleFunc(NULL); // make idle function inactive
        break;
    default:
        break;
    }
}
void init(void)
{

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}
void input()
{
}
int main(int argc, char **argv)
{
    input();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Bitch!!");
    init();
    glutDisplayFunc(display);

    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutMouseFunc(my_mouse);

    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}