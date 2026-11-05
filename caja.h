#ifndef CAJA_H
#define CAJA_H

#include "Particula.h"

class Caja
{
public:
    Caja(double xmin, double xmax, double ymin, double ymax);
    bool rebotar(Particula &p) const;

    // Getters (la Simulacion los usa para escribir la linea CAJA del archivo)
    double getXmin() const { return xmin; }
    double getXmax() const { return xmax; }
    double getYmin() const { return ymin; }
    double getYmax() const { return ymax; }

private:
    double xmin, xmax, ymin, ymax;
};

#endif // CAJA_H