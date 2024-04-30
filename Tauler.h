#ifndef TAULER_H
#define TAULER_H
#include "figura.h"

class Tauler
{
public:
	Tauler();
	Tauler(ColorFigura tauler[MAX_FILA_TAULER][MAX_FILA_TAULER]);

	ColorFigura getTauler(const int& x, const int& y) const { return m_tauler[x][y]; }
	void setTauler(ColorFigura color, int posX, int posY) { m_tauler[posX][posY] = color; }

	bool esMovimentValid(const Figura& figura,const Posicio& pos) const;
	void eliminarFilesCompletades();
	void collocarFigura(Figura figura,const Posicio& pos);
private:
	bool posicioValida(const Posicio& pos) const;

	ColorFigura m_tauler[MAX_FILA_TAULER][MAX_FILA_TAULER];
};
#endif
