/*
##################################################

# Pontificia Universidad Javeriana
# Autor: David Vallejo
# fecha: 21 de octubre de 2026
# Asunto: segundo ejercicio de POSIX
#################################################
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
typedef int fileDescriptor;
typedef fileDescriptor Pipe[2];
fileDescriptor Reader (Pipe p) { return p[0];}
fileDescriptor Writer (Pipe p) {return p[1];}

void check(int ok, char *where) {

if(ok<0) {

	fprintf(stderr, "error %s: %s\n", where, strerror(errno));
exit(1);
}


}



int main() {

int ok;
Pipe tuboA, tuboB;
char entradaA[100], entradaB[100];

printf("ingreso 1: \n");
scanf("%s", entradaA);

printf("2\n");
scanf("%s", entradaB);

ok = pipe(tuboA);	check(ok,"abriendo tubo  a");
ok = pipe(tuboB);	check(ok, "abriendo el b");

pid_t proceso = fork(); check (proceso, "creando proceso");

if(proceso >0) {
char busP[100];
close(Reader(tuboA));
write(tuboA[1], entradaB, strlen(entradaB) +1);
close(Writer(tuboB)); read(tuboB[0], busP, 100);
printf("Cadena: %s\n", busP);
close(Reader(tuboB));

} else {

close(Writer(tuboA));
char busH[100];
read(tuboA[0], busH, 100);
int k= strlen(busH);

for(int i=0; i<strlen(entradaA); i++) {

busH[k++] = entradaA[i];
}
busH[k]= '\0';


close(Reader(tuboA));
close(Reader(tuboB));

write(tuboB[1], busH, strlen(busH) +1);
close(Writer(tuboB));
}

exit (0);
}
