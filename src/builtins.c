#include "../includes/minishell.h"
#include <string.h>

// Vérifie si la commande est un builtin
int est_builtin(char *commande) 
{
    return (strcmp(commande, "cd") == 0 ||
            strcmp(commande, "pwd") == 0 ||
            strcmp(commande, "echo") == 0 ||
            strcmp(commande, "exit") == 0);
}

// Exécute la commande builtin correspondante
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

// Change le répertoire courant
int cmd_cd(char **args) 
{
    if (args[1] == NULL) 
    {
        erreur("Chemin manquant pour cd");
        return 1;
    }
    if (chdir(args[1]) != 0) 
    {
        erreur("Impossible de changer de répertoire");
    }
    return 1;
}

// Affiche le répertoire courant
int cmd_pwd() {
    char chemin[1024];
    if (getcwd(chemin, sizeof(chemin)) != NULL) 
    {
        printf("%s\n", chemin);
    } 
    else 
    {
        erreur("Impossible de récupérer le répertoire courant");
    }
    return 1;
}

// Affiche les arguments passés (support de variables plus tard)
int cmd_echo(char **args) 
{
    for (int i = 1; args[i]; i++) 
    {
        printf("%s ", args[i]);
    }
    printf("\n");
    return 1;
}

// Quitte le shell
int cmd_exit() 
{
    printf("Fermeture du minishell INES Galilée. À bientôt !\n");
    exit(0);
}
