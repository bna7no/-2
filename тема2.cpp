#include <iostream>
#include <string>
#include <vector>

// 1. Базовий клас (Інтерфейс алгоритму)
class EncryptionAlgorithm {
public:
    virtual void encrypt(std::string data) {
        std::cout << "[Base] Загальна підготовка даних: " << data << std::endl;
    }
    virtual ~EncryptionAlgorithm() {}
};

// 2. Похідний клас - RSA
class RSAAlgorithm : public EncryptionAlgorithm {
public:
    void encrypt(std::string data) override {
        std::cout << "[RSA] Асиметричне шифрування ключем: " << data << std::endl;
    }
};

// 3. Похідний клас - ElGamal
class ElGamalAlgorithm : public EncryptionAlgorithm {
public:
    void encrypt(std::string data) override {
        std::cout << "[ElGamal] Шифрування через дискретні логарифми: " << data << std::endl;
    }
};

// Функція для Прикладу №2 (передача покажчика *)
void processWithPointer(EncryptionAlgorithm* algo, std::string text) {
    std::cout << "виклик через покажчик *: ";
    algo->encrypt(text);
}

// Клас-менеджер для Прикладу №3 (передача посилання &)
class CryptoManager {
public:
    void execute(EncryptionAlgorithm& algo, std::string message) {
        std::cout << "Виклик у методі через посилання &: ";
        algo.encrypt(message);
    }
};

int main() {
    // Налаштування консолі для коректного відображення (якщо потрібно)
    setlocale(LC_ALL, "Ukrainian");

    // --- Приклад 1: Виклик за покажчиком (->) ---
    std::cout << "--- Приклад 1 ---" << std::endl;
    EncryptionAlgorithm* directPtr = new RSAAlgorithm();
    directPtr->encrypt("Secret_Payload");
    delete directPtr;

    // --- Приклад 2: Три класи + функція з покажчиком (*) ---
    std::cout << "\n--- Приклад 2 ---" << std::endl;
    RSAAlgorithm rsa;
    ElGamalAlgorithm elgamal;
    processWithPointer(&rsa, "Data_1");
    processWithPointer(&elgamal, "Data_2");

    // --- Приклад 3: Три класи + посилання (&) у методі ---
    std::cout << "\n--- Приклад 3 ---" << std::endl;
    CryptoManager manager;
    manager.execute(rsa, "Message_A");
    manager.execute(elgamal, "Message_B");

    return 0;
}