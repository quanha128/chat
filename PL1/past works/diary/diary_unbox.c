#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    time_t ts;
    char   msg[280+1];
} Tweet;

typedef struct {
    int    n;
    int    size;
    Tweet* tweets;
} Diary;


Diary* create_diary()
{
    int N = 100;
    Diary* d = (Diary*)malloc(sizeof(Diary));
    d->size = N;
    d->n = 0;
    d->tweets = (Tweet*)malloc(N*sizeof(Tweet));
    return d;
}

void remove_tweet(Diary* d, Tweet* t)
{
    int remove_index = t - d->tweets;
    
    d->n--;
    
    for (int i = remove_index; i < d->n; i++) {
        d->tweets[i] = d->tweets[i+1];
    }
}

Tweet* get_tweet(Diary* d, int index)
{
    return &(d->tweets[index]);
}

void add_tweet(Diary* d, const char* msg)
{
    if (d->n >= d->size){
        d->size++;
        d->tweets = (Tweet*)realloc(d->tweets,(d->size)*sizeof(Tweet));
    }
    d->tweets[d->n].ts = time(NULL);
    strcpy(d->tweets[d->n].msg, msg);
    
    d->n++;
}

void print_tweets(const Diary* d)
{
    for (int i = 0; i < d->n; i++) {
        char s[100];
        printf("%d: %s\t%s\n\n", i, ctime_r(&(d->tweets[i].ts), s), d->tweets[i].msg);
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
    for (int i=0; i<110; i++){
        add_tweet(diary, "hoge");
    }

    print_tweets(diary);

    return 0;
}
