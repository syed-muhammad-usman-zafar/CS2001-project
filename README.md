# C++ Notepad Project

A simple text editor implementation in C++ using a linked list data structure for managing and manipulating text data.

## Features

- **Text Editing**: Create and edit text with basic cursor movement
- **File Operations**: Save and load text content from files
- **Linked List Implementation**: Using a custom multi-directional node structure

## Getting Started

### Prerequisites

- C++ compiler (supports C++11 or later)
- Standard C++ libraries
- Windows OS (for `conio.h` functionality)

### Installation

1. Clone or download the project files
2. Compile the source code using your preferred C++ compiler:
   ```
   g++ main.cpp -o notepad
   ```
3. Run the executable:
   ```
   ./notepad
   ```

## Usage

When you run the program, you'll be presented with three options:

- **S**: Save mode - Enter text and save it to a file
- **L**: Load mode - Load and display text from a file
- **I**: Input mode - Use the notepad editor interface

### Save Mode (S)

1. Enter characters one by one
2. Press 'S' (uppercase) to finish and save the text
3. The data will be saved to "Data.txt"

### Load Mode (L)

1. Loads content from "Data.txt"
2. Displays the loaded content in the linked list format

### Input Mode (I)

In the notepad editor:
- Use arrow keys to navigate
- Press Enter and then input a character to add text
- Press Backspace to delete characters

## Technical Implementation

### Data Structure

The project uses a multi-directional linked list where each node contains:
- A character value
- Pointers to the next, previous, above, and below nodes

This structure allows for 2D navigation within the text, enabling cursor movement in four directions.

### Key Classes

#### Node Class
```cpp
class Node {
public:
    char value;
    Node* next;
    Node* prev;
    Node* above;
    Node* below;
    // ...
};
```

#### Linked List (LL) Class
```cpp
class LL {
public:
    Node* head;
    // Methods for insertion, display, file operations...
};
```

## File Operations

- **Save**: Writes linked list content to "Data.txt"
- **Load**: Reads content from "Data.txt" into the linked list

## Limitations

- Basic UI with command-line interface
- Limited text formatting capabilities
- Only supports single character inputs at a time
- Windows-specific due to `conio.h` dependency

## Future Improvements

- Enhanced text editing capabilities
- Support for multiple files
- Improved user interface
- Cross-platform compatibility
- Support for multi-character input

## License

This project is available for educational purposes. Feel free to modify and expand upon it.
