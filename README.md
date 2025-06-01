# 📚 C++ Dictionary Application

A console-based C++ application that allows users to load, search, and manage a dictionary of words and definitions. Built as part of **OOP345** to include performance monitoring and event logging.

---

## 🚀 Features

- 📂 Load words and definitions from `.csv` files (`english_small.csv`, `english_large.csv`)
- 🔍 Search for word definitions
- ➕ Add new words to the dictionary
- ❌ Remove existing words
- ⏱️ Measure performance metrics (execution time in nanoseconds)
- 📝 Optional modules:
  - Event logging (via `Logger` and `Event` classes)
  - Configurable settings

---

## 🛠️ Tech Stack

- C++17
- STL (`<vector>`, `<chrono>`, etc.)
- Custom classes: `Dictionary`, `TimeMonitor`, `Event`, `Logger`

---

## 🧭 How to Run the Application (Visual Studio on Windows)

### ✅ Prerequisites

- Visual Studio (Community/Professional/Enterprise)
- Desktop development with C++ workload enabled
- C++17 standard support
- A terminal or command prompt
- `.csv` files: `english_small.csv` or `english_large.csv`

---

### 🧱 Setup Instructions

1. **Clone the Repository**

   ```bash
   git clone https://github.com/your-username/DictionaryApplication.git

Or download the ZIP and extract it.

### Open in Visual Studio

1. Launch Visual Studio  
2. Go to **File > Open > CMake...**  
3. Select the root folder of the project  

✅ **Alternatively, for manual setup:**  

1. Create a new C++ Console App project  
2. Add all `.cpp` and `.h` files from `src/` and `include/`  

### Set Include and Working Directory Paths

1. Right-click your project → **Properties**  
2. Under **C/C++ > General > Additional Include Directories:**  
   - Add: `$(ProjectDir)include`  
3. Under **Debugging > Working Directory:**  
   - Add: `$(ProjectDir)data`  

### Set C++ Language Standard

1. Go to **C/C++ > Language**  
2. Set: `ISO C++17 Standard (/std:c++17)`  

### Build and Run

1. Go to **Build > Build Solution**
2. Run using **Ctrl + F5** (Start Without Debugging)  

