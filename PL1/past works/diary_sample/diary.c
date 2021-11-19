#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "diary.h"

typedef struct diary {
    int    n; // 要素数 (The number of elements)
    Tweet  tweets[100];
} Diary;


Diary* create_diary()
{
    Diary* d = (Diary*)malloc(sizeof(Diary));
    d->n = 0; // 初めの要素数は 0 (The number of elements starts by 0)
    return d;
}

Tweet* get_tweet(Diary* d, int index)
{
    return &(d->tweets[index]);
}

void remove_tweet(Diary* d, Tweet* t)
{
    int remove_index = t - d->tweets;
    
    d->n--; // 要素数を1減らす (Decrement number of elements by one)
    
    for (int i = remove_index; i < d->n; i++) {
        d->tweets[i] = d->tweets[i+1];
    }
}

void add_tweet(Diary* d, const char* msg)
{
    d->tweets[d->n].ts = time(NULL);
    strcpy(d->tweets[d->n].msg, msg);
    
    d->n++; // 要素数を1増やす (Increment number of elements by one)
}

void print_tweets(const Diary* d)
{
    for (int i = 0; i < d->n; i++) {
        char s[100];
        printf("%d: %s\t%s\n\n", i, ctime_r(&(d->tweets[i].ts), s), d->tweets[i].msg);
    }
}


int save_diary(const Diary* d)
{
    FILE* fp = fopen("diary.bin", "w");
    if (!fp) goto error; // ファイルのオープンに失敗 (Failed to open file)

    size_t n = fwrite(d->tweets, sizeof(Tweet), d->n, fp);
    if (n != d->n) goto error; // 必要な個数が書き込まれていない (Not all posts are written)

    fclose(fp);
    return 0;

 error:
    if (fp) fclose(fp);
    return 1;
}

Diary* load_diary()
{
    FILE* fp = fopen("diary.bin", "r");
    if (!fp) goto error; // ファイルのオープンに失敗 (Failed to open file)

    Diary* d = (Diary*)malloc(sizeof(Diary));
    if (!d) goto error;
    
    d->n = fread(d->tweets, sizeof(Tweet), 100, fp);
    return d;

 error:
    if (fp) fclose(fp);
    return NULL;
}
