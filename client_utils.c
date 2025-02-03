#include "g_header.h"

extern volatile sig_atomic_t g_ack_received;

int get_data_size(char *data)
{
    int len = 0;
    if (!data)
    {
        printf("Error: The given data is NULL.\n");
        exit(1);
    }
    while (data[len])
        len++;
    return (len);
}

t_client *gen_client_struct(void)
{
    t_client *cs = malloc(sizeof(t_client));
    if (!cs)
    {
        printf("Error: Failed to allocate the client struct.\n");
        exit(1);
    }
    return (cs);
}

void init_client_struct(t_client *client_struct, int proc_id, char *data)
{
    if (!client_struct)
    {
        printf("Error: The given client struct is NULL.\n");
        exit(1);
    }
    client_struct->data_to_send = data;
    client_struct->current_state = 0;
    client_struct->final_sgs = 0;
    client_struct->s_data_size = get_data_size(data);
    client_struct->server_proc_id = proc_id;
    client_struct->r_data_size = 0;
}

void clean_client_struct(t_client *client_struct)
{
    if (!client_struct)
    {
        printf("Error: The given client struct is NULL.\n");
        exit(1);
    }
    client_struct->data_to_send = NULL;
    client_struct->current_state = 0;
    client_struct->final_sgs = 0;
    client_struct->s_data_size = 0;
    client_struct->server_proc_id = 0;
    client_struct->r_data_size = 0;
}

int mark_file_signal(t_client *client_struct)
{
    if (!client_struct)
    {
        printf("Error: The given client struct is NULL.\n");
        exit(1);
    }
    if (client_struct->s_data_size == client_struct->r_data_size)
    {
        client_struct->final_sgs = 1;
        return (1);
    }
    return (0);
}

// client_utils.c
void send_bit(int proc_id, int bit)
{
    int timeout = 1000; // ~100ms timeout

    if (bit == 0)
    {
        print_data("Client: Sending bit [0]");
        if (kill(proc_id, SIGUSR1) == -1)
        {
            print_error("Client: Failed to send bit [0]");
            exit(1);
        }
    }
    else
    {
        print_data("Client: Sending bit [1]");
        if (kill(proc_id, SIGUSR2) == -1)
        {
            print_error("Client: Failed to send bit [1]");
            exit(1);
        }
    }

    // Wait for acknowledgment with timeout
    while (!g_ack_received && timeout-- > 0)
        usleep(100);

    if (!g_ack_received)
    {
        print_error("Client: Timeout waiting for acknowledgment");
        exit(1);
    }
    g_ack_received = 0;
}

void send_data(t_client *client_struct)
{
    unsigned char tmp;
    int bit_shifter;

    while (*client_struct->data_to_send)
    {
        tmp = *client_struct->data_to_send;
        bit_shifter = 7;
        while (bit_shifter >= 0)
        {
            send_bit(client_struct->server_proc_id, (tmp >> bit_shifter) & 1);
            bit_shifter--;
        }
        client_struct->s_data_size++;
        client_struct->data_to_send++;
    }
}

void send_death_signal(int proc_id)
{
    // Send a termination byte (0x00) to indicate end of transmission.
    unsigned char term_byte = 0x00;
    int bit_shifter = 7;

    while (bit_shifter >= 0)
    {
        send_bit(proc_id, (term_byte >> bit_shifter) & 1);
        bit_shifter--;
    }
}