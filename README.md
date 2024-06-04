# MINITALK

**minitalk** is a 42 project which entails creating a small client-server data exchange program with UNIX signals.

## Grade: 113%

## The Brief:

• Executable files: 'client' & 'server'

• Create communication program between 'client' and 'server'

• Client must take parameters: (1) Server PID, (2) String to send

• Can only use signals: (1) SIGUSR1, (2) SIGUSR2

• Client must send string (param) to server

• Server must print this string... quickly

• One global variable allowed

• Written in C

• Norminette compliant

• No seg fault/bus error/double free etc.


## Run Program:

Create executables:
```
make
```

Run server in one terminal:
```
./server
```

Run client in another terminal:
```
./client <server_PID> <string__to_send>
```

## Principal Method:

1.  Client converts the inputted characters to bits, sending them to the server using SIGUSR1 if bit is a 1, or SIGUSR2 if bit is 0, for 8 bits (equiv. to char)
2.  Server receives signals, storing the bits in variagle 'g_store' until until 8 bits been received. This is then printed in the output in the server's main function.

---
<p align="center">
Made by NicoleLehmeyer: nlehmeye@student.42adel.org.au | LinkedIn: <a href="https://www.linkedin.com/in/nicole-lehmeyer/">nicole-lehmeyer</a> | Discord: <a href="https://discordapp.com/users/1107446949344448543/">nicole.lehmeyer</a>
</p>

<p align="center">
  <img src="https://github.com/NicoleLehmeyer/NicoleLehmeyer/blob/main/images/coder_hampster.png" alt="hampster" style="width:100px;"/>
</p>
