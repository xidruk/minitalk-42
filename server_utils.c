#include "g_header.h"

extern t_server *server_struct;

t_server *gen_server_struct(void)
{
    t_server *ss = malloc(sizeof(t_server));
    if (!ss)
    {
        print_error("Error: Failed to allocate the server struct.\n");
        exit(1);
    }
    return (ss);
}

void init_server_struct(t_server *server_struct)
{
    if (!server_struct)
    {
        print_error("Error: The given server struct is NULL.\n");
        exit(1);
    }
    server_struct->received_data = malloc(1024 * sizeof(char));
    if (!server_struct->received_data)
    {
        print_error("Error: Failed to allocate the receive buffer.\n");
        exit(1);
    }
    server_struct->current_state = 0;
    server_struct->final_sgs = 0;
    server_struct->r_data_size = 0;
    server_struct->client_proc_id = 0;
    server_struct->death_state = 0;
}

void clean_up_server(t_server *server_struct)
{
    if (!server_struct)
    {
        print_error("Error: The given server struct is NULL.\n");
        exit(1);
    }
    free(server_struct->received_data);
    server_struct->received_data = NULL;
    server_struct->current_state = 0;
    server_struct->final_sgs = 0;
    server_struct->r_data_size = 0;
    server_struct->client_proc_id = 0;
    server_struct->death_state = 0;
}

int check_proces_id(t_server *server_struc, int new_proc_id)
{
    return (server_struc->client_proc_id == new_proc_id);
}

void save_bytes(t_server *server_struct, unsigned char byte)
{
    if (server_struct->r_data_size >= 1024)
    {
        printf("Error: Buffer overflow!\n");
        exit(1);
    }
    server_struct->received_data[server_struct->r_data_size] = byte;
    server_struct->r_data_size++;
    server_struct->received_data[server_struct->r_data_size] = '\0';
    printf("Received byte: %c\n", byte);
}

void process_received_bit(t_server *server_struct, int bit)
{
    static unsigned char byte = 0;
    static int bit_count = 0;

    byte = (byte << 1) | (bit & 1);
    bit_count++;

    if (bit_count == 8)
    {
        if (byte == 0x00)  // Termination byte
        {
            print_data("Termination byte received. Closing connection.");
            server_struct->death_state = 1;
            server_struct->final_sgs = 1;
        }
        else
        {
            save_bytes(server_struct, byte);
        }
        bit_count = 0;
        byte = 0;
    }
}

void handle_signal(int signal, siginfo_t *info, void *context)
{
    (void)context;
    int bit;

    if (signal == SIGUSR2)
        bit = 1;
    else if (signal == SIGUSR1)
        bit = 0;
    else
        return;

    // Reject signals from other clients during active connection
    if (server_struct->client_proc_id != 0 &&
        server_struct->client_proc_id != info->si_pid)
    {
        printf("Server: Ignoring signal from PID %d (active client: %d)\n",
              info->si_pid, server_struct->client_proc_id);
        return;
    }

    // New client connection
    if (server_struct->client_proc_id == 0)
    {
        server_struct->client_proc_id = info->si_pid;
        printf("Server: New client connected with PID %d\n", info->si_pid);
    }

    process_received_bit(server_struct, bit);

    // Send acknowledgment
    if (kill(info->si_pid, SIGUSR1) == -1)
    {
        printf("Server: Failed to ack PID %d\n", info->si_pid);
    }
}

void server_loop(t_server *server_struct)
{
    while (!server_struct->final_sgs)
        pause();
}

void restart_server_for_next_client(t_server *server_struct)
{
    printf("\nResetting server for next client...\n");
    clean_up_server(server_struct);
    init_server_struct(server_struct);
    printf("Ready for new connections!\n");
}
