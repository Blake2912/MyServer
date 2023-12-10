## Server setup
```
cd build/ && gcc -I.. -o HttpLinux ../server_linux.cpp ../http_tcpServer_linux.cpp -lstdc++
```
Run this command to build the server code.

Check List
- [ ] Prepare a basic server setup
- [ ] The server should be able to parse JSON data
- [ ] The server should be able to parse HTML Data
- [ ] The server should be able to connect to a Database/Database Provider (Start with SQLite then scale up)


Packages/Libraries Used:
- <a href="https://github.com/nlohmann/json">Json</a>
