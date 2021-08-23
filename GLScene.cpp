#include "GLScene.hpp"

// Global parameter struct, 'Paramater P'.
Parameter P;
Flock *flock;

void GLScene(int argc, char *argv[])
{
    int tmp = 0;
    GLScene(0, 0, argc, argv);
}

void GLScene(int x, int y, int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(P.window_width, P.window_height);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutCreateWindow("Boid 2D version");

    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glutTimerFunc(1000 / FPS, Update, 0);

    Init();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Render();
    glutSwapBuffers();
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
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-P.R, P.R, -P.R, P.R, -1.0, 1.0);
}

void Update(int val)
{
    flock->Update();
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, Update, val);
}

void Init()
{
    flock = new Flock(P);

    glShadeModel(GL_SMOOTH);
    glClearColor((double)255 / 255, (double)240 / 255, (double)237 / 255, 1);
}

void Render()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int i = 0; i < P.N; i++)
    {
        glPushMatrix();

        Boid b = flock->GetBoids()[i];

        glTranslated(b.GetPos().x, b.GetPos().y, 0);
        glRotated(b.GetAngle() / PI * 180 - 90, 0, 0, 1);

        double s = b.GetSize();

        glBegin(GL_POLYGON);
        glColor3d((double)214 / 255, (double)29 / 255, 0);
        glVertex2d(-cos(72.0 / 180 * PI) * s, -sin(72.0 / 180 * PI) / 2 * s);
        glVertex2d(cos(72.0 / 180 * PI) * s, -sin(72.0 / 180 * PI) / 2 * s);
        glVertex2d(0 * s, sin(72.0 / 180 * PI) / 2 * s);
        glEnd();

        glPopMatrix();
    }
}