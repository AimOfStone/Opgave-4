# Opgave-4


Rock Paper Scissors Spock Lizard (RPSSL)

Sådan fungerer spillet:

- Ved start mødes du af en menu:
  - (s) Start single player
  - (e) Exit program
- Hvis du vælger single player, spiller du mod en bot der vælger tilfældigt.
- Første spiller til at nå 5 point vinder spillet.
- Ugyldige inputs giver en fejlmeddelelse, og du kan prøve igen.


Komponenter i koden:
- while-løkker til spilflow
- switch til at afgøre vinderen
- rand() med time(NULL) til bot
- enum til at symbolisere figurerne
- Inputvalidering via getchar()
