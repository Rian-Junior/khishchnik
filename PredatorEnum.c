#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#define DARKORANGE "\033[38;5;214m"

void exibir_ajuda(char *programa) {
    printf(GREEN"Use: %s [options]\n\n"RESET, programa);
    printf("Opções:\n");
    printf("  -u            | Listar os usuários do sistema.\n");
    printf("  -h            | Exibir esta mensagem de ajuda.\n");
    printf("  -suid          | Listar arquivos com permissão SUID.\n");
    printf("  -gsuid         | Listar arquivos com permissão G-SUID.\n");
    printf("  -ip           | Listar as interfaces de IP do sistema.\n");
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
    printf(RED"@Autor:"RESET " Rian Júnior. " CYAN"@Instagram:"RESET "_rian.jr\n\n");


    printf(CYAN"GitHub:"RESET " github.com/Rian-Junior\n");
    printf(CYAN"colab:"RESET " AlcaTech Security\n\n");
}

void listar_interfaces_ip() {
    struct ifaddrs *interfaces, *ifa;
    char ip_buffer[INET6_ADDRSTRLEN];

    if (getifaddrs(&interfaces) == -1) {
        perror("Erro ao obter as interfaces de rede");
        return;
    }

    printf(GREEN"Interfaces de rede e seus IPs:\n"RESET);
    printf("+-------------------+-------------------+\n");

    for (ifa = interfaces; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family == AF_INET) {
            void *addr_ptr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, addr_ptr, ip_buffer, sizeof(ip_buffer));
            printf("| %-17s | %-15s |\n", ifa->ifa_name, ip_buffer);
        } else if (ifa->ifa_addr->sa_family == AF_INET6) {
            void *addr_ptr = &((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            inet_ntop(AF_INET6, addr_ptr, ip_buffer, sizeof(ip_buffer));
            printf("| %-17s | %-15s |\n", ifa->ifa_name, ip_buffer);
        }
    }

    printf("+-------------------+-------------------+\n");

    freeifaddrs(interfaces);
}

void listar_usuarios() {
    FILE *file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        perror("Erro ao abrir /etc/passwd");
        exit(1);
    }

    printf(GREEN"Usuários disponíveis no sistema:\n"RESET);
    printf("+----------------------+\n");

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        char *usuario = strtok(linha, ":");
        printf("| %-20s |\n", usuario);
    }

    printf("+----------------------+\n");

    fclose(file);
}

// Função para listar arquivos com permissão SUID
void listar_suid() {
    printf(GREEN"[+]"RESET" Arquivos com permissão SUID no sistema:\n");
    system("find / -type f -perm /4000 2>/dev/null");
    printf("\n");
}

// Função para listar arquivos com permissão G-SUID
void listar_gsuid() {
    printf(GREEN"[+]"RESET" Arquivos com permissão G-SUID no sistema:\n");
    system("find / -type f -perm /2000 2>/dev/null");
    printf("\n");
}

int main(int argc, char *argv[]) {
    int remove_banner = 0;
    const char *banner_flag_file = "/tmp/.banner_shown";

    // Processa os parâmetros para o comando
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            exibir_ajuda(argv[0]);
            return 0;
        }
        if (strcmp(argv[i], "--remove-banner") == 0) {
            remove_banner = 1;
        }
        if (strcmp(argv[i], "--show-banner") == 0) {
            banner();
            return 0;
        }
    }

    if (argc < 2) {
        printf(RED"Use:"RESET " %s -h (para exibir o menu de ajuda)\n", argv[0]);
        return 1;
    }

    // Verifica se o banner já foi exibido
    FILE *file = fopen(banner_flag_file, "r");
    if (!file && !remove_banner) {
        banner();
        file = fopen(banner_flag_file, "w");
        fclose(file);
    }

    // Executa as funções correspondentes aos parâmetros passados
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0) {
            listar_usuarios();
        }
        else if (strcmp(argv[i], "-ip") == 0) {
            listar_interfaces_ip();
        }
        else if (strcmp(argv[i], "-suid") == 0) {
            listar_suid();
        }
        else if (strcmp(argv[i], "-gsuid") == 0) {
            listar_gsuid();
        }
    }

    return 0;
}
