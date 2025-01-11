/*
    An example of simple MPI programming.
    Verify the result of the series, 

    Pi/ 4 =  Sum_{n=0}^{\infin} (-1)^n / (2n +1)  

    by comparing it with value of Pi. 

    Set infin to a large value M and assume M is divisible by number of processes. 
*/

#include <mpi.h>
#include <iostream>
#include <cmath>
#include <vector>

/*
int main()
{
    double sum = 0; 
    int max = 1e7; 

    MPI::Init();
    int rank         = MPI::COMM_WORLD.Get_rank();
    int numOfProcess = MPI::COMM_WORLD.Get_size();

    for (int i = rank; i < max; i += numOfProcess)
    {
        sum += std::pow(-1.0, i) / (2.0*(double)(i) + 1.0);
    }

    double globalSum;
    // (address of local var, address of global var, size of local var, 
    //  data type, Action (sum, min etc.), desiniation of rank)
    MPI::COMM_WORLD.Reduce(&sum, &globalSum, 1, MPI::DOUBLE, MPI::SUM, 0);

    if (rank == 0)
    {
        std::cout << "The estimated value of Pi : ";
        std::cout << globalSum*4 << " \n";
        std::cout << "It has absolute errors (compared with C++ constant values): ";
        std::cout << std::abs(globalSum*4 - M_PI) << " \n";

        std::cout << "Hello";
    }

    MPI::Finalize();

    return 0; 

}
*/

// Use a vector to store the values from different ranks 

int main()
{

    MPI::Init();
    int rank         = MPI::COMM_WORLD.Get_rank();
    int numOfProcess = MPI::COMM_WORLD.Get_size();

    double sum = 0; 
    int max = 1e8; 
    for (int i = rank; i < max; i += numOfProcess)
    {
        sum += std::pow(-1.0, i) / (2.0*(double)(i) + 1.0);
    }

    std::vector<double> allSums;
    if (rank == 0) {
        allSums.resize(numOfProcess);
    }

    // Gather the sum values from all processes to the root process
    MPI::COMM_WORLD.Gather(&sum, 1, MPI::DOUBLE, allSums.data(), 1, MPI::DOUBLE, 0);

    if (rank == 0)
    {
        double globalSum = 0;
        for (double s : allSums) {
            globalSum += s;
        }

        std::cout << "The estimated value of Pi : ";
        std::cout << globalSum*4 << " \n";
        std::cout << "It has absolute errors (compared with C++ constant values): ";
        std::cout << std::abs(globalSum*4 - M_PI) << " \n";
    }

    MPI::Finalize();
    return 0;
}


