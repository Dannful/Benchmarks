#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

int partition(std::vector<int>& numbers, const long int low, const long int high) {
    const int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (numbers[j] < pivot) {
            i++;
            std::swap(numbers[i], numbers[j]);
        }
    }
    std::swap(numbers[i + 1], numbers[high]);
    return i + 1;
}

void quicksort(std::vector<int>& numbers, const long int low, const long int high) {
    if (low >= high)
        return;
    const int pivot = partition(numbers, low, high);
    quicksort(numbers, low, pivot - 1);
    quicksort(numbers, pivot + 1, high);
}

void quicksort(std::vector<int>& numbers) {
    quicksort(numbers, 0, static_cast<long>(numbers.size()) - 1);
}

int main() {
    constexpr long count = 1000000;
    std::vector<int> numbers(count);
    for (int i = 0; i < count; i++)
        numbers[i] = static_cast<long int>(tan(i));
    const auto start = std::chrono::high_resolution_clock::now();
    quicksort(numbers);
    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken: " << diff.count() << " seconds\n";
    return 0;
}