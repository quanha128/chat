#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tweet {
    time_t ts; // 投稿時刻 (Posted time)
    char   msg[280+1]; // メッセージ (Message)
    struct tweet* prev; // 一つ前の要素 (Previous element)
    struct tweet* next; // 一つ先の要素 (Next element)
} Tweet;

typedef struct {
    Tweet* first; // 最初の要素 (First element)
    Tweet* last; // 最後の要素 (Last element)
} Diary;


Diary* create_diary()
{
    Diary* d = (Diary*)malloc(sizeof(Diary));
    d->first = d->last = NULL;
    return d;
}

Tweet* get_tweet(Diary* d, int index)
{
    Tweet* t = d->first;
    for (int i = 0; i < index; i++) {
        t = t->next;
    }
    return t;
}

void remove_tweet(Diary* d, Tweet* t)
{
    Tweet* prev = t->prev;
    Tweet* next = t->next;

    if (prev) prev->next = next;
    else d->first = next;

    if (next) next->prev = prev;
    else d->last = prev;

    free(t);
}

void add_tweet(Diary* d, const char* msg)
{
    Tweet* t = (Tweet*)malloc(sizeof(Tweet));

    t->ts = time(NULL);
    strcpy(t->msg, msg);

    t->prev = d->last;
    t->next = NULL;

    if (d->last) d->last->next = t;
    d->last = t;
    if (!d->first) d->first = t;
}

void print_tweets(const Diary* d)
{
    int i = 0;
    for (Tweet* t = d->last; t; t = t->prev) {
        char s[100];
        printf("%d: %s\t%s\n\n", i++, ctime_r(&(t->ts), s), t->msg);
    }
}


int main()
{
    Diary* diary = create_diary();

    add_tweet(diary, "Hello, World!");
    add_tweet(diary, "My second tweet!");
    add_tweet(diary, "My third tweet!");

    Tweet* tw = get_tweet(diary, 1);
    remove_tweet(diary, tw);

    add_tweet(diary, "My last tweet!");

    print_tweets(diary);

    return 0;
}
