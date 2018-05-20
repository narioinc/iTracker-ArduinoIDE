nRF52832 HCI/UART DFU Bootloader - From nRF5 SDK v11.0.0
======================================================

Device firmware update (DFU) bootloader which allows the nRF52832's firmware and/or SoftDevice to be updated serially.

[nrfutil v0.5.2](https://github.com/NordicSemiconductor/pc-nrfutil/releases/tag/v0.5.2) can be used to transfer a firmware image from computer to nRF52832.

To enter the bootloader, pin 6 -- attached to a button on the SparkFun nRF52832 Breakout -- must be held low on startup or reset. The LED on pin 7 will blink in a "timebomb" pattern to indicate the board is in the bootloader state.

For more information on the Nordic BLE & HCI/UART Bootloader/DFU, check out their [SDK Reference Page](http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.sdk5.v11.0.0/examples_ble_dfu.html).

### Contents

* **/config** -- Platform-specific configurations.
* **/hex** -- Compiled hex files for the SoftDevice (S132) and bootloader.
* **main.c** -- Main source file for bootloader application

### Toolchain Requirements

To compile this bootloader, you'll need [armgcc](https://launchpad.net/gcc-arm-embedded) and Nordic's [nRF5_SDK_V11.0.0](https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v11.x.x/).

Documentation for the nRF5 SDK (v11.0.0) can be found at [http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v11.0.0%2Findex.html](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v11.0.0%2Findex.html). Follow along with the instructions there to install and set up the SDK. Note that GCC is used instead of Keil or IAR.

### Building the Bootloader

Replace the two file below from this repository into the \examples\dfu\bootloader folder in Nordic SDK

* **main.c**, to replace in \examples\dfu\bootloader folder
* **dfu_bank_internal.h**, to replace in \components\libraries\bootloader_dfu folder

compile the bootloader app by invoking make in the bootloader example directory. Sample bootloder is present in the **hex/** folder and i have also added a merged hex. 
