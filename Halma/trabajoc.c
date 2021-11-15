#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void imprimir_tablero(char matriz[10][10])
{
    int i, j;
    printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < 10; i++)
    {
        //		printf(" %c |", 'A' + i); // para imprimir filas con letras
        printf(" %d |", i + 1); //para imprimir filas con numeros
        for (j = 0; j < 10; j++)
        {
            printf(" %c |", matriz[i][j]);
        }
        printf("\n-------------------------------------------\n");
    }
}

int iniciar_tablero(char tablero[10][10])
{
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            tablero[i][j] = ' ';
        }
    }

    //Número aleatorio para definir en que esquinan van las piezas
    int num_aleatorio = rand() % 1;
    char bon[2] = {'B','N'};

    //piezas blancas -> B
    tablero[0][0] = bon[num_aleatorio];
    tablero[0][1] = bon[num_aleatorio];
    tablero[0][2] = bon[num_aleatorio];
    tablero[0][3] = bon[num_aleatorio];
    tablero[0][4] = bon[num_aleatorio];
    tablero[1][0] = bon[num_aleatorio];
    tablero[1][1] = bon[num_aleatorio];
    tablero[1][2] = bon[num_aleatorio];
    tablero[1][3] = bon[num_aleatorio];
    tablero[2][0] = bon[num_aleatorio];
    tablero[2][1] = bon[num_aleatorio];
    tablero[2][2] = bon[num_aleatorio];
    tablero[3][0] = bon[num_aleatorio];
    tablero[3][1] = bon[num_aleatorio];
    tablero[4][0] = bon[num_aleatorio];

    //piezas negras -> N
    if (num_aleatorio == 1)
        num_aleatorio = 0;
    else num_aleatorio++;
    tablero[5][9] = bon[num_aleatorio];
    tablero[6][9] = bon[num_aleatorio];
    tablero[7][9] = bon[num_aleatorio];
    tablero[8][9] = bon[num_aleatorio];
    tablero[9][9] = bon[num_aleatorio];
    tablero[6][8] = bon[num_aleatorio];
    tablero[7][8] = bon[num_aleatorio];
    tablero[8][8] = bon[num_aleatorio];
    tablero[9][8] = bon[num_aleatorio];
    tablero[7][7] = bon[num_aleatorio];
    tablero[8][7] = bon[num_aleatorio];
    tablero[9][7] = bon[num_aleatorio];
    tablero[8][6] = bon[num_aleatorio];
    tablero[9][6] = bon[num_aleatorio];
    tablero[9][5] = bon[num_aleatorio];

    return num_aleatorio;
    
}

