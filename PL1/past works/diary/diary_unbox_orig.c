#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    time_t ts; // 投稿時刻 (Posted time)
    char   msg[280+1]; // メッセージ (Message)
} Tweet;

typedef struct {
    int    n; // 要素数 (The number of elements)
    Tweet* tweets[100];
} Diary;


Diary* create_diary()
{
    Diary* d = (Diary*)malloc(sizeof(Diary));
    d->n = 0; // 初めの要素数は 0 (The number of elements starts by 0)
    return d;
}

void remove_tweet(Diary* d, int index)
{
    free(d->tweets[index]); // 不要な記事の中身を削除 (Free post content)
    d->n--; // 要素数を1減らす (Decrement number of elements by one)
    
    for (int i = index; i < d->n; i++) {
        d->tweets[i] = d->tweets[i+1];
    }
}

void add_tweet(Diary* d, const char* msg)
{
    #error YOU NEED TO IMPLEMENT THIS FUNCTION BY YOURSELVES!!
}

void print_tweets(const Diary* d)
{
    for (int i = 0; i < d->n; i++) {
        char s[100];
        printf("%d: %s\t%s\n\n", i, ctime_r(&(d->tweets[i]->ts), s), d->tweets[i]->msg);
    }
}


int main()
{
    Diary* diary = create_diary();

    add_tweet(diary, "Hello, World!");
    add_tweet(diary, "My second tweet!");
    add_tweet(diary, "My third tweet!");

    remove_tweet(diary, 1);

    add_tweet(diary, "My last tweet!");

    print_tweets(diary);

    return 0;
}
