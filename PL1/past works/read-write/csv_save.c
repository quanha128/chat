#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>

typedef struct tweet {
    time_t ts;
    char   msg[280+1];
    struct tweet* prev;
    struct tweet* next;
} Tweet;

typedef struct {
    Tweet* first;
    Tweet* last;
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
    for (Tweet* t = d->first; t; t = t->next) {
        char s[100];
        printf("%d: %s\t%s\n\n", i++, ctime_r(&(t->ts), s), t->msg);
    }
}

int save_diary(const Diary* d)
{
    FILE* fp = fopen("diary.bin", "wb");
    if (!fp) goto error;

    FILE* fp_csv = fopen("diary.csv", "wb");
    if (!fp) goto error;

    char bom[3] = "\xef\xbb\xbf";
    fwrite(bom, sizeof(bom), 1, fp_csv);

    for (Tweet* t = d->first; t; t = t->next){
        char s[128];
        size_t n1 = fwrite(&t->ts, sizeof(t->ts), 1, fp);
        if (n1 != 1) goto error;

        size_t n2 = fwrite(t->msg, sizeof(t->msg), 1, fp);
        if (n2 != 1) goto error;

        char* timestamp = ctime_r(&(t->ts), s);
        int len = strlen(timestamp);
        timestamp[len-1] = (char) '\0';

        fprintf(fp_csv, "%s,%s\n", timestamp, t->msg);
    }

    fclose(fp);
    fclose(fp_csv);
    return 0;

 error:
    if (fp) fclose(fp);
    return 1;
}

Diary* load_diary()
{
    FILE* fp = fopen("diary.bin", "r+b");
    if (!fp) goto error;

    Diary* d = (Diary*)malloc(sizeof(Diary));
    if (!d) goto error;
    
    d->first = (Tweet*)malloc(sizeof(Tweet));
    Tweet* t = d->first;

    while (fread(&t->ts, sizeof(t->ts), 1, fp) == 1
        && fread(t->msg, sizeof(t->msg), 1, fp) == 1){
        t->next = (Tweet*)malloc(sizeof(Tweet));
        t->next->prev = t;
        t = t->next;
    }
    d->last = t->prev;

    return d;

 error:
    if (fp) fclose(fp);
    return NULL;
}

int main()
{
    const char *messages[] = {
        "Hello World!",
        "Goodbye World!",
        "Hello Goodbye",
    };

    Diary* diary = load_diary();
    if (!diary)
        diary = create_diary();

    add_tweet(diary, messages[time(NULL) % 3]);
    add_tweet(diary, messages[time(NULL) % 1]);
    add_tweet(diary, messages[time(NULL) % 2]);

    print_tweets(diary);

    save_diary(diary);
    return 0;
}