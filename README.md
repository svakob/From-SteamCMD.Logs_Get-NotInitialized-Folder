## From-SteamCMD.Logs_Get-NotInitialized-Folder

## English

This is a simple but useful program that will help you find a missing folder in a directory.

I use this program to get missing folders/mods uploaded to SteamCMD. Sometimes I might remove one important mod for RimWorld. To find this mod I wrote this simple program.

> Important: this program works with folders named only by numerical names.

### How to use.

This program needs several input parameters to work. Before using, you need to replace [PathToDir] with the path to the directory where the folders you want to check are located. You can also replace "workshop_log.txt" with the path to the log file or something else.

> Important: The log file must contain the numeric names of the folders you will check for.

" [AppID 294100] Download item " is a key excerpt from the file after which the numerical name of the folder will be searched.

> Important: after the key string to the name of the folder, there should not be any character other than numbers.

##### If a missing file is found, the name of the missing folder will be displayed in the console.

##### If all folders/mods are present, "oll good" will be displayed

### How it works

1. The program receives all folder names in the directory regardless of which one.
2. The program parses and receives an array with numeric folder names "without repetitions".
3. The program compares the logs with the folders and outputs the information to the console.

## Українська

Це проста, но корисна програма, яка допоможе знайти відсутню папку в дерикторії.

Я використовую цю програму для отримання відсутніх папок/модів завантажених в SteamCMD. Інколи я можу видалити один важливий модів для RimWorld. Щоб знайти цей мод я написав цю просту програму.

> Важливо: ця програма працює з папками які називаються тільки циферовими назвами.

### Як використовувати.

Цій програмі необхідні декілька вхідних параметрів для роботи. Перед використанням потрібно замінити [PathToDir] на шлях до дерикторії, де знаходяться папки, які потрібно перевірити. Також можна замінити "workshop_log.txt" на шлях до файлу логів чи інший.

> Важливо: у файлі логів повинні міститися цифрові назви папок, які ви будете перевіряти на наявність.

" [AppID 294100] Download item " - це ключовий уривок з файлу після якого буде шукатись номерова назва папки.

> Важливо: після ключового рядка до назви папки немає бути жодного іншого символа окрім цифер.

##### У випадку знаходження відсутнього файлу - в консоль виведеться назва папки, якої немає.

##### Якщо всі папки/моди присутні виведеться "oll good"

### Як працює

1. Програма отримує всі назви папок в дерикторії незалежно яка.
2. Програма парсить, та отримує масив з циферними назвами папок "без повторень".
3. Програма звіряє логи з папками та виводить інформацю в консоль.
