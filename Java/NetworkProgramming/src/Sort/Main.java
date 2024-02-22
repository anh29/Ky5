package Sort;

public class Main {
    public static void main(String[] args) {
        int[] inputArray = {1, 5, 2, 7, 3};

        // Using Bubble Sort
        SortAlgorithm bubbleSortAlgorithm = new BubbleSortAlgorithm();
        VeryComplexService business1 = new VeryComplexService(bubbleSortAlgorithm);
        business1.complexBusiness(inputArray);

        // Using Quicksort
        SortAlgorithm quickSortAlgorithm = new QuicksortAlgorithm();
        VeryComplexService business2 = new VeryComplexService(quickSortAlgorithm);
        business2.complexBusiness(inputArray);
    }
}
