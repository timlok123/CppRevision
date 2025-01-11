#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[])
{
    // Initialize the MPI 
    
    MPI::Init(argc, argv);
    // ====================== The code should be writtern in between MPI::Init & MPI::Finalize ====================== 

    int numOfProcess = MPI::COMM_WORLD.Get_size();
    int rank = MPI::COMM_WORLD.Get_rank();

    std::cout << "Hello World from process " << rank 
              << " .There are total " << numOfProcess << " process(es) ." 
              << std::endl; 

    // ============================================================================================================== 
    MPI::Finalize();

    return 0; 
}