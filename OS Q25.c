#include <stdio.h>

int contiguousAllocation(int fileSize, int blockSize) {
    int totalOperations = 0;
    int numBlocks = fileSize / blockSize;

    
    totalOperations += 1;

    
    totalOperations += numBlocks;

    return totalOperations;
}

int linkedAllocation(int fileSize, int blockSize) {
    int totalOperations = 0;
    int numBlocks = fileSize / blockSize;

    
    totalOperations += 1;

    
    totalOperations += 1;

    
    totalOperations += numBlocks;

    return totalOperations;
}

int indexedAllocation(int fileSize, int blockSize) {
    int totalOperations = 0;
    int numBlocks = fileSize / blockSize;

    
    totalOperations += 1;

    
    totalOperations += 1;

    
    totalOperations += numBlocks;

    return totalOperations;
}

int main() {
    int fileSize = 100;
    int blockSize = 1;

    int contiguousOperations = contiguousAllocation(fileSize, blockSize);
    printf("Contiguous allocation requires %d disk I/O operations.\n", contiguousOperations);

    int linkedOperations = linkedAllocation(fileSize, blockSize);
    printf("Linked allocation requires %d disk I/O operations.\n", linkedOperations);

    int indexedOperations = indexedAllocation(fileSize, blockSize);
    printf("Indexed allocation requires %d disk I/O operations.\n", indexedOperations);

    return 0;
}
