#include "Cubo.h"
#include <GL/glut.h>
#include <cstdlib> // srand, rand
#include <ctime>   // time
#include <iostream>
#include <GL/gl.h>

Cubo cubo2;

float angTheta = 135;
float angPhi = 45;
float angGamma = 90;
float s = 1;

bool mov = false;
bool stop = true;
int xb, yb;

using namespace std;

float dOrthox = 10;
float dOrthoy = 5;
float dOrthoz = 10;

// Função para configurar a matriz de projeção e a matriz de modelo e visualização
void config() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dOrthox, dOrthox, -dOrthoy, dOrthoy, -dOrthoz, dOrthoz);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(angGamma, 0, 0, 1);
    glRotatef(angPhi, 0, 1, 0);
    glRotatef(angTheta, 0, 0, 1);
    glScalef(s, s, s);
}

void iluminacao(){
    //luz ambien 0.2
    //ambiente, difuso, specular

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    float intensidadeDaLuz[] = {0.8f, 0.8f, 0.8f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, intensidadeDaLuz);

    float light[4][4] = {
            {0.1f, 0.1f, 0.1f, 0.1f}, //ambiente
            {0.8f, 0.8f, 0.8f, 0.8f} ,//difuso
            {1.f, 1.f, 1.f, 1.f }, //specular
            {0.f, 0.f, 1.f, 1.f} //posição
    };

    glLightfv(GL_LIGHT0, GL_AMBIENT, &light[0][0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, &light[1][0]);
    glLightfv(GL_LIGHT0, GL_SPECULAR, &light[2][0]);
    glLightfv(GL_LIGHT0, GL_POSITION, &light[3][0]);

}


// Função de renderização
void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    iluminacao();

    cubo2.displayCubo();


    glutSwapBuffers();
}

// Manipulador de eventos de clique do mouse
void botao(int b, int state, int x, int y) {
    if (b == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            xb = x;
            yb = y;
            mov = true;
        }
        else
            mov = false;
    }
}

// Manipulador de eventos de movimento do mouse
void botao_mov(int x, int y) {
    if (mov) {
        float dx = x - xb;
        float dy = y - yb;

        angTheta += dx;
        angPhi -= dy;
        if (angPhi > 180)
            angPhi = 180.f;
        else if (angPhi < 0)
            angPhi = 0.f;

        config();
        glutPostRedisplay();
        xb = x;
        yb = y;
    }
}

// Manipulador de eventos do teclado
void teclado(unsigned char key, int x, int y) {
    cout << key << endl;
    switch (key) {
        case '1':
            cubo2.tecla1();
            glutPostRedisplay();
            break;
        case '2':
            cubo2.tecla2();
            glutPostRedisplay();
            break;
        case '3':
            cubo2.tecla3();
            glutPostRedisplay();
            break;
        case '4':
            cubo2.tecla4();
            glutPostRedisplay();
            break;
        case '5':
            cubo2.tecla5();
            glutPostRedisplay();
            break;
        case '6':
            cubo2.tecla6();
            glutPostRedisplay();
            break;
        case '7':
            cubo2.tecla7();
            glutPostRedisplay();
            break;
        case '8':
            cubo2.tecla8();
            glutPostRedisplay();
            break;
        case '9':
            cubo2.tecla9();
            glutPostRedisplay();
            break;
        case '0':
            cubo2.tecla0();
            glutPostRedisplay();
            break;
        case '.':
            cubo2.teclaPonto();
            glutPostRedisplay();
            break;

        case 'r':
            cubo2.vermelhoHorario();
            break;
        case 'R':
            cubo2.vermelhoAntiHorario();
            break;
        case 'y':
            cubo2.amareloHorario();
            break;
        case 'Y':
            cubo2.amareloAntiHorario();
            break;
        case 'b':
            cubo2.azulHorario();
            break;
        case 'B':
            cubo2.azulAntiHorario();
            break;
        case 'g':
            cubo2.verdeHorario();
            break;
        case 'G':
            cubo2.verdeAntiHorario();
            break;
        case 'w':
            cubo2.brancoHorario();
            break;
        case 'W':
            cubo2.brancoAntiHorario();
            break;
        case 'o':
            cubo2.laranjaHorario();
            break;
        case 'O':
            cubo2.laranjaAntiHorario();
            break;

        case 'p':
        case 'P':
            stop = !stop;
            break;

        case 's':
        case 'S':
            cubo2.salvar();
            glutPostRedisplay();
            break;
        case 'l':
        case 'L':
            cubo2.carregar();
            glutPostRedisplay();
            break;

        case '+':
            s *= 1.1;
            config();
            glutPostRedisplay();
            break;

        case '-':
            s /= 1.1;
            config();
            glutPostRedisplay();
            break;

        case ' ':
            cubo2.printId();
            glutPostRedisplay();
            break;

        default:
            break;
    }
}

// Função de execução contínua para animação
void executa() {
    if (!stop && !cubo2.espera()) {
        char movs[] = {'y', 'Y', 'w', 'W', 'b', 'B', 'g', 'G', 'o', 'O', 'r', 'R'};
        int i = rand() % 12;
        teclado(movs[i], 0, 0);
    }
    if (!stop) {
        angTheta += 0.5;
        config();
        glutPostRedisplay();
    }
}


// Manipulador de evento de redimensionamento da janela
void reshape(int x, int y) {
    dOrthox = float(x) / float(y) * dOrthoy;

    glViewport(0, 0, x, y);
    config();
}

int main(int argc, char **argv) {
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 400);
    glutCreateWindow("Cubo Magico");
    config();
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutIdleFunc(executa);
    glutMouseFunc(botao);
    glutMotionFunc(botao_mov);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

