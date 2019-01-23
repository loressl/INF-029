

struct principal{
    int *auxiliar;
    int quantidade;
    int contador;
    int *ordenaEstrutura;
};

int menu();
void chooseArq(struct principal *Posicao, int tam);
void tipoArquivo(int op);
int tamanhoArquivo();
void txt(struct principal *Posicao, int tam);
void binario(struct principal *Posicao, int tam);
void segunda_entrada(int *op);
void alocacao(int i, int contador, int alocar, struct principal *Posicao);
void dados_TXT(struct principal *Posicao, int tam);
void dados_BINARIO(struct principal *Posicao, int tam);
void escolha(struct principal *Posicao, int tam, int op);
void dados_Alocar(struct principal *Posicao, int tam);
void dados_Arquivo(struct principal *Posicao, int tam, int op);
void passarDados(struct principal *Posicao, int tam);
void dados_Alocacao(struct principal *Posicao, int tam);
void *Malloc(struct principal *Posicao, int posicao);
void *Realloc(struct principal Posicao[], int num, int pos);
void inserir(struct principal *Posicao, int tam, int pos);
int contSpace(struct principal *Posicao, int elemento, int pos);
void listarPorEstrutura(struct principal *Posicao, int tam);
void listarOrdPorEstr(struct principal *Posicao, int tam);
void listarTodos(struct principal *Posicao, int tam);
void passarValores(struct principal *Posicao, int tam);
void insertionSort(struct principal *Posicao, int tam);
void insertionSort_Todos(int *ordenaTotal, int *total);
int validarEntrada(char *dado, int *num);
int validarElemento(char *dados, int *elemento);
void saberPosicao(int *pos, int tam);
void pegarElemento(int *elemento);
void excluir(struct principal *Posicao, int tam, int pos);
void mostrarPosicoes(struct principal *Posicao, int tam);
void aumentar(struct principal *Posicao, int pos);
int somaTotal(struct principal *Posicao, int tam);
int separar_Numero(char *dados, int *vetor, int *cont, int *multiplicador, int negativo);
