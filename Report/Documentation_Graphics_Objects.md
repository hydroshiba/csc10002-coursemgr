# **Documentation**

## **Graphics**

### 1. Constant namespace
(Define in Constant.h)

Contains constants for various elements used in a Course Management System. It includes constants for application, box, button, and text related components.

* **"app_const" namespace**:  the constants are defined for the width, height, and frames per second of the application window. Additionally, the title of the window and the path of the application directory are also defined.

* **"box_const" namespace**: the constants are defined for the width, height, and thickness of the box, as well as the roundness and number of segments for the box corners. The fill and border color of the box are also defined.

* **"button_const" namespace**: the constants are defined for the colors of the button on hover and press.

* **"text_const" namespace**: the constants are defined for the font path, space between lines, size, and color of the text. The padding for the text is also defined.

### 2. Scissor

(Define in Scissor.h and implement in Scissor.cpp)

| Function                                       | Description                                                                                                                                                                                 |
| ---------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `StartScissor(Rectangle rect)`                   | Starts a new scissor rectangle with the given `Rectangle` object. It first checks if there is any previously defined scissor rectangle and modifies the current rectangle to be the intersection of the previous and new rectangle. It then calls the `EndScissorMode()` function from the "raylib.h" library and begins a new scissor mode with the modified rectangle. The rectangle is also pushed onto a stack to keep track of the previous scissor rectangles. |
| `StartScissor(Vector2 pos, Vector2 size)`     | Starts a new scissor rectangle with the given position and size as `Vector2` objects. It creates a new `Rectangle` object with these values and calls the `StartScissor(Rectangle rect)` function. |
| `StartScissor(float x, float y, float width, float height) `| Starts a new scissor rectangle with the given position and size as separate float values. It creates a new `Rectangle` object with these values and calls the `StartScissor(Rectangle rect)` function. |
| `EndScissor()`                                   | Pops the top scissor rectangle off the stack and calls the `EndScissorMode()` function to end the current scissor mode. It then begins a new scissor mode with the previous scissor rectangle on top of the stack, if there is one. |

The source file "Scissor.cpp" defines the scissorStack variable as an external Stack object, which is used to keep track of the current scissor rectangle.

Overall, this Scissor class provides a convenient way to handle scissoring of graphics to a certain area in a 2D graphics program. It also allows for nested scissor rectangles, with the ability to modify the current rectangle to the intersection of the previous and new rectangle.

### 3. Application
(Define in Application.h and implement in Application.cpp)

An `Application` class that serves as the entry point for running the program. The class initializes the window and sets the target frame rate using the Raylib library.


| Attribute / Method                | Description                                                 |
| ------------------- | ----------------------------------------------------------- |
| `- Vector2 mousePoint`| A private member variable representing the current mouse position. |
| `- Scene\* scene`     | A private member variable representing the current scene that the application is rendering. |
| `- void render()`     | A private member function that renders the current scene.   |
| `- void process()`    | A private member function that updates the current scene.   |
| `+ Application()`     | A public constructor that initializes the application window and the scenes. |
| `+ ~Application()`    | A public destructor that cleans up the application window and the scenes. |
| `+ Application(const Application &other) = delete;` | A public copy constructor that is disabled. |
| `+ Application& operator=(const Application &other) = delete;` | A public assignment operator that is disabled. |
| `+ bool shouldClose() const` | A public member function that returns true if the window should close, false otherwise. |
| `+ void run()`         | A public member function that runs the application.          |

## **Graphics / Objects**
(All objects is defined and implemented in directory *Graphics/Objects*)
### 1. Text
(Define in Text.h and implement in Text.cpp)

The `Text` class is a simple class used to create text objects. It contains attributes for the text content, font size, additional space between characters, font, and color. The `Text` object can be initialized using either a C-style string or an `std::string` object. 


