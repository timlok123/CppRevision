/*
    This program does the simple MPI programing. 
    You can input your name and all the processes 
    would say "Hello" to you ! 
*/
#include <iostream>
#include <string>
#include <mpi.h>

int main(int argc, char* argv[])
{
    // Initialize the MPI 
    
    MPI::Init(argc, argv);
    // ====================== The code should be writtern in between MPI::Init & MPI::Finalize ====================== 

    int numOfProcess = MPI::COMM_WORLD.Get_size();
    int rank = MPI::COMM_WORLD.Get_rank();

    std::string name;
    if (rank == 0)
    {
        std::cout << "Hello. What is your name? "; 
        std::cin >> name;
    }

    // Broadcast the name to all other processes 
    // i. Broadcast the size of the namestring 
    //    (address of variables you wanna boardcast, size of variables, types, rank of the process)
    int nameSize = name.size();
    MPI::COMM_WORLD.Bcast(&nameSize, 1, MPI::INT, 0);

    // ii. Broadcast the string 
    if (rank != 0) // adjust the size of string in other rank 
    {
        name.resize(nameSize);
    }
    
    // Broadcast the name string
    MPI::COMM_WORLD.Bcast(&name[0], nameSize, MPI::CHAR, 0);

    std::cout << "Hello " << name << " from process " << rank 
              << " .There are total " << numOfProcess << " process(es) ." 
              << std::endl; 

    // ============================================================================================================== 
    MPI::Finalize();

    return 0; 
}