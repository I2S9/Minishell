#include "../includes/utilitaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Supprime le caractère '\n' en fin de ligne
void nettoyer_ligne(char *ligne) 
{
    size_t longueur = strlen(ligne);
    if (longueur > 0 && ligne[longueur - 1] == '\n') 
    {
        ligne[longueur - 1] = '\0';
    }
}

// Affiche un titre ASCII art personnalisé
void afficher_ascii_art() 
{
    // Coquillage artistique - rose clair
    printf("\033[38;5;217m");
    printf("           _.---._\n");
    printf("       .\"\".' /|\\ `.\"\".\n");
    printf("      :  .' / | \\ `.  :\n");
    printf("      '.'  /  |  \\  `.'\n");
    printf("       `. /   |   \\ .'\n");
    printf("    jgs  `-.__|__.-'\n");
    printf("\033[0m");

    // Titre MINISHELL couleur cyan
    printf("\033[1;36m"); 
    printf("\n");
    printf("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n");
    printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n");
    printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n");
    printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n");
    printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n");
    printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
    printf("\033[0m");

    // Encadrement informatif d'accueil
    printf("\033[1;34m");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║         Bienvenue dans le Minishell INES Galilée - Projet UNIX 🐧          ║\n");
    printf("║       Tapez une commande pour commencer — utilisez 'exit' pour quitter     ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\033[0m\n");
}

// Affiche un prompt coloré avec répertoire courant
void afficher_prompt() 
{
    char repertoire[1024];
    getcwd(repertoire, sizeof(repertoire));

    // léments du prompt (coquillage + couleur + chemin)
    printf("\033[1;36m"); 
    printf("🐚 ");
    printf("\033[1;34m"); 
    printf("[ines@minishell]");
    printf("\033[0;36m~%s$\033[0m ", repertoire); 
    fflush(stdout);
}