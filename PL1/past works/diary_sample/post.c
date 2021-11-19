#include <stdio.h>
#include "diary.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }
    
    Diary* diary = load_diary();
    if (!diary) {
        diary = create_diary();
    }

    add_tweet(diary, argv[1]);
    save_diary(diary);

    return 0;
}
