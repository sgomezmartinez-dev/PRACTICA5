#include "caja.h"

Caja::Caja(double xmin, double xmax, double ymin, double ymax)
    : xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax)
{
}

bool Caja::rebotar(Particula &p) const
{
    bool choco = false;

    // Pared izquierda
    if (p.x - p.radio < xmin) {
        p.x = xmin + p.radio;   // reubicar en el borde
        p.vx = -p.vx;           // invertir componente perpendicular
        choco = true;
    }
    // Pared derecha
    if (p.x + p.radio > xmax) {
        p.x = xmax - p.radio;
        p.vx = -p.vx;
        choco = true;
    }
    // Pared inferior
    if (p.y - p.radio < ymin) {
        p.y = ymin + p.radio;
        p.vy = -p.vy;
        choco = true;
    }
    // Pared superior
    if (p.y + p.radio > ymax) {
        p.y = ymax - p.radio;
        p.vy = -p.vy;
        choco = true;
    }

    // Las cuatro comprobaciones son independientes: en una esquina se
    // cumplen dos a la vez y se invierten ambas componentes.
    return choco;
}