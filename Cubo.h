#pragma once
#include "Cubinho.h"
#include <GL/gl.h>

class Cubo {
private:
    // Coordenadas do centro do cubo
    float cx, cy, cz;

    // Arrays para armazenar os ângulos de rotação em cada eixo para cada cubinho
    float rotsX[27];
    float rotsY[27];
    float rotsZ[27];

    // Array de objetos Cubinho representando os cubinhos no cubo
    Cubinho cubinhos[27];

    // Mapeamento para reorganizar a ordem dos cubinhos após rotações
    int mapa2[27];

    // Array para rastrear a presença dos cubinhos no cubo
    bool mapa[27];

    // Flag para indicar se há uma rotação em andamento
    bool flagRot = false;

    // Tamanho da aresta dos cubinhos
    float largAresta;

    // Ângulo temporário para rotação
    float rotTemp = 0;

    // Identificador único para o cubo
    int id_;
    static int proxId_;

    // Funções privadas para rotacionar um lado do cubo no sentido horário
    void ladoXHorario(float dr, char cor);
    void ladoYHorario(float dr, char cor);
    void ladoZHorario(float dr, char cor);

public:

    Cubo(float _cx = 0.0f, float _cy = 0.0f, float _cz = 0.0f, float _largAresta = 1.0f);

    // Função para exibir/renderizar o cubo
    void displayCubo();



    // Métodos para reagir a teclas específicas do teclado
    void tecla1();
    void tecla2();
    void tecla3();
    void tecla4();
    void tecla5();
    void tecla6();
    void tecla7();
    void tecla8();
    void tecla9();
    void tecla0();
    void teclaPonto();

    // Rearranjar o mapeamento após rotações
    void rearranjaMapa(char c);

    // Métodos para realizar rotações horárias em diferentes lados do cubo
    void verdeHorario();
    void azulHorario();
    void vermelhoHorario();
    void laranjaHorario();
    void amareloHorario();
    void brancoHorario();

    // Métodos para realizar rotações anti-horárias em diferentes lados do cubo
    void verdeAntiHorario();
    void azulAntiHorario();
    void vermelhoAntiHorario();
    void laranjaAntiHorario();
    void amareloAntiHorario();
    void brancoAntiHorario();

    // Funções amigas para acessar funções privadas de rotação
    friend void giraVerdeHorario(int id);
    friend void giraAzulHorario(int id);
    friend void giraVermelhoHorario(int id);
    friend void giraLaranjaHorario(int id);
    friend void giraAmareloHorario(int id);
    friend void giraBrancoHorario(int id);

    friend void giraVerdeAntiHorario(int id);
    friend void giraAzulAntiHorario(int id);
    friend void giraVermelhoAntiHorario(int id);
    friend void giraLaranjaAntiHorario(int id);
    friend void giraAmareloAntiHorario(int id);
    friend void giraBrancoAntiHorario(int id);

    // Retorna verdadeiro se uma rotação estiver em andamento
    bool espera() { return flagRot; }

    // Funções para salvar e carregar o estado do cubo
    void salvar();
    void carregar();

    // Exibe o ID único do cubo
    void printId();
};
