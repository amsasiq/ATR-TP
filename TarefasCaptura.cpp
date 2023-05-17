#include <iostream>

// *** Bibliotecas ***
// Rever as bibliotecas 
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <errno.h>
#include <signal.h>
#include <conio.h>		                                                        
#include <math.h>                                                               
#include <time.h>
#include <string.h>
#include <locale.h>
//#include <pthread.h>
#include <string>
//#define _CHECKERROR	1
//#include "CheckForError.h"   

// *** Constantes ***
#define TECLA_ESC 0x1B
#define WIN32_LEAN_AND_MEAN 
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#define TAM_MSG 42

DWORD WINAPI WaitEventFunc(LPVOID);	// declara��o da fun��o  coisa do c�digo exemplo

// Casting para terceiro e sexto par�metros da fun��o _beginthreadex
typedef unsigned (WINAPI* CAST_FUNCTION)(LPVOID);
typedef unsigned* CAST_LPDWORD;


int main() { // Receber parametros
    HANDLE hListaCircular;
    BOOL bStatus;
    char* lpImage;

    hListaCircular = OpenFileMapping(
        FALSE_MAP_ALL_ACCESS,               // Direitos de acesso
        FALSE,                              // O handle n�o ser� herdado
        "LISTA_CIRCULAR"                    // Apontador para o nome do objeto
    );
    //CheckForError(hListaCircular);

    lpImage = (char*)MapViewOfFile(
        hListaCircular,             //Handle para o arquivo mapeado
        FILE_MAP_WRITE,		        // Direitos de acesso: leitura e escrita
        0,                          // Bits mais significativos da "vis�o"
        0,                          // Bits menos significativos da "vis�o"
        TAM_MSG
    );
    //CheckForError(lpImage);


    printf("*** tarefas de captura iniciadas ***\n");

    // recebe o evento de bloqueio e o esc
    // recebe ids de comunica��o com as tarefas de captura
    // criar objetos de sincroniza��o
        // mutex de leitura/escrita da lista circular
        // evento de temporiza��o
    // criar a lista circular
    // gerar mensagem
        // armazenar mensagem na lista
    // wait for multiple, bloqueio ou ESC

    bStatus = UnmapViewOfFile(lpImage);
    //CheckForError(bStatus);
    CloseHandle(hListaCircular);

    return 0;
}

