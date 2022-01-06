#include "cola.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>


static void prueba_cola_vacia(void) {
    printf("INICIO DE PRUEBAS COLA VACIA\n");

    /* Declaro las variables a utilizar*/
    cola_t *cola = cola_crear();

    /* Inicio de pruebas */
    print_test("crear cola", cola != NULL);
    print_test("la cola esta vacia", cola_esta_vacia(cola));

    /* Pruebo ver el primero de una cola vacia */
    print_test("ver primero de una cola vacia es NULL", cola_ver_primero(cola) == NULL);

    /* Pruebo desencolar de una cola vacia */
    print_test("desencolar un cola vacia es NULL", cola_desencolar(cola) == NULL);

    /* Destruyo la cola*/
    cola_destruir(cola, NULL);
    print_test("la cola fue destruida", true);
}

static void prueba_encolar_desencolar(void) {
    printf("INICIO DE PRUEBAS DE ENCOLAR Y DESENCOLAR\n");
    
    cola_t *cola2 = cola_crear();
    print_test("crear cola", cola2 != NULL);
    
    /* Declaro las variables a utilizar*/
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    int n5 = 5;
    int *valor1 = &n1;
    int *valor2 = &n2;
    int *valor3 = &n3;
    int *valor4 = &n4;
    int *valor5 = &n5;
    
    /* Pruebo encolar*/
    print_test("se encolo el elemento 1", cola_encolar(cola2, valor1));
    
    /* Pruebo que el elemento encolado es el primero */
    print_test("el primero es el elemento 1", (cola_ver_primero(cola2) == valor1));
    
    print_test("se encolo el elemento 2", cola_encolar(cola2, valor2));
    
    /* Pruebo desencolar */
    print_test("se desencolo el elemento 1", cola_desencolar(cola2) == valor1);
    
    /* Luego el nuevo primero es el elemento 2 */
    print_test("el nuevo primero es el elemento 2", (cola_ver_primero(cola2) == valor2));
    
    print_test("se encolo el elemento 3", cola_encolar(cola2, valor3));
    
    print_test("se encolo el elemento 4", cola_encolar(cola2, valor4));
    
    /* Pruebo desencolar */
    print_test("se desencolo el elemento 2", cola_desencolar(cola2) == valor2);
    
    /* Luego el nuevo primero es el elemento 3 */
    print_test("el nuevo primero es el elemento 3", (cola_ver_primero(cola2) == valor3));
    
    print_test("se encolo el elemento 5", cola_encolar(cola2, valor5));
    
    print_test("se desencolo el elemento 3", cola_desencolar(cola2) == valor3);
    
    print_test("el nuevo primero es el elemento 4", (cola_ver_primero(cola2) == valor4));
    print_test("se desencolo el elemento 4", cola_desencolar(cola2) == valor4);
    
    print_test("el nuevo primero es el elemento 5", (cola_ver_primero(cola2) == valor5));
    print_test("se desencolo el elemento 5", cola_desencolar(cola2) == valor5);
    
    /* Pruebo que la cola este vacia */
    print_test("la cola esta vacia", cola_esta_vacia(cola2));
    
    /* Pruebo ver el primero de una cola vacia */
    print_test("ver primero de una cola vacia es NULL", cola_ver_primero(cola2) == NULL);
    
    /* Pruebo desencolar de una cola vacia */
    print_test("desencolar un cola vacia es NULL", cola_desencolar(cola2) == NULL);
    
    /* Destruyo la cola*/
    cola_destruir(cola2, NULL);
    print_test("la cola fue destruida", true);
}

static void prueba_elemento_NULL(void) {
    printf("INICIO DE PRUEBAS ELEMENTO NULL\n");
    
    cola_t *cola3 = cola_crear();
    print_test("crear cola", cola3 != NULL);
    
    /* Pruebo encolar NULL */
    print_test("se encolo el elemento NULL", cola_encolar(cola3, NULL));
    
    /* Pruebo que la cola NO este vacia */
    print_test("la cola NO esta vacia", !cola_esta_vacia(cola3));
    
    /* Pruebo ver primero */
    print_test("el primero es el elemento NULL", (cola_ver_primero(cola3) == NULL));
    
    /* Pruebo desencolar NULL */
    print_test("desencolo NULL", cola_desencolar(cola3) == NULL);
    
    /* Pruebo que la cola este vacia */
    print_test("la cola esta vacia", cola_esta_vacia(cola3));
    
    /* Destruyo la cola */
    cola_destruir(cola3, NULL);
    print_test("la cola fue destruida", true);
}

