using namespace boost::asio;

struct client {
    ip::tcp::socket sock;
    char buff[1024]; // each msg is at maximum this size
    int already_read; // how much have we already read

    bool set_reading() {
        boost::mutex::scoped_lock lk(cs_);
        if(is_reading_){
            return false;
        } else {
            is_reading_ = true;
            return true;
        }
    void unset_reading() {
            boost::mutex::scoped_lock lk(cs_);
            is_reading_ = false;
        }
    private:
        boost::mutex cs_;
        bool is_reading_;
    }
};

std::vector<client> clients;

void handle_clients() {
    for(int i = 0; i < 10; ++i) {
        boost::thread( handle_clients_thread);
    }
}

void handle_clients_thread() {
    while (true) {
        for (int i = 0; i < clients.size(); ++i) {
            if(clients[i].sock.available()) {
                if(clients[i].set_reading()) {
                    on_read(clients[i]);
                    clients[i].unset_reading();
                }
            }
        }
    }
}

void on_read(client &c) {
    int to_read = std::min(1024 - c.already_read, c.sock.available());
    c.sock.read_some(buffer(c.buff + c.already_read, to_read));
    c.already_read += to_read;
    if(std::find(c.buff, c.buff + c.already_read, '\n') < c.buf + c.already_read) {
        int pos = std::find(c.buff, c.buff + c.already_read, '\n') - c.buff;
        std::string msg(c.buff, c.buff + pos);
        std::copy(c.buff + pos, c.buff + 1024, c.buff);
        c.already_read -= pos;
        on_read_msg(c, msg);
    }
}

void on_read_msg(client &c, const std::string &msg) {
    // analyze message, and write back
    if(msg == "request_login") {
        c.sock.write("request_ok\n");
    }
}