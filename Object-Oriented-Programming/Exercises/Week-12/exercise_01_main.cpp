// Да се разработи система за обработка на данни от IoT сензори за 
// температура и влажност.

// Да се реализира клас Sensor, който описва данни за сензор и валидира 
// своето състояние. Всеки сензор е във формат:

// <ID>;<timestamp>;<temperature>;<humidity>
// Където:

// ID е низ от латински букви и цифри с дължина между 4 и 8 символа;
// timestamp е във формат YYYY-MM-DD HH:MM:SS;
// temperature е число в интервала [-50.0, 100.0];
// humidity е цяло число в интервала [0, 100].
// Да се реализират следните custom exception класове:

// InvalidSensorIdException
// InvalidTimestampException
// InvalidTemperatureException
// InvalidHumidityException
// FileOpenException
// Класът Sensor трябва:

// да валидира своите данни;
// при невалидни стойности да хвърля подходящ exception;
// да предефинира операторите >> и <<.
// Данните за сензорите ще се четат от файл sensorReadings.txt, като за 
// целта трябва да се резлизира допълнителен клас SensorManager, който да 
// съхранява и обработва данните. При обработка:

// валидните данни да се записват във файл processedReadings.txt;
// невалидните редове да се записват във файл invalidReadings.log заедно 
// със съответното съобщение за грешка.
// При възникване на грешка програмата не трябва да прекратява работа, а 
// да продължава обработката на следващите редове.
#include <iostream>
#include "exercise_01_sensor_manager.h"
#include "exercise_01_file_exception.h"

int main() {
    SensorManager manager;

    try {
        manager.process("sensorReadings.txt", "processedReadings.txt",
            "invalidReadings.log");
    }
    catch (const FileOpenException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "===== valid sensors =====" << std::endl;
    manager.display();

    return 0;
}
