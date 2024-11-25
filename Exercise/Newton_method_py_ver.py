import math
import time

def func(x):
    return math.exp(x) + x**3 - 5

def func_derivative(x):
    return math.exp(x) + 3 * x**2

def newton_method_for_loop(initial_guess, iteration):
    x_prev = initial_guess
    for _ in range(iteration):
        x_next = x_prev - func(x_prev) / func_derivative(x_prev)
        x_prev = x_next
    return x_next

# Example usage
initial_guess = 2
iteration = int(1e7)

start_time = time.time()
root = newton_method_for_loop(initial_guess, iteration)
end_time = time.time()

print(f"Root: {root:.15f}")
print(f"Time taken: {end_time - start_time:.6f} seconds")