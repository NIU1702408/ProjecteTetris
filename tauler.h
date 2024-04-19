#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	Tauler(ColorFigura tauler[MAX_FILA][MAX_FILA]);
	bool esMovimentValid(Figura figura, int fila, int columna);
	void eliminarFilesCompletades();
	void collocarFigura();
private:
	int m_fila;
	int m_columna;
	ColorFigura m_tauler[MAX_FILA][MAX_FILA];

};
#endif
