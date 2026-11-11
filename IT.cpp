#include <iostream>
#include <iomanip>

int main() {

    setlocale(0, "");

    // диапазон мощности генератора
    const double P_MIN = 0.0;
    const double P_MAX = 5000.0;

    std::cout << "=============================================" << std::endl;
    std::cout << "  ЭНЕРГОСЕТЬ КИБЕРПАНКА // MONITORING NODE   " << std::endl;
    std::cout << "=============================================" << std::endl;

    double g1 = 0.0, g2 = 0.0, g3 = 0.0;


    std::cout << "Введите мощность генератора #1 (МВт): ";
    std::cin >> g1;
    if (std::cin.fail()) {
        std::cout << std::endl << "ОШИБКА Некорректный ввод: ожидалось число." << std::endl;
        return 1;
    }

    std::cout << "Введите мощность генератора #2 (МВт): ";
    std::cin >> g2;
    if (std::cin.fail()) {
        std::cout << std::endl << "ОШИБКА Некорректный ввод: ожидалось число." << std::endl;
        return 1;
    }

    std::cout << "Введите мощность генератора #3 (МВт): ";
    std::cin >> g3;
    if (std::cin.fail()) {
        std::cout << std::endl << "ОШИБКА Некорректный ввод: ожидалось число." << std::endl;
        return 1;
    }
    //Проверка диапазона
    if (g1 < P_MIN || g1 > P_MAX || g2 < P_MIN || g2 > P_MAX || g3 < P_MIN || g3 > P_MAX) {
        std::cout << std::endl << "ОШИБКА Мощность вне допустимого диапазона ("
            << P_MIN << "-" << P_MAX << " МВт). Мониторинг прерван." << std::endl;
        return 1;
    }

    // Расчет среднего потребления 
    double avg = (g1 + g2 + g3) / 3.0;

    std::cout << std::endl << "--- ПРОТОКОЛ МОНИТОРИНГА РАЙОНА ---" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Генератор #1: " << g1 << " МВт" << std::endl;
    std::cout << "Генератор #2: " << g2 << " МВт" << std::endl;
    std::cout << "Генератор #3: " << g3 << " МВт" << std::endl;
    std::cout << "Среднее потребление района: " << avg << " МВт" << std::endl;

    // Поиск с критически низким уровнем
    int criticalCount = 0;
    int firstCritical = 0;

    if (g1 < avg) {
        std::cout << "[ALERT] Генератор #1: выработка ниже среднего района (" << g1 << " МВт)" << std::endl;
        criticalCount = criticalCount + 1;
        if (firstCritical == 0) {
            firstCritical = 1;
        }
    }
    if (g2 < avg) {
        std::cout << "[ALERT] Генератор #2: выработка ниже среднего района (" << g2 << " МВт)" << std::endl;
        criticalCount = criticalCount + 1;
        if (firstCritical == 0) {
            firstCritical = 2;
        }
    }
    if (g3 < avg) {
        std::cout << "[ALERT] Генератор #3: выработка ниже среднего района (" << g3 << " МВт)" << std::endl;
        criticalCount = criticalCount + 1;
        if (firstCritical == 0) {
            firstCritical = 3;
        }
    }


    if (criticalCount == 0) {
        std::cout << std::endl << "[СТАТУС] Критических отклонений не обнаружено." << std::endl;
        std::cout << "Все генераторы держат нагрузку. Неон города в безопасности." << std::endl;
    }
    else {
        std::cout << std::endl << "[СТАТУС] Обнаружено критических генераторов: " << criticalCount << std::endl;
        std::cout << "Приоритетная диагностика: генератор #" << firstCritical << "." << std::endl;
        std::cout << "Требуется перераспределение нагрузки по районам." << std::endl;
    }

    std::cout << "=============================================" << std::endl;
    return 0;
}