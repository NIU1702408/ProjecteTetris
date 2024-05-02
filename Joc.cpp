#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	Posicio posicio;
	int tipus, gir;
	ifstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> tipus;
		m_figura.incialitza(TipusFigura(tipus));

		fitxer >> posicio.vertical >> posicio.horitzontal;
		if (m_figura.getMida() == 3)
		{
			posicio.vertical--;
			posicio.horitzontal--;
		}
		else
			if (m_figura.getMida() == 4)
			{
				posicio.horitzontal -= 2;
				posicio.vertical--;
			}

		m_figura.setPosicio(posicio);
		m_posicio = posicio;
		
		fitxer >> gir;
		for (int i = 0; i < gir; i++)
			m_figura.girar(GIR_HORARI);

		for (int i = 0; i < MAX_COL; i++)
		{
			for (int j = 0; j < MAX_FILA; j++)
			{
				int color;
				fitxer >> color;

				m_tauler.setTauler(ColorFigura(color), i, j);
			}
		}

		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool gira = true;
	m_figura.girar(direccio);

	if (!m_tauler.esMovimentValid(m_figura, m_posicio))
	{
		if (direccio == GIR_HORARI)
			m_figura.girar(GIR_ANTI_HORARI);
		else
			m_figura.girar(GIR_HORARI);
		gira = false;
	}

	return gira;
}

bool Joc::mouFigura(int dirX)
{
	bool mou = true;
	m_figura.desplacar(dirX);

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
		if (dirX == -1)
			m_figura.desplacar(1);
		else
			m_figura.desplacar(-1);
		mou = false;
	}
	else
		m_posicio = m_figura.getPosicio();

	return mou;
}

int Joc::baixaFigura()
{
	int nFiles = 0;
	m_figura.baixar(1);

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
		m_figura.baixar(-1);
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
		nFiles = m_tauler.eliminarFilesCompletades();
	}
	else
		m_posicio = m_figura.getPosicio();

	return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	int i, j;
	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		m_tauler.collocarFigura(m_figura, m_posicio);
		for (int i = 0; i < MAX_COL; i++)
		{
			for (int j = 0; j < MAX_FILA; j++)
				fitxer << int(m_tauler.getTauler(i, j)) << " ";
			fitxer << endl;
		}
		m_tauler.eliminarFigura(m_figura, m_posicio);
		fitxer.close();
	}
}
