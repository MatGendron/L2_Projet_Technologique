#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "game.h"


/* ********** TEST is_edge *********** */
int test_is_edge(int argc, char *argv[])
{
   if ( ! is_edge(SEGMENT , N , N) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(SEGMENT , N , S) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(SEGMENT , S , S) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(SEGMENT , S , N) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

                if ( ! is_edge(SEGMENT , E , E) )
                { 
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(SEGMENT , E , W) )
                { 
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(SEGMENT , W , W) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(SEGMENT , W , E) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
            
            ///////////////_test_LEAF_//////////////////// 
          
                if ( ! is_edge(LEAF , N , N) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                
            
                if ( ! is_edge(LEAF , S , S) )
                {
                    
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

                if ( ! is_edge(LEAF , W , W) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
        
                if ( ! is_edge(LEAF , E , E) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

            }       
            ///////////////_test_CORNER_/////////////////// 
            if ( ! is_edge(CORNER , N , N) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

             if ( ! is_edge(CORNER , N , E) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }   
                
            
                if ( ! is_edge(CORNER , S , S) )
                {
                    
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

                if ( ! is_edge(CORNER , S , W) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

                if ( ! is_edge(CORNER , W , W) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(CORNER , W , N) )
                {
                   
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
        
                if ( ! is_edge(CORNER , E , E) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(CORNER , E , S) )
                {
                    fprintf(stderr, "Error: connection piece!\n");
                    return EXIT_FAILURE;
                }

            
            ///////////////_test_TEE_///////////////////
            
                if ( ! is_edge(TEE , N , N) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , N , E) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , N , W) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
            
                if ( ! is_edge(TEE , S , S) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , S , W) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , S , E) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

                if ( ! is_edge(TEE , W , W) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , W , N) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , W , S) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }

          
                if ( ! is_edge(TEE , E , E) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , E , N) )
                {
                    fprintf(stderr, "Error: connection piece )!\n");
                    return EXIT_FAILURE;
                }
                if ( ! is_edge(TEE , E , S) )
                {
                    fprintf(stderr, "Error: connection piece !\n");
                    return EXIT_FAILURE;
                }
    return EXIT_SUCCESS;
}

/* ********** TEST opposite_dir *********** */
int test_opposite_dir(int argc, char *argv[])
{

    /*
    Setting up the parameters of the game
    */
    piece p1[] = {
        LEAF, TEE, LEAF, LEAF, LEAF,
        LEAF, TEE, TEE, CORNER, SEGMENT,
        LEAF, LEAF, TEE, LEAF, SEGMENT,
        TEE, TEE, TEE, TEE, TEE,
        CORNER, LEAF, LEAF, CORNER, LEAF
    };
    direction p2[] = {
        E, W, S, E, S,
        S, S, N, W, N,
        E, N, W, W, E,
        S, W, N, E, E,
        W, N, W, N, S,
    };
    game g = new_game(p1, p2);
    assert(g);
    int w = game_width(g);
    int h = game_height(g);
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++)
        {
            direction d = get_current_dir(g, x, y);
            if(d==N){
                if ( opposite_dir( d ) != S )
                {
                    delete_game(g);
                    g = NULL;
                    fprintf(stderr, "Error: opposite direction (%d,%d)!\n", x, y);
                    return EXIT_FAILURE;
                }
            } 
            if(d==S){
                if ( opposite_dir( d ) != N )
                {
                    delete_game(g);
                    g = NULL;
                    fprintf(stderr, "Error: opposite direction (%d,%d)!\n", x, y);
                    return EXIT_FAILURE;
                }
            }
            if(d==W){
                if ( opposite_dir( d ) != E )
                {
                    delete_game(g);
                    g = NULL;
                    fprintf(stderr, "Error: opposite direction (%d,%d)!\n", x, y);
                    return EXIT_FAILURE;
                }
            }       
            if(d==E){
                if ( opposite_dir( d ) != W )
                {
                    delete_game(g);
                    g = NULL;
                    fprintf(stderr, "Error: opposite direction (%d,%d)!\n", x, y);
                    return EXIT_FAILURE;
                }
            }              
        }
    }    
    delete_game(g);
    g = NULL;
    return EXIT_SUCCESS;
}

/* ********** TEST copy_game *********** */
int test_copy_game (int argc, char *argv[]){

    /*
    Setting up the parameters of the game
    */
    piece p1[] = {
        LEAF, TEE, LEAF, LEAF, LEAF,
        LEAF, TEE, TEE, CORNER, SEGMENT,
        LEAF, LEAF, TEE, LEAF, SEGMENT,
        TEE, TEE, TEE, TEE, TEE,
        CORNER, LEAF, LEAF, CORNER, LEAF
    };
    direction p2[] = {
        E, W, S, E, S,
        S, S, N, W, N,
        E, N, W, W, E,
        S, W, N, E, E,
        W, N, W, N, S,
    };
    game g = new_game(p1, p2);
    assert(g);
    game g_copy=copy_game (g);
    assert(g_copy);

    if ( game_width(g) != game_width(g_copy))
    {
        delete_game(g);
        g = NULL;
        fprintf(stderr, "Error: copy game width !\n");
        return EXIT_FAILURE;
    }
    if ( game_height(g) != game_height(g_copy))
    {
        delete_game(g);
        g = NULL;
        fprintf(stderr, "Error: copy game height !\n");
        return EXIT_FAILURE;
    }

    int w = game_width(g);
    int h = game_height(g);
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++)
        {
            direction d = get_current_dir(g, x, y);
            direction d_copy = get_current_dir(g_copy, x, y);

            if (   (get_piece(g, x, y) != get_piece(g_copy, x, y) )  && ( d != d_copy )   )
            {
                delete_game(g);
                g = NULL;
                delete_game(g_copy);
                g_copy = NULL;   
                fprintf(stderr, "Error: copy game (%d,%d)!\n", x, y);
                return EXIT_FAILURE;
            }
        }
    }
    delete_game(g);
    g = NULL;
    delete_game(g_copy);
    g_copy = NULL;    
    return EXIT_SUCCESS;
}


