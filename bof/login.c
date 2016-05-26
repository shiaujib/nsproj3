/*
 * bob.c
 *
 *  Created on: Apr 28, 2016
 *      Author: wdhongtw
 *      Email:  wdhongtw@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFFER_LEN 16
#define USER_ID "bob"
#define USER_PASSWD "asdf"
#define WELCOME_MSG     "Wellcome to the workstation.\nYou can press Control-D to exit. :D\n\n"
#define GOODBYE_MSG     "\nGood bye!!\n"
#define LOGIN_MSG       "[SUCCESS]\nWow... You have the password! :)\n"
#define LOGIN_FAIL_MSG  "[FAILURE] The username password pair seems not correct. :(\n"

void provide_shell(void) {
    system("/bin/sh");
}

void provide_train(void) {
    system("/usr/games/sl");
}

bool login(void) {
    char id[BUFFER_LEN];
    char passwd[BUFFER_LEN];

    fputs("username: ", stdout);
    if (gets(id) == NULL) return true;
    fputs("password: ", stdout);
    if (gets(passwd) == NULL) return true;

    if (strcmp(id, USER_ID) == 0 && strcmp(passwd, USER_PASSWD) == 0) {
        fputs(LOGIN_MSG, stdout);
        provide_train();
        return true;
    } else {
        fputs(LOGIN_FAIL_MSG, stdout);
        return true;
    }
}

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL); // disable buffering
    fputs(WELCOME_MSG, stdout);

    while (!login())
        continue;

    fputs(GOODBYE_MSG, stdout);
    return 0;
}
