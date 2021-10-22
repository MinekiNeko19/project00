#include "linkedsongs.h"

int main(){
    struct song_node * dw;
    printf("\nTesting print_list:\n"); // change some later to test capitalization

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

    printf("\nTesting find_song and print_song:\n");
    print_song(find_song(dw, "pearl jam", "even flow"));
    print_song(find_song(dw, "yeet", "delete"));

    printf("\nTesting compare_song and order_list:\n");
    printf("%d\n",compare_songs(dw, dw->next));
    print_list(dw);
        // swap(dw, dw->next);
        // print_list(dw);
    dw = order_list(dw);
    print_list(dw);
    
    return 0;
}

void print_list(struct song_node * list) {
    struct song_node * temp = list;
    while(temp) {
        printf("{%s, %s} | ", temp -> artist, temp -> name);
        temp = temp -> next; 
    }
    printf("\n");
}

struct song_node * insert_front(struct song_node * list, char a[100], char s[100]) {
    struct song_node * temp = malloc(sizeof(struct song_node));
    strcpy(temp -> artist, a);
    strcpy(temp -> name, s);
    temp -> next = list;
    list = temp;
    return list;
}

struct song_node * order_list(struct song_node * list){
    struct song_node * temp = list;
    int errors = 1;
    while (errors) {
        errors = 0;
        while (temp->next) {
            if(compare_songs(temp,temp->next)) {
                swap(temp, temp->next);
                print_list(list);
                errors++;
            }
            temp = temp -> next;
        }
        temp = list;
    }
    return list;
}

int compare_songs(struct song_node * s1, struct song_node * s2) { // helper, change later for capitalization
    if (strcmp(s1 -> artist, s2->artist) < 0) {
        return 0;
    }
    if (strcmp(s1 -> artist, s2->artist) == 0) {
        if (strcmp(s1 -> name, s2->name) < 0) {
            return 0;
        }
    }
    return 1;
}

void swap(struct song_node * s1, struct song_node * s2) { // helper
    printf("\nswapping %s and %s\n", s1->name, s2->name);
    char astore[100];
    char nstore[100];
    strcpy(astore,s1->artist);
    strcpy(nstore,s1->name);

    strcpy(s1->artist,s2->artist);
    strcpy(s1->name,s2->name);

    strcpy(s2->artist,astore);
    strcpy(s2->name,nstore);
}

void print_song(struct song_node * song) {
    if(song){
        printf("{%s, %s}\n", song -> artist, song -> name); 
    }
}

struct song_node * find_song(struct song_node * list, char a[100], char s[100]) {
    struct song_node * temp = list;
    while(temp) {
        if(!strcmp(temp -> artist,a) && !strcmp(temp -> name,s)) {
            // print_song(temp);
            return temp;
        }
        temp = temp->next;
    }
    printf("%s by %s not found!\n", a, s);
    return NULL;
}

// struct song_node * find_artist(struct song_node * list, char a[100]) { // do order list first before testing this
//     struct song_node * temp = list;
//     while (temp) {
//         if (!strcmp(temp -> artist,a)) {
//             return temp;
//         }
//         temp = temp -> next;
//     }
//     printf("%s by %s not found!\n", a, s);
//     return NULL;
// }