#include <GL/freeglut.h>

// transformaciones
float transX = 0.0f, transY = 0.0f, transZ = 0.0f;
float rotX = 0.0f, rotY = 0.0f;
float scale = 1.0f;

// control para mouse
int lastMouseX, lastMouseY;
bool isDragging = false;

// coordenadas X (Rojo), Y (Verde), Z (Azul)
void drawAxes() {
    glBegin(GL_LINES);
    // Eje X
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
    // Eje Y
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);
    // Eje Z
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();
}

void drawCustomFigure() {
  glPushMatrix();
    glScalef(0.1f, 0.1f, 0.1f); 

    //CARAS 
    glBegin(GL_QUADS); 
        glColor3f(1.0f, 0.0f, 0.0f);
        //CARA 1
        glVertex3f(0.0f, 0.0f, 0.0f);   
        glVertex3f(0.0f, 37.0f, 0.0f);  
        glVertex3f(17.0f, 37.0f, 0.0f); 
        glVertex3f(17.0f, 0.0f, 0.0f); 
        
        glVertex3f(17.0f, 0.0f, 0.0f);   
        glVertex3f(17.0f, 17.0f, 0.0f);  
        glVertex3f(37.0f, 17.0f, 0.0f); 
        glVertex3f(37.0f, 0.0f, 0.0f);  
        
        glVertex3f(34.0f, 0.0f, 0.0f);   
        glVertex3f(34.0f, 27.0f, 0.0f);  
        glVertex3f(70.0f, 27.0f, 0.0f); 
        glVertex3f(70.0f, 0.0f, 0.0f);  
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.6f, 0.3f, 0.1f);
        //CARA 12
        glVertex3f(0.0f, 0.0f, 37.0f);   
        glVertex3f(0.0f, 37.0f, 37.0f);  
        glVertex3f(17.0f, 37.0f, 37.0f); 
        glVertex3f(17.0f, 0.0f, 37.0f); 
        
        glVertex3f(17.0f, 0.0f, 37.0f);   
        glVertex3f(17.0f, 17.0f, 37.0f);  
        glVertex3f(37.0f, 17.0f, 37.0f); 
        glVertex3f(37.0f, 0.0f, 37.0f);  
         
        glVertex3f(34.0f, 0.0f, 37.0f);   
        glVertex3f(34.0f, 27.0f, 37.0f);  
        glVertex3f(70.0f, 27.0f, 37.0f); 
        glVertex3f(70.0f, 0.0f, 37.0f);  

    glEnd();

    //CARA 2
    glBegin(GL_POLYGON); 
        glColor3f(0.0f, 1.0f, 0.0f); 
        glVertex3f(0.0f, 0.0f, 0.0f); 
        glVertex3f(0.0f, 37.0f, 0.0f); 
        glVertex3f(0.0f, 27.0f, 18.5f); 
        glVertex3f(0.0f, 37.0f, 37.0f); 
        glVertex3f(0.0f, 0.0f, 37.0f);
        
    glEnd();

    glBegin(GL_QUADS);
        // CARA 3
        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex3f(0.0f, 37.0f, 0.0f);
        glVertex3f(17.0f, 37.0f, 0.0f);
        glVertex3f(17.0f, 27.0f, 18.5f);
        glVertex3f(0.0f, 27.0f, 18.5f);
    glEnd();

    glBegin(GL_QUADS);
        // CARA 4
        glColor3f(0.5f, 0.0f, 0.5f);
        glVertex3f(0.0f, 27.0f, 18.5f);
        glVertex3f(17.0f, 27.0f, 18.5f);
        glVertex3f(17.0f, 37.0f, 37.0f);
        glVertex3f(0.0f, 37.0f, 37.0f);
    glEnd();

    //CARA 5
    glBegin(GL_POLYGON); 
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(17.0f, 17.0f, 0.0f); 
        glVertex3f(17.0f, 37.0f, 0.0f); 
        glVertex3f(17.0f, 27.0f, 18.5f); 
        glVertex3f(17.0f, 37.0f, 37.0f); 
        glVertex3f(17.0f, 17.0f, 37.0f); 
    glEnd();
    
    //CARA 6
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(17.0f,17.0f, 0.0f);   
        glVertex3f(34.0f, 17.0f, 0.0f);  
        glVertex3f(34.0f, 17.0f, 37.0f); 
        glVertex3f(17.0f, 17.0f, 37.0f); 
    glEnd();

    //CARA 7
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(34.0f,17.0f, 0.0f);   
        glVertex3f(34.0f, 27.0f, 0.0f);  
        glVertex3f(34.0f, 27.0f, 37.0f); 
        glVertex3f(34.0f, 17.0f, 37.0f); 
    glEnd();

    //CARA 8
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(34.0f,27.0f, 0.0f);   
        glVertex3f(51.0f, 27.0f, 0.0f);  
        glVertex3f(51.0f, 27.0f, 37.0f); 
        glVertex3f(34.0f, 27.0f, 37.0f); 
    glEnd();

    //CARA 9
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(51.0f, 27.0f, 0.0f);   
        glVertex3f(51.0f, 37.0f, 18.5f);  
        glVertex3f(51.0f, 27.0f, 37.0f); 
    glEnd();

    glBegin(GL_QUADS);
        // CARA 10
        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex3f(51.0f, 27.0f, 0.0f);
        glVertex3f(51.0f, 37.0f, 18.5f);
        glVertex3f(70.0f, 37.0f, 18.5f);
        glVertex3f(70.0f, 27.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        // CARA 11
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex3f(51.0f, 37.0f, 18.5f);
        glVertex3f(70.0f, 37.0f, 18.5f);
        glVertex3f(70.0f, 27.0f, 37.0f);
        glVertex3f(51.0f, 27.0f, 37.0f);
    glEnd();

    //CARA 13
    glBegin(GL_POLYGON);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(70.0f, 0.0f, 0.0f);
        glVertex3f(70.0f, 27.0f, 0.0f);   
        glVertex3f(70.0f, 37.0f, 18.5f);  
        glVertex3f(70.0f, 27.0f, 37.0f);
        glVertex3f(70.0f, 0.0f, 37.0f); 
    glEnd();

    glBegin(GL_QUADS);
        // CARA 14
        glColor3f(0.5f, 0.0f, 0.5f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(70.0f, 0.0f, 0.0f);
        glVertex3f(70.0f, 0.0f, 37.0f);
        glVertex3f(0.0f, 0.0f, 37.0f);
    glEnd();

    glPopMatrix();
}




void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Configurar la cámara
    gluLookAt(0.0, 3.0, 10.0,   // Posición de la cámara
              0.0, 0.0, 0.0,    // Hacia dónde mira
              0.0, 1.0, 0.0);   // Vector arriba

    // Aplicar Transformaciones en orden (Traslación -> Rotación -> Escalado)
    glTranslatef(transX, transY, transZ);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glScalef(scale, scale, scale);

    drawAxes();
    drawCustomFigure();

    glutSwapBuffers();
}

// PERSPECTIVA 3D
void reshape(int w, int h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0f / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f); 
    glMatrixMode(GL_MODELVIEW);
}

// USO DEL TECLADO (A,S,D,W)
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'w': transY += 0.5f; break; // Traslación arriba
        case 's': transY -= 0.5f; break; // Traslación abajo
        case 'a': transX -= 0.5f; break; // Traslación izquierda
        case 'd': transX += 0.5f; break; // Traslación derecha
        case '+': scale += 0.1f; break;  // Escalar más grande
        case '-': scale -= 0.1f; break;  // Escalar más pequeño
        case 27: exit(0); // Tecla ESC para salir
    }
    glutPostRedisplay();
}

// Eventos de clic del mouse
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = true;
            lastMouseX = x;
            lastMouseY = y;
        } else {
            isDragging = false;
        }
    }
}

// USO DEL MOUSE
void motion(int x, int y) {
    if (isDragging) {
        rotY += (x - lastMouseX);
        rotX += (y - lastMouseY);
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

void init() {
    glEnable(GL_DEPTH_TEST); // Activar profundidad para 3D
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Fondo oscuro
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Proyecto OpenGL - Laboratorio");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // Registramos la nueva función
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
    return 0;
}