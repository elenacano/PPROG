/**
 * @brief It declares the tests for the game management module
 *
 * @file game_management_test.h
 * @author Group 1
 * @version 2.0
 * @date 15-12-2019
 * @copyright GNU Public License
 */

 #ifndef GAME_MANAGEMENT_TEST_H
 #define GAME_MANAGEMENT_TEST_H

 #include "game_management.h"
 #include "test.h"


void test1_game_management_create_from_file();
void test2_game_management_create_from_file();

void test1_game_management_load_spaces();
void test2_game_management_load_spaces();
void test3_game_management_load_spaces();

void test1_game_management_load_links();
void test2_game_management_load_links();
void test3_game_management_load_links();

void test1_game_management_load_objects();
void test2_game_management_load_objects();
void test3_game_management_load_objects();

void test1_game_management_load_player();
void test2_game_management_load_player();
void test3_game_management_load_player();

void test1_game_management_save();
void test2_game_management_save();
void test3_game_management_save();


#endif
