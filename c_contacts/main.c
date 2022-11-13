#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"

typedef enum {False = 0, True = !False} bool;

void listOfCmds() {

    printf("\t** Command List **\n\n");
    printf("1. add contact\n");
    printf("2. gets all contacts\n");
    printf("3. remove contacts\n\n");

}

int main(int argc, char* argv[]) {

    if (argc > 1) {
        printf("No args please.\n");
        exit(1);
    }

    bool running = True;

    size_t i = 0;

    Contact contacts[200];

    while (running) {

        listOfCmds();

        int cmd = 0;
        scanf("%i", &cmd);

        char name[255];

        switch (cmd) {

            case 1:
                add_contact(&i, contacts);
            break;

            case 2:
                getAllContacts(contacts);
            break;
            
            case 3:
                printf("Enter in contact name: ");
                scanf("%s", name);

                remove_contact(contacts, name, &i);
            break;

            case 4:
                running = False;
            break;

            default:
                printf("Enter in a valid command.\n");
            break;
        }
    }

    return 0;
    
}