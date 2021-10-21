#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

// struct song_node * add_song(char n[100], char a[100]);
struct song_node * insert_front(struct song_node * list, char a[100], char s[100]); // done
struct song_node * order_list(struct song_node * list);
// struct song_node * compare_songs(struct song_node * s1, struct song_node * s2); // helper
struct song_node * compare_songs(struct song_node * prev); 
void print_list(struct song_node * list); // done
void print_song(struct song_node * song); // helper // done
struct song_node * find_song(struct song_node * list, char a[100], char s[100]); // done
struct song_node * find_artist(struct song_node * list, char a[100]);
struct song_node * random_song(struct song_node * list);
struct song_node * remove_song(struct song_node * list, char a[100], char s[100]);
struct song_node * free_list(struct song_node * list);