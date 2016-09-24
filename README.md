# LibDS (Legacy Version)

[![Build Status](https://img.shields.io/travis/FRC-Utilities/LibDS.svg?style=flat-square)](https://travis-ci.org/FRC-Utilities/LibDS)
[![Donate button](https://img.shields.io/badge/bitcoin-donate-brightgreen.svg?style=flat-square)](https://blockchain.info/address/1K85yLxjuqUmhkjP839R7C23XFhSxrefMx "Donate once-off to this project using BitCoin")

This is the legacy version of LibDS, which was written with C++ and Qt. The [new version](https://github.com/frc-utilities/libds) is written in C and provides some additional features.

### Project sections

This library consists of three basic sections:

- [Core](#core-section) Section
- [Protocols](#protocols-section) Section
- [DriverStation](#driverstation-section) Section

#### Core section

The core section is in charge of implementing all the support system of the library. In this section you will find:

- A parallel network scanner
- Definitions for DS-specific types
- Configurable NetConsole listener/sender
- A watchdog for reseting the DS when not receiving input from the robot
- The protocol abstract template
- The base signaling/event system of the library

#### Protocols section

This section contains the different protocols used for communicating with any FRC robot.

This section includes:

- The 2014 communication protocol
- The 2015/2016 communication protocol

#### DriverStation section

This section provides client access to the library, while preserving all the features for safe robot operation. Think of this section as the 'public' side of the library, while the rest can be considered as the 'internal' side.

### Credits

This library was created by FRC team 3794 "WinT" from Metepec, Mexico. We sincerely hope that you enjoy our application and we would love some feedback from your team about it.

### Contact

To contact us, you can send us an e-mail at [team3794@outlook.com](mailto:team3794@outlook). If you would like to report an issue, or a bug, please use the [Issues](https://github.com/wint-3794/qdriverstation/issues) page.

### License

This project is licensed under the MIT license. See the LICENSE file for more information.
