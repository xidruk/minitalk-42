#include "g_header.h"

volatile sig_atomic_t g_ack_received = 0;

void handle_ack(int signal)
{
    if (signal == SIGUSR1)
	{
        g_ack_received = 1;
		print_data("Client : Received Acknowledgement from the server ... ");
	}
}

int main(int argc, char **argv)
{
    if (!pars_data(argc, argv))
    {
        printf("Error: Invalid arguments\n");
        exit(1);
    }

    int proc_id = atoi(argv[1]);
    char *data = argv[2];

    // Set up signal handler for acknowledgments
    struct sigaction sa;
    sa.sa_handler = handle_ack;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);

    t_client *client_struct = gen_client_struct();
    init_client_struct(client_struct, proc_id, data);
	print_data("Init the client struct ...");
    send_data(client_struct);
	print_data("send data to the server ...");
    if (mark_file_signal(client_struct))
    {
		print_data("Send death signal to the server ...");
        send_death_signal(proc_id);
        clean_client_struct(client_struct);
		print_data("clean up the client struct ...");
        printf("Data was sent successfully!\n");
    }
    else
    {
        printf("Data was not sent successfully. An error occurred.\n");
        exit(1);
    }

    free(client_struct);
    return (0);
}