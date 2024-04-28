#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA_TAULER; i++)
		for (int j = 0; j < MAX_FILA_TAULER; j++)
			m_tauler[i][j] = COLOR_NEGRE;
}

Tauler::Tauler(ColorFigura tauler[MAX_FILA_TAULER][MAX_FILA_TAULER])
{
	for (int i = 0; i < MAX_FILA_TAULER; i++)
		for (int j = 0; j < MAX_FILA_TAULER; j++)
			m_tauler[i][j] = tauler[i][j];
}

bool Tauler::posicioValida(const Posicio& pos) const 
{
	bool esValid = true;

	if (0 > pos.x > MAX_COL_TAULER || 0 > pos.y )
		esValid = false;
	else
	{
		if (m_tauler[pos.x][pos.y] != COLOR_NEGRE)
			esValid = false;
	}

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
				pos_tmp.x = pos.x + i;
				pos_tmp.y = pos.y - j;

				esValid = posicioValida(pos_tmp);
			}
			j++;
		}
		i++;
	}

	return esValid;
}


void Tauler::eliminarFilesCompletades()
{
	// Buscar las filas completadas
	for (int i = 0; i < MAX_FILA_TAULER; ++i)
	{
		bool completa = true;
		int j = 0;

		while (j < MAX_COL_TAULER && completa)
		{
			if (m_tauler[i][j] == 0) {
				completa = false;
			}
		}

		if (completa)
		{
			for (int fila = i; fila < MAX_FILA_TAULER; ++fila)
				for (int k = 0; k < MAX_COL_TAULER; ++k)
					m_tauler[fila][k] = m_tauler[fila - 1][k];

			for (int k = 0; k < MAX_COL_TAULER; ++k)
				m_tauler[0][k] = COLOR_NEGRE;
		}

	}
}

void Tauler::collocarFigura( Figura figura,const Posicio& pos) // no comprovo si es valid
{
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; i < figura.getMida(); j++)
		{
			if (figura.getFigura(i, j) != NO_COLOR)
				m_tauler[pos.x + i][pos.y - j] = figura.getColor();
		}
	figura.setPosicio(pos);
}
