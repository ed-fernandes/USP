import java.io.IOException;
import java.lang.Math;

public class Exercicio2 {

    public static double lerNum() {
        double x = 0;
        boolean talkey = false;
        while (!talkey) {
            try {
                x = EntradaTeclado.leDouble();
                return x;
            } catch (Exception e) {
                System.out.println("Número incorreto! Digite novamente:");
            }
        }
        return x;
    }

    public static void bhaskara(double a, double b, double c) {
        double delta = b * b - 4 * a * c;
        if (delta >= 0) {
            double s1 = (-b + Math.sqrt(delta)) / 2 * a;
            double s2 = (-b - Math.sqrt(delta)) / 2 * a;
            System.out.println("O conjunto solução da equação é : S = [" + s1 + "," + s2 + "]");
        } else {
            System.out.println("Não possui raízes reais!");
        }
    }

    public static void main(String[] args) throws IOException {
        double c1 = 0, c2 = 0, c3 = 0;
        System.out.println("Digite o primeiro coeficiente:");
        c1 = lerNum();
        System.out.println("Digite o segunda coeficiente:");
        c2 = lerNum();
        System.out.println("Digite o terceiro coeficiente:");
        c3 = lerNum();
        bhaskara(c1,c2,c3);
    }
}
