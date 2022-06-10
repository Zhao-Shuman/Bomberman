cmake_minimum_required(VERSION 3.21)
project(Bomberman)

set(CMAKE_CXX_STANDARD 14)


set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(SDL2_INCLUDE_DIR C:/SDL/SDL_FILES/include)
set(SDL2_LIB_DIR C:/SDL/SDL_FILES/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(SDL2_IMAGE_INCLUDE_DIR C:/SDL/SDL_IMAGE/include)
set(SDL2_IMAGE_LIB_DIR C:/SDL/SDL_IMAGE/lib/x64)



include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

add_executable(Bomberman src/main.cpp src/ErrorHandler.h src/Game.cpp src/Game.h src/ErrorHandler.cpp src/GameObject.h src/Player.cpp src/Player.h src/Map.cpp src/Map.h src/MapObject.h src/TextureManager.cpp src/TextureManager.h src/KeyboardController.h src/TransformObject.h src/Vector2D.cpp src/Vector2D.h src/CircleCollision.h src/Enemy.cpp src/Enemy.h)#PhysicalObject.h MovableObject.h AbstractObject.h Player.h Enemy.h EnemyType.h Bomb.h Bonus.h BonusType.h Game.h AbstractObject.cpp Bomb.cpp Enemy.cpp Game.cpp Bonus.cpp Player.cpp



target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
