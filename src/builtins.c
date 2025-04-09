#include "../includes/minishell.h"
#include <string.h>

/* Verifie si la commande est un builtin */
int est_builtin(char *commande) 
{
    return (strcmp(commande, "cd") == 0 ||
            strcmp(commande, "pwd") == 0 ||
            strcmp(commande, "echo") == 0 ||
            strcmp(commande, "exit") == 0);
}

/* Execute la commande builtin correspondante */
int executer_builtin(char **arguments) 
{
    if (strcmp(arguments[0], "cd") == 0) 
    {
        return cmd_cd(arguments);
    } 
    else if (strcmp(arguments[0], "pwd") == 0) 
    {
        return cmd_pwd();
    } 
    else if (strcmp(arguments[0], "echo") == 0) 
    {
        return cmd_echo(arguments);
    } 
    else if (strcmp(arguments[0], "exit") == 0) 
    {
        return cmd_exit();
    }
    return 0;
}

/* Change le repertoire courant */
int cmd_cd(char **args) 
{
    if (args[1] == NULL) 
    {
        erreur("Chemin manquant pour cd");
        return 1;
    }
    if (chdir(args[1]) != 0) 
    {
        erreur("Impossible de changer de repertoire");
    }
    return 1;
}

/* Affiche le repertoire courant */
int cmd_pwd() 
{
    char chemin[1024];
    if (getcwd(chemin, sizeof(chemin)) != NULL) 
    {
        printf("%s\n", chemin);
    } 
    else 
    {
        erreur("Impossible de recuperer le repertoire courant");
    }
    return 1;
}

/* Affiche les arguments (support de variables plus tard) */
int cmd_echo(char **args) 
{
    int i;

    for (i = 1; args[i]; i++) 
    {
        printf("%s ", args[i]);
    }
    printf("\n");
    return 1;
}

/* Quitte le shell */
int cmd_exit() 
{
    printf("Fermeture du minishell INES Galilee. A bientot !\n");
    exit(0);
}

/* Test pour l'instant temporaire */
int gerer_variable(char *ligne) 
{
    return 0;
}

/* pareil, test pour l'instant temporaire */
char* recuperer_variable(char *nom) 
{
    return NULL;
}