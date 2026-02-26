# Hotel Blissful C++ Backend

A high-performance RESTful API built using **Modern C++23**. This project demonstrates the implementation of a scalable backend service focusing on memory efficiency, modern language standards, and robust system architecture.

## Technical Highlights

* **Modern C++ Standard:** Developed using **C++23**, leveraging features like the **Spaceship Operator (<=>)** for efficient three-way comparisons and `std::weak_ordering`.
* **High-Performance Serialization:** Utilized the **RapidJSON** DOM and Writer APIs for manual, low-overhead data serialization, bypassing the performance costs of reflective libraries.
* **Memory Management:** Strictly adheres to **RAII principles**. Implemented optimized data handling through move semantics (`std::move`) and minimizing heap allocations via pass-by-reference-to-const patterns.
* **Asynchronous Networking:** Built on the **Crow Framework** (header-only) and **Boost.Asio**, utilizing an asynchronous event loop to handle concurrent HTTP requests.
* **Build & Deployment:** Integrated **CMake** for cross-platform build management and **Docker** for containerized environment consistency.

## Toolchain
* **Language:** C++23 (GCC 13+)
* **Framework:** Crow (Web/Microservices)
* **JSON:** RapidJSON
* **Build System:** CMake
* **Containerization:** Docker
