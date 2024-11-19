# System-of-a-Dunk
**Jogo de basquete em C** desenvolvido para a disciplina de **Programação Imperativa e Funcional** (2024.2) da **CESAR School**.

## Equipe
- **Matheus Miranda Escorel**
- **Jorge Augusto Lacerda Vasconcelos**
- **Fernanda Ramalho Bezerra**
- **Paulo Henrique Egito Inácio da Silva**

## Descrição
O **System-of-a-Dunk** é um jogo de basquete de terminal, desenvolvido em C, que busca proporcionar uma experiência interativa e divertida, utilizando conceitos fundamentais de programação imperativa e funcional.

O objetivo principal é arremesar a bola na cesta adversária para obter pontos, o jogador que alcançar a quantidade de pontos máxima primeiro ganha a partida.

## Mecânicas do Jogo

1. Movimentação:
    - Horizontal (esquerda/direita).
    - Vertical (para cima).
2. Ataque:
    - Permite roubar a bola do adversário caso esteja ao alcance.
3. Defesa:
    - Modifica a posição da bola, tirando-a do alcance do adversário.
4. Arremesso:
    - Permite lançar a bola a uma distância definida em direção à cesta.

## Como Executar
Para compilar e executar o jogo, siga os passos abaixo:

1. Clone o repositório:
    ```bash
    git clone https://github.com/seu-repositorio/system-of-a-dunk.git
    ```

2. Acesse o diretório do projeto:
    ```bash
    cd system-of-a-dunk
    ```

3. Compile o código:
    ```bash
    gcc src/*.c -I include -o system-of-a-dunk
    ```

4. Execute o jogo:
    ```bash
    ./system-of-a-dunk
    ```

## Funcionalidades
- [ ] Movimentação do jogador: controle dinâmico no terminal.
- [ ] Arremessos para a cesta: simulação de jogadas reais.
- [ ] Sistema de pontuação: registro automático de pontos.
- [ ] Temporizador de partida: limite de tempo configurável.
- [ ] Efeitos visuais e sonoros no terminal: elementos gráficos e auditivos no terminal.

## Contribuições
Contribuições são muito bem-vindas! Se desejar colaborar, siga os passos abaixo:

1. Abra uma issue para sugerir melhorias ou relatar problemas.
2. Crie um fork do repositório.
3. Envie suas alterações via pull request, explicando as modificações realizadas.

## Regras do Jogo

1. **Objetivo**
O objetivo do jogo é marcar o maior número de pontos possível antes que o tempo acabe, enquanto evita obstáculos e interage com os elementos do jogo.

2. **Movimentação**
- O jogador utiliza as teclas W, A, D para mover o personagem:
W → Pular.
A → Mover para a esquerda.
D → Mover para a direita.

3. **Arremesso**
- Pressione F para realizar um arremesso.
- Se a bola entrar na cesta, o jogador ganha pontos.
- A posição da cesta será fixa na tela (exibida pela função exibirCesta2()).

4. **Tempo**
- O jogador tem 30 segundos para jogar (valor definido em TEMPO_LIMITE).
- O tempo restante é exibido no canto superior direito da tela.

5. **Pontuação**
- Cada arremesso bem-sucedido aumenta a pontuação do jogador (o valor exato é calculado pela função arremessarJogador1()).
- A pontuação é salva ao final do jogo no sistema de ranking (salvarPontuacao).

6. **Personagem Controlado (Jogador)**
- As posições do jogador são atualizadas em tempo real conforme as teclas pressionadas.

7. **NPC (Adversário)**
- O NPC se move na tela utilizando a função movNpc(). Ele pode atuar como um obstáculo para o jogador.

8. **Fim do Jogo**
- O jogo termina quando:
    - O tempo acaba (tempoRestante == 0).
    - O jogador pressiona a tecla ESC, retornando ao menu principal.

9. **Menu**
- No início, o jogador vê um menu com as seguintes opções:
    -> 0 - Jogar: Começa o jogo.
    -> 1 - Exibir Controles: Exibe as instruções de jogo.

10. **Gravidade e Pulo**
- A física do jogo é representada pelos seguintes parâmetros:
    - GRAVIDADE: Define o efeito de gravidade sobre o jogador.
    - ALTURA_PULO: Define o limite vertical que o jogador pode alcançar ao pular.

11. **Rankings**
    - Ao final do jogo, a pontuação do jogador é salva e poderá ser exibida em rankings futuros.



