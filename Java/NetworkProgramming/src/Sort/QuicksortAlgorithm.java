package Sort;

import java.util.Arrays;

public class QuicksortAlgorithm implements SortAlgorithm {
    @Override
    public void sort(int[] array) {
        // TODO: Implement quicksort logic
        Arrays.sort(array);
        System.out.println("Sorted using Quicksort: " + Arrays.toString(array));
    }
}