| Attribute / Method                  | Description                              | 
| :---------------------------------- | :--------------------------------------- | 
| `+ std::string text`                | The text content of the Text object.      |
| `+ float font_size`                 | The size of the font used in the text.    |
| `+ float space`                     | The additional space between characters. |
| `+ Font font`                       | The font used in the text.                |
| `+ Color color`                     | The color of the text.                    |
| `+ Text()`                          | Default constructor.                      |
| `+ Text(const char* text, float fsize = text_const::size, Font font = LoadFontEx(text_const::font_path.c_str(), 128, 0, 0), float space = text_const::space, Color color = text_const::color)` | Constructor that initializes the Text object with the given values. |
| `+ Text(std::string text, float fsize = text_const::size, Font font = LoadFontEx(text_const::font_path.c_str(), 128, 0, 0), float space = text_const::space, Color color = text_const::color)` | Constructor that initializes the Text object with the given values. |
| `+ void operator=(std::string text)` | Overloaded assignment operator that sets the text content of the Text object to the given string. |
| `+ void operator=(const char* text)` | Overloaded assignment operator that sets the text content of the Text object to the given C-style string. |
| `+ Vector2 size()`                   | Returns a Vector2 containing the width and height of the Text object based on the current font and font size. |


### 2. TextBox
(Define in TextBox.h and implement in TextBox.cpp)

The `TextBox` class represents a text box that can be rendered on the screen using `raylib`. The class provides various methods to set and get properties of the text box, and also to render it on the screen.

| Attribute / Method | Description |
| :----------------- | :---------- |
| - `Vector2 pos` | The position of the top-left corner of the text box |
| - `Text content` | The content of the text box (i.e. the actual text to be displayed) |
| - `Rectangle bound` | The rectangular bounds of the text box (including any padding or border) |
| - `Color color_box` | The color of the text box's background |
| + `TextBox()` | Default constructor that initializes an empty text box with position at the origin and default background color |
| + `TextBox(Text content, Vector2 pos = {0, 0}, Color color_box = box_const::fill_color)` | Constructor that initializes a text box with the specified content, position, and background color |
| + `TextBox(std::string text, Vector2 pos = {0, 0}, Color color_box = box_const::fill_color)` | Constructor that initializes a text box with the specified text string, position, and background color |
| + `TextBox(const char* text, Vector2 pos = {0, 0}, Color color_box = box_const::fill_color)` | Constructor that initializes a text box with the specified text C-string, position, and background color |
| + `TextBox& operator=(Text content)` | Copy assignment operator that sets the content of the text box |
| + `TextBox& operator=(std::string text)` | Copy assignment operator that sets the content of the text box from a string |
| + `TextBox& operator=(const char* text)` | Copy assignment operator that sets the content of the text box from a C-string |
| + `TextBox& operator + (const std::string& text)` | Concatenation operator that appends a string to the content of the text box |
| + `void setContent(const std::string& content)` | Sets the content of the text box from a string |
| + `void setContent(const Text& content)` | Sets the content of the text box from a `Text` object |
| + `std::string& getContent()` | Returns a reference to the content of the text box |
| + `void setX(float x)` | Sets the x-coordinate of the position of the text box |
| + `void setY(float y)` | Sets the y-coordinate of the position of the text box |
| + `void setPos(Vector2 pos)` | Sets the position of the text box |
| + `Vector2 getPos()` | Returns the position of the text box |
| + `void centerX()` | Centers the text box horizontally on the screen |
| + `void centerY()` | Centers the text box vertically on the screen |
| + `void setSize(float size)` | Sets the font size of the text box |
| + `void setColor(Color color)` | Sets the background color of the text box |
| + `void render()` | Renders the text box on the screen |
| + `void clear()` | Clears the content of the text box | 

### 3. InputBox
(Define in InputBox.h and implement in InputBox.cpp)

The `InputBox` class provides a customizable input box to get text input from users. It contains several properties such as the text content, position, size, border and fill colors. It also supports several input events such as hovering and clicking.


