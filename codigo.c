#include <stdio.h>

int simulador_escada_dupla (int N, int pessoas[][2]) {
    int ultima_parada = 0;  // Variável para armazenar o último momento em que a escada parou
    int direção = -1;  // Direção inicial da escada, -1 indica que ainda não foi definida

    for (int i = 0; i < N; i++) {
        int tempo = pessoas[i][0];
        int direção_desejada = pessoas[i][1];

        if (direção == -1 || direção == direção_desejada) {
            // Se a escada está parada ou se está indo na direção desejada pela pessoa, ela entra imediatamente
          direção = direção_desejada;
            ultima_parada = tempo > ultima_parada ? tempo : ultima_parada;  // A escada começa a se mover no momento em que a pessoa entra
        } else {
            // Se a escada está indo na direção oposta, esperamos até que ela pare
            ultima_parada += 10;  // A escada leva 10 segundos para se mover de um lado para o outro
            direção = direção_desejada;
        }
    }

    return ultima_parada + 10;  // Adiciona 10 segundos para representar o momento em que a escada parou pela última vez
}

int main() {
    int N;
    scanf("%d", &N);

    int pessoas[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pessoas[i][0], &pessoas[i][1]);
    }

    // Chamada da função e impressão do resultado
    int resultado = simulador_escada_dupla (N, pessoas);
    printf("%d\n", resultado);

    return 0;
}