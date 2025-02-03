#include "g_header.h"

t_server *server_struct = NULL;

void leaks_checker()
{
  system();
}

int main()
{
    print_data("Generate the server struct ....");
    server_struct = gen_server_struct();
    init_server_struct(server_struct);
    print_data("Init the server struct ...");

    // Set up signal handlers once
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO | SA_NODEFER;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("Server PID: %d\n", getpid());

    while (1)
    {
        server_loop(server_struct);
        if (server_struct->death_state)
            restart_server_for_next_client(server_struct);
    }

    clean_up_server(server_struct);
    print_data("Clean up the server ...");
    free(server_struct);
    return (0);
}