/* ********** TEST EMPTY ********** */
/*
int test_empty(int argc, char *argv[])
{
    game g = new_game_empty();
    assert(g);
    int w = game_width(g);
    int h = game_height(g);
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++)
        {
            if (get_piece(g, x, y) != EMPTY)
            {
                fprintf(stderr, "Error: piece (%d,%d) is not empty!\n", x, y);
                return EXIT_FAILURE;
            }
        }
    }    
    delete_game(g);
    g = NULL;
    return EXIT_SUCCESS;
}
*/

/* ********** USAGE ********** */

#ifndef TESTFW

void usage(int argc, char *argv[])
{
    fprintf(stderr, "Usage: %s <testname>\n", argv[0]);
    exit(EXIT_FAILURE);
}

#endif

/* ********** MAIN ROUTINE ********** */

#ifndef TESTFW

int main(int argc, char *argv[])
{
    if (argc == 1)
        usage(argc, argv);

    printf("=> RUN TEST \"%s\"\n", argv[1]);

    int status;
    /*if (strcmp("empty", argv[1]) == 0)
	  status = test_empty(argc, argv);*/
    if (strcmp("is_edge_coordinates", argv[1]) == 0)
        status = test_is_edge_coordinates(argc, argv); 
    else if (strcmp("is_edge", argv[1]) == 0)
        status = test_is_edge(argc, argv); 
    else if (strcmp("opposite_dir", argv[1]) == 0)
        status = test_opposite_dir(argc, argv); 
    else if (strcmp("copy_game", argv[1]) == 0)
        status = test_copy_game(argc, argv);             
    else
    {
        fprintf(stderr, "Error: test %s not found!\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (status != EXIT_SUCCESS)
        printf("FAILURE (status %d)\n", status);
    else
        printf("SUCCESS (status %d)\n", status);

    return status;
}

#endif
