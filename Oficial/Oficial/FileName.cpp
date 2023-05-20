#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

struct jugador {
    int edad;
    char nombre[50];
    char simbolo;
};

// Definimos una estructura para representar un polígono
struct poligono {
    int lados;
    char nombre[20];
};

void logo(void);
void linea2(int n);
int preguntas_tipo1(int, int);
int preguntas_tipo2(int, int);
void inicializartablero(int filas, int columnas, char matriz[21][21])
{
    for (int i = 0; i < filas; i++)
    {
        int z = 1;
        for (int j = 0; j < columnas; j++)
        {
            if ((i) % 4 == 0 || (j) % 4 == 0)
                matriz[i][j] = '#';

            else
                matriz[i][j] = 'o';
        }
    }
    matriz[3][3] = '1'; matriz[3][7] = '2'; matriz[3][11] = '3'; matriz[3][15] = '4'; matriz[3][19] = '5'; matriz[7][3] = '6'; matriz[7][7] = '7'; matriz[7][11] = '8'; matriz[7][15] = '9';
    matriz[7][18] = '1'; matriz[7][19] = '0'; matriz[11][2] = '1'; matriz[11][3] = '1'; matriz[11][6] = '1'; matriz[11][7] = '2'; matriz[11][10] = '1'; matriz[11][11] = '3'; matriz[11][14] = '1'; matriz[11][15] = '4'; matriz[11][18] = '1'; matriz[11][19] = '5'; matriz[15][2] = '1'; matriz[15][3] = '6'; matriz[15][6] = '1'; matriz[15][7] = '7'; matriz[15][10] = '1'; matriz[15][11] = '8'; matriz[15][14] = '1'; matriz[15][15] = '9';
    matriz[15][18] = '2'; matriz[15][19] = '0'; matriz[19][2] = '2'; matriz[19][3] = '1'; matriz[19][6] = '2'; matriz[19][7] = '2'; matriz[19][10] = '2'; matriz[19][11] = '3'; matriz[19][14] = '2'; matriz[19][15] = '4'; matriz[19][18] = '2'; matriz[19][19] = '5';


}
void imprimirtablero(char matriz[21][21])
{
    printf("\n\n");
    for (int i = 0; i < 21; i++) { //Imprimir los valores de la matriz
        for (int j = 0; j < 21; j++) {
            if ((i) % 4 == 0 || (j) % 4 == 0)
                printf(AZUL_T"%c " RESET_COLOR, matriz[i][j]);
            else if ((i + 1) % 4 == 0 && (j + 1) % 4 == 0)
                printf(CYAN_T"%c " RESET_COLOR, matriz[i][j]);
            else if ((i + 1) % 4 == 0 && (j + 2) % 4 == 0)
                printf(CYAN_T"%c " RESET_COLOR, matriz[i][j]);
            else
                printf(AMARILLO_T"%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void numerosrandom()
{
    for (int j = 0; j < 10; j++) //Hacer que aparezcan numeros random hasta sacar el dado
    {
        int num1 = 0;
        num1 = rand() % 6 + 1;
        printf("\t\t\t%d\r", num1);
        Sleep(200);
    }
}
 
int lanzardado()
{
    srand(time(NULL));
    return (rand() % 6 + 1);
}

int movimiento(int, int, char[21][21], struct jugador*, int);
void inijuga(struct jugador*);
int generartableroop(int, int, int[5][5]);
void imprimirtableroop(int[5][5], int, int);
int estructurajuegoop(int, int, int[5][5]);
int conversion_juego();
int ladostriang();
void imprimir_reto_est(int, int);
int num_aleatorio();
int aleatoriedad_p1(int);
void error_p1(int, int);
int sucesos_p2(int);
void error_p2(int, int);
int probabilidad_p3(int);
int areatriang();
int* calcnumitera(int, int*);
void inivec(int*, int, int);
int estructjuego_se(int, int*, int);
int multiplicacion(int, int);
int estructmulti(void);
struct poligono generar_poligono();
int n_lados_poligono();
void imprimirProblema(int, int);
int problemas();
void creditos();

int main()
{
    int yes;
    struct jugador* jugadores;
    char matriz[21][21];
    int filas = 21, columnas = 21, eleccion, dificultad;

    jugadores = (struct jugador*)malloc(4 * sizeof(struct jugador));
    if (jugadores == NULL)
        exit(1);

    do {
        int menu_1;
        logo();
        printf("Importate cuando el ordenador te pida que ingreses un numero o letra NO te olvides de pulsar enter");
        printf("\n 1_Jugar\n 2_Tutorial\n 3_Creditos\n\n");
        do {
            printf(RESET_COLOR"Dime que vas a hacer: ");
            scanf_s("%d", &menu_1);
            switch (menu_1)
            {
            case 2:
                printf(CYAN_T"Bienvenido al tutorial");
                printf(CYAN_T"\nQue hacer en el menu\n -Al abrir el menu se nos dispondran tres opciones"
                    VERDE_T"\n\t#Jugar\n\t#Tutorial\n\t#Creditos"
                    CYAN_T"\n\nTutorial: la explicacion e instruciones de como funciona el juego\nCreditos: Muestra los creadores del juego"
                    "\nJuego:Al empezar el juego, te permitira elegir la dificultad"
                    VERDE_T"\n\n\t#TIPO 1" CYAN_T "\t\tCojunto de matematicas basica con preguntas mas basicas"
                    VERDE_T"\n\t#TIPO 2" CYAN_T "\t\tCojunto de matematicas basica con preguntas mas compliacadas"
                    CYAN_T"\n\n\t incluye varios mini juegos dentro de cada dificultad:"
                    VERDE_T"\n\n\t\tLados triangulos ->\tEl juego te generara 3 num aleatorios lado 1, lado 2 y lado 3, con esos datos tendras que decir si es un trangulo equilatero, escaleno o isosceles"
                    "\n\n\t\tConversiones ->\t\tEl juego genera un numero que tendras que convertir de una unidad base a otra unidad"
                    "\n\n\t\tAleatorio ->\t\tEl juego te generara un escenario y tendras que determinar si este escenario es aleatorio o no"
                    "\n\n\t\tMultiplicaciones ->\tEl juego genera multiplicaciones aleatorias que tendras que resolver"
                    "\n\n\t\tSumas ->\t\tEl juego te genera un tablero de numeros aleatorios, el jugador tendra que elegir movimiento arriba, abajo, derecha o izquierda y a su vez elegir si sumar o restar"
                    "\n\n\t\tProblemas ->\t\tEl juego te sugiere 4 problemas del que tendras que elegir uno, al elegir problema tendras que resolverlo e introducir el resultado correspondiente"
                    "\n\n\t\tLados poligonos ->\tEl juego te genera el nombre de un poligono, tendras que responder el numero de lados que se le asigna a ese poligono"
                    "\n\n\t\tArea triangulo ->\tEl juego te genera los datos necesarios de un triangulo para que halles el area correspondiente"
                    "\n\n\t\tSucesos ->\t\tEl juego te genera un suceso y tendras que determinar si es seguro, posible o imposible"
                    "\n\n\t\tProbabilidad ->\t\tEl juego te genera un suceso del que tendras que resolver su probabilidad, poniendo primero el numero del numerador y luego del enter el del denominador"
                    "\n\n\t\tSerie ->\t\tEl juego genera un numero aleatorio y se te dara instrucciones para realizar ciertas operaciones dependiendo del numero generado"
                    "\n\nCuando respondas una pregunta, si la respuesta es correcta te mantendras en la casilla, en caso contrario volveras a la casilla en la que te encontrabas en la ronda anterior");
                break;
            case 3:
                creditos();
                break;
            case 1:
                printf("\nElige la dificultad de juego: 1-TIPO 1 // 2-TIPO 2 \nLa dificultad que elijo es: ");
                scanf_s("%d", &dificultad);
                printf("\n");

                inijuga(jugadores);
                yes=movimiento(filas, columnas, matriz, jugadores, dificultad);
                break;
            }
        } while (menu_1 != 1 && menu_1 != 2 && menu_1 != 3);
        system("cls");
    } while (yes == 1);
}

int movimiento(int filas, int columnas, char matriz[21][21], struct jugador* jugadores, int dificultad)
{
    int lanzar, movimiento, resto, retorno2, auxcolumna = 0, auxfila = 0,yes;
    int fila_jugador[4] = { 1,1,2,2 }, columna_jugador[4] = { 1,2,1,2 }; //Poner a cada jugador en la posicion incial
    do
    {
        inicializartablero(filas, columnas, matriz); //Llamar a la funcion para generar los valores de la matriz nuevamente
        for (int i = 0; i < 4; i++) //Inicializar a cada jugador en la posicion que quedo al terminar el bucle
            matriz[fila_jugador[i]][columna_jugador[i]] = jugadores[i].simbolo;

        for (int i = 0; i < 4; i++)
        {
            auxcolumna = columna_jugador[i];
            auxfila = fila_jugador[i];

            imprimirtablero(matriz);

            printf("\nJugador %c presiona el boton (1) para lanzar el dado: ", jugadores[i].simbolo);
            do
            {
                scanf_s("%d", &lanzar);
            } while (lanzar != 1);
            movimiento = lanzardado();
            numerosrandom(); //Simular el lanzamiento de un dado
            Sleep(200);
            printf("Jugador %c has sacado un: %d\n\n", jugadores[i].simbolo, movimiento);
            for (int j = 0; j < movimiento * 4; j++)
            {
                columna_jugador[i]++;
                if (fila_jugador[i] > 16 && columna_jugador[i] > 14)
                {
                    printf("\nJugador %c ganaste el juego felicidades", jugadores[i].simbolo);
                    printf(RESET_COLOR"\n\n\n\nDesea volver al menu principal?\n volver a menu principal: pulse cualquier tecla \n abandonar el Juego: pulse 0\n");
                    scanf_s("%d", &yes);
                    getchar();
                    if (yes == 0)
                        exit(1);
                    else
                        return(1);
                }
                if (columna_jugador[i] == columnas - 1)
                {
                    fila_jugador[i] += 4;
                    columna_jugador[i] = 0;
                }
            }
            inicializartablero(filas, columnas, matriz); //Llamar al tablero para que inicialice los valores del tablero otra vez
            for (int i = 0; i < 4; i++)
                matriz[fila_jugador[i]][columna_jugador[i]] = jugadores[i].simbolo;//Hacer el cambio del jugador que le toco lanzar el dado

            imprimirtablero(matriz);
            printf(RESET_COLOR);

            if (dificultad == 1)
            {
                retorno2 = preguntas_tipo1(fila_jugador[i], columna_jugador[i]);
                if (retorno2 == 1)
                    printf(VERDE_T"\n\nFelicidades te quedas donde estas!!");
                if (retorno2 == 0)
                {
                    printf(ROJO_T"\nRetrocedes a donde estabas antes");
                    columna_jugador[i] = auxcolumna;
                    fila_jugador[i] = auxfila;
                }
                if (retorno2 == 2)
                {
                    columna_jugador[i] = columna_jugador[i] - (2*4);;
                }
                if (retorno2 == 3)
                {
                    columna_jugador[i] = columna_jugador[i] + (2*4);
                }
                if (retorno2 == 4)
                {
                    columna_jugador[i] = columna_jugador[i] + (2*4);
                }
                if (retorno2 == 5)
                {
                    if (i == 0)
                    {
                        fila_jugador[0] = 1;
                        columna_jugador[0] = 1;
                    }
                    if (i == 1)
                    {
                        fila_jugador[1] = 1;
                        columna_jugador[1] = 2;
                    }
                    if (i == 2)
                    {
                        fila_jugador[2] = 2;
                        columna_jugador[2] = 1;
                    }
                    if (i == 3)
                    {
                        fila_jugador[3] = 2;
                        columna_jugador[3] = 2;
                    }
                }
            }
            if (dificultad == 2)
            {
                retorno2 = preguntas_tipo2(fila_jugador[i], columna_jugador[i]);
                if (retorno2 == 1)
                    printf(VERDE_T"\n\nFelicidades te quedas donde estas!!");
                if (retorno2 == 0)
                {
                    printf(ROJO_T"Retrocedes a donde estabas antes");
                    columna_jugador[i] = auxcolumna;
                    fila_jugador[i] = auxfila;
                }
                if (retorno2 == 2)
                {
                    columna_jugador[i] = columna_jugador[i] - (2*4);;
                }
                if (retorno2 == 3)
                {
                    columna_jugador[i] = columna_jugador[i] + (2*4);
                }
                if (retorno2 == 4)
                {
                    columna_jugador[i] = columna_jugador[i] + (2*4);
                }
                if (retorno2 == 5)
                {
                    if (i == 0)
                    {
                        fila_jugador[0] = 1;
                        columna_jugador[0] = 1;
                    }
                    if (i == 1)
                    {
                        fila_jugador[1] = 1;
                        columna_jugador[1] = 2;
                    }
                    if (i == 2)
                    {
                        fila_jugador[2] = 2;
                        columna_jugador[2] = 1;
                    }
                    if (i == 3)
                    {
                        fila_jugador[3] = 2;
                        columna_jugador[3] = 2;
                    }
                }
            }
            inicializartablero(filas, columnas, matriz); //Llamar al tablero para que inicialice los valores del tablero otra vez
            for (int i = 0; i < 4; i++)
                matriz[fila_jugador[i]][columna_jugador[i]] = jugadores[i].simbolo;
        }
    }while (1);
}
void inijuga(struct jugador* jugadores)
{
    jugadores[0].simbolo = 156;
    jugadores[1].simbolo = 245;
    jugadores[2].simbolo = 244;
    jugadores[3].simbolo = 145;

    for (int i = 0; i < 4; i++)
    {
        getchar();
        printf("Dime tu nombre: ");
        gets_s(jugadores[i].nombre);
        printf("Dime tu edad: ");
        scanf_s("%d", &jugadores[i].edad);
        printf("%s este es tu simbolo %c\n\n", jugadores[i].nombre, jugadores[i].simbolo);
    }
}

void logo(void) {

    int n = 178, b = 176, i, j;

    linea2(n);

    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 15) || (j > 18 && j <= 30) || (j > 33 && j <= 37) || (j > 48 && j <= 52) || (j > 55 && j <= 65) || (j > 77 && j <= 92) || (j > 95 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }

    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 15) || (j > 18 && j <= 30) || (j > 33 && j <= 38) || (j > 47 && j <= 52) || (j > 55 && j <= 67) || (j > 77 && j <= 92) || (j > 95 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }

    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 7) || (j > 11 && j <= 15) || (j > 18 && j <= 21) || (j > 33 && j <= 40) || (j > 45 && j <= 52) || (j > 55 && j <= 70) || (j > 77 && j <= 80) || (j > 89 && j <= 92) || (j > 95 && j <= 99))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 15) || (j > 18 && j <= 30) || (j > 33 && j <= 41) || (j > 44 && j <= 52) || (j > 55 && j <= 73) || (j > 77 && j <= 80) || (j > 89 && j <= 92) || (j > 95 && j <= 99))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 15) || (j > 18 && j <= 30) || (j > 33 && j <= 36) || (j > 37 && j <= 42) || (j > 43 && j <= 48) || (j > 49 && j <= 52) || (j > 55 && j <= 75) || (j > 77 && j <= 92) || (j > 95 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 7) || (j > 18 && j <= 21) || (j > 33 && j <= 36) || (j > 39 && j <= 46) || (j > 49 && j <= 52) || (j > 55 && j <= 73) || (j > 77 && j <= 92) || (j > 95 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 7) || (j > 18 && j <= 21) || (j > 33 && j <= 36) || (j > 41 && j <= 44) || (j > 49 && j <= 52) || (j > 55 && j <= 70) || (j > 77 && j <= 80) || (j > 89 && j <= 92) || (j > 106 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 7) || (j > 18 && j <= 30) || (j > 33 && j <= 36) || (j > 49 && j <= 52) || (j > 55 && j <= 67) || (j > 77 && j <= 80) || (j > 89 && j <= 92) || (j > 95 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");
    for (j = 0; j < 114; j++)
    {
        if ((j > 3 && j <= 7) || (j > 18 && j <= 30) || (j > 33 && j <= 36) || (j > 49 && j <= 52) || (j > 55 && j <= 65) || (j > 77 && j <= 80) || (j > 89 && j <= 92) || (j > 95 && j <= 110))
        {
            printf(ROJO_T"%c", b);
        }
        else
        {
            printf(ROJO_T"%c", n);
        }
    }
    printf("\n");

    linea2(n);

}
void linea2(int n)
{
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 114; i++)
        {
            printf(ROJO_T"%c", n);
        }
        printf("\n");
    }
}

