# 🎮 First Semester C++ Projects

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A comprehensive collection of console-based applications developed during my first semester of Computer Science, showcasing fundamental programming concepts, data structures, and Windows console manipulation techniques.

## 📑 Table of Contents

- [Overview](#-overview)
- [Projects](#-projects)
  - [Base Conversion Application](#1-base-conversion-application)
  - [Biriyani Hunter Game](#2-biriyani-hunter-game)
  - [Mess Management System](#3-mess-management-system)
  - [Tic-Tac-Toe](#4-tic-tac-toe)
- [Technologies](#-technologies)
- [Installation](#-installation)
- [Usage](#-usage)
- [Features](#-features)
- [Learning Outcomes](#-learning-outcomes)
- [Screenshots](#-screenshots)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)

## 🎯 Overview

This repository contains four distinct C++ console applications that demonstrate various programming paradigms and problem-solving approaches:

| Project | Description | Key Features |
|---------|-------------|--------------|
| **Base Converter** | Number system conversion tool | Multi-base support (2-62), Encryption/Decryption |
| **Biriyani Hunter** | Action shooter game | 3 levels, Save/Load, Enemy AI |
| **Mess Management** | Hostel mess system | User/Admin roles, File handling, Billing |
| **Tic-Tac-Toe** | Classic board game | 2-player, Win detection, Color UI |

## 🎮 Projects

### 1. Base Conversion Application

**File:** `BaseConversionApplication.cpp`

A powerful number system converter with encryption capabilities supporting bases from binary (2) to base-62.

#### Features
- ✅ Convert between any base (2-62)
- ✅ Visual step-by-step conversion process
- ✅ Message encryption using custom base conversion
- ✅ Secure decryption with character mapping
- ✅ Color-coded interface for better UX
- ✅ Supports digits (0-9), uppercase (A-Z), and lowercase (a-z)

#### Usage
```bash
# Compile
g++ BaseConversionApplication.cpp -o BaseConverter.exe

# Run
BaseConverter.exe
```

#### Menu Options
1. **Base Conversion** - Convert numbers between different bases
2. **Encrypt Message** - Encrypt text using base conversion
3. **Decrypt Message** - Decrypt previously encrypted messages
4. **Exit**

#### Example
```
Enter base: 10
Enter number: 255
To base: 16
Answer: FF
```

---

### 2. Biriyani Hunter Game

**File:** `biriyani_hunter.cpp`

An exciting console-based shooter game where players defend their precious biriyani from enemy invaders across three challenging levels.

#### Features
- 🎮 **3 Progressive Levels** - Increasing difficulty and enemy count
- 🤖 **Smart Enemy AI** - Multiple enemy types with unique movement patterns
- 💥 **Combat System** - Bullet mechanics for player and enemies
- 🧱 **Obstacle Course** - Strategic level design with barriers
- ❤️ **Health System** - HP tracking with collectible health pills
- 💾 **Save/Resume** - Continue your game anytime
- 🏆 **Score Tracking** - Points system for achievements
- ⏸️ **Pause Functionality** - Take a break when needed

#### Controls
| Key | Action |
|-----|--------|
| `↑` | Move Up |
| `↓` | Move Down |
| `←` | Move Left |
| `→` | Move Right |
| `SPACE` | Fire Bullet |
| `ESC` | Pause Menu |

#### Game Stats
- **Player Health:** 100 HP
- **Enemy Bullet Damage:** 20 HP
- **Collision Damage:** 40 HP
- **Hits to Kill Enemy:** 5
- **Points per Hit:** 10

#### Compilation
```bash
g++ biriyani_hunter.cpp -o BiriyaniHunter.exe
```

---

### 3. Mess Management System

**File:** `MessMangementSystem.cpp`

A comprehensive hostel mess management solution with role-based access control, featuring separate interfaces for administrators and students.

#### Features

##### 🔐 Authentication System
- User registration and login
- Role-based access (Admin/User)
- Admin approval workflow
- Password and username management

##### 👨‍💼 Admin Dashboard
- ➕ Add new students to the mess
- ✏️ Update student information
- 🗑️ Remove students from mess
- 📊 View all enrolled students
- 🍽️ Update weekly mess menu
- 📅 Track daily attendance
- 📝 View and manage complaints
- 👥 Approve visitor attendance requests
- ✅ Approve admin role requests

##### 👤 User Dashboard
- 🍴 View weekly mess menu
- 💰 Check monthly billing
- 📢 Submit complaints
- 👨‍👩‍👧‍👦 Request visitor attendance
- 🔑 Change credentials
- 📋 View personal details

##### 💾 Data Persistence
All data is stored in text files for persistence:
- `login_users.txt` - User credentials
- `mess_users.txt` - Student records
- `complains.txt` - Complaint history
- `visitor_requests.txt` - Visitor attendance requests
- `mess_menu.txt` - Weekly menu items
- `admin_approval.txt` - Pending admin approvals

#### Billing Formula
```
Service Charges = 1200 PKR (fixed)
Meal Charges = Number of Meals × 220 PKR
Total Bill = Service Charges + Meal Charges
```

#### Compilation
```bash
g++ MessMangementSystem.cpp -o MessSystem.exe
```

---

### 4. Tic-Tac-Toe

**File:** `TicTacToe.cpp`

A classic two-player Tic-Tac-Toe game with an intuitive console interface and color-coded player marks.

#### Features
- 👥 Two-player gameplay
- 🎨 Color-coded players (X: Red, O: Blue)
- ✅ Input validation
- 🏆 Win detection (rows, columns, diagonals)
- 🤝 Tie game detection
- 📍 Visual cell reference guide

#### How to Play
1. Players take turns entering cell numbers (0-8)
2. Cell numbers correspond to board positions:
```
 0 | 1 | 2
-----------
 3 | 4 | 5
-----------
 6 | 7 | 8
```
3. First player to get three in a row wins
4. If all cells are filled with no winner, it's a tie

#### Compilation
```bash
g++ TicTacToe.cpp -o TicTacToe.exe
```

---

## 🛠 Technologies

### Languages & Libraries
```cpp
#include <iostream>      // Standard I/O operations
#include <windows.h>     // Console manipulation & colors
#include <conio.h>       // Console input functions
#include <fstream>       // File handling operations
#include <ctime>         // Time and date functions
#include <sstream>       // String stream operations
#include <string>        // String manipulation
#include <algorithm>     // Standard algorithms
#include <iomanip>       // I/O formatting
#include <cmath>         // Mathematical functions
#include <climits>       // Numeric limits
#include <chrono>        // High-resolution timing
#include <random>        // Random number generation
```

### Platform Requirements
- **OS:** Windows (Windows.h dependency)
- **Compiler:** MinGW-w64, Visual Studio, or Dev-C++
- **C++ Standard:** C++11 or higher

## 📥 Installation

### Prerequisites
1. **Install MinGW (Recommended)**
   ```bash
   # Download from: https://www.mingw-w64.org/
   # Add to PATH: C:\MinGW\bin
   ```

2. **Alternative: Install Visual Studio**
   - Download Visual Studio Community Edition
   - Install C++ Desktop Development workload

### Clone Repository
```bash
git clone https://github.com/yourusername/first-semester-projects.git
cd first-semester-projects
```

### Compile Individual Projects

#### Using MinGW
```bash
# Base Conversion Application
g++ BaseConversionApplication.cpp -o BaseConverter.exe

# Biriyani Hunter
g++ biriyani_hunter.cpp -o BiriyaniHunter.exe

# Mess Management System
g++ MessMangementSystem.cpp -o MessSystem.exe

# Tic-Tac-Toe
g++ TicTacToe.cpp -o TicTacToe.exe
```

#### Using Visual Studio
1. Create a new Console Application project
2. Add the `.cpp` file to the project
3. Build and run (F5)

## 🚀 Usage

### Running Programs

#### Method 1: Command Line
```bash
# Navigate to project directory
cd first-semester-projects

# Run any executable
./BaseConverter.exe
./BiriyaniHunter.exe
./MessSystem.exe
./TicTacToe.exe
```

#### Method 2: Double-Click
Simply double-click the `.exe` file after compilation

### Quick Start Guide

#### Base Conversion Application
```
1. Launch BaseConverter.exe
2. Select option (1-4)
3. Follow on-screen prompts
4. View results
```

#### Biriyani Hunter
```
1. Launch BiriyaniHunter.exe
2. Choose New Game or Resume
3. Use arrow keys to move
4. Press SPACE to shoot
5. Survive all 3 levels!
```

#### Mess Management System
```
1. Launch MessSystem.exe
2. Sign up (first-time users)
3. Sign in with credentials
4. Navigate menu options
5. Data auto-saves
```

#### Tic-Tac-Toe
```
1. Launch TicTacToe.exe
2. Enter cell number (0-8)
3. Players alternate turns
4. First to 3-in-a-row wins!
```

## ✨ Features

### 🎨 User Interface
- **Color-Coded Output** - Enhanced readability with color schemes
- **ASCII Art Headers** - Professional-looking banners
- **Formatted Tables** - Organized data presentation
- **Dynamic Menus** - Context-sensitive navigation
- **Real-time Updates** - Smooth screen refreshes

### 🔒 Robust Input Handling
- **Input Validation** - Prevents invalid entries
- **Error Messages** - Clear feedback on mistakes
- **Type Checking** - Ensures correct data types
- **Range Verification** - Validates numeric bounds
- **Retry Mechanisms** - Allows users to correct errors

### 💾 Data Management
- **File Persistence** - Data survives program closure
- **Auto-Save** - Automatic data preservation
- **Data Integrity** - Validation on load/save
- **CSV-like Format** - Human-readable storage
- **Multiple Files** - Organized data separation

### 🎮 Game Mechanics (Biriyani Hunter)
- **Collision Detection** - Precise hit detection
- **Physics Simulation** - Bullet trajectories
- **AI Patterns** - Unique enemy behaviors
- **Level Progression** - Difficulty scaling
- **State Management** - Save/load game state

### 🔐 Security Features (Mess System)
- **Password Protection** - Secure authentication
- **Role-Based Access** - Admin/User separation
- **Approval Workflow** - Admin verification
- **Session Management** - User state tracking

## 📚 Learning Outcomes

Through developing these projects, I gained practical experience in:

### Core Programming Concepts
- ✅ Variables, constants, and data types
- ✅ Operators and expressions
- ✅ Control structures (if-else, switch-case)
- ✅ Loops (for, while, do-while)
- ✅ Functions and parameters
- ✅ Arrays and strings
- ✅ Pointers and references

### Advanced Topics
- ✅ File I/O operations
- ✅ String manipulation
- ✅ Algorithm design
- ✅ Data structure usage
- ✅ Memory management
- ✅ Error handling
- ✅ Code modularization

### Windows Console Programming
- ✅ Console API functions
- ✅ Cursor positioning (`gotoxy`)
- ✅ Color manipulation (`SetConsoleTextAttribute`)
- ✅ Console buffer management
- ✅ Keyboard input handling
- ✅ Screen clearing and updating

### Software Engineering
- ✅ Problem decomposition
- ✅ Function design
- ✅ Code organization
- ✅ Debugging techniques
- ✅ Testing strategies
- ✅ Documentation practices
- ✅ Version control basics

### Domain-Specific Skills
- 🔢 **Base Conversion:** Number system algorithms
- 🎮 **Game Development:** Game loops, collision detection
- 💼 **System Design:** User authentication, role management
- 🏆 **Logic Programming:** Win condition checking

## 🔮 Future Enhancements

### Planned Improvements

#### Base Conversion Application
- [ ] Add floating-point conversion support
- [ ] Implement advanced encryption algorithms (AES, RSA)
- [ ] Add file encryption/decryption
- [ ] Create GUI version using Qt or wxWidgets
- [ ] Support for very large numbers (BigInt)

#### Biriyani Hunter
- [ ] Add sound effects and background music
- [ ] Implement power-ups (shields, rapid fire)
- [ ] Create more levels with boss battles
- [ ] Add difficulty settings (Easy/Medium/Hard)
- [ ] Include local multiplayer mode
- [ ] Implement high score leaderboard
- [ ] Add customizable controls

#### Mess Management System
- [ ] Migrate to SQL database (SQLite/MySQL)
- [ ] Add email notifications for bills
- [ ] Implement payment gateway integration
- [ ] Create mobile app version
- [ ] Add graphical reports and charts
- [ ] Include inventory management
- [ ] Implement SMS notifications
- [ ] Add biometric attendance

#### Tic-Tac-Toe
- [ ] Add AI opponent (Minimax algorithm)
- [ ] Include difficulty levels for AI
- [ ] Implement online multiplayer
- [ ] Add game statistics tracking
- [ ] Create tournament mode
- [ ] Add customizable board sizes (4x4, 5x5)
- [ ] Include themes and skins

### General Improvements
- [ ] Port to cross-platform (Linux, macOS)
- [ ] Add comprehensive unit tests
- [ ] Implement CI/CD pipeline
- [ ] Create detailed API documentation
- [ ] Add internationalization (i18n)
- [ ] Improve error handling and logging
- [ ] Optimize performance
- [ ] Add configuration files

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/yourusername/first-semester-projects/issues).

### How to Contribute

1. **Fork the Project**
   ```bash
   # Click 'Fork' button on GitHub
   ```

2. **Clone Your Fork**
   ```bash
   git clone https://github.com/yourusername/first-semester-projects.git
   cd first-semester-projects
   ```

3. **Create a Branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

4. **Make Changes**
   - Write clean, commented code
   - Follow existing code style
   - Test thoroughly

5. **Commit Changes**
   ```bash
   git add .
   git commit -m "Add some AmazingFeature"
   ```

6. **Push to Branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

7. **Open Pull Request**
   - Go to your fork on GitHub
   - Click "New Pull Request"
   - Describe your changes

### Contribution Guidelines
- Write clear commit messages
- Comment your code
- Update documentation
- Test before submitting
- Follow C++ best practices
- Be respectful and collaborative

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2026 [Saim Mustafa]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 📧 Contact

**Project Link:** [https://github.com/yourusername/first-semester-projects](https://github.com/yourusername/first-semester-projects)

## 🙏 Acknowledgments

- Thanks to my Programming Fundamentals instructor for guidance
- [Windows Console API Documentation](https://docs.microsoft.com/en-us/windows/console/)
- [C++ Reference](https://en.cppreference.com/)
- Stack Overflow community
- GitHub for hosting
- All open-source contributors

## 📊 Project Statistics

- **Total Lines of Code:** ~3,500+
- **Number of Functions:** 150+
- **Development Time:** 1 Semester
- **Languages:** C++ (100%)
- **Files:** 4 main source files
- **Data Files:** 6 persistent storage files

## ⚙️ Troubleshooting

### Common Issues

#### Compilation Errors
```bash
# If you get "windows.h not found"
# Install MinGW properly and add to PATH

# If you get linking errors
g++ filename.cpp -o output.exe -lwinmm
```

#### Runtime Issues
```bash
# If console colors don't work
# Run in Windows Command Prompt or PowerShell
# Git Bash may not support full color

# If files don't save
# Ensure write permissions in directory
# Run as administrator if needed
```

#### Display Issues
```bash
# If layout is broken
# Ensure console window is large enough
# Recommended: 120x30 character window
```

<div align="center">

### ⭐ Star this repository if you found it helpful!

Made with ❤️ by a First Semester CS Student

[Report Bug](https://github.com/yourusername/first-semester-projects/issues) · [Request Feature](https://github.com/yourusername/first-semester-projects/issues)

</div>
