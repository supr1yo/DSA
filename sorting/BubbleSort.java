public class BubbleSort {

    static void Sort(int[] arr, int n) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,3,2,5,4};
        int n = 5;

        Sort(arr, n);

        // Printing the sorted array:
        System.out.println("Printing the sorted array:");
        for(int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
    }
}