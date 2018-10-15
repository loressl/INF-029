
struct data{
    int dia, mes, ano;
};

int q1(char *data);
void ValorStringEmInteiro(char *data, int *dia, int *mes, int *ano);
void TransformaNumero(int *num, int a, int *multiplicador, int *data);

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int comparaData(char *dataInicial, char *dataFinal);
int anoBissexto(int ano);
void TotalDias(int *vetorDias, struct data DATA[], int *dias, int *total);
void CalculoDiferenca(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
void CalculoMesesDias(struct data DATA[], int *total, int divisor, int *qtdMeses, int *qtdDias);

int q3(char *texto, char c, int isCaseSensitive);

int q4(char *strTexto, char *strBusca, int posicoes[30]);

int q5(int num);

int q6(int numerobase, int numerobusca);
void SeparaNumero(int num, int vetor[], int *cont);
