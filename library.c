#include "library.h"

int main() {
    struct song_node * dw = NULL;
    //testing linkedsongs.c
    printf("Testing linkedsongs.c\n");
    printf("\n==================================\n");
    printf("\nTesting print_list:\n\n");

    // scrambled
    dw = insert_front(dw, "pearl jam", "yellow ledbetter");
    dw = insert_front(dw, "radiohead", "paranoid android");
    dw = insert_front(dw, "radiohead", "street spirit (fade out)");
    dw = insert_front(dw, "ac/dc", "thunderstruck");
    dw = insert_front(dw, "pearl jam", "even flow");
    dw = insert_front(dw, "pink floyd", "time");
    dw = insert_front(dw, "pearl jam", "alive");

    // ordered
    // dw = insert_front(dw, "radiohead", "street spirit (fade out)");
    // dw = insert_front(dw, "radiohead", "paranoid android");
    // dw = insert_front(dw, "pink floyd", "time");
    // dw = insert_front(dw, "pearl jam", "yellow ledbetter");
    // dw = insert_front(dw, "pearl jam", "even flow");
    // dw = insert_front(dw, "pearl jam", "alive");
    // dw = insert_front(dw, "ac/dc", "thunderstruck");

    print_list(dw);

    printf("\n==================================\n");
    printf("\nTesting find_song and print_song:\n\n");
    print_song(find_song(dw, "pearl jam", "even flow"));
    print_song(find_song(dw, "yeet", "delete"));

    printf("\n==================================\n");
    printf("\nTesting compare_song and order_list:\n\n");
    // printf("%d\n",compare_songs(dw, dw->next));
    printf("original: \n");
    print_list(dw);
        // swap(dw, dw->next);
        // print_list(dw);
    dw = order_list(dw);
    printf("\nnew: \n");
    print_list(dw);

    printf("\n==================================\n");
    printf("\nTesting find_artist\n\n");
    print_list(find_artist(dw,"pearl jam"));
    print_list(find_artist(dw,"toto"));

    printf("\n==================================\n");
    printf("\nTesting random_song\n\n");
    print_song(random_song(dw));
    print_song(random_song(dw));
    print_song(random_song(dw));
    print_song(random_song(dw));
    print_song(random_song(dw));

    printf("\n==================================\n");
    printf("\nTesting remove_song\n\n");
    print_list(dw);
    print_song(remove_song(dw,"pink floyd", "time"));
    printf("Removing [pink floyd,time]\n");
    print_list(dw);

    printf("\n==================================\n");
    printf("\nTesting free_list\n\n");
    printf("original: \n");
    print_list(dw);
    dw = free_list(dw);
    printf("\nnew: \n");
    print_list(dw);

    // testing library

    printf("\n==================================\n");
    printf("\nTesting library.c\n");
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

    //random entries    
    dwlib = add_song(dwlib, "...","testing");
    // dwlib = add_song(dwlib, "yam", "alive");
    // dwlib = add_song(dwlib, "spam", "open");
    // dwlib = add_song(dwlib, "doggo", "bork");
    // dwlib = add_song(dwlib, "cat", "meow");
    // dwlib = add_song(dwlib, "chatty jam", "dead");
    // dwlib = add_song(dwlib, "osu jam", "clicking circles");
    // dwlib = add_song(dwlib, "tornato", "sauce");
    // dwlib = add_song(dwlib, "queen", "rap");

    print_lib(dwlib);
    
    printf("\n==================================\n");
    printf("\nTesting find_songlib\n\n");
    print_song(find_songlib(dwlib,"radiohead","paranoid android"));
    print_song(find_songlib(dwlib,"tornados","brrr"));

    printf("\n==================================\n");
    printf("\nTesting find_artist, print_artist\n\n");
    print_song(find_artistlib(dwlib,"pearl jam"));
    print_song(find_artistlib(dwlib,"jam"));

    printf("\n==================================\n");
    printf("\nTesting print_letter\n\n");
    print_letter(dwlib,'p');
    print_letter(dwlib,'[');

    printf("\n==================================\n");
    printf("\nTesting print_artist\n\n");
    print_artist(dwlib, "pearl jam");
    print_artist(dwlib, "jam");

    printf("\n==================================\n");
    printf("\nTesting shuffle\n\n");
    print_list(shuffle(dwlib,5));
    print_list(shuffle(dwlib,6));
    print_list(shuffle(dwlib,3));
    print_list(shuffle(dwlib,8));

    printf("\n==================================\n");
    printf("\nTesting delete song\n\n");
    dwlib = delete_song(dwlib, "pearl jam","even flow");
    print_lib(dwlib);
    dwlib = delete_song(dwlib, "yaur","mp");
    print_lib(dwlib);
    
    printf("\n==================================\n");
    printf("\nTesting free_lib\n\n");
    dwlib = free_lib(dwlib);
    print_lib(dwlib);

    return 0;
}