int preguntas_tipo1(int fila, int columna)
{
    int retorno1;
    if ((fila == 1 && columna == 5) || (fila == 1 && columna == 6) || (fila == 2 && columna == 5) || (fila == 2 && columna == 6) || (fila == 9 && columna == 9) || (fila == 9 && columna == 10) || (fila == 10 && columna == 9) || (fila == 10 && columna == 10) || (fila == 13 && columna == 9) || (fila == 13 && columna == 10) || (fila == 14 && columna == 9) || (fila == 14 && columna == 10) || (fila == 17 && columna == 1) || (fila == 17 && columna == 2) || (fila == 18 && columna == 1) || (fila == 18 && columna == 2))
    {
        ladostriang();
    }
    if ((fila == 1 && columna == 13) || (fila == 1 && columna == 14) || (fila == 2 && columna == 13) || (fila == 2 && columna == 14) || (fila == 5 && columna == 1) || (fila == 5 && columna == 2) || (fila == 6 && columna == 1) || (fila == 6 && columna == 2) || (fila == 9 && columna == 13) || (fila == 9 && columna == 14) || (fila == 10 && columna == 13) || (fila == 10 && columna == 14) || (fila == 13 && columna == 17) || (fila == 13 && columna == 18) || (fila == 14 && columna == 17) || (fila == 14 && columna == 18))
    {
        int filas = 5, columnas = 5, movimiento, totales = 0, comodin = 0, fila = 0, columna = 0;
        int tablero[5][5], objetivo;
        char jugada, opccomodin;
        objetivo = generartableroop(filas, columnas, tablero);
        imprimirtableroop(tablero, filas, columnas);
        jugada = tablero[0][0];
        retorno1 = estructurajuegoop(jugada, objetivo, tablero);
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 1 && columna == 9) || (fila == 1 && columna == 10) || (fila == 2 && columna == 9) || (fila == 2 && columna == 10) || (fila == 5 && columna == 9) || (fila == 5 && columna == 10) || (fila == 6 && columna == 9) || (fila == 6 && columna == 10) || (fila == 5 && columna == 17) || (fila == 5 && columna == 18) || (fila == 6 && columna == 17) || (fila == 6 && columna == 18) || (fila == 13 && columna == 5) || (fila == 13 && columna == 6) || (fila == 14 && columna == 5) || (fila == 14 && columna == 6))
    {
        retorno1 = estructmulti();
        printf("\n");
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 5 && columna == 5) || (fila == 5 && columna == 6) || (fila == 6 && columna == 5) || (fila == 6 && columna == 6) || (fila == 9 && columna == 1) || (fila == 9 && columna == 2) || (fila == 10 && columna == 1) || (fila == 10 && columna == 2) || (fila == 13 && columna == 13) || (fila == 13 && columna == 14) || (fila == 14 && columna == 13) || (fila == 14 && columna == 14) || (fila == 17 && columna == 9) || (fila == 17 && columna == 10) || (fila == 18 && columna == 9) || (fila == 18 && columna == 10))
    {
        retorno1 = conversion_juego();
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 1 && columna == 17) || (fila == 1 && columna == 18) || (fila == 2 && columna == 17) || (fila == 2 && columna == 18) || (fila == 9 && columna == 17) || (fila == 9 && columna == 18) || (fila == 10 && columna == 17) || (fila == 10 && columna == 18) || (fila == 17 && columna == 5) || (fila == 17 && columna == 6) || (fila == 18 && columna == 5) || (fila == 18 && columna == 6))
    {
        int opc1, n;
        printf("Identifica si las experiencias son aleatrias o no.\n");
        printf("COMENZAMOS\n");
        n = num_aleatorio();
        opc1 = n;
        retorno1 = aleatoriedad_p1(opc1);
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 5 && columna == 13) || (fila == 5 && columna == 14) || (fila == 6 && columna == 13) || (fila == 6 && columna == 14))
    {
        printf(VERDE_T"Retrocede dos casillas\n");
        return(2);
    }
    if ((fila == 13 && columna == 1) || (fila == 13 && columna == 2) || (fila == 14 && columna == 1) || (fila == 14 && columna == 2))
    {
        printf(ROJO_T"Avanza dos casillas\n");
        return(3);
    }
    if ((fila == 9 && columna == 5) || (fila == 9 && columna == 6) || (fila == 10 && columna == 5) || (fila == 10 && columna == 6))
    {
        printf(VERDE_T"Avanza una casilla \n");
        return(4);
    }
    if ((fila == 17 && columna == 13) || (fila == 17 && columna == 14) || (fila == 18 && columna == 13) || (fila == 18 && columna == 14))
    {
        printf(ROJO_T"Vuelve al inicio\n");
        return(5);
    }
}
int preguntas_tipo2(int fila, int columna)
{
    int retorno1=0;
    if ((fila == 1 && columna == 9) || (fila == 1 && columna == 10) || (fila == 2 && columna == 9) || (fila == 2 && columna == 10) || (fila == 9 && columna == 1) || (fila == 9 && columna == 2) || (fila == 10 && columna == 1) || (fila == 10 && columna == 2) || (fila == 13 && columna == 9) || (fila == 13 && columna == 10) || (fila == 14 && columna == 9) || (fila == 14 && columna == 10))
    {
        retorno1 = n_lados_poligono();
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 1 && columna == 17) || (fila == 1 && columna == 18) || (fila == 2 && columna == 17) || (fila == 2 && columna == 18) || (fila == 5 && columna == 17) || (fila == 5 && columna == 18) || (fila == 6 && columna == 17) || (fila == 6 && columna == 18) || (fila == 9 && columna == 13) || (fila == 9 && columna == 14) || (fila == 10 && columna == 13) || (fila == 10 && columna == 14) || (fila == 17 && columna == 5) || (fila == 17 && columna == 6) || (fila == 18 && columna == 5) || (fila == 18 && columna == 6))
    {
        srand(time(NULL));
        int numini = rand() % 8 + 3, iteracciones, * resultados;
        resultados = calcnumitera(numini, &iteracciones);
        inivec(resultados, numini, iteracciones);
        retorno1 = estructjuego_se(numini, resultados, iteracciones);
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 5 && columna == 5) || (fila == 5 && columna == 6) || (fila == 6 && columna == 5) || (fila == 6 && columna == 6) || (fila == 13 && columna == 17) || (fila == 13 && columna == 18) || (fila == 14 && columna == 17) || (fila == 14 && columna == 18) || (fila == 17 && columna == 1) || (fila == 17 && columna == 2) || (fila == 18 && columna == 1) || (fila == 18 && columna == 2))
    {
        retorno1 = problemas();
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 5 && columna == 1) || (fila == 5 && columna == 2) || (fila == 6 && columna == 1) || (fila == 6 && columna == 2) || (fila == 9 && columna == 17) || (fila == 9 && columna == 18) || (fila == 10 && columna == 17) || (fila == 10 && columna == 18) || (fila == 13 && columna == 5) || (fila == 13 && columna == 6) || (fila == 14 && columna == 5) || (fila == 14 && columna == 6))
    {
        retorno1 = areatriang();
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 1 && columna == 13) || (fila == 1 && columna == 14) || (fila == 2 && columna == 13) || (fila == 2 && columna == 14) || (fila == 9 && columna == 9) || (fila == 9 && columna == 10) || (fila == 10 && columna == 9) || (fila == 10 && columna == 10) || (fila == 17 && columna == 9) || (fila == 17 && columna == 10) || (fila == 18 && columna == 9) || (fila == 18 && columna == 10))
    {
        int opc3, n;
        n = num_aleatorio();
        opc3 = n;
        retorno1 = probabilidad_p3(opc3);
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 1 && columna == 5) || (fila == 1 && columna == 6) || (fila == 2 && columna == 5) || (fila == 2 && columna == 6) || (fila == 5 && columna == 9) || (fila == 5 && columna == 10) || (fila == 6 && columna == 9) || (fila == 6 && columna == 10) || (fila == 13 && columna == 13) || (fila == 13 && columna == 14) || (fila == 14 && columna == 13) || (fila == 14 && columna == 14))
    {
        int opc2, n;
        printf("Identifica si los sucesos son posibles, seguros o imposibles.\n");
        n = num_aleatorio();
        opc2 = n;
        retorno1 = sucesos_p2(opc2);
        if (retorno1 == 1)
            return(1);
        if (retorno1 == 0)
            return(0);
    }
    if ((fila == 5 && columna == 13) || (fila == 5 && columna == 14) || (fila == 6 && columna == 13) || (fila == 6 && columna == 14))
    {
        printf(VERDE_T"Avanza dos casillas\n");
        return(2);
    }
    if ((fila == 13 && columna == 1) || (fila == 13 && columna == 2) || (fila == 14 && columna == 1) || (fila == 14 && columna == 2))
    {
        printf(ROJO_T"Retrodece dos casillas\n");
        return(3);
    }
    if ((fila == 9 && columna == 5) || (fila == 9 && columna == 6) || (fila == 10 && columna == 5) || (fila == 10 && columna == 6))
    {
        printf(ROJO_T"Avanzas una casillas\n");
        return(4);
    }
    if ((fila == 17 && columna == 13) || (fila == 17 && columna == 14) || (fila == 18 && columna == 13) || (fila == 18 && columna == 14))
    {
        printf(ROJO_T"Vuelve al inicio\n");
        return(5);
    }
}

