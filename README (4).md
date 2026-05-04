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
- [ ] nRF Connect app installed on your phone (App Store / Google Play) — for BLE exercise

---

*Questions? Contact your instructor before the workshop day.*  
**IEEE RAS E-JUST Microcontrollers Workshop**
