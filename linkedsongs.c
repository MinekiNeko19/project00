#include "linkedsongs.h"

int main(){
    struct song_node * dw;
    printf("\nTesting print_list:\n"); // change some later to test capitalization
    dw = insert_front(dw, "radiohead", "street spirit (fade out)");
    dw = insert_front(dw, "radiohead", "paranoid android");
    dw = insert_front(dw, "pink floyd", "time");
    dw = insert_front(dw, "pearl jam", "yellow ledbetter");
    dw = insert_front(dw, "pearl jam", "alive");
    dw = insert_front(dw, "ac/dc", "thunderstruck");
    dw = insert_front(dw, "pearl jam", "even flow");
    print_list(dw);

    printf("\nTesting find_song and print_song:\n");
    print_song(find_song(dw, "pearl jam", "even flow"));
    print_song(find_song(dw, "yeet", "delete"));

    printf("\nTesting compare_song and order_list:\n");
    print_song(compare_songs(dw));
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

// struct song_node * order_list(struct song_node * list); // nvm we'll do the slow bubble sort
// struct song_node * compare_songs(struct song_node * s1, struct song_node * s2) { // helper, change later to take into account capitalization
//     struct song_node * temp;
//     char one[100];
//     char two[100];
//     strcpy(one, s1-> artist);
//     strcpy(two, s2 -> artist);

//     if (one[0] < two[0]) {
//         temp = s1;
//         s1 -> next = s2->next;
        
        
//     }
// }

struct song_node * compare_songs(struct song_node * s1) { // helper, change later for capitalization
    struct song_node * s2 = s1 -> next;
    struct song_node * temp;
    char one[100];
    char two[100];
    strcpy(one, s1-> artist);
    strcpy(two, s2 -> artist);

    if (strcmp(one, two)) { // prev s1 s2 -> prev s2 s1
        temp = s1;
        strcpy(temp -> artist, s1 -> artist);
        strcpy(temp -> name, s1 -> name);
        temp -> next = s1 -> next;
        strcpy(s1 -> artist, s2 -> artist);
        strcpy(s1 -> name, s2 -> name);
        s1 -> next = s2 -> next;
        strcpy(s2 -> artist, temp -> artist);
        strcpy(s2 -> name, temp -> name);
        s2 -> next = temp -> next;
    }
    return s1 -> next;
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