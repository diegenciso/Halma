#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void imprimir_tablero(char matriz[8][8])
{
    int i, j;
    printf("   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n");
    printf("------------------------------------\n");
    for (i = 0; i < 8; i++)
    {
        //		printf(" %c |", 'A' + i); // para imprimir filas con letras
        printf(" %d |", i + 1); //para imprimir filas con numeros
        for (j = 0; j < 8; j++)
        {
            printf(" %c |", matriz[i][j]);
        }
        printf("\n------------------------------------\n");
    }
}

char *verif_origen(char tablero[8][8], int origen_fila, int origen_col, char origen[2], int turno)
{
    char *auxiliar;
    if (turno == 0)
    {
        while (tablero[origen_fila][origen_col] != 'B')
        {
            printf("No hay una reina en esta posicion");
            printf("\nDefine las coordenadas de la reina a mover: \n");
            scanf("%s", origen);
            origen_fila = (origen[0] - '0') - 1;
            origen_col = (origen[1] - '0') - 1;
        }
    }
    else
    {
        while (tablero[origen_fila][origen_col] != 'N')
        {
            printf("No hay una reina en esta posicion");
            printf("\nDefine las coordenadas de la reina a mover \n");
            scanf("%s", origen);
            origen_fila = (origen[0] - '0') - 1;
            origen_col = (origen[1] - '0') - 1;
        }
    }
    auxiliar = origen;
    return auxiliar;
}

char *verif_movimiento(char tablero[8][8], int movimiento_fila, int movimiento_col, char movimiento[2], int origen_fila, int origen_col)
{
    char *auxiliar;
    int verif = 1;
    while (tablero[movimiento_fila][movimiento_col] != ' ' || verif == 1)
    {
        verif = 1;
        printf("No se puede mover aca");
        printf("\nDefine las coordenadas del movimiento:\n");
        scanf("%s", movimiento);
        movimiento_fila = (movimiento[0] - '0') - 1;
        movimiento_col = (movimiento[1] - '0') - 1;
        if (origen_fila != movimiento_fila && origen_col != movimiento_col)
        {
            if (abs(origen_fila - movimiento_fila) == abs(origen_col - movimiento_col))
            {
                verif = 0;
            }
        }
        else
        {
            verif = 0;
        }
    }
    auxiliar = movimiento;
    return auxiliar;
}

int main(void)
{
    int movimiento_fila, movimiento_col, turno = 0, arrow_fila, arrow_col, origen_fila, origen_col, ok;
    char *auxi;
    char movimiento[2], arrow[2], origen[2];
    char tablero[8][8];
    int i, j;

    printf("Bienvenido al juego de las amazonas!")
    


    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            tablero[i][j] = ' ';
        }
    }
    //piezas negras -> N
    tablero[1][0] = 'N';
    tablero[0][4] = 'N';
    tablero[2][7] = 'N';

    //piezas blancas -> B
    tablero[7][3] = 'B';
    tablero[6][7] = 'B';
    tablero[5][0] = 'B';

    // Empieza el juego por turno
    while (1)
    {
        ok = 1;
        imprimir_tablero(tablero);

        if (turno == 0)
        {
            printf("Turno de las blancas");
        }
        else
        {
            printf("Turno de las negras");
        }

        // Turno de jugador movimiento
        printf("\n Define las coordenadas de la reina a mover: \n");
        scanf("%s", origen);
        origen_fila = (origen[0] - '0') - 1;
        origen_col = (origen[1] - '0') - 1;
        if ((turno == 0 && tablero[origen_fila][origen_col] != 'B') || (turno == 1 && tablero[origen_fila][origen_col] != 'N'))
        {
            auxi = verif_origen(tablero, origen_fila, origen_col, origen, turno);
            origen_fila = (*auxi - '0') - 1;
            auxi++;
            origen_col = (*auxi - '0') - 1;
        }

        printf("\nDefine las coordenadas del movimiento:\n");
        scanf("%s", movimiento);
        movimiento_fila = (movimiento[0] - '0') - 1;
        movimiento_col = (movimiento[1] - '0') - 1;

        if (origen_fila != movimiento_fila && origen_col != movimiento_col)
        {
            if (abs(origen_fila - movimiento_fila) == abs(origen_col - movimiento_col))
            {
                ok = 0;
            }
        }
        else
        {
            ok = 0;
        }

        if (tablero[movimiento_fila][movimiento_col] != ' ' || ok != 0)
        {
            auxi = verif_movimiento(tablero, movimiento_fila, movimiento_col, movimiento, origen_fila, origen_col);
            movimiento_fila = (*auxi - '0') - 1;
            auxi++;
            movimiento_col = (*auxi - '0') - 1;
        }
        // Actualizar el tablero
        tablero[origen_fila][origen_col] = ' ';
        if (turno == 0)
        {
            tablero[movimiento_fila][movimiento_col] = 'B';
            turno++;
        }
        else
        {
            tablero[movimiento_fila][movimiento_col] = 'N';
            turno--;
        }

        imprimir_tablero(tablero);

        printf("\nDefine las coordenadas del disparo:\n");
        scanf("%s", arrow);
        arrow_fila = (arrow[0] - '0') - 1;
        arrow_col = (arrow[1] - '0') - 1;

        tablero[arrow_fila][arrow_col] = 'X';

        imprimir_tablero(tablero);
    }
}
