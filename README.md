# MINITALK

<p>
<b><a href="https://github.com/NicoleLehmeyer/MINITALK/blob/main/subject/MINITALK_SUBJECT.pdf">'minitalk'</a></b> is a 42 project which entails creating a small client-server data exchange program with UNIX signals.<br><br>
<b>minitalk Grade: 113%</b>
<br>
<br>
<br>
<br>
<br>
<b>Requirements:</b><br><br>
  The communication program must consist of executable files, 'client' & 'server.'<br><br>
  'Client' must take 2 parameters - 'Server PID' & 'String to send'.<br><br>
  You may only use 2 signals - SIGUSR1 & SIGUSR2.<br><br>
  The client must send the string to the server, and the server must print this string... quickly.<br><br>
  Use of one global variable is allowed. Program must be written in C and <a href="https://github.com/NicoleLehmeyer/LIBFT/blob/main/subject/norme.pdf">Norminette</a> (42 organisational syntax) compliant, without seg fault/bus error/double free etc.<br><br>
</p>



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
