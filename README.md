<<<<<<< HEAD
<h1><a href="https://github.com/igotbitches/coffee_machine/blob/mikalai/coffee_machine_v.1.2.cpp">Файл [coffee_machine_v.1.2.cpp]</a></h1>


<ol type="a">
<li>убрал надпись <i>Main Menu</i> из функции <code>mainMenu()</code> Можем снова добавить, если посчитаешь нужным. Просто надпись посередине экрана. Совсем не вяжется с остальным меню.</li>

```c++
cout << "\t\t\tMain Menu" << endl;
cout << endl;
```

<li>переименовал переменные в <code>#define</code> (задал более понятные определения,
наименования теперь только из заглавных букв)</li>

```c++
#define TEN_COINS 0.1
#define TWENTY_COINS 0.2
#define FIFTY_COINS 0.5
#define ONE_RUB 1
#define TWO_RUB 2
```

<li>функция <code>int customerChoose(int &choose)</code> сделал <b>void</b> 
(мы передаем туда значение по ссылке, оно в любом случае меняется, 
даже если мы его не возвращаем) и переименовал в <code>choiceMenu()</code>, 
т.к. у нас там небольшая менюшка, по сути</li>

```c++
void choiceMenu(int &choose);
```

<li>убрал в функциях <code>serviceMenu()</code> и <code>mainMenu()</code> передачу аргументов
по ссылке. По тем же причинам, что и выше. В этих функциях нам не нужно менять переменные.</li>

<li>по максимуму сделал программму без <code>goto</code>. Штука хорошая, 
но существенно код она нам не сократила, а понять, что твориться в коде было сложнее, 
поэтому постарался от неё избававиться. Пригодилась она, конечно, 
когда нужно было закрыть остальыне пункты меню.</li>

<li>при вводе цифры не от 1 до 5 программа <em><b>вылетает</b></em> и больше не возвращает mainMenu()</li>

```text
Этот пункт исправлен. Сделал программу практически полностью без goto.
goto оставл только при перенаправлении в сервис. Ты увидишь.
```





</ol>


=======
# coffee_machine
Будем здесь делать пометки, чтобы было удобнее вспоминать, что нужно ещё. \
Нужно будет добавить: 

`progress bar` \
`отступы (чтобы не сливался текст и меню)` 

Крутая штука - `goto`. Не знал о таком.
>>>>>>> Artur2
