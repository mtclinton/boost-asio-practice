#g++ echo_client_sync.cpp -o client -L /usr/lib/ -lboost_system -lboost_thread -lpthread
#g++ echo_server_sync.cpp -o server -L /usr/lib/ -lboost_system -lboost_thread -lpthread

g++ tutorial/timer1.cpp -o build/timer1 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ tutorial/timer2.cpp -o build/timer2 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ tutorial/timer3.cpp -o build/timer3 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ tutorial/timer4.cpp -o build/timer4 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ tutorial/timer5.cpp -o build/timer5 -L /usr/lib/ -lboost_system -lboost_thread -lpthread

g++ tutorial/sync_tcp_client.cpp -o build/sync_tcp_client -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ tutorial/sync_tcp_server.cpp -o build/sync_tcp_server -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ tutorial/async_tcp_server.cpp -o build/async_tcp_server -L /usr/lib/ -lboost_system -lboost_thread -lpthread