#ifndef FIGURA_H
#define FIGURA_H

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

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura();
    Figura(TipusFigura figura, ColorFigura color);

    TipusFigura getTipus() const { return m_tipusFigura; }
    ColorFigura getColor() const { return m_color; }
    int getMida() const { return m_mida; }
    void transposarFigura();
    void invertirFigura();

private:
    void inicialitzaFigura();

    TipusFigura m_tipusFigura;
    ColorFigura m_color;
    int m_mida;
    ColorFigura m_matriuFigura[MAX_ALCADA][MAX_AMPLADA];

};


#endif
