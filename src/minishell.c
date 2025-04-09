#include "../includes/minishell.h"

int main() {
    char ligne[TAILLE_LIGNE];
    char *arguments[TAILLE_MAX_ARGS];
    pid_t pid;
    int i;
    char *jeton;
    int arriere_plan;

    afficher_ascii_art();

    while (1) {
        afficher_prompt();

        /* Lire la commande */
        if (fgets(ligne, sizeof(ligne), stdin) == NULL) 
        {
            printf("\n");
            break;
        }

        nettoyer_ligne(ligne);

        if (ligne_est_vide(ligne)) 
        {
            continue;
        }

        if (gerer_variable(ligne)) 
        {
            continue;
        }

        /* Séparer les arguments */
        i = 0;
        jeton = strtok(ligne, " ");
        while (jeton != NULL && i < TAILLE_MAX_ARGS - 1) 
        {
            arguments[i++] = jeton;
            jeton = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        if (arguments[0] == NULL) 
        {
            continue;
        }

        /* Commande interne */
        if (est_builtin(arguments[0])) 
        {
            executer_builtin(arguments);
            continue;
        }

        arriere_plan = 0;
        if (i > 0 && strcmp(arguments[i - 1], "&") == 0) 
        {
            arriere_plan = 1;
            arguments[i - 1] = NULL;
        }

        pid = fork();
        if (pid == 0) 
        {
            /* Processus enfant */
            if (execvp(arguments[0], arguments) == -1) 
            {
                erreur("Commande introuvable");
                exit(EXIT_FAILURE);
            }
        } 
        else if (pid < 0) 
        {
            erreur("Échec du fork");
        } 
        else 
        {
            if (!arriere_plan) 
            {
                waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}