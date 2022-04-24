import java.io.IOException;

public class Exercicio5 {
    public static boolean primo(int n) {
        boolean p = true;
        int t = (int) (Math.sqrt(n));
        for (int i = 2; i <= t; ++i) {
            if (Math.floorMod(n, i) == 0) {
                p = false;
                break;
            }
        }
        return p;
    }

    public static void main(String[] args) throws IOException {
        System.out.println("Digite um número:");
        int n = EntradaTeclado.leInt();
        if (primo(n)) {
            System.out.println("É primo.");
        } else {
            while (!primo(n)) {
                n--;
            }
            System.out.println("O primeiro número primo menor é "+n);
        }

    }
}
