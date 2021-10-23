#include "library.h"

int main() {
    // struct song_node * dw;
    // testing linkedsongs.c
    // printf("\n==================================\n");
    // printf("\nTesting print_list:\n\n");

    // // scrambled
    // dw = insert_front(dw, "pearl jam", "yellow ledbetter");
    // dw = insert_front(dw, "radiohead", "paranoid android");
    // dw = insert_front(dw, "radiohead", "street spirit (fade out)");
    // dw = insert_front(dw, "ac/dc", "thunderstruck");
    // dw = insert_front(dw, "pearl jam", "even flow");
    // dw = insert_front(dw, "pink floyd", "time");
    // dw = insert_front(dw, "pearl jam", "alive");

    // ordered
    // dw = insert_front(dw, "radiohead", "street spirit (fade out)");
    // dw = insert_front(dw, "radiohead", "paranoid android");
    // dw = insert_front(dw, "pink floyd", "time");
    // dw = insert_front(dw, "pearl jam", "yellow ledbetter");
    // dw = insert_front(dw, "pearl jam", "even flow");
    // dw = insert_front(dw, "pearl jam", "alive");
    // dw = insert_front(dw, "ac/dc", "thunderstruck");

    // print_list(dw);

    // printf("\n==================================\n");
    // printf("\nTesting find_song and print_song:\n\n");
    // print_song(find_song(dw, "pearl jam", "even flow"));
    // print_song(find_song(dw, "yeet", "delete"));

    // printf("\n==================================\n");
    // printf("\nTesting compare_song and order_list:\n\n");
    // // printf("%d\n",compare_songs(dw, dw->next));
    // printf("original: \n");
    // print_list(dw);
    //     // swap(dw, dw->next);
    //     // print_list(dw);
    // dw = order_list(dw);
    // printf("\nnew: \n");
    // print_list(dw);

    // printf("\n==================================\n");
    // printf("\nTesting find_artist\n\n");
    // print_list(find_artist(dw,"pearl jam"));
    // print_list(find_artist(dw,"toto"));

    // printf("\n==================================\n");
    // printf("\nTesting random_song\n\n");
    // print_song(random_song(dw));

    // printf("\n==================================\n");
    // printf("\nTesting remove_song\n\n");
    // print_list(dw);
    // print_song(remove_song(dw,"pink floyd", "time"));
    // print_list(dw);

    // printf("\n==================================\n");
    // printf("\nTesting free_list\n\n");
    // printf("original: \n");
    // print_list(dw);
    // dw = free_list(dw);
    // printf("\nnew: \n");
    // print_list(dw);

    // testing library

    printf("\n==================================\n");
    printf("\nTesting make_lib, add_song, and print_lib\n\n");
    struct song_node ** dwlib = make_lib();
    struct song_node * temp;
    // temp = insert_front(temp, "yoink", "bonk");
    // dwlib[1] = temp;
    dwlib = add_song(dwlib, "pearl jam", "yellow ledbetter");
    dwlib = add_song(dwlib, "radiohead", "paranoid android");
    dwlib = add_song(dwlib, "radiohead", "street spirit (fade out)");
    dwlib = add_song(dwlib, "ac/dc", "thunderstruck");
    dwlib = add_song(dwlib, "pearl jam", "even flow");
    dwlib = add_song(dwlib, "pink floyd", "time");
    dwlib = add_song(dwlib, "pearl jam", "alive");
    print_lib(dwlib);
    
    printf("\n==================================\n");
    printf("\nTesting find_song, find_artist\n\n");
    print_song(find_songlib(dwlib,"radiohead","paranoid android"));
    print_song(find_songlib(dwlib,"tornados","brrr"));

    print_song(find_artistlib(dwlib,"pearl jam"));
    print_song(find_artistlib(dwlib,"jam"));

    return 0;
}

struct song_node ** make_lib() {
    struct song_node ** temp = calloc(27,sizeof(struct song_node *));
    return temp;
}

struct song_node ** add_song(struct song_node ** lib, char a[100], char s[100]) {
    // Uppercase Letters − A - Z having ASCII values from 65 - 90 where, 65 and 90 are inclusive.
    // Lowercase Letter − a - z having ASCII values from 97 - 122 where, 97 and 122 are inclusive.
    struct song_node * temp = lib[a[0]%97];
    temp = insert_front(temp, a, s);
    temp = order_list(temp);
    // printf("%c %d\n",a[0]%97,a[0]%97);
    // print_list(temp);
    lib[a[0]%97] = temp;
    return lib;
}

struct song_node * find_songlib(struct song_node ** lib, char a[100], char s[100]) {
    return find_song(lib[a[0]%97],a,s);
}

struct song_node * find_artistlib(struct song_node ** lib, char a[100]) {
    struct song_node * temp = find_artist(lib[a[0]%97],a);
    while (temp && strcmp(temp -> artist,a)==0) {
        printf("{%s, %s} | ", temp -> artist, temp -> name);
        temp = temp -> next; 
    }
    printf("\n");
    return find_artist(lib[a[0]%97],a);
}

void print_lib(struct song_node ** lib) {
    struct song_node ** temp = lib;
    struct song_node * tempsong;
    int i;
    for (i = 0; i < 27; i++) {
        tempsong = lib[i];
        if (i != 26) {
            printf("%d %c\n", 65+i,65+i);
        } else {
            printf("Other:\n");
        }
        print_list(tempsong);
    }
}

// void print_letter(struct song_node ** lib);
// void print_artist(struct song_node ** lib);
// struct song_node * shuffle(struct song_node ** lib, int numSongs);
// struct song_node ** delete_song(struct song_node ** lib, char a[100], char s[100]);
// struct song_node ** free_lib(struct song_node ** lib);