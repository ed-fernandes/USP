
import java.io.IOException;

public class Exercicio4 {

    public static void main(String[] args) throws IOException {
        System.out.println("Digite um inteiro:");
        int x = EntradaTeclado.leInt();
        int m = x;
        while (x > 0) {
            int k = x;
            int j = m - x;
            while (j > 0) {
                System.out.print(" ");
                j--;
            }
            while (k > 0) {

                System.out.print("*");
                k--;
            }
            
            System.out.println("");
            x--;
        }
    }
}