struct song_node ** make_lib() {
    struct song_node ** temp = calloc(27,sizeof(struct song_node *));
    return temp;
}

struct song_node ** add_song(struct song_node ** lib, char a[100], char s[100]) {
    // Uppercase Letters − A - Z having ASCII values from 65 - 90 where, 65 and 90 are inclusive.
    // Lowercase Letter − a - z having ASCII values from 97 - 122 where, 97 and 122 are inclusive.
    if (a[0] >= 97 && a[0] <= 122) {
        struct song_node * temp = lib[a[0]%97];
        temp = insert_front(temp, a, s);
        temp = order_list(temp);
        // printf("%c %d\n",a[0]%97,a[0]%97);
        // print_list(temp);
        lib[a[0]%97] = temp;
    } else {
        struct song_node * temp = lib[26];
        temp = insert_front(temp, a, s);
        temp = order_list(temp);
        // printf("%c %d\n",a[0]%97,a[0]%97);
        // print_list(temp);
        lib[26] = temp;
    }
    return lib;
}

struct song_node * find_songlib(struct song_node ** lib, char a[100], char s[100]) {
    return find_song(lib[a[0]%97],a,s);
}

struct song_node * find_artistlib(struct song_node ** lib, char a[100]) {
    // struct song_node * temp = find_artist(lib[a[0]%97],a);
    return find_artist(lib[a[0]%97],a);
}

void print_lib(struct song_node ** lib) {
    struct song_node ** temp = lib;
    struct song_node * tempsong;
    int i;
    for (i = 0; i < 27 && lib; i++) {
        tempsong = lib[i];
        if (i != 26) {
            printf("%c\n",65+i);
        } else {
            printf("Other:\n");
        }
        print_list(tempsong);
    }
}

void print_letter(struct song_node ** lib, char c) {
    print_list(lib[c%97]);
}

void print_artist(struct song_node ** lib, char a[100]) {
    struct song_node * temp = find_artistlib(lib, a);
    while (temp && strcmp(temp -> artist,a)==0) {
        printf("{%s, %s} | ", temp -> artist, temp -> name);
        temp = temp -> next; 
    }
    printf("\n");
}

struct song_node * shuffle(struct song_node ** lib, int numSongs) {
    struct song_node * queue = NULL;
    srand(time(NULL));
    while(numSongs) {
        // printf("Songs that need to be added: %d\n", numSongs);
        int r = rand()%27;
        // printf("%d\n",r);
        if (lib[r]){
            // printf("List we're picking from: %d\n", r);
            // print_list(lib[r]);
            struct song_node * temp = random_song(lib[r]);
            // printf("Adding: %s by %s\n", temp->artist, temp->name);
            queue = insert_front(queue, temp -> artist, temp -> name);
        } else {
            numSongs++;
        }
        numSongs--;
    } 
    return queue;
}

struct song_node ** delete_song(struct song_node ** lib, char a[100], char s[100]) {
    struct song_node * temp = lib[a[0]%97];
    temp = remove_song(temp,a,s);
    return lib;
}
struct song_node ** free_lib(struct song_node ** lib) {
    // struct song_node * temp;
    for (int i = 0; i < 27; i++) {
        free(lib[i]);
    }
    free(lib);
    lib = NULL;
    return lib;
}