#ifndef FIGURA_H
#define FIGURA_H

const int MAX_FILA = 8;
const int MAX_COL = 8;

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
} SentitDesplacament;

class Figura
{
public:
    Figura();
    Figura(TipusFigura figura);

    ColorFigura getColor() const { return m_color; }
    int getMida() const { return m_mida; }
    ColorFigura getFigura(const int& x, const int& y) const { return m_figura[x][y]; }
    Posicio getPosicio() const { return m_posicio; }
    void setPosicio(const Posicio& pos) { m_posicio = pos; }

    void girar(const DireccioGir& gir);
    void baixar();
    void desplacar(const SentitDesplacament& sentit);
private:
    TipusFigura m_tipusFigura;
    ColorFigura m_color;
    Posicio m_posicio;
    int m_mida;
    ColorFigura m_figura[MAX_COL][MAX_FILA];

};


#endif
