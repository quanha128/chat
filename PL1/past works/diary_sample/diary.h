#ifndef DEFINE_H_DIARY
#define DEFINE_H_DIARY

#include <time.h>

typedef struct {
    time_t ts; // 投稿時刻 (Posted time)
    char   msg[280+1]; // メッセージ (Message)
} Tweet;

typedef struct diary Diary;

extern Diary* create_diary();
extern Tweet* get_tweet(Diary* d, int index);
extern void remove_tweet(Diary* d, Tweet* t);
extern void add_tweet(Diary* d, const char* msg);
extern void print_tweets(const Diary* d);
extern int save_diary(const Diary* d);
extern Diary* load_diary();

#endif /* DEFINE_H_DIARY */
