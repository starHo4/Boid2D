#include "GLScene.hpp"

void GLScene(int argc, char *argv[])
{
    int tmp = 0;
    GLScene(0, 0, argc, argv);
}

void GLScene(int x, int y, int argc, char *argv[])
{
    int tmp = 794;

    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(tmp, tmp);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutCreateWindow("Boid 2D version");

    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glutTimerFunc(1000 / FPS, Update, 0);
}

void Display()
{
}

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
    case 'Q':
    case '\033':
        exit(0);
    default:
        break;
    }
}

void Reshape(int w, int h)
{
    if (h == 0)
    {
        h = 1;
    }
}

void Update(int val)
{
    glutTimerFunc(1000 / FPS, Update, val);
}