int generartableroop(int filas, int columnas, int tablero[5][5]) //Funcion para generar el tablero y el objetivo a llegar por el laberinto
{
    srand(time(NULL));
    int objetivo;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            tablero[i][j] = rand() % 10;
    }
    do
    {
        objetivo = rand() % 30;
    } while (objetivo == tablero[0][0]);
    return(objetivo);
}
void imprimirtableroop(int tablero[5][5], int filas, int columnas)
{
    printf("salida-> ");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            printf("%d ", tablero[i][j]);

        Sleep(400);
        printf("\n         ");
    }
}
int estructurajuegoop(int jugada, int objetivo, int tablero[5][5])
{
    int movimiento, fila = 0, columna = 0, comodin = 0, totales = 0;
    char opccomodin;
    printf("\nTen en cuenta que solo tienes 10 movimientos\nAdemas tienes un comodin que puedes usar solo una vez\nTu objetivo es: %d", objetivo);
    while (jugada != objetivo)
    {
        printf("\nEstas ubicado en el numero: %d\n", tablero[fila][columna]);
        do
        {
            if (fila < 0)
            {
                fila++;
                printf("Ten en cuenta que no puedes salir del tablero, intentalo de nuevo\n");
            }
            if (fila > 4)
            {
                fila--;
                printf("Ten en cuenta que no puedes salir del tablero, intentalo de nuevo\n");
            }
            if (columna < 0)
            {
                columna++;
                printf("Ten en cuenta que no puedes salir del tablero, intentalo de nuevo\n");
            }
            if (columna > 4)
            {
                columna--;
                printf("Ten en cuenta que no puedes salir del tablero, intentalo de nuevo\n");
            }
            while (1) {
                printf("\nDime el movimiento que quieres hacer: arriba()1 izquierda()2 abajo()3 derecha()4: ");

                if (scanf_s("%d", &movimiento) != 1) {
                    int c;
                    printf(ROJO_T"Error:" CYAN_T"Debe estar dentro del rango\n" RESET_COLOR);
                    while ((c = getchar()) != '\n' && c != EOF) {}
                }
                else {
                    break;  // Salir del bucle si se ingresó un número válido
                }
            }
            if (movimiento == 1)  fila--;
            else if (movimiento == 2)  columna--;
            else if (movimiento == 3) fila++;
            else if (movimiento == 4) columna++;
            else  printf(ROJO_T"Error:"  CYAN_T"Debe estar dentro del rango\n" RESET_COLOR);
        } while (fila < 0 || fila>4 || columna < 0 || columna>4 || movimiento < 1 || movimiento>4);

        totales++;
        if (totales == 10)
        {
            printf(ROJO_T"\nNo lograste el objetivo,mala suerte\n");
            break;
        }
        do
        {
            while (1) {
                //printf("Ingresa un movimiento: ");
                printf("Quieres sumar(1) o restar(2): ");

                if (scanf_s("%d", &movimiento) != 1) {
                    int c;
                    printf(ROJO_T"Error:" CYAN_T"Debe estar dentro del rango\n" RESET_COLOR);
                    while ((c = getchar()) != '\n' && c != EOF) {}
                }
                else {
                    break;  // Salir del bucle si se ingresó un número válido
                }
            }
            if (movimiento == 1)
                jugada += tablero[fila][columna];
            if (movimiento == 2)
                jugada -= tablero[fila][columna];
        } while (movimiento != 1 && movimiento != 2);

        if (comodin == 0)
        {
            printf("Quieres usar tu comodin? si(s) no(n): ");
            do
            {
                scanf_s("%c", &opccomodin);
            } while (opccomodin != 's' && opccomodin != 'n');
            if (opccomodin == 's')
            {
                printf("\nLlevas acomulado: %d", jugada);
                comodin = 1;
            }
        }
        getchar();
    }
    if (jugada == objetivo)
    {
        printf(VERDE_T"\nFelicidades ganaste el juego\n");
        return 1;
    }
    else
        return 0;
}

