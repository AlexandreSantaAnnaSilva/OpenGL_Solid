# OpenGL_Solid



Para utilizar o modo sólido de apresentação de objetos em programas OpenGL

1.Modifique a(s) funções de modelagem dos objetos:
Por exemplo, substitua a função glutWireCube();
pela função glutSolidCube();

2.Em main(), modificar o modo de apresentação no GLUT.
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

3.Na função init():
incluir a chamada à função glEnable(GL_DEPTH_TEST);

4.Na função display():
substituir o
glClear (GL_COLOR_BUFFER_BIT);
por
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