|    Attribute/Method   |          Description         |
|-----------------------|-------------------------------|
| `+defaultText: Text`   | The default text displayed inside the InputBox |
| `+content: Text`       | The text content of the InputBox |
| `+fill_color: Color`   | The color of the fill inside the InputBox |
| `+border_color: Color` | The color of the border of the InputBox |
| `+hover_color: Color`  | The color of the InputBox when the mouse is hovering over it |
| `+press_color: Color`  | The color of the InputBox when it is being clicked |
| `+pos: Vector2`        | The position of the InputBox |
| `+size: Vector2`       | The size of the InputBox |
| `+selected: bool`      | A flag indicating whether the InputBox is currently selected by the user |
| `+frameCount: int`     | The frame count since the creation of the InputBox |
| `+refreshText(): void` | Recalculates the size and position of the text displayed inside the InputBox |
| `+refresh(): void`     | Recalculates the position and size of the InputBox |
| `+InputBox() `         | Constructs an InputBox with default values |
| `+InputBox(x: float, y: float, width: float, height: float, text: string, fill: Color, hover: Color, press: Color, border: Color)` | Constructs an InputBox with the given parameters |
| `+InputBox(pos: Vector2, size: Vector2, text: string, fill: Color, hover: Color, press: Color, border: Color)` | Constructs an InputBox with the given parameters |
| `+render(mouse: Vector2): void` | Renders the InputBox |
| `+process(mouse: Vector2): void` | Processes input events for the InputBox |
| `+setX(x: float): void` | Sets the x position of the InputBox |
| `+setY(y: float): void` | Sets the y position of the InputBox |
| `+setWidth(width: float): void` | Sets the width of the InputBox |
| `+setHeight(height: float): void` | Sets the height of the InputBox |
| `+setPos(pos: Vector2): void` | Sets the position of the InputBox |
| `+setSize(size: Vector2): void` | Sets the size of the InputBox |
| `+getPos(): Vector2` | Returns the position of the InputBox |
| `+getSize(): Vector2` | Returns the size of the InputBox |
| `+clearContent(): void` | Clears the text content of the InputBox |
| `+centerX(): void` | Centers the InputBox horizontally |
| `+centerY(): void` | Centers the InputBox vertically |
| `+getContent(): string` | Returns the text content of the InputBox |
| `+clicked(mouse: Vector2): bool` | Returns `true` if the InputBox was clicked |
| `+pressed(mouse: Vector2): bool` | Returns `true` if the InputBox was being clicked |
| `+hovering(mouse: Vector2): bool` | Returns `true` if the mouse is hovering over the InputBox

### 4. Button
(Define in Button.h and implement in Button.cpp)

The `Button` class is used to create clickable buttons in graphical user interface (GUI) applications. The class is defined in the `Button.h` header file and implemented in the `Button.cpp` source file. 

The `Button` class inherits from the `Text` class, which represents a block of text that can be rendered on the screen. It has a `label` property that stores the text to be displayed on the button, and it can adjust the font size of the text to fit inside the button's bounds.

| Attribute / Method| Description                                                      |
| ----- |---------------- |
| `- Vector2 pos`| The position of the button.|
| `- Vector2 size`| The size of the button.|
| `- Vector2 textPos` | The position of the text label inside the button.   |
| `- Rectangle border_bound`   | The bounding rectangle of the button's border.                   |
| `- Rectangle fill_bound`                                                                                                                                                                                                                                                           | The bounding rectangle of the button's fill.                     |
| `- Rectangle text_bound`                                                                                                                                                                                                                                                           | The bounding rectangle of the button's text.                     |
| `- virtual void refreshText()`                                                                                                                                                                                                                                                       | Calculates the font size and position of the text label.         |
| `- virtual void refresh()`                                                                                                                                                                                                                                                           | Calculates the bounding rectangles of the button.                |
| `+ Text label`                                                                                                                                                                                                                                                                       | The text label to be displayed on the button.                    |
| `+ float roundness`                                                                                                                                                                                                                                                                  | The roundness of the button's corners.                           |
| `+ Color fill_color`                                                                                                                                                                                                                                                                 | The fill color of the button.                                    |
| `+ Color border_color`                                                                                                                                                                                                                                                               | The border color of the button.                                  |
| `+ Color hover_color`                                                                                                                                                                                                                                                                | The fill color of the button when the mouse is hovering over it. |
| `+ Color press_color`                                                                                                                                                                                                                                                                | The fill color of the button when it is being pressed.           |
| `+ Button()`                                                                                                                                                                                                                                                                         | Constructor for an empty button with default properties.     |
| `+ Button(float x, float y, float width, float height, std::string text = "", float roundness = box_const::roundness, Color fill = box_const::fill_color, Color hover = button_const::hover_color, Color press = button_const::press_color, Color border = box_const::border_color)` | Constructor for a button with custom properties.             |
| `+ Button(Vector2 pos, Vector2 size, std::string text = "", float roundness = box_const::roundness, Color fill = box_const::fill_color, Color hover = button_const::hover_color, Color press = button_const::press_color, Color border = box_const::border_color)` | Constructor for a button with custom properties.             |
| `+ virtual void render(const Vector2 &mouse) const` | Renders the button on the screen.                             |
| `+ void setX(float x)`         | Sets the x-coordinate of the button's position.              |
| `+ void setY(float y)`         | Sets the y-coordinate of the button's position.              |
| `+ void setWidth(float width)` | Sets the width of the button.                                 |
| `+ void setHeight(float height)` | Sets the height of the button.                             |
| `+ void setPos(Vector2 pos)`   | Sets the position of the button.                              |
| `+ void setSize(Vector2 size)` | Sets the size of the button.                                  |
| `+ Vector2 getPos()`           | Gets the position of the button.
| `+ Rectangle getRec()`| Gets the rectangle of the button.
| `+ void setViewColor()`| Sets color of the button.
| `+ void setRemoveColor()`| Sets color of the button.
| `+ void setInsertColor()`| Sets color of the button.
| `+ centerX(): void` | Centers the Button horizontally |
| `+ centerY(): void` | Centers the Button vertically |
| `+ clicked(mouse: Vector2): bool` | Returns `true` if the Button was clicked. |
| `+ pressed(mouse: Vector2): bool` | Returns `true` if the Button was being clicked. |
| `+ hovering(mouse: Vector2): bool` | Returns `true` if the mouse is hovering over the Button.

