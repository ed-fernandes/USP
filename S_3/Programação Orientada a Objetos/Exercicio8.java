import java.io.IOException;

public class Exercicio8 {
    public static double funcao(double x) {
        return Math.pow(x, 3) + -1 * Math.pow(x, 2) - 13 * x + 8;
    }
    public static double d_funcao(double x){ // derivada de f
        return (3*Math.pow(x,2) -2*x - 13);
    }
    public static void newtonRaphson(double x0, double e){
        double h = funcao(x0)/d_funcao(x0);
        int cont = 0;
        while(Math.abs(h)>=e){
            h = funcao(x0)/d_funcao(x0);
            x0 = x0 - h;
            cont++;
        }
        System.out.println("A raiz é "+x0);
        System.out.println(cont+" iterações.");
    }
    public static void main(String[] args) throws IOException {
        double e = Math.pow(10, -7);
        double x0 = EntradaTeclado.leDouble();
        newtonRaphson(x0,e);
    }
}
