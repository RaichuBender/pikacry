pika:	extract_cry.o main.o play_cry.o
	$(CC) $^ -lportaudio -o $@
