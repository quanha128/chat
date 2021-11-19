#include "diary.h"

int main()
{
    Diary* diary = load_diary();
    if (diary) {
        print_tweets(diary);
    }
    return 0;
}