int conversion_juego() {
    int desde_unidad, hasta_unidad;
    float respuesta_correcta, usuario_respuesta, valor;
    int nota = 0;
    int i;

    // Generar numeros random
    srand(time(NULL));

    // Bucle de 10 preguntas
    for (i = 0; i < 10; i++) {
        // ELije unidad random de 1 a 3
        desde_unidad = rand() % 3 + 1;

        // Elige unidad random (1-3, no igual a desde_unidad)
        do {
            hasta_unidad = rand() % 3 + 1;
        } while (hasta_unidad == desde_unidad);

        // Elegir valor random a convertide de (1-100) 
        valor = rand() % 100 + 1;

        // Calcular respuesta
        if (desde_unidad == 1 && hasta_unidad == 2) {
            respuesta_correcta = valor / 10;
        }
        else if (desde_unidad == 1 && hasta_unidad == 3) {
            respuesta_correcta = valor / 1000;
        }
        else if (desde_unidad == 2 && hasta_unidad == 1) {
            respuesta_correcta = valor * 10;
        }
        else if (desde_unidad == 2 && hasta_unidad == 3) {
            respuesta_correcta = valor / 100;
        }
        else if (desde_unidad == 3 && hasta_unidad == 1) {
            respuesta_correcta = valor * 1000;
        }
        else {
            respuesta_correcta = valor * 100;
        }

        // preguntar al usuario el valor a convertir
        printf(RESET_COLOR"Convertir %.2f ", valor);
        switch (desde_unidad) {
        case 1:
            printf("mm");
            break;
        case 2:
            printf("cm");
            break;
        case 3:
            printf("m");
            break;
        }
        printf(" en ");
        switch (hasta_unidad) {
        case 1:
            printf("mm");
            break;
        case 2:
            printf("cm");
            break;
        case 3:
            printf("m");
            break;
        }
        printf(": ");
        scanf_s("%f", &usuario_respuesta);

        // Comprobar respuesta de usuario
        if (usuario_respuesta == respuesta_correcta) {
            printf("Correcto!\n");
            nota++;
        }
        else {
            printf(ROJO_T"Incorrecto. la respuesta correcta es %.2f.\n", respuesta_correcta);
        }
        getchar();
    }

    // Print the final score
    printf("Nota final: %d de 10.\n", nota);
    if (nota >= 7)
        return 1;
    if (nota < 7)
        return 0;
}

