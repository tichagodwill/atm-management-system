#include "header.h"

#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <pthread.h>

// #define PORT 8080

// void * messageRecv(void * t) {
//     int sock, new_sock;
//     struct sockaddr_in server, client;
//     char buffer[50];

//     sock = socket(AF_INET, SOCK_STREAM, 0);

//     server.sin_family = AF_INET;
//     server.sin_addr.s_addr = INADDR_ANY;
//     server.sin_port = htons(PORT);

// // Bind
//     if ( bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
//         puts("\nbind failed\n");
//     } else {
//         puts("\nbind done");
//     }

// // Listen
//     listen(sock, 3);

//     puts("\nWaiting for incoming connections...\n");

//     socklen_t clilen = sizeof(client);
//     if ( new_sock = accept(sock, (struct sockaddr *)&client, &clilen) < 0) {
//         puts("\naccept failed\n");
//     } 
//     if ( recv(new_sock, buffer, strlen(buffer), 0) < 0) {
//         puts("recv failed");
//     }
//     printf("buffer is %s", buffer);

// }

void mainMenu(struct User u, int sysClear)
{
    int option;

    if (sysClear == 1) {
     system("clear");
    }
    char nick[100];
    printf("\n\n\t\t======= ATM =======\n\n");
    printf("\n\t\t-->> Feel free to choose one of the options below <<--\n");
    printf("\n\t\t[1]- Create a new account\n");
    printf("\n\t\t[2]- Update information of account\n");
    printf("\n\t\t[3]- Check accounts\n");
    printf("\n\t\t[4]- Check list of owned account\n");
    printf("\n\t\t[5]- Make Transaction\n");
    printf("\n\t\t[6]- Remove existing account\n");
    printf("\n\t\t[7]- Transfer ownership\n");
    printf("\n\t\t[8]- Exit\n");

    // pthread_t t;
    // pthread_create(&t, NULL, messageRecv, (void *)&t);

///////////////////////////////////////    
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        createNewAcc(u);
        break;
    case 2:
        // student TODO : add your **Update information of existing account** function
        // here
        updateAcc(u);
        break;
    case 3:
        // student TODO : add your **Check the details of existing accounts** function
        // here
        CheckAcc(u);
        break;
    case 4:
        checkAllAccounts(u);
    case 5:
        // student TODO : add your **Make transaction** function
        // here
        MakeTransaction(u);
        break;
    case 6:
        // student TODO : add your **Remove existing account** function
        // here
        RemoveAcc(u);
        break;
    case 7:
        // student TODO : add your **Transfer owner** function
        // here
        // same IDs problem
        TransferAcc(u);
        break;
    case 8:
        exit(1);
        break;
    default:
        printf("Invalid operation!\n");
    }
};

void initMenu(struct User *u)
{
    int r = 0;
    int option;
    system("clear");
    printf("\n\n\t\t======= ATM =======\n");
    printf("\n\t\t-->> Feel free to login / register :\n");
    printf("\n\t\t[1]- login\n");
    printf("\n\t\t[2]- register\n");
    printf("\n\t\t[3]- exit\n");
    while (!r)
    {
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            loginMenu(u->name, u->password);
            if (strcmp(u->password, getPassword(*u)) == 0)
            {
                printf("\n\nPassword Match!");
            }
            else
            {
                printf("\nWrong password!! or User Name\n");
                exit(1);
            }
            r = 1;
            break;
        case 2:
            // student TODO : add your **Registration** function
            // here
            registerMenu(u->name, u->password);
            r = 1;
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Insert a valid operation!\n");
            exit(1);
        }
    }
};

int main()
{

    struct User u;
    initMenu(&u);
    mainMenu(u, 1);
    return 0;
}