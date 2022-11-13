#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char name[255];
    int age;

} Contact;

void add_contact(int* index, Contact contacts[]) {
    if (contacts[*index].name == "" || contacts[*index].age == 0) {

        char name[255];
        int age = 0;

        printf("Enter in a name: ");

        scanf("%s", name);
        printf("Enter in an age: ");
        scanf("%d", &age);

        if (name != "" || age != 0) {

            if (name[0] >= 'a' && name[0] <= 'z') {
                name[0] = name[0] -32;
            }

            strcpy(contacts[*index].name, name);
            contacts[*index].age = age;

            *index = *index + 1;

            printf("Added contact: %s.\n", name);
        }

        else {
            /* Do nothing. */
        }
    }

    else {
        /* Do nothing. */
    }
}

void getAllContacts(Contact contacts[]) {
    for (int i = 0; contacts[i].age != 0; i++) {
        if (contacts[i].name != "") {
            printf("%d: %s | Age : %d\n", i + 1, contacts[i].name, contacts[i].age);
        }
    }
}

void remove_contact(Contact contacts[], char contact[999], int* index) {
    for (int i = 0; contacts[i].age != 0; i++) {
        if (strcmp(contacts[i].name, contact) == 0) {
            *index--;
            strcpy(contacts[i].name, "");

            contacts[i].age = 0;

            printf("Removed contact: %s\n", contact);
            break;
        }
        
        else {
            printf("Cannot find contact: %s\n", contact);
        }
    }
}