int ladostriang() {
    int lado1, lado2, lado3, rectf, rectf2;
    char respuesta, respuesta2, correcto;
    srand(time(0)); // Inicializar el generador de números aleatorios

    // Generar tres números aleatorios entre 1 y 10
    lado1 = rand() % 10 + 1;
    lado2 = rand() % 10 + 1;
    lado3 = rand() % 10 + 1;

    printf("Bienvenido al juego de lados de un triangulo!\n\n");
    printf("Los lados del triangulo son: %d, %d, %d\n", lado1, lado2, lado3);
    printf("Es el triangulo equilatero? (s/n): ");


    do {
        scanf_s("%c", &respuesta);

        rectf = int(respuesta);
        switch (respuesta) {
        case 's':
        case 'S':
            if (lado1 == lado2 && lado2 == lado3) {
                printf("Correcto! El triangulo es equilatero.\n");
                return 1;
            }
            else {
                printf("Lo siento, la respuesta es incorrecta.\n ");
                return 0;
            }
            break;
        case 'n':
        case 'N':
            printf("Entonces el triangulo que es: \n escaleno, iscosceles o equilatero? (e/i/q): ");

            do {
                scanf_s(" %c", &respuesta2);
                rectf2 = int(respuesta2);
                switch (respuesta2) {
                case 'e':
                case 'E':
                    if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3) {
                        printf("Correcto! El triangulo es escaleno.\n");
                        return 1;
                    }
                    else {
                        printf("Lo siento, la respuesta es incorrecta.\n ");
                        return 0;
                    }
                    break;
                case 'i':
                case 'I':
                    if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
                        printf("Correcto! El triangulo es isosceles.\n");
                        return 1;
                    }
                    else {
                        printf("Lo siento, la respuesta es incorrecta.\n ");
                        return 0;
                    }
                    break;
                case 'q':
                case 'Q':
                    printf("Lo siento, la respuesta es incorrecta.\n La respuesta correcta ya la habias puesto al principio, has caido en la trampa.\n\n");
                    return 0;
                    break;
                default:
                    printf("ingrese una respuesta valida.\n");
                    break;
                }
            } while (rectf2 != 101 && rectf2 != 69 && rectf2 != 105 && rectf2 != 73 && rectf2 && 113 && rectf2 != 81);
            break;
        default:
            printf("Ingrese una respuesta valida.\n");
            break;
        }
    } while (rectf != 115 && rectf != 83 && rectf != 110 && rectf != 78);

}

