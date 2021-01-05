make re
make clean
CUB=Cub3D ; MAP=maps/map0.cub ; valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes --log-file=valgrind_log ./$CUB $MAP; grep -A1 "valgrind" valgrind_log | grep $CUB