# 📚 C++ Dictionary Application

A C++ console application that allows users to load, search, and manage a dictionary of words and definitions. Includes optional modules for performance monitoring, event logging, and user settings.

## 🚀 Features

- Load words and definitions from a text file
- Search for definitions
- Add and remove words
- View performance metrics (execution time)
- Optional: Event logging and configurable settings


## 🧭 How to Run DictionaryApplication in Visual Studio (Windows)

### ✅ Prerequisites

- **Visual Studio** (Community/Professional/Enterprise) installed  
- **Desktop development with C++** workload enabled
- A terminal or command line environment
- C++ compiler (e.g., `g++` or MSVC)
- C++17 standard support or higher

---

### 🛠️ Step-by-Step Instructions

#### 1. Clone the Repository

```bash
git clone https://github.com/your-username/DictionaryApplication.git
```

Or download the ZIP from GitHub and extract it.

---

#### 2. Open Visual Studio

- Launch **Visual Studio**
- Go to **File > Open > CMake...**
- Navigate to the cloned/extracted `DictionaryApplication` folder and open it

> ✅ If you're **not using CMake**, follow the steps below to manually set up the project.

---

#### 3. Create a New C++ Project (Manual Setup)

- Go to **File > New > Project**
- Select **Console App (C++)**
- Name it something like `DictionaryAppVS`
- Choose a location to store the solution

Once the project is created:

- Right-click the project name in **Solution Explorer**
- Select **Add > Existing Item...**
- Add all `.cpp` and `.h` files from the `src/` and `include/` folders

---

#### 4. Configure Include and Data Paths

1. Right-click your project → **Properties**
2. Go to **C/C++ > General > Additional Include Directories**
   - Add: `$(ProjectDir)include`
3. Go to **Debugging > Working Directory**
   - Set it to: `$(ProjectDir)data`

> This ensures your program can find `dictionary.txt` when running.

---

#### 5. Set C++ Language Standard

1. In the same **Properties** window:
2. Navigate to **C/C++ > Language**
3. Set **C++ Language Standard** to: `ISO C++17 Standard (/std:c++17)`

---

#### 6. Build the Project

- Go to **Build > Build Solution** or press `Ctrl+Shift+B`
- Fix any compile errors if they appear

---

#### 7. Run the Application

- Press `Ctrl+F5` or go to **Debug > Start Without Debugging**
- The console should launch and begin running the Dictionary app

---

### 📝 Notes

- Make sure `dictionary.txt` is in the correct location or adjust the working directory to point to it
- If using logging, ensure your app has permission to write to files in the output directory
