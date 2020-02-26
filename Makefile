TARGET=MMult
OBJS= main.o mmult.o
CFLAGS= -Wall

ALL: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS) core*
