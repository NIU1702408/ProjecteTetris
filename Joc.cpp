#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	Posicio posicio;
	int tipus, gir;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> tipus;
		m_figura.incialitza(TipusFigura(tipus));

		fitxer >> posicio.x >> posicio.y;
		m_figura.setPosicio(posicio);
		
		fitxer >> gir;
		for (int i = 0; i < gir; i++)
			m_figura.girar(GIR_HORARI);

		for (int i = 0; i < MAX_ALCADA; i++)
			for (int j = 0; j < MAX_AMPLADA; j++)
			{
				int color;
				fitxer >> color;

				m_tauler.setTauler(ColorFigura(color), i, j);
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
	else
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());

	return gira;
}

bool Joc::mouFigura(int dirX)
{
	bool mou = true;
	m_figura.desplaçar(dirX);

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
		if (dirX == -1)
			m_figura.desplaçar(1);
		else
			m_figura.desplaçar(-1);
		mou = false;
	}
	else
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
	m_posicio = m_figura.getPosicio();

	return mou;
}

int Joc::baixaFigura()
{
	bool baixa = true;
	m_figura.baixar(1);

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
		m_figura.baixar(-1);
		baixa = false;
	}
	else
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
	m_posicio = m_figura.getPosicio();

	return baixa;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
			cout << int(m_tauler.getTauler(i, j)) << " ";
		cout << endl;
	}
}
