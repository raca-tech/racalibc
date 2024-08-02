SOURCES := $(shell find ./src -name "*.[Sc]")
OBJECTS := $(patsubst %, build/%.o, $(SOURCES))

C_FLAGS := -m64 -mcmodel=large -fno-stack-protector -fno-builtin -nostdinc -nostdlib -Iinclude
C_COMPILER_PREFIX ?= x86_64-elf-

all: $(OBJECTS)
	rm -rf libc.a
	$(C_COMPILER_PREFIX)ar rcs build/libc.a $(OBJECTS)

build/%.S.o: %.S
	@mkdir -p $(@D)
	$(C_COMPILER_PREFIX)gcc $(C_FLAGS) -c $< -o $@ -DASM_FILE

build/%.c.o: %.c
	@mkdir -p $(@D)
	$(C_COMPILER_PREFIX)gcc $(C_FLAGS) -c $< -o $@

clean:
	rm -rf build