### 5.1 Option
(Define in Option.h and implement in Option.cpp)

This class `Option` extends the `Button` class and includes the `Scissor` and `raylib` libraries. It is used to create an option that can be clicked and interacted with. It has protected attributes for the left and right padding of the option, and public methods for getting these values, refreshing the text and bounds of the option, and rendering the option.


Attribute / Method | Description
--- | ---
`# float right_padding` | Right padding of the option.
`# float left_padding` | Left padding of the option, default is `text_const::padding`.
`# void refreshText()` | Refreshes the text size and position of the label.
`# void refresh()` | Refreshes the bounds and text of the option.
`+ float getLeftPad()` | Returns the left padding of the option.
`+ float getRightPad()` | Returns the right padding of the option.
`+ void render(const Vector2 &mouse) const` | Renders the option with the given mouse position.

### 5.2 Equilateral
(Define in Equilareral.h and implement in Equilateral.cpp)

The `Equilateral` class represents an equilateral triangle with a specified center, side length, angle, and color.

| Attribute/Method         | Description                                                                  |
|--------------------------|------------------------------------------------------------------------------|             
| - `float rootInv3`        | A constant float value equal to the inverse square root of 3.               |
| `public`                  |                                                                              |
| + `Vector2 center`        | The center point of the equilateral triangle.                                |
| + `float length`          | The length of one side of the equilateral triangle.                           |
| + `float angle`           | The angle of rotation of the equilateral triangle in degrees.                 |
| + `Color color`           | The color of the equilateral triangle.                                       |
| + `Equilateral()`         | The default constructor of the Equilateral class, which initializes all attributes to their default values. |
| + `Equilateral(Vector2 center, float length, float angle, Color color)` | The constructor of the Equilateral class, which initializes the attributes with the given values. |
| + `void render()`         | A method to render the equilateral triangle on the screen. It uses the raylib library's `DrawTriangle()` function to draw the triangle on the screen. |

### 5.3 Scrollbar
(Define in Scrollbar.h and implement in Scrollbar.cpp)

The `Scrollbar` class represents a user interface component that allows scrolling through a large content area that doesn't fit within a smaller window.

| Attribute / Method | Description |
| --- | --- |
| - `Vector2 pos` | The position of the scrollbar. |
| - `Vector2 cur_pos` | The current position of the scrollbar. |
| - `Vector2 last_mouse` | The position of the mouse during the last update. |
| - `float len` | The length of the scrollbar. |
| - `bool pressing` | A boolean value indicating whether the scrollbar is currently being pressed. |
| + `float pos_min` | The minimum position value for the scrollbar. |
| + `float pos_max` | The maximum position value for the scrollbar. |
| + `float thickness` | The thickness of the scrollbar. |
| + `float content_len` | The length of the content to be scrolled through. |
| + `float content_max_len` | The maximum length of the content to be scrolled through. |
| + `Color fill` | The color of the scrollbar. |
| + `Color press` | The color of the scrollbar when it is being pressed. |
| + `bool horizontal` | A boolean value indicating whether the scrollbar is horizontal. |
| + `Scrollbar()` | Default constructor for the Scrollbar class. |
| + `Scrollbar(Vector2 pos, float pos_min, float pos_max, float content_len, float content_max_len, float thickness, bool horizontal, Color fill, Color press)` | Constructor for the Scrollbar class. |
| + `Rectangle getRect()` | Returns a rectangle representing the current position and size of the scrollbar. |
| + `void setPos(Vector2 newPos)` | Sets the position of the scrollbar. |
| + `float content_height()` | Returns the height of the content that can be displayed by the scrollbar. |
| + `bool clicked(const Vector2 &mouse)` | Returns true if the scrollbar has been clicked by the mouse. |
| + `bool pressed(const Vector2 &mouse)` | Returns true if the scrollbar is currently being pressed by the mouse. |
| + `bool currentlyPressed(const Vector2 &mouse)` | Returns true if the scrollbar is currently being pressed. |
| + `void render(const Vector2 &mouse)` | Renders the scrollbar. |
| + `void process(const Vector2 &mouse)` | Processes the scrollbar for the current frame. |

