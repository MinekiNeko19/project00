#include "linkedsongs.h"

struct song_node ** make_lib();
struct song_node ** add_song(struct song_node ** lib, char a[100], char s[100]);
struct song_node * find_songlib(struct song_node ** lib, char a[100], char s[100]);
struct song_node * find_artistlib(struct song_node ** lib, char a[100]);
void print_lib(struct song_node ** lib);
void print_letter(struct song_node ** lib);
void print_artist(struct song_node ** lib);
struct song_node * shuffle(struct song_node ** lib, int numSongs);
struct song_node ** delete_song(struct song_node ** lib, char a[100], char s[100]);
struct song_node ** free_lib(struct song_node ** lib);