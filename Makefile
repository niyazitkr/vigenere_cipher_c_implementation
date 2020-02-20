build:
	gcc -o exec_vc main.c vigenere_cipher.c -I . -fno-stack-protector

run:
	./exec_vc

clean:
	rm exec_vc