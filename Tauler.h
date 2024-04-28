#ifndef TAULER_H
#define TAULER_H
#include "figura.h"

class Tauler
{
public:
	Tauler();
	Tauler(ColorFigura tauler[MAX_FILA_TAULER][MAX_FILA_TAULER]);
	bool esMovimentValid(const Figura& figura,const Posicio& pos) const;
	void eliminarFilesCompletades();
	void collocarFigura(Figura figura,const Posicio& pos);
private:
	bool posicioValida(const Posicio& pos) const;

	ColorFigura m_tauler[MAX_FILA_TAULER][MAX_FILA_TAULER];
};
#endif
