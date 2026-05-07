# 🛠️ Workshop Prerequisites — Installation Guide

**IEEE RAS E-JUST | Microcontrollers Workshop**  
Complete all installations **before the workshop day**. Estimated time: 15–20 minutes.

---

## ✅ Requirements Overview

| # | What to Install | Required For |
|---|---|---|
| 1 | Arduino IDE 2.x | Everything |
| 2 | ESP32 Board Package | ESP32 exercises |
| 3 | MightyCore Board Package | ATmega32 challenge |
| 4 | USBasp Driver (Windows only) | ATmega32 upload |
| 5 | SimulIDE | ATmega32 simulation |

---

## 0. Arduino IDE

Download and install **Arduino IDE 2.x** from:  
👉 https://www.arduino.cc/en/software

> ⚠️ If you have IDE 1.x, please upgrade — IDE 2.x is required for faster compilation and caching.

---

## 1. ESP32 Board Package

### Step 1 — Add the ESP32 URL
1. Open Arduino IDE
2. Go to **File → Preferences**
3. Find the field **"Additional Boards Manager URLs"**
4. Paste this URL:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

5. Click **OK**

### Step 2 — Install the Package
1. Go to **Tools → Board → Boards Manager**
2. Search for: `esp32`
3. Find **"esp32 by Espressif Systems"**
4. Click **Install** and wait for it to finish

### Step 3 — Select Your Board
1. Go to **Tools → Board → ESP32 Arduino**
2. Select **"ESP32 Dev Module"**

### Step 4 — Recommended Settings
| Setting | Value |
|---|---|
| Upload Speed | 115200 |
| CPU Frequency | 240MHz |
| Flash Size | 4MB (32Mb) |
| Partition Scheme | Default 4MB with spiffs |

> ✅ **Test:** Open **File → Examples → WiFi → WiFiScan** and try compiling. If it compiles without errors, you're good.

---

## 2. MightyCore Board Package (for ATmega32)

MightyCore is a third-party package that adds support for ATmega chips not included in Arduino by default (ATmega32, ATmega16, etc.).

### Step 1 — Add the MightyCore URL
1. Go to **File → Preferences**
2. In **"Additional Boards Manager URLs"**, add this URL  
   *(if you already added the ESP32 URL, separate them with a comma)*:

```
https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json
```

3. Click **OK**

### Step 2 — Install the Package
1. Go to **Tools → Board → Boards Manager**
2. Search for: `MightyCore`
3. Click **Install** and wait

### Step 3 — Select ATmega32
1. Go to **Tools → Board → MightyCore**
2. Select **"ATmega32"**

