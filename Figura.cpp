#include "Figura.h"

Figura::Figura()
{
	m_color = NO_COLOR;
	m_tipusFigura = NO_FIGURA;

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_matriuFigura[i][j] = false;

}

Figura::Figura(TipusFigura tipusFigura, ColorFigura color)
{
	m_tipusFigura = tipusFigura;
	m_color = color;
	int mida = 0;

	switch (tipusFigura)
	{
		case FIGURA_T:
		case FIGURA_L:
		case FIGURA_J:
		case FIGURA_Z:
		case FIGURA_S:
			mida = 3;
			break;
		case FIGURA_O:
			mida = 2;
			break;
		case FIGURA_I:
			mida = 4;
			break;
	}

	m_mida = mida;

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_matriuFigura[i][j] = false;

	void inicialitzaFigura();
}

void Figura::inicialitzaFigura()
{
	switch (m_tipusFigura)
	{
		case FIGURA_O:
			m_matriuFigura[0][0] = true;
			m_matriuFigura[0][1] = true;
			m_matriuFigura[1][0] = true;
			m_matriuFigura[1][1] = true;
			break;
		case FIGURA_I:
			m_matriuFigura[1][0] = true;
			m_matriuFigura[1][1] = true;
			m_matriuFigura[1][2] = true;
			m_matriuFigura[1][3] = true;
			break;
		case FIGURA_T:
			m_matriuFigura[0][1] = true;
			m_matriuFigura[1][0] = true;
			m_matriuFigura[1][1] = true;
			m_matriuFigura[1][2] = true;
			break;
		case FIGURA_L:
			m_matriuFigura[0][1] = true;
			m_matriuFigura[1][1] = true;
			m_matriuFigura[2][1] = true;
			m_matriuFigura[2][2] = true;
			break;
		case FIGURA_J:
			m_matriuFigura[0][1] = true;
			m_matriuFigura[1][1] = true;
			m_matriuFigura[2][0] = true;
			m_matriuFigura[2][1] = true;
			break;
		case FIGURA_Z:
			m_matriuFigura[0][0] = true;
			m_matriuFigura[0][1] = true;
			m_matriuFigura[1][1] = true;
			m_matriuFigura[1][2] = true;
			break;
		case FIGURA_S:
			m_matriuFigura[0][1] = true;
			m_matriuFigura[0][2] = true;
			m_matriuFigura[1][0] = true;
			m_matriuFigura[1][1] = true;
			break;
	}
}

void Figura::transposarFigura()
{
	bool transposada[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < MAX_ALCADA; ++i) {
		for (int j = 0; j < MAX_AMPLADA; ++j) {
			transposada[j][i] = m_matriuFigura[i][j];
		}
	}

	for (int i = 0; i < MAX_ALCADA; ++i) {
		for (int j = 0; j < MAX_AMPLADA; ++j) {
			m_matriuFigura[i][j] = transposada[i][j];
		}
	}

}

void Figura::invertirFigura()
{

}
