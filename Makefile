# Compilateur

CC = gcc

# Flags de compilation
# -Wall : affiche tous les warnings
# -Wextra : affiche des warnings supplémentaires
# -std=c89 : utilise le standard C89
# -pedantic : respecte strictement le standart C
CFLAGS = -Wall -Wextra -std=c89 -pedantic

# Répertoires des fichiers
INCLUDES = -Iincludes
SRC = src/minishell.c src/utilitaires.c src/builtins.c
OBJ = $(SRC:.c=.o)
EXEC = minishell

# Compile l'ensemble des fichiers
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Nettoyer les fichiers oblets (sans les exécutables)
clean:
	rm -f $(OBJ)

# Nettoyer tous les fichiers générés (exécutables inclus)
fclean: clean
	rm -f $(EXEC)

# Recompiler entièrement le projet
re: fclean all

.PHONY: all clean fclean re