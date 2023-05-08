#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTICIPANTS 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PRIZE_LENGTH 100

struct Participant {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char prize[MAX_PRIZE_LENGTH];
};

struct Participant participants[MAX_PARTICIPANTS];
int numParticipants = 0;

void addParticipant() {
    if (numParticipants == MAX_PARTICIPANTS) {
        printf("Maximum number of participants reached.\n");
        return;
    }   

    struct Participant newParticipant;

    printf("Enter name: ");
    scanf("%s", newParticipant.name);

    printf("Enter email: ");
    scanf("%s", newParticipant.email);

    printf("Enter prize: ");
    scanf("%s", newParticipant.prize);

    participants[numParticipants] = newParticipant;
    numParticipants++;

    printf("Participant added successfully.\n");
}

void listParticipants() {
    printf("Participants:\n");

    for (int i = 0; i < numParticipants; i++) {
        printf("%d. Name: %s, Email: %s, Prize: %s\n", i + 1, participants[i].name, participants[i].email, participants[i].prize);
    }
}

void chooseWinner() {
    if (numParticipants == 0) {
        printf("There are no participants to choose from.\n");
        return;
    }

    int randomIndex = rand() % numParticipants;
    printf("The winner is: %s (%s) who won and the ticket number is%s!\n", participants[randomIndex].name, participants[randomIndex].email, participants[randomIndex].prize);
}

int main() {
    int choice;

    do {
        printf("\nGiveaway Management System\n");
        printf("1. Add participant\n");
        printf("2. List participants\n");
        printf("3. Choose winner\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addParticipant();
                break;
            case 2:
                listParticipants();
                break;
            case 3:
                chooseWinner();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
