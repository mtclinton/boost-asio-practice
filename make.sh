g++ echo_client_sync.cpp -o client -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ echo_server_sync.cpp -o server -L /usr/lib/ -lboost_system -lboost_thread -lpthread