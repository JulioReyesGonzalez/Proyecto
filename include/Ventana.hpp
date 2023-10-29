#include <curses.h>
#include <iostream>
#include <unistd.h>

class Ventana
{
private:
    int x;
    int y;
    int velocidad;
    int contador;
    bool ejecucion;

public:
    Ventana()
    {
        initscr();
        getmaxyx(stdscr, this->y, this->x);
        this->ejecucion = false;
        this->velocidad = 1;
        this->contador = 20;
        curs_set(FALSE);
        cbreak();
        timeout(100);
        noecho();
        keypad(stdscr, TRUE);
    }

    void Iniciar()
    {
        this->ejecucion = true;
    }

    void Actualizar()
    {
        this->contador = this->contador - 1;
        if (this->contador == 0)
        {
            this->Cerrar();
        }
    }

    void Dibujar()
    {
        // Borra toda la pantalla
        // erase();

        // Obtén las nuevas dimensiones de la ventana
        getmaxyx(stdscr, this->y, this->x);

        // Dibuja un contorno
        box(stdscr, '|', '-');

        // Refresca la pantalla
        refresh();
    }

    void Cerrar()
    {
        this->ejecucion = false;
    }

    ~Ventana()
    {
        endwin();
    }
};