static void prueba_cola_volumen(void) {
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");
    
    cola_t *cola4 = cola_crear();
    print_test("crear cola", cola4 != NULL);
    
    /* Declaro las variables a utilizar*/
    int n6 = 6;
    int n7 = 7;
    int n8 = 8;
    int n9 = 9;
    int n10 = 10;
    int *valor6 = &n6;
    int *valor7 = &n7;
    int *valor8 = &n8;
    int *valor9 = &n9;
    int *valor10 = &n10;
    
    size_t volumen = 1000;
    size_t i = 0;
    bool ok = true;
    bool ok2 = true;
    bool ok3 = true;
    printf("PRUEBA CON %ld ELEMENTOS / %ld BYTES\n", volumen, volumen * sizeof(void *));
    
    /* Pruebo que se pueden encolar muchos elementos */
    for (size_t i2 = 0; i2 < volumen ; i2++) {
        if (i == 0) {
            ok &= cola_encolar(cola4, valor6);
        } else if (i == 1) {
            ok &= cola_encolar(cola4, valor7);
        } else if (i == 2) {
            ok &= cola_encolar(cola4, valor8);
        } else if (i == 3) {
            ok &= cola_encolar(cola4, valor9);
        } else if (i == 4) {
            ok &= cola_encolar(cola4, valor10);
            i = 0;
            continue;
        }
        i++;
    }
    
    print_test("se pudieron encolar todos los elementos", ok);
    
    /* Pruebo que se pueden desencolar muchos elementos */
    for (size_t i2 = 0; i2 < volumen ; i2++) {
        if (i == 0) {
            ok2 &= cola_ver_primero(cola4) == valor6;
            ok3 &= cola_desencolar(cola4) == valor6;
        } else if (i == 1) {
            ok2 &= cola_ver_primero(cola4) == valor7;
            ok3 &= cola_desencolar(cola4) == valor7;
        } else if (i == 2) {
            ok2 &= cola_ver_primero(cola4) == valor8;
            ok3 &= cola_desencolar(cola4) == valor8;
        } else if (i == 3) {
            ok2 &= cola_ver_primero(cola4) == valor9;
            ok3 &= cola_desencolar(cola4) == valor9;
        } else if (i == 4) {
            ok2 &= cola_ver_primero(cola4) == valor10;
            ok3 &= cola_desencolar(cola4) == valor10;
            i = 0;
            continue;
        }
        i++;
    }
    //cola_desencolar(cola4)
    
    print_test("se pudieron desencolar todos los elementos", cola_esta_vacia(cola4));
    print_test("todos los primeros fueron correctos", ok2);
    print_test("todos los elementos fueron correctos", ok3);
    
    /* Destruyo la cola*/
    cola_destruir(cola4, NULL);
    print_test("la cola fue destruida", true);
}

static void prueba_cola_destruir(void) {
    printf("INICIO DE PRUEBAS DESTRUIR COLA\n");
    
    cola_t *cola5 = cola_crear();
    print_test("crear cola", cola5 != NULL);
    
    /* Declaro las variables a utilizar*/
    int n11 = 11;
    int n12 = 12;
    int n13 = 13;
    int n14 = 14;
    int n15 = 15;
    int *valor11 = &n11;
    int *valor12 = &n12;
    int *valor13 = &n13;
    int *valor14 = &n14;
    int *valor15 = &n15;
    size_t volumen = 1000;
    size_t i = 0;
    bool ok = true;
    
    for (size_t i2 = 0; i2 < volumen ; i2++) {
        if (i == 0) {
            ok &= cola_encolar(cola5, valor11);
        } else if (i == 1) {
            ok &= cola_encolar(cola5, valor12);
        } else if (i == 2) {
            ok &= cola_encolar(cola5, valor13);
        } else if (i == 3) {
            ok &= cola_encolar(cola5, valor14);
        } else if (i == 4) {
            ok &= cola_encolar(cola5, valor15);
            i = 0;
            continue;
        }
        i++;
    }
    
    print_test("se pudieron encolar todos los elementos", ok);
    
    /* Destruyo la cola*/
    cola_destruir(cola5, NULL);
    print_test("la cola llena fue destruida", true);   
}

