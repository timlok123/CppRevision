# Compiling flag cheatsheet

1. Normal 
`g++ -o HelloWorld HelloWorld.cpp`

2. Warn all the errors/ unexpected situation 
`g=+ -Wall -Werror -o HelloWorld HelloWorld.cpp`

3. Enable vectorization
`g++ -O2 -o HelloWorld HelloWorld.cpp`
    - You can use either -O3 or -O2 to enable vectorization 