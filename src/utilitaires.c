#include "../includes/utilitaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Supprime le caractere '\n' en fin de ligne */
void nettoyer_ligne(char *ligne) 
{
    size_t longueur = strlen(ligne);
    if (longueur > 0 && ligne[longueur - 1] == '\n') 
    {
        ligne[longueur - 1] = '\0';
    }
}

/* Affiche un logo ASCII personnalise */
void afficher_ascii_art() 
{
    /* Icône coquillage (source : https://ascii.co.uk/art/seashell) */
    printf("\033[38;5;217m"); /* Couleur rose pâle */

    /* Ligne par ligne des 3 coquillages alignés */
    printf("         /\\                        _.---._                       /\\\n");
    printf("        {.-}                   .\"\".' /|\\ `.\"\".                  {.-}\n");
    printf("       ;_.-'\\                 :  .' / | \\ `.  :                ;_.-'\\\n");
    printf("      {    _.}_               '.'  /  |  \\  `.'               {    _.}_\n");
    printf("       \\.-' /  `,              `. /   |   \\ .'                 \\.-' /  `,\n");
    printf("        \\  |    /                `-.__|__.-'                    \\  |    /\n");
    printf("         \\ |  ,/                                                 \\ |  ,/\n");
    printf("          \\|_/                                                    \\|_/\n");

    printf("\033[0m"); /* Reset couleurs */


    /* Titre MINISHELL en bleu cyan */
    printf("\033[1;36m");
    printf("\n");
    printf("        ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n");
    printf("        ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n");
    printf("        ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n");
    printf("        ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n");
    printf("        ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n");
    printf("        ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
    printf("\033[0m");

    /* Encadrement informatif d'accueil du Minishell */
    printf("\033[1;34m");
    printf("╔════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                ║\n");
    printf("║             Bienvenue dans le Minishell INES Galilee – Projet UNIX             ║\n");
    printf("║                                                                                ║\n");
    printf("║         Tapez une commande pour commencer | utilisez 'exit' pour quitter       ║\n");
    printf("║                                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\033[0m\n");

}

/* Affiche un prompt colore avec repertoire courant */
void afficher_prompt() 
{
    char repertoire[1024];
    getcwd(repertoire, sizeof(repertoire));

    printf("\033[1;36m");
    printf("🐚 ");
    printf("\033[1;34m");
    printf("[ines@minishell]");
    printf("\033[0;36m~%s$\033[0m ", repertoire);
    fflush(stdout);
}

/* Affiche un message d'erreur en rouge */
void erreur(const char *msg) 
{
    fprintf(stderr, "\033[1;31mErreur : %s\033[0m\n", msg);
}

/* Verifie si la ligne contient uniquement des espaces ou des tabulations */
int ligne_est_vide(const char *ligne) 
{
    while (*ligne) {
        if (*ligne != ' ' && *ligne != '\t') 
        {
            return 0;
        }
        ligne++;
    }
    return 1;
}