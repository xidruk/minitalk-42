Minitalk 📡
Inter-Process Communication (IPC) using UNIX Signals

Overview 🚀
This project implements a client-server communication system using UNIX signals (SIGUSR1 and SIGUSR2). The client sends messages to the server bit-by-bit, and the server reconstructs and displays the received string. This project is part of the 42 curriculum and focuses on low-level signal handling, synchronization, and binary data transmission.

Features ✨
Mandatory Part
Server:

Displays its PID on startup.

Listens for signals from clients and reconstructs messages.

Handles multiple clients sequentially.

Prints received strings quickly (no noticeable delay).

Client:

Sends a string to the server using its PID.

Converts each character to 8 bits (sent as SIGUSR1 = 0, SIGUSR2 = 1).

Synchronizes with the server using signal acknowledgment.

Bonus Part ✅
Server Acknowledgment:

Server sends a confirmation signal (SIGUSR1) back to the client after receiving each bit.

Unicode Support:

Extended support for multi-byte Unicode characters (e.g., emojis, non-ASCII).

Installation & Usage 🛠️
Compilation
bash
Copy
make        # Compiles mandatory parts (client and server)  
make bonus  # Compiles bonus features (if implemented)  
Run
Start the server:

bash
Copy
./server  
The server will print its PID (e.g., PID: 12345).

Send a message via the client:

bash
Copy
./client 12345 "Hello, 42!"  
Technical Details 🔧
Signal Handling
Signals Used: SIGUSR1 (bit 0), SIGUSR2 (bit 1).

Bitwise Encoding: Each character is split into 8 bits (LSB-first or MSB-first).

Synchronization: Client waits for server acknowledgment after each bit to prevent signal loss.

Allowed Functions
write, signal, sigaction, kill, getpid, malloc, free, pause, usleep, etc.

Global Variables: Limited to one per program (client/server).

Challenges Addressed
Signal Queuing: Linux does not queue signals of the same type. Solutions involve synchronization and delays.

Speed: Server must process ~100 characters per second.

Memory Management: Zero leaks, robust error handling.

Resources 📚
Key Concepts
UNIX Signals:

Signal Handling in C (GeeksforGeeks)

sigaction vs. signal: sigaction Tutorial

Bitwise Operations:

Bit Manipulation in C (Wikipedia)

Unicode Encoding:

UTF-8 Explained (Joel on Software)

Debugging & Testing
Use printf (or ft_printf) to log signal steps.

Test edge cases: empty strings, special characters (\0, \n), long messages.

FAQ ❓
Q: Why does my client freeze after sending a message?
A: Ensure the server acknowledges each bit. Use usleep sparingly to avoid race conditions.

Q: How to handle Unicode in the bonus?
A: Encode characters in UTF-8 and split them into multiple bytes (each byte = 8 bits).

Q: Can I use sleep or usleep?
A: Yes, but minimize delays to meet the "quickly" requirement.

License
This project is part of the 42 curriculum. Code by [xidruk].
