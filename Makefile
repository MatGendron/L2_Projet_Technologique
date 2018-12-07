CC = gcc
CFLAGS = -std=c99 -Wall -g
CPPFLAGS = -I ../include
LDFLAGS = -L. -lgame 
all : libs net_text


net_text.o : net_text.c libgame.a
	$(CC) -c $< $(CFLAGS)
test_avialar.o: test_avialar.c libs
	$(CC) -c $< $(CFLAGS)
test_mgendron.o : test_mgendron.c libs
	$(CC) -c $< $(CFLAGS)
test_walouini.o: test_walouini.c libs
	$(CC) $(CFLAGS) -c $<
test_kleguen.o: test_kleguen.c libs
	$(CC) -c $< $(CFLAGS)
game.o: game.c game.h 
	$(CC) $(CFLAGS) -c $< 
game_io.o: game_io.c game.h game_io.h
	$(CC) $(CFLAGS) -c $< 		


testfw_avialar.o: test_avialar.c libs
	$(CC) -c $< $(CFLAGS) -DTESTFW -o $@
testfw_mgendron.o : test_mgendron.c libs
	$(CC) -c $< $(CFLAGS) -DTESTFW -o $@
testfw_walouini.o: test_walouini.c libs
	$(CC) $(CFLAGS) -c $< -DTESTFW -o $@
testfw_kleguen.o: test_kleguen.c libs
	$(CC) -c $< $(CFLAGS) -DTESTFW -o $@


libgame.a : game.o game_io.o 
	ar rcs $@ $^

libs : libgame.a libtestfw.a libtestfw_main.a
net_text : net_text.o
	$(CC) $^ -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

testfw: testfw_all 
	./testfw_all -t 2 -o test.log -c


test: run_test_kleguen run_test_walouini run_test_avialar run_test_mgendron
 

testfw_all: testfw_avialar.o testfw_mgendron.o testfw_walouini.o testfw_kleguen.o libgame.a
	$(CC) $^ -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -ltestfw_main -ltestfw -ldl -rdynamic


run_test_kleguen: test_kleguen
	./test_kleguen set_piece
	./test_kleguen game_new_game
	./test_kleguen shuffle_dir
	./test_kleguen game_height

run_test_avialar: test_avialar
	./test_avialar is_game_over
	./test_avialar game_width
	./test_avialar rotate_piece_one
	./test_avialar rotate_piece
	./test_avialar set_piece_current_dir
	./test_avialar empty

run_test_mgendron: test_mgendron
	./test_mgendron delete
	./test_mgendron get_piece
	./test_mgendron current_dir
	./test_mgendron restart

run_test_walouini: test_walouini
	./test_walouini is_edge_coordinates
	./test_walouini is_edge
	./test_walouini opposite_dir
	./test_walouini copy_game
	


test_kleguen : test_kleguen.o
	$(CC) $(CFLAGS)  $(CPPFLAGS) $^ $(LDFLAGS) -o $@

test_avialar: test_avialar.o
	$(CC) $^ -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

test_walouini: test_walouini.o
	$(CC) $(CFLAGS)  $(CPPFLAGS) $^ $(LDFLAGS) -o $@

test_mgendron : test_mgendron.o
	$(CC) $^ -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)


clean :
	rm net_text net_text.o testfw_*.o test_*.o libgame.a test_walouini test_kleguen test_avialar testfw_all test_mgendron *~ *.log game.o game_io.o
.PHONY : clean libs test
