#include "ListaDinEncadeadaDupla.h" //inclui os Protótipos


/**
 * @brief Insere um novo elemento no final da lista.
 *
 * Esta função insere um novo elemento com os dados do aluno 'al' no final da lista.
 *
 * @param li Ponteiro para a lista.
 * @param al Dados do aluno a serem inseridos.
 * @return 1 se a inserção for bem-sucedida, 0 se a lista for NULL ou a alocação de memória falhar.
 */
int insere_lista_final(Lista* li, Aluno al){
   
    if (li == NULL) return 0;
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;

         no->dados = al;
         no->prox  = NULL;

    if (*li == NULL){
        *li = no;

    } else {

        Elemento* aux = *li;
        
            while (aux->prox != NULL){
                aux = aux->prox;
            }
                aux->prox = no;
    }
    return 1;

}

/**
 * @brief Insere um novo elemento no início da lista.
 *
 * Esta função insere um novo elemento com os dados do aluno 'al' no início da lista.
 *
 * @param li Ponteiro para a lista.
 * @param al Dados do aluno a serem inseridos.
 * @return 1 se a inserção for bem-sucedida, 0 se a lista for NULL ou a alocação de memória falhar.
 */
int insere_lista_inicio(Lista* li, Aluno al){

    if (li == NULL) {
     return 0;
    }
    
    else {

    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0;
    no->dados = al;
    no->prox  = *li;
    *li       = no;
    return 1;

     }
}

/**
 * @brief Insere um novo elemento de forma ordenada na lista (ordenado por matrícula).
 *
 * Esta função insere um novo elemento com os dados do aluno 'al' na lista, mantendo a ordem crescente
 * da matrícula dos alunos.
 *
 * @param li Ponteiro para a lista.
 * @param al Dados do aluno a serem inseridos.
 * @return 1 se a inserção for bem-sucedida, 0 se a lista for NULL ou a alocação de memória falhar.
 */
int insere_lista_ordenada(Lista* li, Aluno al){
     
    if (li == NULL) return 0;
    calcular_media(&al);

    Elemento* no = malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = al;
    no->prox  = NULL;

    // caso a lista esteja vazia
    if (*li == NULL) {
        *li = no;
    } else {
        Elemento *ant = NULL, *atual = *li;

        // procura o local de inserção para o novo elemento dessa lista
        
        while (atual != NULL && atual->dados.matricula < al.matricula) {
            ant    = atual;
            atual  = atual->prox;
        }
        if (ant == NULL) {
            // insere no início
            no->prox = *li;
            *li      = no;
        } else {
            // insere entre ant e atual
            no->prox  = atual;
            ant->prox = no;
        }
    }
    return 1;

}

/**
 * @brief Remove um elemento da lista pela matrícula do aluno.
 *
 * Esta função remove o elemento da lista com a matrícula 'mat'.
 *
 * @param li Ponteiro para a lista.
 * @param mat Matrícula do aluno a ser removido.
 * @return 1 se a remoção for bem-sucedida, 0 se a lista for NULL, a lista estiver vazia ou a matrícula não for encontrada.
 */

