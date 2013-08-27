#include <stdlib.h>
#include <string.h>
#include <head-unit.h>
#include "common.h"

void replace_one_substr(void)
{
    char *string = "it is a string";
    char *sub = "is";
    char *new = "was";

    char *result = str_replace(string, sub, new);

    assert_string_equals("it was a string", result);
}

void replace_one_substr_beginning(void)
{
    char *string = "it is a string";
    char *sub = "it";
    char *new = "that";

    char *result = str_replace(string, sub, new);

    assert_string_equals("that is a string", result);
}

void replace_one_substr_end(void)
{
    char *string = "it is a string";
    char *sub = "string";
    char *new = "thing";

    char *result = str_replace(string, sub, new);

    assert_string_equals("it is a thing", result);
}

void replace_two_substr(void)
{
    char *string = "it is a is string";
    char *sub = "is";
    char *new = "was";

    char *result = str_replace(string, sub, new);

    assert_string_equals("it was a was string", result);
}

void replace_char(void)
{
    char *string = "some & a thing & something else";
    char *sub = "&";
    char *new = "&amp;";

    char *result = str_replace(string, sub, new);

    assert_string_equals("some &amp; a thing &amp; something else", result);
}

void replace_when_none(void)
{
    char *string = "its another string";
    char *sub = "haha";
    char *new = "replaced";

    char *result = str_replace(string, sub, new);

    assert_string_equals("its another string", result);
}

void replace_when_match(void)
{
    char *string = "hello";
    char *sub = "hello";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("goodbye", result);
}

void replace_when_string_empty(void)
{
    char *string = "";
    char *sub = "hello";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("", result);
}

void replace_when_string_null(void)
{
    char *string = NULL;
    char *sub = "hello";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_is_null(result);
}

void replace_when_sub_empty(void)
{
    char *string = "hello";
    char *sub = "";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("hello", result);
}

void replace_when_sub_null(void)
{
    char *string = "hello";
    char *sub = NULL;
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("hello", result);
}

void replace_when_new_empty(void)
{
    char *string = "hello";
    char *sub = "hello";
    char *new = "";

    char *result = str_replace(string, sub, new);

    assert_string_equals("", result);
}

void replace_when_new_null(void)
{
    char *string = "hello";
    char *sub = "hello";
    char *new = NULL;

    char *result = str_replace(string, sub, new);

    assert_string_equals("hello", result);
}

void compare_win_nums_less(void)
{
    gconstpointer a = GINT_TO_POINTER(2);
    gconstpointer b = GINT_TO_POINTER(3);

    int result = cmp_win_num(a, b);

    assert_true(result < 0);
}

void compare_win_nums_equal(void)
{
    gconstpointer a = GINT_TO_POINTER(5);
    gconstpointer b = GINT_TO_POINTER(5);

    int result = cmp_win_num(a, b);

    assert_true(result == 0);
}

void compare_win_nums_greater(void)
{
    gconstpointer a = GINT_TO_POINTER(7);
    gconstpointer b = GINT_TO_POINTER(6);

    int result = cmp_win_num(a, b);

    assert_true(result > 0);
}

void compare_0s_equal(void)
{
    gconstpointer a = GINT_TO_POINTER(0);
    gconstpointer b = GINT_TO_POINTER(0);

    int result = cmp_win_num(a, b);

    assert_true(result == 0);
}

void compare_0_greater_than_1(void)
{
    gconstpointer a = GINT_TO_POINTER(0);
    gconstpointer b = GINT_TO_POINTER(1);

    int result = cmp_win_num(a, b);

    assert_true(result > 0);
}

void compare_1_less_than_0(void)
{
    gconstpointer a = GINT_TO_POINTER(1);
    gconstpointer b = GINT_TO_POINTER(0);

    int result = cmp_win_num(a, b);

    assert_true(result < 0);
}

void compare_0_less_than_11(void)
{
    gconstpointer a = GINT_TO_POINTER(0);
    gconstpointer b = GINT_TO_POINTER(11);

    int result = cmp_win_num(a, b);

    assert_true(result < 0);
}

void compare_11_greater_than_0(void)
{
    gconstpointer a = GINT_TO_POINTER(11);
    gconstpointer b = GINT_TO_POINTER(0);

    int result = cmp_win_num(a, b);

    assert_true(result > 0);
}

void compare_0_greater_than_9(void)
{
    gconstpointer a = GINT_TO_POINTER(0);
    gconstpointer b = GINT_TO_POINTER(9);

    int result = cmp_win_num(a, b);

    assert_true(result > 0);
}

void compare_9_less_than_0(void)
{
    gconstpointer a = GINT_TO_POINTER(9);
    gconstpointer b = GINT_TO_POINTER(0);

    int result = cmp_win_num(a, b);

    assert_true(result < 0);
}

void next_available_when_only_console(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));

    int result = get_next_available_win_num(used);

    assert_int_equals(2, result);
}

void next_available_3_at_end(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));

    int result = get_next_available_win_num(used);

    assert_int_equals(3, result);
}

void next_available_9_at_end(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(6));
    used = g_slist_append(used, GINT_TO_POINTER(7));
    used = g_slist_append(used, GINT_TO_POINTER(8));

    int result = get_next_available_win_num(used);

    assert_int_equals(9, result);
}

void next_available_0_at_end(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(6));
    used = g_slist_append(used, GINT_TO_POINTER(7));
    used = g_slist_append(used, GINT_TO_POINTER(8));
    used = g_slist_append(used, GINT_TO_POINTER(9));

    int result = get_next_available_win_num(used);

    assert_int_equals(0, result);
}

