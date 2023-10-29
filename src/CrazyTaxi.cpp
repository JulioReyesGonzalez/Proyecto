#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <curses.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    Ventana v;
    v.Iniciar();
    Dibujo d4(0, 0, "ciudad");
    Dibujo d5(40, 0, "ciudad");
    Dibujo d6(95, 0, "ciudad");
    Dibujo d3(1, 7, "carretera");
    Dibujo d1(0, 5, "Taxi");

    bool ejecucion = true;
    bool moviendo_d1 = false;
    bool moviendo_d2 = false;

    while (ejecucion)
    {
        // Ciclo de actualización
        v.Actualizar();

        int ch = getch();
        if (ch != ERR)
        {
            // Se presionó una tecla
            if (ch == 'q')
            {
                ejecucion = false;
            }
            else if (ch == 'd')
            {
                moviendo_d1 = true;
                d1.AvanzarX(1);
            }
            else if (ch == 'a')
            {
                moviendo_d1 = true;
                d1.RetrocederX(1);
            }

            else if (ch == 's')
            {
                moviendo_d1 = true;
                d1.Bajary(1);
            }
            else if (ch == 'w')
            {
                moviendo_d1 = true;
                d1.Subiry(1);
            }
        }
        else
        {
            // No se presionó una tecla, detener el movimiento
            moviendo_d1 = false;
            moviendo_d2 = false;
        }

        // Ciclo de dibujo
        clear();

        d6.Dibujar();
        d5.Dibujar();
        d4.Dibujar();
        d3.Dibujar();
        d1.Dibujar();
        v.Dibujar();
        refresh();
        usleep(16667); // 60 fps
    }

    return 0;
}