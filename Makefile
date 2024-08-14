CC = gcc
CFLAGS = -Wall -Wextra -g

# Liste des fichiers source
SRCS = devoir.c hashcode.c freel-liste.c

# Liste des fichiers objets à générer
OBJS = $(SRCS:.c=.o)

# Cibles principales
all: devoir

# Règle de compilation pour les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de compilation pour le programme principal
devoir: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Nettoyer les fichiers objets et le programme principal
clean:
	rm -f $(OBJS) devoir

