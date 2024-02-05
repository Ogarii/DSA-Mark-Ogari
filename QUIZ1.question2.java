import java.util.Arrays;
import java.util.Scanner;

 class RotateArray {
    public static void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;  // Handle cases where k >= n

       
        int start = 0;
        int count = 0;
        while (count < n) {
            int current = start;
            int prev = nums[start];
            while (true) {
                int nextIndex = (current + k) % n;
                int nextElement = nums[nextIndex];
                nums[nextIndex] = prev;
                prev = nextElement;
                current = nextIndex;
                count++;
                if (current == start) {
                    break;
                }
            }
            start++;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] nums = new int[size];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            nums[i] = scanner.nextInt();
        }

        System.out.print("Enter the number of positions to rotate right: ");
        int k = scanner.nextInt();

        rotate(nums, k);

        System.out.println("The rotated array is: " + Arrays.toString(nums));
    }
}
