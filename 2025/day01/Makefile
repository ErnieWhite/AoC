CC = gcc
CFLAGS = -Wall -Wextra -O2

# Targets
TARGETS = part1 part2

# Default rule
all: $(TARGETS)

# Build part1 from part1.c
part1: 
	$(CC) $(CFLAGS) -o part1 part1.c

# Build part2 from part2.c
part2: 
	$(CC) $(CFLAGS) -o part2 part2.c

# Clean up build artifacts
clean:
	rm -f $(TARGETS)
