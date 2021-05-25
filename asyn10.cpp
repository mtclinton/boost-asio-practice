using namespace boost::asio:

io_service service;

struct client {
    ip::tcp::socket sock;
    streambuf buff; // reads the answer from the client
};

std::vector<client> clients;

void handle_clients() {
    for(int i = 0; i < clients.size(); ++i) {
        async_read_until(clients[i].sock, clients[i].buff, '\n',
                         boost::bind(on_read, clients[i], _1, _2));
    }

    for(int i = 0; i < 10; ++i){
        boost::thread(handle_clients_thread);
    }
}

void handle_clients_thread() {
    service.run();
}

void on_read(client &c, const error_code &err, size_t read_bytes) {
    std::istream in(&c.buff);
    std::string msg;
    std::getline(in, msg);
    if ( msg == "request_login") {
        c.sock.async_write( "request_ok\n", on_write);
    }

    // now, wait for the next read from the same client
    async_read_until(c.sock, c.buff, '\n',
                     boost::bind(on_read, c, _1, _2));
}