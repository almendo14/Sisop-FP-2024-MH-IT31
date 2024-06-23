#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_register(const char *username) {
    char message[128]; // Menyesuaikan ukuran buffer dengan kebutuhan

    // Menggunakan snprintf untuk memastikan tidak ada overflow
    snprintf(message, sizeof(message), "%s berhasil register\n", username);
    message[sizeof(message) - 1] = '\0'; // Memastikan string terakhiri dengan null-terminator

    // Output pesan
    printf("%s", message);
}

void handle_login(const char *username) {
    char message[128]; // Menyesuaikan ukuran buffer dengan kebutuhan

    // Menggunakan snprintf untuk memastikan tidak ada overflow
    snprintf(message, sizeof(message), "%s berhasil login\n", username);
    message[sizeof(message) - 1] = '\0'; // Memastikan string terakhiri dengan null-terminator

    // Output pesan
    printf("%s", message);
}

int main() {
    char username[256]; // Misalnya, panjang username maksimal 255 karakter

    printf("Masukkan username: ");
    scanf("%s", username);

    handle_register(username);
    handle_login(username);

    return 0;
}