### Step 4 — Required IDE Settings for ATmega32
| Setting | Value |
|---|---|
| Board | MightyCore → ATmega32 |
| Clock | External 16MHz |
| Programmer | USBasp |
| Port | *(leave empty — USBasp doesn't use COM port)* |

> ⚠️ **Important:** Always use **Sketch → Upload Using Programmer** — NOT the regular Upload button when working with ATmega32.

---

## 3. USBasp Driver Installation

> 🍎 **Mac / Linux:** Driver installs automatically — skip this section.  
> 🪟 **Windows:** Follow all steps below.

### What You Need
- USBasp programmer (bring it to the workshop)
- Zadig tool — download free from: https://zadig.akeo.ie

### Step 1 — Plug In USBasp
Connect your USBasp to a USB port on your PC **before** opening Zadig.

### Step 2 — Open Zadig and List All Devices
1. Open **Zadig**
2. Click **Options → List All Devices**  
   *(This is required — without it, USBasp may not appear)*
3. Click the dropdown at the top and select **"USBasp"**

### Step 3 — Install the Driver
1. Make sure the right side shows **WinUSB** or **libusb-win32**
2. Click **Install Driver** (or **Replace Driver**)
3. Wait for the installation to complete

### Step 4 — Verify
1. Open **Device Manager** (search in Start menu)
2. Look for **USBasp** under "Universal Serial Bus devices"
3. No yellow warning ⚠️ = driver installed correctly ✅

---

## 🔌 USBasp Wiring to ATmega32

Use this reference when connecting during the workshop:

| USBasp Pin | ATmega32 Pin | Notes |
|---|---|---|
| MOSI | Pin 6 | ISP data line |
| MISO | Pin 7 | ISP data line |
| SCK | Pin 8 | ISP clock |
| RST | Pin 9 | Reset line |
| VCC | Pin 10 (VCC) | Power — no external supply needed |
| GND | Pin 11 (GND) | Ground |

---

## 📍 ATmega32 Pin Mapping (MightyCore)

| Arduino Pin | ATmega32 Physical Pin | Port | Notes |
|---|---|---|---|
| 2 (Button) | 12 | Port B4 | Digital I/O |
| 7 (LED) | 13 | Port B5 | Digital I/O |
| 9 (PWM~) | 21 | Port D5 | PWM capable |
| A0 (Analog) | 40 | Port A0 | Analog input |

---

## 4. SimulIDE — ATmega32 Simulation

SimulIDE is a real-time electronic circuit simulator that supports AVR microcontrollers, including the ATmega32. It allows you to simulate and test your code **without physical hardware**.

### Step 1 — Download SimulIDE
1. Go to the official website: https://simulide.com/p/downloads/
2. Download the version for your OS:

| OS | File to Download |
|---|---|
| Windows | `SimulIDE_x.x.x-Win_x64.zip` |
| Linux | `SimulIDE_x.x.x-Linux_x64.tar.gz` |
| Mac | `SimulIDE_x.x.x-MacOS.dmg` |

### Step 2 — Install / Extract
- **Windows:** Extract the `.zip` file anywhere (e.g. `C:\SimulIDE\`) — no installer needed, it's portable
- **Linux:** Extract the `.tar.gz` and run the binary inside
- **Mac:** Open the `.dmg` and drag SimulIDE to your Applications folder

### Step 3 — Launch SimulIDE
- Open the SimulIDE executable
- You should see the circuit editor workspace on launch

### Step 4 — Set Up ATmega32 Simulation

1. In the **Components panel** on the left, search for `ATmega32`
2. Drag and drop the **ATmega32** component onto the workspace
3. Add any other components you need (LEDs, resistors, buttons, etc.) from the components panel
4. Wire everything up by clicking and dragging between pins

### Step 5 — Load Your Arduino Code

1. First, **compile your sketch** in Arduino IDE:
   - Go to **Sketch → Export Compiled Binary**
   - This produces a `.hex` file in your sketch folder
2. In SimulIDE, **right-click** on the ATmega32 component
3. Select **"Load firmware"**
4. Browse to and select your `.hex` file

### Step 6 — Run the Simulation
1. Click the **Play ▶** button (top toolbar) to start the simulation
2. Interact with your circuit in real time (press buttons, observe LEDs, etc.)
3. Click **Stop ⏹** to end the simulation

### Recommended SimulIDE Settings for ATmega32

| Setting | Value |
|---|---|
| Frequency | 16 MHz |
| Programmer | None (simulation only) |
| Auto Load | Enable (reloads .hex on recompile) |

> ✅ **Test:** Drop an ATmega32 onto the workspace, connect an LED to Port B5 (pin 13), load a blink `.hex` file, and press Play — the LED should blink.

> ⚠️ **Note:** SimulIDE simulates behavior but may not replicate all hardware-level timing perfectly. Always test on real hardware before the final demo.

---

## 🖥️ Simulators Overview

Simulators let you design, test, and debug circuits and code **without any physical hardware**. Below is a summary of the recommended simulators for this workshop and beyond.

---

### 1. 🟠 Tinkercad Circuits

**Type:** Online (browser-based, no install needed)  
**Best for:** Beginners — Arduino UNO simulation, basic circuits, breadboard design  
**Link:** 👉 https://www.tinkercad.com

**What it does:**
- Simulate Arduino UNO with real C++ code in the browser
- Build circuits visually with a drag-and-drop breadboard
- Includes a built-in code editor and serial monitor
- Great for learning GPIO, sensors, and basic electronics
- Free with a free Autodesk account

> ⚠️ Does **not** support ESP32 or ATmega32 — Arduino UNO only.

---

### 2. 🔵 Circuito.io

**Type:** Online (browser-based, no install needed)  
**Best for:** Automatic wiring diagrams and component guides  
**Link:** 👉 https://www.circuito.io

**What it does:**
- Select your microcontroller and components — it auto-generates the wiring diagram
- Provides a starter code template for each component combination
- Useful for planning a circuit before physically building it
- Supports Arduino, ESP32, and Raspberry Pi

> ℹ️ Circuito is a **design assistant**, not a full simulator — it won't run your code, but it's excellent for wiring reference.

---

### 3. 🟢 Wokwi

**Type:** Online (browser-based, no install needed)  
**Best for:** ESP32 and Arduino simulation with advanced peripherals  
**Link:** 👉 https://wokwi.com

**What it does:**
- Simulate **ESP32**, Arduino UNO, Arduino Mega, Raspberry Pi Pico, and more
- Supports WiFi simulation, OLED displays, servos, I2C/SPI sensors, and NeoPixels
- Real-time serial monitor and logic analyzer built in
- Integrates with VS Code via extension
- Free to use; paid plan available for advanced features

> ✅ **Recommended for ESP32 exercises** — best online ESP32 simulator available.

---

### 4. 🔴 SimulIDE

**Type:** Offline desktop application (requires download)  
**Best for:** AVR microcontroller simulation — especially **ATmega32**  
**Download:** 👉 https://simulide.com/p/downloads/

**What it does:**
- Real-time circuit simulation with AVR, PIC, and Arduino support
- Load a compiled `.hex` file directly onto the simulated chip
- Supports LEDs, buttons, LCD displays, oscilloscope, and more
- Works fully offline — no internet required
- Free and open-source

> ✅ **Recommended for ATmega32 exercises** — see Section 4 above for full setup instructions.

---

### 5. 🟡 Autodesk Fusion 360

**Type:** Desktop application (requires download and free account)  
**Best for:** 3D PCB design, enclosure modeling, and professional schematic design  
**Download:** 👉 https://www.autodesk.com/products/fusion-360/free-trial

**What it does:**
- Full professional 3D CAD + PCB design tool in one application
- Design custom PCBs with schematic editor and auto-router
- Model 3D enclosures and mechanical parts for your electronics project
- Simulate thermal and stress analysis on designs
- Free for students and personal/hobby use (requires Autodesk account)

> ⚠️ Fusion 360 is a **heavy application** — requires a decent PC and ~10 GB of disk space. Not needed for the workshop exercises, but valuable for future projects.

---

### Simulator Comparison

| Simulator | Type | ESP32 | ATmega32 | Arduino UNO | PCB Design | Best Use |
|---|---|---|---|---|---|---|
| Tinkercad | Online | ❌ | ❌ | ✅ | ❌ | Beginners / UNO |
| Circuito.io | Online | ✅ | ❌ | ✅ | ❌ | Wiring reference |
| Wokwi | Online | ✅ | ❌ | ✅ | ❌ | ESP32 simulation |
| SimulIDE | Offline | ❌ | ✅ | ✅ | ❌ | ATmega32 / AVR |
| Fusion 360 | Offline | ❌ | ❌ | ❌ | ✅ | PCB + 3D design |

---

## ❗ Troubleshooting

### ESP32
| Problem | Fix |
|---|---|
| ESP32 not in board list | Make sure the URL was added correctly and package installed |
| Upload fails | Hold **BOOT button** on ESP32 while uploading |
| Slow compilation | Normal on first compile — IDE 2.x caches after that |

### MightyCore / ATmega32
| Problem | Fix |
|---|---|
| ATmega32 not in board list | Check MightyCore URL and reinstall |
| Upload fails | Make sure you used **Sketch → Upload Using Programmer** |
| Wrong device signature | Verify ATmega32 is selected, not ATmega328P |

### SimulIDE
| Problem | Fix |
|---|---|
| ATmega32 not found in components | Use search bar in the components panel — type `ATmega32` |
| Firmware won't load | Make sure you exported a `.hex` file via **Sketch → Export Compiled Binary** |
| Simulation runs but nothing happens | Check wiring connections and verify correct pin mapping |
| Wrong frequency behavior | Right-click ATmega32 → set frequency to **16 MHz** |
| SimulIDE crashes on open | Try downloading the latest stable version from simulide.com |

### USBasp Driver
| Problem | Fix |
|---|---|
| USBasp not in Zadig list | Click Options → List All Devices |
| "0 devices found" in Zadig | Unplug and replug USBasp, then reopen Zadig |
| Still not detected | Try a different USB port — avoid USB hubs |
| `Cannot open device` in IDE | Driver not installed — redo Zadig steps |
| `avrdude: initialization failed` | Check wiring, especially RST and GND |

---

## 📋 Pre-Workshop Checklist

Before arriving to the workshop, confirm:

- [ ] Arduino IDE 2.x installed
- [ ] ESP32 board package installed — test compile works
- [ ] MightyCore board package installed — ATmega32 appears in board list
- [ ] USBasp driver installed (Windows) — no yellow warning in Device Manager
- [ ] SimulIDE installed — ATmega32 loads and blink simulation works
- [ ] nRF Connect app installed on your phone (App Store / Google Play) — for BLE exercise

---

*Questions? Contact your instructor before the workshop day.*  
**IEEE RAS E-JUST Microcontrollers Workshop**
