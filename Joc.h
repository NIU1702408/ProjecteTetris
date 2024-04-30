#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Joc
{
public:
	Joc() { m_posicio.x = 0; m_posicio.y = 0; }
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:
	Tauler m_tauler;
	Figura m_figura;
	Posicio m_posicio;
};

#endif
