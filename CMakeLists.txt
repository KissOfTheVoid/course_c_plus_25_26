cmake_minimum_required(VERSION 3.16)
project(course_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)

# Helper: add standalone .cpp files from a directory as separate executables
function(add_seminar_tasks dir prefix)
    file(GLOB sources "${dir}/*.cpp")
    foreach(src ${sources})
        get_filename_component(name ${src} NAME_WE)
        add_executable(${prefix}_${name} ${src})
    endforeach()
endfunction()

# --- Seminar 2 ---
add_seminar_tasks(seminar2 sem02)

# --- Seminar 5 ---
# Standalone tasks
foreach(task task01 task02 task05 task06 task07 task08 task09 task10 task11 task12 task13 task14)
    add_executable(sem05_${task} seminar5/${task}.cpp)
endforeach()
# Multi-file tasks
add_executable(sem05_task03 seminar5/task03/task03.cpp seminar5/task03/function.cpp)
target_include_directories(sem05_task03 PRIVATE seminar5/task03)
add_executable(sem05_task04
    seminar5/task04/task04.cpp
    seminar5/task04/plus.cpp
    seminar5/task04/minus.cpp
    seminar5/task04/multiply.cpp
    seminar5/task04/divide.cpp
)
target_include_directories(sem05_task04 PRIVATE seminar5/task04)

# --- Seminar 6 ---
add_seminar_tasks(seminar6 sem06)

# --- Seminar 7 ---
add_seminar_tasks(seminar7 sem07)

# --- Seminar 9 ---
add_seminar_tasks(seminar9 sem09)

# --- Seminar 10 ---
add_seminar_tasks(seminar10 sem10)

# --- Seminar 11 ---
add_seminar_tasks(seminar11 sem11)

# --- Seminar 16 ---
add_seminar_tasks(seminar16 sem16)

# --- Seminar 17 ---
add_seminar_tasks(seminar17 sem17)

# --- Seminar 18 ---
add_seminar_tasks(seminar18 sem18)

# --- Seminar 19 ---
add_seminar_tasks(seminar19 sem19)

# --- Seminar 20 ---
add_seminar_tasks(seminar20 sem20)

# --- Seminar 22 ---
add_seminar_tasks(seminar22 sem22)

# --- Seminar 23 ---
add_executable(sem23_task3 seminar23/task3.cpp)
add_executable(sem23_task4 seminar23/task4/task4.cpp)
add_executable(sem23_task5 seminar23/task5.cpp)

# --- Seminar 25 ---
add_seminar_tasks(seminar25 sem25)

# --- Seminar 26 ---
add_seminar_tasks(seminar26 sem26)

# --- Seminar 29 ---
add_seminar_tasks(seminar29 sem29)

# --- Seminar 30 ---
add_seminar_tasks(seminar30 sem30)

# --- Seminar 32 ---
add_seminar_tasks(seminar32 sem32)

# --- Seminar 33 ---
add_seminar_tasks(seminar33 sem33)

# --- Seminar 34 ---
add_executable(sem34_task1 seminar34/task1/task1.cpp)
add_executable(sem34_task2 seminar34/task2.cpp)
add_executable(sem34_task3 seminar34/task3.cpp)

# --- Seminar 35 ---
add_seminar_tasks(seminar35 sem35)

# --- Seminar 37 ---
add_executable(sem37_training1 seminar37/TrainingTask1.1/main.cpp)
target_include_directories(sem37_training1 PRIVATE seminar37/TrainingTask1.1/include)

# --- Lectures ---
add_executable(lecture_moveSemantic1 lectures/moveSemantic1.cpp)

# --- class_vector ---
add_executable(class_vector class_vector/main.cpp)
target_include_directories(class_vector PRIVATE class_vector)
