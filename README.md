# minitalk

Two small programs in C that talk to each other using only Unix signals. The client turns each character into bits and sends them one by one to the server, with `SIGUSR1` and `SIGUSR2`. The server puts the bits back together and prints the message. Accents and emoji work too.

## Run it

```bash
make
./server                  # prints its PID
./client <PID> "hello"    # in another terminal
```
