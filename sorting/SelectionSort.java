public class SelectionSort {
    static void sort(int[] arr, int n) {
        for(int i = 0; i < n - 1; i++) {
            int min_index = i;
            for(int j = i+1; j < n; j++) {
                if(arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }

            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,5,3,2,6,8,10};

        sort(arr, arr.length);

        // Printing the sorted array:
        System.out.println("Printing the sorted array:");
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}