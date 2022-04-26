#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[20];
    int poderbase;
    float acuracia;
    char classe;
} Ataque;
typedef struct {
    int hp;
    int ataque;
    int defesa;
    int ataqueespecial;
    int defesaespecial;
    int velocidade;
} Atributo;
typedef struct {
    char nome[50];
    char tipoprimario[20];
    char tiposecundario[20];
    Atributo atributos;
    Ataque ataques[4];
} Pokemon;
Pokemon addPokemon() {
    Pokemon pokemon;
    scanf("%s\n", pokemon.nome);
    scanf("%s\n", pokemon.tipoprimario);
    scanf("%s\n", pokemon.tiposecundario);
    scanf("%d\n", &pokemon.atributos.hp);
    scanf("%d\n", &pokemon.atributos.ataque);
    scanf("%d\n", &pokemon.atributos.defesa);
    scanf("%d\n", &pokemon.atributos.ataqueespecial);
    scanf("%d\n", &pokemon.atributos.defesaespecial);
    scanf("%d\n", &pokemon.atributos.velocidade);
    return pokemon;
}
Ataque addAtaque() {
    Ataque ataque;
    scanf("%s\n", ataque.nome);
    scanf("%d\n", &ataque.poderbase);
    scanf("%f\n", &ataque.acuracia);
    scanf("%c\n", &ataque.classe);
    return ataque;
}
void printPokemon(Pokemon pokemon) {
    printf("Nome do Pokemon: %s\n", pokemon.nome);
    printf("Tipo primario: %s\n", pokemon.tipoprimario);
    printf("Tipo secundario: %s\n", pokemon.tiposecundario);
    printf("Status:\n");
    printf("\tHP: %d\n", pokemon.atributos.hp);
    printf("\tAtaque: %d\n", pokemon.atributos.ataque);
    printf("\tDefesa: %d\n", pokemon.atributos.defesa);
    printf("\tAtaque Especial: %d\n", pokemon.atributos.ataqueespecial);
    printf("\tDefesa Especial: %d\n", pokemon.atributos.defesaespecial);
    printf("\tVelocidade: %d\n\n", pokemon.atributos.velocidade);
}
void printAtaque(Ataque ataque) {
    printf("Nome do Ataque: %s\n", ataque.nome);
    printf("Poder base: %d\n", ataque.poderbase);
    printf("Acuracia: %f\n", ataque.acuracia);
    printf("Classe: %c\n\n", ataque.classe);
}
int main() {
    Pokemon *pokedex = malloc(sizeof(Pokemon)); // uma pokedex é uma "lista" de pokemons
    int quantidade = 0, operacao, indicepokemon, indiceataque;
    while (operacao != 0) {
        scanf("%d", &operacao);
        if (operacao == 1) {  // adiciona pokemon
            pokedex = realloc(pokedex, (quantidade + 1) * sizeof(Pokemon));
            pokedex[quantidade] = addPokemon();
            quantidade++;
        } else if (operacao == 2) { //adiciona ataque
            scanf("%d\n", &indicepokemon);
            scanf("%d\n", &indiceataque);
            pokedex[indicepokemon].ataques[indiceataque] = addAtaque();
        } else if (operacao == 3) { //printa pokemom
            scanf("%d\n", &indicepokemon);
            printPokemon(pokedex[indicepokemon]);
        } else if (operacao == 4) { //printa ataque
            scanf("%d\n", &indicepokemon);
            scanf("%d\n", &indiceataque);
            printAtaque(pokedex[indicepokemon].ataques[indiceataque]);
        }else{
            break;
        }
    }
    free(pokedex);
    return 0;
}