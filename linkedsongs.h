#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node * add_song();
struct song_node * insert_front();
struct song_node * order_list();
void print_list();
struct song_node * find_artist();
struct song_node * find_song();
struct song_node * random_song();
struct song_node * remove_song();
struct song_node * free_list();