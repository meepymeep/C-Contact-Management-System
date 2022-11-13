#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char name[255];
    int age;

} Contact;
/*
    This structure is used to make an array of contacts, if you were wondering.
*/

void add_contact(int* index, Contact contacts[]) {
    if (contacts[*index].name == "" || contacts[*index].age == 0) {

        /*
            What the if statement is checking for is:
            "If the contact at index {whatever index is} has no name, or it's age is set to 0,
            execute code below."
        */

        char name[255];
        int age = 0;

        printf("Enter in a name: ");

        scanf("%s", name);
        printf("Enter in an age: ");
        scanf("%d", &age);

        /* 
            Pretty basic code up there, you just enter in a name and an age.    
        */

        if (name != "" || age != 0) {

            if (name[0] >= 'a' && name[0] <= 'z') {
                name[0] = name[0] -32;

                /* For whatever reason, I felt like making the first letter
                uppercase in the name was pretty cool. */
            }

            strcpy(contacts[*index].name, name); /* This line just changes the contact name
            at whatever index, to the name we gave. */
            contacts[*index].age = age;
            /* Same for age. */
            *index = *index + 1;
            /*
                Then we wanna increment index by one, so that way we can't accidently change
                the name or age of the same contact, unless we delete a contact ahead of it.
            */

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
    /* Pretty simple solution here, basically:
        "For every contact in contacts, if contact at index {i} has an age of 0,
        and if their name isn't empty, print their name, otherwise don't."
    */
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
            /*
                If we can find the name entered in, we decrement the index.
                Meaning that contact doesn't exist anymore.
            */

            strcpy(contacts[i].name, "");

            contacts[i].age = 0;
            /* Then we remove the age and name, which is a way of deleting it. */

            printf("Removed contact: %s\n", contact);
            break;
        }
        
        else {
            printf("Cannot find contact: %s\n", contact);
        }
    }
}
