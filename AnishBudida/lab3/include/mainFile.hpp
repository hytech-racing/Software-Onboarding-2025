class mainServer {
    public:
        mainServer();
        bool send(const std::String& message, u_16int port);
        bool receive(std::string& message);
        void close();
}
