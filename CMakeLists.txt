cmake_minimum_required(VERSION 3.8)
project(arduino_snake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp game/Snake.cpp game/Snake.h game/SnakeSegment.cpp game/SnakeSegment.h renderer/Renderer.cpp renderer/Renderer.h game/Board.cpp game/Board.h game/Entity.h game/BoardState.h game/Food.cpp game/Food.h game/Entity.cpp renderer/DiffDescription.cpp renderer/DiffDescription.h input/InputState.cpp input/InputState.h input/Direction.h input/ButtonState.h GameManager.cpp GameManager.h input/ArduinoInputReader.cpp input/ArduinoInputReader.h ArduinoGame.cpp ArduinoGame.h renderer/ArduinoRenderer.cpp renderer/ArduinoRenderer.h timer/Timer.cpp timer/Timer.h timer/Waiter.cpp timer/Waiter.h)
add_executable(arduino_snake ${SOURCE_FILES})