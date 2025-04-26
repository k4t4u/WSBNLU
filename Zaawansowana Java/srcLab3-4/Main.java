import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("\nWybierz 1 - kalkulator prosty \n2 - kalkulator zaawansowany");

        Scanner sc = new Scanner(System.in);
        switch (sc.nextInt()) {
            case 1 :
                ProstyKalkulator kalkulator = new ProstyKalkulator();
                break;
            case 2 :
                ZaawansowanyKalkulator zaawansowany = new ZaawansowanyKalkulator();
                break;
        }
        sc.close();
    }
}
