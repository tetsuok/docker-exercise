#!/bin/bash
clang++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
    -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o ${GTEST_DIR}/src/gtest-all.o
ar -rv ${GTEST_DIR}/libgtest.a ${GTEST_DIR}/src/gtest-all.o
