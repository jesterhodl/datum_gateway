#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "datum_utils.h"

/* Stub out logger dependency used by datum_utils.c */
int datum_logger_queue_msg(const char *func, int level, const char *format, ...) {
    (void)func; (void)level; (void)format;
    return 0;
}

/* Provide dummy argv reference for datum_reexec */
const char *datum_argv[] = { "test_datum_utils", NULL };


int main(void) {
    const char *secret = "abc";
    size_t secret_len = strlen(secret);

    /* equal strings */
    assert(datum_secure_strequals(secret, secret_len, "abc"));

    /* guess longer than secret */
    assert(!datum_secure_strequals(secret, secret_len, "abcd"));

    /* guess repeats secret but is longer */
    assert(!datum_secure_strequals(secret, secret_len, "abcabc"));

    /* zero-length secret matches only on empty guess */
    assert(!datum_secure_strequals("", 0, "anything"));
    assert(datum_secure_strequals("", 0, ""));

    printf("All tests passed.\n");
    return 0;
}
