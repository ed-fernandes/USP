import java.io.IOException;

public class Exercicio7 {
    //função que calcula valor do polinômio
    public static double calc(int a, int b, int c, int d, double x) {
        double n = a * Math.pow(x, 3) + b * Math.pow(x, 2) + c * x + d;
        return n;
    }
    //função que verifica sinal da expressão
    public static int sinal(double n){
        if(n >= 0){
            return 1;
        }else{
            return 0;
        }
    }
    public static void main(String[] args) throws IOException {
        double a = 0, b = 0;
        System.out.println("Digite o início do intervalo");
        a = EntradaTeclado.leDouble();
        System.out.println("Digite o fim do intervalo:");
        b = EntradaTeclado.leDouble();
        //System.out.println("f(a) = "+calc(1, -1, -13, 8, a)+", f(b) = "+calc(1, -1, -13, 8, b));
        double erro = Math.pow(10, -7);
        int n = 1;
        while (n <= 1000) {
            double c = (a + b) / 2;
            if (calc(1, -1, -13, 8, c) == 0 || (b - a) / 2 < erro) {
                System.out.println("f("+String.format("%.6f", c)+") = "+ String.format("%.6f", calc(1, -1, -13, 8, c)));
                System.out.println(n + " iterações necessárias.");
                break;
            }
            n++;
            if (sinal(calc(1, -1, -13, 8, c)) == sinal(calc(1, -1, -13, 8, a))) {
                a = c;
            } else {
                b = c;
            }
        }
    }
}
