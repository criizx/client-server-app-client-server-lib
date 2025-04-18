The system is designed with extensibility in mind—for example, it can be enhanced with logging or additional data processors.
Core Components:

    Server – A TCP server that handles incoming connections, invokes a callback, and (if a forwarding address was provided during construction) relays data to another server.

    ClientConnector – A TCP client capable of connecting to a server, sending messages, and receiving responses.

Key Features:

    Support for server chaining – Data can be routed through multiple servers in sequence.

    Optional forwarding – If no destination is specified, the server simply returns a response to the client.

    Extensible architecture – The code structure allows for easy enhancements (e.g., logging, middleware).

    Message framing – Messages are sent with a 4-byte length prefix followed by the actual data.

Implementation Details:

    Network operations (server & client) are encapsulated in a reusable library (server_lib.hpp / server_lib.cpp).

    The design promotes separation of concerns, making it adaptable for different use cases.
