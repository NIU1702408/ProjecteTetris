#include "Tauler.h"

Tauler::Tauler()
{
	for(int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = NO_COLOR;
}

Tauler::Tauler(ColorFigura tauler[MAX_FILA][MAX_FILA])
{
	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = tauler[i][j];
}

bool Tauler::esMovimentValid(Figura figura, int fila, int columna)
{
    bool esValid = true;
    int esquerra = 0, dreta = 0, amunt = 0, avall = 0;
    int i = 0, j = 0;

    //se tiene que revisar, supongo que midaFigura devuelve 4 variables con posiciones respecto el punto medio de la figura
    figura.midaFigura(esquerra, dreta, amunt, avall); 

    //comprueva si colisiona con los limites del tauler
    if (fila - avall < 0 || columna - esquerra < 0 || fila + amunt > MAX_FILA || columna + dreta > MAX_COL)
        esValid = false;

    // Comprobar si la figura colisiona con otras figuras en el tauler
    while (i < MAX_ALCADA && esValid)
    {
        while (j < MAX_AMPLADA && esValid)
        {
            if (figura.getMatriu(i, j) && m_tauler[fila - esquerra + i][columna - amunt + j] != COLOR_NEGRE)
                esValid = false;
            j++;
        }
        i++;
    }
            
    return esValid;
}


void Tauler::eliminarFilesCompletades()
{
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
	        for (int fila = i; fila < MAX_FILA; ++fila )
	            for (int k = 0; k < MAX_COL; ++k)
	                m_tauler[fila][k] = m_tauler[fila - 1][k];
	
	        for (int k = 0; k < MAX_COL; ++k)
	            m_tauler[0][k] = COLOR_NEGRE;
	    }
	
	}
}

void Tauler::collocarFigura(Figura figura) //colloco figura a la posicio guardada, no comprovo si es valid
{
	int esquerra = 0, dreta = 0, amunt = 0, avall = 0;

	//se tiene que revisar, supongo que medidaFigura devuelve 4 variables con posiciones respecto el punto medio de la figura
	figura.midaFigura(esquerra, dreta, amunt, avall);

	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; i < MAX_AMPLADA; j++)
			m_tauler[m_fila - esquerra + i][m_columna - amunt + j] = figura.getColor();
}
