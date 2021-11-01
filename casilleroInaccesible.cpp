#include "casilleroInaccesible.hpp"

CasilleroInaccesible ::CasilleroInaccesible(int x, int y) : Casillero(x, y)
{
}

CasilleroInaccesible ::~CasilleroInaccesible()
{
}

void CasilleroInaccesible ::mostrar()
{
    cout << "Soy un casillero inaccesible y estás en la posición " << this->coord_x << " " << this->coord_y << endl;
}

void CasilleroInaccesible ::display()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_BLUE_25 << "   " << END_COLOR << " ";
}
