# minitalk
Server - Client mini chat written on C, using only 2 signals (SIGUSR1 and SIGUSR2) to send a message.

Small data exchange program using UNIX signals

How to run?
make all
Open 2 terminals and run

Terminal 1: ./server

Terminal 2: ./client <PID> <string message that you want to send>
