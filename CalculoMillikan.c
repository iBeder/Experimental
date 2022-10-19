//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
//%%%%%%%%%%%% Código para calcular o raio e a carga da gota de Millikan %%%%%%%%%//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
//%%%%%%%%%%%%%%%%%%%% Elaborado por: Igor Beder Burti R. %%%%%%%%%%%%%%%%%%%%%%%%//
//%%%%%%%%%%%%%%%%%%%%%% Última modificação: 16/10/2022 %%%%%%%%%%%%%%%%%%%%%%%%%%//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define pi M_PI
#define g 9.81

int main(){

    FILE *txt;

    double eta, vd, vs, rhoAR, rhoOleo, U, ts, td, Sumts, Sumtd, d, r, num, den, q;
    char file1[50], file2[50];
    int i;
    
    printf("Nome do arquivo de entrada: "); // O programa pede o nome do arquivo de entrada
    scanf("%s", file1);

    txt = fopen(file1, "r");

    U = 350.0; // Tensão
    eta = 17.2e-6; // Coeficiente de viscosidade do ar
    rhoOleo = 1030.0; // Densidade do óleo
    rhoAR = 1.293; // Densidade do ar
    d = (0.89e-3/(3.0)); // Distância percorrida pelas gotas
    Sumts = 0.0;
    Sumtd = 0.0;
    i = 0;
     
    while(fscanf(txt, "%lf %lf", &ts, &td) != EOF){ // O programa lê a primeira coluna (tempo de subida) e a segunda coluna (tempo de descida)

        Sumts = Sumts + ts;
        Sumtd = Sumtd + td;
        i++;
    }

    Sumts = Sumts/i; // Cálculo da média do tempo de subida
    Sumtd = Sumtd/i; // Cálculo da média do tempo de descida

    vs = d/Sumts; // Velocidade de subida
    vd = d/Sumtd; // Velocidade de descida

    num = eta*(vd-vs); // Numerador da equação ()
    den = g*(rhoOleo - rhoAR); // Denominador da equação ()

    r = (3.0/2.0)*sqrt(num/den); // Cálculo do raio da gota

    q = (4.0/3.0)*pi*(d/U)*(pow(r, 3.0)*g*(rhoAR-rhoOleo) + (9.0/2.0)*eta*r*vd); // Cálculo da carga, a partir da equação () 

    printf("\nCarga: %.4g", q);
    printf("\nvs: %.4g", vs);
    printf("\nvd: %.8g\n", vd);
    printf("ts: %.4g\n", Sumts);
    printf("td: %.4g\n", Sumtd);

    //printf("\nErro: %lf\n", ((1.6e-19 - q)/(1.6e-19))*100);
    return 0;
}
