#include "g_header.h"

t_server *server_struct = NULL;

int main()
{
    print_data("Generate the server struct ....");
    server_struct = gen_server_struct();
    init_server_struct(server_struct);
    print_data("Init the server struct ...");

    // Set up signal handlers once, outside the loop
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    // struct sigaction sa_death;
    // sa_death.sa_handler = handle_death_signal;
    // sa_death.sa_flags = 0;
    // sigaction(SIGUSR1, &sa_death, NULL);

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