# 🎓 Alumni Management System (C++ CLI Project)

A Command-Line Interface (CLI) based Alumni Management System implemented in C++ using Object-Oriented Programming (OOP) concepts. This project allows admins and alumni to manage and interact with alumni data, offering functionalities like login, registration, messaging, and filtering based on graduation year or department.

---

## 🚀 Features

* 🔐 **User Authentication**

  * Separate login/registration for Admins and Alumni
* 📄 **Alumni Details Management**

  * View, search, and filter alumni based on various criteria
* 💬 **Messaging System**

  * Admins can send messages to individual alumni, batches, or all alumni
  * Alumni can message each other without needing admin approval
* 🗕️ **Filter by Year/Department**

  * Search for alumni by graduation year or department
* 🧐 **Object-Oriented Design**

  * Uses OOP principles (classes, inheritance, encapsulation, etc.)

---

## 🛠️ Tech Stack

* **Language:** C++
* **Paradigm:** Object-Oriented Programming
* **Interface:** Command Line (CLI)
* **Compiler:** g++ or any C++17+ compatible compiler

---

## 📂 Project Structure

```
Alumni_management_system_CLI_oops/
├── main_proj.cpp         # Main control flow
├── login.cpp             # Login & registration logic
├── overload.cpp          # Overloaded functions & message handling
├── login.h               # Login-related declarations
├── alumni.h              # Alumni class and attributes
├── admin.h               # Admin class and attributes
├── message.h             # Message class and functions
├── data/                 # Optional: store messages or user info
```

---

## 🧪 How to Compile and Run

### 🔧 Compile (using g++)

```bash
g++ main_proj.cpp login.cpp overload.cpp -o alumni_app
```

### ▶️ Run

```bash
./alumni_app       # On Linux/macOS
alumni_app.exe     # On Windows
```

> 📌 Make sure `g++` is installed and available in your system PATH.

---

## 📝 Sample Functionalities

* Register as a new alumni or admin
* Secure login for both roles
* View all alumni or search by:

  * Graduation year
  * Department
  * Name or ID
* Admin-only privileges:

  * Broadcast messages
  * View alumni data
* Alumni-to-alumni messaging (if enabled)
* Well-organized and modular codebase using headers and source files

---

## ✅ Requirements

* A C++ compiler (`g++` recommended)
* Works on:

  * Windows (via PowerShell/Command Prompt)
  * Linux/macOS (via terminal)

---

## 🤝 Contributing

Contributions are welcome! If you'd like to:

* Add file/database persistence
* Improve UI/UX (CLI formatting)
* Add unit tests or modern C++ features

Feel free to fork the repo, open issues, or create pull requests.

---

## 📃 License

This project is licensed under the [MIT License](LICENSE).
Feel free to use it for academic or learning purposes.

---

## 🙇‍♂️ Author

Created with ❤️ by **Jatin**
📢 GitHub: [github.com/blackpanther093](https://github.com/blackpanther093)