### 5.4 DropBox
(Define in DropBox.h and implement in DropBox.cpp)

The `DropBox` class represents a graphical user interface (GUI) component that displays a list of options and allows the user to select one of them. This class provides methods to add, remove, and reset the options, as well as to set the position, size, and label of the component.


| Attribute / Method            | Description                                                                                                                                                                |
| -----------------------------| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `- float textSize`              | Font size of the label inside the dropdown box.                                                                                                                            |
| `- bool selected`               | Indicates whether the dropdown box is currently selected.                                                                                                                 |
| `- int curIndex`                | Index of the currently selected option. If no option is selected, `curIndex` is set to -1.                                                                                 |
| `- Option current`              | The currently selected option.                                                                                                                                             |
| `- Scrollbar bar`               | The scrollbar object used in the dropdown box.                                                                                                                             |
| `- Vector2 pos`                 | The position of the dropdown box.                                                                                                                                          |
| `- Vector2 size`                | The size of the dropdown box.                                                                                                                                              |
| `- Rectangle bound`             | The bounding rectangle of the dropdown box, including all the options.                                                                                                     |
| `- Vector<Option> options`      | The options in the dropdown box.
| `+ float roundness`             | The roundness of the border of the dropdown box.                                                                                                                           |
| `+ Color fill_color`            | The fill color of the dropdown box.                                                                                                                                        |
| `+ Color border_color`          | The border color of the dropdown box.                                                                                                                                      |
| `+ Color hover_color`           | The hover color of the options in the dropdown box.                                                                                                                        |
| `+ Color press_color`           | The press color of the options in the dropdown box.                                                                                                                        |
| `+ Color text_color`            | The color of the text in the dropdown box.                                                                                                                                 |
| `+ Equilateral arrow`           | The arrow object used in the dropdown box.                                                                                                                                 |
| `+ DropBox()`                   | Constructor of the `DropBox` class. Initializes `curIndex`, `selected`, `current`, `pos`, and `size`.                                                                    |
| `+ void refresh()`              | Updates the position, size, and other properties of the dropdown box and all its options.                                                                                  |
| `+ void setLabel(std::string label)` | Sets the label of the currently selected option.                                                                                                                         |
| `+ void setX(float x)`          | Sets the x-coordinate of the position of the dropdown box.                                                                                                                |
| `+ void setY(float y)`          | Sets the y-coordinate of the position of the dropdown box.                                                                                                                |
| `+ void setWidth(float width)`  | Sets the width of the dropdown box.                                                                                                                                        |
| `+ void setHeight(float height)`| Sets the height of the dropdown box.                                                                                                                                       |
| `+ void setPos(Vector2 pos)`    | Sets the position of the dropdown box.                                                                                                                                     |
| `+ void setSize(Vector2 size)`  | Sets the size of the dropdown box.                                                                                                                                         |
| `+ void add(const std::string &label)` | Adds an option to the dropdown box with the given label.                                                                                                           |
| `+ void add(const Vector<std::string> &labels)` | Adds multiple options to the dropdown box with the given labels.                                                                                               |
| `+ string getCurLabel() const`  | Returns the label of the currently selected option.                                                                                                                       |
| `+ void remove(const std::string label)` | Removes the option with the given label from the dropdown box.                                                                                                    |
| `+ void reset()`                 | Resets the dropdown box by removing all the options except the default option.                                                                                             |
| `+ void clear()`                 | Clears the dropdown box by removing all the options.                                                                                                                       |
| `+ int getSelected()`            | Returns the index of the currently selected option. If no option is selected, returns -1.                                                                                  |
|` + void render(const Vector2 &mouse)`| enders the component to the screen.
|`+ bool process(const Vector2 &mouse)`| Processes user input and returns true if the user has selected an option.









