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
		m_matriuFigura[0][0] = m_color;
		m_matriuFigura[0][1] = m_color;
		m_matriuFigura[1][0] = m_color;
		m_matriuFigura[1][1] = m_color;
		break;
	case FIGURA_I:
		m_matriuFigura[1][0] = m_color;
		m_matriuFigura[1][1] = m_color;
		m_matriuFigura[1][2] = m_color;
		m_matriuFigura[1][3] = m_color;
		break;
	case FIGURA_T:
		m_matriuFigura[0][1] = m_color;
		m_matriuFigura[1][0] = m_color;
		m_matriuFigura[1][1] = m_color;
		m_matriuFigura[1][2] = m_color;
		break;
	case FIGURA_L:
		m_matriuFigura[0][1] = m_color;
		m_matriuFigura[1][1] = m_color;
		m_matriuFigura[2][1] = m_color;
		m_matriuFigura[2][2] = m_color;
		break;
	case FIGURA_J:
		m_matriuFigura[0][1] = m_color;
		m_matriuFigura[1][1] = m_color;
		m_matriuFigura[2][0] = m_color;
		m_matriuFigura[2][1] = m_color;
		break;
	case FIGURA_Z:
		m_matriuFigura[0][0] = m_color;
		m_matriuFigura[0][1] = m_color;
		m_matriuFigura[1][1] = m_color;
		m_matriuFigura[1][2] = m_color;
		break;
	case FIGURA_S:
		m_matriuFigura[0][1] = m_color;
		m_matriuFigura[0][2] = m_color;
		m_matriuFigura[1][0] = m_color;
		m_matriuFigura[1][1] = m_color;
		break;
	}
}

void Figura::transposarFigura()
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < m_mida; ++i) {
		for (int j = 0; j < m_mida; ++j) {
			transposada[j][i] = m_matriuFigura[i][j];
		}
	}

	for (int i = 0; i < m_mida; ++i) {
		for (int j = 0; j < m_mida; ++j) {
			m_matriuFigura[i][j] = transposada[i][j];
		}
	}

}

void Figura::invertirFigura(DireccioGir gir)
{	
	ColorFigura invertir[MAX_ALCADA][MAX_AMPLADA];

	if (m_gir = GIR_HORARI)
	{
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				invertir[i][j] = m_matriuFigura[i][m_mida-1-j];
	}
	else
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				invertir[i][j] = m_matriuFigura[m_mida-1-i][j];

}
