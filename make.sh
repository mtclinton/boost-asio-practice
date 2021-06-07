#g++ echo_client_sync.cpp -o client -L /usr/lib/ -lboost_system -lboost_thread -lpthread
#g++ echo_server_sync.cpp -o server -L /usr/lib/ -lboost_system -lboost_thread -lpthread

g++ timer1.cpp -o build/timer1 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ timer2.cpp -o build/timer2 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ timer3.cpp -o build/timer3 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ timer4.cpp -o build/timer4 -L /usr/lib/ -lboost_system -lboost_thread -lpthread
g++ timer5.cpp -o build/timer5 -L /usr/lib/ -lboost_system -lboost_thread -lpthread