int remove_lista_mat(Lista* li, int mat) {
 
    if (li == NULL || *li == NULL) 
        return 0;  // validação de se a a lista é inexistente ou vazia

    Elemento *ant = NULL;
    Elemento *atual = *li;

    // busca o nó com a matrícula desejada atualizando ant e atual, até achar essa matrícula ou chegar até o fim
    while (atual != NULL && atual->dados.matricula != mat) {
        ant = atual;
        atual = atual->prox;
    }

    
    if (atual == NULL) 
        return 0;

    // se ant é NULL, o nó a remover vai ser esse primeiro
    if (ant == NULL) {
        *li = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return 1;  // remove com free e retorna 1 ao sistema do código
}



/**
 * @brief Remove o primeiro elemento da lista.
 *
 * Esta função remove o primeiro elemento da lista.
 *
 * @param li Ponteiro para a lista.
 * @return 1 se a remoção for bem-sucedida, 0 se a lista for NULL ou a lista estiver vazia.
 */
int remove_lista_inicio(Lista* li){

    if (li == NULL || *li == NULL) return 0;
    Elemento* rem = *li;
    *li = rem->prox;
    free(rem);
    return 1;

}

/**
 * @brief Remove o último elemento da lista.
 *
 * Esta função remove o último elemento da lista.
 *
 * @param li Ponteiro para a lista.
 * @return 1 se a remoção for bem-sucedida, 0 se a lista for NULL ou a lista estiver vazia.
 */
int remove_lista_final(Lista* li){
   
    if (li == NULL || *li == NULL) {
    
    return 0;
    
    }
    
    Elemento *ant = NULL, *atual = *li;
    while (atual->prox != NULL){
        ant   = atual;
        atual = atual->prox;
    }
    if (ant == NULL){
        // único elemento
        *li = NULL;
    } else {
        ant->prox = NULL;
    }
    free(atual);
    return 1;

}

/**
 * @brief Consulta um elemento da lista em uma determinada posição.
 *
 * Esta função consulta o elemento na posição 'pos' da lista e copia os
 * dados do aluno para a variável 'al'.
 *
 * @param li Ponteiro para a lista.
 * @param pos Posição do elemento a ser consultado (a posição 1 é o primeiro elemento).
 * @param elem Ponteiro para a estrutura elemento onde os dados serão copiados.
 * @return 1 se a consulta for bem-sucedida, 0 se a lista for NULL ou a posição for inválida.
 */
int busca_lista_pos(Lista* li, int pos, Elemento **elem) {

    if (li == NULL || *li == NULL || pos <= 0 || elem == NULL) 
        return 0;

    Elemento* no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if (no == NULL) 
        return 0;

    *elem = no;   // devolve o próprio nó
    return 1;
}


/**
 * @brief Consulta um elemento da lista pela matrícula do aluno.
 *
 * Esta função busca um elemento na lista com a matrícula 'mat' e copia os
 * dados do aluno para a variável 'al'.
 *
 * @param li Ponteiro para a lista.
 * @param mat Matrícula do aluno a ser consultado.
 * @param elem Ponteiro para a estrutura elemento onde os dados serão copiados.
 * @return 1 se a consulta for bem-sucedida, 0 se a lista for NULL ou a matrícula não for encontrada.
 */
int busca_lista_mat(Lista* li, int mat, Elemento **elem) {
    if (li == NULL || *li == NULL || elem == NULL)
        return 0;

    Elemento* no = *li;
    while (no && no->dados.matricula != mat) {
        no = no->prox;
    }
    if (no == NULL)
        return 0;

    *elem = no;
    return 1;
}


/**
 * @brief Troca a posição de dois elementos na lista com base nas matrículas.
 *
 * Esta função localiza dois elementos na lista com as matrículas especificadas
 * e troca suas posições, ajustando os ponteiros adequadamente.
 *
 * @param li Ponteiro para a lista.
 * @param mat1 Matrícula do primeiro elemento a ser trocado.
 * @param mat2 Matrícula do segundo elemento a ser trocado.
 * @return 1 se a operação de troca for bem-sucedida, 0 caso contrário (lista NULL, elementos não encontrados ou erro na troca).
 */
int troca_elementos_lista(Lista* li, int mat1, int mat2) {

    if (!li || !*li || mat1 == mat2) return 0;

    Elemento dummy;            // nó “antes” da cabeça
    dummy.prox = *li;

    Elemento *prev1 = &dummy, *prev2 = &dummy;
    // encontra o antecessor de quem tem matrícula mat1
    while (prev1->prox && prev1->prox->dados.matricula != mat1)
        prev1 = prev1->prox;
    // e de quem tem matrícula mat2
    while (prev2->prox && prev2->prox->dados.matricula != mat2)
        prev2 = prev2->prox;

    Elemento *curr1 = prev1->prox, *curr2 = prev2->prox;
    if (!curr1 || !curr2) return 0;  // caso uma das matrículas não existe

    // aqui faz com que os antecessores apontem para o nó oposto
    prev1->prox = curr2;
    prev2->prox = curr1;
    // faz a troca dos próximos dentro dos próprios nós
    Elemento* tmp   = curr1->prox;
    curr1->prox     = curr2->prox;
    curr2->prox     = tmp;

    *li = dummy.prox;  // atualiza a cabeça 
    return 1;
}




/**
 * @brief Cria uma nova lista duplamente encadeada.
 *
 * Esta função aloca memória para uma nova lista duplamente encadeada e
 * inicializa o ponteiro da lista para NULL, indicando que a lista está vazia.
 *
 * @return Ponteiro para a lista criada. Retorna NULL se a alocação falhar.
 */
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

/**
 * @brief Calcula a média de um aluno e define seu status de aprovação.
 *
 * Esta função realiza a validação das notas do aluno, garantindo que
 * valores negativos sejam ajustados para zero. Em seguida, calcula a
 * média aritmética das duas notas e define o status de aprovação do
 * aluno com base na média calculada.
 *
 * @param aluno Ponteiro para a estrutura do tipo Aluno, que contém
 *              as notas, a média e o status de aprovação.
 *
 * @details
 * - Se a média for maior ou igual a 6.0, o status será definido como 1 (Aprovado).
 * - Caso contrário, o status será definido como 0 (Reprovado).
 */
void calcular_media(Aluno *aluno) {
    // Validação das notas
    aluno->n1 = aluno->n1 < 0 ? 0 : aluno->n1;
    aluno->n2 = aluno->n2 < 0 ? 0 : aluno->n2;
    aluno->n3 = aluno->n3 < 0 ? 0 : aluno->n3;

    aluno->media = (aluno->n1 + aluno->n2 + aluno->n3) / 3.0;

    if (aluno->media >= 6.0) {
        aluno->status = 1; // Aprovado
    } else {
        aluno->status = 0; // Reprovado
    }
}

/**
 * @brief Libera a memória alocada para a lista duplamente encadeada.
 *
 * Esta função libera a memória alocada para todos os elementos da lista e
 * para a própria lista. Se a lista for NULL, a função retorna sem fazer nada.
 *
 * @param li Ponteiro para a lista que será liberada.
 */
void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


/**
 * @brief Obtém o número de elementos na lista.
 *
 * Esta função calcula e retorna o número de elementos na lista.
 *
 * @param li Ponteiro para a lista.
 * @return O número de elementos na lista. Retorna 0 se a lista for NULL.
 */
int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}


