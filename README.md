# LED Control System Simulation

This project simulates an advanced LED control system in C, designed for both desktop testing and embedded systems development. The following instructions detail how to compile and test the code on a desktop environment using the GCC compiler.

## Step 1: Prepare the Development Environment

### For Desktop Testing (Using GCC)
You can compile and test this program on a regular desktop using the GCC compiler, which is available on most Linux and macOS systems. For Windows users, install GCC using either the **MinGW** or **Cygwin** packages.

This allows you to simulate the logic of the program on your computer without needing a microcontroller.

## Step 2: Compile and Test on Desktop (Using GCC)

### Save the Code
1. Create a new file, for example, `led_group.c`, and copy the provided code into this file.

### Install GCC (if needed)
- On **Linux** or **macOS**, GCC is usually pre-installed.
- On **Windows**, you can install GCC through **MinGW** or **Cygwin**. Follow the respective instructions for installation.

### Compile the Code
1. Open a terminal (or Command Prompt on Windows).
2. Navigate to the folder where the `led_group.c` file is saved.
3. Run the following command to compile the code:

    ```bash
    gcc -o led_group led_group.c
    ```

   This will produce an executable file named `led_group` (or `led_group.exe` on Windows).

### Run the Program
To execute the program, run the following command:

- **Linux/macOS**:

    ```bash
    ./led_group
    ```

- **Windows**:

    ```bash
    led_group.exe
    ```

The output will display the default and updated LED statuses as per the logic defined in the code.

---

## Example Output

After running the program, you will see the following output:


