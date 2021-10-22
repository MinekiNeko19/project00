#include "library.h"

int main() {
    struct song_node * dw;
    // testing linkedsongs.c
    printf("\n==================================\n");
    printf("\nTesting print_list:\n");

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
    printf("\nTesting find_song and print_song:\n");
    print_song(find_song(dw, "pearl jam", "even flow"));
    print_song(find_song(dw, "yeet", "delete"));

    printf("\n==================================\n");
    printf("\nTesting compare_song and order_list:\n");
    // printf("%d\n",compare_songs(dw, dw->next));
    printf("original: \n");
    print_list(dw);
        // swap(dw, dw->next);
        // print_list(dw);
    dw = order_list(dw);
    printf("\nnew: \n");
    print_list(dw);

    printf("\n==================================\n");
    printf("\nTesting find_artist\n");
    print_list(find_artist(dw,"pearl jam"));
    print_list(find_artist(dw,"toto"));

    printf("\n==================================\n");
    printf("\nTesting random_song\n");
    print_song(random_song(dw));

    printf("\n==================================\n");
    printf("\nTesting remove_song\n");
    print_list(dw);
    print_song(remove_song(dw,"pink floyd", "time"));
    print_list(dw);

    printf("\n==================================\n");
    printf("\nTesting free_list\n");
    printf("original: \n");
    print_list(dw);
    dw = free_list(dw);
    printf("\nnew: \n");
    print_list(dw);
    
    return 0;
}