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

    if (fila < 0 || columna < 0 || fila + figura.getMida() > MAX_FILA || columna + figura.getMida() > MAX_COL) {
        esValid = false;
    }

    // Comprobar si la figura colisiona con otras figuras en el tauler
    for (int i = 0; i < figura.getMida(); ++i)
        for (int j = 0; j < figura[0].size(); ++j)
            if (figura[i][j] != 0 && tauler[fila + i][columna + j] != 0)
                esValid = false;

    return true;
}


void Tauler::eliminarFilesCompletades()
{
    // Buscar las filas completadas
    for (int i = 0; i < files; ++i) {
        bool completa = true;
        for (int j = 0; j < columnes; ++j) {
            if (tauler[i][j] == 0) {
                completa = false;
                break;
            }
        }
        if (completa) {
            filesCompletades.push_back(i);
        }
    }

    // Eliminar las filas completadas y añadir nuevas filas vacías arriba
    for (int fila : filesCompletades) {
        tauler.erase(tauler.begin() + fila);
        tauler.insert(tauler.begin(), std::vector<int>(columnes, 0));
    }
}

void Tauler::collocarFigura()
{

}