static void prueba_cola_destruir_dato_free(void) {
    printf("INICIO DE PRUEBAS DESTRUIR DATO FREE\n");
    
    cola_t *cola6 = cola_crear();
    print_test("crear cola", cola6 != NULL);
    
    /* Declaro las variables a utilizar*/
    int n16 = 16;
    int n17 = 17;
    int n18 = 18;
    int n19 = 19;
    int n20 = 20;
    size_t volumen = 1000;
    size_t i = 0;
    bool ok = true;
    int *valor16;
    int *valor17;
    int *valor18;
    int *valor19;
    int *valor20;
    
    for (size_t i2 = 0; i2 < volumen ; i2++) {
        if (i == 0) {
            valor16 = malloc(sizeof(int));
            *valor16 = n16;
            ok &= cola_encolar(cola6, valor16);
        } else if (i == 1) {
            valor17 = malloc(sizeof(int));
            *valor17 = n17;
            ok &= cola_encolar(cola6, valor17);
        } else if (i == 2) {
            valor18 = malloc(sizeof(int));
            *valor18 = n18;
            ok &= cola_encolar(cola6, valor18);
        } else if (i == 3) {
            valor19 = malloc(sizeof(int));
            *valor19 = n19;
            ok &= cola_encolar(cola6, valor19);
        } else if (i == 4) {
            valor20 = malloc(sizeof(int));
            *valor20 = n20;
            ok &= cola_encolar(cola6, valor20);
            i = 0;
            continue;
        }
        i++;
    }
    
    print_test("se pudieron encolar todos los elementos", ok);
    
    /* Destruyo la cola*/
    cola_destruir(cola6, free);
    print_test("la cola llena fue destruida", true); 
}

void free_strv(void *dato) {
    char **strv = (char **) dato;
    for (int i = 0; strv[i] != NULL; i++) {
        free(strv[i]);
    }
    free(strv);
}

char **crea_strv() {
    size_t size = 5;
    char **strv = malloc(sizeof(char*) * size);
    size_t i = 0;
    char *str;
    while (i<(size-1)) {
        str = malloc(sizeof(char)*10);
        strv[i++] = str;
    }
    strv[i] = NULL;
    return strv;
}

static void prueba_cola_destruir_dato_funcion_aux(void) {
    printf("INICIO DE PRUEBAS DESTRUIR DATO FUNCION AUX\n");
    
    cola_t *cola7 = cola_crear();
    print_test("crear cola", cola7 != NULL);
    
    /* Declaro las variables a utilizar*/
    size_t volumen = 1;
    size_t i = 0;
    bool ok = true;
    char **strv21;
    char **strv22;
    char **strv23;
    char **strv24;
    char **strv25;
    
    for (size_t i2 = 0; i2 < volumen ; i2++) {
        if (i == 0) {
            strv21 = crea_strv();
            ok &= cola_encolar(cola7, strv21);
        } else if (i == 1) {
            strv22 = crea_strv();
            ok &= cola_encolar(cola7, strv22);
        } else if (i == 2) {
            strv23 = crea_strv();
            ok &= cola_encolar(cola7, strv23);
        } else if (i == 3) {
            strv24 = crea_strv();
            ok &= cola_encolar(cola7, strv24);
        } else if (i == 4) {
            strv25 = crea_strv();
            ok &= cola_encolar(cola7, strv25);
            i = 0;
            continue;
        }
        i++;
    }
    
    print_test("se pudieron encolar todos los elementos", ok);
    
    /* Destruyo la cola*/
    cola_destruir(cola7, free_strv);
    print_test("la cola llena fue destruida", true); 
}


void pruebas_cola_estudiante() {
    prueba_cola_vacia();
    prueba_encolar_desencolar();
    prueba_elemento_NULL();
    prueba_cola_volumen();
    prueba_cola_destruir();
    prueba_cola_destruir_dato_free();
    prueba_cola_destruir_dato_funcion_aux();
}

#ifndef CORRECTOR

int main(void) {
    pruebas_cola_estudiante();
    return failure_count() > 0;
}

#endif