void next_available_2_in_first_gap(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(9));
    used = g_slist_append(used, GINT_TO_POINTER(0));

    int result = get_next_available_win_num(used);

    assert_int_equals(2, result);
}

void next_available_9_in_first_gap(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(6));
    used = g_slist_append(used, GINT_TO_POINTER(7));
    used = g_slist_append(used, GINT_TO_POINTER(8));
    used = g_slist_append(used, GINT_TO_POINTER(0));
    used = g_slist_append(used, GINT_TO_POINTER(11));
    used = g_slist_append(used, GINT_TO_POINTER(12));
    used = g_slist_append(used, GINT_TO_POINTER(13));
    used = g_slist_append(used, GINT_TO_POINTER(20));

    int result = get_next_available_win_num(used);

    assert_int_equals(9, result);
}

void next_available_0_in_first_gap(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(6));
    used = g_slist_append(used, GINT_TO_POINTER(7));
    used = g_slist_append(used, GINT_TO_POINTER(8));
    used = g_slist_append(used, GINT_TO_POINTER(9));
    used = g_slist_append(used, GINT_TO_POINTER(11));
    used = g_slist_append(used, GINT_TO_POINTER(12));
    used = g_slist_append(used, GINT_TO_POINTER(13));
    used = g_slist_append(used, GINT_TO_POINTER(20));

    int result = get_next_available_win_num(used);

    assert_int_equals(0, result);
}

void next_available_11_in_first_gap(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(6));
    used = g_slist_append(used, GINT_TO_POINTER(7));
    used = g_slist_append(used, GINT_TO_POINTER(8));
    used = g_slist_append(used, GINT_TO_POINTER(9));
    used = g_slist_append(used, GINT_TO_POINTER(0));
    used = g_slist_append(used, GINT_TO_POINTER(12));
    used = g_slist_append(used, GINT_TO_POINTER(13));
    used = g_slist_append(used, GINT_TO_POINTER(20));

    int result = get_next_available_win_num(used);

    assert_int_equals(11, result);
}

void next_available_24_first_big_gap(void)
{
    GSList *used = NULL;
    used = g_slist_append(used, GINT_TO_POINTER(1));
    used = g_slist_append(used, GINT_TO_POINTER(2));
    used = g_slist_append(used, GINT_TO_POINTER(3));
    used = g_slist_append(used, GINT_TO_POINTER(4));
    used = g_slist_append(used, GINT_TO_POINTER(5));
    used = g_slist_append(used, GINT_TO_POINTER(6));
    used = g_slist_append(used, GINT_TO_POINTER(7));
    used = g_slist_append(used, GINT_TO_POINTER(8));
    used = g_slist_append(used, GINT_TO_POINTER(9));
    used = g_slist_append(used, GINT_TO_POINTER(0));
    used = g_slist_append(used, GINT_TO_POINTER(11));
    used = g_slist_append(used, GINT_TO_POINTER(12));
    used = g_slist_append(used, GINT_TO_POINTER(13));
    used = g_slist_append(used, GINT_TO_POINTER(14));
    used = g_slist_append(used, GINT_TO_POINTER(15));
    used = g_slist_append(used, GINT_TO_POINTER(16));
    used = g_slist_append(used, GINT_TO_POINTER(17));
    used = g_slist_append(used, GINT_TO_POINTER(18));
    used = g_slist_append(used, GINT_TO_POINTER(19));
    used = g_slist_append(used, GINT_TO_POINTER(20));
    used = g_slist_append(used, GINT_TO_POINTER(21));
    used = g_slist_append(used, GINT_TO_POINTER(22));
    used = g_slist_append(used, GINT_TO_POINTER(23));
    used = g_slist_append(used, GINT_TO_POINTER(51));
    used = g_slist_append(used, GINT_TO_POINTER(52));
    used = g_slist_append(used, GINT_TO_POINTER(53));
    used = g_slist_append(used, GINT_TO_POINTER(89));
    used = g_slist_append(used, GINT_TO_POINTER(90));
    used = g_slist_append(used, GINT_TO_POINTER(100));
    used = g_slist_append(used, GINT_TO_POINTER(101));
    used = g_slist_append(used, GINT_TO_POINTER(102));

    int result = get_next_available_win_num(used);

    assert_int_equals(24, result);
}

void register_common_tests(void)
{
    TEST_MODULE("common tests");
    TEST(replace_one_substr);
    TEST(replace_one_substr_beginning);
    TEST(replace_one_substr_end);
    TEST(replace_two_substr);
    TEST(replace_char);
    TEST(replace_when_none);
    TEST(replace_when_match);
    TEST(replace_when_string_empty);
    TEST(replace_when_string_null);
    TEST(replace_when_sub_empty);
    TEST(replace_when_sub_null);
    TEST(replace_when_new_empty);
    TEST(replace_when_new_null);
    TEST(compare_win_nums_less);
    TEST(compare_win_nums_equal);
    TEST(compare_win_nums_greater);
    TEST(compare_0s_equal);
    TEST(compare_0_greater_than_1);
    TEST(compare_1_less_than_0);
    TEST(compare_0_less_than_11);
    TEST(compare_11_greater_than_0);
    TEST(compare_0_greater_than_9);
    TEST(compare_9_less_than_0);
    TEST(next_available_when_only_console);
    TEST(next_available_3_at_end);
    TEST(next_available_9_at_end);
    TEST(next_available_0_at_end);
    TEST(next_available_2_in_first_gap);
    TEST(next_available_9_in_first_gap);
    TEST(next_available_0_in_first_gap);
    TEST(next_available_11_in_first_gap);
    TEST(next_available_24_first_big_gap);
}
