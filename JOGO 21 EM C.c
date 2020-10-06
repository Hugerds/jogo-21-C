//Feitos por Bryan Dias e Hugo Esteves
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void gotoxy(int x,int y) {
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x-1;
    dwPos.Y = y-1;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void rules() {
	system("cls");
	printf("Você receberá 2 cartas de início e poderá pedir quantas quiser.\nO objetivo é alcançar o número 21 sem estrapolar,\no jogador que tiver o valor mais próximo de 21 sem ter passado do limite é o vencedor.\nOBS: no turno do BOT(oponente) ele fará tudo sozinho, não é necessário clicar nem digitar nada.\n\n");
	printf ("APERTE QUALQUE TECLA PARA CONTINUAR\n\n\n");
   	getch();
   	system("cls");
}

void pause (float delay1) {
   if (delay1<0.001) return;
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
}

void game() {
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	system("color F0");
	int carta[20], cartaB[20], n, somaC=0, somaCB=0;
	char opcao;
	printf(">------------------>> ~BLACKJACK~ <<------------------<");
	printf("\n");
	printf("\n");
	srand( (unsigned)time(NULL) );
	carta[1]=1 + ( rand() % 10 );
	carta[2]=1 + ( rand() % 10 );
	somaC=carta[1]+carta[2];
	printf("Carta 1: %d.\nCarta 2: %d.\n\nSoma parcial: %d.\n\n",carta[1], carta[2], somaC);
	for(n=3; n<22; n++) {
		fflush(stdin);
		fflush(stdout);
		printf("Deseja comprar mais uma carta? (s/n)\n\n");
		scanf("%c",&opcao);
		if(opcao=='s') {
			carta[n]=1 + ( rand() % 10 );
			somaC+=carta[n];
			printf("\nCarta %d: %d.\n\nSoma parcial: %d.\n\n", n, carta[n], somaC);
			if(somaC>21) {
				printf("Você perdeu :C\n");
				goto acabou;
			}
			if(somaC==21) {
				printf("Você somou 21, Parabéns você ganhou!\n");
				goto acabou;
			}
		}
		if(opcao=='n') {
			printf("\nCerto, você somou %d. Agora é a minha vez.\n\n",somaC);
			break;
		}
	}
	// Turno do BOT //s
	cartaB[1]=1 + ( rand() % 10 );
	cartaB[2]=1 + ( rand() % 10 );
	somaCB=cartaB[1]+cartaB[2];
	printf("Tirei %d e %d então minha soma parcial é %d.\n",cartaB[1], cartaB[2], somaCB);
	int i=3;
	while(somaCB<=somaC) {
		printf("\nComprando mais uma carta.\n\n");
		cartaB[i]=1 + ( rand() % 10 );
		somaCB+=cartaB[i];
		if(somaCB==21) {
			pause(1 + ( rand() % 10 ));
			printf("\nMinha %dª carta é %d e minha soma é %d.\n", i, cartaB[i], somaCB);
			pause(2);
			printf("\nEu somei 21, eu ganhei!\n");
			goto acabou;
		}
		if(somaCB>21) {
			printf("\nMinha %dª carta é %d e minha soma é %d.\n", i, cartaB[i], somaCB);
			pause(2);
			printf("\nVocê ganhou, pois eu ultrapassei 21.\n");
			goto acabou;
		}
		pause(1 + ( rand() % 10 ));
		printf("Minha %dª carta é %d e minha soma parcial é %d.\n", i, cartaB[i], somaCB);
		i++;
	}
	if(somaCB>somaC) {
		printf("\nEu somei %d e você somou %d, por isso eu ganhei!\n",somaCB, somaC);
		goto acabou;
	}
	acabou:
	printf ("\n\nAPERTE QUALQUE TECLA PARA CONTINUAR\n\n\n");
   	getch();
   	fflush (stdin);
   	fflush (stdout);
   	system("cls");
}

void rep() {
	game();
}

void carregamento() {
    setlocale(LC_ALL, "C");
    int i, j;
   system ("cls");
   gotoxy(15,8);printf ("\n\nCarregando: \n\n");
   for (i = 0; i <= 100; i++) {
      printf ("  %d%%\r", i);
      fflush (stdout);
      for (j = 0; j < i; j++) {
         if (!j)
           printf ("  ");
         printf ("%c", 219);
         Sleep(0.9999999999999995);
      }
   }
   printf ("\n\nAguarde...");
   Sleep (1000);
   gotoxy(15,17);printf ("APERTE QUALQUE TECLA PARA CONTINUAR\n\n\n");
   getch();
   fflush (stdin);
   fflush (stdout);
   setlocale(LC_ALL, "Portuguese");
}

void menuPrincipal() {
	
    int sair = 1, y = 7, opcao = 1;
    setlocale(LC_ALL, "C");
    gotoxy(18,5); printf("Menu Principal");
    gotoxy(18,7); printf("->");
    while(sair){
        setlocale(LC_ALL, "Portuguese");
        gotoxy(18,5);  printf("Menu Principal");
        gotoxy(20,7);  printf("JOGAR");
        gotoxy(20,8);  printf("REGRAS");
        gotoxy(20,9);  printf("SAIR");
        setlocale(LC_ALL, "C");
        system("pause>nul");
        if(GetAsyncKeyState(VK_DOWN) && y != 9) {
            gotoxy(18,y); printf("  ");
            y++;
            gotoxy(18,y); printf("->");
            opcao++;
            continue;
        }
        if(GetAsyncKeyState(VK_UP) && y != 7){
            gotoxy(18,y); printf("  ");
            y--;
            gotoxy(18,y); printf("->");
            opcao--;
            continue;
        }
        if(GetAsyncKeyState(VK_RETURN)){
            if (opcao == 1) {
                carregamento();
                system("cls");
                game();
                }
            if (opcao == 2) {
            	setlocale(LC_ALL, "Portuguese");
            	system("cls");
                rules();
            }
            if (opcao == 3) {
                break;
            }
        }
    }
    setlocale(LC_ALL, "C");
}	

int main() {
	system("color F0");
	menuPrincipal();
}
