package com.company;

import java.util.*;
import static java.lang.StrictMath.sqrt;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // инициализация элементов программы
        int N = 0;
        int x;
        int choose = 0;
        List<Integer> clients = new ArrayList<>();

        try {
            System.out.print("Укажите число клиентов: "); N = sc.nextInt();
            System.out.println("Необходимо присвоить каждому клиенту номер ID");
            for(int i = 0; i < N; i++) {
                System.out.print("Клиент " + (i+1) + "й: ");
                clients.add(sc.nextInt());
            }
            System.out.print("Введите ID искомого клиента: "); x = sc.nextInt();
            System.out.println("1. Поиск перебором");
            System.out.println("2. Поиск с барьером");
            System.out.println("3. Бинарный поиск");
            System.out.println("3. Бинарный поиск (Золотое сечение)");
            System.out.print("Выберите способ поиска: "); choose = sc.nextInt();

            switch(choose) {
                // Поиск перебором
                case 1:
                    Force_search(x, clients);
                    break;
                // Поиск с барьером
                case 2:
                    Barrier_search(x, clients);
                    break;
                // Бинарный поиск
                case 3:
                    // сортируем элементы массива, так как для бинарного поиска
                    // элементы массива должны быть отсортированными
                    Collections.sort(clients);
                    int first = 0;
                    int last = N-1;
                    Binary_search(clients, first, last, x);
                    break;
                case 4:
                    Collections.sort(clients);
                    Binary_Search_Gold_Cut(clients, x);
                default:
                    System.out.println("Данный символ не поддерживается");
                    break;
            }
            System.exit(1);
        } catch (Exception e) {
            System.out.println("Ошибка ввода данных! Работа программы будет завершена");
            System.exit(0);
        }
    }
    // Поиск перебором
    public static void Force_search(int x, List<Integer> arr) {
        int i = 0;
        while((i < arr.size()) && (arr.get(i) != x)) {
            i++;
        }
        if (i == arr.size()) {
            System.out.println("_________________________");
            System.out.println("Совпадения не обнаружено");
        } else {
            System.out.println("__________________________________________________");
            System.out.println("Метод поиска перебором нашел искомого клиента");
            System.out.println("Клиент c ID " +x+ " найден и его порядковый номер " + (i+1));
        }
    }

    // Поиск с барьером
    public static void Barrier_search(int x, List<Integer> arr) {
        arr.add(x);
        int i = 0;
        while(arr.get(i) != x) {
            i++;
        }
        if ((i+1) == arr.size()) {
            System.out.println("_________________________");
            System.out.println("Совпадения не обнаружено!");
        } else {
            System.out.println("__________________________________________________");
            System.out.println("Метод поиска c барьером нашел искомого клиента");
            System.out.println("Клиент c ID " +x+ " найден и его порядковый номер " + (i+1));
        }
    }

    // Бинарный поиск
    public static void Binary_search(List<Integer> arr, int first, int last, int x) {
        int pos;
        int Count = 1;
        pos = (first + last) / 2;

        while((arr.get(pos) != x) && (first <= last)) {
            Count++;
            if (arr.get(pos) > x) last = pos -1;
            else {
                first = pos + 1;
            }
            pos = (first + last) / 2;
        }
        if (first <= last) {

            System.out.println("________________________________________________________________");
            System.out.println("Метод бинарного поиска нашел искомого клиента после " +Count+" сравнений");
            System.out.println("Клиент c ID " +x+ " найден");
        }
        else {
            System.out.println("_________________________");
            System.out.println("Совпадения не обнаружено!");
        }
    }

    // Бинарный поиск с золотым сечением
    public static void Binary_Search_Gold_Cut(List<Integer> arr, int x){
        int l = 0;
        int r = arr.size() - 1;
        int k = 0;
        boolean isFound = false;
        while((l < r) && (!isFound)){
            int m = (int)Math.round((r - l) * (3 - sqrt(5)) / 2);
            if(arr.get(m) == x){
                isFound = true;
                k = m;
            }
            else if(arr.get(m) < x) { r = m; }
            else { l = m; }

        }
        if (isFound && k != 0){ System.out.println("__________________________________________________");
            System.out.println("Метод поиска перебором нашел искомого клиента");
            System.out.println("Клиент c ID " +x+ " найден и его порядковый номер " + (k+1)); }
        else{  System.out.println("_________________________");
            System.out.println("Совпадения не обнаружено"); }
    }
}
