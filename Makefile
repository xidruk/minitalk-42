NAME = mulib.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror

CLIENT_UTILS_SRCS = \
	client_utils/client_get_data_size.c \
	client_utils/client_init_s.c \
	client_utils/client_cleaner.c \
	client_utils/client_marker.c \
	client_utils/client_send_data.c \
	client_utils/client_send_death_signal.c

SERVER_UTILS_SRCS = \
	server_utils/init_server_struct.c \
	server_utils/clean_server_struct.c \
	server_utils/r_and_s_bytes.c \
	server_utils/handle_signal.c \
	server_utils/loop_server.c \
	server_utils/restart_server.c

SHARED_UTILS_SRCS = \
	shared_utils/print_intergers.c \
	shared_utils/swap_types.c \
	shared_utils/print_data.c \
	shared_utils/print_error.c \
	shared_utils/data_parser.c

OBJS = \
	$(CLIENT_UTILS_SRCS:.c=.o) \
	$(SERVER_UTILS_SRCS:.c=.o) \
	$(SHARED_UTILS_SRCS:.c=.o)

all: $(NAME) client server

$(NAME): $(OBJS)
	ar rcs $@ $^

client: client.o $(NAME)
	$(CC) $(CFLAGS) -o $@ $< $(NAME)

server: server.o $(NAME)
	$(CC) $(CFLAGS) -o $@ $< $(NAME)

%.o: %.c g_header.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) client.o server.o

fclean: clean
	rm -f $(NAME) client server

re: fclean all
