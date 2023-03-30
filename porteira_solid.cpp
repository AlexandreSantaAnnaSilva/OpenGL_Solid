// programa porteira.c, modo aramado
//ST765, 1sem23, Prof. Marco Antonio
#include<stdlib.h>
#include<GL/glut.h>

static int rot = 0;
static int port = 0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
}

void display(void){
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

glColor3f(0.0, 1.0, 0.0);

/*gramado / curral*/
glPushMatrix();
glScalef(10.0, 0.2, 6.0);
glutSolidCube(1.0);
glPopMatrix();

/*estaca lado esquerdo frente*/
glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glTranslatef(-4.0, 0.9, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();
  
/*estaca lado esquerdo traseira*/
glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glTranslatef(-4.0, 0.9, -2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estaca lado direito frente*/
glPushMatrix();
glTranslatef(4.0, 0.9, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estaca lado direito traseira*/
glPushMatrix();
glTranslatef(4.0, 0.9, -2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas porteira*/
//esquerda
glPushMatrix();
glTranslatef(-1.0, 0.9, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//direita
glPushMatrix();
glTranslatef(1.0, 0.9, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas horizontais cerca*/
//esquerda
glPushMatrix();
glTranslatef(-2.5, 0.5, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.5, 1.0, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//lateral esquerda
glPushMatrix();
glTranslatef(-3.9, 0.5, 0.0);
glScalef(0.1, 0.1, 5.2);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.9, 1.0, 0.0);
glScalef(0.1, 0.1, 5.2);
glutSolidCube(1.0);
glPopMatrix();

//direita
glPushMatrix();
glTranslatef(2.5, 0.5, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(2.5, 1.0, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//lateral direita
glPushMatrix();
glTranslatef(3.9, 0.5, 0.0);
glScalef(0.1, 0.1, 5.2);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.9, 1.0, 0.0);
glScalef(0.1, 0.1, 5.2);
glutSolidCube(1.0);
glPopMatrix();

//traseira
glPushMatrix();
glTranslatef(0.0, 0.5, -2.4);
glScalef(8.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.0, -2.4);
glScalef(8.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//abre e fecha a porteira

/*estacas horizontais porteira*/
glColor3f(1.0, 1.0, 0.0);

glPushMatrix();
glTranslatef(-1.1, 0.3, 2.7);
glRotatef((GLfloat) port, 0.0, 1.0, 0.0);
glTranslatef(1.1, -0.3, -2.7);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(2.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(2.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(2.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//vertical direita
glPushMatrix();
glTranslatef(1.0, 0.9, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();


  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
glTranslatef(0.0, -2.0, -12.0);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
case 'r':
rot = (rot+5) % 360;
glutPostRedisplay();
break;
case 'R':
rot = (rot-5) % 360;
glutPostRedisplay();
break;
case 'a':
port = (port+5) % 360;
glutPostRedisplay();
break;
case 'A':
port = (port-5) % 360;
glutPostRedisplay();
break;

  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("abre a porteira");
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