int num_aleatorio()
{
    int n;
    srand(time(NULL));
    n = rand() % 10 + 1;
    return(n);
}
int aleatoriedad_p1(int opc1)
{
    printf("1-aleatorio // 2-NO aleatorio\n");
    int respuesta1;
    switch (opc1)
    {
    case 1:
        imprimir_reto_est(2, 2);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 1)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 2)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es aleatorio\n");
            return 0;
        }
        break;
    case 2:
        imprimir_reto_est(3, 3);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 2)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 1)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  NO es aleatorio\n");
            return 0;
        }
        break;
    case 3:
        imprimir_reto_est(4, 4);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 1)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 2)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es aleatorio\n");
            return 0;
        }
        break;
    case 4:
        imprimir_reto_est(5, 5);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 2)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 1)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  NO es aleatorio\n");
            return 0;
        }
        break;
    case 5:
        imprimir_reto_est(6, 6);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 2)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 1)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  NO es aleatorio\n");
            return 0;
        }
        break;
    case 6:
        imprimir_reto_est(7, 7);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 1)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 2)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es aleatorio\n");
            return 0;
        }
        break;
    case 7:
        imprimir_reto_est(8, 8);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 2)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 1)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  NO es aleatorio\n");
            return 0;
        }
        break;
    case 8:
        imprimir_reto_est(9, 9);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 1)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 2)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es aleatorio\n");
            return 0;
        }
        break;
    case 9:
        imprimir_reto_est(10, 10);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 1)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 2)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es aleatorio\n");
            return 0;
        }
        break;
    case 10:
        imprimir_reto_est(11, 11);
        scanf_s("%d", &respuesta1);
        error_p1(respuesta1, opc1);
        if (respuesta1 == 2)
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta1 == 1)
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  NO es aleatorio\n");
            return 0;
        }
        break;
    }
}
void error_p1(int respuesta1, int opc1)
{
    while (respuesta1 != 1 && respuesta1 != 2)
    {
        printf("Intentalo de nuevo.\n");
        aleatoriedad_p1(opc1);
        break;
    }
}
int sucesos_p2(int opc2)
{
    printf("marca una opcion: s-suceso seguro // p-suceso posible // i-suceso imposible\n");
    char respuesta2;
    switch (opc2)
    {
    case 1:
        imprimir_reto_est(13, 13);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'i')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 'p' || respuesta2 == 's')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso imposible\n");
            return 0;
        }
        break;
    case 2:
        imprimir_reto_est(14, 14);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'p')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 's' || respuesta2 == 'i')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso posible\n");
            return 0;
        }
        break;
    case 3:
        imprimir_reto_est(15, 15);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'i')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 's' || respuesta2 == 'p')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso imposible\n");
            return 0;
        }
        break;
    case 4:
        imprimir_reto_est(16, 16);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 's')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 'p' || respuesta2 == 'i')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso seguro\n");
            return 0;
        }
        break;
    case 5:
        imprimir_reto_est(17, 17);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'i')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 'p' || respuesta2 == 's')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso imposible\n");
            return 0;
        }
        break;
    case 6:
        imprimir_reto_est(18, 18);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'p')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 's' || respuesta2 == 'i')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso posible\n");
            return 0;
        }
        break;
    case 7:
        imprimir_reto_est(19, 19);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 's')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 'p' || respuesta2 == 'i')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso seguro\n");
            return 0;
        }
        break;
    case 8:
        imprimir_reto_est(20, 20);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'i')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 'p' || respuesta2 == 's')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso imposible\n");
            return 0;
        }
        break;
    case 9:
        imprimir_reto_est(21, 21);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'p')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 's' || respuesta2 == 'i')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso posible\n");
            return 0;
        }
        break;
    case 10:
        imprimir_reto_est(22, 22);
        scanf_s(" %c", &respuesta2);
        error_p2(respuesta2, opc2);
        if (respuesta2 == 'p')
        {
            printf("Respuesta correcta\n");
            return 1;
        }
        if (respuesta2 == 's' || respuesta2 == 'i')
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta: es un suceso posible\n");
            return 0;
        }
        break;
    }
}
void error_p2(int respuesta2, int opc2)
{
    while (respuesta2 != 'i' && respuesta2 != 's' && respuesta2 != 'p')
    {
        printf("Intentalo de nuevo.\n");
        sucesos_p2(opc2);
        break;
    }
}
int probabilidad_p3(int opc3)
{
    printf("Halla la probabilidad de estos sucesos\n");
    printf("Introduce la respuesta en el siguiente formato: A/B. Primero tecle el valor de A y luego el de B. SIN SIMPLIFICAR.\n");
    int a, b;
    switch (opc3)
    {
    case 1:
        printf("Se lanza una moneda. Probabilidad de que salga cara\n");
        scanf_s("%d%d", &a, &b);
        if (a == 1 && b == 2)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  1/2\n");
            return(0);
        }
        break;
    case 2:
        printf("Se lanzan tres monedas. Probabilidad de que salga lo mismo en las tres.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 2 && b == 8)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  2/8\n");
            return(0);
        }
        break;
    case 3:
        printf("Hay 7 mujeres y 5 hombres;se apuntan sus nombres y se guardan en una caja;se extrae un nombre. Probabilidad de que sea de un hombre.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 5 && b == 12)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  5/12\n");
            return(0);
        }
        break;
    case 4:
        printf("Se lanzan dos dados. Probabilidad de que salga un numero par en algun dado.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 27 && b == 36)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  27/36\n");
            return(0);
        }
        break;
    case 5:
        int color;
        printf("Tenemos una ruleta que tiene 3 secciones verdes, 2 azules, 2 rosas y una roja. \n");
        printf("Si se gira la ruleta indica que color tiene mas probabilidad de salir:\n");
        printf("1-VERDE  //  2-AZUL  //  3-ROSA  //  4-ROJO\n");
        scanf_s("%d", &color);
        if (color == 1)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  VERDE\n");
            return(0);
        }
        break;
    case 6:
        printf("Si se tienen 6 monedas numeradas del 1 al 6 y se elige una al azar. Probabilidad de que el numero que aparece en la moneda sea mayor o igual a 3\n");
        scanf_s("%d%d", &a, &b);
        if (a == 4 && b == 6)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  4/6\n");
            return(0);
        }
        break;
    case 7:
        printf("En una bolsa hay 15 caramelos: 5 de fresa, 7 de limon y 3 de naranja. Si saca uno al azar; probabilidad de que sea de limon.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 7 && b == 15)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  7/15\n");
            return(0);
        }
        break;
    case 8:
        printf("En una urna hay 5 bolas rojas. Se saca una al azar. Probabilidad de que sea roja.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 5 && b == 5)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  5/5\n");
            return(0);
        }
        break;
    case 9:
        printf("En una urna hay 5 bolas rojas, se saca una al azar. Probabilidad de que sea amarilla.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 0 && b == 5)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  0/5\n");
            return(0);
        }
        printf("Respuesta incorrecta\n");
        break;
    case 10:
        printf("Se tira una moneda y un dado a la vez. Probabilidad de que salga un numero par en el dado y cara en la moneda.\n");
        scanf_s("%d%d", &a, &b);
        if (a == 3 && b == 12)
        {
            printf("Respuesta correcta\n");
            return(1);
        }
        else
        {
            printf("Respuesta incorrecta\n");
            printf("Respuesta correcta:  3/12\n");
            return(0);
        }
        break;
    }

}
void imprimir_reto_est(int fila_inicial, int fila_final)
{
    int aux = 0;
    FILE* fi;
    char linea[3000]; // Almacena cada línea del archivo
    fi = fopen("preg_est.txt", "r");


    if (fi == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    while (fgets(linea, 3000, fi) != NULL)//Lee las líneas del fichero
    {
        aux++;
        if ((aux >= fila_inicial) && (aux <= fila_final))
            printf("%s", linea);
    }
}
int areatriang()
{
    int base, altura, respuesta = 0, area;
    srand(time(0)); // Inicializar el generador de números aleatorios

    base = rand() % 10 + 1; // Generar un número aleatorio entre 1 y 10
    altura = rand() % 10 + 1; // Generar otro número aleatorio entre 1 y 10

    area = base * altura / 2; // Calcular el área del triángulo

    printf("Calcula el area de un triangulo con base %d y altura %d ", base, altura);
    char pista;
    printf("¿Quieres una pista? (s/n): ");
    scanf_s(" %c", &pista);
    if (pista == 's' || pista == 'S') {
        printf("La formula del area del triangulo es base * altura / 2\n\nAhora introduce tu respuesta:");
        scanf_s("%d", &respuesta);
    }
    if (pista == 'n' || pista == 'N') {
        printf("Introduce tu respuesta");
        scanf_s("%d", &respuesta);
    }

    if (respuesta == area) {
        printf("Perfecto. La respuesta es correcta. El area es %d m^2. \n", area);
        return 1;
    }
    else {
        printf("Lo siento, la respuesta es incorrecta.\n");
        return 0;

    }
    getchar();
}
int* calcnumitera(int numini, int* iteracciones) //Funcion para calcular el numero de iteracciones necesarias de la conjetura y devuelve ese numero de iteracciones ademas inicializa un puntero con esa dimension
{
    int r = numini, * resultados, totales = 0;
    while (r != 1)
    {
        if (r % 2 == 0)
            r = r / 2;
        else
            r = r * 3 + 1;

        totales++;
    }
    *iteracciones = totales;
    resultados = (int*)malloc(totales * sizeof(int));
    if (resultados == NULL)
        exit(1);

    return(resultados);
}
void inivec(int* resultados, int numini, int iteracciones) //Funcion para inicializar el puntero y conocer las respuestas
{
    int r = numini;
    for (int i = 0; i < iteracciones; i++)
    {
        if (r % 2 == 0)
            r = r / 2;
        else
            r = r * 3 + 1;
        resultados[i] = r;
    }
}
int estructjuego_se(int numini, int* resultados, int iteracciones)
{
    int respuesta, vidas = 1;
    printf("Estas son las reglas del juego: \nSi el numero que te toca es par dividelo entre dos.\nSi es impar multiplicalo por tres y sumale uno.\nHaz eso con cada numero que te salga despues de dividir o multiplicar hasta llegaras al uno.");
    printf("\n\nTe toco el numero: %d", numini);
    for (int i = 0; i < iteracciones; i++)
    {
        printf("\nEl numero siguiente es: ");
        scanf_s("%d", &respuesta);
        if (respuesta == resultados[i])
            printf("\nMuy bien!!");
        else
        {
            printf("\nIncorrecto!!");
            if (vidas == 1)
            {
                vidas--;
                printf("\nTienes una oportunidad mas.\n");
                i--;
            }
            else
            {
                printf("\nMalas suerte perdiste :(\n");
                return 0;
                break;
            }
        }
    }
    if (vidas != 0)
    {
        printf("\nFelicidades ganaste, ademas acabas de descrubrir la famosa conjetura de collatz que dice:\n'A partir de cualquier numero si sigues la sucesion dicha al principio llegaras al uno'");
        return 1;
    }
    free(resultados);
}
int multiplicacion(int num1, int num2)
{
    return(num1 * num2);
}
int estructmulti(void)
{
    int cuenta = 3, listo = 0;

    printf("Bienvenido a un nuevo reto\n\n%cEstas preparado?\n", 168);
    printf("Dale al 1 para empezar\n");

    do //Empezar el juego
    {
        scanf_s("%d", &listo);
    } while (listo != 1);

    for (cuenta; cuenta > 0; cuenta--) //Para la cuenta atras
    {
        printf("\t\t\t%d\n", cuenta);
        Sleep(1000); //1000 milisegundos=1 segundo, la funcion sleep esta definida en milisegundos y sirve para espera
    }

    srand(time(NULL)); //Declara la semalla random
    int num1, num2, resultado = 0, respuesta = 0;

    printf("\nCuantos es...\n");
    for (int i = 0; i < 10; i++)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        printf("\t\t%d\t\tX\t\t%d\r", num1, num2);
        Sleep(100);
    }
    resultado = multiplicacion(num1, num2); //Llama a la funcion
    printf("\n\nDime tu respuesta: ");
    scanf_s("%d", &respuesta);
    if (resultado == respuesta)
    {
        printf("\nEs la respuesta correcta\n\n");
        return 1;
    }
    else
    {
        printf("\nEsta no es la respuesta\n\n");
        return 0;
    }
}

