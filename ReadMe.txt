https://www.youtube.com/watch?v=keX4ivr9Ytc&list=PLeqyOOqxeiINBBW5KUmcf-M4_wfb4yqKp&index=1&t=205s
https://github.com/okovtun/VBU_022_CPP

TOREAD:
http://cplusplus.com/reference/regex/
https://www.boost.org/
https://www.qt.io/ - Разработка кроссплатформенных приложений на C++
https://doc.qt.io/qt-5/gettingstarted.html#create-your-first-applications
https://doc.qt.io/qt-5/qtwidgets-tutorials-notepad-example.html
https://doc.qt.io/qt-5/qtdoc-tutorials-alarms-example.html
https://hh.ru/vacancy/42462084?query=C%20%20
https://hh.ru/vacancy/43394134?query=C%20%20
https://hh.ru/vacancy/42462084?query=C%20%20
https://hh.ru/vacancy/43824819?query=C%20%20
https://hh.ru/vacancy/42482001?query=C%20%20
https://hh.ru/vacancy/43964782?query=C%20%20

GameDev:
https://www.unrealengine.com/en-US/
OpenGL/DirectX

TODO:
ГИБДД:
-номера автомобилей можно проверять по регулярным выражениям;
-базу можно сохранять в CSV-файл, и загружать ее из файла при запуске программы;
						CSV-Comma Separated Values
	BI 3244 ВА, ...(номер статьи), DD.MM.YYYY;

DONE:
В BinaryTree добавить:
CopyAssignment();
ILconstructor;	//Tree t = {3, 5, ....};
erase(int Data);//Удаляет заданное значение из дерева
Шаблонизировать дерево.

DONE:
В класс List, добавить методы:
void erase(int index);	//Удаляет элемент по индексу
CopyMethods();
MoveMethods();
operator+();
Iterator;		DONE
ReverseIterator;//Методы rbegin() и rend() должны возращать ReverseIterator
Создать ветку templated и в ней шаблонизировать классы List и ForwardList.

DONE:
В класс List добавить методы:
void pop_front();	//Удаляет начальный элемент списка	DONE
void pop_back();	//Удаляет последний элемент списка	DONE
void erase(int index);	//Удаляет значение из списка по указанному индексу
void Sort();		//Сортировка списка;

CopyMethods: CopyConstructor; CopyAssignment (=);
MoveMethods: MoveConstructor; MoveAssignment;
operator+ - выполняет конкатенацию двух списков;
Конструктор на заданное число элементов; 	DONE
operator[];					DONE

//Этот проверочный код должен заработать
List list = {3,5,8,13,21};			DONE
for(int i:list)			DONE
	cout << i << tab;
cout << endl;
///////////////////////////////////////////////////////////////

TOREAD:
http://cplusplus.com/doc/tutorial/inheritance/
http://cplusplus.com/doc/tutorial/polymorphism/

DONE:
1. Реализовать фигуры: Квадрат, Прямоугольник, Треугольник, Круг.
У каждой фигуры есть цвет, площадь и периметр, и особые свойства конкретной фигуры.
Сгенерировать фигуры случайным образом, и вывести на экран их свойства, и нарисовать эти фигуры.
2. В проект Academy добавить фильтрацию данных в set-методы.

DONE:
1. Реализовать класс Binary, описывающий двоичное число, обеспечить арифметические (+, -, *, /) и побитовые    (& AND, | OR, ~ NOT, ^ XOR) операции над двоичными числами. Двоичное число можно инициализировать десятичным числом, или ввести с клавиатуры. Нужны только целые двоичные числа.

DONE:
В класс String добавить опрераторы =, +, +=, [], а так же MoveConstructor и MoveAssignment.
http://cplusplus.com/doc/tutorial/classes2/

DONE:
1. В класс Fraction добавить методы: DONE
	to_proper() - преобразует неправильную дробь в правильную;
	to_improper()-преобразует правильную дробь в неправильную;
	reduce() - сокращает дробь; https://www.webmath.ru/poleznoe/formules_12_7.php
2. Для класса Fraction перегрузить операторы 
	+, -, *, /;
	+=, -=, *=, /=;
	==, !=, >, <, >=, <=;
3. Перегрузить оператор >> для ввода дробей с клавиатуры.


DONE:
1. В классе Point реализовать метод distance, который вычисляет расстояние до указанной точки;
2. Написать функцию distance, которая вычисляет расстояние между двумя точками;
3. Реализовать класс Fraction, описывающий простую дробь. В классе нужно обеспечить инкапсуляцию, и создание дробей самыми разными способами;
4. *Реализовать класс String, описывающий строку. В классе должна быть реализована инкапсуляция, и создание объектов самыми разными способами.