/**
 * @brief Verifica se a lista está vazia.
 *
 * Esta função verifica se a lista está vazia.
 *
 * @param li Ponteiro para a lista.
 * @return 1 se a lista estiver vazia ou for NULL, 0 caso contrário.
 */
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}


/**
 * @brief Imprime todos os elementos de uma lista encadeada.
 *
 * Esta função percorre a lista encadeada e imprime os dados armazenados
 * em cada nó da lista. É necessário que a lista tenha sido previamente
 * inicializada e que os elementos estejam corretamente inseridos.
 *
 * @param li Ponteiro para a lista encadeada que será impressa.
 */
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;

    printf("\n");
    printf("%-10s | %-8s | %-8s | %-8s | %-8s | %-10s \n",
           " Matrícula", "N1", "N2", "N3", "MEDIA", "Status");
    printf("-----------|----------|----------|----------|----------|------------\n");

    /*
    printf("%-10s | %-30s | %-8s | %-8s | %-8s | %-8s | %-10s \n",
        " Matrícula", "Nome", "N1", "N2", "N3", "MEDIA", "Status");
    printf("-----------|--------------------------------|----------|----------|----------|------------\n");
    */

    while(no != NULL){

        if (no->dados.status == 0) { // Reprovado
            printf(RED_TEXT);
        }

        //printf("%-10d | %-30s | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10s",
        printf("%-10d | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10s",
            no->dados.matricula,
            no->dados.n1,
            no->dados.n2,
            no->dados.n3,
            no->dados.media,
            no->dados.status == 1 ? "Aprovado" : "Reprovado");
        if (no->dados.status == 0) {
            printf(RESET_TEXT);
        }
        printf("\n");

        no = no->prox;
    }
    printf("\n");
}

/**
 * @brief Imprime os dados de um único aluno.
 *
 * Esta função exibe as informações de um aluno, incluindo matrícula, notas,
 * média e status de aprovação.
 *
 * @param al Ponteiro para a estrutura do tipo Aluno que será impressa.
 */
void imprime_aluno(Aluno *al) {
    if (al == NULL)
        return;

    printf("\n");
    printf("%-10s | %-8s | %-8s | %-8s | %-8s | %-10s \n",
           " Matrícula", "N1", "N2", "N3", "MEDIA", "Status");
    printf("-----------|----------|----------|----------|----------|------------\n");

    if (al->status == 0) { // Reprovado
        printf(RED_TEXT);
    }

    printf("%-10d | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10s",
           al->matricula,
           al->n1,
           al->n2,
           al->n3,
           al->media,
           al->status == 1 ? "Aprovado" : "Reprovado");

    if (al->status == 0) {
        printf(RESET_TEXT);
    }
    printf("\n");
}

/**
 * @brief Limpa o buffer de entrada.
 *
 * Esta função descarta todos os caracteres restantes no buffer de entrada
 * até encontrar um caractere de nova linha ('\n') ou o fim do arquivo (EOF).
 * É útil para evitar problemas com entradas indesejadas em funções de leitura.
 */
void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}


/**
 * @brief Exibe uma mensagem de erro formatada e aguarda interação do usuário.
 *
 * Esta função limpa o buffer de entrada, limpa a tela do terminal,
 * exibe uma mensagem de erro formatada e aguarda o usuário pressionar
 * a tecla <ENTER> para continuar.
 *
 * @param msg Ponteiro para a string contendo a mensagem de erro a ser exibida.
 * @return Nenhum valor é retornado (função void).
 */
void msg_erro(char *msg){
    limpar_buffer();
    system(LIMPAR_TELA);
    printf("\n----------------Erro------------------------------\n");
    printf("%s", msg);
    printf("----------------------------------------------------\n");
    printf("\nAperte <ENTER> para voltar ao menu principal.");
    getchar();
}
