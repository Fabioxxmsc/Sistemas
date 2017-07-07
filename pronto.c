#include "lib.c"

int main(){
	int i, j;
	int x1 =  0, y1 =  0; // Vértice A
	int x2 =  0, y2 = 50; // Vértice B
	int x3 = 50, y3 = 50; // Vértice C
	int x, y;							// Ponto P
	bool flag = false;

	arq = fopen("entradaVerilog.txt", "w");
	prm = fopen("saida.txt", "w");

	printf("\n\tMatriz de 50x50\n\n");
	printf("Informe as coordenadas do ponto P: \n\n");
	scanf("%d%d", &x, &y);
	printf("\n\n");
	for (i = 0; i < 50; i++){
		for (j = 0; j < 50; j++){
			if (verifica(x1, y1 , x2, y2, x3, y3, i, j)){
				//fprintf(prm,"%d %d  %d %d  %d %d  %d %d\n", x1, y1, x2, y2, x3, y3, i, j);
				if(i == x && j == y){
					printf("X");
					//fprintf(arq,"%d %d  %d %d  %d %d  %d %d 2\n", x1, y1, x2, y2, x3, y3, i, j);
					flag = true;
				}
				else{
					printf("*");
					fprintf(arq,"%d %d  %d %d  %d %d  %d %d 1\n", x1, y1, x2, y2, x3, y3, i, j);
				}
			}else{
				printf("!");
				fprintf(arq,"%d %d  %d %d  %d %d  %d %d 0\n", x1, y1, x2, y2, x3, y3, i, j);
			}
		}
		printf("\n");
	}

	fclose(arq);
	if(flag)
		printf("O ponto P esta dentro do triangulo!\n\n");
	else
		printf("O ponto P nao esta dentro do triangulo!\n\n");
	system("iverilog pronto.v -o verilog");
	system("./verilog");
	system("rm dump.vcd");
	system("diff entradaVerilog.txt saidaVerilog.txt");
	return 0;
}
