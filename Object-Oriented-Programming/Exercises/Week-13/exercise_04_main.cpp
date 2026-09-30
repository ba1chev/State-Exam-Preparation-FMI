// Имплементирайте turn-based RPG игра, която да поддържа различни класове герои 
// с различни бойни механики, йерархия от оръжия с различен начин на изчисляване 
// на damage, и статусни ефекти, които влияят на битката всеки рунд. BattleArena 
// управлява симулацията и трябва да остане напълно "незнаеща" за конкретни 
// типове герои или оръжия.

// Йерархия от изключения
// Дефинирайте базов клас CombatException, наследяващ std::exception. 
// От него изведете две конкретни изключения:

// OutOfManaException - хвърля се, когато Mage се опита да атакува без достатъчно 
// мана. Съобщението от what() трябва да включва името на магьосника и липсващата мана.
// DeadCharacterException - хвърля се, когато се опита каквото и да е действие върху 
// герой с нула HP. Съобщението трябва да включва името на героя.
// DaggerNotRetrievedException - хвърля се, когато Rogue опита да нападне след като 
// е хвърлил ножа си, но не е отишъл да си го вземе
// Йерархия Weapon
// Weapon е абстрактен клас с:

// std::string name
// virtual int roll() const = 0 - връща нанесените щети при един удар
// Имплементирайте три конкретни оръжия:

// Клас - Поведение на roll():

// Sword - Връща фиксирана стойност (напр. винаги 10). Просто и надеждно.
// Staff - Приема параметър maxMana при конструиране. Връща случайна стойност в 
// [1, maxMana / 5].
// Dagger - Връща случайна стойност в [1, 20]. Може и да се хвърля, което 
// увеличава минималния damage 5 пъти, а максималния - 1.5 пъти. 
// Ако е хръвлен, трябва да бъде взет преди отново да се ползва.
// Използвайте следния code snippet за генериране на случайни числа:

// #include <random>

// std::mt19937 engine{std::random_device{}()};  // важно е да се 
// seed-не само веднъж!!
// std::uniform_int_distribution<int> dist{a, b}; // [a, b]

// int roll = dist(engine);
// Йерархия Character
// Character е абстрактен клас с:

// std::string name, int hp, int maxHp
// оръжие
// списък с активни StatusEffect-и
// virtual void attack(Character& target) = 0 и virtual void defend(int incomingDamage) = 0
// Невиртуален void takeDamage(int amount) - извиква defend(), след което прилага резултата;
// bool isDead() const
// Виртуален std::string statusLine() const - едноредово представяне на текущото състояние на 
// героя, напр. "Misho [Warrior] HP: 41/80 - poisoned"
// virtual rest() = 0
// Warrior -> възстановява малко живот
// Mage -> възстановява малко мана
// Rogue -> взима си ножа, ако е бил хвърлен, иначе не прави нищо и продължава текущия ход
// takeDamage трябва да хвърля DeadCharacterException ако героят вече е мъртъв при извикването.

// Имплементирайте три конкретни вида герои:

// Warrior
// int armor (задава се при конструиране)
// attack(): извиква weapon->roll() и прилага резултата върху целта чрез target.takeDamage()
// defend(int incoming): изважда armor от входящите щети преди да ги запише - минимум 0
// Mage
// int mana (текуща) и int maxMana (максимална, задава се при конструиране)
// attack(): струва 10 мана. Ако mana < 10%, хвърля OutOfManaException. Иначе хвърля зара на оръжието 
// и нанася щети. Цената в мана се плаща дори при 1 щета.
// defend(int incoming)
// Rogue
// Допълнително поле: int critChance (1–100, процентна вероятност)
// attack(): хвърля зара на оръжието нормално. После независимо хвърля случайно цяло число в [
// 1, 100] - ако попада в critChance, щетите се удвояват преди прилагане
// defend(int incoming)
// Йерархия StatusEffect
// StatusEffect е абстрактен клас с:

