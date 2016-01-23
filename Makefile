INC_DIR=/home/arembedded/func_mq_example

SRC_FILES=thread2_inf.c \
          thread2.c \
          thread1.c \
          $(INC_DIR)/util/util.c \
          main.c 

app: $(SRC_FILES)
	gcc $(SRC_FILES) -I$(INC_DIR) -lpthread -lrt -o app.o

all: app

clean:
	rm -rf *.o	
