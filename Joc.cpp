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
		m_figura = Figura(static_cast<TipusFigura>(tipus));

		fitxer >> posicio.x >> posicio.y;
		m_figura.setPosicio(posicio);
		
		
		fitxer >> gir;
		for (int i = 0; i < gir; i++)
			m_figura.girar(GIR_HORARI);

		for (int i = 0; i < MAX_FILA_TAULER; i++)
			for (int j = 0; j < MAX_COL_TAULER; j++)
			{
				int color;
				fitxer >> color;

				m_tauler.setTauler(ColorFigura(color), i, j);
			}
		
		m_tauler.collocarFigura(m_figura, posicio);
		
		
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
	SentitDesplacament dir;
	
	//determinar la direccio de com mourem la figura
	if (dirX > 0)
        dir = DRETA;
    else if (dirX < 0)
        dir = ESQUERRA;
    else
        mou = false; // si dirX = 0, no hi ha desplaçament
	
	
    // fer el desplaçament
    if (mou) {
        m_figura.desplacar(dir);
        
        //veure si el moviment és vàlid
    	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
    	{
    		if (dirX > 0)
    			m_figura.desplacar(DRETA); //desplaçar a l'esquerra
    		else 
    			m_figura.desplacar(ESQUERRA); //desplaçar a la dreta
    	}
    	else
    		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
    		
    	//actualitzar posicio de la figura
    	m_posicio = m_figura.getPosicio();
    }
	return mou;
}

int Joc::baixaFigura()
{
	bool baixa = true;
	
	m_figura.baixar();

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
	    //Si la figura no pot baixar més, no la col·loquem
		baixa = false;
	}
	else //si la figura pot baixar, la col·loquem a la seva nova posició
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
	
	//Actualitzar nova posicio de la figura
	m_posicio = m_figura.getPosicio();

	return baixa ? 1 : 0; //retornem un 1 si pot baixar i sino un 0;
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    
    fitxer.open(nomFitxer);
    
    if (fitxer.is_open())
    {
    	for (int i = 0; i < MAX_FILA_TAULER; i++)
    	{
    		for (int j = 0; j < MAX_COL_TAULER; j++)
    			fitxer << m_tauler.getTauler(i, j);

    		fitxer << endl;
    	}
    	
    	fitxer.close();
    }
}