// protected int duration - оставащи рундове (намалява се всеки тик)
// virtual void tick(Character& target) = 0 - прилага ефекта за един рунд
// virtual bool isExpired() const - връща true когато duration <= 0
// Имплементирайте три конкретни ефекта:

// Клас - Поведение на tick():

// Poison - Нанася 5 щети на target всеки рунд. Хваща и игнорира DeadCharacterException.
// Burn - Нанася 8 щети на рунд. Също намалява следващите входящи щети на целта с 3 
// (необходим е начин Character да следи временна редукция на щети).
// Stun - Не нанася щети. Задава флаг на target, който кара attack() да бъде 
// пропуснато за този рунд (героят губи хода си). Флагът се изчиства след като attack() би трябвало да се изпълни.
// За Burn и Stun ще е необходимо да добавите някакво състояние в Character - 
// помислете внимателно какво е най-малкото необходимо допълнение и дали то принадлежи в 
// базовия клас или може да се реши по друг начин.

// BattleArena
// BattleArena притежава два Character указателя и трябва да предоставя:

// void runRound() - един пълен рунд на битката:
// Тикване на всички активни статусни ефекти и на двата героя (извиква tickEffects() вътрешно)
// Герой 0 атакува герой 1 (пропуска се ако е stunned или мъртъв)
// Герой 1 атакува герой 0 (пропуска се ако е stunned или мъртъв)
// Принтира статусен ред за всеки герой след рунда
// Хваща OutOfManaException на ниво атака: принтира съобщението и пропуска тази атака, форсирайки rest()
// Хваща DeadCharacterException на ниво атака: принтира съобщението и прекратява рунда
// void tickEffects() - итерира списъка с ефекти на всеки герой, извиква tick(), след което премахва изтеклите ефекти
// bool isOver() const - връща true ако някой от героите е мъртъв
// void addEffect(int characterIndex, std::unique_ptr<StatusEffect>) - прилага статусен ефект върху един от героите
// main()
// Конструирайте битка, която упражнява всеки код-път:

// Warrior с име "Stoyan", оръжие Sword, armor 15
// Mage с име "Garjo", оръжие Staff, mana 30 (достатъчно ниска, за да свърши по средата на битката)
// Приложете Poison върху Stoyan от самото начало (duration 3 рунда)
// Приложете Stun върху Garjo за рунд 1 (duration 1 рунд)
// Изпълнявайте рундове в цикъл докато isOver() върне true, принтирайки номерата на рундовете
// Принтирайте победителя
// Изходът трябва да демонстрира: stunned герой, пропускащ хода си; отрова, тикваща върху Stoyan; 
// OutOfManaException при Garjo след изразходване на мана; и видима редукция на щети от 
// warrior armor спрямо суровата стойност от roll() (принтирайте и двете числа).
#include <iostream>
#include "exercise_04_sword.h"
#include "exercise_04_staff.h"
#include "exercise_04_warrior.h"
#include "exercise_04_mage.h"
#include "exercise_04_poison.h"
#include "exercise_04_stun.h"
#include "exercise_04_battle_arena.h"

int main() {
    Warrior stoyan("Stoyan", new Sword("Iron Sword"), 15);
    Mage garjo("Garjo", new Staff(30, "Oak Staff"), 30);

    BattleArena arena(&stoyan, &garjo);

    arena.addEffect(0, new Poison(3));
    arena.addEffect(1, new Stun(1));

    int round = 1;
    while (!arena.isOver()) {
        std::cout << "=== Round " << round << " ===" << std::endl;
        arena.runRound();
        std::cout << std::endl;
        round++;
    }

    if (stoyan.isDead()) {
        std::cout << "Winner: " << garjo.getName() << std::endl;
    } else {
        std::cout << "Winner: " << stoyan.getName() << std::endl;
    }

    return 0;
}