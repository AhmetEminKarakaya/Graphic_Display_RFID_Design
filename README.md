# Graphic Display RFID Design
This project aims to create a card access system using the STM32F407VG Discovery card, RFID module and 2.8 inch TFT screen. The system allows personal information and photo to be displayed on the TFT screen by reading the RFID card. The information is stored on the SD card.

## Project Summary
The following components were used in this project:
- **STM32F407VG Discovery Card:** It is used as the central control unit of the project.
- **RFID Module:** It performs identity verification by reading the card number.
- **2.8 inch TFT Screen:** It displays the card holder's photo and information.
- **SD Card:** It stores user information (card number, name, photo) and provides the necessary data.

## System Features
Identity Verification: The user logs in to the system by reading the RFID card on the reader.
Information and Photo Display: When the card is read, the user's name, photo and other information are displayed on the TFT screen.
Data Storage: User information is stored on the SD card and can be updated when necessary.

## Hardware Connections:
Connect your STM32 card and RFID module appropriately.
Create the display unit by connecting the TFT display to the STM32 card.
Insert the SD card into the card slot of the TFT display.

## Software Installation:
Install the necessary drivers and libraries for STM32.
Download or clone the project files from this link.
Open the project in a development environment such as STM32CubeIDE or Keil uVision.

## Compile and Load:
Compile the project and load it to the STM32 card.

## SD Card Settings:
Organize the user information and photos according to the specific file structure created on the SD card.

## Usage
You can test the system's authentication and information display processes by reading your RFID card to the reader.
