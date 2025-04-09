#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "utilitaires.h"

/* Taille maximale d'une ligne de commande */
#define TAILLE_LIGNE 1024
#define TAILLE_MAX_ARGS 64

/* Fonctions liées aux built-ins */
int est_builtin(char *commande);
int executer_builtin(char **arguments);
int cmd_cd(char **args);
int cmd_pwd();
int cmd_echo(char **args);
int cmd_exit();
int gerer_variable(char *ligne);        /* Ajouté pour éviter warning */
char* recuperer_variable(char *nom);

#endif