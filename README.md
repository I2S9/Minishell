# 🐚 Projet Minishell

Bienvenue dans le **MiniShell**, un shell minimaliste conçu dans le cadre du cours de **systèmes d'exploitation**.

## 📋 Objectif du projet

Créer un shell simple capable de :
- Lire et exécuter des commandes UNIX standards
- Gérer les **arguments**, les **processus en arrière-plan** (&)
- Implémenter des **commandes internes** comme `cd`, `pwd`, `echo`, `exit`
- Gérer de manière simple les **variables utilisateur** (ex: `nom=valeur`, `$nom`)
- Proposer un affichage **personnalisé** (ASCII, couleurs)

## ⚙️ Structure du projet

minishell/
├── includes/
│   ├── minishell.h
│   └── utilitaires.h
├── src/
│   ├── minishell.c
│   ├── builtins.c
│   └── utilitaires.c
├── Makefile
└── README.md

## 🛠️ Compilation

```bash
make
./minishell