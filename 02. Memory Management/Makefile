CC=g++ -g

all: pointer_examples reference_examples memory_error dynamic_memory_example

pointer_examples: pointer_examples.cpp
	$(CC) pointer_examples.cpp -o pointer_examples

reference_examples: reference_examples.cpp
	$(CC) reference_examples.cpp -o reference_examples

memory_error: memory_error.cpp
	$(CC) memory_error.cpp -o memory_error

dynamic_memory_example: dynamic_memory_example.cpp
	$(CC) dynamic_memory_example.cpp -o dynamic_memory_example

clean:
	rm -f pointer_examples reference_examples memory_error dynamic_memory_example