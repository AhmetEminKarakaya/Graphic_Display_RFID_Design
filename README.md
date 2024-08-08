# Graphic Display RFID Design

This project aims to create a card access system using the STM32F407VG Discovery card, RFID module and 2.8 inch TFT screen. The system allows personal information and photo to be displayed on the TFT screen by reading the RFID card. The information is stored on the SD card.

## Features

- **Fixed Size:** Uses a predefined maximum size for the stack.
- **FIFO Order:** Ensures first-in-first-out order of processing elements.
- **Efficient Operations:** Provides efficient push and pop operations.

# API Reference

- **arrayQueue(int initialcapacity = 10);**
- **~arrayQueue();**
- **bool empty() const;**
- **int size() const;**
- **T& front();**
- **T& back();**
- **void pop();**
- **void push(const T& theElement);**
