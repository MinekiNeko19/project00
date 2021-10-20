#include "linkedsongs.h"

void print_list(struct song_node * list) {
    struct song_node * temp = list;
    while(temp) {
        printf("%s: %s | ", temp -> artist, temp -> name);
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

int main(){
    struct song_node * vibe = NULL;
    printf("\nTesting print_list:\n");
    vibe = insert_front(vibe, "mokita", "colorblind");
    vibe = insert_front(vibe, "fun.", "we are young");
    vibe = insert_front(vibe, "Ed Sheeran", "Happier");
    print_list(vibe);
    
    return 0;
}