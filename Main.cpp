#include <iostream>
#include <string>
#include <vector>

#define ENCRYPT 0
#define DECRYPT 1

int charToInt(char number) {
    return number -= 48;
}

bool strToUpperCase(std::string& text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 97 && 122 >= text[i])
            text[i] -= 32;
    }

    return EXIT_SUCCESS;
}

std::string changeText(std::string text, std::string key, int type = ENCRYPT) {
    if (EXIT_SUCCESS != strToUpperCase(text)) {
        return text;
    }

    for (int i = 0; i < text.size(); i++) {
        key += key[i];
    }

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            continue;
        }

        switch (type) {
        case ENCRYPT: {
            text[i] += charToInt(key[i]);

            if (text[i] >= 91) {
                text[i] -= 26;
            }
            break;
        }
        case DECRYPT: {
            text[i] -= charToInt(key[i]);

            if (text[i] <= 64) {
                text[i] += 26;
            }
            break;
        }

        }
    }

    return text;
}

int main() {
    std::string text = "Hidden message";
    std::string key = "892305";

    std::cout << "Source text: " << text << "\n";
    std::cout << "Source Key: " << key << "\n";

    text = changeText(text, key, ENCRYPT);
    std::cout << "Encrypted text: " << text << "\n";

    text = changeText(text, key, DECRYPT);
    std::cout << "Decrypted text: " << text << "\n";

    return EXIT_SUCCESS;
}

/*
Розробити програму, яка могла би зашифровувати і розшифровувати текст за
допомогою шифра Гронсвельда.
*/
