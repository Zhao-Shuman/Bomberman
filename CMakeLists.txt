cmake_minimum_required(VERSION 3.21)
project(Bomberman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bomberman main.cpp PhysicalObject.h MovableObject.h AbstractObject.h Player.h Enemy.h EnemyType.h Bomb.h Bonus.h BonusType.h App.h AbstractObject.cpp Bomb.cpp Enemy.cpp App.cpp Bonus.cpp Player.cpp)
