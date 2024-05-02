#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = COLOR_NEGRE;
}

Tauler::Tauler(ColorFigura tauler[MAX_COL][MAX_FILA])
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = tauler[i][j];
}

bool Tauler::posicioValida(const Posicio& pos) const 
{
	bool esValid = true;

	if (0 > pos.horitzontal > MAX_FILA || pos.vertical > MAX_COL )
		esValid = false;
	else
		if (m_tauler[pos.vertical][pos.horitzontal] != COLOR_NEGRE)
			esValid = false;

	return esValid;
}

bool Tauler::esMovimentValid(const Figura& figura,const Posicio& pos) const
{
	bool esValid = true;
	int i = 0, j = 0;

	while (i < figura.getMida() && esValid)
	{
		while (j < figura.getMida() && esValid)
		{
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				Posicio pos_tmp;
				pos_tmp.vertical = pos.vertical + i;
				pos_tmp.horitzontal = pos.horitzontal + j;

				esValid = posicioValida(pos_tmp);
			}
			j++;
		}
		i++;
	}

	return esValid;
}


int Tauler::eliminarFilesCompletades()
{
	int nCompletades = 0;

	// Buscar las filas completadas
	for (int i = 0; i < MAX_FILA; ++i)
	{
		bool completa = true;
		int j = 0;

		while (j < MAX_COL && completa)
		{
			if (m_tauler[i][j] == 0) {
				completa = false;
			}
		}

		if (completa)
		{
			nCompletades++;
			for (int fila = i; fila < MAX_FILA; ++fila)
				for (int k = 0; k < MAX_COL; ++k)
					m_tauler[fila][k] = m_tauler[fila - 1][k];

			for (int k = 0; k < MAX_COL; ++k)
				m_tauler[0][k] = COLOR_NEGRE;
		}

	}
	return nCompletades;
}

void Tauler::eliminarFigura(Figura figura, const Posicio& pos)
{
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; j < figura.getMida(); j++)
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				m_tauler[pos.vertical + i][pos.horitzontal + j] = COLOR_NEGRE;
			}
}

void Tauler::collocarFigura( Figura figura,const Posicio& pos) // no comprovo si es valid
{
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; j < figura.getMida(); j++)
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				m_tauler[pos.vertical + i][pos.horitzontal + j] = figura.getColor();
			}
	figura.setPosicio(pos);
}
