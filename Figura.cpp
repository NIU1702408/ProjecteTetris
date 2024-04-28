#include "figura.h"

Figura::Figura()
{
	m_mida = 0;
	m_color = NO_COLOR;
	m_tipusFigura = NO_FIGURA;
	m_posicio.x = 0;
	m_posicio.y = MAX_FILA_TAULER;

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_figura[i][j] = NO_COLOR;

}

Figura::Figura(TipusFigura tipusFigura, ColorFigura color)
{
	m_mida = 0;
	m_tipusFigura = tipusFigura;
	m_color = color;
	m_posicio.x = 0;
	m_posicio.y = MAX_FILA_TAULER;

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_figura[i][j] = NO_COLOR;

	switch (m_tipusFigura)
	{
	case FIGURA_O:
		m_mida = 2;
		m_figura[0][0] = COLOR_GROC;
		m_figura[0][1] = COLOR_GROC;
		m_figura[1][0] = COLOR_GROC;
		m_figura[1][1] = COLOR_GROC;
		break;
	case FIGURA_I:
		m_mida = 4;
		m_figura[1][0] = COLOR_BLAUCEL;
		m_figura[1][1] = COLOR_BLAUCEL;
		m_figura[1][2] = COLOR_BLAUCEL;
		m_figura[1][3] = COLOR_BLAUCEL;
		break;
	case FIGURA_T:
		m_mida = 3;
		m_figura[0][1] = COLOR_MAGENTA;
		m_figura[1][0] = COLOR_MAGENTA;
		m_figura[1][1] = COLOR_MAGENTA;
		m_figura[1][2] = COLOR_MAGENTA;
		break;
	case FIGURA_L:
		m_mida = 3;
		m_figura[0][1] = COLOR_TARONJA;
		m_figura[1][1] = COLOR_TARONJA;
		m_figura[2][1] = COLOR_TARONJA;
		m_figura[2][2] = COLOR_TARONJA;
		break;
	case FIGURA_J:
		m_mida = 3;
		m_figura[0][1] = COLOR_BLAUFOSC;
		m_figura[1][1] = COLOR_BLAUFOSC;
		m_figura[2][0] = COLOR_BLAUFOSC;
		m_figura[2][1] = COLOR_BLAUFOSC;
		break;
	case FIGURA_Z:
		m_mida = 3;
		m_figura[0][0] = COLOR_VERMELL;
		m_figura[0][1] = COLOR_VERMELL;
		m_figura[1][1] = COLOR_VERMELL;
		m_figura[1][2] = COLOR_VERMELL;
		break;
	case FIGURA_S:
		m_mida = 3;
		m_figura[0][1] = COLOR_VERD;
		m_figura[0][2] = COLOR_VERD;
		m_figura[1][0] = COLOR_VERD;
		m_figura[1][1] = COLOR_VERD;
		break;
	}
}

void Figura::girar(const DireccioGir& gir)
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];
	ColorFigura invertir[MAX_ALCADA][MAX_AMPLADA];

	// Transposa matriu
	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
			transposada[j][i] = m_figura[i][j];

	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
			m_figura[i][j] = transposada[i][j];

	//Inverteix matriu
	if (gir == GIR_HORARI)
	{
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				invertir[i][j] = m_figura[i][m_mida - 1 - j];
	}
	else
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				invertir[i][j] = m_figura[m_mida - 1 - i][j];

	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
			m_figura[i][j] = invertir[i][j];
}

void Figura::baixar()
{
	if (m_posicio.y > 0)
		m_posicio.y--;
}

void Figura::desplaçar(const SentitDesplaçament& sentit)
{
	if (sentit == ESQUERRA)
	{
		if (m_posicio.x > 0)
			m_posicio.x++;
	}
	else
	{
		if (m_posicio.x < MAX_COL_TAULER)
			m_posicio.x++;
	}
}
