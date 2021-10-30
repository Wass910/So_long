#include "so_long.h"

void    error_close_map_exit(void)
{
    printf("Il doit y' avoir au moin une sortie ok bg\n");
    exit(EXIT_FAILURE);
}

void    error_close_map_collectible(void)
{
    printf("Il doit y' avoir au moin un collectible ok bg\n");
    exit(EXIT_FAILURE);
}

void    error_close_map_appear(void)
{
    printf("Il doit y' avoir uniquement un point d apparition c'est tout ok bg\n");
    exit(EXIT_FAILURE);
}

void    error_close_map(void)
{
    printf("Erreur la map n'est pas ferme\n");
    exit(EXIT_FAILURE);
}