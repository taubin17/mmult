TARGET=MMult
OBJS= main.o dimensions.o matparse.o mmult.o
CFLAGS=-g

ALL: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS) core*