struct poligono generar_poligono() {
    struct poligono p;
    int n = rand() % 10 + 3; // Generamos un número aleatorio de lados entre 3 y 12
    p.lados = n;
    switch (n) {
    case 3:
        strcpy_s(p.nombre, _countof(p.nombre), "triangulo");
        break;
    case 4:
        strcpy_s(p.nombre, _countof(p.nombre), "cuadrilatero");
        break;
    case 5:
        strcpy_s(p.nombre, _countof(p.nombre), "pentagono");
        break;
    case 6:
        strcpy_s(p.nombre, _countof(p.nombre), "hexagono");
        break;
    case 7:
        strcpy_s(p.nombre, _countof(p.nombre), "heptagono");
        break;
    case 8:
        strcpy_s(p.nombre, _countof(p.nombre), "octagono");
        break;
    case 9:
        strcpy_s(p.nombre, _countof(p.nombre), "eneagono");
        break;
    case 10:
        strcpy_s(p.nombre, _countof(p.nombre), "decagono");
        break;
    case 11:
        strcpy_s(p.nombre, _countof(p.nombre), "endecagono");
        break;
    case 12:
        strcpy_s(p.nombre, _countof(p.nombre), "dodecagono");
        break;
    }
    return p;
}
// Función para jugar a adivinar el número de lados de un polígono
int n_lados_poligono() 
{
    srand(time(NULL)); // Inicializamos el generador de números aleatorios
    struct poligono p; // Declaramos una variable para el polígono
    int aciertos = 0;
    int intentos = 0;
    int respuesta;
    while (intentos < 10) 
    {
        p = generar_poligono(); // Generamos un polígono aleatorio
        printf("Cuantos lados tiene un %s? \n", p.nombre);
        scanf_s("%d", &respuesta);
        if (respuesta == p.lados) {
            printf("Correcto!\n");
            aciertos++;
        }
        else {
            printf("Incorrecto. Un %s tiene %d lados.\n", p.nombre, p.lados);
        }
        intentos++;
        printf("Llevas %d aciertos de %d intentos.\n", aciertos, intentos);
        if (aciertos == 5)
        {
            printf("Ganaste!!");
            return(1);
        }
        else if (intentos == 10) 
        {
            printf("Se han agotado los intentos. El juego ha terminado.\n");
            return (0);
        }
    
    }
} 
void imprimirProblema(int lineaInicio, int lineaFin) {
    FILE* archivo;
    char linea[1000]; // Crea un buffer para almacenar cada línea
    int numLinea = 0; // Contador de línea

    archivo = fopen("Problemasinfo.txt", "r");// Abre el archivo en modo lectura
    if (archivo == NULL) { // Verifica si se pudo abrir el archivo
        printf("No se pudo abrir el archivo.\n");
        exit(1); // Sale del programa con un código de error
    }

    printf("Contenido del archivo. \n\n");

    // Lee y escribe las líneas del archivo
    while (fgets(linea, 1000, archivo) != NULL) {
        numLinea++;

        // Imprime las líneas seleccionadas
        if (numLinea >= lineaInicio && numLinea <= lineaFin) {
            printf("%s", linea);
        }
    }

    if (fclose(archivo) != 0)
        printf("Problemas al cerrar el fichero.\n");
}

