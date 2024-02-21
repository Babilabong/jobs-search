cmake_minimum_required(VERSION 3.23)
project(job_search)

set(CMAKE_CXX_STANDARD 14)

add_executable(job_search main.cpp Employer.cpp Employer.h Candidate.h Candidate.cpp Jobs.cpp Jobs.h)
