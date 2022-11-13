#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"

typedef enum {False = 0, True = !False} bool;
/* I didn't realize at the time "stdbool.h" existed, so I just made a 
custom bool keyword. */

/* This method below prints out the list of possible commands. */
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

        /*
            This if statement checks if there are any arguments,
            if so, the program exits out.
        */
    }

    bool running = True;
    /*
        This keeps the program running.
    */

    size_t i = 0;
    /* The reason "i" is up here, is because whenever I put it in the switch
    statement, it gave me an error, but I didn't put it in the loop
    for whatever reason. */

    Contact contacts[200];

    while (running) {

        listOfCmds();

        int cmd = 0;
        scanf("%i", &cmd);

        /* These two lines above are important for the switch statement a few lines
        below. */

        char name[255];
        /* Contact name variable above, very important. */

        switch (cmd) {

            case 1:
                add_contact(&i, contacts);
                /*
                    The first two case statements are very simple,
                    just call the methods with the required parameters, only one line
                    of code.
                */
            break;

            case 2:
                getAllContacts(contacts);
            break;
            
            case 3:
                printf("Enter in contact name: ");
                scanf("%s", name);

                /* This is still simple, you just gotta get input for the name. */

                remove_contact(contacts, name, &i);
                /* Then the line above just calls the "remove_contact" method
                from contact.h */
            break;

            case 4:
                running = False;
                /*
                    This line sets the running boolean to false.
                */
            break;

            default:
                printf("Enter in a valid command.\n");
                /*
                    If you don't enter in a valid command, this pops up.
                */
            break;
        }
    }

    return 0;
    
}