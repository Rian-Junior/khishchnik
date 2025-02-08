#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#define DARKORANGE "\033[38;5;214m"

void exibir_ajuda(char *programa) {
    printf(GREEN"Uso: %s [opções]\n\n"RESET, programa);
    printf("Opções:\n");
    printf("  -u            | Listar os usuários do sistema.\n");
    printf("  -h            | Exibir esta mensagem de ajuda.\n");
    printf("  --remove-banner | Impedir a exibição do banner.\n");
    printf("  --show-banner   | Forçar a exibição do banner.\n");
    printf("\n");
}

void banner() {


    printf(CYAN"\n\n[+]"RESET " Tool under development and analysis!\n"); 
    printf(CYAN"[!]"RESET " This tool automates the reconnaissance steps efficiently! Make sure you have the necessary privileges to execute the tool!\n\n\n");

    printf(GREEN"               ⣠⣶⣾⣿⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣌⠙⣿⣿⣿⣤⣀⣀⣀⣴⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢴⣶⣿⣿⣿⣿⣿⣿⣮⣻⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡛⠛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⢈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⣿⣷⣶⣤⣴⣿⣿⣿⣿⣋⣽⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⣠⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⠟⢋⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡜⠻⣿⣿⣿⣿⣿⣿⣿⣟⣋⣭⣿⣿⣿⣷⣦⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠈⣹⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡶⠶⣤⣀⡀\n");
    printf("⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠈⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢟⣩⣤⣶⣿⣿⣿⣿⣿⣿⣿⣟⢿⣿⣿⣦⣴⣾⣿⡇\n");
    printf("⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡖⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣿⠿⣿⡿⢿⣿⣿⣧⣿⣿⣿⣿⣿⡿⠁\n");
    printf("⠜⠿⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠊⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠉⠀⡁⠀⠘⠀⢹⠁⠀⢹⣿⢿⣿⣿⡟⢻⡿⠀⠀\n");
    printf("⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⡇⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⣿⣿⣿⣋⠁⠀⠀⠉⠉⣸⡤⠤⣀⣸⠀⠀⢸⠁⠀⠉⠈⠀⢸⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣧⣇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⣿⣿⣿⡇⠀⠙⠉⠲⡄⢰⡿⠀⠀⠀⠈⡇⠀⡞⠒⠒⢲⠀⠀⡜⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⡄⠀⠹⠉⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⣿⣿⣿⣷⡀⠀⠀⠀⢸⣽⣧⡀⠀⠀⠀⢸⡼⠁⠀⠀⢸⢀⡴⠁⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡸⣿⣿⣍⠉⠒⢄⠀⠘⣧⣤⡈⠒⡶⣆⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣆⡀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣽⣿⣿⣷⣦⣘⠉⠁⠻⢿⣿⣷⠃⢸⠒⢤⠀⠀⡞⡄⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠸⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣀⣼⠃⠀⢠⣷⣦⣧⡜⠀⢸⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣾⣿⣿⣿⣿⣠⡎⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠈⠉⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠉⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠈⠁⠈⠋⠙⠛⠉⠛⠉⠿⠿⠛⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡿⠁⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣿⠟⠻⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"RESET);
        printf(RED"@Autor:"RESET " Rian Júnior | Tryplex \n\n");

    // github
    printf(CYAN"GitHub:"RESET " github.com/Rian-Junior\n");
    printf(CYAN"colab:"RESET " AlcaTech Security\n\n\n");
}


// Função para listar os usuários do sistema
void listar_usuarios() {
    FILE *file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        printf(RED"[!] Erro ao abrir /etc/passwd\n"RESET);
        exit(1);
    }

    printf(GREEN"Usuários disponiveis no sistema:\n"RESET);
    printf("+----------------------+\n");

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        char *usuario = strtok(linha, ":");
        printf("| %-20s |\n", usuario);
    }

    printf("+----------------------+\n");

    fclose(file);
}

int main(int argc, char *argv[]) {
    int remove_banner = 0;  // Variável para controlar se o banner será exibido
    const char *banner_flag_file = "/tmp/.banner_shown";  // Caminho para o arquivo de controle do banner

    // Loop para processar os argumentos passados na linha de comando
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            exibir_ajuda(argv[0]);
            return 0;
        } 
        if (strcmp(argv[i], "--remove-banner") == 0) {
            remove_banner = 1;  // Marca para não exibir o banner
        }
        if (strcmp(argv[i], "--show-banner") == 0) {
            banner();  // Exibe o banner independentemente de outros parâmetros
        }
    }

    if (argc < 2) {
        printf(RED"Use:"RESET " %s -h (para exibir o menu de ajuda)\n", argv[0]);
        return 1;
    }

    // Verifica se o banner já foi exibido
    FILE *file = fopen(banner_flag_file, "r");
    if (!file && !remove_banner) {
        // Se o arquivo não existir e o --remove-banner não foi passado, exibe o banner
        banner();
        // Cria o arquivo para indicar que o banner foi mostrado
        file = fopen(banner_flag_file, "w");
        fclose(file);
    }

    // Se o parâmetro for -u, lista os usuários
    if (strcmp(argv[1], "-u") == 0) {
        listar_usuarios();
    } else {
        printf(RED"[!]"RESET " Opção inválida. Use -h para ver o menu de ajuda.\n");
    }

    return 0;
}