int problemas() {
    int opcion;
    int resultado;

    printf("Seleccione un problema al azar:\n");
    printf("1. Problema 1\n");
    printf("2. Problema 2\n");
    printf("3. Problema 3\n");
    printf("4. Problema 4\n");
    printf("5. Problema 5\n");

    do {
        scanf_s("%d", &opcion);
        switch (opcion) {

        case 1:
            imprimirProblema(0, 5);
            scanf_s("%d", &resultado);
            if (resultado == 25)
            {
                printf("\nCorrecto! Para alcanzar a Gema le quedan 25 km por recorrer \n");
                return 1;
            }
            else {
                printf("\nIncorrecto!\n");
                return 0;
                break; // salir del switch
            }
            break;
        case 2:
            imprimirProblema(6, 15);
            scanf_s("%d", &resultado);
            if (resultado == 3)
            {
                printf("\nCorrecto! El club podra comprar 6 equipaciones\n");
                return 1;
            }
            else {
                printf("\nIncorrecto!\n");
                return 0;
                break; // salir del switch
            }
            break;
        case 3:
            imprimirProblema(16, 20);
            scanf_s("%d", &resultado);
            if (resultado == 24)
            {
                printf("\nCorrecto! El mes pasado ahorro 24 euros\n");
                return 1;
            }
            else {
                printf("\nIncorrecto!\n");
                return 0;
                break; // salir del switch
            }
            break;
        case 4:
            imprimirProblema(21, 25);
            scanf_s("%d", &resultado);
            if (resultado == 261)
            {
                printf("\nCorrecto! Vera tenia 261 euros\n");
                return 1;
            }
            else {
                printf("\nIncorrecto!\n");
                return 0;
                break; // salir del switch
            }
            break;
        case 5:
            imprimirProblema(26, 33);
            scanf_s("%d", &resultado);
            if (resultado == 1)
            {
                printf("\nCorrecto! Equivale a 552 cm\n");
                return 1;
            }
            else {
                printf("\nIncorrecto!\n");
                return 0;
                break; // salir del switch
            }
            break;
        default:
            printf("\nOpcion invalida. Seleccione una opcion valida.\n");
            break;
        }
    } while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
}

void creditos()
{
    printf("Este trabajo esta realizado por los siguientes alumnos: \n");
    Sleep(1000);
    printf("Rocio Geldbord\nAdrian Juarez\nVictor Casanova\nPablo Dinis\n");
    Sleep(1000);
    printf("Pertenecientes al grado en ingenieria electronica industrial y automatica\n");
    printf("Pertenecientes al grupo A104\n");
    Sleep(1000);
    printf("Ha sido realizado en el curso 22/23\n");
}