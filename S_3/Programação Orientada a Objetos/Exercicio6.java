import java.io.IOException;
import java.util.Scanner;

public class Exercicio6 {
    public static void main(String[] args) throws IOException {
        double n = EntradaTeclado.leDouble();
        double menor = n, maior = n;
        while (true) {
            if (n == 0) {
                break;
            }
            if (n <= menor) {
                menor = n;
            } else if (n >= maior) {
                maior = n;
            }
            n = EntradaTeclado.leDouble();
        }
        System.out.println("O menor é " + menor + " e o maior é " + maior);

    }


}
