CC = gcc
CFLAGS = -Wall -gc
TARGET = oss user
OBJS = oss.o user.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
oss.o: oss.c
	$(CC) $(CFLAGS) -c oss.o

user.o: user.c
	$(CC) $(CFLAGS) -c user.o

clean:
	rm -f $(TARGET) $(OBJS)
