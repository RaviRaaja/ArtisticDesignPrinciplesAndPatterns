# Design Logger
A logging framework's low-level design involves creating a system that can capture and manage logs from various applications and locations. This typically involves defining log levels, storage locations (console, files, databases, etc.), and configuration options for customization. It also considers aspects like performance, scalability, and thread safety, especially in concurrent environments.

## Key Components and Considerations

- **Log Levels:** The framework should support different log levels (e.g., DEBUG, INFO, WARN, ERROR, FATAL) to allow filtering and prioritization of log messages.
- **Log Format:** Define how log messages are structured (e.g., timestamp, log level, message content, source).
- **Output Destinations:** Support writing logs to different locations, such as the console, files, databases, and potentially third-party log management systems (ELK, Splunk).
- **Configuration:** Allow users to configure the framework, including log levels, output destinations, and log format, possibly through configuration files or dynamic updates.
- **Asynchronous Logging:** Implement asynchronous logging for better performance, especially when handling high volumes of log data.
- **Thread Safety:** Ensure the framework is thread-safe to handle concurrent logging from multiple threads.
- **Design Patterns:** Consider using design patterns like Singleton (for a single logging instance), Observer (for notifying different destinations) & strategy for sink. 
- **Scalability and Performance:** Design the system to handle large volumes of log data efficiently, possibly using techniques like asynchronous logging and efficient data structures. 
