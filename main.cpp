#include <iostream>
#include <list>

std::list<int> obtenerPosiblesMovimientosDesdeCasilla(int casilla) {
    std::list<int> posiblesMovimientosDesdeCasilla;

    if (casilla == 0) {
        posiblesMovimientosDesdeCasilla = {6, 4};
    } else if (casilla == 1) {
        posiblesMovimientosDesdeCasilla = {6, 8};
    } else if (casilla == 2) {
        posiblesMovimientosDesdeCasilla = {7, 9};
    } else if (casilla == 3) {
        posiblesMovimientosDesdeCasilla = {4, 8};
    } else if (casilla == 4) {
        posiblesMovimientosDesdeCasilla = {3, 9, 0};
    } else if (casilla == 6) {
        posiblesMovimientosDesdeCasilla = {1, 7, 0};
    } else if (casilla == 7) {
        posiblesMovimientosDesdeCasilla = {6, 2};
    } else if (casilla == 8) {
        posiblesMovimientosDesdeCasilla = {1, 3};
    } else if (casilla == 9) {
        posiblesMovimientosDesdeCasilla = {2, 4};
    }

    return posiblesMovimientosDesdeCasilla;
}

/**
 * Desde una casilla de partida, devuelve el número de movimientos totales que se pueden hacer
 * @param casillaActual la casilla actual
 * @param jugadas el número de jugadas que se van a hacer partiendo de la casilla
 * @return número de movimientos totales
 */
int calculaMovimientosDeJugadasDesdeCasilla(int casillaActual, int jugadas) {
    int suma = 0;

    if (jugadas > 0) {
        std::list<int> posiblesMovimientosDesdeCasilla = obtenerPosiblesMovimientosDesdeCasilla(casillaActual);
        suma = suma + posiblesMovimientosDesdeCasilla.size();

        for (int casillaDestino: posiblesMovimientosDesdeCasilla) {
            suma = suma + calculaMovimientosDeJugadasDesdeCasilla(casillaDestino, jugadas - 1);
        }
    }

    return suma;
}

int calculaMovimientosPosiblesCaballo(int jugadas) {
    int suma = 0;
    for (int i = 0; i <= 9; i++) {
        int movimientosDeJugadasDesdeCasilla = calculaMovimientosDeJugadasDesdeCasilla(i, jugadas);
        suma = suma + movimientosDeJugadasDesdeCasilla;
    }
    return suma;
}


int main() {
    long long jugadasCaballo = 32;
    std::cout << "Numero de jugadas es: " << jugadasCaballo << std::endl;
    long long movimientos = calculaMovimientosPosiblesCaballo(jugadasCaballo);
    std::cout << "Numero total de movimientos (con repeticiones): " << movimientos << std::endl;
    long long movimientosUnicos = movimientos-calculaMovimientosPosiblesCaballo(jugadasCaballo-1);
    std::cout << "Numero total de movimientos unicos: " << movimientosUnicos << std::endl;
    return 0;
}
