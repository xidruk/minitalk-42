# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR_CLIENT = client_utils
SRCDIR_SERVER = server_utils
SRCDIR_SHARED = shared_tools
INCDIR = .
OBJDIR = obj

# Source files for the client executable
SRC_CLIENT = $(SRCDIR_CLIENT)/send_death_signal.c \
             $(SRCDIR_CLIENT)/client_struct_controller.c \
             $(SRCDIR_CLIENT)/client_struct_utils.c \
             $(SRCDIR_CLIENT)/data_parser.c \
             $(SRCDIR_CLIENT)/send_data.c \
             client.c

# Source files for the server executable
SRC_SERVER = $(SRCDIR_SERVER)/server_struct_utils.c \
             $(SRCDIR_SERVER)/struct_markers.c \
             $(SRCDIR_SERVER)/checkers.c \
             $(SRCDIR_SERVER)/collect_bits.c \
             $(SRCDIR_SERVER)/handle_signal.c \
             $(SRCDIR_SERVER)/server_looper.c \
             server.c

# Object files (map .c to .o in obj/ directory)
OBJ_CLIENT = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_CLIENT))
OBJ_SERVER = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC_SERVER))

# Header files (include global header and specific ones)
HEADERS = g_header.h \
          $(SRCDIR_CLIENT)/client_utils_h.h \
          $(SRCDIR_SERVER)/server_utils_h.h \
          $(SRCDIR_SHARED)/shared_tools.h

# Executable files
CLIENT_EXEC = client
SERVER_EXEC = server

# Default target (builds everything)
all: $(CLIENT_EXEC) $(SERVER_EXEC)

# Ensure the object directory exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile object files for client and server
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

# Compile client executable
$(CLIENT_EXEC): $(OBJ_CLIENT) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(CLIENT_EXEC) $(OBJ_CLIENT)

# Compile server executable
$(SERVER_EXEC): $(OBJ_SERVER) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(SERVER_EXEC) $(OBJ_SERVER)

# Clean up object files and executables
clean:
	rm -rf $(OBJDIR)

# Remove everything including the executables
fclean: clean
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC)

# Rebuild everything
re: fclean all

# Phony targets (not real files)
.PHONY: all clean fclean re
