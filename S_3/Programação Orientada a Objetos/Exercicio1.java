import java.io.IOException;
public class Exercicio1 {
    public static void main(String[] args) throws IOException {
        double precisao = (double)0.00000001;
        System.out.println("Digita um valor para calcular a raiz:");
        double num = EntradaTeclado.leDouble();
        double b = num;
        double a = 1;
        while ((b-a) >= precisao){
            System.out.println("Iterando... "+b);
            b = (a+b)/2;
            a = num/b;
        }
        System.out.println("A raiz é aproximadamente: "+ b);
    }
}