int verificar_ganador(char tablero[10][10], int num_aleatorio)
{
    if ( num_aleatorio == 1){
        if (
            tablero[5][9] == 'B'&&
            tablero[6][9] == 'B'&&
            tablero[7][9] == 'B'&&
            tablero[8][9] == 'B'&&
            tablero[9][9] == 'B'&&
            tablero[6][8] == 'B'&&
            tablero[7][8] == 'B'&&
            tablero[8][8] == 'B'&&
            tablero[9][8] == 'B'&&
            tablero[7][7] == 'B'&&
            tablero[8][7] == 'B'&&
            tablero[9][7] == 'B'&&
            tablero[8][6] == 'B'&&
            tablero[9][6] == 'B'&&
            tablero[9][5] == 'B'
        )    
            return 1;
        if (
            tablero[0][0] == 'N' &&
            tablero[0][1] == 'N' &&
            tablero[0][2] == 'N' &&
            tablero[0][3] == 'N' &&
            tablero[0][4] == 'N' &&
            tablero[1][0] == 'N' &&
            tablero[1][1] == 'N' &&
            tablero[1][2] == 'N' &&
            tablero[1][3] == 'N' &&
            tablero[2][0] == 'N' &&
            tablero[2][1] == 'N' &&
            tablero[2][2] == 'N' &&
            tablero[3][0] == 'N' &&
            tablero[3][1] == 'N' &&
            tablero[4][0] == 'N'
        ) 
            return 1;
    }
    else {
        if (
            tablero[5][9] == 'N'&&
            tablero[6][9] == 'N'&&
            tablero[7][9] == 'N'&&
            tablero[8][9] == 'N'&&
            tablero[9][9] == 'N'&&
            tablero[6][8] == 'N'&&
            tablero[7][8] == 'N'&&
            tablero[8][8] == 'N'&&
            tablero[9][8] == 'N'&&
            tablero[7][7] == 'N'&&
            tablero[8][7] == 'N'&&
            tablero[9][7] == 'N'&&
            tablero[8][6] == 'N'&&
            tablero[9][6] == 'N'&&
            tablero[9][5] == 'N'
        )    
            return 1;
        if (
            tablero[0][0] == 'B' &&
            tablero[0][1] == 'B' &&
            tablero[0][2] == 'B' &&
            tablero[0][3] == 'B' &&
            tablero[0][4] == 'B' &&
            tablero[1][0] == 'B' &&
            tablero[1][1] == 'B' &&
            tablero[1][2] == 'B' &&
            tablero[1][3] == 'B' &&
            tablero[2][0] == 'B' &&
            tablero[2][1] == 'B' &&
            tablero[2][2] == 'B' &&
            tablero[3][0] == 'B' &&
            tablero[3][1] == 'B' &&
            tablero[4][0] == 'B' 
        ) 
            return 1;
    }
    return 0;
}
char *verif_origen(char tablero[10][10], int origen_fila, int origen_col, char origen[2], int turno)
{
    char *auxiliar;
    if (turno == 1)
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

    char *verif_movimiento(char tablero[10][10], int movimiento_fila, int movimiento_col, char movimiento[2], int origen_fila, int origen_col)
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



int main()
{
    char *auxiliar;
    int turno = 0, origen_fila, origen_col, movimiento_fila, movimiento_col, ok;
    int num_aleatorio;
    char tablero[10][10], origen[2], movimiento[2];
    
    printf("Bienvenido al juego Halma!\n");
    //Iniciamos el tablero con las piezas en sus correspondientes posiciones
    num_aleatorio = iniciar_tablero(tablero);
    
    while (1){
        imprimir_tablero(tablero);

        if (turno == 0)
        {
            printf("Turno de las blancas\n");
            turno++;
        }
        else
        {
            printf("Turno de las negras\n");
            turno--;
        }
        printf("Escribe las coordenadas de la pieza que quieres mover: \n");
        scanf("%s", origen);
        //Leemos las coordenadas de la pieza que el usuario quiere mover y transformamos de char a int
        origen_fila = (origen[0] - '0') - 1;
        origen_col = (origen[1] - '0') - 1; 
    
        //Verificamos si las coordenadas ingresadas por el usuario son correctas
        if ((turno == 1 && tablero[origen_fila][origen_col] != 'B') || (turno == 0 && tablero[origen_fila][origen_col] != 'N'))
        {
            //Caso no exista una pieza en las coordenadas ingresadas mandamos los datos a la función verif_origen
            auxiliar = verif_origen(tablero, origen_fila, origen_col, origen, turno);
            origen_fila = (*auxiliar - '0') - 1;
            auxiliar++;
            origen_col = (*auxiliar - '0') - 1;
        }

        printf("\nEscribe las coordenadas donde quieres mover la pieza: \n");
        scanf("%s", movimiento);
        movimiento_fila = (movimiento[0] - '0') - 1;
        movimiento_col = (movimiento[1] - '0') - 1;
        if (origen_fila != movimiento_fila && origen_col != movimiento_col)
        {
            if(movimiento_fila == (origen[0]-1) || movimiento_fila == (origen[0]+1))
            {
                ok = 0;
            } 
            if(movimiento_col == (origen[1]-1) || movimiento_col == (origen[1]+1))
            {
                ok = 0;
            }
        }

        if (tablero[movimiento_fila][movimiento_col] != ' ' || ok != 0)
        {
            auxiliar = verif_movimiento(tablero, movimiento_fila, movimiento_col, movimiento, origen_fila, origen_col);
            movimiento_fila = (*auxiliar - '0') - 1;
            auxiliar ++;
            movimiento_col = (*auxiliar - '0') - 1;
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

        if (verificar_ganador(tablero, num_aleatorio)){
            if(turno == 1)
                printf("GANARON LAS BLANCAS!");
            
            else
                printf("GANARON LAS NEGRAS!");
        }

    }


}