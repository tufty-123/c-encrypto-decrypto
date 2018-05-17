# c-encrypto-decrypto

## What it is?
It is a basic encryption decryption software written in C, which uses binary files to store encrypted data.

It is just a hobby project to understand basics of C.

## Contribution

1) Anyone can contribute to this project.

2) If you are a beginner in open-source , this is the best project to start with.

3) Some "Todos" are already marked, though you can add more.

## Setting up the project (Linux)

1. git clone this project using <code>$ git clone https://github.com/ujjwalrox/c-encrypto-decrypto.git</code>
2. Build the project using, <code>$ make cencrypto cdecrypto </code>
3. Now building of this project is complete, two executable files "cencrypto and cdecrypto" will show up.
4. make a random input file to test, namely "input.txt" and add some text to it.
5. run <code>$ ./cencrypto input.txt output.o</code> it will create a encrypted binary file name output.o
6. now to decrypt run, <code>$ ./cdecrypto output.o decrypted.txt</code> , now decrypted.txt will contain the original text.
