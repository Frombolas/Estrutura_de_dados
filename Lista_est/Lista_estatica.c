#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario{
    char nome[50];
    int id;
    char setor[50];
    float salario;
};

struct Funcionario vetor_funcionario[3];
int numFuncionarios = 0;

void adicionarFuncionario(){
    if(numFuncionarios < 3){
        struct Funcionario novoFuncionario;
        fflush(stdin);
        printf("\nDigite o nome do funcionario: ");
        scanf("%[^\n]s", novoFuncionario.nome);
        fflush(stdin);
        printf("\nDigite o ID do funcionario: ");
        scanf("%d", &novoFuncionario.id);
        fflush(stdin);
        printf("\nDigite o setor do funcionario: ");
        scanf("%[^\n]s", novoFuncionario.setor);
        fflush(stdin);
        printf("\nDigite o salario do funcionario: ");
        scanf("%f", &novoFuncionario.salario);
        
        vetor_funcionario[numFuncionarios++] = novoFuncionario;
        printf("Funcionario adicionado!");
    }else{
        printf("Limite de funcionarios!");
    }
}

void removerFuncionario(){
    int id;
    printf("\nDigite o ID do funcionario: ");
    scanf("%d", &id);
    int i,j;
    for(i = 0; i < numFuncionarios; i++){
        if(vetor_funcionario[i].id == id){
            for(j = i; j < numFuncionarios - 1; j++){
                vetor_funcionario[j] = vetor_funcionario[j+1];
            }
            numFuncionarios--;
        }
        else{
            printf("Funcionario nao encontrado!\n ");
        }
    }

}

void mostrarTodosFuncionarios(){
    int i;
    if (numFuncionarios <= 0){
        printf("Nao ha funcionarios cadastrado");
    }else{
        for(i = 0; i < numFuncionarios; i++){
            printf("Nome: %s \nID: %d\nSetor: %s\nSalario: %.2f\n", vetor_funcionario[i].nome, vetor_funcionario[i].id, vetor_funcionario[i].setor, vetor_funcionario[i].salario);
            
        }
    }
}
void buscarFuncionario(){
    int id;
    printf("\nDigite o ID do funcionario: ");
    scanf("%d",&id);
    int i;
    for(i = 0; i < numFuncionarios; i++){
        if(vetor_funcionario[i].id == id){
            printf("Nome: %s \nID: %d\nSetor: %s\nSalario: %.2f\n", vetor_funcionario[i].nome, vetor_funcionario[i].id, vetor_funcionario[i].setor, vetor_funcionario[i].salario);
        }else{
            printf("\nFuncionario nao encontrado! ");
        }
    }
    
}

void save(){
    int k;
    FILE *file;
    file = fopen("funcionarios.csv", "w");

    for(k = 0; k < numFuncionarios; k++){
        fprintf(file, "%s,%d,%s,%.2f\n", vetor_funcionario[k].nome, vetor_funcionario[k].id, vetor_funcionario[k].setor, vetor_funcionario[k].salario);
    }
    fclose(file);
}

void arquivoTotal(){
    FILE *file;
    file = fopen("funcionarios.csv", "r");
    numFuncionarios = 0;

    while (fscanf(file, "%49[^,], %d, %49[^,], %f\n", vetor_funcionario[numFuncionarios].nome, &vetor_funcionario[numFuncionarios].id,
                vetor_funcionario[numFuncionarios].setor, &vetor_funcionario[numFuncionarios].salario) == 4 && file != NULL) {
            numFuncionarios++;
    }
    fclose(file);
    mostrarTodosFuncionarios();

}

void main(){
    int opcao;
    arquivoTotal();
    do{
        printf("\n MENU \n");
        printf("1 - Adicionar funcionario \n");
        printf("2 - Mostrar todos funcionario \n");
        printf("3 - Remover funcionario \n");
        printf("4 - Buscar funcionario pelo ID:\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

    switch (opcao){
        case 1: 
            adicionarFuncionario (); 
            break;
        case 2: 
            mostrarTodosFuncionarios (); 
            break;
        case 3: 
            removerFuncionario (); 
            break;
        case 4: 
            buscarFuncionario (); 
            break;
        case 5:
            save(vetor_funcionario);
            printf("Saindo...");
            break;
        default: 
            printf("Opçao invalida");
            break;
    }

    } while (opcao!=5);

}
