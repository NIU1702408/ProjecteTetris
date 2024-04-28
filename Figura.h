
#ifndef FIGURA_H
#define FIGURA_H

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

const int MAX_FILA_TAULER = 8;
const int MAX_COL_TAULER = 8;

typedef struct
{
    int x;
    int y;
} Posicio;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

typedef enum
{
    DRETA = 0,
    ESQUERRA
} SentitDesplaçament;

class Figura
{
public:
    Figura();
    Figura(TipusFigura figura, ColorFigura color);
      
    TipusFigura getTipus() const { return m_tipusFigura; }
    ColorFigura getColor() const { return m_color; }
    void getMatriuFigura(ColorFigura m[MAX_AMPLADA][MAX_ALCADA]) const;
    int getMida() const { return m_mida; }
    bool getFigura(int x, int y) const { return m_figura[x][y]; }
    void setFigura(int x, int y, bool valor) { m_figura[x][y] = valor; }
    

    void girar(DireccioGir gir);
    void baixar();
    void desplaçar(SentitDesplaçament sentit);
    // Tal vez falte una funcion para recuperar la formma actual de la figura¿
private:
    TipusFigura m_tipusFigura;
    ColorFigura m_color;
    Posicio m_posicio;
    int m_mida;
    bool m_figura[MAX_AMPLADA][MAX_ALCADA];

};


#endif
