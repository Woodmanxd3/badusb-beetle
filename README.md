# **HiLetGo BadUSB Beetle - Keystroke Injection Example Payload**

## **Overview**
This project turns the **HiLetgo BadUSB Beetle (ATMEGA32U4)** into a **multi-OS keystroke injection tool** that can automate commands across **Windows, Linux, and macOS**. The included **payload** is just an example for **Windows**. It will just open up notepad on windows and type "Payload Succeeded!".
## **⚠️ Disclaimer**
This tool is for **educational and ethical hacking purposes only**. Do not use this on systems you do not own or have explicit permission to test. The misuse of this tool may result in legal consequences.

---

## **🔧 Requirements**
- **HiLetgo BadUSB Beetle (ATMEGA32U4)** or any ATMEGA32U4-based board
- **Arduino-CLI installed**
- **Arduino Keyboard Library installed**
- **A computer running Windows, Linux, or macOS**
- **USB cable for flashing the board**

---

## **🛠️ Installation & Setup**
### **Step 1: Install Arduino-CLI**
Arduino-CLI is required to compile and upload scripts to the BadUSB device.

Run the following command to install Arduino-CLI:
```bash
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
```
Verify the installation:
```bash
arduino-cli version
```

### **Step 2: Configure Arduino-CLI**
Initialize the configuration file:
```bash
arduino-cli config init
```
Update the core index and install support for ATMEGA32U4 boards:
```bash
arduino-cli core update-index
arduino-cli core install arduino:avr
```

### **Step 3: Install the Keyboard Library**
The Keyboard library is required to simulate keystrokes. Install it using:
```bash
arduino-cli lib install "Keyboard"
```

### **Step 4: Check If Your Board is Detected**
Plug in your HiLetgo BadUSB Beetle and run:
```bash
arduino-cli board list
```
If detected, you should see an output like:
```
Port         Type              Board Name  
/dev/ttyACM0 Serial Port      Arduino Micro
```

---

## **📜 Writing a Keystroke Injection Script**
The following is an **example payload for Windows**. Additional payloads will be added to support different automation use cases.

### ** Create a New Sketch**
Create a new file called `payload.ino` and paste the following script:

```cpp
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_hu_HU.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_pt_PT.h>
#include <Keyboard_sv_SE.h>

void setup() {
  // put your setup code here, to run once:
delay(3000);
Keyboard.begin();
//Press the windows key
Keyboard.press(KEY_LEFT_GUI);
Keyboard.releaseAll();
delay(1000);
Keyboard.print("n");
delay(300);
Keyboard.print("o");
delay(100);
Keyboard.print("t");
delay(100);
Keyboard.print("e");
delay(300);
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
delay(1000);
Keyboard.print("Pay");
delay(50);
Keyboard.print("load ");
delay(100);
Keyboard.print("Succ");
delay(50);
Keyboard.print("eeded!");
//Stop emulating the keyboard
Keyboard.releaseAll();
Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

---

## **🛠️ Compiling & Uploading the Script**
### **Step 1: Compile the Script**
Run the following command to compile the script for the **ATMEGA32U4**:
```bash
arduino-cli compile --fqbn arduino:avr:micro payload.ino
```
If your board uses the **Leonardo bootloader**, use:
```bash
arduino-cli compile --fqbn arduino:avr:leonardo payload.ino
```

### **Step 2: Upload the Script to the BadUSB Device**
```bash
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:micro payload.ino
```
Replace `/dev/ttyACM0` with the correct port detected earlier.

---

## **🚀 Executing the Payload**
1. **Plug the BadUSB into a computer** running Windows.
2. The behavior depends on the payload:
3. The **payload example** will launch and type "Payload Succeeded!".
---

## **🎯 Troubleshooting**
### **1. The Payload Doesn't Execute**
- Ensure the script is **compiled and uploaded correctly**.
- Verify that **Arduino-CLI detects the board** with `arduino-cli board list`.
- Try increasing the delay (`delay(3000);` to `delay(5000);`) in `setup()`.
---

## **📢 Final Notes**
This repository is designed for **educational purposes**, helping users understand how keystroke injection can be used for **automation and security research**.

For any issues or improvements, feel free to **submit a pull request** or **open an issue** on GitHub.

