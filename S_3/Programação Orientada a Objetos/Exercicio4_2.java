import java.io.IOException;
import java.lang.Math;
public class Exercicio4_2 {
    public static void main(String[] args) throws IOException {
        System.out.println("Digite um inteiro:");
        int n = EntradaTeclado.leInt();
        int p = (int)(Math.sqrt(n));
        int menor = n;
        boolean primo = true;
        for(int i = n-1; i >= p; --i){
            if(Math.floorMod(n,i)==0){
                primo = false;
                if(i < menor){
                    menor = i;
                }
            }
        }
        if(primo){
            System.out.println("É primo");
        }else{
            System.out.println("Não é primo e menor divisor é: "+menor);
        }
    }
}
