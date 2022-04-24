
import java.io.IOException;

public class Exercicio3 {

    public static void main(String[] args) throws IOException {
        System.out.println("Digite um inteiro:");
        int x = EntradaTeclado.leInt();
        while (x > 0) {
            int k = x;
            while (k > 0) {
                System.out.print("*");
                k--;
            }
            System.out.println("");
            x--;
        }
    }
}
