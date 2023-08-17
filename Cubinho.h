#pragma once
#include <GL/gl.h>
// Declaração da classe Cubinho que representa um cubo tridimensional
class Cubinho {
private:
    // Variáveis para armazenar as coordenadas do centro do cubo (cx, cy, cz)
    float cx, cy, cz;

    // Variáveis para armazenar os ângulos de rotação em torno dos eixos (rotTheta, rotPhi, rotGamma)
    float rotTheta = 0;
    float rotPhi = 0;
    float rotGamma = 0;

    // Variável para armazenar o tamanho das arestas do cubo
    float largAresta;

public:

// Função para incializar as variáveis para sombreamento e iluminação
    void init();
    // Construtor da classe Cubinho
    Cubinho(float _cx = 0.f, float _cy = 0.f, float _cz = 0.f, float _largAresta = 1.f) {
        cx = _cx;
        cy = _cy;
        cz = _cz;
        largAresta = _largAresta;
    }

    // Métodos para configurar o tamanho das arestas do cubo e as coordenadas do centro
    void setAresta(float _largAresta) { largAresta = _largAresta; }
    void setCX(float _cx) { cx = _cx; }
    void setCY(float _cy) { cy = _cy; }
    void setCZ(float _cz) { cz = _cz; }

    // Método para configurar o centro do cubo
    void setCentro(float _cx, float _cy, float _cz) {
        cx = _cx;
        cy = _cy;
        cz = _cz;
    }

    // Métodos para configurar os ângulos de rotação em torno dos eixos
    void setTheta(float _rotTheta) { rotTheta = _rotTheta; }
    void setPhi(float _rotPhi) { rotPhi = _rotPhi; }
    void setGamma(float _rotGamma) { rotGamma = _rotGamma; }

    // Declaração de um método para exibir/renderizar o cubo
    void displayCubinho();

    // Declaração de métodos para obter informações sobre as cores das faces do cubo
    char corX();
    char corY();
    char corZ();
    char corXn();
    char corYn();
    char corZn();

    // Declaração de amizade com a classe Cubo, permitindo acesso aos membros privados
    friend class Cubo;
};
