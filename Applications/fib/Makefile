PROJECT_NAME:=fib
VERSION:=0.1

CC := arm-none-eabi-gcc
CFLAGS := -Wall -mcpu=cortex-m0plus -mthumb -Os -ffreestanding -fpie -nostdlib
CFLAGS += -fno-diagnostics-show-caret -fdata-sections -ffunction-sections -funsigned-char -funsigned-bitfields

OBJCOPY := arm-none-eabi-objcopy

LDFLAGS := -nostdlib -lgcc -fpie -ffreestanding -nostartfiles -mcpu=cortex-m0plus -mthumb -Wl,--gc-sections -Wl,--script=memmap_app.ld

OBJ:=main.o

.PHONY: build clean
build: app.bin
	@echo "Done building $(PROJECT_NAME)@$(VERSION)"

clean:
	rm -rf app.bin app.hex app $(OBJ) 

app.hex: app.bin
	hexdump -e '/1 "0x%02X" "\n"' app.bin >> app.hex

app.bin: app
	$(OBJCOPY) -O binary $< $@

app: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

