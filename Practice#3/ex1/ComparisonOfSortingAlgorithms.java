package com.company;
/*
* реализовать в программе два алгоритма указанных ниже
* 1) сортировка с помощью прямого включения
* 2) шейкерная сортировка
* сравнить эффективность алгоритмов по числу перестановок
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size;

        System.out.print("Enter size of array: ");
        size = sc.nextInt();
        int[] arr = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.print("Element " + (i+1) + ": ");
            arr[i] = sc.nextInt();
        }

        inclusionSort(arr);
        myShakerSort(arr);
        showArray(arr);

    }

    // Сортировка методом прямого включения
    public static void inclusionSort(int[] arr) {
        int counter = 0;
        for (int i = 0; i < arr.length; i++) {
            int value = arr[i]; // запоминаем значение элемента
            int index = i; // и его индекс

            while ((index > 0) && (arr[index - 1] > value)) {
                // смещаем другие элементы к концу массива пока они меньше index
                arr[index] = arr[index - 1];
                index--; // смещаем просмотр к началу массива
                counter++;
            }
            arr[index] = value; // рассматриваемый элемент помещаем на освободившееся место
        }
        System.out.printf("\nЧисло перестановок сортировкой методом прямого включения: " + counter);
    }

    // Функция для обмена значений ячеей
    public static void swapEl(int[] arr, int i) {
        int temp;
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }

    // Шейкерная сортировка
    public static void myShakerSort(int[] arr) {
        int leftMark = 1;
        int rightMark = arr.length - 1;

        while (leftMark <= rightMark) {
            for (int i = rightMark; i >= leftMark; i--) {
                if (arr[i-1] > arr[i]) swapEl(arr, i);
                leftMark++;
            }

            for (int i = leftMark; i <= rightMark; i++)
                if (arr[i-1] > arr[i]) swapEl(arr, i);
                rightMark--;
        }
        System.out.println("\nЧисло перестановок шейкерной сортировкой: " + (leftMark-1));
    }

    public static void showArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
