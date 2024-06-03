# MINITALK

**minitalk** is a 42 project which entails creating a small client-server data exchange program with UNIX signals.



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

In one terminal:
```
./server
```

In another terminal:
```
./client <server_PID> <string__to_send>
```

## My Approach:

1. 
