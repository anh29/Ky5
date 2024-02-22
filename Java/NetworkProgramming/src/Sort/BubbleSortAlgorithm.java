package Sort;

import java.util.Arrays;

public class BubbleSortAlgorithm implements SortAlgorithm {
    @Override
    public void sort(int[] array) {
        // TODO: Implement bubble sort logic
        int n = array.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    // swap temp and arr[i]
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        System.out.println("Sorted using Bubble Sort: " + Arrays.toString(array));
    }
}
